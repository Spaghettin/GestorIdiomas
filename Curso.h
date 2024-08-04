/*
 * Curso.h
 *
 *  Created on: Jun 19, 2024
 *      Author: mat
 */

#ifndef CURSO_H_
#define CURSO_H_

#include "Leccion.h"
#include "Idioma.h"
#include "Profesor.h"
#include "Inscripcion.h"
#include "DT_DataCurso.h"
#include "DT_DataCursoConContador.h"
#include "DT_DataPromedioCurso.h"
#include "DT_DataCursoCompleto.h"
#include "Integer.h"
#include "String.h"

class Inscripcion;
class Profesor;

class Curso : public ICollectible {
private:
	std::string nombreCurso;
	std::string descripcionCurso;
	dificultad dificultadCurso;
	bool habilitado;
	int cantidadLecciones;
	int cantidadEjercicios;
	IDictionary* previas;
	IDictionary* lecciones;
	IDictionary* inscripciones;
	Profesor* profesor;
	Idioma* idiomaCurso;
	Inscripcion* mem_ins;
public:
	Curso(DT_DataCurso* dataC, Profesor* prof, Idioma* idioma, std::set<Curso*> cprevios);
	virtual ~Curso();
	std::string getNombreCurso();
	std::string getDescripcionCurso();
	std::string getDificultadToString();
	bool estaHabilitado();
	Inscripcion* getMemIns();
	int getCantidadEjercicios();
	int getCantidadLecciones();
	void setCantidadEjercicios(int n);
	void setCantidadLecciones(int n);
	void setMemIns(Inscripcion* inscr);
	bool habilitarCurso();
	int crearLeccion(std::string tema, std::string objetivo);
	std::set<DT_DataLeccion*> listarLecciones();
	int crearEjercicioDeTraduccion(
			int idLeccion,
			std::string descripcionEjercicio,
			std::string frase,
			std::string solucion);
	int crearEjercicioDeCompletar(
			int idLeccion,
			std::string descripcionEjercicio,
			std::string frase,
			std::vector<std::string> solucion);
	bool estaInscripto(std::string nicknameEst);
	std::set<std::string> getPrevias();
	bool esPrevia(Curso* crs);
	void removerPrevia(Curso* crs);
	Leccion* getPrimerLeccion();
	Leccion* getLeccionSiguiente(Leccion*);
	DT_DataCurso* getDataCurso();
	DT_DataPromedioCurso* getDataPromedioCurso();
	void agregarInscripcion(Inscripcion* nuevaInsc);
	DT_DataCursoConContador* getDataCursoConContador();
	DT_DataPromedioCurso* getInformacionCurso(Curso* curso);
	DT_DataCursoCompleto* getDataCursoCompleto();
	bool tieneLeccionesSinEjercicios();
	void setLeccionActual(int idLec);
};

#endif /* CURSO_H_ */
