#include "DT_DataProgresoCurso.h"

DT_DataProgresoCurso::DT_DataProgresoCurso(
		std::string nombreCurso,
		std::string nombreEstudiante,
		DT_Date* fechaIns,
		float progresoCurso,
		float progresoLeccion) {
	this->nombreCurso = nombreCurso;
	this->nombreEstudiante = nombreEstudiante;
	this->fechaIns = fechaIns;
	this->progresoCurso = progresoCurso;
	this->progresoLeccion = progresoLeccion;
	this->aprobado = (progresoCurso == 100);
}

DT_DataProgresoCurso::~DT_DataProgresoCurso() {
	
}

std::string DT_DataProgresoCurso::getNombreCurso() {
	return this->nombreCurso;
}

std::string DT_DataProgresoCurso::getNombreEstudiante() {
	return this->nombreEstudiante;
}

std::string DT_DataProgresoCurso::getFechaInscripcionToString() {
	DT_Date* fechaInsc = this->fechaIns;
	std::string fechaString = (
			std::to_string(fechaInsc->getDia()) + "/"
			+ std::to_string(fechaInsc->getMes()) + "/"
			+ std::to_string(fechaInsc->getAno())
			);
	return fechaString;
}

bool DT_DataProgresoCurso::getAprobado() {
	return this->aprobado;
}

std::string DT_DataProgresoCurso::getAprobadoToString() {
	if (this->aprobado) {
		return "Aprobado";
	} else {
		return "No aprobado";
	}
}

float DT_DataProgresoCurso::getProgresoCurso() {
	return this->progresoCurso;
}

float DT_DataProgresoCurso::getProgresoLeccion() {
	return this->progresoLeccion;
}


std::ostream& operator<<(std::ostream& os, DT_DataProgresoCurso* dataPC) {
	os << "\nCurso: " << dataPC->getNombreCurso()
		<< "\nEstudiante: " << dataPC->getNombreEstudiante()
		<< "\nFecha de inscripcion: " << dataPC->getFechaInscripcionToString()
		<< "\nEstado: " << dataPC->getAprobadoToString()
		<< "\nProgreso de curso: " << dataPC->getProgresoCurso()
		<< "\nProgreso de leccion actual: " << dataPC->getProgresoLeccion();

	return os;
}
