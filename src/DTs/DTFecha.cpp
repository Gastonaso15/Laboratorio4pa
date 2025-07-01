
#include "DTFecha.h"
#include <iostream>
#include <ctime>
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

DTFecha DTFecha::obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* tiempo = localtime(&t);
    int dia = tiempo->tm_mday;
    int mes = tiempo->tm_mon + 1;
    int anio = tiempo->tm_year + 1900;
    return DTFecha(anio, mes, dia);
}