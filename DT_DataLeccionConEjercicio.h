#ifndef DT_DATALECCIONCONEJERCICIO_H
#define DT_DATALECCIONCONEJERCICIO_H

#include "DT_DataDeTraduccion.h"
#include "DT_DataDeCompletar.h"
#include "set"

class DT_DataLeccionConEjercicio {
private:
	int idLeccion;
	std::string tema;
	std::string objetivo;
	std::set<DT_DataDeCompletar*> setDeCompletar;
	std::set<DT_DataDeTraduccion*> setDeTraduccion;
public:
	DT_DataLeccionConEjercicio(
		int idLeccion,
		std::string tema, 
		std::string objetivo, 
		std::set<DT_DataDeCompletar*> setDeCompletar, 
		std::set<DT_DataDeTraduccion*> setDeTraduccion);
	~DT_DataLeccionConEjercicio();
	int getIdLeccion();
	std::string getTema();
	std::string getObjetivo();
	std::set<DT_DataDeCompletar*> getSetDeCompletar();
	std::set<DT_DataDeTraduccion*> getSetDeTraduccion();
	friend std::ostream& operator<<(std::ostream& os, DT_DataLeccionConEjercicio* dataLec);
};

#endif

