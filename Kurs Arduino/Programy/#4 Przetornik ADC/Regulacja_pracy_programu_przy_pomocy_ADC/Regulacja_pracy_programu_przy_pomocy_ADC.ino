int odczytanaWartosc = 0; //Zmienna do przechowywania odczytu ADC
 
void setup() {
  pinMode(8, OUTPUT); //Konfiguracja wyjść pod diodę LED
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  odczytanaWartosc = analogRead(A5); //Odczytanie wartosci z ADC
  odczytanaWartosc = map(odczytanaWartosc, 0, 1023, 1, 5); //Przeskalowanie odczytanej wartosci

  if(odczytanaWartosc == 1){  //Pierwszy zakres
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
  if(odczytanaWartosc == 2){  //Drugi zakres
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }

  if(odczytanaWartosc == 3){  //Trzeci zakres
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
 
  if(odczytanaWartosc == 4){  //Czwartyzakres
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
 
 if(odczytanaWartosc == 5){  //Piąty zakres
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
  }
  delay(50); //Opoxnienie, aby nie odczytywać ADC zbyt szybko
}
