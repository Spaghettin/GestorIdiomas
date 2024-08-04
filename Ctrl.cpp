/*
 * Ctrl.cpp
 *
 *  Created on: Jun 23, 2024
 *      Author: mat
 */

#include "Ctrl.h"

Ctrl* Ctrl::instancia = nullptr;

Ctrl* Ctrl::getInstance() {
	if (Ctrl::instancia == nullptr) {
		Ctrl::instancia = new Ctrl();
	}
	return (Ctrl::instancia);
}

Ctrl::Ctrl() {
	//colecciones
	this->Cursos = new OrderedDictionary();
	this->Estudiantes = new OrderedDictionary();
	this->Idiomas = new OrderedDictionary();
	this->Profesores = new OrderedDictionary();
	this->Usuarios = new OrderedDictionary();

	//atributos de memoria
	this->mem_profesor = nullptr;
	this->mem_nombreCursosPrevios = {};
	this->mem_dataCurso = nullptr;
	this->mem_idiomaCurso = nullptr;
	this->mem_estudiante = nullptr;
	this->mem_Curso = nullptr;
}

Ctrl::~Ctrl() {
	IIterator* itCursos = this->getCursos()->getIterator();
	IIterator* itUsuario = this->Usuarios->getIterator();
	IIterator* itIdioma = this->Idiomas->getIterator();
	Curso* crs = nullptr;
	Usuario* usr = nullptr;
	Idioma* idm = nullptr;


	while (itCursos->hasCurrent()) {
		crs = (Curso*)itCursos->getCurrent();
		delete crs;
		itCursos->next();
	}
	delete itCursos;

	while (itUsuario->hasCurrent()) {
		usr = (Usuario*)itUsuario->getCurrent();
		delete usr;
		itUsuario->next();
	}
	delete itUsuario;

	while (itIdioma->hasCurrent()) {
		idm = (Idioma*)itIdioma->getCurrent();
		delete idm;
		itIdioma->next();
	}
	delete itIdioma;

	delete this->getUsuarios();
	delete this->getCursos();
	delete this->getIdiomas();
	delete this->getProfesores();
	delete this->getEstudiantes();
}

IDictionary* Ctrl::getCursos(){
	return this->Cursos;
}

IDictionary* Ctrl::getUsuarios(){
	return this->Usuarios;
}

IDictionary* Ctrl::getEstudiantes(){
	return this->Estudiantes;
}

IDictionary* Ctrl::getProfesores(){
	return this->Profesores;
}

IDictionary* Ctrl::getIdiomas(){
	return this->Idiomas;
}

Estudiante* Ctrl::getMemEstudiante() {
	return this->mem_estudiante;
}

DT_DataCurso* Ctrl::getMemDataCurso() {
	return this->mem_dataCurso;
}

Profesor* Ctrl::getMemProf(){
	return this->mem_profesor;
}

Idioma* Ctrl::getMemIdiomaCurso() {
	return this->mem_idiomaCurso;
}

std::set<Curso*> Ctrl::getMemSetCursosPrevios() {
	return this->mem_cursosPrevios;
}

std::set<std::string> Ctrl::getMemSetNombreCursosPrevio() {
	return this->mem_nombreCursosPrevios;
}

std::string Ctrl::getNombreCursoRecordado() {
	return this->mem_nombreCurso;
}

int Ctrl::getIdLeccionRecordado() {
	return this->mem_idLeccion;
}

int Ctrl::getIdEjercicioRecordado() {
	return this->mem_idEjercicio;
}

tipoEjercicio Ctrl::getTipoEjercicioRecordado() {
	return this->mem_tipoEjercicio;
}

std::string Ctrl::getDescripcionEjercicioRecordado() {
	return this->mem_descripcionEjercicio;
}

Curso* Ctrl::getCursoRecordado() {
	return this->mem_Curso;
}

void Ctrl::setMemSetNombreCursosPrevio(std::set<std::string> setCtrlCPevios) {
	this->mem_nombreCursosPrevios = setCtrlCPevios;
}

void Ctrl::setNombreCursoRecordado(std::string nombreCurso) {
	this->mem_nombreCurso = nombreCurso;
}

void Ctrl::setIdiomaCursoRecordado(Idioma* idioma) {
	this->mem_idiomaCurso = idioma;
}

void Ctrl::setProfesorRecordado(Profesor* prof) {
	this->mem_profesor = prof;
}

void Ctrl::setNuevoCursoPrevioRecordado(Curso* curso) {
	this->mem_cursosPrevios.insert(curso);
}

void Ctrl::setNuevoNombreCursoPrevioRecordado(std::string nombreCurso) {
	this->mem_nombreCursosPrevios.insert(nombreCurso);
}

void Ctrl::setDataCursoRecordado(DT_DataCurso* dataCurso){
	this->mem_dataCurso = dataCurso;
}

void Ctrl::setIdLeccionRecordado(int id) {
	this->mem_idLeccion = id;
}

void Ctrl::setTipoEjercicioRecordado(tipoEjercicio tipo) {
	this->mem_tipoEjercicio = tipo;
}

void Ctrl::setDescripcionEjercicioRecordado(std::string descripcionEj) {
	this->mem_descripcionEjercicio = descripcionEj;
}

void Ctrl::setCursoRecordado(Curso* curso) {
	this->mem_Curso = curso;
}

void Ctrl::setMemEst(Estudiante* est){
	this->mem_estudiante = est;
}

