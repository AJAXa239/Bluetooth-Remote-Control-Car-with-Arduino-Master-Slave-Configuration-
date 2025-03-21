// Arduino program to control two DC motors using L298N motor driver and a Bluetooth module

// Motor driver pins
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

// Speed control pins (optional for PWM)
#define ENA 8
#define ENB 10


// Bluetooth commands
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define STOP 'S'

void setup() {
  // Set motor driver pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set initial motor state to stopped
  stopMotors();

  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Bluetooth control ready");
}

void loop() {
  // Check if data is available from Bluetooth module
  if (Serial.available()) {
    char command = Serial.read();

    // Process the command
    switch (command) {
      case FORWARD:
        moveForward();
        break;
      case BACKWARD:
        moveBackward();
        break;
      case LEFT:
        turnLeft();
        break;
      case RIGHT:
        turnRight();
        break;
      case STOP:
        stopMotors();
        break;
      default:
        Serial.println("Invalid command");
    }
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); // Adjust speed (0-255)
  analogWrite(ENB, 255); // Adjust speed (0-255)
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255); // Adjust speed (0-255)
  analogWrite(ENB, 255); // Adjust speed (0-255)
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); // Adjust speed (0-255)
  analogWrite(ENB, 255); // Adjust speed (0-255)
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255); // Adjust speed (0-255)
  analogWrite(ENB, 255); // Adjust speed (0-255)
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
