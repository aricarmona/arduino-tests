// initialize digital pin 13 as an output.
int ledPing = 13 ;

void setup() {
  pinMode( ledPing , OUTPUT ) ;
}

void loop() {
  digitalWrite( ledPing , HIGH ) ;
  delay( 2000 ) ;

  digitalWrite( ledPing , LOW ) ;
  delay( 400 ) ;

  digitalWrite( ledPing , HIGH ) ;
  delay( 300 ) ;
  digitalWrite( ledPing , LOW ) ;
  delay( 300 ) ;
  digitalWrite( ledPing , HIGH ) ;
  delay( 300 ) ;
  digitalWrite( ledPing , LOW ) ;
  delay( 300 ) ;
  digitalWrite( ledPing , HIGH ) ;
  delay( 300 ) ;
  digitalWrite( ledPing , LOW ) ;
  delay( 300 ) ;
}
