//definindo portas
#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4
#define LED_AZUL 5

//definindo tempo
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

//definindo quantidade de leds
#define TAMANHO_SEQUENCIA 4
int sequenciaLuzes[TAMANHO_SEQUENCIA];

//main
void setup(){
  iniciaPortas();
  iniciaJogo();
}

void loop(){
  for(int i=0; i<TAMANHO_SEQUENCIA;i++){
    piscaLed(sequenciaLuzes[i]);
  }
}  

//métodos
void iniciaPortas(){
  pinMode(LED_VERMELHO,OUTPUT);//output indica saída de sinal (pulso)
  pinMode(LED_VERDE,OUTPUT);
  pinMode(LED_AMARELO,OUTPUT);
  pinMode(LED_AZUL,OUTPUT);
}

void iniciaJogo(){
  sequenciaLuzes[0] = LED_VERDE;
  sequenciaLuzes[1] = LED_VERMELHO;
  sequenciaLuzes[2] = LED_AMARELO;
  sequenciaLuzes[3] = LED_AZUL;
}

void piscaLed(int portaLed){
  digitalWrite(portaLed,HIGH);
  //delay(MEIO_SEGUNDO);
  digitalWrite(portaLed,LOW);
  //delay(UM_SEGUNDO);
}


void piscaSequencial2(){
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

void piscaSequencial(){
  piscaLed(LED_VERDE);
  piscaLed(LED_AMARELO);
  piscaLed(LED_VERMELHO);
  piscaLed(LED_AZUL);
  delay(MEIO_SEGUNDO);
}