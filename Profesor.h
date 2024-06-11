#ifndef PROFESOR_H
#define PROFESOR_H
#include "Usuario.h"
using namespace std;

class Profesor : protected Usuario {
public:
	Profesor();
	Profesor(const Profesor &arg);
	~Profesor();
private:
	string nombreInstituto;
};

#endif

