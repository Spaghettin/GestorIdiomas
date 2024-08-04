/*
 * Leccion.h
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#ifndef LECCION_H_
#define LECCION_H_

#include "string"
#include "vector"
#include "set"

#include "DT_DataLeccion.h"
#include "DT_DataLeccionConEjercicio.h"
#include "Ejercicio.h"
#include "IDictionary.h"

class DT_DataLeccion;
class DT_DataProblemaEjercicio;

class Leccion : public ICollectible {
private:
	std::string tema;
	std::string objetivo;
	int idLeccion;
	IDictionary* ejercicios;
	static int cantInstancias;
public:
	Leccion();
	Leccion(std::string tema, std::string obj);
	virtual ~Leccion();
	std::string getTema();
	std::string getObjetivo();
	int getID();
	int getCantidadEjercicios();
	Ejercicio* getEjercicio(int idEjercicio);
	std::set<int> getListaEjercicios();
	DT_DataLeccionConEjercicio* getDataLeccionConEjercicio();
	DT_DataLeccion* getDataLeccion();
	DT_DataProblemaEjercicio* getDataProblemaEjercicio(int idEjercicio);
	void crearEjercicioDeTraduccion(std::string descripcion, std::string frase, std::string solucion);
	void crearEjercicioDeCompletar(std::string descripcion, std::string frase, std::vector<std::string> solucion);
};

#endif /* LECCION_H_ */
