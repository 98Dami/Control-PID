#include <PID_v1.h>

// Asignaciones pins
const int PIN_INPUT = A0;
const int PIN_OUTPUT = 3;

// Constantes del controlador
double Kp=2, Ki=5, Kd=1;

// variables externas del controlador
double Input, Output, Setpoint;

PID pidController(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
 
void setup()
{
   Input = analogRead(PIN_INPUT);
   Setpoint = 100;
   
   pidController.SetMode(AUTOMATIC);     // encender el PID
}
 
void loop()
{
   Input = analogRead(PIN_INPUT);
   pidController.Compute();         // actualizar el PID
   analogWrite(PIN_OUTPUT, Output);
}
