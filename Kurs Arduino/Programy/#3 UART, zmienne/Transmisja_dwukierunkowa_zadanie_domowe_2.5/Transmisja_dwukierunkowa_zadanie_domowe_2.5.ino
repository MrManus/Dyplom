#define zielona 8
#define czerwona 9

String odebraneDane = ""; //Pusty ciąg znaków
bool czyZielonaSiePali = false; //Zmienne pamiętające stan diod
bool czyCzerwonaSiePali = false;

void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  pinMode(zielona, OUTPUT); //Konfiguracja wyjść
  pinMode(czerwona, OUTPUT);

  digitalWrite(zielona, LOW); //Wyłącczenie diod
  digitalWrite(czerwona, LOW);

  Serial.println("Jaką diodę chcesz przestawić?");
}

void loop() {

  if(Serial.available() > 0) { //Czy Arduino odebrało danne
    odebraneDane = Serial.readStringUntil('\n'); //Jeśli tak, to odczytaj je do znaku końca lini i zapisz w zmiennej odebraneDane

    if(odebraneDane != "czerwona" and odebraneDane != "zielona"){ //Czy odebrane słowo różne od zielona i czerwona
      Serial.println("Błędna komenda spróbuj ponownie");
      Serial.println("Jaką diodę chcesz przestawić?");
    }
    
    if(odebraneDane == "zielona" and czyZielonaSiePali == false){ //Czy odebrano zielona i czy zielona jest zgaszona
      digitalWrite(zielona, HIGH);  //Jesli tak to zapal zieloną diode
      Serial.println("Włączona dioda jest " + odebraneDane + "."); //Wyswietl komunikat
      czyZielonaSiePali = true; //zapamiętaj stan diody
      delay(1000);  //Opoźnienie dla zaobserwowania diody
    }
    else if(odebraneDane == "zielona" and czyZielonaSiePali == true){ //Czy odebrano zielona i czy zielona się pali
      digitalWrite(zielona, LOW); // Jeśli tak to zgaś zielona
      Serial.println("Zgaszona dioda jest " + odebraneDane + ".");  //Wyświetl komunikat
      czyZielonaSiePali = false;  //zapamiętaj stan diody
      delay(1000);
    }

    if(odebraneDane == "czerwona" and czyCzerwonaSiePali == false){ //Czy odebrano czerwona i czy czerwona jest zgaszona
      digitalWrite(czerwona, HIGH); //Jeśli tak to zapal czerwoną diodę
      Serial.println("Włączona dioda jest " + odebraneDane + "."); //Wyświetl komunikat
      czyCzerwonaSiePali = true; //Zapamiętaj stan diody
      delay(3000);  //Opóźnienie dla zaobserwowania diody
    }
    else if(odebraneDane == "czerwona" and czyCzerwonaSiePali == true){ //Czy odebrano czerwona i czy czerwona jest zgaszona
      digitalWrite(czerwona, LOW); //Jeśli tak to zapal czerwoną diodę
      Serial.println("Zgaszona dioda jest " + odebraneDane + "."); //Wyświetl komunikat
      czyCzerwonaSiePali = false; //Zapamiętaj stan diody
      delay(3000);  //Opóźnienie dla zaobserwowania diody
    }
  }
}
