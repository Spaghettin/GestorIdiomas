#ifndef DT_DATAProfesor_H
#define DT_DATAProfesor_H
#include<iostream>
#include "date.h"
using namespace std;

class DT_DataProfesor {
private:
	std::string nombre;
	std::string contrasena;
	std::string descripcion;
	std::string nickname;
public:
	DT_DataProfesor();
	DT_DataProfesor(std::string nickname,
					std::string nombre,
					std::string descripcion,
					std::string contrasena);
	DT_DataProfesor(const DT_DataProfesor &arg);
	~DT_DataProfesor();
	std::string getNickname() const;
	std::string getContrasena() const;
	std::string getNombre() const;
	std::string getDescripcion() const;
	
};

#endif
