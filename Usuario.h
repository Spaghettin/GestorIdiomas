/*
 * Usuario.h
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#ifndef HEADERS_USUARIO_H_
#define HEADERS_USUARIO_H_

#include "string"
#include "IDictionary.h"
#include "ICollectible.h"
#include "OrderedDictionary.h"
#include "DT_DataRegistroUsuario.h"
#include "DT_DataUsuarioGenerico.h"

class Usuario : public ICollectible {
protected:
	std::string nickname;
	std::string contrasena;
	std::string nombreUsuario;
	std::string descripcionUsuario;
public:
	Usuario();
	virtual ~Usuario();
	std::string getNickname();
	std::string getNombreUsuario();
	std::string getDescripcionUsuario();
	virtual DT_DataUsuarioGenerico* getDataUsuarioGenerico() = 0;
};

#endif /* HEADERS_USUARIO_H_ */
