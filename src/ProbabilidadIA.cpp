#include <ctime>
#include <cstdlib>
#include "../include/ProbabilidadIA.h"

using namespace std;

bool decidirCantarEnvido(int envidoIA)
{
    int probabilidad = (envidoIA >= 31) ? 90 : (envidoIA >= 25) ? 50 : 10;
    return rand() % 100 < probabilidad;
}

bool decidirCantarTruco()
{
    return rand() % 100 < 50;
}

bool aceptarEnvido(int envidoIA)
{
    int probabilidad = (envidoIA >= 31) ? 80 : (envidoIA >= 25) ? 50 : 20;
    return rand() % 100 < probabilidad;
}

bool aceptarTruco()
{
    return rand() % 100 < 60;
}
