void setup() {
  Serial.begin(9600);

  // Exercise 1
  Serial.println(multiplier(11.348, 23.435));
}

void loop() {

}

// Exercise 1
float multiplier(float x, float y){
  return x * y;
}
