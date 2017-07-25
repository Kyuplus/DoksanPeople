unsigned long currentMillis, dot_previousMillis;
unsigned long currentMicros, dot_previousMicros;
int dot_i,dot_j,dot_k,dot_m;
int dot_cnt,dot_cnt1;
char DotM_arr[2][8]={
                      {36,39,40,47,42,46,34,33},  //===, 0=HIGH
                      {48,35,44,45,37,43,38,41}   //|||  1=LOW
                    };
unsigned char num[10][8]={  
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
unsigned char num_print[8]={0,};
int i;

                
void setup() {
  for(int i=33;i<49;i++)
    pinMode(i,OUTPUT);
 
  Serial.begin(9600);
}

void loop() {
  currentMicros=micros();
  currentMillis=millis();
  if(currentMicros-dot_previousMicros>=3000){
    dot_previousMicros=currentMicros;
   
    //========== Row SET ============//    
    dot_k--;
    if(dot_k<0)
      dot_k=8;
    /*----------------------------*/      

    //========== Dot CNT ============//  
    if(dot_cnt>=100){
     for(int j=0;j<8;j++)
          num_print[j]=(num[dot_m%10][j]>>i)+(num[(dot_m+1)%10][j]<<(8-i));

     i++;
     if(i>7){
       i=0;
       dot_m++;     
     }     
     dot_cnt=0; 
    } 
    dot_cnt++;
    /*----------------------------*/     
      
    //========== RESET ============//    
    for(dot_j=0;dot_j<8;dot_j++){
      digitalWrite(DotM_arr[0][dot_j],1);
      digitalWrite(DotM_arr[1][dot_j],0);      
    } 
    /*----------------------------*/   
   
    //======== DOT PRINT ==========//   
    for(dot_i=0;dot_i<=7;dot_i++){
      if( num_print[dot_k-1]&(0x01 << (dot_i)) ){
        digitalWrite(DotM_arr[1][dot_k-1],1);
        digitalWrite(DotM_arr[0][7-dot_i],0);
      }
    } 
    /*----------------------------*/
    

  }    

}
