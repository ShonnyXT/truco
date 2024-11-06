#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <iostream>
#include "Carta.h"
#include "ProbabilidadIA.h"

using namespace std;

class Jugador
{
public:
    vector<Carta> mano;
    int puntos;
    string nombre;

    Jugador();

    // Recibe cartas para su mano
    void recibirCarta(Carta carta);

    bool decidir(bool decidirIA);

    int calcularEnvido();
};

#endif // JUGADOR_H_INCLUDED
