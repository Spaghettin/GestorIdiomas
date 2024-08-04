/*
 * IOHandler.h
 *
 *  Created on: Jun 27, 2024
 *      Author: mat
 */

#ifndef IOHANDLER_H_
#define IOHANDLER_H_

#include <iostream>
#include "string"
#include "ctime"
#include "regex"
#include "limits"
#include "set"

class IOHandler {
public:
	IOHandler();
	virtual ~IOHandler();
	bool validarDiaDelMes(int dia);
	bool validarMes(int mes);
	bool validarAnio(int anio);
	bool validarFraseDeCompletar(std::string frase, int ocurrencias);
	bool validarContrasena(std::string contrasena);
	bool validarNombreSinNumeros(std::string nombre);
	bool validarNumeroSinCaracteres(std::string stringNumero);
	bool validarOpcionMenuInt(int input, int condicion);
	bool validarOpcionMenuChar(char input, char condicion);
	std::string read(std::string variable);
	char readChar(char variable);
	void printSet(const std::set<std::string>& mySet);
};

#endif /* IOHANDLER_H_ */
