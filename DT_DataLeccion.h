#ifndef DT_DATALECCION_H
#define DT_DATALECCION_H
#include<iostream>

class DT_DataLeccion {
private:
	int idLeccion;
	std::string tema;
	std::string objetivo;
public:
	DT_DataLeccion();
	DT_DataLeccion(int id, std::string temaL, std::string objL);
	virtual ~DT_DataLeccion();
	int getID();
	std::string getTema();
	std::string getObjetivo();
	friend std::ostream& operator<<(std::ostream& os, DT_DataLeccion* lec);
};


#endif
