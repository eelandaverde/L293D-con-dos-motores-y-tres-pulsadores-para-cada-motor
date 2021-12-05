/*
Vamos a hacer un ckto programable de dos motores controlados por
un L293D que va a tener por cada motor: un botón para que el motor
gire a la derecha, gire a la izquierda y que no gire
*/

//pulsadores
int pDireccion1M1,pDireccion2M1, paroM1; //Pulsadores Motor1
int pDireccion1M2,pDireccion2M2, paroM2; //Pulsadores Motor2

//Salidas
int habilitadorM1 = 9;
int habilitadorM2 = 11; 
int Direccion1M1 = 8; //derecha M1
int Direccion2M1 = 10; //izquierda M1

int Direccion1M2 = 12; //derecha M2
int Direccion2M2 = 13; //izquierda M2


void setup(){
  Serial.begin(9600);
  //configuracion entradas digitales
  for(int i = 2; i<8; i++)
  {
    pinMode(i,INPUT_PULLUP);
  }
  //configuracion salidas digitales
  pinMode(habilitadorM1,OUTPUT);
  pinMode(habilitadorM2,OUTPUT);
  pinMode(Direccion1M1,OUTPUT);
  pinMode(Direccion2M1,OUTPUT);
  pinMode(Direccion1M2,OUTPUT);
  pinMode(Direccion2M2,OUTPUT);
}

void loop ()
{
  //definicion de enables
  int DivisonVoltio = (3*255)/5;
  analogWrite(habilitadorM1,DivisonVoltio);
  analogWrite(habilitadorM2,DivisonVoltio);
  /*
  5V -> 255
  3v -> X
  */
  
  //definicion de pulsadores M1
  pDireccion1M1 = digitalRead(2);
  pDireccion2M1 = digitalRead(3);
  paroM1 = digitalRead(4);
  
  //definicion de pulsadores M2
  pDireccion1M2 = digitalRead(5);
  pDireccion2M2 = digitalRead(6);
  paroM2 = digitalRead(7);
  
  if (pDireccion1M1 == false)
  {
    digitalWrite(Direccion1M1,HIGH);
    digitalWrite(Direccion2M1,LOW);
  }
  
  if (pDireccion2M1 == false)
  {
    digitalWrite(Direccion1M1,LOW);
    digitalWrite(Direccion2M1,HIGH);
  }
  
  if(paroM1 == false)
  {
    digitalWrite(Direccion1M1,LOW);
    digitalWrite(Direccion2M1,LOW);
  }
  
  //condicion m2
  if (pDireccion1M2 == false)
  {
    digitalWrite(Direccion1M2,HIGH);
    digitalWrite(Direccion2M2,LOW);
  }
  
  if (pDireccion2M2 == false)
  {
    digitalWrite(Direccion1M2,LOW);
    digitalWrite(Direccion2M2,HIGH);
  }
  
  if(paroM2 == false)
  {
    digitalWrite(Direccion1M2,LOW);
    digitalWrite(Direccion2M2,LOW);
  }
  
  Serial.println(String(pDireccion1M2) + "  " +
              String(pDireccion2M2) + "  " +
               String(paroM2));
 
}