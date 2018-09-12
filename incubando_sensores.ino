#include <Servo.h> // Inclui a Biblioteca Servo.h

int Pin_LDR = A0;    //Usamos o pino 0 analógico (A0) LDR
float Leitura_LDR ; //Variável do tipo Integer para armazenar a leitura do LDR
int buzzer = 5; //porta buzzer
int val; //LM35
int tempPin = A2; //PORTA LM35
int portab = 2; //porta botao
int valb = 0; //variável para ler o estado do botao
int valor;
Servo meuservo; // Cria o objeto servo para programação
int angulo = 0; // Ajusta o ângulo inicial do Servo
 
void setup(){
  Serial.begin(9600); //Iniciamos a comunicação serie
  pinMode(buzzer,OUTPUT);
  pinMode(portab, INPUT);
  meuservo.attach(9); // Declara o pino do servo
}

void loop(){
//LM35
valor = analogRead(Pin_LDR);
val = analogRead(tempPin);


float mv = ( val/1024.0)*5000; 
float cel = mv/10;

//LDR
   //Obtemos a leitura da resistência LDR
  //Armazenámo-la numa variável de tipo integer
   
Serial.println(valor);  //Mostramos a leitura pelo monitor serie

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();

//botao
valb = digitalRead(portab);  // ler o valor de entrada


//condicao de disparo do alarme aos 32C
  if(valor < 300 && cel>32 && valb){
    tone(buzzer,392);  
    angulo = 70; 
    meuservo.write(angulo); // Comando para angulo específico 

    
//Condiçao de disparo do alarme aos 42C
         if(valor < 300 && cel>42 && valb){
            tone(buzzer,392); 
            angulo = 150;
           meuservo.write(angulo); // Comando para angulo específico   
              
        }
    }

  else{
    noTone(buzzer);
    int angulo = 0; // Ajusta o ângulo inicial do Servo
    meuservo.write(angulo);
  }

  delay(1000);

}
