/*
 * Curso.cpp
 *
 *  Created on: Jun 19, 2024
 *      Author: mat
 */

#include "Curso.h"
#include "OrderedDictionary.h"
#include "IKey.h"

Curso::Curso(DT_DataCurso* dataC, Profesor* prof, Idioma* idioma, std::set<Curso*> cprevios) {

	this->nombreCurso = dataC->getNombreCurso();
	this->descripcionCurso = dataC->getDescripcionCurso();
	this->dificultadCurso = dataC->getDificultadCursoToEnum();

	this->habilitado = false;
	this->cantidadEjercicios = 0;
	this->cantidadLecciones = 0;

	this->previas = new OrderedDictionary();
	this->inscripciones = new OrderedDictionary();
	this->lecciones = new OrderedDictionary();

	this->idiomaCurso = idioma;
	this->profesor = prof;

	std::string nombreCursoPrevio;
	IKey* ik;

	for (Curso* previo : cprevios) {
		nombreCursoPrevio = previo->getNombreCurso();
		ik = new String(nombreCursoPrevio.c_str());
		this->previas->add(ik, previo);
	}
}

Curso::~Curso() {
	IIterator* itLec = this->lecciones->getIterator();
	Leccion* lec;
	while (itLec->hasCurrent()) {
		lec = (Leccion*)itLec->getCurrent();
		delete lec;
		itLec->next();
	}
	delete itLec;

	IIterator* itInsc = this->inscripciones->getIterator();
	Inscripcion* insc;
	while (itInsc->hasCurrent()) {
		insc = (Inscripcion*)itInsc->getCurrent();
		delete insc;
		itInsc->next();
	}
	delete itInsc;

	this->profesor->removerCursoDictado(this->getNombreCurso());
}

bool Curso::esPrevia(Curso* crs) {
	std::string nombreCurso = crs->getNombreCurso();
	IKey* ik = new String(nombreCurso.c_str());
	bool crsEsPrevia = this->previas->member(ik);

	delete ik;

	return crsEsPrevia;
}

void Curso::removerPrevia(Curso* crs) {
	//precondicion: se que crs es previa de este curso porque controle previamente con esPrevia()
	std::string nombreCurso = crs->getNombreCurso();
	IKey* ik = new String(nombreCurso.c_str());
	this->previas->remove(ik);
	delete ik;
}

std::string Curso::getNombreCurso() {
	return this->nombreCurso;
}

std::string Curso::getDescripcionCurso() {
	return this->descripcionCurso;
}

std::string Curso::getDificultadToString() {
	switch (this->dificultadCurso) {
	case Principiante:
		return "Principiante";
	case Medio:
		return "Medio";
	case Avanzado:
		return "Avanzado";
	default:
		return "sin dificultad asignada";
	}
}

void Curso::setMemIns(Inscripcion* inscr){
	this->mem_ins = inscr;
}

