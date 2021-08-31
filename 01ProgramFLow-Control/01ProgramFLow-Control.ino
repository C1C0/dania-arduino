int x = 0;
int y = 100;

void setup() {
  Serial.begin(9600);
  
  // conditions
  if(x > y){
    Serial.println("X > Y");
  }else if(x == y){
    Serial.println("X == Y");
  }else{
    Serial.println("X < Y");
  }

  // looping
  // For loop
  for(int i = 0; i < y; i++){
    Serial.println(i);
  }

  // While loop
  int j = 0;
  while(j < 10){
    Serial.println("Whiling ...");
    Serial.print(j);
    j++;
  }
}

void loop() {

}
