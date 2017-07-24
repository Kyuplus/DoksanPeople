/* Processing code */
import processing.serial.*;

Serial myPort1; 

byte inByte,j,i;
long CdS_val,CdS_val_H,CdS_val_L;
int joy_x,joy_y,joy_z;

void setup () {
 size(800,800 );
 
  myPort1 = new Serial(this, "COM6", 9600);
  myPort1.bufferUntil('\n');
  delay(2000);

}




void draw () {
//stroke(255, 255, 255);
fill(CdS_val);
rect(200,200,400,400);

if(joy_z==0){
  fill(200,100,100);
  ellipse(400+((joy_y-64)*2),400+((64-joy_x)*2),40,40);
}
else{
  fill(100,200,100);
  ellipse(400+((joy_y-64)*2),400+((64-joy_x)*2),20,20);
  }
}

 void serialEvent (Serial myPort1) {
      
      byte[] inByte= new byte[200];
      myPort1.readBytesUntil('\n',inByte);

      CdS_val_H=inByte[0]&0xff;
      CdS_val_H=CdS_val_H<<8;
      CdS_val_L=inByte[1]&0xff;
      CdS_val=(CdS_val_H)+CdS_val_L;
      
      joy_x = inByte[2];
      joy_y = inByte[3];
      joy_z = inByte[4];
      
      System.out.print(CdS_val_H + "  ");
      System.out.print(CdS_val_L + "   ");
      System.out.print(CdS_val+ "   ");

      System.out.print(inByte[2] + "   ");
      System.out.print(inByte[3] + "   ");
      System.out.println(inByte[4] + "   ");
  
}