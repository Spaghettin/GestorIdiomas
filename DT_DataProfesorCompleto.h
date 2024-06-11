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
	string nombre;
	string nickname;
	string instituto;
	set<string> idiomas;
};

#endif

