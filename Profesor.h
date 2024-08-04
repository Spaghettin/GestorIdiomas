/*
 * Profesor.h
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#ifndef SRC_PROFESOR_H_
#define SRC_PROFESOR_H_

#include "Usuario.h"
#include "Curso.h"
#include "set"
#include "DT_DataProfesor.h"
#include "DT_DataPromedioCurso.h"
#include "DT_DataProfesorCompleto.h"

class Curso;

class Profesor : public Usuario {
private:
	std::string instituto;
	IDictionary* idiomasEspecializacion;
	IDictionary* cursosDictados;
public:
	Profesor(DT_DataRegistroUsuario* datosProf, std::string nombreInstituto);
	virtual ~Profesor();
	std::string getInstituto();
	std::set<DT_DataPromedioCurso*> listarPromedioCursos();
	DT_DataProfesor* getDataProfesor();
	DT_DataProfesorCompleto* getDataProfesorCompleto();
	void agregarCursoDictado(Curso* curso);
	void removerCursoDictado(std::string nombreCurso);
	bool agregarIdiomaEspecializacion(Idioma* idioma);
	bool dictaIdioma(std::string nombreIdioma);
	std::set<std::string> listarIdiomas();
	Idioma* getIdiomaDictado(std::string nombreIdioma);
	IDictionary* getCursosDictados();
	DT_DataUsuarioGenerico* getDataUsuarioGenerico();
	DT_DataInfoProfesor* getDataInfoProfesor();

};

#endif /* SRC_PROFESOR_H_ */
