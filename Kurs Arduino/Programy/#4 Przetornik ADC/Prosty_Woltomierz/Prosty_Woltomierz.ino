int odczytanaWartosc = 0; //Zmmienna w której przechowywana jest wartosc odczytywana z ADC
float napiecie = 0; //Wartosc przeliczana na napiecie w V

void setup() {
  Serial.begin(9600); //Uruchomienie komunikacju przez USART

}

void loop() {
  odczytanaWartosc = analogRead(A5); //Odczytujemy watosc napiecia
  napiecie = odczytanaWartosc * (5.0/1024.0); //Obliczenie wartosci w V  
  Serial.println(napiecie); //Wysyłana do terminala
  delay(200); //Lekkie opóźnienie, by łatwiej było odczytać wnoski

}
