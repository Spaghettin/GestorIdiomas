#ifndef DT_DATADECOMPLETAR_H
#define DT_DATADECOMPLETAR_H
#include<iostream>
#include <set>
using namespace std;

class DT_DataDeCompletar {
public:
	DT_DataDeCompletar();
	DT_DataDeCompletar(const DT_DataDeCompletar &arg);
	~DT_DataDeCompletar();
private:
	set<std::string> solucion;
	std::string fraseIncompleta;
	std::string descripcion;
};

#endif

