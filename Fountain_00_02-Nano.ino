/*
  Fountain Watering
  Turns a solenoid on and off to fill the fountain when the water level is low

  Ian Blackwell, 12/04/2025
  00-01 Draft using Arduino UNO

*/

#define SENSOR_PIN 2
#define LED_WATERING_PIN 11
#define LED_PWR_PIN 12
#define RELAY_PIN 9
const long OnDelay = 5000;
const long OffDelay = 60000;
int relayState = 0;
long delayTime = 1000;
int waterLevel = 1;

void relayon () {
  digitalWrite(RELAY_PIN, HIGH);  // turn the relay on
  digitalWrite(LED_WATERING_PIN, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  relayState = 1;
  Serial.println("Turning watering on.");
}
void relayoff () {
  digitalWrite(RELAY_PIN, LOW);  // turn the relay off
  digitalWrite(LED_WATERING_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  relayState = 0;
  Serial.println("Turning watering off.");
}
int readSensor() {
  return digitalRead(SENSOR_PIN);
}
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  // initialize digital pin LED_PWR_PIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_WATERING_PIN, OUTPUT);
  pinMode(LED_PWR_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(LED_PWR_PIN, HIGH);
  Serial.println("Watering is off.");
}

// the loop function runs over and over again forever
void loop() {
  waterLevel = readSensor();
  if (waterLevel == 1) { // Waterlevel is not low. If the relay is on, turn it off
    Serial.println("Water level is high.");
    if (relayState == 1) {
      relayoff();
    };
    delayTime = OffDelay;
  } else {              // Waterlevel is low, turn the relay on if it isn't already
    Serial.println("Water level is low.");
    if (relayState == 0) {
      relayon();
    };
    delayTime = OnDelay;
  }

  Serial.print("Checking again in ");
  Serial.print(delayTime / 1000);
  Serial.println(" seconds.");
  delay(delayTime);
}
