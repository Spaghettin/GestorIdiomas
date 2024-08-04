/*
 * DT_DataLeccion.h
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#ifndef HEADERS_DT_DATALECCION_H_
#define HEADERS_DT_DATALECCION_H_

#include "string"
#include "iostream"

class DT_DataLeccion {
private:
	int idLeccion;
	std::string tema;
	std::string objetivo;
public:
	DT_DataLeccion(int id, std::string temaL, std::string objL);
	virtual ~DT_DataLeccion();
	int getIdLeccion();
	std::string getTema();
	std::string getObjetivo();
	friend std::ostream& operator<<(std::ostream& os, DT_DataLeccion* dataLec);
};

#endif /* HEADERS_DT_DATALECCION_H_ */
