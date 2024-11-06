#include <vector>
#include <iostream>
#include "../include/Mazo.h"

using namespace std;

// Construye el mazo de cartas
Mazo::Mazo()
{
    string palos[] = {"Espadas", "Bastos", "Oros", "Copas"};
    string nombres[] = {"1", "2", "3", "4", "5", "6", "7", "10", "11", "12"};
    int id = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cartas.push_back(Carta(id++, palos[i], nombres[j]));
        }
    }
}

// Busca una carta del mazo por id
Carta Mazo::buscarCarta(int id)
{
    return cartas[id];
}
