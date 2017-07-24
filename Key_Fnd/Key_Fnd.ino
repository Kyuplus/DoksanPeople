/////////////////   CommonVarious/intervening Parmeter   ///////////////////////
char KEY_FND_ARR[][4]={
                    {1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16},
                    {17,18,19,20}
                  };



/////////////////        0.KeyMatrix             ///////////////////////

unsigned long currentMillis = 0, Key_previousMillis0 = 0;
unsigned short portVal;
int realPort,currentKeyPort,currentPortval,previousKeyPort,previousPortval;
int tog,tog1,keep_down,shift_column,row;
/*-----------------------------------------------------------------*/



/////////////////        1.FND             ///////////////////////

  unsigned long FND_previousMillis0,FND_previousMillis1;
  int FND_arr[10][8]={
                   //0 1 2 3 4 5 6 7
                    {0,0,0,0,1,1,0,0},  //0
                    {0,0,1,1,1,1,1,1},  //1
                    {0,1,0,0,0,1,0,1},  //2
                    {0,0,1,0,0,1,0,1},  //3
                    {0,0,1,1,0,1,1,0},  //4
                    {1,0,1,0,0,1,0,0},  //5
                    {1,0,0,0,0,1,0,0},  //6
                    {0,0,1,1,1,1,0,0},  //7
                    {0,0,0,0,0,1,0,0},  //8
                    {0,0,1,1,0,1,0,0}   //9
                  };
  
  int i,k,DIG1_CNT,DIG2_CNT,BtnNum;
  int FNDtog=1;
/*-----------------------------------------------------------------*/


void setup() {
 //FND PIN config
  for(int k=23;k<=32;k++)
    pinMode(k,OUTPUT);

  digitalWrite(23,1);
  digitalWrite(32,1);
/*=====================*/
  
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);

  DIG1_CNT=0;
  DIG2_CNT=0;

  Serial.begin(9600); 
}

void loop() {

  currentMillis=millis();

  if(currentMillis-Key_previousMillis0 >=1){                  
    Key_previousMillis0 = currentMillis;
    
    digitalWrite((2*shift_column)+5,1);
    
    if(shift_column == 4) 
      shift_column = 0;
    
    shift_column++;
    digitalWrite((2*shift_column)+5,0); 
  }


  if(tog==0){
    currentKeyPort=0x00;
    currentKeyPort|= (!digitalRead(12)<<0);
     currentKeyPort|= (!digitalRead(10)<<1);
     currentKeyPort|= (!digitalRead(8)<<2);
     currentKeyPort|= (!digitalRead(6)<<3);
     currentKeyPort|= (!digitalRead(5)<<4);



    if(currentKeyPort!=0){
      previousKeyPort=currentKeyPort;
      currentPortval =0x00;
      currentPortval = shift_column-1;
      //Serial.print(currentPortval);
      previousPortval=currentPortval;
      
      while(currentKeyPort){
        currentKeyPort=currentKeyPort>>1;
        row++;
      }
      BtnNum=4- currentPortval+(4*(row-1));
      Serial.println("DOWN btn "+String(BtnNum));
      if(BtnNum>=10)
          DIG2_CNT=(BtnNum/10);
      else
        DIG2_CNT=0;
      
      DIG1_CNT=BtnNum%10;
      
      tog=!tog;
      tog1=0;
    }
  }
  else{

    currentPortval =0x00;
    currentPortval = shift_column-1;
              
    if(previousPortval!=currentPortval)
      tog1=1;

    if(tog1==1){
      currentKeyPort=0x00;
      currentKeyPort|= (!digitalRead(12)<<0);
       currentKeyPort|= (!digitalRead(10)<<1);
       currentKeyPort|= (!digitalRead(8)<<2);
       currentKeyPort|= (!digitalRead(6)<<3);
       currentKeyPort|= (!digitalRead(5)<<4);
      
      if(previousPortval==currentPortval){
        if(previousKeyPort!=currentKeyPort){
          Serial.println("UP btn "+String( 4-currentPortval+(4*(row-1))));
          
          row=0;
          tog=!tog;
        }
      } 
    }   
  }

  /////////////////////    FND    //////////////////////////////
  

  if(currentMillis-FND_previousMillis0>=5){
    FND_previousMillis0=currentMillis;
    if(FNDtog==1){
      for(i=0;i<=7;i++){
        digitalWrite(i+24,FND_arr[DIG1_CNT][i]);
      }
      digitalWrite(32,1);
      digitalWrite(23,0);
    }
    else if(FNDtog==0){
      for(i=0;i<=7;i++){
        digitalWrite(i+24,FND_arr[DIG2_CNT][i]);
      }
      digitalWrite(32,0);
      digitalWrite(23,1);
    }   
    FNDtog=!FNDtog;
  }
/*----------------------------------------------------------*/
  
}
