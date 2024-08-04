/*
 * Estudiante.cpp
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#include "Estudiante.h"

Estudiante::Estudiante(DT_DataRegistroUsuario* datosEst, std::string paisRes, DT_Date* fechaNac) {
	this->nickname = datosEst->getNickname();
	this->nombreUsuario = datosEst->getNombre();
	this->contrasena = datosEst->getContrasena();
	this->descripcionUsuario = datosEst->getDescripcion();
	this->paisResidencia = paisRes;
	this->fechaNacimiento = fechaNac;
	this->inscripciones = new OrderedDictionary();
	delete datosEst;

}

Estudiante::~Estudiante() {
	// TODO Auto-generated destructor stub
}

void Estudiante::removerInscripcion(std::string nombreCurso) {
	IKey* ik = new String(nombreCurso.c_str());
	this->inscripciones->remove(ik);
	delete ik;
}

std::string Estudiante::getPaisResidencia() {
	return this->paisResidencia;
}
DT_Date* Estudiante::getFechaNacimiento() {
	return this->fechaNacimiento;
}

std::set<std::string> Estudiante::listarCursosPendientes(){
	Inscripcion* insc;
	std::set<std::string> listaCursosPendientes;
	IIterator* it = this->inscripciones->getIterator();
	bool cursoAprobado;

	while(it->hasCurrent()){
		insc = (Inscripcion*)it->getCurrent();
		cursoAprobado = insc->aprobado();
		if (!cursoAprobado) {
			listaCursosPendientes.insert(insc->getNombreCurso());
		}
		it->next();
	}
	delete it;

	return listaCursosPendientes;
}

std::set<int> Estudiante::listarEjerciciosPendientes(std::string nombreCurso) {
	IKey* ik = new String(nombreCurso.c_str());
	Inscripcion* insc = (Inscripcion*)this->inscripciones->find(ik);
	std::set<int> ejerciciosPendientes = insc->listarEjerciciosPendientes();
	delete ik;

	return ejerciciosPendientes;
}

void Estudiante::inscribirseACurso(Curso* crs) {
	Inscripcion* nuevaInsc = new Inscripcion(this, crs);
	std::string nombreCurso = crs->getNombreCurso();
	IKey* ik = new String(nombreCurso.c_str());
	this->inscripciones->add(ik, nuevaInsc);

	crs->agregarInscripcion(nuevaInsc);
}

DT_DataProblemaEjercicio* Estudiante::getDataProblemaEjercicio(std::string nombreCurso, int idEjercicio) {
	IKey* ik = new String(nombreCurso.c_str());
	Inscripcion* insc = (Inscripcion*)this->inscripciones->find(ik);
	DT_DataProblemaEjercicio* problemaEjer = insc->getDataProblemaEjercicio(idEjercicio);
	delete ik;
	
	return problemaEjer;
}

bool Estudiante::resolverEjercicioDeTraduccion(
		std::string nombreCurso,
		int idEjercicio,
		std::string solucion) {
	IKey* ik = new String(nombreCurso.c_str());
	Inscripcion* insc = (Inscripcion*)this->inscripciones->find(ik);
	bool esCorrecto = insc->resolverEjercicioDeTraduccion(solucion, idEjercicio);
	delete ik;

	return esCorrecto;
}

bool Estudiante::resolverEjercicioDeCompletar(
		std::string nombreCurso,
		int idEjercicio,
		std::vector<std::string> solucion) {
	IKey* ik = new String(nombreCurso.c_str());
	Inscripcion* insc = (Inscripcion*)this->inscripciones->find(ik);
	bool esCorrecto = insc->resolverEjercicioDeCompletar(solucion, idEjercicio);
	delete ik;

	return esCorrecto;
}

std::set<DT_DataProgresoCurso*> Estudiante::listarProgresoCursos() {
	IIterator* it = this->inscripciones->getIterator();
	DT_DataProgresoCurso* dtpc;
	Inscripcion* insc;
	std::set<DT_DataProgresoCurso*> listaProgresoCursos;

	while(it->hasCurrent()) {
		insc = (Inscripcion*)it->getCurrent();
		dtpc = insc->getDataProgresoCurso();
		listaProgresoCursos.insert(dtpc);
		it->next();
	}
	delete it;

	return listaProgresoCursos;
}

DT_DataEstudiante* Estudiante::getDataEstudiante() {
	DT_DataEstudiante* dataEst = new DT_DataEstudiante(
			this->getNombreUsuario(),
			this->getNickname(),
			this->getDescripcionUsuario(),
			this->getFechaNacimiento(),
			this->getPaisResidencia());

	return dataEst;
}

DT_DataInfoEstudiante* Estudiante::getDataInfoEstudiante() {
	DT_Date* fechaNac = this->getFechaNacimiento();
	std::string paisRes = this->getPaisResidencia();
	
	DT_DataInfoEstudiante* dataInfo = new DT_DataInfoEstudiante(paisRes, fechaNac);
	
	return dataInfo;
}


DT_DataUsuarioGenerico* Estudiante::getDataUsuarioGenerico() {
	std::string nickname = this->getNickname();
	std::string descripcionUsuario = this->getDescripcionUsuario();
	DT_DataInfoEstudiante* dataInfoEst = this->getDataInfoEstudiante();
	
	DT_DataUsuarioGenerico* dataUsr = new DT_DataUsuarioGenerico(nickname, descripcionUsuario, dataInfoEst, nullptr);
	
	return dataUsr;
}

bool Estudiante::aproboCurso(std::string nombreCurso) {
	IKey* ik = new String(nombreCurso.c_str());
	bool yaEstaInscripto = this->estaInscriptoACurso(nombreCurso);
	bool aprobo = false;
	
	if(yaEstaInscripto) {
		Inscripcion* insc = (Inscripcion*)this->inscripciones->find(ik);
		aprobo = insc->aprobado();
	}
	delete ik;
	
	return aprobo;
}

bool Estudiante::estaInscriptoACurso(std::string nombreCurso) {
	IKey* ik = new String(nombreCurso.c_str());
	bool estaInscripto = this->inscripciones->member(ik);
	delete ik;
	return estaInscripto;
}
