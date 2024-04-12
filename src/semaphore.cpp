const int LED_VERDE_CARRO = 13;
const int LED_AMARELO_CARRO = 12;
const int LED_VERMELHO_CARRO = 11;

const int LED_VERMELHO_PEDESTRE = 10;
const int LED_VERDE_PEDESTRE = 9;

const int PIEZO = 7;

void setup() {
  pinMode(LED_VERDE_CARRO, OUTPUT);
  pinMode(LED_AMARELO_CARRO, OUTPUT);
  pinMode(LED_VERMELHO_CARRO, OUTPUT);
  
  pinMode(LED_VERMELHO_PEDESTRE, OUTPUT);
  pinMode(LED_VERDE_PEDESTRE, OUTPUT);
  
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  trafficLightLogic(LED_VERDE_CARRO, 5000);
  trafficLightLogic(LED_AMARELO_CARRO, 2000);
  trafficLightLogic(LED_VERMELHO_CARRO, 5000);
}

void trafficLightLogic(int led, int time) {
  digitalWrite(led, 1);
  if(led == LED_VERMELHO_CARRO) {
    digitalWrite(LED_VERMELHO_PEDESTRE, 0);
    digitalWrite(LED_VERDE_PEDESTRE, 1);
    
    while(time > 0) {
      if(time > 1000) {
        tone(PIEZO, 300, 250);
      }
      else {
        tone(PIEZO, 300, 1000);
      }
      delay(1000);
      time -= 1000;
    }
    
    digitalWrite(LED_VERDE_PEDESTRE, 0);
  } else {
    digitalWrite(LED_VERMELHO_PEDESTRE, 1);
    delay(time);
  }
  
  digitalWrite(led, 0);
}

