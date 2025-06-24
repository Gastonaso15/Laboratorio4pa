//
// Created by marti on 12/6/2025.
//

#include "DTFecha.h"
#include <iostream>
using namespace std;

DTFecha::DTFecha() {

}
DTFecha::~DTFecha() {

}
DTFecha::DTFecha(int anio, int mes, int dia) {
    this->anio = anio;
    this->mes = mes;
    this->dia = dia;
}

int DTFecha::getAnio()const {
    return this->anio;
}
int DTFecha::getMes()const {
    return this->mes;
}
int DTFecha::getDia()const {
    return this->dia;
}
string DTFecha::toString() const {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}