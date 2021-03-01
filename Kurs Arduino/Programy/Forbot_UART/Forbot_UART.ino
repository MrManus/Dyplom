#define ledRed 8
#define ledGreen 9
#define sensorWindow 3

void setup() {
  Serial.begin(9600); //Ustawienie prędkości transmisji
  Serial.println("Inicjacja systemu alarmowego"); //Jednorazowe wysyłanie tekstu 
  pinMode(ledRed, OUTPUT); //Dioda czerwona
  pinMode(ledGreen,OUTPUT);  //Dioda zielona

  pinMode(sensorWindow, INPUT_PULLUP); //Przcisk

  digitalWrite(ledRed,LOW);  //Wyłączenie diod
  digitalWrite(ledGreen,LOW);
}

void loop() {
  
  if(digitalRead(sensorWindow) == LOW){
    Serial.println("Alarm! Okno nie jest zamknięte"); //Komunikat wysyłany potrem szeregowym
    digitalWrite(ledRed,HIGH); //Czerwona
    digitalWrite(ledGreen,LOW); //Zielona

    while(digitalRead(sensorWindow)==LOW){  //Zatrzymanie w pustej pętni do ponownego zamknięcia okna
      delay(25);  //Opóźnienie do zniwelowania zakłóceń
    }
  }
  else{
    digitalWrite(ledRed,LOW);  //Czerwona
    digitalWrite(ledGreen,HIGH); //Zielona
  }
  
  

}
