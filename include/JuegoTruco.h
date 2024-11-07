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
        bool trucoCantado;
        bool turnoSkynetPrimero;
        int puntosTruco;
        bool finDelJuego;


    // Inicio del juego
    void iniciarJuego();

    // Reparte cartas a cada mano
    void repartirCartas();

    // Baraja las cartas a repartir
    void barajarCartas();

    // Cantos Truco - Envido
    void cantos();

    // Alternar el valor de la variable de control
    void alternarTurnoCanto();

    // Resolucion de Envidos
    void resolverEnvido();

    // Jugada de las manos
    void jugarRonda();

    // Ganador de la ronda
    void determinarGanador();
};

#endif // JUEGOTRUCO_H_INCLUDED
