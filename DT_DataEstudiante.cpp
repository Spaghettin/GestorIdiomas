#include "DT_DataEstudiante.h"

DT_DataEstudiante::DT_DataEstudiante() {
	
}

DT_DataEstudiante::DT_DataEstudiante(string nombre,
									string descripcion,
									string nickname,
									string paisResidencia,
									date* fechaNacimiento){
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->nickname = nickname;
	this->paisResidencia = paisResidencia;
	this->fechaNacimiento = fechaNacimiento;
}

DT_DataEstudiante::DT_DataEstudiante(const DT_DataEstudiante &arg) {
	
}

DT_DataEstudiante::~DT_DataEstudiante() {
	
}

