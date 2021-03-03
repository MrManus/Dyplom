#define diodaPIN 3

int wypelnienie = 0;
int zmiana = 5;

void setup() {
  pinMode(diodaPIN, OUTPUT); //Konfiguracja pinu jako wyjscia
}

void loop() {


  if (wypelnienie == 0) { //Jesli wypelnienie jest 0
    while (wypelnienie < 255){
      wypelnienie = wypelnienie + zmiana;; // Zwiekszamy wypelnienie
      analogWrite(diodaPIN, wypelnienie); //Generujemy sygnal o zadanym wypelnieniu
      delay(50); //Małe opóźnienie, aby efekt był widoczny
    }
  }
  else if(wypelnienie == 255){
    while(wypelnienie > 0){
      wypelnienie = wypelnienie - zmiana;
      analogWrite(diodaPIN, wypelnienie); //Generujemy sygnal o zadanym wypelnieniu
      delay(50); //Małe opóźnienie, aby efekt był widoczny
    }
  }

//  delay(50); //Małe opóźnienie, aby efekt był widoczny
}
