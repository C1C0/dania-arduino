void setup() {
  Serial.begin(9600);
  
  // Exercise 1
  Serial.println("\n\n----Exercise1----");

  for(int i = 0; i <= 100; i++){
    Serial.print(i);

    // Avoid printing comma after last number
    if(i != 100){
      Serial.print(','); 
    }
  }



  // Exercise 2
  Serial.println("\n\n----Exercise2----");
  int randomNumber = 0;
  
  if(randomNumber > 0){
    Serial.print(randomNumber);
    Serial.print(" is positive");
  } else if(randomNumber < 0){
    Serial.print(randomNumber);
    Serial.print(" is negative");
  }else{
    // If is neither more nor less than 0, than it's zero ...
    Serial.print(randomNumber);
    Serial.print(" is zero");
  }



  //Exercise 3
  Serial.println("\n\n----Exercise3----");
  float x3 = 3;
  int y3 = 3;

  if(x3 == y3){
    Serial.println("Huray, They are equal");
  }else{
    Serial.println("Ooh, no luck today");
  }

  

  // Exercise 4
  Serial.println("\n\n----Exercise4----");

  // All numbers up to this number are summed up
  int numberOfNaturalNumbers = 10;
  int total = 0;
  
  for(int i = 1; i <= numberOfNaturalNumbers; i++){
    // Shortcut for total = total + i;
    total += i;
  }
  
  Serial.print("Sum of first ");
  Serial.print(numberOfNaturalNumbers);
  Serial.print(" numbers is ");
  Serial.print(total);



  // Exercise 5
  Serial.println("\n\n----Exercise5----");
  
  // We use the same total variable from previous exercise
  total = 0;
  int i5 = 1;
  
  while(i5 <= numberOfNaturalNumbers){
    total += i5;
    i5++;
  }

  Serial.print("Sum of first ");
  Serial.print(numberOfNaturalNumbers);
  Serial.print(" numbers using while loop is ");
  Serial.print(total);



  // Exercise 6
  Serial.println("\n\n----Exercise6----");
  int numberForWhichMuttiplicationsImLookingFor = 3;
  
  for(int i = 1; i <= 10; i++){
    Serial.print(i);
    Serial.print(" : ");
    Serial.print(i * numberForWhichMuttiplicationsImLookingFor);
    Serial.println();
  }



  // Exercise - check if even or odd
  Serial.println("\n\n----Exercise-Check if even or odd----");
  
  int evenOdNumber = random(10, 100);

  // % - modulo
  // 5 % 2 = 1
  // 7 % 4 = 3
  // 123456 % 2 = 0
  // Every even number has modulo of 2 equal zero
  if( evenOdNumber % 2 == 0){
    Serial.print("Number: ");
    Serial.print(evenOdNumber);
    Serial.print(" is EVEN.");
  } else{
    Serial.print("Number: ");
    Serial.print(evenOdNumber);
    Serial.print(" is ODD.");
 }



  // Exercise - check n terms of natural numbers and their sum 
  Serial.println("\n\n----Exercise-check n terms of natural numbers and their sum ----");
  
  // We make make up any natural number
  char number [] = "23568910";
  int totalSum = 0;

  // sizeof tells us, how many characters is in the string
  // we take that information and loops over whole array
  // int num = number[i] - '0' converts char into int
  for(int i = 0; i < sizeof(number) - 1; i++){
    int num = number[i] - '0';
    Serial.println(num);
    totalSum += num;
  }

  Serial.print("Total SUM is: ");
  Serial.print(totalSum);
}

void loop() {

}
