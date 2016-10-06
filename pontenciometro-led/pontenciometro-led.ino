const int potenc = A0 ;
const int led = 11 ;
int potency = 0 ;
int pwm = 0 ;

void setup() {
  pinMode( led , OUTPUT ) ;
}

void loop() {
  potency = analogRead( potenc ) ;
  pwm = map( potency , 0 , 1023 , 0 , 255 ) ;
  analogWrite( led , pwm ) ;
}
