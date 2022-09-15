#include <DHT.h>
#define DHTPIN11 11 // dhtpin
#define DHTPIN22 12 // dhtpin
#define DHTTYPE11 DHT11 // DHT 22
#define DHTTYPE22 DHT22 // DHT 22
DHT dht11(DHTPIN11, DHTTYPE11);
DHT dht22(DHTPIN22, DHTTYPE22);
int n=0;
int x=1;
float H11;
float T11;
float H22;
float T22;
void setup()
{
Serial.begin(9600);
dht11.begin();
dht22.begin();

pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
//pin 2 - bulb
//pin 3 - temperature fan for incubator
//pin 4 - humidity fan for incubator
//pin 5 - temperature fan for hatcher
//pin 6 - humidity for hatcher
//pin 7 - motor1
//pin 8 - motor2
//pin 9 -inlet exhaust fan

}
void loop()
{
delay(500);
H11 = dht11.readHumidity();
T11= dht11.readTemperature();
H22 = dht22.readHumidity();
T22= dht22.readTemperature();
if(T22<=33.0) // Temperature for incubator
{
if(T22<=32.0)
{
digitalWrite(2,LOW);
digitalWrite(3,LOW);
}
}
else
{
digitalWrite(2,HIGH);

digitalWrite(3,HIGH);
}
if(T11<=33.0) // Temperature for hatcher
{

{
if(T11<=32.0)
{
digitalWrite(2,LOW);
digitalWrite(5,LOW);
}
}}
else
{
digitalWrite(2,HIGH);
digitalWrite(5,HIGH);
}
if(H22<=85.0) // humidity for incubator
{
if(H22<=82.0)
{
digitalWrite(4,LOW);
}
}
else
{
digitalWrite(4,HIGH);
}

if(H11<=85.0) // humidity for hatcher
{
if(H11<=82.0)
{
digitalWrite(6,LOW);
} }
else
{
digitalWrite(6,HIGH);
}
while(n>=10)
{
if(x==1)
{
{

digitalWrite(7, LOW);
digitalWrite(9, LOW);
delay(8000);
digitalWrite(7, HIGH);
digitalWrite(9, HIGH);
x=0;
n=0;
}

break;
}
if(x==0)
{
digitalWrite(8, LOW);
digitalWrite(9, LOW);
delay(8000);
digitalWrite(8, HIGH);
digitalWrite(9,HIGH);
x=1;
n=0;
break;
}

}
Serial.print("INCUBATOR TEMPERATURE: ");
Serial.print(T22);
Serial.print(" C, INCUBATOR HUMIDITY: ");
Serial.print(H22);
Serial.println(" %");
Serial.print("HATCHER TEMPERATURE ");
Serial.print(T11);
Serial.print(" C, HATCHER HUMIDITY: ");
Serial.print(H11);
Serial.println(" %");
Serial.println(" TIME-");
Serial.println(n);
Serial.println(x);
n=n+1;
}
