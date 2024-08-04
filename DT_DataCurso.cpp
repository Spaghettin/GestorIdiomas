/*
 * DT_DataCurso.cpp
 *
 *  Created on: Jun 19, 2024
 *      Author: mat
 */

#include "DT_DataCurso.h"

DT_DataCurso::DT_DataCurso(std::string nombre, std::string desc, std::string dif) {
	this->nombreCurso = nombre;
	this->descripcionCurso = desc;
	this->dificultadCurso = dif;
}

DT_DataCurso::~DT_DataCurso() {
	// TODO Auto-generated destructor stub
}

std::string DT_DataCurso::getNombreCurso() {
	return this->nombreCurso;
}

std::string DT_DataCurso::getDescripcionCurso() {
	return this->descripcionCurso;
}

std::string DT_DataCurso::getDificultadCurso() {
	return this->dificultadCurso;
}

dificultad DT_DataCurso::getDificultadCursoToEnum() {

	std::string dificultadC = this->dificultadCurso;

	if (dificultadC == "Principiante") {
		return Principiante;
	} else if (dificultadC == "Medio") {
		return Medio;
	} else if (dificultadC == "Avanzado") {
		return Avanzado;
	} else {
		return Principiante;
	}
}

std::ostream& operator<<(std::ostream& os, DT_DataCurso* dataC) {
	os << "\nNombre: " << dataC->nombreCurso
		<< "\nDescripcion: " << dataC->descripcionCurso
		<< "\nDificultad: " << dataC->dificultadCurso;

	return os;
}
