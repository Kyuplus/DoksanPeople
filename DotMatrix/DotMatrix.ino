unsigned long currentMillis, previousMillis;
unsigned long currentMicros, previousMicros;
int i,j,k,m,temp;
int state=1;
char DotM_arr[2][8]={
                      {36,39,40,47,42,46,34,33},  //===, 0=HIGH
                      {48,35,44,45,37,43,38,41}   //|||  1=LOW
                    };
char num[10][8]={  
                  {0x00,0x38,0x44,0x4c,0x54,0x64,0x44,0x38},
                  {0x00,0x10,0x30,0x50,0x10,0x10,0x10,0x7c},
                  {0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c},
                  {0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38},
                  {0x00,0x08,0x18,0x28,0x48,0x7c,0x08,0x08},
                  {0x00,0x7c,0x40,0x78,0x04,0x04,0x44,0x38},
                  {0x00,0x38,0x40,0x40,0x78,0x44,0x44,0x38},
                  {0x00,0x7c,0x04,0x08,0x10,0x20,0x20,0x20},
                  {0x00,0x38,0x44,0x44,0x38,0x44,0x44,0x38},
                  {0x00,0x38,0x44,0x44,0x3c,0x04,0x44,0x38}
                };
void setup() {
  for(int i=33;i<49;i++)
    pinMode(i,OUTPUT);
    
  Serial.begin(9600);
}

void loop() {
  currentMicros=micros();
  currentMillis=millis();
          
  if(currentMicros-previousMicros>=1000){
    previousMicros=currentMicros;

    for(j=0;j<8;j++)
      digitalWrite(DotM_arr[0][j],1); 
  
    for(i=0;i<8;i++){
      if( num[m][k]& (0x01 << i) )
        digitalWrite(DotM_arr[1][i],1);   
      else
        digitalWrite(DotM_arr[1][i],0);       
    }
    digitalWrite(DotM_arr[0][k],0);
   
    k++;
    if(k>7)
      k=0;    
  
  }  

//  if(currentMillis-previousMillis>=1000){
//    previousMillis=currentMillis;
//    m++;
//    
//    if(m>9)
//      m=0;
//  }
}