void Ctrl::setIdEjercicioRecordado(int id) {
	this->mem_idEjercicio = id;
}

bool Ctrl::crearE(DT_DataRegistroUsuario* datosEst, std::string paisRes, DT_Date* fechaNac){

	std::string nickEst = datosEst->getNickname();
	IKey* ik = new String(nickEst.c_str());

	bool yaExiste = this->Usuarios->member(ik);

	if (yaExiste) {
		delete ik;
		return false;
	} else {
		Estudiante* est = new Estudiante(datosEst, paisRes, fechaNac);
		this->getEstudiantes()->add(ik, est);
		this->getUsuarios()->add(ik, est);
		return true;
	}
}


bool Ctrl::crearP(DT_DataRegistroUsuario* dataProf, std::string nombreInstituto){

	std::string nickProf = dataProf->getNickname();
	IKey* ik = new String(nickProf.c_str());

	bool yaExiste = this->getUsuarios()->member(ik);

	if (yaExiste) {
		delete ik;
		return false;
	} else {
		Profesor* prof = new Profesor(dataProf, nombreInstituto);
		setProfesorRecordado(prof);
		this->getProfesores()->add(ik, prof);
		this->getUsuarios()->add(ik, prof);
		return true;
	}
}


bool Ctrl::altaIdioma(std::string nombreIdioma){
	Idioma* idioma;
	IKey* ik = new String(nombreIdioma.c_str());	//Se crea un key con el nombre del idioma como clave
	bool exists = this->getIdiomas()->member(ik);		//Se crea la variable exists la cual se fija si el objeto idioma ya se encuentra en los Idiomas del this mediante la clave ik
	
	if(exists){
		delete ik;
		return false;
	}else{
		idioma = new Idioma(nombreIdioma);			//Si no existe en los Idiomas del this, se crea el idioma, y consiguientemente se guarda en los Idiomas del this
		this->getIdiomas()->add(ik,idioma);
		return true;
	}
}


bool Ctrl::crearCurso(){
	Curso* nuevoCurso;
	Curso* cursoPrevio;
	Idioma* idioma;
	
	IKey* ikCurso = new String(this->getMemDataCurso()->getNombreCurso().c_str());
	bool yaExisteCurso = this->getCursos()->member(ikCurso);
	
	IKey* ikProfesor = new String(this->getMemProf()->getNickname().c_str());
	bool existeProfesor = this->getProfesores()->member(ikProfesor);
	Profesor* profDeCurso = (Profesor*)this->getProfesores()->find(ikProfesor);
	
	IKey* ikIdioma = new String(this->getMemIdiomaCurso()->getNombre().c_str());
	bool existeIdioma = this->Idiomas->member(ikIdioma);
	idioma = (Idioma*)this->Idiomas->find(ikIdioma);
	
	for (string nombreCurso : this->getMemSetNombreCursosPrevio()){
		IKey* ikCursoPrevio = new String(nombreCurso.c_str());
		bool existeCursoPrevio = this->getCursos()->member(ikCursoPrevio);
		
		if(existeCursoPrevio){
			cursoPrevio = (Curso*)this->getCursos()->find(ikCursoPrevio);
			this->setNuevoCursoPrevioRecordado(cursoPrevio);
		}
	}
	
	if(yaExisteCurso && !existeProfesor && !existeIdioma){
		delete ikCurso;
		delete ikProfesor;
		delete ikIdioma;
		return false;
	}else{
		nuevoCurso = new Curso(this->getMemDataCurso(), this->getMemProf(), idioma, this->getMemSetCursosPrevios());
		this->getCursos()->add(ikCurso, nuevoCurso);
		profDeCurso->agregarCursoDictado(nuevoCurso);
		return true;
	}
}

int Ctrl::crearLeccion(std::string tema, std::string objetivo){
	
	std::string nombreCursoRecordado = this->getNombreCursoRecordado();
	IKey* ik = new String(nombreCursoRecordado.c_str());
	Curso* curso = (Curso*)this->getCursos()->find(ik);
	int idLeccion = curso->crearLeccion(tema, objetivo);
	
	delete ik;
	return idLeccion;
}

bool Ctrl::agregarIdiomaAProfesor(std::string nombreIdioma){

	Idioma* idioma = nullptr;
	IKey* ik = new String(nombreIdioma.c_str());
	//verifico que el idioma exista
	bool exists = this->getIdiomas()->member(ik);

	if (!exists) {
		delete ik;
		return false;
	} else {
		//si existe el idioma en el sistema busco el puntero y le pido al profesor recordado que lo agregue
		idioma = (Idioma*)this->getIdiomas()->find(ik);
		delete ik;
		return (this->getMemProf()->agregarIdiomaEspecializacion(idioma));
	}
}

bool Ctrl::inscribirseACurso(string nombreCurso){
	Curso* cursos = nullptr;
	IKey* ik = new String(nombreCurso.c_str());
	cursos = (Curso*)this->getCursos()->find(ik);
	if(cursos == nullptr){
		return false;
	}
	else{
		this->mem_estudiante->inscribirseACurso(cursos);
		return true;
	}
}

bool Ctrl::ingresarSolucionDeTraduccion(std::string solucion) {
	Estudiante* est = this->getMemEstudiante();
	std::string curso = this->getNombreCursoRecordado();
	int idEjercicio = this->getIdEjercicioRecordado();
	
	bool esCorrecto = est->resolverEjercicioDeTraduccion(curso, idEjercicio, solucion);
	
	return esCorrecto;
}

