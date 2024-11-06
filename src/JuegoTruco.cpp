#include <iostream>
#include <vector>
#include <ctime>
#include "../include/JuegoTruco.h"

using namespace std;

void JuegoTruco::iniciarJuego()
{
    cout << "EL JUEGO INICIO" << endl;
    barajarCartas();
    repartirCartas();
}

void JuegoTruco::repartirCartas()
{

    for (int i=0; i < 3; i++)
    {
        int j = i;
        skynet.recibirCarta(barajar[i]);
        cout << " " << skynet.mano[i].palo << " " << skynet.mano[i].nombre << endl;
        jugador.recibirCarta(barajar[j+3]);
        cout << " " << jugador.mano[j].palo << " " << jugador.mano[j].nombre << endl;
    }
}

void JuegoTruco::barajarCartas()
{
    for (int i = 0; i < 6; i++)
    {
        barajar.push_back(mazo.buscarCarta(rand() % 40 + 1));
    }
}
