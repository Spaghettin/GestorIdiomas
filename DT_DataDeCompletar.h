#ifndef DT_DATADECOMPLETAR_H
#define DT_DATADECOMPLETAR_H

#include<iostream>
#include "vector"
#include "string"

class DT_DataDeCompletar {
	private:
		std::vector<std::string> solucion;
		std::string fraseIncompleta;
		std::string descripcion;
	public:
		DT_DataDeCompletar(std::string descripcion, std::string fraseIncompleta, std::vector<std::string> solucion);
		~DT_DataDeCompletar();
		std::string getSolucionToString();
		std::string getFraseProblema();
		std::string getDescripcion();
		friend std::ostream& operator<<(std::ostream& os, DT_DataDeCompletar* dtdc);

};

#endif

