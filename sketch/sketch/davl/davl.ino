
void pinoff(int count){
  for( int i=4; i < count; i++){
    digitalWrite(i, LOW);
    delay(1);
  }
}
// the setup routine runs once when you press reset:
void setup() {
  pinMode(13, OUTPUT); 
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  int sensorValue = analogRead(A0);
  delay(2);
  int ss=map(sensorValue,0,610,0,10);
  switch (ss) {
    case 0: 
      pinoff(13);
      digitalWrite(13, LOW);
      break;
    case 1:
      pinoff(12);
      digitalWrite(13, HIGH);
      break;
    case 2:
      pinoff(11);
      digitalWrite(12, HIGH);
      break;
    case 3:
      pinoff(10);
      digitalWrite(11, HIGH);
      break;  
    case 4:
      pinoff(9);
      digitalWrite(10, HIGH);
      break;  
    case 5:
      pinoff(8);
      digitalWrite(9, HIGH);
      break;
     case 6:
      pinoff(7);
      digitalWrite(8, HIGH);
      break;
    case 7:
      pinoff(6);
      digitalWrite(7, HIGH);
      break;
    case 8:
      pinoff(5);
      digitalWrite(6, HIGH);
      break;  
    case 9:
      pinoff(4);
      digitalWrite(5, HIGH);
      break;  
    case 10:
      digitalWrite(4, HIGH);
      break;
         
      // if nothing else matches, do the default
      // default is optional
  }
//   if (sensorValue > 2 && sensorValue < 65 ){
//    digitalWrite(13, HIGH);
//  } else { 
//           if (sensorValue > 2 && sensorValue < 65 ){
//          digitalWrite(13, HIGH);
//          } 
 
  Serial.println(sensorValue);
}
