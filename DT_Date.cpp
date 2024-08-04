/*
 * DT_Date.cpp
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#include "DT_Date.h"

DT_Date::DT_Date(int dia, int mes, int ano) {
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

DT_Date::~DT_Date() {
	// TODO Auto-generated destructor stub
}

int DT_Date::getDia() {
	return this->dia;
}

int DT_Date::getMes() {
	return this->mes;
}

int DT_Date::getAno() {
	return this->ano;
}

std::ostream& operator<<(std::ostream& os, DT_Date* fecha) {
	os << fecha->dia << "/" << fecha->mes << "/" << fecha->ano;
	return os;
}
