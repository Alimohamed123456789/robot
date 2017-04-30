//KUIPER TEAM
//NASA SPACE APPS ALEXANDRIA
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(0, 1); // RX, TX
char BluetoothData;
int a1=5;   int a2=6;   //1st motor pins
int b1=10;  int b2=11;  //2nd motor pins
int tcrtp=4;   //input pin of tcrt 5000
int sc=100;      //controlled speed &100 is an initial speed
int c=0;       //counter

/////////////////////////////////////////////
//move forward
void fr(){
analogWrite(a1,sc);
analogWrite(a2,0);
analogWrite(b1,sc);
analogWrite(b2,0);}
////////////////////////////////////////////
//move back
void b(){
analogWrite(a1,0);
analogWrite(a2,sc);
analogWrite(b1,0);
analogWrite(b2,sc);}
///////////////////////////////////////////
//turn right
void right(){
analogWrite(a1,0);
analogWrite(a2,sc);
analogWrite(b1,sc);
analogWrite(b2,0);}
/////////////////////////////////////////
//turn left
void left(){
analogWrite(a1,sc);
analogWrite(a2,0);
analogWrite(b1,0);
analogWrite(b2,sc);}
//////////////////////////////////////////
//stop move
void stp(){
analogWrite(a1,0);
analogWrite(a2,0);
analogWrite(b1,0);
analogWrite(b2,0);}
///////////////////////////////////////////
void setup() { 
bluetooth.begin(9600); 
pinMode(a1,OUTPUT); 
pinMode(a2,OUTPUT); 
pinMode(b1,OUTPUT);
pinMode(b2,OUTPUT);
pinMode(tcrtp,INPUT);}
//////////////////////////////////////////
void loop() {
int y =digitalRead(tcrtp);  // sensor state
// check if bluetooth available and sensor state
if (bluetooth.available()&& y==1)
{c=0;
BluetoothData=bluetooth.read(); 
if(BluetoothData=='F') fr();
else if(BluetoothData=='B') b();
else if(BluetoothData=='L') left();
else if(BluetoothData=='R') right();
else  stp();}

else if(y == 0)  //check sensor state
{c++;            //no. of lines
delay(100);}
//robot speed control
if(c == 1)      sc=75; 
else if(c == 2) sc=150;
else if(c == 3) sc=255;
}
