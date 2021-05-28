// Asignaciones pins
const int PIN_INPUT = A0;
const int PIN_OUTPUT = 3;

//PID constants
double kp = 2, ki = 5, kd = 1; // Constantes del controlador

// variables internas del controlador
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double Input, Output, setPoint; // variables externas del controlador
double cumError, rateError;

void setup(){}

void loop(){
Input = analogRead(PIN_INPUT); // leer una entrada del controlador
Output = computePID(Input); // calcular el controlador
delay(100);
analogWrite(PIN_OUTPUT, Output);  // escribir la salida del controlador

}

double computePID(double inp){
currentTime = millis(); // obtener el tiempo actual
elapsedTime = (double)(currentTime - previousTime); // calcular el tiempo transcurrido

error = setPoint - inp; // determinar el error entre la consigna y la medición
cumError += error * elapsedTime; // calcular la integral del error
rateError = (error - lastError)/elapsedTime; // calcular la derivada del error

double out = kp*error + ki*cumError + kd*rateError; // calcular la salida del PID

lastError = error; // almacenar error anterior
previousTime = currentTime; // almacenar el tiempo anterior

return out; //have function return the PID output
}
