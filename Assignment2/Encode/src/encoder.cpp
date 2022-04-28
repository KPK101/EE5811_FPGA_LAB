#include<arduino.h>
const int  a = 7;
const int  b = 6;
const int  c = 4;
const int  d = 2;
const int  e = 1;
const int  f = 9;
const int  g = 10;
const int  dp = 5 ;// decimal
const int  cc = 3;
const int  ca =  8;
// hexadecimal characters
const int  A = 10;
const int  B = 11;
const int  C = 12;
const int  D = 13;
const int  E = 14;
const int  F = 15;
const int seg[] = {a,b,c,d,e,f,g,dp,cc,ca};


// Or returns the or operation between 8 inputs -> a1,a2...a8
int Or(int a, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){
if(a==a1||a==a2||a==a3||a==a4||a==a5||a==a6||a==a7||a==a8){
    return 1;
  }
  else{
    return 0;
  }
}

// We define functions for each bit
int BB0(int number) {
  int b0 = Or(number,1,3,5,7,9,11,13,15); // B0 = 1 + 3 + 5 + 7 + 9 + B + D + F
  return b0;
}
int BB1(int number){
  int b1 = Or(number,2,3,6,7,10,11,14,15); //B1 = 2 + 3 + 6 + 7 + A + B + E + F
  return b1;
}
int BB2(int number){
  int b2 = Or(number,4,5,6,7,12,13,14,15); //B2 = 4 + 5 + 6 + 7 + C + D + E + F
  return b2;
}
int BB3(int number){
  int b3 = Or(number,8,9,10,11,12,13,14,15); //B3 = 8 + 9 + A + B + C + D + E + F
  return b3;
}

int encoding[4];


int Encode(int input, int* outbuffer){
  outbuffer[0] = BB0(input);
  outbuffer[1] = BB1(input);
  outbuffer[2] = BB2(input);
  outbuffer[3] = BB3(input);
  return 1;
}// The representation is 4,3,2,1 - B3,B2,B1,B0

void DIM(){
  for (int i=0;i<10;i++){
    digitalWrite(seg[i],LOW);
  }
}

void DisplayZero(){
  for(int i=0;i<10;i++){
    if(i<6){
      digitalWrite(seg[i],LOW);
    }else{
      digitalWrite(seg[i],HIGH);
    }
  }
}
void DisplayOne(){
    for(int i=0;i<10;i++){
    if(i>3&&i<6){
      digitalWrite(seg[i],LOW);
    }else{
      digitalWrite(seg[i],HIGH);
    }
  }
}

void DisplayEncoding(int* encoding){
  for(int i=0;i<4;i++){
    if(encoding[3-i]==1){
      DisplayOne();
      delay(500);
      DIM();
      delay(500);
    }else{
      DisplayZero();
      delay(500);
       DIM();
       delay(500);
    }
  }
}


int encodenum = 10; // number to be encoded
int success = Encode(encodenum,encoding);

void setup() {

  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(dp,OUTPUT);
  pinMode(cc,OUTPUT);
  pinMode(ca,OUTPUT);
}

void loop() {
  // Indicaion that encodign is being displayed
  // Blink twice
  for(int iter=0;iter<2;iter++)
  {
    for(int i=0; i<10; i++)
    {
      if(i==7){
        digitalWrite(dp,LOW);
      }else{
        digitalWrite(seg[i],HIGH);
      }
      
    }
    delay(500);
    digitalWrite(dp,HIGH);
    delay(500);
 
  }
    // begin display of encoding
  DisplayEncoding(encoding);
 
  delay(1000);

}
