#ifndef DT_DATACURSO_H
#define DT_DATACURSO_H
#include "iostream"
#include "string"
#include "enums.h"

class DT_DataCurso {
private:
	std::string nombreCurso;
	std::string descripcionCurso;
	std::string dificultadCurso;
public:
	DT_DataCurso();
	DT_DataCurso(std::string nombre, std::string desc, std::string dif);
	virtual ~DT_DataCurso();
	std::string getNombreCurso();
	std::string getDescripcionCurso();
	std::string getDificultadCurso();
	friend std::ostream& operator<<(std::ostream& os, DT_DataCurso* dataC);
};

#endif

