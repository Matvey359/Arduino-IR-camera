#include <GyverButton.h>
#include <Servo.h>

Servo az;
Servo alt;
GButton butt1(4);

int x = 20;
int y = 20;

//int arr[20];

void setup() {
  Serial.begin(9600);
  az.attach(9);
  alt.attach(8);
}

void loop() {
  butt1.tick();
  if(butt1.isClick()){
    take(); 
  }
}

void take() {
  int ser_val = 0;
  int alt_pos = 0;
  for(int i = 0; i < y; i++){
    ser_val = 0;
    Serial.print("\n");
    for(int j = 0; j < x; j++){
      int val = analogRead(A0);
      //arr[i] = val;
      az.write(ser_val);
      ser_val += 2;
      Serial.print(val, DEC);
      Serial.print(", ");
      delay(500);
    }
    /*for(int j; j < x; j++){
      String data = String(arr[j], DEC);
      Serial.print(data + ", ");  
    }*/
    alt.write(alt_pos);
    alt_pos += 2;
  }
}
