/*
 * DT_DataCurso.h
 *
 *  Created on: Jun 19, 2024
 *      Author: mat
 */

#ifndef DATATYPES_DT_DATACURSO_H_
#define DATATYPES_DT_DATACURSO_H_

#include "iostream"
#include "string"
#include "enums.h"

class DT_DataCurso {
private:
	std::string nombreCurso;
	std::string descripcionCurso;
	std::string dificultadCurso;
public:
	DT_DataCurso(std::string nombre, std::string desc, std::string dif);
	virtual ~DT_DataCurso();
	std::string getNombreCurso();
	std::string getDescripcionCurso();
	std::string getDificultadCurso();
	dificultad getDificultadCursoToEnum();
	friend std::ostream& operator<<(std::ostream& os, DT_DataCurso* dataC);
};

#endif /* DATATYPES_DT_DATACURSO_H_ */
