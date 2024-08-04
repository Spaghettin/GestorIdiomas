/*
 * DT_DataProblemaEjercicio.h
 *
 *  Created on: Jun 18, 2024
 *      Author: mat
 */

#ifndef DT_DATAPROBLEMAEJERCICIO_H_
#define DT_DATAPROBLEMAEJERCICIO_H_


#include "iostream"
#include "enums.h"
#include "Ejercicio.h"

class Ejercicio;

class DT_DataProblemaEjercicio {
private:
	std::string descripcion;
	std::string fraseProblema;
	tipoEjercicio tipoEj;
public:
	DT_DataProblemaEjercicio(Ejercicio* ej);
	virtual ~DT_DataProblemaEjercicio();
	std::string getDescripcionEjercicio();
	std::string getFraseProblema();
	std::string getTipoEjercicioToString();
	friend std::ostream& operator<<(std::ostream& os, DT_DataProblemaEjercicio* dtPE);
};

#endif /* DT_DATAPROBLEMAEJERCICIO_H_ */
