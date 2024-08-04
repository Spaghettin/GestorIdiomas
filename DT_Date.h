/*
 * DT_Date.h
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#ifndef HEADERS_DT_DATE_H_
#define HEADERS_DT_DATE_H_

#include "iostream"

class DT_Date {
	int dia;
	int mes;
	int ano;
public:
	DT_Date(int dia, int mes, int ano);
	int getDia();
	int getMes();
	int getAno();
	virtual ~DT_Date();
	friend std::ostream& operator<<(std::ostream& os, DT_Date* fecha);
};

#endif /* HEADERS_DT_DATE_H_ */
