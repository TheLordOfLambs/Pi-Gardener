// this is a first version so values of sensor are predefined, they be soon read by sensors

int message = 0;
String message2 ;
int temp = 23 ;        
int humid1 = 25 ;
int humid2 = 60;
int lum = 50 ;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600); 

  

}

void loop() {

  if (Serial.available())  {
    message = Serial.read()-'0';  // subtracting the 0 character , wich is 48 in ASCII

   
    
    
    if (message == 1){
      
      digitalWrite(2,HIGH);
      delay(1000);
      digitalWrite(2,LOW);
      
      Serial.println(temp,DEC);

  
    }

    if (message == 2){
      
      digitalWrite(3,HIGH);
      delay(1000);
      digitalWrite(3,LOW);
      Serial.println(humid1,DEC);

  
  }

    if (message == 3){
      
      digitalWrite(4,HIGH);
      delay(1000);
      digitalWrite(4,LOW);
      Serial.println(humid2,DEC);
    }
    
   if (message == 9){
      Serial.println(temp,DEC);
      
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      delay(100);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      delay(100);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      delay(100);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      delay(100);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      delay(100);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      
      
    
   }

  
  
   if (message == 4){
      
      digitalWrite(5,HIGH);
      delay(1000);
      digitalWrite(5,LOW);
      Serial.println(lum,DEC);

  
  }
   if (message == 5){
      digitalWrite(2,LOW);
 
      digitalWrite(3,LOW);

      digitalWrite(4,LOW);

      digitalWrite(5,LOW);
  
      digitalWrite(6,HIGH);

      delay(1000);
      
      digitalWrite(6,LOW);

      Serial.println(temp,DEC);

      delay(2000);
      message2 = Serial.readString();
      if (message2 != '0'){

         
        digitalWrite(7, HIGH);
        delay(1000*message2.toInt());
        digitalWrite(7, LOW);



        
      }

  
  }
  
  
  
  
  
  
  
  
  }
}
