const int ldr = 0 ;
const int led = 6 ;
int read_value = 0 ;
int pwm = 0 ;

void setup() {
  Serial.begin( 9600 ) ;
  pinMode( led , OUTPUT ) ;
}

void loop() {
  read_value = analogRead( ldr ) ;
  
  if ( read_value < 60 ) {
    analogWrite( led , pwm ) ;
    pwm += 20 ;
    delay( 100 ) ;
  }
  else {
    digitalWrite( led , LOW ) ;
    pwm = 0 ;
  }
  
  if ( pwm > 255 ) {
    pwm = 255 ;
  }
  
  Serial.print( "Valor lido do ldr = " ) ;
  Serial.println( read_value ) ;
}
