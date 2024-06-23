#ifndef USUARIO_H
#define USUARIO_H
#include "iostream"
#include "IDictionary.h"
class Usuario : public ICollectible {
	
public:
	std::string nickname;
	std::string contrasena;
	std::string nombre;
	std::string descripcion;
	
public:
	Usuario();
	Usuario(const Usuario &arg);
	virtual ~Usuario() = 0;
	
	std::string getNickname() const;
	std::string getContrasena() const;
	std::string getNombre() const;
	std::string getDescripcion() const;
};

#endif

