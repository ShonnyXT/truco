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
    cantos();
    system("pause");
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
            cout << " " << skynet.mano[i].palo << " " << skynet.mano[i].valor << endl;
        }
        else
        {
            jugador.recibirCarta(barajar[i]);
            cout << " " << jugador.mano[i-3].palo << " " << jugador.mano[i-3].valor << endl;
        }
    }
}

void JuegoTruco::cantos()
{
    int opcion;
    // Envido del Jugador
    if (!envidoCantado)
    {
        cout << "Quieres cantar Envido? (1. Si, 2. No): ";
        cin >> opcion;
        if (opcion == 1)
        {
            cout << "Has cantado Envido." << endl;
            if (probabilidadIA.aceptarEnvido(skynet.calcularEnvido()))
            {
                cout << "Skynet acepta el Envido." << endl;
                resolverEnvido();
            }
            else
            {
                cout << "Skynet rechaza el Envido. Ganas 1 punto." << endl;
                jugador.puntos += 1;
            }
            envidoCantado = true;
        }
    }
    // Envido de la Skynet
    if (!envidoCantado && probabilidadIA.decidirCantarEnvido(skynet.calcularEnvido()))
    {
        cout << "Skynet canta Envido. ¿Aceptas? (1. Si, 2. No): ";
        cin >> opcion;
        if (opcion == 1)
        {
            cout << "Aceptaste el Envido." << endl;
            resolverEnvido();
        }
        else
        {
            cout << "Rechazaste el Envido. Skynet gana 1 punto." << endl;
            skynet.puntos += 1;
        }
        envidoCantado = true;
    }
    // Truco del Jugador
    if (!trucoCantado)
    {
        cout << "Quieres cantar Truco? (1. Si, 2. No): ";
        cin >> opcion;
        if (opcion == 1)
        {
            cout << "Has cantado Truco." << endl;
            if (probabilidadIA.aceptarTruco())
            {
                cout << "Skynet acepta el Truco." << endl;
                puntosTruco = 2;
            }
            else
            {
                cout << "Skynet rechaza el Truco. Ganas 1 punto." << endl;
                jugador.puntos += 1;
                return;
            }
            trucoCantado = true;
        }
    }
    // Truco de Skynet
    if (!trucoCantado && probabilidadIA.decidirCantarTruco())
    {
        cout << "Skynet canta Truco. ¿Aceptas? (1. Si, 2. No): ";
        cin >> opcion;
        if (opcion == 1)
        {
            cout << "Aceptaste el Truco." << endl;
            puntosTruco = 2;
        }
        else
        {
            cout << "Rechazaste el Truco. Skynet gana 1 punto." << endl;
            skynet.puntos += 1;
            return;
        }
        trucoCantado = true;
    }
}

void JuegoTruco::resolverEnvido() {
        int envidoJugador = jugador.calcularEnvido();
        int envidoSkynet = skynet.calcularEnvido();
        cout << "Tu envido es: " << envidoJugador << endl;
        cout << "El envido de Skynet es: " << envidoSkynet << endl;
        if (envidoJugador > envidoSkynet) {
            cout << "Ganaste el envido y obtienes 2 puntos." << endl;
            jugador.puntos += 2;
        } else if (envidoJugador < envidoSkynet) {
            cout << "Skynet ganó el envido y obtiene 2 puntos." << endl;
            skynet.puntos += 2;
        } else {
            cout << "Empate en el envido, no se otorgan puntos." << endl;
        }
    }
