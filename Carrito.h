/* DESCRIPCION
 *   Defición de la clase Carrito.
 *   
 * NOTAS
 *   Define los métodos
 *   - Adelante
 *   - Atrás
 *   - GiroDerecho
 *   - GiroIzquierdo
 *   - Parar
 * 
 * MODIFICACIONES
 *   J.Villalobos 03.Jun.2017  Creación
 */
#include <Arduino.h>
#include <Servo.h>

#ifndef CARRITO_H
#define CARRITO_H
class Carrito {
  public:
    // ---- Constructor
    Carrito(int izqPin, int derPin);
  
    // ---- Métodos
    void inicio();
    void adelante();
    void atras();
    void derecha();
    void der90();
    void izquierda();
    void izq90();
    void parar();

    // ---- Variables
    int tiempoizq90 = 800;
    int tiempoder90 = 800;
    
  private:
    Servo _izq,
          _der;
    int _izqPin, 
        _derPin;
};
#endif
