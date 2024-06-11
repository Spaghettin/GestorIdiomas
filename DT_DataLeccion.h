#ifndef DT_DATALECCION_H
#define DT_DATALECCION_H
#include<iostream>

using namespace std;

class DT_DataLeccion {
public:
	DT_DataLeccion();
	DT_DataLeccion(const DT_DataLeccion &arg);
	~DT_DataLeccion();
private:
	int idLeccion;
	string tema;
	string objetivo;
};

#endif

