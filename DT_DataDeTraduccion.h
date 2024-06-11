#ifndef DT_DATADETRADUCCION_H
#define DT_DATADETRADUCCION_H
#include<iostream>

using namespace std;

class DT_DataDeTraduccion {
public:
	DT_DataDeTraduccion();
	DT_DataDeTraduccion(const DT_DataDeTraduccion &arg);
	~DT_DataDeTraduccion();
private:
	string solucion;
	string fraseATraducir;
	string descripcion;
};

#endif

