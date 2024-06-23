#ifndef DT_DATAREGISTROUSUARIO_H
#define DT_DATAREGISTROUSUARIO_H
#include<iostream>

using namespace std;

class DT_DataRegistroUsuario {
public:
	DT_DataRegistroUsuario();
	DT_DataRegistroUsuario(const DT_DataRegistroUsuario &arg);
	~DT_DataRegistroUsuario();
private:
	std::string nickname;
	std::string contrasena;
	std::string nombre;
	std::string descripcion;
};

#endif

