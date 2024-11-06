#ifndef PROBABILIDADIA_H_INCLUDED
#define PROBABILIDADIA_H_INCLUDED

using namespace std;

class ProbabilidadIA {
public:
    bool decidirCantarEnvido(int envidoIA);

    bool decidirCantarTruco();

    bool aceptarEnvido(int envidoIA);

    bool aceptarTruco();
};

#endif // PROBABILIDADIA_H_INCLUDED
