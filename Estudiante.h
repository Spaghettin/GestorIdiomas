/*
 * Estudiante.h
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#ifndef HEADERS_ESTUDIANTE_H_
#define HEADERS_ESTUDIANTE_H_

#include "Usuario.h"
#include "Inscripcion.h"
#include "Curso.h"
#include "set"
#include "String.h"
#include "DT_Date.h"
#include "DT_DataEstudiante.h"
#include "DT_DataProgresoCurso.h"

class Curso;

class Estudiante : public Usuario {
private:
	std::string paisResidencia;
	DT_Date* fechaNacimiento;
	IDictionary* inscripciones;
public:
	Estudiante(DT_DataRegistroUsuario* datosEst, std::string paisRes, DT_Date* fechaNac);
	virtual ~Estudiante();
	std::string getPaisResidencia();
	DT_Date* getFechaNacimiento();
	bool aproboCurso(std::string nombreCurso);
	bool estaInscriptoACurso(std::string nombreCurso);
	void inscribirseACurso(Curso* crs);
	void removerInscripcion(std::string nombreCurso);
	std::set<std::string> listarCursosPendientes();
	std::set<int> listarEjerciciosPendientes(std::string nombreCurso);
	std::set<DT_DataProgresoCurso*> listarProgresoCursos();
	DT_DataEstudiante* getDataEstudiante();
	DT_DataProblemaEjercicio* getDataProblemaEjercicio(std::string nombreCurso, int idEjercicio);
	bool resolverEjercicioDeTraduccion(std::string nombreCurso, int idEjercicio, std::string solucion);
	bool resolverEjercicioDeCompletar(std::string nombreCurso, int idEjercicio, std::vector<std::string> solucion);
	DT_DataUsuarioGenerico* getDataUsuarioGenerico();
	DT_DataInfoEstudiante* getDataInfoEstudiante();
};

#endif /* HEADERS_ESTUDIANTE_H_ */
