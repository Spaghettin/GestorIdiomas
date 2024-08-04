/*
 * Inscripcion.cpp
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#include "Inscripcion.h"
#include "OrderedDictionary.h"
#include "ctime"

Inscripcion::Inscripcion(Estudiante* est, Curso* crs) {
	this->curso = crs;
	this->estudiante = est;
	this->ejerciciosAprobados = new OrderedDictionary();
	this->leccionActual = crs->getPrimerLeccion();

	//obtengo la fecha actual
	time_t tActual = time(nullptr);
	tm *tiempo = localtime(&tActual);
	int dia = tiempo->tm_mday;
	int mes = tiempo->tm_mon + 1;
	int ano = tiempo->tm_year + 1900;

	this->fechaInsc = new DT_Date(dia, mes, ano);
	this->progresoCurso = 0;
	this->progresoLeccion = 0;
}

Inscripcion::~Inscripcion() {
	std::string nombreCurso = this->curso->getNombreCurso();
	this->estudiante->removerInscripcion(nombreCurso);
}

std::string Inscripcion::getNicknameEstudiante() {
	return this->estudiante->getNickname();
}

std::string Inscripcion::getNombreEstudiante() {
	return this->estudiante->getNombreUsuario();
}

std::string Inscripcion::getNombreCurso() {
	return this->curso->getNombreCurso();
}

int Inscripcion::getIdLeccionActual() {
	return this->leccionActual->getID();
}

float Inscripcion::getProgresoCurso() {
	return this->progresoCurso;
}

float Inscripcion::getProgresoLeccion() {
	return this->progresoLeccion;
}

std::string Inscripcion::getFechaInscToString() {
	DT_Date* fechaInsc = this->fechaInsc;
	std::string dia = std::to_string(fechaInsc->getDia());
	std::string mes = std::to_string(fechaInsc->getMes());
	std::string ano = std::to_string(fechaInsc->getAno());

	return (dia + "/" + mes + "/" + ano);
}


DT_Date* Inscripcion::getFechaInsc() {
	return this->fechaInsc;
}

void Inscripcion::setFechaInsc(DT_Date* Fecha) {
	this->fechaInsc = Fecha;
}

bool Inscripcion::aprobado() {
	return (this->getProgresoCurso() == 100);
}

void Inscripcion::setProgresoCurso(float n) {
	this->progresoCurso = n;
}

void Inscripcion::setProgresoLeccion(float n) {
	this->progresoLeccion = n;
}

void Inscripcion::setLeccionActual(Leccion* lecc){
	this->leccionActual = lecc;
}

std::set<int> Inscripcion::listarEjerciciosPendientes() {
	std::set<int> ejerciciosPendientes;
	std::set<int> listaCompletaEjercicios = this->leccionActual->getListaEjercicios();
	bool estaPendiente;
	IKey* ik;

	for (int idEjer : listaCompletaEjercicios) {
		ik = new Integer(idEjer);
		estaPendiente = !(this->ejerciciosAprobados->member(ik));
		if (estaPendiente) {
			ejerciciosPendientes.insert(idEjer);
		}
		delete ik;
	}

	return ejerciciosPendientes;
}

//bool Inscripcion::resolverEjercicioDeTraduccion(std::string solucion, int idEjercicio) {
//	DeTraduccion* ejercicio = (DeTraduccion*)this->leccionActual->getEjercicio(idEjercicio);
//	bool esCorrecto = ejercicio->resolver(solucion);
//
//	if (esCorrecto) {
//		IKey* ik = new Integer(ejercicio->getID());
//		this->ejerciciosAprobados->add(ik, ejercicio);
//
//		int cantTotalEjerciciosDeLeccion = this->leccionActual->getCantidadEjercicios();
//		int cantidadAprobados = this->ejerciciosAprobados->getSize();
//		float progresoLeccion = (cantidadAprobados * 100) / cantTotalEjerciciosDeLeccion;
//		this->setProgresoLeccion(progresoLeccion);
//		
//		if (this->getProgresoLeccion() == 100) {
//			Leccion* lecSiguiente = this->curso->getLeccionSiguiente(this->leccionActual);
//			this->setLeccionActual(lecSiguiente);
//			if (this->leccionActual != nullptr) {
//				this->setProgresoLeccion(0);
//			}
//		}
//
//		int cantTotalEjerciciosDeCurso = this->curso->getCantidadEjercicios();
//		float progresoCurso = (cantidadAprobados * 100) / cantTotalEjerciciosDeCurso;
//		this->setProgresoCurso(progresoCurso);
//	}
//
//	return esCorrecto;
//}
//
//bool Inscripcion::resolverEjercicioDeCompletar(std::vector<std::string> solucion, int idEjercicio) {
//	DeCompletar* ejercicio = (DeCompletar*)this->leccionActual->getEjercicio(idEjercicio);
//	bool esCorrecto = ejercicio->resolver(solucion);
//
//	if (esCorrecto) {
//		IKey* ik = new Integer(ejercicio->getID());
//		this->ejerciciosAprobados->add(ik, ejercicio);
//
//		int cantTotalEjerciciosDeLeccion = this->leccionActual->getCantidadEjercicios();
//		int cantidadAprobados = this->ejerciciosAprobados->getSize();
//		float progresoLeccion = (cantidadAprobados * 100) / cantTotalEjerciciosDeLeccion;
//		this->setProgresoLeccion(progresoLeccion);
//
//		if (this->getProgresoLeccion() == 100) {
//			Leccion* lecSiguiente = this->curso->getLeccionSiguiente(this->leccionActual);
//			this->setLeccionActual(lecSiguiente);
//			if (this->leccionActual != nullptr) {
//				this->setProgresoLeccion(0);
//			}
//		}
//		
//		int cantTotalEjerciciosDeCurso = this->curso->getCantidadEjercicios();
//		float progresoCurso = (cantidadAprobados * 100) / cantTotalEjerciciosDeCurso;
//		this->setProgresoCurso(progresoCurso);
//	}
//
//	return esCorrecto;
//}


bool Inscripcion::resolverEjercicioDeTraduccion(std::string solucion, int idEjercicio) {
	
	DeTraduccion* ejercicio = (DeTraduccion*)this->leccionActual->getEjercicio(idEjercicio);
	if (ejercicio){
		bool esCorrecto = ejercicio->resolver(solucion);
		if (esCorrecto) {
			IKey* ik = new Integer(ejercicio->getID());
			this->ejerciciosAprobados->add(ik, ejercicio);
			
			int cantTotalEjerciciosDeLeccion = this->leccionActual->getCantidadEjercicios();
			int cantidadAprobados = this->ejerciciosAprobados->getSize();
			float progresoLeccion = (cantidadAprobados * 100) / cantTotalEjerciciosDeLeccion;
			this->setProgresoLeccion(progresoLeccion);
			
			int cantTotalEjerciciosDeCurso = this->curso->getCantidadEjercicios();
			float progresoCurso = (cantidadAprobados * 100) / cantTotalEjerciciosDeCurso;
			this->setProgresoCurso(progresoCurso);
		}
		return esCorrecto;
		
	}else{
		return false;
	}
}

bool Inscripcion::resolverEjercicioDeCompletar(std::vector<std::string> solucion, int idEjercicio) {
	DeCompletar* ejercicio = (DeCompletar*)this->leccionActual->getEjercicio(idEjercicio);
	
	if(ejercicio){
		bool esCorrecto = ejercicio->resolver(solucion);
		
		if (esCorrecto) {
			IKey* ik = new Integer(ejercicio->getID());
			this->ejerciciosAprobados->add(ik, ejercicio);
			
			int cantTotalEjerciciosDeLeccion = this->leccionActual->getCantidadEjercicios();
			int cantidadAprobados = this->ejerciciosAprobados->getSize();
			float progresoLeccion = (cantidadAprobados * 100) / cantTotalEjerciciosDeLeccion;
			this->setProgresoLeccion(progresoLeccion);
			
			int cantTotalEjerciciosDeCurso = this->curso->getCantidadEjercicios();
			float progresoCurso = (cantidadAprobados * 100) / cantTotalEjerciciosDeCurso;
			this->setProgresoCurso(progresoCurso);
		}
		
		return esCorrecto;	
	}else{
		return false;
	
	}
	
}

DT_DataProblemaEjercicio* Inscripcion::getDataProblemaEjercicio(int idEjercicio) {
	DT_DataProblemaEjercicio* dtPE = this->leccionActual->getDataProblemaEjercicio(idEjercicio);
	return dtPE;
}

DT_DataProgresoCurso* Inscripcion::getDataProgresoCurso() {

	std::string nombreCurso = this->getNombreCurso();
	std::string nombreEstudiante = this->getNombreEstudiante();
	DT_Date* fechaIns = this->getFechaInsc();
	float progresoCurso = this->getProgresoCurso();
	float progresoLeccion = this->getProgresoLeccion();

	DT_DataProgresoCurso* dtpc = new DT_DataProgresoCurso(
			nombreCurso,
			nombreEstudiante,
			fechaIns,
			progresoCurso,
			progresoLeccion);

	return dtpc;
}
