// N little Schrum / Sven the real Goldschmidt
// Steuerung des MendelPendels
// September 2014


//Zeitmessung

int hallSensor_1= 0;
int hallSensor_2= 1;

volatile unsigned long start_1 =0, start_2 =0, ende, richtung;
volatile float deltaT_ms;

void setup() 
{ 
  //Serial
  Serial.begin(9600);

  //Zeitmerssung
  pinMode(hallSensor_1, INPUT); 
  attachInterrupt(hallSensor_1, catch_1, RISING);
  pinMode(hallSensor_2, INPUT); 
  attachInterrupt(hallSensor_2, catch_2, RISING);
  //led 
  pinMode(13, OUTPUT); 
  Serial.println("reday to start....");
} 
 
 
void loop() 
{ 

digitalWrite(13, HIGH);

}

void catch_1(){
  //Serial.print("CHANGE Hall_1=  ");
  //Serial.println(micros()-start_1);
  start_1= micros();
}

void catch_2(){
  //Serial.print("CHANGE Hall_2=  ");
  deltaT_ms=(micros()-start_1);
  //Serial.print(deltaT_ms);
  //Serial.print(" microsec ");
  Serial.print(deltaT_ms/1000);
  Serial.print(" millisec ");
  Serial.print(deltaT_ms/1000000);
  Serial.println(" sec ");
  float v=(0,015)/(deltaT_ms/1000000);
  Serial.print(v);
  Serial.print(" m/sec ");
  Serial.print(v*3.6);
  Serial.println(" km/h");
  
  //start_2= micros();
}

