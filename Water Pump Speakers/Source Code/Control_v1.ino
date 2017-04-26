//SonidoBAJO//#define MAX 600
#define MAX 700
#define MIN 20
#define UMBRAL 550
#define UMBRAL_AGUA 550

int TIME_UMBRAL = 100;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

int pinLed1 = 5;
int pinLed2 = 6;
int pinLed3 = 7;
int pinLed4 = 8;
int pinLed5 = 9;
int pinLed6 = 10;
int pinLed7 = 11;
int pinLed8 = 12;

int pinBlue = 2;
int pinRG = 3;
int pinGR = 4;

int IzqA = 15;
int IzqB = 16;
int DerA = 17;
int DerB = 18;

int mic = 14;
int dif = MAX - MIN;
int divisor = (int)dif/9;
int valor = 0;
int valorAnterior = 0;
int maxV = 0;
int minV = 1000;

unsigned long inicio = 0;
unsigned long tiempo = 0;
int flagTime = 0;

void encenderMotor(){
    digitalWrite(IzqA,HIGH);
    digitalWrite(IzqB,LOW);
    digitalWrite(DerA,HIGH);
    digitalWrite(DerB,LOW);
}

void apagarMotor(){
    digitalWrite(IzqA,LOW);
    digitalWrite(IzqB,LOW);
    digitalWrite(DerA,LOW);
    digitalWrite(DerB,LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode(mic, INPUT);
  pinMode(pinLed1,OUTPUT);
  pinMode(pinLed2,OUTPUT);
  pinMode(pinLed3,OUTPUT);
  pinMode(pinLed4,OUTPUT);
  pinMode(pinLed5,OUTPUT);
  pinMode(pinLed6,OUTPUT);
  pinMode(pinLed7,OUTPUT);
  pinMode(pinLed8,OUTPUT);
  pinMode(pinBlue,OUTPUT);
  pinMode(pinRG,OUTPUT);
  pinMode(pinGR,OUTPUT);
  pinMode(IzqA,OUTPUT);
  pinMode(IzqB,OUTPUT);
  pinMode(DerA,OUTPUT);
  pinMode(DerB,OUTPUT);
  
  digitalWrite(pinLed1,HIGH);
  digitalWrite(pinLed3,HIGH);
  digitalWrite(pinLed5,HIGH);
  digitalWrite(pinLed4,HIGH);
  digitalWrite(pinLed2,HIGH);
  digitalWrite(pinLed6,HIGH);
  digitalWrite(pinLed7,HIGH);
  digitalWrite(pinLed8,HIGH);
  digitalWrite(pinBlue,HIGH);
  digitalWrite(pinRG,HIGH);
  digitalWrite(pinGR,HIGH);
  digitalWrite(IzqA,HIGH);
      digitalWrite(IzqB,HIGH);
        digitalWrite(DerA,HIGH);
          digitalWrite(DerB,HIGH);
 
}

void loop()
{
  inicio = millis();
  valor = analogRead(mic);
  if(valor >= maxV){
    maxV = valor;
  }
  if(valor <= minV && valor > 0){
    minV = valor;
  }
  if( valor <= 0){
    valor = valorAnterior;
   }
   else valorAnterior = valor;
  if( valor >= MIN + divisor*8){
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed3,LOW);
    digitalWrite(pinLed5,LOW);
    digitalWrite(pinLed4,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed6,LOW);
    digitalWrite(pinLed7,LOW);
    digitalWrite(pinLed8,LOW);
   }
  else if( valor >= MIN + divisor*7){
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,LOW);
    digitalWrite(pinLed4,LOW);
    digitalWrite(pinLed5,LOW);
    digitalWrite(pinLed6,LOW);
    digitalWrite(pinLed7,LOW);
    digitalWrite(pinLed8,HIGH);
  }
  else if( valor >= MIN + divisor*6){
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,LOW);
    digitalWrite(pinLed4,LOW);
    digitalWrite(pinLed5,LOW);
    digitalWrite(pinLed6,LOW);
    digitalWrite(pinLed7,HIGH);
    digitalWrite(pinLed8,HIGH);
  }
  else if( valor >= MIN + divisor*5){
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,LOW);
    digitalWrite(pinLed4,LOW);
    digitalWrite(pinLed5,LOW);
    digitalWrite(pinLed6,HIGH);
    digitalWrite(pinLed7,HIGH);
    digitalWrite(pinLed8,HIGH);
  }
  else if( valor >= MIN + divisor*4){
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,LOW);
    digitalWrite(pinLed4,LOW);
    digitalWrite(pinLed5,HIGH);
    digitalWrite(pinLed6,HIGH);
    digitalWrite(pinLed7,HIGH);
    digitalWrite(pinLed8,HIGH);
  }
  else if( valor >= MIN + divisor*3){
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,LOW);
    digitalWrite(pinLed5,HIGH);
    digitalWrite(pinLed4,HIGH);
    digitalWrite(pinLed6,HIGH);
    digitalWrite(pinLed7,HIGH);
    digitalWrite(pinLed8,HIGH);
  }
  else if( valor >= MIN + divisor*2){
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,HIGH);
    digitalWrite(pinLed5,HIGH);
    digitalWrite(pinLed4,HIGH);
    digitalWrite(pinLed6,HIGH);
    digitalWrite(pinLed7,HIGH);
    digitalWrite(pinLed8,HIGH);
  }
  else if( valor >= MIN + divisor*1){
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed3,HIGH);
    digitalWrite(pinLed5,HIGH);
    digitalWrite(pinLed4,HIGH);
    digitalWrite(pinLed2,HIGH);
    digitalWrite(pinLed6,HIGH);
    digitalWrite(pinLed7,HIGH);
    digitalWrite(pinLed8,HIGH);
  }
  else{
    digitalWrite(pinLed1,HIGH);
    digitalWrite(pinLed3,HIGH);
    digitalWrite(pinLed5,HIGH);
    digitalWrite(pinLed4,HIGH);
    digitalWrite(pinLed2,HIGH);
    digitalWrite(pinLed6,HIGH);
    digitalWrite(pinLed7,HIGH);
    digitalWrite(pinLed8,HIGH);
    }
  /*
  Serial.print("Max= ");
  Serial.print(maxV);
  Serial.print("Min= ");
  Serial.print(minV);
  Serial.println(" ");*/
  Serial.println(valor);
  if( valor >= UMBRAL){
    digitalWrite(pinBlue,LOW);
    digitalWrite(pinRG,LOW);
    digitalWrite(pinGR,LOW);
  }
  else{
     digitalWrite(pinBlue,HIGH);
     digitalWrite(pinRG,HIGH);
     digitalWrite(pinGR,HIGH);
  }
  if( valor >= UMBRAL_AGUA){
    flagTime = 1;
  }
  else{
     flagTime = 0;
  }
  if(flagTime){
    encenderMotor();
    tiempo = 0;
    //digitalWrite(pinBlue,LOW);
    //digitalWrite(pinRG,LOW);
    //digitalWrite(pinGR,LOW);
  }
  if(tiempo >= TIME_UMBRAL){
    tiempo = 0;
    apagarMotor();
     //digitalWrite(pinBlue,HIGH);
     //digitalWrite(pinRG,HIGH);
     //digitalWrite(pinGR,HIGH);
  }
  tiempo = tiempo + millis() - inicio;
}
