#define ONBOARD_LED 12  // LED GP12
#define ONBOARD_SW 7    // Switch GP7

unsigned long previousMillis = 0UL;
unsigned long interval = 1000UL;
unsigned long currentMillis = 0UL;
int current_LED = HIGH;
int state = 0;
bool pressed = false;

void setup() {
  Serial.begin(115200);  //set up serial library baud rate to 115200
  pinMode(ONBOARD_LED, OUTPUT);
  pinMode(ONBOARD_SW, INPUT_PULLUP);

  digitalWrite(ONBOARD_LED, current_LED);  // turn the LED off by making the voltage LOW
}

void loop() {
  if (digitalRead(ONBOARD_SW) == LOW && pressed == false) {  // Switch is asserted Low (Active Low)
    if (state != 3) {
      state += 1;
    } else {
      state = 0;
    }
    pressed = true;
  }
  if (digitalRead(ONBOARD_SW) == HIGH) {
    pressed = false;
  }
  switch (state) {
    case 0:
      current_LED = HIGH;
      break;
    case 1:
      blink(1000UL);
      break;
    case 2:
      blink(500UL);
      break;
    case 3:
      blink(100UL);
      break;
  }
}

void blink(long inter) {
  currentMillis = millis();
  if (currentMillis - previousMillis > inter) {
    current_LED = (current_LED == HIGH) ? LOW : HIGH;
    digitalWrite(ONBOARD_LED, current_LED);
    previousMillis = currentMillis;
  }
}