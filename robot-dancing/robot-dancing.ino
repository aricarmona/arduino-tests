#include <Servo.h>

Servo rightMotor ;
Servo leftMotor ;

void setup() {
  leftMotor.attach( 5 ) ;
  rightMotor.attach( 6 ) ;
}

void loop() {
  straight_run() ;
  delay( 3000 ) ;
  reverse_gerar() ;
  delay( 3000 ) ;
  clockwise() ;
  delay( 3000 ) ;
  anticlockwise() ;
  delay( 3000 ) ;
  dancing() ;
  dancing() ;
  dancing() ;
  dancing() ;
  dancing() ;
  dancing() ;
  nothing() ;
  delay( 4000 ) ;
}

void dancing() {
  clockwise() ;
  delay( 100 ) ;
  anticlockwise() ;
  delay( 100 ) ;
  clockwise() ;
  delay( 100 ) ;
  anticlockwise() ;
  delay( 100 ) ;
  clockwise() ;
  delay( 100 ) ;
  anticlockwise() ;
  delay( 100 ) ;
}

// Em frente
void straight_run() {
  leftMotor.write( 180 ) ;
  rightMotor.write( 0 ) ;
}

// Reh
void reverse_gerar() {
  leftMotor.write( 0 ) ;
  rightMotor.write( 180 ) ;
}

// Gira em sentido horahrio
void clockwise() {
  leftMotor.write( 180 ) ;
  rightMotor.write( 180 ) ;
}

// Gira em sentido anti-horahrio
void anticlockwise() {
  leftMotor.write( 0 ) ;
  rightMotor.write( 0 ) ;
}

// Anda devagar
void slow() {
  leftMotor.write( 100 ) ;
  rightMotor.write( 80 ) ;
}

// Para os motores
// Jah calibrando o diferencial entre os eixos
void nothing() {
  leftMotor.write( 92 ) ;
  rightMotor.write( 92 ) ;
}

