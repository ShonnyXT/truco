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
    do
    {
        barajarCartas();
        repartirCartas();
        jugarRonda();
        determinarGanador();
        system("pause");
    }
    while(finDelJuego);
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
            // testSkynet cout << " " << skynet.mano[i].palo << " " << skynet.mano[i].valor << endl;
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

    if (turnoSkynetPrimero)
    {
        // Preguntar primero a Skynet
        if (!envidoCantado && probabilidadIA.decidirCantarEnvido(skynet.calcularEnvido()))
        {
            cout << "Skynet canta Envido. Aceptas? (1. Si, 2. No): ";
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

        if (!trucoCantado && probabilidadIA.decidirCantarTruco())
        {
            cout << "Skynet canta Truco. Aceptas? (1. Si, 2. No): ";
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
            }
            trucoCantado = true;
        }
    }
    else
    {
        // Preguntar primero al Jugador
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
                }
                trucoCantado = true;
            }
        }
    }

    // Alternar
    alternarTurnoCanto();
}

void JuegoTruco::alternarTurnoCanto()
{
    turnoSkynetPrimero = !turnoSkynetPrimero;
}

void JuegoTruco::resolverEnvido()
{
    int envidoJugador = jugador.calcularEnvido();
    int envidoSkynet = skynet.calcularEnvido();
    cout << "Tu envido es: " << envidoJugador << endl;
    cout << "El envido de Skynet es: " << envidoSkynet << endl;
    if (envidoJugador > envidoSkynet)
    {
        cout << "Ganaste el envido y obtienes 2 puntos." << endl;
        jugador.puntos += 2;
    }
    else if (envidoJugador < envidoSkynet)
    {
        cout << "Skynet gano el envido y obtiene 2 puntos." << endl;
        skynet.puntos += 2;
    }
    else
    {
        cout << "Empate en el envido, no se otorgan puntos." << endl;
    }
}

void JuegoTruco::jugarRonda()
{
    envidoCantado = false;
    trucoCantado = false;
    turnoSkynetPrimero = rand() % 2;
    int jugadorRonda = 0, skynetRonda = 0;

    bool cartaUno = false, cartaDos = false, cartaTres = false;

    for (int ronda = 1; ronda <= 3; ronda++)
    {
        cout << endl << "Ronda " << ronda << endl;
        cantos();
        int cartaJugador, cartaSkynet;
        cout << "Elige una carta para jugar (1, 2, o 3): ";

        bool cartaRepetida;

        do
        {
            cin >> cartaJugador;
            cartaRepetida = false;

            switch (cartaJugador)
            {
            case 1:
                if (!cartaUno)
                {
                    cartaUno = true;
                    cartaRepetida = false;
                }
                else
                {
                    cout << "Carta ya utilizada. Elige otra carta." << endl;
                    cartaRepetida = true;
                }
                break;
            case 2:
                if (!cartaDos)
                {
                    cartaDos = true;
                    cartaRepetida = false;
                }
                else
                {
                    cout << "Carta ya utilizada. Elige otra carta." << endl;
                    cartaRepetida = true;
                }
                break;
            case 3:
                if (!cartaTres)
                {
                    cartaTres = true;
                    cartaRepetida = false;
                }
                else
                {
                    cout << "Carta ya utilizada. Elige otra carta." << endl;
                    cartaRepetida = true;
                }
                break;
            default:
                cout << "Elige una opción correcta (1, 2, o 3)." << endl;
                cartaRepetida = true;
                break;
            }

        }
        while (cartaRepetida);

        Carta cartaJugada = jugador.mano[cartaJugador - 1];
        cout << "Jugaste la carta: " << cartaJugada.palo << " " << cartaJugada.valor << endl;

        cartaSkynet = 0; // Seleccion de una carta diferente cada vez
        Carta cartaSkynetJugada = skynet.mano[cartaSkynet];
        skynet.mano.erase(skynet.mano.begin() + cartaSkynet);
        cout << "Skynet juega la carta: " << cartaSkynetJugada.palo << " " << cartaSkynetJugada.valor << endl;

        // Verificador de rondas ganadas
        if (jugadorRonda == 2 || skynetRonda == 2)
        {
            break;
        }

        if (cartaJugada.valor < cartaSkynetJugada.valor)
        {
            cout << "Ganaste la ronda!" << endl;
            jugadorRonda++;
        }
        else if (cartaJugada.valor > cartaSkynetJugada.valor)
        {
            cout << "Skynet gano la ronda." << endl;
            skynetRonda++;
        }
        else
        {
            cout << "Empardo en la ronda." << endl;
        }
    }
    if (jugadorRonda == 2){
        jugador.puntos++;
    }else{
        skynet.puntos++;
    }
}

void JuegoTruco::determinarGanador()
{
    cout << endl << "Tus puntos: " << jugador.puntos <<". Contra los de Skynet: " << skynet.puntos << endl;
    if (jugador.puntos >= 15 || skynet.puntos >= 15)
    {
        bool finDelJuego = false;
    }
}
