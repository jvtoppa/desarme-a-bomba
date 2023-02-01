void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, INPUT_PULLUP);

  
}

void loop() {
  //DECLARAÇÕES
  int i;
  int Timer = 1000;
  int flag = 0;
  int qtdAcertos = 0;

  Serial.print("Você tem ");
  Serial.print(Timer/100);
  Serial.print(" tentativas.\n");
  //LOOP PRINCIPAL
    while(Timer >= 100 && flag == 0 && qtdAcertos != 5){

      

      for(i = 2; i < 7; i++){

      digitalWrite(i, HIGH);
      


      if(i == 4 && digitalRead(7) == LOW){

        qtdAcertos++;
        Serial.print("Acertou! ");
        Serial.print(qtdAcertos);
        Serial.print("/5\n");

        if(qtdAcertos == 5){
          digitalWrite(4, LOW);
          break;
        }
      }
      else if(i != 4 && digitalRead(7) == LOW){
        for(i = 2; i < 7; i++){

        digitalWrite(i, HIGH);
        }
        flag = 1;
        break;
      }
      delay(Timer);
      if(flag == 0){

        digitalWrite(i, LOW);
        delay(Timer);
      
      }
    
    }
    if(qtdAcertos != 5) {

    Timer = Timer - 100;
    Serial.print("Você tem ");
    Serial.print(Timer/100);
    Serial.print(" tentativas.\n");
    }
    
  }

  //RECOMEÇANDO O PROGRAMA
  if(flag == 0 && Timer != 0){
    Serial.println("Ganhou!");
  }
  else{
    Serial.println("Perdeu!");
  }
  Serial.println("Reiniciando...");
  delay(3000);
  for(i = 2; i < 7; i++){

    digitalWrite(i, LOW);

  }
  Serial.println("-x-");
  delay(1000);


}