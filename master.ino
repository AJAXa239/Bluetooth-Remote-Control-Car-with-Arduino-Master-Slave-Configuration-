// Arduino code for the transmitter using Funduino Joystick Shield and Bluetooth

// Pin definitions for the joystick and buttons
#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define BUTTON_A 2 // Forward
#define BUTTON_B 3 // right
#define BUTTON_C 4 // Backward
#define BUTTON_D 5 // left

#define BUTTON_E 6

// Deadzone to avoid unintentional movement
#define DEADZONE 200

// Bluetooth commands
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define STOP 'S'

void setup() {
  // Initialize joystick and button pins
  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  pinMode(BUTTON_E, INPUT_PULLUP);

  // Initialize Serial communication for Bluetooth
  Serial.begin(9600);
  Serial.println("Transmitter ready");
}

void loop() {
  int xValue = analogRead(JOYSTICK_X);
  int yValue = analogRead(JOYSTICK_Y);

  // Joystick control for motors
  if (yValue > 512 + DEADZONE) {
    Serial.write(FORWARD); // Move forward
  } else if (yValue < 512 - DEADZONE) {
    Serial.write(BACKWARD); // Move backward
    
  } else if (xValue > 512 + DEADZONE) {
    Serial.write(RIGHT); // Turn right
  } else if (xValue < 512 - DEADZONE) {
    Serial.write(LEFT); // Turn left
  } else {
    Serial.write(STOP); // Stop movement
  }

  // Button controls for additional functions
  if (digitalRead(BUTTON_A) == LOW) {
    Serial.write(FORWARD); // Example: Move forward
  }
  if (digitalRead(BUTTON_C) == LOW) {
    Serial.write(BACKWARD); // Example: Move backward
  }
  if (digitalRead(BUTTON_B) == LOW) {
    Serial.write(LEFT); // Example: Turn right
  }
  if (digitalRead(BUTTON_D) == LOW) {
    Serial.write(RIGHT); // Example: Turn left
  }
  if (digitalRead(BUTTON_E) == LOW) {
    Serial.write(STOP); // Example: Stop movement
  }

  delay(100); // Adjust delay for responsiveness
}
