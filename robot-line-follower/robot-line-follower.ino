/**
 * Segue uma linha colocada sob a superficie.
 */
#include <Servo.h>

// Servos
Servo rightMotor ;
Servo leftMotor ;

// CONFIG
int rightSensorValue = 0 ;
int leftSensorValue = 0 ;

int rightSensorSlot = 1 ;
int leftSensorSlot = 2 ;

int rightMotorSlot = 6 ;
int leftMotorSlot = 7 ;

int outline = 650 ;

// Init
void setup() {
  rightMotor.attach( rightMotorSlot ) ;
  leftMotor.attach( leftMotorSlot ) ;

  Serial.begin( 9600 ) ;
}

// Main/loop
void loop() {
  read_positions() ;
  logging() ;

  // Se estiver dentro da linha andar para frente o mais rahpido possivel
  if ( rightSensorValue > outline && leftSensorValue > outline ) {
    walk() ;
  }

  // Se o lado esquerdo estiver saindo da linha vira para direita
  if ( rightSensorValue > outline && leftSensorValue <= outline ) {
    turn_right() ;
  }

  // Se o lado direito estiver saindo da linha vira para esquerda
  if ( rightSensorValue <= outline && leftSensorValue > outline ) {
    turn_left() ;
  }

  // Se os dois sensores estiverem fora da linha
  if ( rightSensorValue <= outline && leftSensorValue <= outline ) {
    reverse() ;
  }

  delay( 30 ) ;
}

void read_positions() {
  rightSensorValue = analogRead( rightSensorSlot ) ;
  leftSensorValue = analogRead( leftSensorSlot ) ;
}

void logging() {
  Serial.print( "rightSensorValue = " ) ;
  Serial.print( rightSensorValue ) ;
  Serial.print( " | " ) ;
  Serial.print( "leftSensorValue = " ) ;
  Serial.println( leftSensorValue ) ;
}

void walk() {
  rightMotor.write( 70 ) ;
  leftMotor.write( 120 ) ;
}

void turn_right() {
  rightMotor.write( 90 ) ;
  leftMotor.write( 110 ) ;
}

void turn_left() {
  rightMotor.write( 70 ) ;
  leftMotor.write( 90 ) ;
}

void reverse() {
  rightMotor.write( 110 ) ;
  leftMotor.write( 70 ) ;
}
