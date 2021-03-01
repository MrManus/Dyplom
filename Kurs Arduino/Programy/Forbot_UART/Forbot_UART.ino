void setup() {
  Serial.begin(9600); //Ustawienie prędkości transmisji
  Serial.println("Inicjacja systemu alarmowego"); //Jednorazowe wysyłanie tekstu 
  pinMode(8, OUTPUT); //Dioda czerwona
  pinMode(9,OUTPUT);  //Dioda zielona

  pinMode(3, INPUT_PULLUP); //Przcisk

  digitalWrite(8,LOW);  //Wyłączenie diod
  digitalWrite(9,LOW);
}

void loop() {
  
  if(digitalRead(3) == LOW){
    Serial.println("Alarm! Okno nie jest zamknięte"); //Komunikat wysyłany potrem szeregowym
    digitalWrite(8,HIGH); //Czerwona
    digitalWrite(9,LOW); //Zielona

    while(digitalRead(3)==LOW){  //Zatrzymanie w pustej pętni do ponownego zamknięcia okna
      delay(25);  //Opóźnienie do zniwelowania zakłóceń
    }
  }
  else{
    digitalWrite(8,LOW);  //Czerwona
    digitalWrite(9,HIGH); //Zielona
  }
  
  

}
