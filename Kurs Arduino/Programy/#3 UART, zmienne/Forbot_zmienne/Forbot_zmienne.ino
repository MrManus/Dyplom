byte licznik = 0;  //Deklaracja zmiennej

void setup() {
  Serial.begin(9600);  //Inicjalizacja połączenia z PC
}

void loop() {
  Serial.println(licznik); //Wysłanie wartości zmiennej licznik
  licznik =  licznik +1;  //Zwiększenie licznika o 1 
  delay(100); //Opóźnienie, dla lepszej widoczności efektu 

}
