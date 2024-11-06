#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "../include/JuegoTruco.h"

using namespace std;

int main()
{
    srand(time(0));

    cout << "BIENVENIDO AL TRUCO" << endl;
    JuegoTruco juego;
    juego.iniciarJuego();

    return 0;
}
