#include "Ctrl.h"
#include "DT_DataEstudiante.h"

Ctrl::Ctrl() {
	
}

Ctrl::Ctrl(const Ctrl &arg) {
	
}

Ctrl::~Ctrl() {
	this->Idiomas = new OrderedDictionary();
	this->Usuarios = new OrderedDictionary();
	this->Estudiantes = new OrderedDictionary();
	this->Profesores = new OrderedDictionary();
	this->profe = new Profesor();
}

void Ctrl::printSet(const std::set<std::string>& mySet) {
	for (const auto& element : mySet) {
		std::cout << element << std::endl;
	}
}

void Ctrl::crearE(DT_DataEstudiante* datosEst){
	
	Estudiante* est = nullptr;
	est = new Estudiante(datosEst);							//Crea al estudiante con los datos recibidos por parametro
	IKey* ik = new String(est->getNickname().c_str());		//Crea la key con la clave nickname para poder agregar el est
	this->Estudiantes->add(ik,est);							//Se agrega el est al diccionario Estudiantes del controlador
	
	delete ik;
	delete est;
}

void Ctrl::crearP(DT_DataProfesor* DataProf, std::string nombreInstituto){
	
	Profesor* prof = nullptr;
	prof = new Profesor(DataProf, nombreInstituto);			//Crea al profesor con los datos recibidos por parametro
	IKey* ik = new String(prof->getNickname().c_str());		//Crea la key con la clave nickname para poder agregar el prof
	this->Profesores->add(ik,prof);							//Se agrega el profe al diccionario Profesores del controlador
	this->profe = prof;
	
	delete ik;
	delete prof;
}

set<std::string> Ctrl::listarIdiomas(){
	Idioma* idiomas = nullptr;
	std::set<std::string> setIdiomas;
	IIterator* it = this->Idiomas->getIterator();	//Se crea el iterador para el diccionario idiomas
	
	while(it->hasCurrent()){
		idiomas = (Idioma*)it->getCurrent();		//Se inicializa el puntero a obj "idiomas" al objeto que esta apuntando el it
		if(idiomas != nullptr){						//Si no es nulo hace
			setIdiomas.insert(idiomas->getNombre());//Inserta el nombre del diccionario Idiomas del controlador 
		}
		return setIdiomas;							//El set de string que sera retornado cuando no hayan mas datos en el diccionario Idiomas
	}
}

void Ctrl::seleccionarIdioma(std::string nombreIdioma){
	
	Idioma* idioma_ = nullptr;
	IKey* ik = new String(nombreIdioma.c_str());	//Se crea un key con el nombre del idioma como clave
	idioma_ = (Idioma*)this->Idiomas->find(ik);		//Se inicializa la variable idioma_, con el objeto Idioma que este asociado con la clave ik en el diccionario Idiomas del controlador
	bool exists = this->profe->getidiomas()->member(ik);	//Se crea la variable exists la cual se fija si el objeto idioma ya se encuentra en los Idiomas del profesor mediante la clave ik
	
	if(!exists && idioma_ != nullptr){				
		this->profe->seleccionarIdioma(idioma_);	//Si no existe en los Idiomas del profe y el idioma no es nulo, se selecciona el idioma, y consiguientemente se guarda en los Idiomas del profe
		this->profe->getidiomas()->add(ik,idioma_);	//this->profe es un puntero al profesor que se guardó en crearP
	}else{
		cout<<"Ese idioma ya esta ingresado";	
	}
	delete ik;
}

void Ctrl::altaIdioma(std::string nombreIdioma){
	
	Idioma* idioma_;
	IKey* ik = new String(nombreIdioma.c_str());	//Se crea un key con el nombre del idioma como clave
	bool exists = this->Idiomas->member(ik);		//Se crea la variable exists la cual se fija si el objeto idioma ya se encuentra en los Idiomas del controlador mediante la clave ik
	
	if(exists){
		cout<<"Ese idioma ya esta ingresado";
	}else{
		idioma_ = new Idioma(nombreIdioma);			//Si no existe en los Idiomas del controlador, se crea el idioma, y consiguientemente se guarda en los Idiomas del controlador
		this->Idiomas->add(ik,idioma_);
	}
	delete ik;
	delete idioma_;
}

set<std::string> Ctrl::listarUsuarios(){
	
}

DT_DataUsuarioGenerico* Ctrl::consultaUsuario(string nickname){
	
}

set<DT_DataCursoConContador*> Ctrl::muestroCursosDisponibles(string nickncameEst){
	
}

void Ctrl::inscribirseACurso(){
	
}

set<std::string> Ctrl::listarCursosPendientes(string nicknameEst){
	
}

set<int> Ctrl::listarEjercicios(string nombreCurso){

}

DT_DataProblemaEjercicio* Ctrl::getProblemaEjercicio(int idEjercicio){
	
}

bool Ctrl::ingresarSolucion(string solucion){
	return true;
}


set<std::string> Ctrl::listarProfesores(){
	
}

void Ctrl::seleccionaProfesor(string nicknameProf){
	
}

void Ctrl::ingesoDatosCurso(DT_DataCurso datosC){
	
}

void Ctrl::seleccionaIdiomaDeCurso(string nombreIdioma){
	
}

set<std::string> Ctrl::listarCursosHabilitados(){
	
}

void Ctrl::ingresarCursoPrevio(string nombreCurso){
	
}

bool Ctrl::crearCurso(){
	return true;
}

set<std::string> Ctrl::listarCursosNoHabilitados(){
	
}

void Ctrl::seleccionaCurso(string nombreCurso){
	
}

int Ctrl::ingresarLeccion(string tema, string objetivo){
	return 0;
}

set<DT_DataLeccion*> Ctrl::listarLecciones(string nombreCurso){
	
}

void Ctrl::seleccionaLecccion(int idLeccion){
	
}

void Ctrl::ingresarTipoEjercicio(tipoEjercicio tipo, string descEjercicio){
	
}

void Ctrl::ingresarEjercicioDeCompletar(string frase, set<string> solucion){
	
}

void Ctrl::ingresarEjercicioDeTraduccion(string frase, string solucion){
	
}

void Ctrl::habilitarCurso(string nombreCurso){
	
}

set<std::string> Ctrl::listarNombreCursos(){
	
}

void Ctrl::eliminarCurso(string nombreCurso){
	
}

set<DT_DataEstudiante*> Ctrl::listarEstudiantes(){

}

set<DT_DataProgresoCurso*> Ctrl::listarCursosDeEstudiante(string nicknameEst){

}

set<DT_DataProfesor*> Ctrl::listarDataProfesores(){

}

set<DT_DataPromedioCurso*> Ctrl::listarCursosDeProfesores(string nicknameProf){

}

set<DT_DataCurso*> Ctrl::listarDataCursos(){
	
}

DT_DataPromedioCurso* Ctrl::informacionCurso(string nombreCurso){
	
}


