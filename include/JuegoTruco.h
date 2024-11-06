#ifndef JUEGOTRUCO_H_INCLUDED
#define JUEGOTRUCO_H_INCLUDED

#include "Mazo.h"
#include "Jugador.h"

using namespace std;

class JuegoTruco {
    public:
        Mazo mazo;
        Jugador jugador;
        Jugador skynet;
        vector<Carta> barajar;
        ProbabilidadIA decision;


    // Inicio del juego
    void iniciarJuego();

    // Reparte cartas a cada mano
    void repartirCartas();

    // Baraja las cartas a repartir
    void barajarCartas();
};

#endif // JUEGOTRUCO_H_INCLUDED
