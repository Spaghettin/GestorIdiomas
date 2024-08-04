/*
 * DT_DataCursoConContador.cpp
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#include "DT_DataCursoConContador.h"

DT_DataCursoConContador::DT_DataCursoConContador(
			std::string nombre,
			std::string desc,
			std::string dificultad,
			int cantLec, int cantEj
			) {
	this->nombreCurso = nombre;
	this->descripcionCurso = desc;
	this->dificultadCurso = dificultad;
	this->cantidadLecciones = cantLec;
	this->cantidadEjercicios = cantEj;
}

DT_DataCursoConContador::~DT_DataCursoConContador() {
	// TODO Auto-generated destructor stub
}

std::string DT_DataCursoConContador::getNombreCurso() {
	return this->nombreCurso;
}

std::string DT_DataCursoConContador::getDescripcionCurso(){
	return this->descripcionCurso;
}

std::string DT_DataCursoConContador::getDificultadCurso() {
	return this->dificultadCurso;
}

int DT_DataCursoConContador::getCantidadLecciones() {
	return this->cantidadLecciones;
}

int DT_DataCursoConContador::getCantidadEjercicios() {
	return this->cantidadEjercicios;
}

std::ostream& operator<<(std::ostream& os, DT_DataCursoConContador* dataCCC) {
	os << "\nCurso: " << dataCCC->getNombreCurso()
		<< "\nDescripcion: " << dataCCC->getDescripcionCurso()
		<< "\nDificultad: " << dataCCC->getDificultadCurso()
		<< "\nCantidad de lecciones: " << std::to_string(dataCCC->getCantidadLecciones())
		<< "\nCantidad de ejercicios: " << std::to_string(dataCCC->getCantidadEjercicios());

	return os;
}



