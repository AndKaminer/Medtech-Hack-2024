//Define variables
const int buttonPin = 1;
const int mosfetPin = 2;
int poweredOn = 0;
int buttonState;

int on_off_state = 0;

// setup pin modes
void setup()
{
	pinMode(buttonPin, INPUT_PULLUP);
  	pinMode(mosfetPin, OUTPUT);
}


void loop()
{
  // if the button is pressed and the pump is off,
  // turn it on
  if(digitalRead(buttonPin) == LOW && !on_off_state){
    on_off_state = 1;
    motorBehaviorOn();

    delay(500);
  } // if the button is pressed and the pump is on,
  	// turn it off
  if(digitalRead(buttonPin) == LOW && on_off_state)
  {
    on_off_state = 0;
    motorBehaviorOff();
    delay(500);
  }
}

void motorBehaviorOn() {

  digitalWrite(mosfetPin, LOW);

}

void motorBehaviorOff()
{
  digitalWrite(mosfetPin, HIGH);
}
