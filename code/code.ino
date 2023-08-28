#include<Servo.h> // Tai thu vien dong co servo

Servo myservo; // Tao doi tuong servo dat ten la my servo

int pos = 0; // Toa do ban dau cua servo la 0, ben trong
int valman = 0; // Khai bao gia tri analog button man
int valhand = 0; // Khai bao gia tri analog button hand
int vallight = 0; // Khai bao gia tri analog cuong do anh sang
int rainSensor = 6; // Cam bien mua gan o chan digital 6

void setup() {
  Serial.begin(9600);// Toc do truyen tai voi may tinh
  myservo.attach(9); // Dau dieu khien servo noi vao chan 9
  pinMode(rainSensor,INPUT);// Dat chan cam bien mua la input cho arduino
}

void loop() {
  valman = analogRead(0); // Lay tu chan analog A0, >0thi nguoi dieu khien, con lai auto
  vallight = analogRead(2); // Lay tu chan analog A2, neu nang thi >300
  valhand = analogRead(1);//Lay tu chan analog A1, neu > 0 thi di ra, 0 thi di vao
  int value = digitalRead(rainSensor);// Cam bien mua HIGH la khong mua
  
  if(valman>0){ // Khi o che do nguoi dieu khien
    if(valhand>0){ // Khi o che do cho ra ngoai
      myservo.write(180); // Cho ra ngoai
      delay(15); // Cho tre de doi dong co quay den vi tri can den 
    }else{ // Khi o che do cho vao trong
      myservo.write(0); // Cho vao trong
      delay(15); // Cho tre de doi dong co quay den vi tri can den 
    }
  }

  if(valman==0){ // Khi o che do tu dong
    if((vallight>300)&&(value==HIGH)){ // Chi o ngoai khi nang va khong mua
      myservo.write(180); //Cho o ben ngoai
      delay(15); // Cho tre de doi dong co quay den vi tri can den 
    }else{ // Khi mua hoac khong co nang
      myservo.write(0); //Cho o ben trong
      delay(15);  // Cho tre de doi dong co quay den vi tri can den 
    }
  }
}
