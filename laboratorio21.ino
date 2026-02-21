#define LED1 13   
#define LED2 12   
#define LED3 11   
#define BOTONCITO 2

int estPulsador = 0;
int estAnterior = HIGH;
int modo = 0;

unsigned long timeAnterior = 0;
unsigned long ultRebote = 0;

int pasoSemaforo = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BOTONCITO, INPUT_PULLUP);

  apagarTodo();
}

void apagarTodo() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void loop() {

  unsigned long timeActual = millis();
  estPulsador = digitalRead(BOTONCITO);

  if (estPulsador == LOW && estAnterior == HIGH && (timeActual - ultRebote > 200)) {

    modo++;
    if (modo > 5) modo = 0;

    if (modo == 5) {
      pasoSemaforo = 0;
      timeAnterior = millis();
    }

    ultRebote = timeActual;
  }

  estAnterior = estPulsador;

  switch (modo) {

    case 0:
      apagarTodo();
      break;

    case 1:
      apagarTodo();
      digitalWrite(LED3, HIGH);
      break;

    case 2:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      delay(100);
      apagarTodo();
      delay(100);
      break;

    case 3:
	apagarTodo();
	digitalWrite(LED2, HIGH);
	delay(100); 
	digitalWrite(LED2, LOW);
	delay(100);  
      break;

    case 4:
      apagarTodo();
      break;

    case 5:
      modoSemaforo();
      break;
  }
}

void modoSemaforo() {

  if (millis() - timeAnterior >= 1000) {
    timeAnterior = millis();
    pasoSemaforo++;
    if (pasoSemaforo > 2) pasoSemaforo = 0;
  }

  apagarTodo();

  if (pasoSemaforo == 0) {
    digitalWrite(LED1, HIGH);  // Rojo
  }
  else if (pasoSemaforo == 1) {
    digitalWrite(LED2, HIGH);  // Amarillo
  }
  else if (pasoSemaforo == 2) {
    digitalWrite(LED3, HIGH);  // Verde
  }
}