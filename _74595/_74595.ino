unsigned long currentMillis = 0, previousMillis;
long LED=0xf0;
long port;
int state=1;

void setup() {
pinMode(A7,OUTPUT);//LATCH
pinMode(51,OUTPUT);//MOSI
pinMode(52,OUTPUT);//SCK
pinMode(53,OUTPUT);//SS595

previousMillis = millis();

digitalWrite(53,0);//SS595 => always LOW
Serial.begin(9600);
}

void loop() {
  currentMillis=millis();
  
  if(currentMillis-previousMillis>=100){
    previousMillis=currentMillis;
  
    for(int i=0;i<8;i++){
      if(LED&(0x0010<<i))
        digitalWrite(51,1);
      else  
        digitalWrite(51,0);
      
      digitalWrite(52,1);//
      digitalWrite(52,0);
    }
    if(state){
      LED=(LED<<1);
      if(LED>=0xf000)
        state=!state;
    }
    else{
      LED=(LED>>1);
      if(LED<=0x0f)
        state=!state;
    }
    
    digitalWrite(A7,1);
    digitalWrite(A7,0);
  }

    
}
