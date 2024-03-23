//definindo portas
#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4
#define LED_AZUL 5

//definindo botões
#define BOTAO_VERDE 8
#define BOTAO_AMARELO 9
#define BOTAO_VERMELHO 10
#define BOTAO_AZUL 11

//definindo tempo
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

//definindo quantidade de leds
#define TAMANHO_SEQUENCIA 4
int sequenciaLuzes[TAMANHO_SEQUENCIA];

//main
void setup(){
  Serial.begin(9600);
  iniciaPortas();
  iniciaJogo();
}

void loop(){
  for(int i=0; i<TAMANHO_SEQUENCIA;i++){
    piscaLed(sequenciaLuzes[i]);
  }
  Serial.println(checaRespostaJogador());
}  

//métodos
void iniciaPortas(){
  pinMode(LED_VERMELHO,OUTPUT);//output indica saída de sinal (pulso)
  pinMode(LED_VERDE,OUTPUT);
  pinMode(LED_AMARELO,OUTPUT);
  pinMode(LED_AZUL,OUTPUT);
  pinMode(BOTAO_VERMELHO,INPUT_PULLUP);//input_pullup indica entrada de sinal inverso (apertado não passa sinal, ao invés de apertado manda sinal)
  pinMode(BOTAO_VERDE,INPUT_PULLUP);
  pinMode(BOTAO_AMARELO,INPUT_PULLUP);
  pinMode(BOTAO_AZUL,INPUT_PULLUP);
}

void iniciaJogo(){
  sequenciaLuzes[0] = LED_AZUL;
  sequenciaLuzes[1] = LED_VERDE;
  sequenciaLuzes[2] = LED_VERMELHO;
  sequenciaLuzes[3] = LED_AMARELO;
}

void piscaLed(int portaLed){
  digitalWrite(portaLed,HIGH);
  delay(MEIO_SEGUNDO);
  digitalWrite(portaLed,LOW);
  delay(UM_SEGUNDO);
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

int pegaRespostaJogador(){
    if(digitalRead(BOTAO_VERDE) == LOW){
        return LED_VERDE;
    }
    if(digitalRead(BOTAO_AMARELO) == LOW){
        return LED_AMARELO;
    }
    if(digitalRead(BOTAO_VERMELHO) == LOW){
        return LED_VERMELHO;
    }
    if(digitalRead(BOTAO_AZUL) == LOW){
        return LED_AZUL;
    }
    else return -1;
}