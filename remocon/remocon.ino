unsigned long currentMicros, A_Micros, B_Micros, gap_Micros;


unsigned long IR_data;
int cnt=31;
char lead_code;
char IR_tog=0;
unsigned long IR_datacode[10]={0x6897,0x30cf,0x18e7,0x7a85,0x10ef,0x38c7,0x5aa5,0x42BD,0x4AB5,0x52AD};

int IR_num;

void setup() {
  pinMode(19,INPUT);
  attachInterrupt(4,myISR,FALLING);
  Serial.begin(9600); 
  A_Micros= B_Micros= gap_Micros = micros();
}

void loop() {
  if(IR_tog){
  
  for(int i; i<10; i++){
    if(IR_datacode[i]==IR_data)
      IR_num=i;
  }
    Serial.print(IR_num);

  IR_tog=!IR_tog;
  }
}

void myISR(){
  A_Micros=micros();
  gap_Micros=A_Micros-B_Micros;
  B_Micros=A_Micros;
  
  if((gap_Micros>=13000)&&(gap_Micros<=14000)){
    lead_code=1;
    cnt=31;
    IR_data=0x00;
  }
  if(lead_code){  
    if((gap_Micros>=1000)&&(gap_Micros<=1300)){
      IR_data|=(0<<cnt); 
       cnt--;            
    }
    else if((gap_Micros>=2100)&&(gap_Micros<=2400)){
      IR_data|=(1<<cnt);
       cnt--;
    }
   
    if(cnt<0){
      IR_tog=1;
      lead_code=0;
    }
  }
}

