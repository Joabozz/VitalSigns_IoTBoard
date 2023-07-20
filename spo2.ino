#include <Wire.h>
#include "MAX30105.h"

MAX30105 particleSensor;
float ir;
float red;
float spo2;

#define debug Serial

void setup()
{
  debug.begin(115200);

  if (particleSensor.begin() == false)
  {
    debug.println("MAX30105 no encontrado");
    while (1);
  }

  particleSensor.setup();
}

void loop()
{
  debug.print(" R[");
  debug.print(particleSensor.getRed());
  debug.print("] IR[");
  debug.print(particleSensor.getIR());
  debug.print("] spo2 ");
  ir=particleSensor.getIR();
  red=particleSensor.getRed();
  spo2= (red/ir)*100;
  if (spo2 <= 100){
    Serial.println(spo2);    
  }
  else {}
  debug.println();
}
