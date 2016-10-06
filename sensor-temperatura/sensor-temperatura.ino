const int lm35 = 0 ;
const int buzzer = 12 ;
const float temperature_limit = 27.7 ;

float temperature = 0 ;
int adc = 0 ;

void setup() {
  Serial.begin( 9600 ) ;
  analogReference( INTERNAL ) ;
  pinMode( buzzer , OUTPUT ) ;
}

void loop() {
  adc = analogRead( lm35 ) ;
  temperature = adc * 0.1075268817204301 ;
  
  if ( temperature > temperature_limit ) {
    digitalWrite( buzzer , HIGH ) ;
  }
  else {
    digitalWrite( buzzer , LOW ) ;
  }
  
  Serial.print( "Temperatura = " ) ;
  Serial.print( temperature ) ;
  Serial.println( " *C" ) ;
  delay( 1000 ) ;
}
