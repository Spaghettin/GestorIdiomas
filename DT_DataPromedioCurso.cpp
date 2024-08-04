/*
 * DT_DataPromedioCurso.cpp
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#include "DT_DataPromedioCurso.h"

DT_DataPromedioCurso::DT_DataPromedioCurso(std::string nombreC, float promedioProgresoC) {
	this->nombreCurso = nombreC;
	this->promedioProgresoCurso = promedioProgresoC;
}

DT_DataPromedioCurso::~DT_DataPromedioCurso() {
	// TODO Auto-generated destructor stub
}

std::string DT_DataPromedioCurso::getNombreCurso() {
	return this->nombreCurso;
}

float DT_DataPromedioCurso::getPromedioProgresoCurso() {
	return this->promedioProgresoCurso;
}

std::ostream& operator<<(std::ostream& os, DT_DataPromedioCurso* dataPC) {
	os << "\nCurso: " << dataPC->getNombreCurso()
			<< "\nPromedio de progreso: " << std::to_string(dataPC->getPromedioProgresoCurso());

	return os;
}
