#include <Adafruit_NeoPixel.h>
#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>


char auth[] = "YourAuthToken";
int PIN = 7; //Pin donde está conectada la tira de leds
int NUMPIXELS = 45; //Número de leds conectados
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

WidgetTerminal terminal(V1);

int r, g, b;
int segundoDerecha = 0;
int segundoIzquierda = 0;
int minutoDerecha = 0;
int minutoIzquierda = 0;
int horaDerecha = 0;
int horaIzquierda = 0;

int ret[7] = {1, 1, 1, 1, 0, 1, 0}; //Array de los leds que se encienden
uint32_t color = pixels.Color(255, 0, 255);


BLYNK_WRITE(V1)
{

  // if you type "Marco" into Terminal Widget - it will respond: "Polo:"
  if (String("Hora") == param.asStr()) {

    terminal.print("La hora actual es: ");
    terminal.print(horaIzquierda);
    terminal.print(horaDerecha);
    terminal.print(":");
    terminal.print(minutoIzquierda);
    terminal.print(minutoDerecha);
    terminal.print(":");
    terminal.print(segundoIzquierda);
    terminal.print(segundoDerecha);
    terminal.println();
  } else {

    // Send it back
    terminal.print("You said:");
    terminal.write(param.getBuffer(), param.getLength());
    terminal.println();
  }

  // Ensure everything is sent
  terminal.flush();
}


BLYNK_WRITE(V6) // Button Widget writes to Virtual Pin V5
{
  r = param.asInt();
}
BLYNK_WRITE(V7) // Button Widget writes to Virtual Pin V5
{
  g = param.asInt();
}
BLYNK_WRITE(V8) // Button Widget writes to Virtual Pin V5
{
  b = param.asInt();
}



void setup() {
  Serial.begin(9600);
  pixels.begin(); // Inicialización
  pixels.show(); // Inicialitza tots els pixels apagats
  Blynk.begin(Serial, auth);
  terminal.println(F("Blynk v" BLYNK_VERSION ": Device started"));
  terminal.println(F("-------------"));


}

void loop() {

  Blynk.run();
  color = pixels.Color(r, g, b);



  numerosALeds(segundoDerecha);

  pixels.setPixelColor(14, color);
  pixels.setPixelColor(15, color);
  pixels.setPixelColor(30, color);
  pixels.setPixelColor(31, color);


  //SEGUNDOS DERECHA
  if (ret[0] == 1) {
    pixels.setPixelColor(0, color);

  } else {
    pixels.setPixelColor(0, 0, 0, 0);

  }

  if (ret[1] == 1) {
    pixels.setPixelColor(1, color);

  } else {
    pixels.setPixelColor(1, 0, 0, 0);

  }

  if (ret[2] == 1) {
    pixels.setPixelColor(2, color);

  } else {
    pixels.setPixelColor(2, 0, 0, 0);

  }

  if (ret[3] == 1) {
    pixels.setPixelColor(3, color);

  } else {
    pixels.setPixelColor(3, 0, 0, 0);

  }
  if (ret[4] == 1) {
    pixels.setPixelColor(4, color);

  } else {
    pixels.setPixelColor(4, 0, 0, 0);

  }
  if (ret[5] == 1) {
    pixels.setPixelColor(5, color);

  } else {
    pixels.setPixelColor(5, 0, 0, 0);

  }
  if (ret[6] == 1) {
    pixels.setPixelColor(6, color);

  } else {
    pixels.setPixelColor(6, 0, 0, 0);

  }


  ////////////////////////////////

  //SEGUNDOS IZQUIERDA

  numerosALeds(segundoIzquierda);

  if (ret[0] == 1) {
    pixels.setPixelColor(7, color);

  } else {
    pixels.setPixelColor(7, 0, 0, 0);

  }

  if (ret[1] == 1) {
    pixels.setPixelColor(8, color);

  } else {
    pixels.setPixelColor(8, 0, 0, 0);

  }

  if (ret[2] == 1) {
    pixels.setPixelColor(9, color);

  } else {
    pixels.setPixelColor(9, 0, 0, 0);

  }

  if (ret[3] == 1) {
    pixels.setPixelColor(10, color);

  } else {
    pixels.setPixelColor(10, 0, 0, 0);

  }
  if (ret[4] == 1) {
    pixels.setPixelColor(11, color);

  } else {
    pixels.setPixelColor(11, 0, 0, 0);

  }
  if (ret[5] == 1) {
    pixels.setPixelColor(12, color);

  } else {
    pixels.setPixelColor(12, 0, 0, 0);

  }
  if (ret[6] == 1) {
    pixels.setPixelColor(13, color);

  } else {
    pixels.setPixelColor(13, 0, 0, 0);

  }
  Serial.print(segundoIzquierda);
  Serial.print(":");
  Serial.println(segundoDerecha);

  pixels.show();

  delay(1000);
  bucleReloj();

}


void bucleReloj() {

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


void numerosALeds(int numero) {


  switch (numero) {

    case 0:
      ret[0] = 1;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 1;
      ret[4] = 1;
      ret[5] = 0;
      ret[6] = 1;
      break;
    case 1:

      ret[0] = 0;
      ret[1] = 0;
      ret[2] = 0;
      ret[3] = 0;
      ret[4] = 1;
      ret[5] = 0;
      ret[6] = 1;

      break;
    case 2:
      ret[0] = 1;
      ret[1] = 0;
      ret[2] = 1;
      ret[3] = 1;
      ret[4] = 0;
      ret[5] = 1;
      ret[6] = 1;

      break;
    case 3:

      ret[0] = 1;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 1;
      ret[4] = 0;
      ret[5] = 1;
      ret[6] = 0;

      break;
    case 4:

      ret[0] = 0;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 0;
      ret[4] = 1;
      ret[5] = 1;
      ret[6] = 0;

      break;
    case 5:

      ret[0] = 1;
      ret[1] = 1;
      ret[2] = 0;
      ret[3] = 1;
      ret[4] = 1;
      ret[5] = 1;
      ret[6] = 0;

      break;
    case 6:

      ret[0] = 1;
      ret[1] = 1;
      ret[2] = 0;
      ret[3] = 1;
      ret[4] = 1;
      ret[5] = 1;
      ret[6] = 1;

      break;
    case 7:

      ret[0] = 0;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 1;
      ret[4] = 0;
      ret[5] = 0;
      ret[6] = 0;

      break;
    case 8:
      ret[0] = 1;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 1;
      ret[4] = 1;
      ret[5] = 1;
      ret[6] = 1;

      break;
    case 9:
      ret[0] = 1;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 1;
      ret[4] = 1;
      ret[5] = 1;
      ret[6] = 0;
      break;

    default:

      ret[0] = 1;
      ret[1] = 1;
      ret[2] = 1;
      ret[3] = 1;
      break;
  }
}
