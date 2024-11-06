#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED

#include <vector>
#include "Carta.h"

using namespace std;

class Mazo
{
public:
    vector<Carta> cartas;

    Mazo();

    Carta buscarCarta(int id);
};

#endif // MAZO_H_INCLUDED
