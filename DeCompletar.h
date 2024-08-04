/*
 * DeCompletar.h
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#ifndef DECOMPLETAR_H_
#define DECOMPLETAR_H_

#include "Ejercicio.h"
#include "string"
#include "vector"

class DeCompletar : public Ejercicio {
private:
	std::vector<std::string> solucion;
	std::string fraseIncompleta;
public:
	DeCompletar();
	DeCompletar(std::string descripcionEj, std::string frase, std::vector<std::string> sol);
	virtual ~DeCompletar();
	std::string getProblema();
	std::vector<std::string> getSolucion();
	bool resolver(std::vector<std::string> sol);
	DT_DataDeCompletar* getDataDeCompletar();
};

#endif /* DECOMPLETAR_H_ */
