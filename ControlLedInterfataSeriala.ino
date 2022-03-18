String comanda;
char hex[3];
int r = 11;
int g = 10;
int b = 9;

void setup() {
 pinMode(LED_BUILTIN, OUTPUT);
 pinMode(r, OUTPUT);
 pinMode(g, OUTPUT);
 pinMode(b, OUTPUT);
 Serial.begin(9600);
}

void loop() {

 if (Serial.available() > 0){
   comanda = Serial.readString();  
 }
   
  if(comanda.charAt(0) == '1'){
    if(comanda.charAt(2) == 'A')
   		digitalWrite(LED_BUILTIN, HIGH);
    else if(comanda.charAt(2) == 'S')
      	digitalWrite(LED_BUILTIN, LOW);
  }else if(comanda.charAt(0) == '2'){
    comanda.substring(2,4).toCharArray(hex, 3);
    analogWrite(r, Hex2Dec(hex));
    comanda.substring(4,6).toCharArray(hex, 3);
    analogWrite(g, Hex2Dec(hex));
    comanda.substring(6,8).toCharArray(hex, 3);
    analogWrite(b, Hex2Dec(hex));
  }
}

int Hex2Dec(char hex[]){
  return (int) strtol(hex, 0, 16);
}