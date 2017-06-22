/* DESCRIPCION
 *   Programa para manejar un carrito con un sensor ultrasonico.
 *   
 * MODIFICACIONES
 *   J.Villalobos  03.Jun.2017  Creación
 */
// ---- Bibliotecas
#include "Carrito.h"
#include "SensorRGB.h"
#include <Wire.h>

// ---- Constantes
#define MOTORIZ 3
#define MOTORDE 5

// ---- Variables
Carrito carro(MOTORIZ, MOTORDE);
SensorRGB rgb;

uint16_t defColores[7][3] = {
  {255, 0  , 0  },
  {0  , 255, 0  },
  {0  , 0  , 255},
  {255, 255, 102},
  {0  , 0  , 0  },
  {255, 255, 255},
  {255, 178, 102}
};
String colores[7] = {
  "Rojo",
  "Verde",
  "Azul",
  "Amarillo",
  "Negro",
  "Blanco",
  "Naranja"
};

void setup() {
  Serial.begin(9600);
  Serial.println("Robot con sensor ultrasonico");
  Serial.println("Jorge Villalobos C. - v1.0 - Jun.2017");
  Serial.println("");

  // Inicialización del carro
  carro.inicio();

  // Inicialización del sensor RGB
  Serial.println(rgb.inicio() ? "Sensor RGB encontrado": "Sensor RGB NO encontrado");
}  // void setup();

void loop() {  
  rgb.getRGBColor();
  Serial.print("Color detectado: ");
  Serial.print(getColor());
  Serial.print(" | R:"); Serial.print(rgb.Red());
  Serial.print(" - G:"); Serial.print(rgb.Green());
  Serial.print(" - B:"); Serial.print(rgb.Blue());
  Serial.println("");
  delay(500);
}  // void loop()

String getColor() {
  int indice = -1;
  int dist = 1000,
      aux;
  
  for (int i = 0 ; i < 7 ; i++) {
    aux = rgb.Diff(defColores[i][0], defColores[i][1], defColores[i][2]);
    if (aux < dist) {
      dist = aux;
      indice = i;
    }
  }

  return colores[indice];
}  // String GetColor()

