#include <DHT.h>
#include <LiquidCrystal.h>

DHT dht (2, DHT22);
const int ldrPin = A0;
const int vermelho = 13;
const int amarelo = 12;
const int verde = 11;
const int buzzer = 10;
int potValor = 0;
int tempoCorridoBaixoDHTHigh = 0;
int tempoLeituraBaixoDHTHigh = 0;
int tempoCorridoBaixoDHTLow = 0;
int tempoLeituraBaixoDHTLow = 0;

LiquidCrystal lcd(9,8,7,6,5,4); 

float temperatura = 0;
float umidade = 0;
int volta = 0;
int tempoCorrido = 0;
int tempoLeitura = 0;
float temperaturaTotal = 0;
float umidadeTotal = 0;
float ldrValueTotal = 0;
float ldrValue = 0;


void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
}

void loop() {

  tempoCorrido = millis();

  if(tempoCorrido - tempoLeitura >= 1000){

    temperatura = dht.readTemperature();
    temperaturaTotal = temperatura + temperaturaTotal;
    umidade = dht.readHumidity();
    umidadeTotal = umidade + umidadeTotal;
    ldrValue = analogRead(A0);
    Serial.println("LdrValue: ");
    Serial.println(ldrValue);
    ldrValueTotal = ldrValue + ldrValueTotal;

    volta = volta + 1;

    if(volta == 5){

      temperaturaTotal = temperaturaTotal / 5;
      umidadeTotal = umidadeTotal / 5;
      ldrValueTotal = ldrValueTotal / 5;

      //Serial.println("temperatura = ");
      //Serial.println(temperatura);
      //Serial.println("temperatura total = ");
      //Serial.println(temperaturaTotal);

      lcd.clear();
      //lcd.setCursor(0,1);

      //lcd.print("Luz = "); 
      //lcd.print(ldrValue); 

      //lcd.print("Temperatura = "); 
      //lcd.print(temperaturaTotal); 

      //lcd.print("Umidade = "); 
      //lcd.print(umidade); 


      if (ldrValueTotal < 300) {
          digitalWrite(verde, HIGH);
          digitalWrite(amarelo, LOW);
          digitalWrite(vermelho, LOW);
          digitalWrite(buzzer, LOW);
          noTone(buzzer);
      } else if (ldrValueTotal > 300 && ldrValueTotal < 500){
          digitalWrite(verde, LOW);
          digitalWrite(amarelo, HIGH);
          digitalWrite(vermelho, LOW);
          digitalWrite(buzzer, HIGH);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Ambiente meia luz");
      } else {
          digitalWrite(verde, LOW);
          digitalWrite(amarelo, LOW);
          digitalWrite(vermelho, HIGH);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Ambiente muito claro");
      }  


      if(temperaturaTotal < 10 && umidadeTotal < 50){

          tempoCorridoBaixoDHTHigh = millis();
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Temp e Umid Baixa"); 
          lcd.setCursor(0,1);
          lcd.print(temperaturaTotal);
          lcd.print(" e "); 
          lcd.print(umidadeTotal);       


          if(tempoCorridoBaixoDHTHigh - tempoLeituraBaixoDHTHigh >= 3000){

            digitalWrite(buzzer, HIGH);
            tone(buzzer, 1000);

            tempoLeituraBaixoDHTHigh = tempoCorridoBaixoDHTHigh;
          }

          tempoCorridoBaixoDHTLow = millis();

          if(tempoCorridoBaixoDHTLow - tempoLeituraBaixoDHTLow >= 6000){
            digitalWrite(buzzer, LOW);
            noTone(buzzer);
            tempoLeituraBaixoDHTLow = tempoCorridoBaixoDHTLow;

          }
      } else if(temperaturaTotal > 15 && umidadeTotal > 70){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Temp e umid alta"); 
        lcd.setCursor(0,1);
        lcd.print(temperaturaTotal); 
        lcd.print(" e "); 
        lcd.print(umidadeTotal); 
        digitalWrite(buzzer, HIGH);
        tone(buzzer, 1000);      


      }else if(temperaturaTotal < 10 && umidade > 80){
        lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Umid Alta,Temp Baixa"); 
         lcd.setCursor(0,1);
         lcd.print(umidadeTotal);
         lcd.print(" e "); 
         lcd.print(temperaturaTotal);        

      }else if(temperaturaTotal > 15 && umidade < 60){
        lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Umi Baixa,Temp Alta"); 
         lcd.setCursor(0,1);
         lcd.print(umidadeTotal);
         lcd.print(" e "); 
         lcd.print(temperaturaTotal);

      }else if (temperaturaTotal > 10 && temperaturaTotal < 15 && umidadeTotal > 60 && umidadeTotal < 80 ){
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Umi Ok,Temp Ok"); 
         lcd.setCursor(0,1);
         lcd.print(umidadeTotal);
         lcd.print(" e "); 
         lcd.print(temperaturaTotal);


      }else if(temperaturaTotal > 10 && temperaturaTotal < 15 && umidadeTotal  < 60){
        lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Umi Baixa,TempOk"); 
         lcd.setCursor(0,1);
         lcd.print(umidadeTotal);
         lcd.print(" e "); 
         lcd.print(temperaturaTotal);

      }else if(temperaturaTotal > 10 && temperaturaTotal < 15 && umidadeTotal  > 80){
        lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Umi Alta,Temp Ok"); 
         lcd.setCursor(0,1);
         lcd.print(umidadeTotal);
         lcd.print(" e "); 
         lcd.print(temperaturaTotal);
      }else if(umidadeTotal > 60 && umidadeTotal < 80 && temperaturaTotal < 10){
        lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Umi OK,Temp Baixa"); 
         lcd.setCursor(0,1);
         lcd.print(umidadeTotal);
         lcd.print(" e "); 
         lcd.print(temperaturaTotal);
      }else if(umidadeTotal > 60 && umidadeTotal < 80 && temperaturaTotal > 15){
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Umi OK,Temp Alta"); 
         lcd.setCursor(0,1);
         lcd.print(umidadeTotal);
         lcd.print(" e "); 
         lcd.print(temperaturaTotal);
      } else if(temperaturaTotal >= 10 && temperaturaTotal <= 15){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Ambiente OK");
        lcd.setCursor(0,1);
        lcd.print("Temperatura = "); 
        lcd.print(temperaturaTotal);
      }

    temperaturaTotal = 0;
    umidadeTotal = 0;
    ldrValueTotal = 0;
    volta = 0;
    }
    
  tempoLeitura = millis();
  }
}
