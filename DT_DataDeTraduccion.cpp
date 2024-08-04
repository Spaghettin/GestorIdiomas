#include "DT_DataDeTraduccion.h"

DT_DataDeTraduccion::DT_DataDeTraduccion(
		std::string descripcion,
		std::string fraseATraducir,
		std::string solucion) {
	this->descripcion = descripcion;
	this->fraseATraducir = fraseATraducir;
	this->solucion = solucion;
}

DT_DataDeTraduccion::~DT_DataDeTraduccion() {
	
}


std::string DT_DataDeTraduccion::getSolucion() {
	return this->solucion;
}

std::string DT_DataDeTraduccion::getFraseProblema() {
	return this->fraseATraducir;
}

std::string DT_DataDeTraduccion::getDescripcion() {
	return this->descripcion;
}

std::ostream& operator<<(std::ostream& os, DT_DataDeTraduccion* dtdt) {
	os << "\nDescripcion: " << dtdt->getDescripcion()
		<< "\nFrase a traducir: " << dtdt->getFraseProblema()
		<< "\nSolucion: " << dtdt->getSolucion();

	return os;
}
