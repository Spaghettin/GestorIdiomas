#ifndef DT_DATALECCIONCONEJERCICIO_H
#define DT_DATALECCIONCONEJERCICIO_H
#include<iostream>
#include "DT_DataDeTraduccion.h"
#include "DT_DataDeCompletar.h"
#include <set>
using namespace std;

class DT_DataLeccionConEjercicio {
public:
	DT_DataLeccionConEjercicio();
	DT_DataLeccionConEjercicio(const DT_DataLeccionConEjercicio &arg);
	~DT_DataLeccionConEjercicio();
private:
	string tema;
	string objetivo;
	set<DT_DataDeCompletar> DeCompletar;
	set<DT_DataDeTraduccion> DeTraduccion;
};

#endif

