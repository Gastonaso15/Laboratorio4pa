
#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>
using namespace std;

class DTFecha {
private:
    int anio;
    int mes;
    int dia;
public:
    DTFecha();
    ~DTFecha();
    DTFecha(int anio, int mes, int dia);

    int getAnio()const;
    int getMes()const;
    int getDia()const;

    string toString() const;

    static DTFecha obtenerFechaActual();

    bool operator<=(const DTFecha& otra) const {
        return anio < otra.anio ||
               (anio == otra.anio && mes < otra.mes) ||
               (anio == otra.anio && mes == otra.mes && dia <= otra.dia);
    }
};

#endif //DTFECHA_H