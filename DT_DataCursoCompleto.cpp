#include "DT_DataCursoCompleto.h"

DT_DataCursoCompleto::DT_DataCursoCompleto(
	   DT_DataCurso* dataC,
	   std::string nombreIdioma,
	   std::string nombreUsuario,
	   std::set<DT_DataLeccionConEjercicio*> leccionesDeCurso,
	   std::set<DT_DataEstudianteCurso*> estudiantesDeCurso
   ) {
	this->dataCurso = dataC;
	this->nombreIdioma = nombreIdioma;
	this->nombreUsuario = nombreUsuario;
	this->leccionesDeCurso = leccionesDeCurso;
	this->estudiantesDeCurso = estudiantesDeCurso;
}

DT_DataCursoCompleto::~DT_DataCursoCompleto() {
	
}

DT_DataCurso* DT_DataCursoCompleto::getDataCurso() {
	return this->dataCurso;
}

std::string DT_DataCursoCompleto::getNombreIdioma() {
	return this->nombreIdioma;
}

std::string DT_DataCursoCompleto::getNombreUsuario() {
	return this->nombreUsuario;
}

std::set<DT_DataLeccionConEjercicio*> DT_DataCursoCompleto::getLeccionesDeCurso() {
	return this->leccionesDeCurso;
}
std::set<DT_DataEstudianteCurso*> DT_DataCursoCompleto::getDataEstudiantes() {
	return this->estudiantesDeCurso;
}

std::ostream& operator<<(std::ostream& os, DT_DataCursoCompleto* dataCC) {
	os << "\nCurso: " << dataCC->getDataCurso()  
		<< "\nIdioma: " << dataCC->getNombreIdioma()
		<< "\nProfesor: " << dataCC->getNombreUsuario();
	
	std::set<DT_DataLeccionConEjercicio*> setDataLeccionConEjer = dataCC->getLeccionesDeCurso();
	
	if (!setDataLeccionConEjer.empty()) {
		os << "\n\nLecciones:";
		for (DT_DataLeccionConEjercicio* dataLec : setDataLeccionConEjer) {
			os << dataLec << "\n";
		}
	}
	
	std::set<DT_DataEstudianteCurso*> setDataEstudiantesCurso = dataCC->getDataEstudiantes();
	
	if(!setDataEstudiantesCurso.empty()) {
		os << "Estudiantes: \n";
		for (DT_DataEstudianteCurso* dataEst : setDataEstudiantesCurso) {
			os << dataEst << "\n";
		}
	}
	
	
	return os;
}
