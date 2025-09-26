// Lab 03 - WASD Control of the Robot
// The following code was inspired by video game features and 
// It enables the robot to turn left (A key), right (D key), forwards (W key), and backwards (S key)
// Further, pressing Q will turn the robot in place, and pressing X will stop the robot
// Group Members: Liana, Geoff, Amrita, Flora

// Define Motor A connections
#define enA 9
#define in1 8
#define in2 7

// Define Motor B connections
#define enB 10
#define in3 12
#define in4 11

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
  Serial.println("Ready for commands: W/S/A/D/Q/X");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'W' || command == 'w') {
      forwards();
    } else if (command == 'S' || command == 's') {
      backwards();
    } else if (command == 'A' || command == 'a') {
      turnRight();
    } else if (command == 'D' || command == 'd') {
      turnLeft();
    } else if (command == 'Q' || command == 'q') {
      turnInPlace();
    } else if (command == 'X' || command == 'x') {
      stopMotors();
    }
  }
}

void forwards() {
  Serial.println("Moving forwards");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void backwards() {
  Serial.println("Moving backwards");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

void turnLeft() {
  Serial.println("Turning Right (while moving)");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);

  analogWrite(enB, 0); // stop right motor
}

void turnRight() {
  Serial.println("Turning Left (while moving)");
  analogWrite(enA, 0); // stop left motor

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void turnInPlace() {
  Serial.println("Turning in place");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

void stopMotors() {
  Serial.println("Stopping motors");
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}