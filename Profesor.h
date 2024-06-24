#ifndef PROFESOR_H
#define PROFESOR_H
#include "Usuario.h"
#include "iostream"
#include "DT_DataProfesor.h"
#include "Integer.h"
#include "set"
#include "Idioma.h"
#include "IKey.h"
#include "String.h"
#include "OrderedDictionary.h"

class Profesor : public Usuario {
private:
	std::string nombreInstituto;
	IDictionary* Idiomas;
public:
	Profesor();
	Profesor(DT_DataProfesor* datosProf, std::string nombreInstituto);
	Profesor(const Profesor &arg);
	~Profesor();
	
	std::string getnombreInstituto();
	Profesor* crearP(DT_DataProfesor* datosProfe, std::string nombreInstituto);
	void listarIdiomas();
	void seleccionarIdioma(Idioma* idiomaS);
	//friend std::ostream& operator<<(std::ostream& os, Profesor* prof);
	IDictionary* getidiomas();
	
};

#endif
