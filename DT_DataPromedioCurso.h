/*
 * DT_DataPromedioCurso.h
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#include "string"
#include "iostream"

#ifndef HEADERS_DT_DATAPROMEDIOCURSO_H_
#define HEADERS_DT_DATAPROMEDIOCURSO_H_

class DT_DataPromedioCurso {
private:
	std::string nombreCurso;
	float promedioProgresoCurso;
public:
	DT_DataPromedioCurso(std::string nombreC, float promedioProgresoC);
	virtual ~DT_DataPromedioCurso();
	std::string getNombreCurso();
	float getPromedioProgresoCurso();
	friend std::ostream& operator<<(std::ostream& os, DT_DataPromedioCurso* dataPC);
};

#endif /* HEADERS_DT_DATAPROMEDIOCURSO_H_ */
