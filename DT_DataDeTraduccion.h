#ifndef DT_DATADETRADUCCION_H
#define DT_DATADETRADUCCION_H
#include<iostream>

class DT_DataDeTraduccion {
private:
std::string solucion;
std::string fraseATraducir;
std::string descripcion;
public:
	DT_DataDeTraduccion(std::string descripcion, std::string fraseATraducir, std::string solucion);
	~DT_DataDeTraduccion();
	std::string getDescripcion();
	std::string getFraseProblema();
	std::string getSolucion();
	friend std::ostream& operator<<(std::ostream& os, DT_DataDeTraduccion* dtdt);
};

#endif