bool Ctrl::ingresarSolucionDeCompletar(std::vector<std::string> solucion) {
	Estudiante* est = this->getMemEstudiante();
	std::string curso = this->getNombreCursoRecordado();
	int idEjercicio = this->getIdEjercicioRecordado();
	
	bool esCorrecto = est->resolverEjercicioDeCompletar(curso, idEjercicio, solucion);
	
	return esCorrecto;
}

bool Ctrl::ingresarCursoPrevio(std::string nombreCurso){
	
	Curso* curso;
	IKey* ik = new String(nombreCurso.c_str());
	curso = (Curso*)this->getCursos()->find(ik);
	if(curso){
		if(curso->estaHabilitado()){
			for(Curso* CursoPrevio : this->getMemSetCursosPrevios()){
				if(CursoPrevio->getNombreCurso() != nombreCurso){
					
				}else{
					return false;
				}
			}
			this->mem_cursosPrevios.insert(curso);
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}


void Ctrl::ingresarTipoEjercicio(tipoEjercicio tipo, std::string descEjercicio){
	this->setTipoEjercicioRecordado(tipo);
	this->setDescripcionEjercicioRecordado(descEjercicio);
}

void Ctrl::ingresarEjercicioDeCompletar(std::string frase, std::vector<std::string> solucion){
	IKey* ik = new String(this->getNombreCursoRecordado().c_str());
	Curso* cursoRecordado = (Curso*)this->getCursos()->find(ik);
	int idLeccionRecordada = this->getIdLeccionRecordado();
	std::string descEjerRecordada = this->getDescripcionEjercicioRecordado();
	delete ik;
	
	cursoRecordado->crearEjercicioDeCompletar(idLeccionRecordada, descEjerRecordada, frase, solucion);
}

void Ctrl::ingresarEjercicioDeTraduccion(string frase, string solucion){
	IKey* ik = new String(this->getNombreCursoRecordado().c_str());
	Curso* cursoRecordado = (Curso*)this->getCursos()->find(ik);
	int idLeccionRecordada = this->getIdLeccionRecordado();
	std::string descEjerRecordada = this->getDescripcionEjercicioRecordado();
	delete ik;
	
	cursoRecordado->crearEjercicioDeTraduccion(idLeccionRecordada, descEjerRecordada, frase, solucion);
}

bool Ctrl::seleccionaIdiomaDeCurso(string nombreIdioma){
	IKey* ik = new String(nombreIdioma.c_str());
	
	bool dictaIdioma = this->getMemProf()->dictaIdioma(nombreIdioma);
	
	if (dictaIdioma) {
		Idioma* idioma = this->getMemProf()->getIdiomaDictado(nombreIdioma);
		this->setIdiomaCursoRecordado(idioma);
		delete ik;
		return true;
	}
	else{
		delete ik;
		return false;
	}
}

bool Ctrl::existeCurso(std::string nombreCurso) {
	IKey* ik = new String(nombreCurso.c_str());
	bool existe = this->getCursos()->member(ik);
	delete ik;
	return existe;
}

bool Ctrl::existeEstudiante(std::string nickEstudiante) {
	IKey* ik = new String(nickEstudiante.c_str());
	bool existe = this->getEstudiantes()->member(ik);
	delete ik;
	return existe;
}

bool Ctrl::existeProfesor(std::string nickProfesor) {
	IKey* ik = new String(nickProfesor.c_str());
	bool existe = this->getProfesores()->member(ik);
	delete ik;
	return existe;
}

bool Ctrl::recordarProfesorDeCurso(std::string nicknameProf){
	IKey* ik = new String(nicknameProf.c_str());
	bool existe = this->getProfesores()->member(ik);

	if (existe) {
		Profesor* prof = (Profesor*)this->getProfesores()->find(ik);
		this->setProfesorRecordado(prof);
		delete ik;
		return true;
	} else {
		delete ik;
		return false;
	}
}

void Ctrl::recordarIdLeccion(int idLeccion){
	this->setIdLeccionRecordado(idLeccion);
}

bool Ctrl::habilitarCurso(string nombreCurso){
	Curso* curso = nullptr;
	IKey* ik = new String(nombreCurso.c_str());
	curso = (Curso*)this->getCursos()->find(ik);
	
	if( curso->habilitarCurso() ) {
		delete ik;
		return true;
	}
	else{
		delete ik;
		return false;
	}
}

bool Ctrl::eliminarCurso(string nombreCurso){
	//busco el curso y lo remuevo de la coleccion de cursos del ctrl
    Curso* cursoABorrar = nullptr;
    IKey* ik = new String(nombreCurso.c_str());
    bool existe = this->getCursos()->member(ik);

    if (!existe) {
    	return false;
    }

    cursoABorrar = (Curso*)this->getCursos()->find(ik);
    this->getCursos()->remove(ik);

    //remuevo el curso a borrar de los cursos previos de otros cursos
    IIterator* it = this->getCursos()->getIterator();
    Curso* curso = nullptr;
    while (it->hasCurrent()) {
    	curso = (Curso*)it->getCurrent();
    	//pregunto si el curso a borrar es previa del curso actual de la iteracion,
    	//le pido que lo remueva en caso afirmativo
    	if (curso->esPrevia(cursoABorrar)) {
    		curso->removerPrevia(cursoABorrar);
    	}
    	it->next();
    }

    delete ik;
    delete it;

    delete cursoABorrar;
    return true;
}

std::set<int> Ctrl::listarEjerciciosPendientes(std::string nombreCurso){
	this->setNombreCursoRecordado(nombreCurso);
	
	return this->mem_estudiante->listarEjerciciosPendientes(nombreCurso);
}

DT_DataUsuarioGenerico* Ctrl::consultaUsuario(std::string nickname){
	IKey* ik = new String(nickname.c_str());
	DT_DataUsuarioGenerico* dataUsr = nullptr;
	Usuario* usr = (Usuario*)this->getUsuarios()->find(ik);
	if (usr != nullptr) {
		dataUsr = usr->getDataUsuarioGenerico();
	}
	delete ik;
	
	return dataUsr;
	
}

DT_DataProblemaEjercicio* Ctrl::getProblemaEjercicio(int idEjercicio){
	Estudiante* est = this->getMemEstudiante();
	std::string curso = this->getNombreCursoRecordado();
	DT_DataProblemaEjercicio* problemaEjer =  est->getDataProblemaEjercicio(curso, idEjercicio);
	this->setIdEjercicioRecordado(idEjercicio);
	
	return problemaEjer;
}

std::set<DT_DataCursoConContador*> Ctrl::muestroCursosDisponibles(std::string nicknameEst) {
	std::set<DT_DataCursoConContador*> CursosAMostrar;
	Estudiante* BuscoEstudiante;
	IKey* ik = new String(nicknameEst.c_str());
	BuscoEstudiante = (Estudiante*)this->getEstudiantes()->find(ik);
	this->setMemEst(BuscoEstudiante);
	Curso* curso = nullptr;
	IIterator* it = this->getCursos()->getIterator();
	while (it->hasCurrent()) {
		curso = (Curso*)it->getCurrent();
		if (curso->estaHabilitado()) {
			if (!curso->estaInscripto(nicknameEst)) {
				std::set<std::string> RecorroPrevias = curso->getPrevias();
				bool apruebaTodasLasPrevias = true;
				for (const std::string& nombre : RecorroPrevias) {
					if (!BuscoEstudiante->aproboCurso(nombre)) {
						apruebaTodasLasPrevias = false;
						break; // Sale del bucle de previas si no aprueba una
					}
				}
				if (apruebaTodasLasPrevias) {
					CursosAMostrar.insert(curso->getDataCursoConContador());
				}
			}
		}
		it->next(); 
	}
	delete it;
	delete ik;
	return CursosAMostrar;
}

std::set<std::string> Ctrl::listarCursosHabilitados(){
	
	Curso* curso = nullptr;
	std::set<std::string> cursosHabilitados;
	IIterator* it = this->getCursos()->getIterator();
	
	while(it->hasCurrent()){
		curso = (Curso*)it->getCurrent();
		if(curso->estaHabilitado()){
			cursosHabilitados.insert(curso->getNombreCurso());
		}
		it->next();
	}
	delete it;
	
	return cursosHabilitados;
}

std::set<std::string> Ctrl::listarIdiomas(){
	Idioma* idioma = nullptr;
	std::set<std::string> setIdiomas;
	
	IIterator* it = this->getIdiomas()->getIterator();
	
	while(it->hasCurrent()){
		idioma = (Idioma*)it->getCurrent();
		setIdiomas.insert(idioma->getNombre());
		it->next();
	}
	delete it;
	
	return setIdiomas;
}

std::set<std::string> Ctrl::listarNombreCursos(){
	Curso* curso;
	std::set<std::string> listaDeNombreCurso;
	IIterator* it = this->getCursos()->getIterator();
	
	while(it->hasCurrent()){
		curso = (Curso*)it->getCurrent();
		listaDeNombreCurso.insert(curso->getNombreCurso());
		it->next();
	}
	delete it;
	
	return listaDeNombreCurso;
}

DT_DataCursoCompleto* Ctrl::getDataCursoCompleto(std::string nombreCurso) {
	IKey* ik = new String(nombreCurso.c_str());
	Curso* curso = (Curso*)this->getCursos()->find(ik);
	DT_DataCursoCompleto* dataCC = curso->getDataCursoCompleto();
	
	delete ik;
	
	return dataCC;
}

std::set<std::string> Ctrl::listarIdiomasDeProfesor(std::string nicknameProf) {
	std::set<std::string> idiomasDeProfesor;
	IKey* ik = new String(nicknameProf.c_str());
	Profesor* prof = (Profesor*)this->getProfesores()->find(ik);
	
	idiomasDeProfesor = prof->listarIdiomas();
	delete ik;
	return idiomasDeProfesor;
}

std::set<std::string> Ctrl::listarUsuarios(){
	Usuario* usr = nullptr;
	std::set<std::string> listaDeUsuarios;
	IIterator* it = this->getUsuarios()->getIterator();
	
	while(it->hasCurrent()){
		usr = (Usuario*)it->getCurrent();
		listaDeUsuarios.insert(usr->getNickname());
		it->next();
	}
	delete it;
	
	return listaDeUsuarios;
}

std::set<std::string> Ctrl::listarCursosPendientes(std::string nicknameEst){
	Estudiante* estudiante;
	IKey* IK_EST = new String(nicknameEst.c_str());
	estudiante = (Estudiante*)this->getEstudiantes()->find(IK_EST);
	delete IK_EST;
	this->setMemEst(estudiante);
	
	return (estudiante->listarCursosPendientes());
}

std::set<std::string> Ctrl::listarProfesores(){
	Profesor* prf = nullptr;
	std::set<std::string> listaProfesores = {};
	IIterator* it = this->getProfesores()->getIterator();
	
	while(it->hasCurrent()){
		prf = (Profesor*)it->getCurrent();
		listaProfesores.insert(prf->getNickname());
		it->next();
	}
	delete it;
	
	return listaProfesores;
}

std::set<std::string> Ctrl::listarCursosNoHabilitados(){
	Curso* curso = nullptr;
	std::set<std::string> cursosNoHabilitados = {};
	IIterator* it = this->getCursos()->getIterator();
	
	while(it->hasCurrent()){
		curso = (Curso*)it->getCurrent();
		if(!curso->estaHabilitado()){
			cursosNoHabilitados.insert(curso->getNombreCurso());
		}
		it->next();
	}
	delete it;
	
	return cursosNoHabilitados;
}

std::set<DT_DataLeccion*> Ctrl::listarLecciones(std::string nombreCurso){
	IKey* ik = new String(nombreCurso.c_str());
	Curso* curso = (Curso*)this->getCursos()->find(ik);
	//recuerdo el curso para las operaciones siguientes de agregar ejercicios
	this->setCursoRecordado(curso);
	
	std::set<DT_DataLeccion*> dataLecciones = curso->listarLecciones();
	delete ik;
	
	return dataLecciones;
}

set<DT_DataEstudiante*> Ctrl::listarEstudiantes(){
	IIterator* it = this->Estudiantes->getIterator();
	Estudiante* est = nullptr;
	set<DT_DataEstudiante*> setDataEstudiantes = {};

	while(it->hasCurrent()) {
		est = (Estudiante*)it->getCurrent();
		setDataEstudiantes.insert(est->getDataEstudiante());
		it->next();
	}
	delete it;

	return setDataEstudiantes;
}

set<string> Ctrl::listarNickEstudiantes() {
	IIterator* it = this->Estudiantes->getIterator();
	Estudiante* est = nullptr;
	set<string> setNicknameEstudiantes = {};
	
	while (it->hasCurrent()) {
		est = (Estudiante*)it->getCurrent();
		setNicknameEstudiantes.insert(est->getNickname());
		it->next();
	}
	delete it;
	
	return setNicknameEstudiantes;
}

set<DT_DataProgresoCurso*> Ctrl::listarCursosDeEstudiante(string nicknameEst){
	IKey* ik = new String(nicknameEst.c_str());
	bool existe = this->Estudiantes->member(ik);
	set<DT_DataProgresoCurso*> setDPC = {};

	if (existe) {
		Estudiante* est = (Estudiante*)this->Estudiantes->find(ik);
		setDPC = est->listarProgresoCursos();
	}
	delete ik;

	return setDPC;
}

set<DT_DataProfesor*> Ctrl::listarDataProfesores(){
	IIterator* it = this->getProfesores()->getIterator();
	Profesor* prof = nullptr;
	DT_DataProfesor* dataProf = nullptr;
	std::set<DT_DataProfesor*> dataProfesores = {};

	while (it->hasCurrent()) {
		prof = (Profesor*)it->getCurrent();
		dataProf = prof->getDataProfesor();
		dataProfesores.insert(dataProf);
		it->next();
	}
	delete it;

	return dataProfesores;
}

set<DT_DataPromedioCurso*> Ctrl::listarCursosDeProfesor(string nicknameProf){
	Profesor* prof = nullptr;
	IKey* ik = new String(nicknameProf.c_str());
	prof = (Profesor*)this->getProfesores()->find(ik);
	set<DT_DataPromedioCurso*> setCursosProf = {}; 
	delete ik;
	
	if (prof) {
		setCursosProf = prof->listarPromedioCursos();
		return setCursosProf;
	}

	return setCursosProf;
}

set<DT_DataCurso*> Ctrl::listarDataCursos(){
	
	DT_DataCurso* dataCurso;
	Curso* crs = nullptr;
	IIterator* it = this->Cursos->getIterator();
	std::set<DT_DataCurso*> setDataCursos = {};
	
	while (it->hasCurrent()) {
		crs = (Curso*)it->getCurrent();
		dataCurso = crs->getDataCurso(); 
		setDataCursos.insert(dataCurso);  
		it->next();
	}
	delete it;
	
	return setDataCursos;
}

DT_DataPromedioCurso* Ctrl::informacionCurso(string nombreCurso){
	
	DT_DataPromedioCurso* dataPromCurso;
	Curso* crs = nullptr;
	IKey* ik = new String(nombreCurso.c_str());
	crs = (Curso*)this->Cursos->find(ik);
	
	dataPromCurso = crs->getInformacionCurso(crs);
	delete ik;
	
	return dataPromCurso;
}

Estudiante* Ctrl::buscarEstudiante(std::string nicknameEst) {
	IKey* ik = new String(nicknameEst.c_str());
	Estudiante* est = (Estudiante*)this->getEstudiantes()->find(ik);
	delete ik;
	
	return est;
}

Profesor* Ctrl::buscarProfesor(std::string nicknameProf) {
	IKey* ik = new String(nicknameProf.c_str());
	Profesor* prof = (Profesor*)this->getProfesores()->find(ik);
	delete ik;
	
	return prof;
}

Idioma* Ctrl::buscarIdioma(std::string nombreIdioma) {
	IKey* ik = new String(nombreIdioma.c_str());
	Idioma* idm = (Idioma*)this->getIdiomas()->find(ik);
	delete ik;
	
	return idm;
}

Curso* Ctrl::buscarCurso(std::string nombreCurso) {
	IKey* ik = new String(nombreCurso.c_str());
	Curso* curso = (Curso*)this->getCursos()->find(ik);
	delete ik;
	
	return curso;
}

void Ctrl::cargarDatos(){
	
	//Crea Idiomas
	
	this->altaIdioma("Ingles");
	this->altaIdioma("Aleman");
	this->altaIdioma("Portugues");

//	// Crear instancias de usuarios y fechas de nacimiento
//	// ESTUDIANTES
	DT_DataRegistroUsuario* usuario1 = new DT_DataRegistroUsuario("jpidiom", "Juan Perez", "1234", "Soy un apasionado del aprendizaje de idiomas.");
	DT_Date* fecha1 = new DT_Date(1995, 7, 15);
	this->crearE(usuario1, "Argentina", fecha1);
	Estudiante* u1 = this->buscarEstudiante("jpidiom");
	
	DT_DataRegistroUsuario* usuario2 = new DT_DataRegistroUsuario("marsilva", "Maria Silva", "1234", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.");
	DT_Date* fecha2 = new DT_Date(1998, 2, 28);
	this->crearE(usuario2, "Ecuador", fecha2);
	Estudiante* u2 = this->buscarEstudiante("marsilva");
	
	DT_DataRegistroUsuario* usuario3 = new DT_DataRegistroUsuario("pero12", "Pedro Rodriguez", "1234", "Soy un entusiasta del aprendizaje de idiomas.");
	DT_Date* fecha3 = new DT_Date(1994, 11, 10);
	this->crearE(usuario3, "Peru", fecha3);
	Estudiante* u3 = this->buscarEstudiante("pero12");
	
	DT_DataRegistroUsuario* usuario4 = new DT_DataRegistroUsuario("laugu", "Laura Gutierrez", "1234", "Estoy fascinada por la forma en que las palabras pueden unir a las personas.");
	DT_Date* fecha4 = new DT_Date(1997, 4, 22);
	this->crearE(usuario4, "Chile", fecha4);
	Estudiante* u4 = this->buscarEstudiante("laugu");
	
	DT_DataRegistroUsuario* usuario5 = new DT_DataRegistroUsuario("carlo22", "Carlos Lopez", "1234", "Emocionado por adquirir fluidez en diferentes lenguas.");
	DT_Date* fecha5 = new DT_Date(1996, 9, 3);
	this->crearE(usuario5, "Uruguay", fecha5);
	Estudiante* u5 = this->buscarEstudiante("carlo22");
	
	DT_DataRegistroUsuario* usuario6 = new DT_DataRegistroUsuario("anator", "Ana Torres", "1234", "Disfruto de la belleza de las diferentes estructuras y sonidos.");
	DT_Date* fecha6 = new DT_Date(1999, 1, 12);
	this->crearE(usuario6, "Argentina", fecha6);
	Estudiante* u6 = this->buscarEstudiante("anator");
	
	DT_DataRegistroUsuario* usuario7 = new DT_DataRegistroUsuario("luher24", "Lucia Hernandez", "1234", "Emocionada en la riqueza cultural que cada idioma ofrece.");
	DT_Date* fecha7 = new DT_Date(1993, 6, 25);
	this->crearE(usuario7, "Colombia", fecha7);
	Estudiante* u7 = this->buscarEstudiante("luher24");
	
	DT_DataRegistroUsuario* usuario8 = new DT_DataRegistroUsuario("dagon", "David Gonzalez", "1234", "Aprender nuevas lenguas y sumergirme en diferentes culturas.");
	DT_Date* fecha8 = new DT_Date(1997, 12, 8);
	this->crearE(usuario8, "Uruguay", fecha8);
	Estudiante* u8 = this->buscarEstudiante("dagon");
	
	DT_DataRegistroUsuario* usuario9 = new DT_DataRegistroUsuario("carmor", "Carmen Morales", "1234", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.");
	DT_Date* fecha9 = new DT_Date(1995, 3, 17);
	this->crearE(usuario9, "Chile", fecha9);
	Estudiante* u9 = this->buscarEstudiante("carmor");
	
	DT_DataRegistroUsuario* usuario10 = new DT_DataRegistroUsuario("jose24", "Jose Fernandez", "1234", "Disfruto del proceso de descubrir nuevas formas de comunicarme.");
	DT_Date* fecha10 = new DT_Date(1998, 8, 2);
	this->crearE(usuario10, "Bolivia", fecha10);
	Estudiante* u10 = this->buscarEstudiante("jose24");
	
//		IDIOMAS
	Idioma* i1 = this->buscarIdioma("Ingles");
	Idioma* i2 = this->buscarIdioma("Aleman");
	Idioma* i3 = this->buscarIdioma("Portugues");

//	// PROFESORES
	DT_DataRegistroUsuario* usuario11 = new DT_DataRegistroUsuario("langMaster", "Marta Grecia", "1234", "Soy una profesora apasionada por los idiomas.");
	this->crearP(usuario11, "Instituto de Idiomas Moderno");
	Profesor* profe1 = this->buscarProfesor("langMaster");
	profe1->agregarIdiomaEspecializacion(i1);
	profe1->agregarIdiomaEspecializacion(i3);
//	
	DT_DataRegistroUsuario* usuario12 = new DT_DataRegistroUsuario("linguaPro", "Carlos Petro", "1234", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas.");
	this->crearP(usuario12, "Centro Global");
	Profesor* profe2 = this->buscarProfesor("linguaPro");
	profe2->agregarIdiomaEspecializacion(i1);
	profe2->agregarIdiomaEspecializacion(i2);
	profe2->agregarIdiomaEspecializacion(i3);
	
	DT_DataRegistroUsuario* usuario13 = new DT_DataRegistroUsuario("talkExpert", "Laura Perez", "1234", "Soy una profesora entusiasta del aprendizaje de idiomas.");
	this->crearP(usuario13, "Instituto de Idiomas Vanguardia");
	Profesor* profe3 = this->buscarProfesor("talkExpert");
	profe3->agregarIdiomaEspecializacion(i2);
	
	DT_DataRegistroUsuario* usuario14 = new DT_DataRegistroUsuario("lingoSensei", "Franco Lopez", "1234", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos.");
	this->crearP(usuario14, "Centro de Idiomas");
	Profesor* profe4 = this->buscarProfesor("lingoSensei");
	profe4->agregarIdiomaEspecializacion(i3);
	
	DT_DataRegistroUsuario* usuario15 = new DT_DataRegistroUsuario("wordMaestro", "Ana Morales", "1234", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas.");
	this->crearP(usuario15, "Instituto de Idiomas Progreso");
	Profesor* profe5 = this->buscarProfesor("wordMaestro");
	profe5->agregarIdiomaEspecializacion(i1);
	
	//CURSOS
	DT_DataCurso* cursoC1 = new DT_DataCurso("Ingles para principiantes",
											 "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.",
											 "Principiante");
	this->setDataCursoRecordado(cursoC1);
	this->setProfesorRecordado(profe1);
	this->setIdiomaCursoRecordado(i1);
	this->getMemSetCursosPrevios() = {};
	this->setNombreCursoRecordado(cursoC1->getNombreCurso());
	this->crearCurso();
	Curso* c1 = this->buscarCurso("Ingles para principiantes");
	int idLec1 = this->crearLeccion("Saludos y Presentaciones","Aprender a saludar y despedirse");
	int idLec2 = this->crearLeccion("Artículos y Plurales","Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
	vector <string> vec1 = {"allow", "myself"};
	vector <string> vec2 = {"some"};
	int idEj1 = c1->crearEjercicioDeTraduccion(idLec1, "Presentaciones", "Mucho gusto en conocerte", "Nice to meet you");
	int idEj2 = c1->crearEjercicioDeCompletar(idLec1, "Presentaciones formales", "Please --- me to introduce ---", vec1);
	int idEj3 = c1->crearEjercicioDeTraduccion(idLec2, "Plurales regulares", "I have two brothers and three sisters", "Tengo dos hermanos y tres hermanas");
	int idEj4 = c1->crearEjercicioDeCompletar(idLec2, "Sustantivos contables en plural", "Can I have --- water, please?", vec2);
	this->habilitarCurso(c1->getNombreCurso());
	
	//INSCRIPCIONES C1
	DT_Date* fechaN1 = new DT_Date(1, 1, 2022);	
	u1->inscribirseACurso(c1);
	Inscripcion* ins1 = c1->getMemIns();
	ins1->setFechaInsc(fechaN1);
	c1->setLeccionActual(idLec1);
	ins1->resolverEjercicioDeTraduccion("Nice to meet you", idEj1);
	ins1->resolverEjercicioDeCompletar(vec1, idEj2);
	c1->setLeccionActual(idLec2);
	ins1->resolverEjercicioDeTraduccion("Tengo dos hermanos y tres hermanas",idEj3);
	ins1->resolverEjercicioDeCompletar(vec2, idEj4);
	
	DT_Date* fechaN2 = new DT_Date(2, 1, 2022);
	u2->inscribirseACurso(c1);
	Inscripcion* ins4 = c1->getMemIns();
	ins4->setFechaInsc(fechaN2);
	c1->setLeccionActual(idLec1);
	ins4->resolverEjercicioDeTraduccion("Nice to meet you", idEj1);
	ins4->resolverEjercicioDeCompletar(vec1, idEj2);
	
	DT_Date* fechaN3 = new DT_Date(2, 1, 2022);
	u3->inscribirseACurso(c1);
	Inscripcion* ins5 = c1->getMemIns();
	ins5->setFechaInsc(fechaN3);
	ins5->resolverEjercicioDeTraduccion("Nice to meet you", idEj1);
	ins5->resolverEjercicioDeCompletar(vec1, idEj2);
	c1->setLeccionActual(idLec2);
	ins5->resolverEjercicioDeCompletar(vec2, idEj4);
	
	DT_Date* fechaN4 = new DT_Date(2, 3, 2023);
	u4->inscribirseACurso(c1);
	Inscripcion* ins6 = c1->getMemIns();
	ins6->setFechaInsc(fechaN4);
	
	
	DT_DataCurso* cursoC2 = new DT_DataCurso("Curso de ingles basico",
											 "Construye una base sólida en el idioma. Cubre gramática, vocabulario, comprensión auditiva y expresión oral.",
											 "Principiante");
	this->setDataCursoRecordado(cursoC2);
	this->setProfesorRecordado(profe1);
	this->setIdiomaCursoRecordado(i1);
	this->getMemSetCursosPrevios() = {};
	this->setNombreCursoRecordado(cursoC2->getNombreCurso());
	this->crearCurso();
	Curso* c2 = this->buscarCurso("Curso de ingles basico");
	int idLec3 = this->crearLeccion("Actividades Cotidianas","Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
	int idLec4 = this->crearLeccion("Artículos y Plurales","Aprender el uso del presente simple");
	vector <string> vec3 = {"up"};
	int idEj5 = c2->crearEjercicioDeCompletar(idLec3, "Actividades diarias", "Wake ---", vec3);
	
	
	DT_DataCurso* cursoC3 = new DT_DataCurso("Ingles intermedio: mejora tu nivel",
											 "Para estudiantes con conocimientos básicos de inglés que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.",
											 "Medio");
	this->setDataCursoRecordado(cursoC3);
	this->setProfesorRecordado(profe2);
	this->setIdiomaCursoRecordado(i1);
	this->getMemSetCursosPrevios() = {c1};
	this->setNombreCursoRecordado(cursoC3->getNombreCurso());
	this->crearCurso();
	Curso* c3 = this->buscarCurso("Ingles intermedio: mejora tu nivel");
	int idLec5 = this->crearLeccion("Conversaciones cotidianas","Aprender a hacer preguntas y respuestas en situaciones comunes");
	vector <string> vec4 = {"have", "past"};
	int idEj6 = c3->crearEjercicioDeCompletar(idLec5, "Consultas de la hora", "Q: Do you --- the time?, A: Yes, it is half --- 4", vec4);		
	this->habilitarCurso(c3->getNombreCurso());

	//INSCRIPCION C3
	DT_Date* fechaN5 = new DT_Date(12, 6, 2022);
	u1->inscribirseACurso(c3);
	Inscripcion* ins2 = c3->getMemIns();
	ins2->setFechaInsc(fechaN5);
	c3->setLeccionActual(idLec5);
	ins2->resolverEjercicioDeCompletar(vec4, idEj6);
	
	DT_DataCurso* cursoC4 = new DT_DataCurso("Curso avanzado de ingles",
											 "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramática avanzada, vocabulario y comprensión escrita y auditiva.",
											 "Avanzado");
	this->setDataCursoRecordado(cursoC4);
	this->setProfesorRecordado(profe2);
	this->setIdiomaCursoRecordado(i1);
	this->getMemSetCursosPrevios() = {c1,c3};
	this->setNombreCursoRecordado(cursoC4->getNombreCurso());
	this->crearCurso();
	Curso* c4 = this->buscarCurso("Curso avanzado de ingles");
	int idLec6 = this->crearLeccion("Uso de modales avanzados","Explorar el uso de los modales complejos");
	int idEj7 = c4->crearEjercicioDeTraduccion(idLec6, "Dar consejos o expresar obligacion", "You should visit that museum", "Deberias visitar ese museo");
	this->habilitarCurso(c4->getNombreCurso());
	
	//INSCRIPCIONES C4
	DT_Date* fechaN6 = new DT_Date(3, 1, 2023);
	u1->inscribirseACurso(c4);
	Inscripcion* ins3 = c4->getMemIns();
	ins3->setFechaInsc(fechaN6);
	
	DT_DataCurso* cursoC5 = new DT_DataCurso("Portugues intermedio",
											 "Curso para aquellos que tienen conocimientos básicos de portugués y desean mejorar su nivel. Incluye práctica de lectura, escritura y comprensión auditiva.",
											 "Medio");
	this->setDataCursoRecordado(cursoC5);
	this->setProfesorRecordado(profe2);
	this->setIdiomaCursoRecordado(i3);
	this->getMemSetCursosPrevios() = {};
	this->setNombreCursoRecordado(cursoC5->getNombreCurso());
	this->crearCurso();
	Curso* c5 = this->buscarCurso("Portugues intermedio");
	int idLec7 = this->crearLeccion("Lectura y comprension de textos","Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");
	int idEj8 = c5->crearEjercicioDeTraduccion(idLec7, "Imperativo", "Fale comigo", "Habla conmigo");
	this->habilitarCurso(c5->getNombreCurso());
	
	//INSCRIPCIONES C5
	DT_Date* fechaN7 = new DT_Date(3, 1, 2023);
	u4->inscribirseACurso(c5);
	Inscripcion* ins7 = c5->getMemIns();
	ins1->setFechaInsc(fechaN7);
	DT_Date* fechaN8 = new DT_Date(5, 1, 2023);
	u5->inscribirseACurso(c5);
	Inscripcion* ins8 = c5->getMemIns();
	ins1->setFechaInsc(fechaN8);
	
	DT_DataCurso* cursoC6 = new DT_DataCurso("Portugues avanzado",
											 "Curso avanzado para personas con un nivel intermedio-alto de portugués que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramática avanzada y la expresión oral.",
											 "Avanzado");
	this->setDataCursoRecordado(cursoC6);
	this->setProfesorRecordado(profe4);
	this->setIdiomaCursoRecordado(i3);
	this->getMemSetCursosPrevios() = {c5};
	this->crearCurso();	
}
