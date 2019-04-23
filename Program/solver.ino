#include <Servo.h>
Servo push;
Servo base;
Servo block;

// DECLARE SERVO MOVES, DELAYS AND ROTATION LENGTH
int temps_push = 1600;
int temps_2push = 3100;
int temps_3push = 4530;
int stop_push = 84;
int base_maxB = 180;   
int base_cB = 90;     
int base_min = 0;
int base_rectificar1 = 80;
int base_rectificar2 = 100;
int block_max = 180;
int block_min = 17;
int delay_1 = 1000;
int delay_5 = 5000;
int base_maxP = 167;
int base_cP = 79;

// SOLUTION
char solve[]= {'r', 'U', 'l', 'N'};
int moviments = 4;

// PROCEDURES FOR ALL OF THE POSSIBLE ROTATIONS
// Bring down the blocking part
void baixa_block() {
 block.write(block_min);
 delay(delay_1);
}

// Move blocking part back up
void puja_block() {
  block.write(block_max);
  delay(delay_1);
}

// Move base to position 0º
void base0(){
  base.write(base_min);
  delay(delay_1);
}

// Move base to position 90º
void base90(){
  base.write(base_cB);
  delay(delay_1);
}

// Move base to position 180º
void base180(){
  base.write(base_maxB);
  delay(delay_1);
}

// Rotate layer 90º clockwise
void rota90horari(){
  base90();
  baixa_block();      
  base180();          
  puja_block();
  base.write(base_rectificar1);
  delay(delay_1);
  baixa_block();
  base.write(base_rectificar2);
  delay(delay_1);
  puja_block();
}

// Rotate layer 90º anticlockwise
void rota90antihorari(){
  base90();
  baixa_block();          
  base0();
  puja_block(); 
}

// Rotate layer 180º
void rota180(){
  base90();
  baixa_block();
  base0(); 
  puja_block();
  base90();
  baixa_block();
  base0();
  puja_block();
}

// Push cube once
void push1(){
  push.write(180);
  delay(temps_push);
  push.write(90);
  delay(stop_push);
}

// Push cube twice
void push2(){  
  push.write(180);
  delay(temps_2push);
  push.write(90);
  delay(stop_push);
}

// Push cube three times
void push3(){ 
  push.write(180);
  delay(temps_3push);
  push.write(90);
  delay(stop_push);
}

// ATTACH SERVOS TO ARDUINO BOARD
void setup(){
  push.attach(11);
  base.attach(10);
  block.attach(9);   
  Serial.begin(9600);
}

