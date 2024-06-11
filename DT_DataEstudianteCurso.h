#ifndef DT_DATAESTUDIANTECURSO_H
#define DT_DATAESTUDIANTECURSO_H
#include<iostream>
#include "date.h"
using namespace std;

class DT_DataEstudianteCurso {
public:
	DT_DataEstudianteCurso();
	DT_DataEstudianteCurso(const DT_DataEstudianteCurso &arg);
	~DT_DataEstudianteCurso();
private:
	string nombreEstudiante;
	date fechaIns;
};

#endif

