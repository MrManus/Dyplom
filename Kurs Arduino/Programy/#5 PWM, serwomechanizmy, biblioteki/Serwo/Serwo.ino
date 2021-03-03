#include <Servo.h> //Biblioteka odpowiedzialna za serwa 

Servo serwomechanizm; //Tworzymy obiekt, dzieki któremu możemy odwoływać się do serwa
int pozycja = 0; //Aktualna pozycja serwa 0-180
int zmiana = 6; //O ile zmienia się pozycja serwa
int opoznienie = 200; //Opóźnienie miedzy kolejną zmianą pozycji
int zmianaOpoznienia = 50; //O ile zmienia się opóźnienie miedzy kolejną zmianą pozycji 

void setup() {
  serwomechanizm.attach(9); //Serwomechanizm podłączony do pinu 9

}

void loop() {
  if (pozycja <180) { //Jesli pozycja miesci się w zakresie
    serwomechanizm.write(pozycja); //Wykonaj ruch
  } 
  else { //Jeżeli nie, to owrót na początek
    pozycja=0;
    opoznienie = 200;
  }

  pozycja = pozycja + zmiana; // Zwiększenie aktualnej pozycji serwa
  opoznienie = opoznienie + zmianaOpoznienia;
  delay(opoznienie); //Opóźnienie dla zaobserwowania efektu    
  
}
