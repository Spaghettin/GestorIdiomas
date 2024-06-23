#include "date.h"

date::date() {
	
}

date::date(int ano, int mes, int dia) {
	this->ano=ano;
	this->mes=mes;
	this->dia=dia;
}

date::date(const date &arg) {
	
}

date::~date() {
	
}

int date::getDia() {
	return this->dia;
}

int date::getMes() {
	return this->mes;
}

int date::getAno() {
	return this->ano;
}

std::ostream& operator<<(std::ostream& os, date* fecha) {
	os  << fecha->ano << "-" << fecha->mes << "-" << fecha->dia;
	
	return os;
}
