/* DESCRIPCIÓN
 *  
 * MODIFICACIONES
 *   J.Villalobos  03.Jun.2017  Creación
 */
#include "Carrito.h"
Carrito::Carrito(
  int izqPin,
  int derPin
) {
  _izqPin = izqPin;
  _derPin = derPin;
  }  // Constructor

void Carrito::inicio(){
  _izq.attach(_izqPin);
  _der.attach(_derPin);
  parar();
}  // void inicio()

void Carrito::parar(){
  _der.write(90);  
  _izq.write(90);  
}  // void parar()

void Carrito::adelante(){
  _der.write(180);  
  _izq.write(0);
}  // void adelante()

void Carrito::atras(){
  _der.write(0);
  _izq.write(180);
}  // void atras()

void Carrito::izquierda() {
  _der.write(180);  
  _izq.write(180);    
}  // void izquierda()

void Carrito::izq90() {
  parar();
  izquierda();
  delay(tiempoizq90);
  parar();
}  // void izq90()

void Carrito::derecha(){
  _der.write(0);  
  _izq.write(0);  
}  // void izquierda()

void Carrito::der90() {
  parar();
  derecha();
  delay(tiempoder90);
  parar();
}  // void izq90()

