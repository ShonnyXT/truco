#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "Carta.h"

using namespace std;

class Jugador
{
public:
    vector<Carta> mano;
    int puntos;

    Jugador();

    void recibirCarta(Carta carta);
};

#endif // JUGADOR_H_INCLUDED
