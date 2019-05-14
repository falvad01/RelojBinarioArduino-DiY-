#include <Adafruit_NeoPixel.h>


int PIN=7; //Pin donde está conectada la tira de leds
int NUMPIXELS=16; //Número de leds conectados

   int segundoDerecha = 0;
   int segundoIzquierda = 0;
   int minutoDerecha = 0;
   int minutoIzquierda = 0;
   int horaDerecha = 0;
   int horaIzquierda = 0;

int ret[4] = {1,1,1,1};



Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600); 
      pixels.begin(); // Inicialización
      pixels.show(); // Inicialitza tots els pixels apagats
  
}

void loop(){ 
  
  
    bucleReloj();
  
  numerosALeds(segundoDerecha);
 
  
  for(int i = 0; i < 4; i++){
     Serial.print(ret[i]);
  }
   Serial.println("");
  

  if(ret[0] == 1){
       pixels.setPixelColor(3,255,0,0);
         pixels.show();
  }else{
    pixels.setPixelColor(3,0,0,0);
    pixels.show();
  }
  
  if(ret[1] == 1){
       pixels.setPixelColor(2,255,0,0);
         pixels.show();
  }else{
    pixels.setPixelColor(2,0,0,0);
    pixels.show();
  }
  
  if(ret[2] == 1){
       pixels.setPixelColor(1,255,0,0);
         pixels.show();
  }else{
    pixels.setPixelColor(1,0,0,0);
    pixels.show();
  }
  
  if(ret[3] == 1){
       pixels.setPixelColor(0,255,0,0);
         pixels.show();
  }else{
    pixels.setPixelColor(0,0,0,0);
    pixels.show();
  }
  
   
  
  
  delay(1000);
  
}


void bucleReloj(){
  
  segundoDerecha++;// TODO codigo cronometro

      if (segundoDerecha == 10) { // CAmbiamos el segundo digito de los segundos
        segundoIzquierda++;
        segundoDerecha = 0;
      }

      if (segundoIzquierda == 6) { // cambiamos el segundo digito de los minutos

        minutoDerecha++;
        segundoIzquierda = 0;
      }

      if (minutoDerecha == 10) { //cambiamos el primer digito de los minutos
        minutoIzquierda++;
        minutoDerecha = 0;
      }

      if (minutoIzquierda == 6) { //Cambiamos el segundo digito de las horas
        horaDerecha++;
        minutoIzquierda = 0;
      }

      if (horaDerecha == 10) { //cambiamos el primer digito de la hora
        horaIzquierda++;
        horaDerecha = 0;
}
  
}


void numerosALeds(int numero){
  
 

    switch (numero) {

    case 0:
      ret[0] = 0;
      ret[1] = 0;
      ret[2] = 0;
      ret[3] = 0;
      break;
    case 1:

      ret[0] = 0;
      ret[1] = 0;
      ret[2] = 0;
      ret[3] = 1;

      break;
    case 2:
      ret[0] = 0;
      ret[1] = 0;
      ret[2] = 0;
      ret[3] = 0;

      break;
    case 3:

      ret[0] = 0;
      ret[1] = 0;
      ret[2] = 1;
      ret[3] = 1;

      break;
    case 4:

      ret[0] = 0;
      ret[1] = 1;
      ret[2] = 0;
      ret[3] = 0;

      break;
    case 5:

      ret[0] = 0;
      ret[1] = 1;
      ret[2] = 0;
      ret[3] = 1;

      break;
    case 6:

      ret[0] = 0;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 0;

      break;
    case 7:

      ret[0] = 0;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 1;

      break;
    case 8:
      ret[0] = 1;
      ret[1] = 0;
      ret[2] = 0;
      ret[3] = 0;

      break;
    case 9:
      ret[0] = 1;
      ret[1] = 0;
      ret[2] = 0;
      ret[3] = 1;
      break;

    default:

      ret[0] = 1;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 1;
      break;
    }
}
