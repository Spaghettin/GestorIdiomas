#include "DT_DataDeCompletar.h"

DT_DataDeCompletar::DT_DataDeCompletar(
		std::string descripcion,
		std::string fraseIncompleta,
		std::vector<std::string> solucion) {
	this->descripcion = descripcion;
	this->fraseIncompleta = fraseIncompleta;
	this->solucion = solucion;
}

DT_DataDeCompletar::~DT_DataDeCompletar() {
	
}

std::string DT_DataDeCompletar::getSolucionToString() {
	std::string solucion = "";
	for (std::string st : this->solucion) {
		solucion = solucion + " | " + st;
	}
	return solucion;
}

std::string DT_DataDeCompletar::getFraseProblema() {
	return this->fraseIncompleta;
}

std::string DT_DataDeCompletar::getDescripcion() {
	return this->descripcion;
}

std::ostream& operator<<(std::ostream& os, DT_DataDeCompletar* dtdc) {
	os << "\nDescripcion: " << dtdc->getDescripcion()
		<< "\nFrase a completar: " << dtdc->getFraseProblema()
		<< "\nSolucion: " << dtdc->getSolucionToString();

	return os;
}
