#define LED1 13  
#define LED2 12  
#define LED3 11  
#define LED4 10  
#define LED5 9   

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {

  for (int numero = 0; numero <= 20; numero++) {

    digitalWrite(LED1, (numero >> 0) & 1);
    digitalWrite(LED2, (numero >> 1) & 1);
    digitalWrite(LED3, (numero >> 2) & 1);
    digitalWrite(LED4, (numero >> 3) & 1);
    digitalWrite(LED5, (numero >> 4) & 1);

    delay(1000);
  }

}