#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include <iostream>

using namespace std;

class Carta
{
public:
    int id;
    string palo;
    int valor;

    Carta(int i, string p, int v);
};

#endif // CARTA_H_INCLUDED
