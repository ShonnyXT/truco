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

int Jugador::calcularEnvido()
{
    /*int maxEnvido = 0;
    for (int i = 0; i < mano.size(); ++i)
    {
        for (int j = i + 1; j < mano.size(); ++j)
        {
            if (mano[i].palo == mano[j].palo)
            {
                int envido = 20 + mano[i].valor + mano[j].valor;
                maxEnvido = max(maxEnvido, envido);
            }
        }
    }
    return maxEnvido;*/
}