Inscripcion* Curso::getMemIns(){
	return this->mem_ins;
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

void Curso::setLeccionActual(int lec){
	Leccion* lecc= nullptr;
	IKey* ik = new Integer(lec);
	lecc = (Leccion*)this->lecciones->find(ik);
	this->mem_ins->setLeccionActual(lecc);
}

bool Curso::tieneLeccionesSinEjercicios() {
	if (this->lecciones == nullptr) {
		return true;
	}
	
	bool tieneLeccionSinEjercicio = false;
	Leccion* lec = nullptr;
	
	IIterator* it = this->lecciones->getIterator();
	while (it->hasCurrent()) {
		lec = (Leccion*)it->getCurrent();
		tieneLeccionSinEjercicio = (lec->getCantidadEjercicios() == 0 );
		if (tieneLeccionSinEjercicio) {
			delete it;
			return true;
		}
		it->next();
	}
	
	delete it;
	return false;
}

bool Curso::habilitarCurso() {
	bool tieneLeccionesSinEjer = this->tieneLeccionesSinEjercicios();
	if (!tieneLeccionesSinEjer) {
		this->habilitado = true;
		return true;
	}
	return false;
}

int Curso::crearLeccion(std::string tema, std::string objetivo) {
	Leccion* nuevaLeccion = new Leccion(tema, objetivo);
	int idLec = nuevaLeccion->getID();

	IKey* ik = new Integer(idLec);
	this->lecciones->add(ik, nuevaLeccion);
	setCantidadLecciones(this->lecciones->getSize());

	return idLec;
}

Leccion* Curso::getPrimerLeccion() {
	IIterator* it = this->lecciones->getIterator();
	Leccion* primerLec = (Leccion*)it->getCurrent();

	delete it;

	return primerLec;
}

Leccion* Curso::getLeccionSiguiente(Leccion* lecActual) {
	IIterator* it = this->lecciones->getIterator();
	Leccion* lec = nullptr;
	
	while (it->hasCurrent()) {
		lec = (Leccion*)it->getCurrent();
		if (lecActual == lec) {
			it->next();
			lec = (Leccion*)it->getCurrent();
			delete it;
			return lec;
		}
		it->next();
	}
	delete it;
	return nullptr;
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
	delete it;

	return setDataLecciones;
}

void Curso::agregarInscripcion(Inscripcion* nuevaInsc) {
	this->setMemIns(nuevaInsc);
	std::string nickEstudiante = nuevaInsc->getNicknameEstudiante();
	IKey* ik = new String(nickEstudiante.c_str());
	this->inscripciones->add(ik, nuevaInsc);
}

int Curso::crearEjercicioDeTraduccion(int idLeccion,
		std::string descripcionEjercicio,
		std::string frase, std::string solucion) {

	IKey* ik = new Integer(idLeccion);
	Leccion* lec = (Leccion*)this->lecciones->find(ik);
	lec->crearEjercicioDeTraduccion(descripcionEjercicio, frase, solucion);
	delete ik;

	this->setCantidadEjercicios(this->getCantidadEjercicios()+1);
}

int Curso::crearEjercicioDeCompletar( int idLeccion,
		std::string descripcionEjercicio,
		std::string frase,
		std::vector<std::string> solucion) {

	IKey* ik = new Integer(idLeccion);
	Leccion* lec = (Leccion*)this->lecciones->find(ik);
	lec->crearEjercicioDeCompletar(descripcionEjercicio, frase, solucion);
	delete ik;

	this->setCantidadEjercicios(this->getCantidadEjercicios()+1);
}

bool Curso::estaInscripto(std::string nicknameEst) {
	IKey* ik = new String(nicknameEst.c_str());
	bool yaEstaInscripto = this->inscripciones->member(ik);
	delete ik;
	return yaEstaInscripto;
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
	delete it;

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
	float promedioProgreso = 0;
	int cantInscripciones = this->inscripciones->getSize();
	Inscripcion* insc;

	IIterator* it = this->inscripciones->getIterator();
	while (it->hasCurrent()) {
		insc = (Inscripcion*)it->getCurrent();
		sumatoriaProgreso += insc->getProgresoCurso();
		it->next();
	}
	delete it;
	if (cantInscripciones != 0) {
		promedioProgreso = sumatoriaProgreso / cantInscripciones;
	}
	
	DT_DataPromedioCurso* DataPC = new DT_DataPromedioCurso(nombreC, promedioProgreso);
	
	return DataPC;
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

DT_DataCursoCompleto* Curso::getDataCursoCompleto() {
	
	std::string nombreIdioma = this->idiomaCurso->getNombre();
	std::string nombreProf = this->profesor->getNombreUsuario();
	DT_DataCurso* dataCurso = this->getDataCurso();
	
	std::set<DT_DataLeccionConEjercicio*> setDataLeccionesConEj = {};
	
	if (this->cantidadLecciones > 0) {
		IIterator* it = this->lecciones->getIterator();
		Leccion* lec;
		DT_DataLeccionConEjercicio* dataLecConEj;
		
		while (it->hasCurrent()) {
			lec = (Leccion*)it->getCurrent();
			dataLecConEj = lec->getDataLeccionConEjercicio();
			setDataLeccionesConEj.insert(dataLecConEj);
			it->next();
		}
		delete it;
	}
	
	std::set<DT_DataEstudianteCurso*> setDataEstudiantesCurso = {};
	
	if (this->inscripciones->getSize() > 0) {
		IIterator* it = this->inscripciones->getIterator();
		Inscripcion* insc;
		DT_DataEstudianteCurso* dataEst;
		std::string nombreEstudiante;
		DT_Date* fechaInscripcion;
		
		while (it->hasCurrent()) {
			insc = (Inscripcion*)it->getCurrent();
			fechaInscripcion = insc->getFechaInsc();
			nombreEstudiante = insc->getNombreEstudiante();
			dataEst = new DT_DataEstudianteCurso(nombreEstudiante, fechaInscripcion);
			setDataEstudiantesCurso.insert(dataEst);
			it->next();
		}
		delete it;
	}
	
	DT_DataCursoCompleto* dataCC = new DT_DataCursoCompleto(
			dataCurso, 
			nombreIdioma, 
			nombreProf, 
			setDataLeccionesConEj, 
			setDataEstudiantesCurso);
			
	return dataCC;
}

DT_DataPromedioCurso* Curso::getInformacionCurso(Curso* curso){
	
	DT_DataPromedioCurso* dataPromCurso;
	dataPromCurso = curso->getDataPromedioCurso();
	return dataPromCurso;
}
