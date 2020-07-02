
#include <TMRpcm.h> // libreria que permite reproducir sonido en Arduino.

#include <SPI.h>

#include <SD.h>

#include <LiquidCrystal.h>


LiquidCrystal lcd(9, 8, 7, 6, 5, 4); //rs E D4 D5 D6 D7

TMRpcm tmrpcm; //Se crea un objeto de la librería TMRpcm llamado Audio. 

long randomNumber;

bool Nvl_1 = 0; //Nivel 1
bool Nvl_2 = 0; //Nivel 2
bool Nvl_3 = 0; //Nivel 3
bool si = 0; //Acierto
bool no = 0; //Desacierto

int Led_1 = 22;
int Led_2 = 23;
int Led_3 = 24;
int Led_4 = 25;
int Led_5 = 26;
int Led_6 = 27;
int t = 2000;
int s = 2000;

const int chipSelect = 53; //


void setup() {

  Serial.begin(9600); //Inicializamos la comunicación serial
  Serial.println("Inicio de sketch - secuencia de numeros aleatorios"); //Escribimos por el puerto serie mensaje de inicio

  tmrpcm.speakerPin = 11; 

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("  Bienvenido ");
  lcd.setCursor(0, 1);
  lcd.print(" a Braille Box!");
  delay(3000);

  lcd.clear();

  inicializar_sd_card();

  //tmrpcm.play("bienvenida.wav");
  //delay(4000);

  pinMode(Nvl_1, INPUT);
  pinMode(Nvl_2, INPUT);
  pinMode(Nvl_3, INPUT);
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
  pinMode(Led_5, OUTPUT);
  pinMode(Led_6, OUTPUT);

   tmrpcm.play("hola.wav");
  delay(4000);
  tmrpcm.play("inst.wav");
  delay(9000);
  /*
  tmrpcm.play("1.wav");
  delay(4000);
  tmrpcm.play("2.wav");
  delay(4000);
  tmrpcm.play("3.wav");
  delay(4000);
  tmrpcm.play("4.wav");
  delay(5000);
  */

}
void loop() {

  int a = 0;
  tmrpcm.play("nivel.wav"); //nivel
  delay(s);
  

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Selecciona un ");
  lcd.setCursor(0, 1);
  lcd.print("   nivel");
  delay(5000);

  Nvl_1 = digitalRead(41); //Selecciónd e nivel
  Nvl_2 = digitalRead(42); //
  Nvl_3 = digitalRead(43);

  if (Nvl_1 == HIGH && Nvl_2 == LOW && Nvl_3 == LOW) { //Nivel 1

    int cont = 0;
    lcd.clear();

      tmrpcm.play("nivel1.wav");//nivel1
      delay(s);

    for (int i = 0; i < 4; i++) {

      randomNumber = random(1, 10);
      a = randomNumber;
      Serial.print("\nEl numero aleatorio es = ");
      Serial.println(a);
      //Esperamos 1 segundo para repetir
      delay(1000);

      switch (a) {

      case 1:
        //Ojo

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("OJO");
        delay(t);

        tmrpcm.play("ojo.wav");
        delay(s);

        lcd.clear();
        break;

      case 2:

        Serial.print("\nCase 2");
        delay(1000);

        //TAXI

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 1);
        delay(t);

        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("TAXI");
        delay(t);

        tmrpcm.play("taxi.wav");
        delay(s);
        lcd.clear();

        break;

      case 3:

        Serial.print("\nCase 3");
        delay(1000);

        //MAMA

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("MAMA");
        delay(t);

        tmrpcm.play("mama.wav");
        delay(s);
        lcd.clear();

        break;

      case 4:

        Serial.print("\nCase 4");
        delay(1000);

        //CASA
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("CASA");
        delay(t);

        tmrpcm.play("casa.wav");
        delay(s);
        lcd.clear();

        break;

      case 5:

        Serial.print("\nCase 5");
        delay(1000);

        //SOL
        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("SOL");
        delay(t);

        tmrpcm.play("sol.wav");
        delay(s);
        lcd.clear();

        break;

      case 6:
        Serial.print("\nCase 6");
        delay(1000);

        //RIO
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("RIO");
        delay(t);

        tmrpcm.play("rio.wav");
        delay(s);
        lcd.clear();

        break;

      case 7:

        Serial.print("\nCase 7");
        delay(1000);

        //VACA
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 1);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("VACA");
        delay(t);

        tmrpcm.play("vaca.wav");
        delay(s);
        lcd.clear();

        break;

      case 8:

        Serial.print("\nCase 8");
        delay(1000);

        //GATO
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("GATO");
        delay(t);

        tmrpcm.play("gato.wav");
        delay(s);
        lcd.clear();

        break;

      case 9:

        Serial.print("\nCase 9");
        delay(1000);

        //PELOTA
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("PELOTA");
        delay(t);

        tmrpcm.play("pelota.wav");
        delay(s);
        lcd.clear();

        break;

      case 10:

        Serial.print("\nCase 10");
        delay(1000);

        //MALETA
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("MALETA");
        delay(t);

        tmrpcm.play("maleta.wav");
        delay(s);
        lcd.clear();
        break;
      default:
        Serial.print("Este es el default");
        // if nothing else matches, do the default
        // default is optional
        break;
      }
        delay(t);
        si = digitalRead(36); //ACIERTO
        no = digitalRead(37); //DESACIERTO
        delay(t);
        if(si==1){
          cont++;
        }
    }
    if(cont == 1){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste una:");
        lcd.setCursor(0, 1);
        lcd.print("palabra");
        delay(t);      
        tmrpcm.play("1.wav");
        delay(s);
    }
    else if(cont == 2){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste dos:");
        lcd.setCursor(0, 1);
        lcd.print("palabra");
        delay(t);
        
        tmrpcm.play("2.wav");
        delay(s);       
    }
    else if(cont == 3){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste tres:");
        lcd.setCursor(0, 1);
        lcd.print("palabras");
        delay(t);
        
        tmrpcm.play("3.wav");
        delay(s);  
    }
    else if(cont == 4){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste cuatro");
        lcd.setCursor(0, 1);
        lcd.print("palabras");
        delay(t);
        
        tmrpcm.play("4.wav");
        delay(s);
    }
    else{
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("No acertaste ");
        lcd.setCursor(0, 1);
        lcd.print("ninguna palabra");
        delay(4000);
    }
  }

  if (Nvl_1 == LOW && Nvl_2 == HIGH && Nvl_3 == LOW) {
    int cont2 = 0;
    
    lcd.clear();

      tmrpcm.play("nivel2.wav");
      delay(s);
    

    for (int i = 0; i < 4; i++) {

      randomNumber = random(1, 10);
      a = randomNumber;
      Serial.print("\nEl numero aleatorio es = ");
      Serial.println(a);
      //Esperamos 1 segundo para repetir
      delay(1000);
      
      switch (a) {
      case 1:
        Serial.print("\nCase 1");
        delay(1000);

        //Kiwi
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);
        
        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);
        
        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 1);
        delay(t);
        
        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("KIWI");
        delay(250);

        tmrpcm.play("kiwi.wav");
        delay(s);
        lcd.clear();
    
        break;
        
      case 2:
        Serial.print("\nCase 2");
        delay(1000);
        //CEBOLLA
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);   

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);        

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("CEBOLLA");
        delay(250);

        tmrpcm.play("cebolla.wav");
        delay(s);
        lcd.clear();
               
        break;
        
      case 3:
        Serial.print("\nCase 3");
        delay(1000);
        
        //ELEFANTE
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

         digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);    

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);  

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);                 

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);
        
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("ELEFANTE");
        delay(250);

        tmrpcm.play("elefante.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 4:
        Serial.print("\nCase 4");
        delay(1000);

        //DOMINGO
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);
        
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("DOMINGO");
        delay(250);

        tmrpcm.play("domingo.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 5:
        Serial.print("\nCase 5");
        delay(1000);

        //PALOMA
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);
        
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("PALOMA");
        delay(250);

        tmrpcm.play("paloma.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 6:
        Serial.print("\nCase 6");
        delay(1000);

        //CAMISA
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);
        
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("CAMISA");
        delay(250);

        tmrpcm.play("camisa.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 7:
        Serial.print("\nCase 7");
        delay(1000);


        //LAPIZ
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,1);
        delay(t);
        
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("LAPIZ");
        delay(250);

        tmrpcm.play("lapiz.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 8:
        Serial.print("\nCase 8");
        delay(1000);

        //TELEFONO
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);       

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);
        
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("TELEFONO");
        delay(250);

        tmrpcm.play("telefono.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 9:
        Serial.print("\nCase 9");
        delay(1000);

        //MAYO
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,1);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("MAYO");
        delay(250);

        tmrpcm.play("mayo.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 10:
        Serial.print("\nCase 10");
        delay(1000);

        //COCINA
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);


        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("COCINA");
        delay(250);

        tmrpcm.play("cocina.wav");
        delay(s);
        lcd.clear();
        break;
        
      default:
        Serial.print("Este es el default");
        // if nothing else matches, do the default
        // default is optional
        break;
      }

        delay(t);
        si = digitalRead(36); //ACIERTO
        no = digitalRead(37); //DESACIERTO
        delay(t);
        if(si==1){
          cont2++;
        }
    }
    if(cont2 == 1){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste una:");
        lcd.setCursor(0, 1);
        lcd.print("palabra");
        delay(t);      
        tmrpcm.play("1.wav");
        delay(s);
    }
    else if(cont2 == 2){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste dos:");
        lcd.setCursor(0, 1);
        lcd.print("palabra");
        delay(t);
        
        tmrpcm.play("2.wav");
        delay(s);       
    }
    else if(cont2 == 3){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste tres:");
        lcd.setCursor(0, 1);
        lcd.print("palabras");
        delay(t);
        
        tmrpcm.play("3.wav");
        delay(s);  
    }
    else if(cont2 == 4){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste cuatro");
        lcd.setCursor(0, 1);
        lcd.print("palabras");
        delay(t);
        
        tmrpcm.play("4.wav");
        delay(s);
    }
    else{
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("No acertaste ");
        lcd.setCursor(0, 1);
        lcd.print("ninguna palabra");
        delay(4000);
    }
  

  } else if (Nvl_1 == LOW && Nvl_2 == LOW && Nvl_3 == HIGH) {
    int cont3 = 0;
    
    lcd.clear();
    tmrpcm.play("nivel3.wav");
    delay(s);
    
    for (int i = 0; i < 4; i++) {

      randomNumber = random(1, 10);
      a = randomNumber;
      Serial.print("\nEl numero aleatorio es = ");
      Serial.println(a);
      //Esperamos 1 segundo para repetir
      delay(1000);
      
      switch (a) {
      case 1:
        Serial.print("\nCase 1");
        delay(1000);

            //ZAPATO
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 1);
        delay(t);
        
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);
        
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);
        
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 0);
        digitalWrite(Led_5, 0);
        digitalWrite(Led_6, 0);
        delay(t);
        
        digitalWrite(Led_1, 0);
        digitalWrite(Led_2, 1);
        digitalWrite(Led_3, 1);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);
        
        digitalWrite(Led_1, 1);
        digitalWrite(Led_2, 0);
        digitalWrite(Led_3, 0);
        digitalWrite(Led_4, 1);
        digitalWrite(Led_5, 1);
        digitalWrite(Led_6, 0);
        delay(t);
    
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("ZAPATO");
        delay(250);
    
        tmrpcm.play("zapato.wav");
        delay(s);
        lcd.clear();

        break;
        
      case 2:
        Serial.print("\nCase 2");
        delay(1000);

        //CORAZÓN
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,1);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("CORAZON");
        delay(250);
    
        tmrpcm.play("corazon.wav");
        delay(s);
        lcd.clear();

        
        break;
        
      case 3:
        Serial.print("\nCase 3");
        delay(1000);

        //CALCULADORA
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);
        
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,1);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("CALCULADORA");
        delay(250);
    
        tmrpcm.play("calculadora.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 4:
        Serial.print("\nCase 4");
        delay(1000);

        //SALTAMONTES
        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);


        

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("SALTAMONTES");
        delay(250);
    
        tmrpcm.play("salta.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 5:
        Serial.print("\nCase 5");
        delay(1000);

        //BIBLIOTECA
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("BIBLIOTECA");
        delay(250);
    
        tmrpcm.play("biblio.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 6:
        Serial.print("\nCase 6");
        delay(1000);

        //UNIVERSIDAD
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,1);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,1);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);


        

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("UNIVERSIDAD");
        delay(250);
    
        tmrpcm.play("un.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 7:
        Serial.print("\nCase 7");
        delay(1000);

        //TRANSPORTE
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("TRANSPORTE");
        delay(250);
    
        tmrpcm.play("trans.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 8:
        Serial.print("\nCase 8");
        delay(1000);

        //INGENIERO
        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);
        
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("INGENIERO");
        delay(250);
    
        tmrpcm.play("inge.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 9:
        Serial.print("\nCase 9");
        delay(1000);

        //ZANAHORIA
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,1);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("ZANAHORIA");
        delay(250);
    
        tmrpcm.play("zan.wav");
        delay(s);
        lcd.clear();
        break;
        
      case 10:
        Serial.print("\nCase 10");
        delay(1000);

        //RESTAURANTE
        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,0);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,1);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,1);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,1);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,1);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,0);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        digitalWrite(Led_1,1);
        digitalWrite(Led_2,0);
        digitalWrite(Led_3,0);
        digitalWrite(Led_4,1);
        digitalWrite(Led_5,0);
        digitalWrite(Led_6,0);
        delay(t);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("LA PALABRA ES:");
        lcd.setCursor(0, 1);
        lcd.print("RESTAURANTE");
        delay(250);
    
        tmrpcm.play("res.wav");
        delay(s);
        lcd.clear();
        break;
        
      default:
        Serial.print("Este es el default");
        // if nothing else matches, do the default
        // default is optional
        break;
        
      }

        delay(t);
        si = digitalRead(36); //ACIERTO
        no = digitalRead(37); //DESACIERTO
        delay(t);
        if(si==1){
          cont3++;
        }
    }

    if(cont3 == 1){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste una:");
        lcd.setCursor(0, 1);
        lcd.print("palabra");
        delay(t);      
        tmrpcm.play("1.wav");
        delay(s);
    }
    else if(cont3 == 2){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste dos:");
        lcd.setCursor(0, 1);
        lcd.print("palabra");
        delay(t);
        
        tmrpcm.play("2.wav");
        delay(s);       
    }
    else if(cont3 == 3){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste tres:");
        lcd.setCursor(0, 1);
        lcd.print("palabras");
        delay(t);
        
        tmrpcm.play("3.wav");
        delay(s);  
    }
    else if(cont3 == 4){
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Acertaste cuatro");
        lcd.setCursor(0, 1);
        lcd.print("palabras");
        delay(t);
        
        tmrpcm.play("4.wav");
        delay(s);
    }
    else{
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("No acertaste ");
        lcd.setCursor(0, 1);
        lcd.print("ninguna palabra");
        delay(4000);
    }
  } else {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Selecciona un");
    lcd.setCursor(0, 1);
    lcd.print("   nivel ");
    delay(250);

    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_3, HIGH);
    digitalWrite(Led_4, HIGH);
    digitalWrite(Led_5, HIGH);
    digitalWrite(Led_6, HIGH);
    delay(250);

  }
 }

void inicializar_sd_card() {
  /////////////////   inicializacion sd card  //////////////////////
  //Serial.print("Inicializando SD card...");
  // Asegurarse de que el chip de forma predeterminada seleccione anclar se establece en
  // Salida, incluso si usted no lo utiliza:
  lcd.clear();
  pinMode(chipSelect, OUTPUT);
  digitalWrite(chipSelect, HIGH);
  lcd.print("Inicializando SD card...");
  delay(1000);
  lcd.clear();
  //digitalWrite(chipSelect,HIGH);
  // Ver si la tarjeta está presente y se puede inicializar:
  if (!SD.begin(chipSelect)) {
    Serial.println("fallo lectura de tarjeta");
    lcd.print("fallo SD card...");
    delay(600);
    lcd.clear();
    return;
  }
  Serial.println("SD inicializada ok.");
  lcd.print("SD inicia ok.");
  delay(1000);
  lcd.clear();
}
/////////**************************************************