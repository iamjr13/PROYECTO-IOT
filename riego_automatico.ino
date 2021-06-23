#include <ThingerEthernet.h>
#include <SPI.h>
#include <Ethernet.h>
#define USERNAME "iamjr"
#define DEVICE_ID "13ARDU"
#define DEVICE_CREDENTIAL "k8+PdwS8OHzTsTKw"
#define sensor A0
hecho hoy

ThingerEthernet thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
int Valor;
 int sensorValue = analogRead(sensor);
  int percentage = map(sensorValue, 0, 1023, 100, 0);
void setup() {
  pinMode(sensor, INPUT);
  
 thing["sensor"] >> [](pson& out){
    out["Humedad"] = analogRead(sensor)/1023*100;
  Serial.print("IR radiation: ");
  Serial.print(percentage);
  Serial.println(" %");
    };
}

void loop() { 
  Serial.print("Sensor de Humedad valor:");  
  Valor =analogRead(1);
  Serial.print(Valor);
   if (Valor <= 300)  
    Serial.println(" Encharcado"); 
    digitalWrite (9,HIGH);
    digitalWrite (7,LOW);
    digitalWrite (5,LOW);
  if ((Valor > 300) and (Valor <= 700))  {
    Serial.println(" Humedo, no regar");
    digitalWrite (9,LOW);  
     digitalWrite (7,HIGH);
     digitalWrite (5,LOW);
  } 
  if (Valor > 700) {
    Serial.println(" Seco, necesitas regar"); 
    digitalWrite (9,LOW);
    digitalWrite (7,LOW); 
    digitalWrite (5,HIGH);
  }
  thing.handle();
}
