//const int LED1 = 13;
#define LED1 13
#define LED2 12
#define LED3 11

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, HIGH);
  delay(3000);
  digitalWrite(LED1, LOW);
  delay(100);
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);
  delay(100);
  digitalWrite(LED3, HIGH);
  delay(3000);
  digitalWrite(LED3, LOW);
  delay(100);
}
