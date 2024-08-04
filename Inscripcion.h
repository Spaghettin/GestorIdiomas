/*
 * Inscripcion.h
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#ifndef INSCRIPCION_H_
#define INSCRIPCION_H_

#include "DT_Date.h"
#include "DT_DataProgresoCurso.h"
#include "Curso.h"
#include "Estudiante.h"
#include "DeCompletar.h"
#include "DeTraduccion.h"

class Curso;
class Estudiante;

class Inscripcion : public ICollectible {
private:
	DT_Date* fechaInsc;
	float progresoCurso;
	float progresoLeccion;
	Curso* curso;
	Estudiante* estudiante;
	Leccion* leccionActual;
	IDictionary* ejerciciosAprobados;
public:
	Inscripcion(Estudiante* est, Curso* crs);
	virtual ~Inscripcion();
	std::string getFechaInscToString();
	DT_Date* getFechaInsc();
	void setFechaInsc(DT_Date* Fecha);
	float getProgresoCurso();
	float getProgresoLeccion();
	void setProgresoCurso(float n);
	void setProgresoLeccion(float n);
	std::string getNicknameEstudiante();
	std::string getNombreEstudiante();
	std::string getNombreCurso();
	int getIdLeccionActual();
	void setLeccionActual(Leccion* lec);
	bool aprobado();
	std::set<int> listarEjerciciosPendientes();
	bool resolverEjercicioDeTraduccion(std::string solucion, int idEjercicio);
	bool resolverEjercicioDeCompletar(std::vector<std::string> solucion, int idEjercicio);
	DT_DataProblemaEjercicio* getDataProblemaEjercicio(int idEjercicio);
	DT_DataProgresoCurso* getDataProgresoCurso();
};

#endif /* INSCRIPCION_H_ */
