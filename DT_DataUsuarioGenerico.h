#ifndef DT_DATAUSUARIOGENERICO_H
#define DT_DATAUSUARIOGENERICO_H
#include<iostream>
#include "DT_DataInfoEstudiante.h"
#include "DT_DataInfoProfesor.h"
using namespace std;

class DT_DataUsuarioGenerico {
public:
	DT_DataUsuarioGenerico(
		   std::string nickname, 
		   std::string descripcion,
		   DT_DataInfoEstudiante* dataEst,
		   DT_DataInfoProfesor* dataProf
   );
	~DT_DataUsuarioGenerico();
	std::string getNickname();
	std::string getDescripcion();
	DT_DataInfoEstudiante* getDataInfoEstudiante();
	DT_DataInfoProfesor* getDataInfoProfesor();
	friend std::ostream& operator<<(std::ostream& os, DT_DataUsuarioGenerico* dataUsr);
private:
	std::string nickname;
	std::string descripcion;
	DT_DataInfoEstudiante* datosEstudiante;
	DT_DataInfoProfesor* datosProfesor;
};

#endif

