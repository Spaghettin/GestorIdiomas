#ifndef DT_DATAPROBLEMAEJERCICIO_H
#define DT_DATAPROBLEMAEJERCICIO_H
#include<iostream>

using namespace std;

class DT_DataProblemaEjercicio {
public:
	DT_DataProblemaEjercicio();
	DT_DataProblemaEjercicio(const DT_DataProblemaEjercicio &arg);
	~DT_DataProblemaEjercicio();
private:
	string descripcion;
	string fraseProblema;
};

#endif

