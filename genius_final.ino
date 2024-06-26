#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4
#define LED_AZUL 5

#define BOTAO_VERDE 8
#define BOTAO_AMARELO 9
#define BOTAO_VERMELHO 10
#define BOTAO_AZUL 11

#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

#define TAMANHO_SEQUENCIA 4

int sequenciaLuzes[TAMANHO_SEQUENCIA];

void setup() {
  Serial.begin(9600);
  iniciaPortas();
  iniciaJogo();
}


void iniciaJogo(){
  sequenciaLuzes[0] = LED_AZUL;
  sequenciaLuzes[1] = LED_VERDE;
  sequenciaLuzes[2] = LED_VERMELHO;
  sequenciaLuzes[3] = LED_AMARELO;
}

void iniciaPortas(){
  pinMode(LED_VERDE,OUTPUT);
  pinMode(LED_AMARELO,OUTPUT);
  pinMode(LED_VERMELHO,OUTPUT);
  pinMode(LED_AZUL,OUTPUT);

  pinMode(BOTAO_VERDE,INPUT_PULLUP);
  pinMode(BOTAO_AMARELO,INPUT_PULLUP);
  pinMode(BOTAO_VERMELHO,INPUT_PULLUP);
  pinMode(BOTAO_AZUL,INPUT_PULLUP);
}

void loop() {
  for(int i=0; i<TAMANHO_SEQUENCIA; i++){
    piscaLed(sequenciaLuzes[i]);
  }
  int estadoApertado = pegaRespostaJogador();
  Serial.println(estadoApertado);
}

int checaRespostaJogador() {
  if(digitalRead(BOTAO_VERDE) == LOW) {
     return piscaLed(LED_VERDE);  
  }
  if(digitalRead(BOTAO_AMARELO) == LOW) {
     return piscaLed(LED_AMARELO);  
  }
  if(digitalRead(BOTAO_VERMELHO) == LOW) {
     return piscaLed(LED_VERMELHO);  
  }
  if(digitalRead(BOTAO_AZUL) == LOW) {
     return piscaLed(LED_AZUL);  
  }
  return -1;
}

void piscaSequencia1(){
  piscaLed(LED_VERDE);
  piscaLed(LED_AMARELO);
  piscaLed(LED_VERMELHO);
  piscaLed(LED_AZUL);
  delay(MEIO_SEGUNDO);
}

void piscaSequencia2(){
  digitalWrite(LED_VERDE,HIGH);
  digitalWrite(LED_AMARELO,HIGH);
  digitalWrite(LED_VERMELHO,HIGH);
  digitalWrite(LED_AZUL,HIGH);
  delay(UM_SEGUNDO);
  digitalWrite(LED_VERDE,LOW);
  digitalWrite(LED_AMARELO,LOW);
  digitalWrite(LED_VERMELHO,LOW);
  digitalWrite(LED_AZUL,LOW);
  delay(MEIO_SEGUNDO);
}

int piscaLed(int portaLed){
  digitalWrite(portaLed,HIGH);
  delay(UM_SEGUNDO);
  digitalWrite(portaLed,LOW);
  delay(MEIO_SEGUNDO);
  return portaLed;
}