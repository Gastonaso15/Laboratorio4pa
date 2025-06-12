//
// Created by marti on 12/6/2025.
//

#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>


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
    bool operator<=(const DTFecha& otra) const {
        return anio < otra.anio ||
               (anio == otra.anio && mes < otra.mes) ||
               (anio == otra.anio && mes == otra.mes && dia <= otra.dia);
    }
};

#endif //DTFECHA_H