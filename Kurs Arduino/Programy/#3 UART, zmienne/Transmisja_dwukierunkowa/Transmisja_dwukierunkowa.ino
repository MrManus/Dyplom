#define zielona 8
#define czerwona 9

String odebraneDane = ""; //Pusty ciąg znaków

void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  pinMode(zielona, OUTPUT); //Konfiguracja wyjść
  pinMode(czerwona, OUTPUT);

  digitalWrite(zielona, LOW); //Wyłącczenie diod
  digitalWrite(czerwona, LOW);

  Serial.println("Jaką diodę chcesz zapalić?");
}

void loop() {

  if(Serial.available() > 0) { //Czy Arduino odebrało danne
    odebraneDane = Serial.readStringUntil('\n'); //Jeśli tak, to odczytaj je do znaku końca lini i zapisz w zmiennej odebraneDane
    
    if(odebraneDane == "zielona"){ //Czy odebrano zielona
      digitalWrite(zielona, HIGH);  //Jesli tak to zapal zieloną diode
      Serial.println("Włączona dioda jest " + odebraneDane +"."); //Wyswietl komunikat
      delay(3000);  //Opoźnienie dla zaobserwowania diody
      digitalWrite(zielona, LOW); //Zgaś diodę
    }

    if(odebraneDane == "czerwona"){ //Czy odebrano czerwona
      digitalWrite(czerwona, HIGH); //Jeśli tak to zapal czerwoną diodę
      Serial.println("Włączona dioda jest " + odebraneDane +"."); //Wyświetl komunikat
      delay(3000);  //Opóźnienie dla zaobserwowania diody
      digitalWrite(czerwona, LOW); // Zgaś diodę
    }

    if(odebraneDane != "czerwona" and odebraneDane != "zielona"){ //Czy odebrane słowo różne od zielona i czerwona
      Serial.println("Błędna komenda spróbuj ponownie");
      Serial.println("Jaką diodę chcesz zapalić?");
    }
    
  }
}
