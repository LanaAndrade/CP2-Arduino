# Edge Computing Checkpoint 2 - Caso Vinheira Agnello

> Status: Developed

![image](![image](https://github.com/LanaAndrade/CP2-Arduino/assets/82892986/39ff7fa2-8f10-473c-bad1-484883cf433d))

Em um ambiente hospitalar, o armazenamento eficiente dos medicamentos não é apenas uma questão logística. Está diretamente ligado à segurança do paciente e à eficácia dos tratamentos. A má gestão pode comprometer a qualidade dos cuidados prestados.

Nosso projeto possui sensores de temperatura e umidade, para garantir que as vacinas sejam armazenadas sempre em temperatura e teor de umidade corretos, assim como um buzzer que é acionado sempre que os valores se tornam impróprios. Possuímos também um display LCD, para que os valores de temperatura e umidade estejam sempre sob controle, e um sensor de movimento para portas e janelas, que sempre que é acionado acende uma led vermelha e é a movimentação é exibida no monitor, para garantir o controle e a segurança do estoque.

Os valores de temperatura e umidade são exibidos no monitor há cada 5 segundos, para garantir um bom monitoramento, e caso algum valor seja anormal, é acionado um buzzer por 3 segundos, que depois é desligado por 3 segundos.

## Componentes
* 1 Arduino Uno R3
* 1 Placa de Ensaio
* 2 LED's (Utilizados para indicar o estado do ambiente)
* 1 LED Vermelho (Sensor de movimento ativado)
* 1 LED Verde (Normal)
* 1 DHT22 (Sensor de humidade e temperatura)
* 1 Buzzer (Utilizado para soar um aviso sonoro em caso do estado estar Crítico ou em Alerta)
* 1 Display LCD
* 1 Sensor de movimento
* 3 Resistores de 1kΩ
* 21 Cabos Jumper Macho x Macho
  
## Desenvolvimento
O projeto foi desenvolvido utilizando a plataforma Wokwi para a montagem do esquema e para a codificação. O projeto será validado pelo professor responsável.

## Código Fonte
[Link para o simulador](https://wokwi.com/projects/382238469380023297)

### Vídeo do Projeto
<a href="[https://www.youtube.com/watch?v=Vo5QHUxvhsI](https://youtu.be/WCP_qn4kbSU?si=f2CN_PlewkSakOXX)"><img src="![image](https://github.com/LanaAndrade/CP2-Arduino/assets/82892986/e8df9490-1e12-4be2-bb05-aa5085358bf0)
" alt="Imagem circuito Arduíno" border="0"></a>

## Desenvolvedores

Desenvolvedor | RM
:-----------: | :------:
Caio Freitas  | 553190
Lana Andrade  | 552596

