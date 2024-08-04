/*
 * IOHandler.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: mat
 */

#include "IOHandler.h"

IOHandler::IOHandler() {}

IOHandler::~IOHandler() {
	// TODO Auto-generated destructor stub
}

bool IOHandler::validarDiaDelMes(int dia) {
	return ((dia > 0) && (dia < 32));
}

bool IOHandler::validarMes(int mes) {
	return ((mes > 0) && (mes < 13));
}

bool IOHandler::validarAnio(int anio) {

	time_t tActual = time(nullptr);
	tm *tiempo = localtime(&tActual);
	int anioActual = tiempo->tm_year + 1900;

	return ((anio > 1900) && (anio < anioActual));
}

bool IOHandler::validarFraseDeCompletar(std::string frase, int ocurrencias) {

	std::regex patron("---");
	bool contienePatron = regex_search(frase, patron);

	if (ocurrencias < 1 && !contienePatron) {
		return true;
	}

	if (ocurrencias < 1 && contienePatron) {
		return false;
	}

	if (contienePatron) {
		int posPatron = frase.find("---");
		return validarFraseDeCompletar(frase.substr(posPatron+3), ocurrencias-1);
	} else {
		return false;
	}
}

bool IOHandler::validarContrasena(std::string contrasena) {
	return (contrasena.length() >= 6);
}

bool IOHandler::validarNombreSinNumeros(std::string nombre) {
	return (std::string::npos != nombre.find_first_of("0123456789"));
}

bool IOHandler::validarNumeroSinCaracteres(std::string stringNumero) {
	return ( (!stringNumero.empty()) && (std::all_of(stringNumero.begin(), stringNumero.end(), ::isdigit)) );
}

bool IOHandler::validarOpcionMenuInt(int input, int condicion) {
	return (input == condicion);
}

bool IOHandler::validarOpcionMenuChar(char input, char condicion) {
	return (input == condicion);
}

std::string IOHandler::read(std::string variable){
	std::getline(std::cin, variable,'\n');
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return variable;
}

char IOHandler::readChar(char variable){
	std::cin>>variable;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return variable;
}

void IOHandler::printSet(const std::set<std::string>& mySet) {
	std::set<std::string> localSet = mySet;  // Copia los elementos de mySet a localSet
	for (const auto& element : localSet) {
		std::cout << element << std::endl;
	}
}

