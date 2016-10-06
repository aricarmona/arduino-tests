#include <Servo.h>

Servo rightMotor ;
Servo leftMotor ;

int rightSensor = 0 ;
int leftSensor = 0 ;

int rightSensorSlot = 4 ;
int leftSensorSlot = 3 ;

int outline = 450 ;

void setup() {
  rightMotor.attach( 6 ) ;
  leftMotor.attach( 5 ) ;

  Serial.begin( 9600 ) ;
}

void loop() {
  read_positions() ;
  logging() ;

  // Se os dois sensores estiverem fora da linha (dentro dos limites), andar o mais rapido possivel
  if ( rightSensor < outline && leftSensor < outline ){
    walk() ;
  }

 // Se um dos sensores estiverem nos limites, para, dah reh, dah meia volta e anda
  if ( rightSensor > outline || leftSensor > outline ){
    stop() ;
    delay( 50 ) ;
    reh() ;
    delay( f_random() ) ;
    turn_right() ;
    delay( f_random() ) ;
  }
}

void read_positions() {
  rightSensor = analogRead( rightSensorSlot ) ;
  leftSensor = analogRead( leftSensorSlot ) ;
}

void logging() {
  Serial.print( "rightSensor = " ) ;
  Serial.print( rightSensor ) ;
  Serial.print( " | " ) ;
  Serial.print( "leftSensor = " ) ;
  Serial.println( leftSensor ) ;
}

void walk() {
  rightMotor.write( 0 ) ;
  leftMotor.write( 180 ) ;
}

void turn_right() {
  rightMotor.write( 180 ) ;
  leftMotor.write( 180 ) ;
}

void stop() {
  rightMotor.write( 90 ) ;
  leftMotor.write( 90 ) ;
}

void reh() {
  rightMotor.write( 110 ) ;
  leftMotor.write( 70 ) ;
}

int f_random() {
    return ( rand() % 100 ) + 650 ;
}
