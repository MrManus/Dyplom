#include <Servo.h> //Biblioteka odpoiedzialna za serwa
#define potencjometr A5 

Servo serwomechanizm; //Obiekt przez który odwołujemy się do serwa
int pozycja = 0; //Aktualna pozycja serwa 0-180
int nowaPozycja = 0; //Nowa pozycja 0 - 180T
String odebranaPozycja = ""; //Pozycja odebrana przez UART
int odczytZADC = 0; //Zmienna do przechowania wartosci odczytanej z ADC
 
void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  serwomechanizm.attach(9); //Serwomechanizm podłączony do pinu 9

  Serial.println("Jaką pozycję serwa chcesz ustawić"); //Wyswietlenie komunikatu

}

void loop() {
  odczytZADC = analogRead(potencjometr); //Odczytanie wartosci z ADC
  odczytZADC = map(odczytZADC, 0, 1023, 0, 180); //Przeskalowanie odczytanej z ADC wartości
  nowaPozycja = odczytZADC;
//  if(Serial.available() > 0){ //Czy Arduino odebrało dane
//    odebranaPozycja = Serial.readStringUntil('\n'); //Zapisanie odebranych danych typu string
//    nowaPozycja = odebranaPozycja.toInt(); //konwersja odebranej pozycji na typ int
//  }

  if(abs(nowaPozycja - pozycja) > 5){ //Sprawdzenie czy należy wykonać ruch, ruch tylko gdy należy dokonać zmiany o wiecej niż 5 stopni 
      pozycja = nowaPozycja; //Pzypisanie nowej pozycji 
      if(pozycja <= 180){  //Sprawdzenie czy pozycja nie ejst za duża
        Serial.print("Wybrana pozycja to: "); //Wyswietlenie komunikatów
        Serial.println(pozycja);
        serwomechanizm.write(pozycja); //Wykonanie ruchu
      }
      else{
        pozycja = 0; // Zerowanie pozycji w razie podania za dużej wartosci
        nowaPozycja = 0;
        Serial.println("Błędna pozycja"); //Wyswietlenie komunikatu o błędzie
      }
  }
  delay(200);
}
