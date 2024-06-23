#ifndef EJERCICIO_H_
#define EJERCICIO_H_

#include "string"
#include "vector"
#include "DT_DataProblemaEjercicio.h"
#include "ICollectible.h"

class DT_DataProblemaEjercicio;

class Ejercicio : public ICollectible {
protected:
	static int cantInstancias;
	int idEjercicio;
	std::string descripcion;
	
public:
	Ejercicio();
	virtual ~Ejercicio();
	virtual std::string getProblema() = 0;
	DT_DataProblemaEjercicio* getDataProblema();
	std::string getDescripcion();
	int getID();
};

#endif /* EJERCICIO_H_ */
