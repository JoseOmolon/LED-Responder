// Pin assignments for LEDs
int Redled = 8;       // Red LED connected to digital pin 8
int Yellowled = 7;    // Yellow LED connected to digital pin 7
int Greenled = 6;     // Green LED connected to digital pin 6

// Pin assignments for buttons
int Key1 = 5;         // Red button connected to digital pin 5
int Key2 = 4;         // Yellow button connected to digital pin 4
int Key3 = 3;         // Green button connected to digital pin 3
int KeyRest = 2;      // Reset button connected to digital pin 2

// Variables to store current button states
int Red;
int Yellow;
int Green;

void setup() {
  // Set LED pins as OUTPUT to control their state (on/off)
  pinMode(Redled, OUTPUT);
  pinMode(Yellowled, OUTPUT);
  pinMode(Greenled, OUTPUT); // ⚠️ FIXED: original had typo "OUTPUt"

  // Set button pins as INPUT to read button states
  pinMode(Key1, INPUT);
  pinMode(Key2, INPUT);
  pinMode(Key3, INPUT);
  pinMode(KeyRest, INPUT);
}

void loop() {
  // Read the state of each color button
  Red = digitalRead(Key1);         // Check if Red button is pressed
  Yellow = digitalRead(Key2);      // Check if Yellow button is pressed
  Green = digitalRead(Key3);       // ⚠️ FIXED: original had typo "ditialRead"

  // Execute LED functions if corresponding button is pressed
  if (Red == HIGH) Red_YES();         // If Red button pressed, activate Red LED logic
  if (Yellow == HIGH) Yellow_YES();   // If Yellow button pressed, activate Yellow LED logic
  if (Green == HIGH) Green_YES();     // If Green button pressed, activate Green LED logic
}

// Red LED stays ON until Reset button is pressed
void Red_YES() {
  while (digitalRead(KeyRest) == LOW) {  // Stay in loop until Reset is pressed
    digitalWrite(Redled, HIGH);      // Turn ON Red LED
    digitalWrite(Greenled, LOW);     // Turn OFF others
    digitalWrite(Yellowled, LOW);
  }
  clear_led(); // Once reset is pressed, turn off all LEDs
}

// Yellow LED stays ON until Reset button is pressed
void Yellow_YES() {
  while (digitalRead(KeyRest) == LOW) {
    digitalWrite(Redled, LOW);       // Turn OFF Red
    digitalWrite(Greenled, LOW);     // Turn OFF Green
    digitalWrite(Yellowled, HIGH);   // Turn ON Yellow
  }
  clear_led(); // All LEDs OFF after reset
}

// Green LED stays ON until Reset button is pressed
void Green_YES() {
  while (digitalRead(KeyRest) == LOW) {
    digitalWrite(Redled, LOW);
    digitalWrite(Greenled, HIGH);    // Turn ON Green
    digitalWrite(Yellowled, LOW);
  }
  clear_led(); // LEDs OFF after reset
}

// Helper function to turn all LEDs OFF
void clear_led() {
  digitalWrite(Redled, LOW);
  digitalWrite(Greenled, LOW);
  digitalWrite(Yellowled, LOW);
}
