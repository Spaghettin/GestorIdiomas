#ifndef DT_DATAUSUARIOGENERICO_H
#define DT_DATAUSUARIOGENERICO_H
#include<iostream>
#include "DT_DataInfoEstudiante.h"
#include "DT_DataInfoProfesor.h"
using namespace std;

class DT_DataUsuarioGenerico {
public:
	DT_DataUsuarioGenerico();
	DT_DataUsuarioGenerico(const DT_DataUsuarioGenerico &arg);
	~DT_DataUsuarioGenerico();
private:
	string nickname;
	string descripcion;
	DT_DataInfoEstudiante datosEstudiante;
	DT_DataInfoProfesor datosProfesor;
};

#endif

