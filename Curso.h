#ifndef CURSO_H_
#define CURSO_H_

#include "Leccion.h"
#include "Idioma.h"
#include "Profesor.h"
#include "DT_DataCurso.h"
#include "DT_DataPromedioCurso.h"
#include "DT_DataCursoConContador.h"
#include "Integer.h"
#include "String.h"
#include "Inscripcion.h"

class Inscripcion;
class Curso {
private:
	std::string nombreCurso;
	std::string descripcionCurso;
	dificultad dificultadCurso;
	bool habilitado;
	int cantidadEjercicios;
	int cantidadLecciones;
	IDictionary* previas;
	IDictionary* lecciones;
	IDictionary* inscripciones;
	Profesor* profesor;
	Idioma* idiomaCurso;
public:
	Curso();
	Curso(DT_DataCurso* dataC, Profesor* prof, Idioma* idioma, std::set<Curso*> cprevios);
	virtual ~Curso();
	std::string getNombreCurso();
	std::string getDescripcionCurso();
	std::string getDificultadToString();
	bool estaHabilitado();
	int getCantidadEjercicios();
	int getCantidadLecciones();
	Leccion* getPrimerLeccion();
	void setCantidadEjercicios(int n);
	void setCantidadLecciones(int n);
	void habilitarCurso();
	int crearLeccion(std::string tema, std::string objetivo);
	std::set<DT_DataLeccion*> listarLecciones();
	void crearEjercicioDeTraduccion(
		int idLeccion,
		std::string descripcionEjercicio,
		std::string frase,
		std::string solucion);
	void crearEjercicioDeCompletar(
	   int idLeccion,
	   std::string descripcionEjercicio,
	   std::string frase,
	   std::vector<std::string> solucion);
	bool estaInscripto(std::string nicknameEst);
	std::set<std::string> getPrevias();
	DT_DataCurso* getDataCurso();
	DT_DataPromedioCurso* getDataPromedioCurso();
	void agregarInscripcion(Inscripcion* nuevaInsc);
	DT_DataCursoConContador* getDataCursoConContador();
	void eliminarContenido();
};

#endif /* CURSO_H_ */
