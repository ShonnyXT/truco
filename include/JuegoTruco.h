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
        ProbabilidadIA probabilidadIA;
        bool envidoCantado;
        int puntosTruco;
        bool trucoCantado;


    // Inicio del juego
    void iniciarJuego();

    // Reparte cartas a cada mano
    void repartirCartas();

    // Baraja las cartas a repartir
    void barajarCartas();

    // Cantos Truco - Envido
    void cantos();

    // Resolucion de Envidos
    void resolverEnvido();
};

#endif // JUEGOTRUCO_H_INCLUDED
