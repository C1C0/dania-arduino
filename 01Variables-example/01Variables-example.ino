char a [] = "Hello ";
char b [] = "You one.";

// for some reason prints
// "No waYou one."
// Probably the pointer returned to the last known variable
char c [5] = "No way this is longer";

int one = 1;
float onedot = 1.1;
bool falsey = false;
bool truethy = true;
char y = "z";
char x = a;

void setup() {
  //clock rate
  //speed of communication between pc and constroller
  Serial.begin(9600);
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);

  // Prints: 1
  Serial.println(one);
  // Prints: 1.10
  Serial.println(onedot);
  // Prints: 0
  Serial.println(falsey);
  // Prints: 1
  Serial.println(truethy);
  // Prints: * (dont't know why)
  Serial.println(y);
  // Prints: 
  Serial.println(x);
}

void loop() {

}
