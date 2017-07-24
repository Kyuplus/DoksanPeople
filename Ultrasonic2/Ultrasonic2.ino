//#define SONAR_TRIGGER_PIN     2
unsigned long currentMicros, A_Micros, B_Micros, gap_Micros;
double L;
int l;

////#define SONAR_ECHO_PIN        3

//unsigned int measure_distance()
//{
//   // Trigger the SRF05:
//   digitalWrite(SONAR_TRIGGER_PIN, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(SONAR_TRIGGER_PIN, LOW);
//
//   // Wait for Echo Pulse
//   unsigned long pulse_length = pulseIn(SONAR_ECHO_PIN, HIGH);
//
//   // Ensure the ultrasonic "beep" has faded away
//   delay(50);
//
//   // Convert Pulse to Distance (inches) 
//   // pulse_length/58 = cm or pulse_length/148 = inches
//   return( (unsigned int) (pulse_length / 148) );
//}

void setup(){
   A_Micros= B_Micros= gap_Micros = micros();
   pinMode(A3, OUTPUT);
   pinMode(18, INPUT);
   Serial.begin(9600);
   attachInterrupt(5, myISR3, CHANGE);
}

void loop(){
  digitalWrite(A3,1);
  delayMicroseconds(10);
  digitalWrite(A3,0);
  delay(200);
}

void myISR3(){
  
  A_Micros=micros();
  gap_Micros=A_Micros-B_Micros;
  B_Micros=A_Micros;
  if(!digitalRead(18)){
    L= (float)gap_Micros*0.5*0.001*340*0.1;
    l=(int)L;
    Serial.print(l);
    Serial.println("cm");       
  }
 
}

