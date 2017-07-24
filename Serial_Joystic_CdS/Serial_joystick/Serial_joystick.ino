#define CdS 6
#define JOYS1_X 3 
#define JOYS1_Y 4
#define JOYS0_X 8 
#define JOYS0_Y 9
#define JOYS0_Z 10
//////////////////        2.JoyStick            /////////////////////
  unsigned long JOY0_previousMillis0;
  int J0_X,J0_Y,J0_Z;
  int J1_X,J1_Y,J1_Z;
/*-----------------------------------------------------------------*/
  long UART3;
//////////////////       5CdS          /////////////////////
  unsigned long CdS_previousMillis0; 
  unsigned int light,light_H,light_L;

  unsigned long currentMillis;
  unsigned long currentMicros;
  int tog=1;

/*--------------------------------------------------------------*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial3.begin(9600);  
}

void loop() {
  currentMicros=micros();
  currentMillis=millis();
//  if(Serial3.available()){
//    UART3=Serial3.read();
//    Serial.write(UART3);
//  }


    if(currentMillis-CdS_previousMillis0>=100){
    CdS_previousMillis0=currentMillis;
    
    light= analogRead(CdS);
    light_H=((light&0xff00)>>8);
    light_L=light&0xff;
      Serial.write(light_H);
      Serial.write(light_L);
//      Serial.write("\n");

//      Serial.print(light_H);
//      Serial.print("    ");
//      Serial.print(light_L);
//      Serial.println("\n");
    
    J0_X= analogRead(JOYS0_X);
    J0_Y= analogRead(JOYS0_Y);
    J0_Z= analogRead(JOYS0_Z);
//     Serial.print("X:");
//     Serial.print(J0_X/8,DEC);
//     Serial.print(" Y:");
//     Serial.print(J0_Y/8,DEC);
//     Serial.print(" Z:");
//     Serial.println(J0_Z/8,DEC);

     Serial.write(J0_X/8);
     Serial.write(J0_Y/8);
     Serial.write(J0_Z/8);
     Serial.write("\n");
     
  }


////////////////////////// JOYSTRIC 0  ////////////////////
  
  if(currentMillis-JOY0_previousMillis0>=1000){
    JOY0_previousMillis0=currentMillis;

     
  }

/*-----------------------------------------------------*/


  
}