// START SOLVING
void loop(){
  block.write(block_max); 
  delay(delay_1);
  base.write(base_cP);
  delay(delay_5);
  
      for (int solucio = 0; solucio < moviments; solucio++){
        Serial.print(" solucio ");
        Serial.print(solucio);
      
        switch (solve[solucio]){    
            
            // R
            case 'R':
                base.write(base_maxP);       
                delay(delay_1);                  
                push1(); 
                base90();
                rota90horari();
                base.write(base_maxP);       
                delay(delay_1);    
                push1(); 
                base.write(base_min);
                delay(delay_1);
                push2();   
                base.write(base_cP);
                delay(delay_1);
                push1(); 
                Serial.print(" R ");
                Serial.print(solucio);
              break;
            
            // R'
            case 'r':
                base.write(base_maxP);                         
                delay(delay_1);
                push1();
                base90();
                rota90antihorari();  
                push1();
                base.write(base_cP);
                delay(delay_1);
                push3();
                Serial.print(" r ");
                Serial.print(solucio);
              break;

           // R2
           case 'Z':
                base.write(base_maxP);
                delay(delay_1);
                push1();
                rota180();
                push1();
                delay(delay_1);
                base.write(base_cP);
                delay(delay_1);
                push2();
                Serial.print(" R2 ");
                Serial.print(solucio);
              break;

           // U
           case 'U':
                push2(); 
                delay(delay_1);   
                rota90horari();
                base.write(base_min);
                delay(delay_1);
                push2();
                delay(delay_1);
                base.write(base_cP);
                delay(delay_1);
                push1();
                delay(delay_1);
                base.write(base_maxP);
                delay(delay_1);
                push1();
                delay(delay_1);
                base.write(base_cP);
                delay(delay_1);
                push3();           
                Serial.print(" U ");
                Serial.print(solucio);
              break;

           // U'
           case 'u':
                push2();
                rota90antihorari();
                push2();
                base.write(base_maxP);
                delay(delay_1);
                push2();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_min);
                delay(delay_1);
                push1();
                base.write(base_cP);
                delay(delay_1);
                push1();
                Serial.print(" u ");
                Serial.print(solucio);
              break;

           // U2
           case 'X':
                push2();
                rota180();
                base.write(base_maxP);
                delay(delay_1);
                push2();
                base.write(base_cP);
                delay(delay_1);
                Serial.print(" U2 ");
                Serial.print(solucio);
              break;

           // L
           case 'L':
                base.write(base_min);
                delay(delay_1);
                push1();
                rota90horari();
                base.write(base_maxP);
                delay(delay_1);
                push1();
                base.write(base_cP);
                delay(delay_1);
                push3();
                Serial.print(" L ");
                Serial.print(solucio);
              break;

           // L'
           case 'l':
                base.write(base_min);
                delay(delay_1);
                push1();
                rota90antihorari();
                base.write(base_maxP);
                delay(delay_1);
                push1();
                base.write(base_cP);
                delay(delay_1);
                push1();
                Serial.print(" l ");
                Serial.print(solucio);
              break;

            // L2
            case 'C':
                base.write(base_min);
                delay(delay_1);
                push1();  
                rota180();
                base.write(base_maxP);
                delay(delay_1);
                push1();
                base.write(base_cP);
                delay(delay_1);
                push2();
                Serial.print(" L2 ");
                Serial.print(solucio);
              break;

           // F
           case 'F':
                push3();
                rota90horari(); 
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_min);
                delay(delay_1);
                push3();
                base.write(base_cP);
                delay(delay_1);
                Serial.print(" F ");
                Serial.print(solucio);
              break;

           // F'
           case 'f':
                push3();
                rota90antihorari();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_maxP);
                delay(delay_1);
                push3();
                base.write(base_cP);
                delay(delay_1);
                Serial.print(" f ");
                Serial.print(solucio);
              break;

           // F2
           case 'V':
                push3();
                rota180();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_maxP);
                delay(delay_1);
                push2();
                base.write(base_cP);
                delay(delay_1);
                Serial.print(" F2 ");
                Serial.print(solucio);
              break;

           // B
           case 'B':
                push1(); 
                rota90horari();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_min);
                delay(delay_1);
                push3();
                base.write(base_cP);
                delay(delay_1);
                push2();
                Serial.print(" B ");
                Serial.print(solucio);
              break;

           // B'
           case 'b':
                push1();
                rota90antihorari();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_maxP);
                delay(delay_1);
                push3();
                base.write(base_cP);
                delay(delay_1);
                push2();
                Serial.print(" b ");
                Serial.print(solucio);
              break;

           // B2
           case 'N':
                push1();
                rota180();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_maxP);
                delay(delay_1);
                push2();
                base.write(base_cP);
                delay(delay_1);
                push2();
                Serial.print(" B2 ");
                Serial.print(solucio);
              break;

           // D
           case 'D':
                rota90horari();
                base.write(base_maxP);
                delay(delay_1);
                push1();
                base.write(base_min);
                delay(delay_1);
                push2();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_maxP);
                delay(delay_1);
                push1();
                base.write(base_cP);
                delay(delay_1);
                Serial.print(" D ");
                Serial.print(solucio);
              break;

           // D'
           case 'd':
                rota90antihorari();
                push1();
                base.write(base_maxP);
                delay(delay_1);
                push2();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_min);
                delay(delay_1);
                push1();
                base.write(base_cP);
                delay(delay_1);
                Serial.print(" d ");
                Serial.print(solucio);
              break;

           // D2
           case 'M':
                rota180();
                base.write(base_cP);
                delay(delay_1);
                push1();
                base.write(base_maxP);
                delay(delay_1);
                push2();
                base.write(base_cP);
                delay(delay_1);
                push3();
                Serial.print(" D2 ");
                Serial.print(solucio);
              break;

            default:
              break;
       }
    }
    exit(0);
}
