/*
 * Profesor.cpp
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#include "Profesor.h"

Profesor::Profesor(DT_DataRegistroUsuario* datosProf, std::string nombreInstituto) {
	this->nickname = datosProf->getNickname();
	this->nombreUsuario = datosProf->getNombre();
	this->contrasena = datosProf->getContrasena();
	this->descripcionUsuario = datosProf->getDescripcion();

	this->instituto = nombreInstituto;

	this->cursosDictados = new OrderedDictionary();
	this->idiomasEspecializacion = new OrderedDictionary();

	delete datosProf;
}

Profesor::~Profesor() {}

std::string Profesor::getInstituto() {
	return this->instituto;
}

IDictionary* Profesor::getCursosDictados(){
	return this->cursosDictados;
}


void Profesor::removerCursoDictado(std::string nombreCurso) {
	IKey* ik = new String(nombreCurso.c_str());
	this->cursosDictados->remove(ik);
	delete ik;
}

void Profesor::agregarCursoDictado(Curso* curso) {
	std::string nombreCurso = curso->getNombreCurso();
	IKey* ik = new String(nombreCurso.c_str());
	this->cursosDictados->add(ik, curso);
}

Idioma* Profesor::getIdiomaDictado(std::string nombreIdioma) {
	IKey* ik = new String(nombreIdioma.c_str());
	Idioma* idm = (Idioma*)this->idiomasEspecializacion->find(ik);
	delete ik;
	return idm;
}

std::set<DT_DataPromedioCurso*> Profesor::listarPromedioCursos() {
	
	std::set<DT_DataPromedioCurso*> dataPromedioCursosDictados = {};
	IIterator* it = this->cursosDictados->getIterator();
	Curso* curso;
	DT_DataPromedioCurso* dpc;
	
	while (it->hasCurrent()) {
		curso = (Curso*)it->getCurrent();
		dpc = curso->getDataPromedioCurso();
		dataPromedioCursosDictados.insert(dpc);
		it->next();
	}
	delete it;
	
	return dataPromedioCursosDictados;
}

DT_DataProfesor* Profesor::getDataProfesor() {
	DT_DataProfesor* dataProf = new DT_DataProfesor(this->getNombreUsuario(), this->getNickname());
	return dataProf;
}

DT_DataProfesorCompleto* Profesor::getDataProfesorCompleto() {
	std::string nombre = this->getNombreUsuario();
	std::string nickname = this->getNickname();
	std::string instituto = this->getInstituto();
	std::set<std::string> idiomas;

	IIterator* it = this->idiomasEspecializacion->getIterator();
	Idioma* idioma;
	while (it->hasCurrent()) {
		idioma = (Idioma*)it->getCurrent();
		idiomas.insert(idioma->getNombre());
		it->next();
	}
	delete it;

	DT_DataProfesorCompleto* dataProf = new DT_DataProfesorCompleto(nombre, nickname, instituto, idiomas);
	return dataProf;
}

std::set<std::string> Profesor::listarIdiomas(){
	std::set<std::string> setIdiomas;
	IIterator* it = this->idiomasEspecializacion->getIterator();
	Idioma* idioma;
	std::string nombreIdioma;

	while(it->hasCurrent()){
		idioma = (Idioma*)it->getCurrent();
		nombreIdioma = idioma->getNombre();
		setIdiomas.insert(nombreIdioma);
		it->next();
	}
	delete it;

	return setIdiomas;
}

bool Profesor::agregarIdiomaEspecializacion(Idioma* idioma) {

	std::string nombreIdioma = idioma->getNombre();
	IKey* ik = new String(nombreIdioma.c_str());

	bool yaExiste = this->idiomasEspecializacion->member(ik);
	if (yaExiste) {
		delete ik;
		return false;
	} else {
		this->idiomasEspecializacion->add(ik, idioma);
		return true;
	}
}

bool Profesor::dictaIdioma(std::string nombreIdioma) {
	IKey* ik = new String(nombreIdioma.c_str());
	bool dictaIdioma = this->idiomasEspecializacion->member(ik);
	delete ik;
	return dictaIdioma;
}

DT_DataInfoProfesor* Profesor::getDataInfoProfesor() {
	std::string inst = this->getInstituto();
	std::set<std::string> idiomasDictados = this->listarIdiomas();
	
	DT_DataInfoProfesor* dataInfo = new DT_DataInfoProfesor(inst, idiomasDictados);
	
	return dataInfo;
}

DT_DataUsuarioGenerico* Profesor::getDataUsuarioGenerico() {
	std::string nickname = this->getNickname();
	std::string descripcionUsuario = this->getDescripcionUsuario();
	DT_DataInfoProfesor* dataInfoProf = this->getDataInfoProfesor();
	
	DT_DataUsuarioGenerico* dataUsr = new DT_DataUsuarioGenerico(nickname, descripcionUsuario, nullptr, dataInfoProf);
	
	return dataUsr;
}
