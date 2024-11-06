#include <iostream>
#include <vector>
#include "../include/Jugador.h"

using namespace std;

Jugador::Jugador()
{
    puntos = 0;
}

void Jugador::recibirCarta(Carta carta)
{
    mano.push_back(carta);
}
