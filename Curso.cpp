/*
* Curso.cpp
*
*  Created on: Jun 19, 2024
*      Author: mat
*/

#include "Curso.h"
#include "OrderedDictionary.h"
#include "IKey.h"

Curso::Curso() {
	// TODO Auto-generated constructor stub
	
}

Curso::~Curso() {
	// TODO Auto-generated destructor stub
}

std::string Curso::getNombreCurso() {
	return this->nombreCurso;
}

std::string Curso::getDescripcionCurso() {
	return this->descripcionCurso;
}

std::string Curso::getDificultadToString() {
	switch (this->dificultadCurso) {
	case Basico:
		return "Basico";
	case Medio:
		return "Medio";
	case Avanzado:
		return "Avanzado";
	default:
		return "sin dificultad asignada";
	}
}

bool Curso::estaHabilitado() {
	return this->habilitado;
}

int Curso::getCantidadEjercicios() {
	return this->cantidadEjercicios;
}

int Curso::getCantidadLecciones() {
	return this->cantidadLecciones;
}

void Curso::setCantidadEjercicios(int n) {
	this->cantidadEjercicios = n;
}

void Curso::setCantidadLecciones(int n) {
	this->cantidadLecciones = n;
}

void Curso::habilitarCurso() {
	this->habilitado = true;
}

int Curso::crearLeccion(std::string tema, std::string objetivo) {
	Leccion* nuevaLeccion = new Leccion(tema, objetivo);
	int idLec = nuevaLeccion->getID();
	
	IKey* ik = new Integer(idLec);
	this->lecciones->add(ik, nuevaLeccion);
	setCantidadLecciones(this->lecciones->getSize());
	
	return idLec;
}

std::set<DT_DataLeccion*> Curso::listarLecciones() {
	
	std::set<DT_DataLeccion*> setDataLecciones;
	Leccion* lec;
	IIterator* it = this->lecciones->getIterator();
	
	while (it->hasCurrent()) {
		lec = (Leccion*)it->getCurrent();
		setDataLecciones.insert(lec->getDataLeccion());
		it->next();
	}
	
	return setDataLecciones;
}

void Curso::crearEjercicioDeTraduccion( int idLeccion,
									   std::string descripcionEjercicio,
									   std::string frase, std::string solucion) {
	
	IKey* ik = new Integer(idLeccion);
	Leccion* lec = (Leccion*)this->lecciones->find(ik);
	lec->crearEjercicioDeTraduccion(descripcionEjercicio, frase, solucion);
}

void Curso::crearEjercicioDeCompletar( int idLeccion,
									  std::string descripcionEjercicio,
									  std::string frase,
									  std::vector<std::string> solucion) {
	
	IKey* ik = new Integer(idLeccion);
	Leccion* lec = (Leccion*)this->lecciones->find(ik);
	lec->crearEjercicioDeCompletar(descripcionEjercicio, frase, solucion);
}

bool Curso::estaInscripto(std::string nicknameEst) {
	//IKey* ik = new String(nicknameEst);
	//bool yaEstaInscripto = this->inscripciones->member(ik);
	//return yaEstaInscripto;
	return true;
}

Leccion* Curso::getPrimerLeccion() {
	IIterator* it = this->lecciones->getIterator();
	return (Leccion*)it->getCurrent();
}

std::set<std::string> Curso::getPrevias() {
	std::set<std::string> nombrePrevias;
	IIterator* it = this->previas->getIterator();
	std::string previa;
	
	while(it->hasCurrent()) {
		previa = ((Curso*)it->getCurrent())->getNombreCurso();
		nombrePrevias.insert(previa);
		it->next();
	}
	
	return nombrePrevias;
}

DT_DataCurso* Curso::getDataCurso() {
	DT_DataCurso* DataC = new DT_DataCurso(
			 this->getNombreCurso(),
			 this->getDescripcionCurso(),
			 this->getDificultadToString()
			 );
	return DataC;
}

DT_DataPromedioCurso* Curso::getDataPromedioCurso() {
	std::string nombreC = this->getNombreCurso();
	float sumatoriaProgreso = 0;
	float promedioProgreso;
	int cantInscripciones = this->inscripciones->getSize();
	Inscripcion* insc;
	
	IIterator* it = this->inscripciones->getIterator();
	while (it->hasCurrent()) {
		insc = (Inscripcion*)it->getCurrent();
		sumatoriaProgreso += insc->getProgresoCurso();
		it->next();
	}
	promedioProgreso = sumatoriaProgreso / cantInscripciones;
	
	DT_DataPromedioCurso* DataPC = new DT_DataPromedioCurso(nombreC, promedioProgreso);
	return DataPC;
}

void Curso::eliminarContenido() {
	//
}

DT_DataCursoConContador* Curso::getDataCursoConContador() {
	DT_DataCursoConContador* dataCCC = new DT_DataCursoConContador(
			 this->getNombreCurso(),
			 this->getDescripcionCurso(),
			 this->getDificultadToString(),
			 this->getCantidadLecciones(),
			 this->getCantidadEjercicios()
			 );
	
	return dataCCC;
}

