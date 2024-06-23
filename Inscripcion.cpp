#include "Inscripcion.h"
#include "OrderedDictionary.h"
#include "ctime"

Inscripcion::Inscripcion(Estudiante* est, Curso* crs) {
	this->curso = crs;
	this->estudiante = est;
	this->ejerciciosAprobados = new OrderedDictionary();
	//this->leccionActual = crs->getPrimerLeccion();
	
	//obtengo la fecha actual
	time_t tActual = time(nullptr);
	tm *tiempo = localtime(&tActual);
	int dia = tiempo->tm_mday;
	int mes = tiempo->tm_mon + 1;
	int ano = tiempo->tm_year + 1900;
	
	this->fechaInsc = new date(dia, mes, ano);
	this->progresoCurso = 0;
	this->progresoLeccion = 0;
}

Inscripcion::~Inscripcion() {
	// TODO Auto-generated destructor stub
}

std::string Inscripcion::getNicknameEstudiante() {
	return this->estudiante->getNickname();
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
	date* fechaInsc = this->fechaInsc;
	std::string dia = std::to_string(fechaInsc->getDia());
	std::string mes = std::to_string(fechaInsc->getMes());
	std::string ano = std::to_string(fechaInsc->getAno());
	
	return (dia + "/" + mes + "/" + ano);
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

bool Inscripcion::resolverEjercicioDeTraduccion(std::string solucion, int idEjercicio) {
	DeTraduccion* ejercicio = (DeTraduccion*)this->leccionActual->getEjercicio(idEjercicio);
	bool esCorrecto = ejercicio->resolver(solucion);
	
	if (esCorrecto) {
		IKey* ik = new Integer(ejercicio->getID());
		this->ejerciciosAprobados->add(ik, ejercicio);
	}
	
	return esCorrecto;
}

bool Inscripcion::resolverEjercicioDeCompletar(std::vector<std::string> solucion, int idEjercicio) {
	DeCompletar* ejercicio = (DeCompletar*)this->leccionActual->getEjercicio(idEjercicio);
	bool esCorrecto = ejercicio->resolver(solucion);
	
	if (esCorrecto) {
		IKey* ik = new Integer(ejercicio->getID());
		this->ejerciciosAprobados->add(ik, ejercicio);
	}
	
	return esCorrecto;
}

DT_DataProblemaEjercicio* Inscripcion::getDataProblemaEjercicio(int idEjercicio) {
	DT_DataProblemaEjercicio* dtPE = this->leccionActual->getDataProblemaEjercicio(idEjercicio);
	return dtPE;
}
