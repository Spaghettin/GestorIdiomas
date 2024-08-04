/*
 * DeTraduccion.h
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#ifndef DETRADUCCION_H_
#define DETRADUCCION_H_

#include "Ejercicio.h"
#include "string"

class DeTraduccion : public Ejercicio {
private:
	std::string solucion;
	std::string fraseATraducir;
public:
	DeTraduccion();
	DeTraduccion(std::string descripcionEj, std::string frase, std::string sol);
	virtual ~DeTraduccion();
	std::string getProblema();
	std::string getSolucion();
	bool resolver(std::string sol);
	DT_DataDeTraduccion* getDataDeTraduccion();
};

#endif /* DETRADUCCION_H_ */
