/*
 * Leccion.cpp
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#include "Leccion.h"
#include "DeCompletar.h"
#include "DeTraduccion.h"
#include "OrderedDictionary.h"
#include "IKey.h"
#include "Integer.h"

int Leccion::cantInstancias = 0;

Leccion::Leccion() {
	this->idLeccion = ++(this->cantInstancias);
	this->ejercicios = new OrderedDictionary();
}

Leccion::Leccion(std::string tema, std::string obj) {
	this->tema = tema;
	this->objetivo = obj;
	this->idLeccion = ++(this->cantInstancias);
	this->ejercicios = new OrderedDictionary();
}

std::string Leccion::getTema() {
	return this->tema;
}

std::string Leccion::getObjetivo() {
	return this->objetivo;
}

int Leccion::getID() {
	return this->idLeccion;
}

int Leccion::getCantidadEjercicios() {
	return this->ejercicios->getSize();
}

Ejercicio* Leccion::getEjercicio(int idEjercicio) {
	IKey* ik = new Integer(idEjercicio);
	Ejercicio* ejercicio = (Ejercicio*)this->ejercicios->find(ik);
	delete ik;
	return ejercicio;
}

DT_DataProblemaEjercicio* Leccion::getDataProblemaEjercicio(int idEjercicio) {
	IKey* ik = new Integer(idEjercicio);
	Ejercicio* ej = (Ejercicio*)(this->ejercicios->find(ik));
	delete ik;
	return ej->getDataProblema();
}

std::set<int> Leccion::getListaEjercicios() {
	std::set<int> idEjercicios;
	int id;
	Ejercicio* ej;
	IIterator* it = this->ejercicios->getIterator();

	while (it->hasCurrent()) {
		ej = (Ejercicio*)(it->getCurrent());
		id = ej->getID();
		idEjercicios.insert(id);
		it->next();
	}
	delete it;

	return idEjercicios;
}

void Leccion::crearEjercicioDeTraduccion(std::string descripcion, std::string frase, std::string solucion) {
	Ejercicio* nuevoEjercicio = new DeTraduccion(descripcion, frase, solucion);
	int idNuevoEjercicio = nuevoEjercicio->getID();
	IKey* ik = new Integer(idNuevoEjercicio);
	this->ejercicios->add(ik, nuevoEjercicio);
}

void Leccion::crearEjercicioDeCompletar(std::string descripcion, std::string frase, std::vector<std::string> solucion) {
	Ejercicio* nuevoEjercicio = new DeCompletar(descripcion, frase, solucion);
	int idNuevoEjercicio = nuevoEjercicio->getID();
	IKey* ik = new Integer(idNuevoEjercicio);
	this->ejercicios->add(ik, nuevoEjercicio);
}

DT_DataLeccion* Leccion::getDataLeccion() {
	DT_DataLeccion* DL = new DT_DataLeccion(
			this->getID(),
			this->getTema(),
			this->getObjetivo()
			);
	return DL;
}

DT_DataLeccionConEjercicio* Leccion::getDataLeccionConEjercicio() {
	DT_DataLeccionConEjercicio* dataLecConEj;
	
	int idLeccion = this->getID();
	std::string temaLec = this->getTema();
	std::string objetivoLec = this->getObjetivo();
	
	std::set<DT_DataDeCompletar*> setDeCompletar = {};
	std::set<DT_DataDeTraduccion*> setDeTraduccion = {};
	
	if (this->getCantidadEjercicios() > 0) {
		IIterator* it = this->ejercicios->getIterator();
		Ejercicio* ejer;
		DeCompletar* deComp;
		DeTraduccion* deTrad;
		DT_DataDeCompletar* dataDeComp;
		DT_DataDeTraduccion* dataDeTrad;
		
		while (it->hasCurrent()) {
			ejer = (Ejercicio*)it->getCurrent();
			
			if (dynamic_cast<DeCompletar*>(ejer) != nullptr) {
				deComp = (DeCompletar*)ejer;
				dataDeComp = deComp->getDataDeCompletar();
				setDeCompletar.insert(dataDeComp);
			} else {
				deTrad = (DeTraduccion*)ejer;
				dataDeTrad = deTrad->getDataDeTraduccion();
				setDeTraduccion.insert(dataDeTrad);
			}
			it->next();
		}
		delete it;
	}
	
	dataLecConEj = new DT_DataLeccionConEjercicio(idLeccion, temaLec, objetivoLec, setDeCompletar, setDeTraduccion);
	return dataLecConEj;
}

Leccion::~Leccion() {
	IIterator* it = this->ejercicios->getIterator();
	Ejercicio* ej;
	while(it->hasCurrent()) {
		ej = (Ejercicio*)it->getCurrent();
		delete ej;
		it->next();
	}
	delete it;
}
