#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>

using namespace std;

class Usuario {
public:
	Usuario();
	Usuario(const Usuario &arg);
	~Usuario();
	virtual string toString() = 0;
private:
	string nickname;
	string contrasena;
	string nombre;
	string descripcion;
};

#endif

