#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include <iostream>

using namespace std;

class Carta
{
public:
    int id;
    string palo;
    string nombre;

    Carta(int i, string p, string n);
};

#endif // CARTA_H_INCLUDED
