#include <iostream>
#include <vector>
#include <ctime>
#include "../include/JuegoTruco.h"

using namespace std;

void JuegoTruco::iniciarJuego()
{
    cout << "EL JUEGO INICIO" << endl;
    skynet.nombre = "Skynet";
    cout << "Ingrese su nombre" << endl;
    cin >> jugador.nombre;
    cout << skynet.nombre << " VS " << jugador.nombre << endl << endl;
    barajarCartas();
    repartirCartas();
}

void JuegoTruco::barajarCartas()
{
    barajar.clear();
    vector<int> idsUsados;
    while (barajar.size() < 6)
    {
        int id = rand() % 40;
        bool idUsado = false;

        // Verificar ID repetidas
        for (int i = 0; i < idsUsados.size(); ++i)
        {
            if (idsUsados[i] == id)
            {
                idUsado = true;
                break;
            }
        }
        if (!idUsado)
        {
            barajar.push_back(mazo.buscarCarta(id));
            idsUsados.push_back(id); // Añade ID a la lista de usados
        }
    }
}

void JuegoTruco::repartirCartas()
{

    for (int i=0; i < 6; i++)
    {
        if (i<3)
        {
            skynet.recibirCarta(barajar[i]);
            cout << " " << skynet.mano[i].palo << " " << skynet.mano[i].nombre << endl;
        }
        else
        {
            jugador.recibirCarta(barajar[i]);
            cout << " " << jugador.mano[i-3].palo << " " << jugador.mano[i-3].nombre << endl;
        }
    }
}
