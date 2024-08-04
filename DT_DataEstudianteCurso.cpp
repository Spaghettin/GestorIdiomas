#include "DT_DataEstudianteCurso.h"

DT_DataEstudianteCurso::DT_DataEstudianteCurso(std::string nombreEst, DT_Date* fechaIns) {
	this->fechaIns = fechaIns;
	this->nombreEstudiante = nombreEst;
}

DT_DataEstudianteCurso::~DT_DataEstudianteCurso() {
	
}

DT_Date* DT_DataEstudianteCurso::getFechaInscripcion() {
	return this->fechaIns;
}

std::string DT_DataEstudianteCurso::getFechaInscripcionToString() {
	std::string fecha = std::to_string(this->getFechaInscripcion()->getDia())
		+ "/" + std::to_string(this->getFechaInscripcion()->getMes()) 
		+ "/" + std::to_string(this->getFechaInscripcion()->getAno());
	
	return fecha;
}

std::string DT_DataEstudianteCurso::getNombreEstudiante() {
	return this->nombreEstudiante;
}

std::ostream& operator<<(std::ostream& os, DT_DataEstudianteCurso* dataEst) {
	
	os << "Estudiante: " << dataEst->getNombreEstudiante()
		<< "\nFecha de inscripcion a curso: " << dataEst->getFechaInscripcionToString();
	
	return os;
}
