#include "Ctrl.h"

Ctrl::Ctrl() {
	
}

Ctrl::Ctrl(const Ctrl &arg) {
	
}

Ctrl::~Ctrl() {
	
}

bool Ctrl::crearE(DT_DataEstudiante* datosEst){
	return true;
}

bool Ctrl::crearP(DT_DataProfesor DataProf){
	return true;
}

set<string> Ctrl::listarIdiomas(){
	
}

void Ctrl::seleccionaIdioma(string nombre){
	
}

set<string> Ctrl::listarUsuarios(){
	
}

DT_DataUsuarioGenerico Ctrl::consultaUsuario(string nickname){
	DT_DataUsuarioGenerico x;
	return x;
}

set<DT_DataCursoConContador> Ctrl::muestroCursosDisponibles(string nickncameEst){
	
}

void Ctrl::inscribirseACurso(){
	
}

set<string> Ctrl::listarCursosPendientes(string nicknameEst){
	
}

set<int> Ctrl::listarEjercicios(string nombreCurso){

}

DT_DataProblemaEjercicio Ctrl::getProblemaEjercicio(int idEjercicio){
	DT_DataProblemaEjercicio x;
	return x;
}

bool Ctrl::ingresarSolucion(string solucion){
	return true;
}

bool Ctrl::altaIdioma(string nombreIdioma){
	return true;
}

set<string> Ctrl::listarProfesores(){
	
}

void Ctrl::seleccionaProfesor(string nicknameProf){
	
}

void Ctrl::ingesoDatosCurso(DT_DataCurso datosC){
	
}

void Ctrl::seleccionaIdiomaDeCurso(string nombreIdioma){
	
}

set<string> Ctrl::listarCursosHabilitados(){
	
}

void Ctrl::ingresarCursoPrevio(string nombreCurso){
	
}

bool Ctrl::crearCurso(){
	return true;
}

set<string> Ctrl::listarCursosNoHabilitados(){
	
}

void Ctrl::seleccionaCurso(string nombreCurso){
	
}

int Ctrl::ingresarLeccion(string tema, string objetivo){
	return 0;
}

set<DT_DataLeccion> Ctrl::listarLecciones(string nombreCurso){
	
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

set<string> Ctrl::listarNombreCursos(){
	
}

void Ctrl::eliminarCurso(string nombreCurso){
	
}

set<DT_DataEstudiante> Ctrl::listarEstudiantes(){

}

set<DT_DataProgresoCurso> Ctrl::listarCursosDeEstudiante(string nicknameEst){

}

set<DT_DataProfesor> Ctrl::listarDataProfesores(){

}

set<DT_DataPromedioCurso> Ctrl::listarCursosDeProfesores(string nicknameProf){

}

set<DT_DataCurso> Ctrl::listarDataCursos(){
	
}

DT_DataPromedioCurso Ctrl::informacionCurso(string nombreCurso){
	DT_DataPromedioCurso x;
	return x;
}


