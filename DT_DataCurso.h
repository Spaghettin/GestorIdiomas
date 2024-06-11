#ifndef DT_DATACURSO_H
#define DT_DATACURSO_H

#include<iostream>
enum  dificultad{Basico, Intermedio, Dificil};
using namespace std;

class DT_DataCurso {
public:
	DT_DataCurso();
	DT_DataCurso(const DT_DataCurso &arg);
	~DT_DataCurso();
private:
	string nombre;
	string descripcion;
	dificultad dificultad;
};

#endif

