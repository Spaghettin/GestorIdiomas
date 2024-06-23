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
	return (Ejercicio*)(this->ejercicios->find(ik));
}

DT_DataProblemaEjercicio* Leccion::getDataProblemaEjercicio(int idEjercicio) {
	IKey* ik = new Integer(idEjercicio);
	Ejercicio* ej = (Ejercicio*)(this->ejercicios->find(ik));
	
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

Leccion::~Leccion() {
	// TODO Auto-generated destructor stub
}
