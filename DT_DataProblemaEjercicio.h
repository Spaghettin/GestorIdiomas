#ifndef DATAPROBLEMAEJERCICIO_H_
#define DATAPROBLEMAEJERCICIO_H_


#include "iostream"
#include "enums.h"
#include "Ejercicio.h"

class Ejercicio;

class DT_DataProblemaEjercicio {
private:
	std::string descripcion;
	std::string fraseProblema;
	tipoEjercicio tipoEj;
public:
	DT_DataProblemaEjercicio();
	DT_DataProblemaEjercicio(Ejercicio* ej);
	virtual ~DT_DataProblemaEjercicio();
	std::string getDescripcion();
	std::string getProblema();
	std::string getTipoEjercicio();
	friend std::ostream& operator<<(std::ostream& os, DT_DataProblemaEjercicio* dtPE);
};

#endif /* DATAPROBLEMAEJERCICIO_H_ */
