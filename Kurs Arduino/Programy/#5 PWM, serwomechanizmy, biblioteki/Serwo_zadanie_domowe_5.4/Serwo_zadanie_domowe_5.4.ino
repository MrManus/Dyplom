#include <Servo.h> //Biblioteka odpoiedzialna za serwa

Servo serwomechanizm; //Obiekt przez który odwołujemy się do serwa
int pozycja = 0; //Aktualna pozycja serwa 0-180
String odebranaPozycja = "";

void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  serwomechanizm.attach(9); //Serwomechanizm podłączony do pinu 9

  Serial.println("Jaką pozycję serwa chcesz ustawić");

}

void loop() {

  if(Serial.available() > 0){ //Czy Arduino odebrało dane
    odebranaPozycja = Serial.readStringUntil('\n'); //Zapisanie odebranych danych typu string
    pozycja = odebranaPozycja.toInt(); //konwersja odebranej pozycji na typ int
  }
    if(pozycja < 180){  //Sprawdzenie czy pozycja nie ejst za duża
      serwomechanizm.write(pozycja); //Wykonanie ruchu
    }
    else{
      pozycja = 0;
      Serial.println("Błędna pozycja");
    }
  delay(200);
}
