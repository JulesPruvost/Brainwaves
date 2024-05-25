//                                 forward  backward  left    right
const int leftFrontIn = 8;   //  HIGH      LOW     HIGH    LOW
const int leftFrontOut = 9;  //  LOW       HIGH    LOW     HIGH
const int leftBackIn = 10;
const int leftBackOut = 11;

const int rightFrontIn = 2;   // HIGH      LOW     LOW     HIGH
const int rightFrontOut = 3;  // LOW       HIGH    HIGH    LOW
const int rightBackIn = 4;
const int rightBackOut = 5;

String current = "neutral";
String forward = "push";
String backward = "pull";
String left = "left";
String right = "right";
String neutral = "neutral";

String actionPart = "neutral";

float powerPart = 0.0;
float power = 0.0;

void setup() {
  pinMode(leftFrontIn, OUTPUT);
  pinMode(leftFrontOut, OUTPUT);
  pinMode(leftBackIn, OUTPUT);
  pinMode(leftBackOut, OUTPUT);

  pinMode(13, OUTPUT);

  pinMode(rightFrontIn, OUTPUT);
  pinMode(rightFrontOut, OUTPUT);
  pinMode(rightBackIn, OUTPUT);
  pinMode(rightBackOut, OUTPUT);

  Serial.begin(9600);
  Serial.setTimeout(1);
  pinMode(13, HIGH);
  delay(1000);
  pinMode(13, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String receivedString = Serial.readString();

    //int commaIndex = receivedString.indexOf(',');
    int actionIndex = receivedString.indexOf("action:");
    if (actionIndex != -1) {
      // Adjust the start index to the character after "action:"
      actionIndex += 7;  // Length of "action:"

      // Find the index of the comma separating action and power
      int commaIndex = receivedString.indexOf(',', actionIndex);

      // Extract the action part from the string
      String actionPart = receivedString.substring(actionIndex, commaIndex);
      current = actionPart;
    }
  }

  power = 254;

  if (current == forward) {
    analogWrite(leftFrontIn, 0);
    analogWrite(leftBackIn, 0);

    analogWrite(leftFrontOut, power);
    analogWrite(leftBackOut, power);

    analogWrite(rightFrontIn, 0);
    analogWrite(rightBackIn, 0);

    analogWrite(rightFrontOut, power);
    analogWrite(rightBackOut, power);

    pinMode(13, HIGH);

    delay(2000);
    pinMode(13, LOW);
  }

  else if (current == backward) {

    analogWrite(leftFrontIn, power);
    analogWrite(leftBackIn, power);

    analogWrite(leftFrontOut, 0);
    analogWrite(leftBackOut, 0);

    analogWrite(rightFrontIn, power);
    analogWrite(rightBackIn, power);

    analogWrite(rightFrontOut, 0);
    analogWrite(rightBackOut, 0);

    pinMode(13, HIGH);

    delay(2000);
    pinMode(13, LOW);
  }

  else if (current == left) {

    analogWrite(leftFrontIn, 0);
    analogWrite(leftBackIn, 0);

    analogWrite(leftFrontOut, power);
    analogWrite(leftBackOut, power);

    analogWrite(rightFrontIn, power);
    analogWrite(rightBackIn, power);

    analogWrite(rightFrontOut, 0);
    analogWrite(rightBackOut, 0);

    pinMode(13, HIGH);

    delay(2000);
    pinMode(13, LOW);
  }

  else if (current == right) {

    analogWrite(leftFrontIn, power);
    analogWrite(leftBackIn, power);

    analogWrite(leftFrontOut, 0);
    analogWrite(leftBackOut, 0);

    analogWrite(rightFrontIn, 0);
    analogWrite(rightBackIn, 0);

    analogWrite(rightFrontOut, power);
    analogWrite(rightBackOut, power);

    pinMode(13, HIGH);

    delay(2000);
    pinMode(13, LOW);
  }

  else if (current == neutral) {

    analogWrite(leftFrontIn, 0);
    analogWrite(leftBackIn, 0);

    analogWrite(leftFrontOut, 0);
    analogWrite(leftBackOut, 0);

    analogWrite(rightFrontIn, 0);
    analogWrite(rightBackIn, 0);

    analogWrite(rightFrontOut, 0);
    analogWrite(rightBackOut, 0);
  }
}
