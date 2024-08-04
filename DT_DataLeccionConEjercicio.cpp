#include "DT_DataLeccionConEjercicio.h"

DT_DataLeccionConEjercicio::DT_DataLeccionConEjercicio(
	int idLeccion,
	std::string tema, 
	std::string objetivo, 
	std::set<DT_DataDeCompletar*> setDeCompletar, 
	std::set<DT_DataDeTraduccion*> setDeTraduccion) {
	
	this->idLeccion = idLeccion;
	this->tema = tema;
	this->objetivo = objetivo;
	this->setDeCompletar = setDeCompletar;
	this->setDeTraduccion = setDeTraduccion;
	
}

DT_DataLeccionConEjercicio::~DT_DataLeccionConEjercicio() {
	
}

int DT_DataLeccionConEjercicio::getIdLeccion() {
	return this->idLeccion;
}

std::string DT_DataLeccionConEjercicio::getObjetivo() {
	return this->objetivo;
}

std::string DT_DataLeccionConEjercicio::getTema() {
	return this->tema;
}

std::set<DT_DataDeCompletar*> DT_DataLeccionConEjercicio::getSetDeCompletar() {
	return this->setDeCompletar;
}

std::set<DT_DataDeTraduccion*> DT_DataLeccionConEjercicio::getSetDeTraduccion() {
	return this->setDeTraduccion;
}

std::ostream& operator<<(std::ostream& os, DT_DataLeccionConEjercicio* dataLec) {
	os << "\nId Leccion: " << dataLec->getIdLeccion()
		<< "\nTema: " << dataLec->getTema()
		<< "\nObjetivo: " << dataLec->getObjetivo();
	
	std::set<DT_DataDeCompletar*> setDeCompletar = dataLec->getSetDeCompletar();
	std::set<DT_DataDeTraduccion*> setDeTraduccion = dataLec->getSetDeTraduccion();
	
	if (!setDeCompletar.empty()) {
		os << "\n\nEjercicios de completar";
		for (DT_DataDeCompletar* dataDeComp : setDeCompletar) {
			os << dataDeComp << "\n";
		}
	}
	
	if (!setDeTraduccion.empty()) {
		os << "\n\nEjercicios de traduccion";
		for (DT_DataDeTraduccion* dataDeTrad : setDeTraduccion) {
			os << dataDeTrad << "\n";
		}
	}
	
	
	return os;
}

