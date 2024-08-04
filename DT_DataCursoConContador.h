/*
 * DT_DataCursoConContador.h
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#ifndef DATATYPES_DT_DATACURSOCONCONTADOR_H_
#define DATATYPES_DT_DATACURSOCONCONTADOR_H_

#include "string"
#include "iostream"

class DT_DataCursoConContador {
private:
	std::string nombreCurso;
	std::string descripcionCurso;
	std::string dificultadCurso;
	int cantidadLecciones;
	int cantidadEjercicios;
public:
	DT_DataCursoConContador(
			std::string nombre,
			std::string desc,
			std::string dificultad,
			int cantLec, int cantEj
			);
	virtual ~DT_DataCursoConContador();
	std::string getNombreCurso();
	std::string getDescripcionCurso();
	std::string getDificultadCurso();
	int getCantidadLecciones();
	int getCantidadEjercicios();
	friend std::ostream& operator<<(std::ostream& os, DT_DataCursoConContador* dataCCC);
};

#endif /* DATATYPES_DT_DATACURSOCONCONTADOR_H_ */
