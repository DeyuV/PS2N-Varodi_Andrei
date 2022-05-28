float Temperatura(){
  float sumaTemperatura = 0;
  int i;
  
  for(i = 0; i < 10; i++){
    int reading = analogRead(5);
    float voltage = reading * 5.0;
    voltage /= 1024.0;
    float temperaturaCelsius = (voltage - 0.5) * 100;
    sumaTemperatura += temperaturaCelsius;
  }

  return (sumaTemperatura / (float)i) - 60;
}

void setup() {
  Serial.begin(9600); // serial monitor baud rate
}

void loop() {
  Serial.println(Temperatura());
  delay(1000);
}
