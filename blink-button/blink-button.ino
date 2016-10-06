const int ledPing = 13 ;
const int button = 2 ;
int buttonStatus = 0 ;

void setup() {
  pinMode( ledPing , OUTPUT ) ;
  pinMode( button , INPUT ) ;
}

void loop() {
  buttonStatus = digitalRead( button ) ;

  if ( buttonStatus == HIGH ) {
    digitalWrite( ledPing , LOW ) ;
  }
  else {
    digitalWrite( ledPing , HIGH ) ;
  }
}
