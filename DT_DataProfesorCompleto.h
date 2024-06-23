#ifndef DT_DATAPROFESORCOMPLETO_H
#define DT_DATAPROFESORCOMPLETO_H
#include<iostream>
#include <set>
using namespace std;

class DT_DataProfesorCompleto {
public:
	DT_DataProfesorCompleto();
	DT_DataProfesorCompleto(const DT_DataProfesorCompleto &arg);
	~DT_DataProfesorCompleto();
private:
	std::string nombre;
	std::string nickname;
	std::string instituto;
	set<std::string> idiomas;
};

#endif

