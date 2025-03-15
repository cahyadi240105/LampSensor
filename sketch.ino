#define merah 15
#define kuning 2
#define hijau 4
#define sensor 34  

void setup() {
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int nilai = analogRead(sensor);  
  int mappedValue = map(nilai, 0, 4095, 0, 150);  
  Serial.println(mappedValue); 

  if (mappedValue >= 1 && mappedValue <= 50) {
    digitalWrite(merah, HIGH);
    digitalWrite(kuning, LOW);
    digitalWrite(hijau, LOW);
  } else if (mappedValue > 50 && mappedValue <= 100) {
    digitalWrite(merah, LOW);
    digitalWrite(kuning, HIGH);
    digitalWrite(hijau, LOW);
  } else if (mappedValue > 100 ){
    digitalWrite(merah, LOW);
    digitalWrite(kuning, LOW);
    digitalWrite(hijau, HIGH);
  }else{
    digitalWrite(merah, LOW);
    digitalWrite(kuning, LOW);
    digitalWrite(hijau, LOW);
  }

  delay(500);
}