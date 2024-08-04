#ifndef DT_DATAREGISTROUSUARIO_H
#define DT_DATAREGISTROUSUARIO_H
#include<iostream>

using namespace std;

class DT_DataRegistroUsuario {
public:
	DT_DataRegistroUsuario(
			std::string nickname,
			std::string nombre,
			std::string descripcion,
			std::string contrasena);
	~DT_DataRegistroUsuario();
	std::string getNickname();
	std::string getContrasena();
	std::string getNombre();
	std::string getDescripcion();
private:
	std::string nickname;
	std::string contrasena;
	std::string nombre;
	std::string descripcion;
};

#endif

