#include <ctime>
#include <cstdlib>
#include "../include/ProbabilidadIA.h"

using namespace std;

bool ProbabilidadIA::decidirCantarEnvido(int envidoSkynet)
{
    int probabilidad = (envidoSkynet >= 31) ? 90 : (envidoSkynet >= 25) ? 50 : 10;
    return rand() % 100 < probabilidad;
}

bool ProbabilidadIA::decidirCantarTruco()
{
    return rand() % 100 < 50;
}

bool ProbabilidadIA::aceptarEnvido(int envidoSkynet)
{
    int probabilidad = (envidoSkynet >= 31) ? 80 : (envidoSkynet >= 25) ? 50 : 20;
    return rand() % 100 < probabilidad;
}

bool ProbabilidadIA::aceptarTruco()
{
    return rand() % 100 < 60;
}
