/*
 * ICtrl.h
 *
 *  Created on: Jun 23, 2024
 *      Author: mat
 */

#ifndef ICTRL_H_
#define ICTRL_H_

#include "DT_Date.h"
#include "DT_DataEstudiante.h"
#include "DT_DataProfesor.h"
#include "DT_DataUsuarioGenerico.h"
#include "DT_DataCursoConContador.h"
#include "DT_DataProblemaEjercicio.h"
#include "DT_DataCurso.h"
#include "DT_DataLeccion.h"
#include "DT_DataEstudiante.h"
#include "DT_DataPromedioCurso.h"
#include "DT_DataProgresoCurso.h"
#include "DT_DataCursoConContador.h"
#include "DT_DataProblemaEjercicio.h"
#include "DT_DataRegistroUsuario.h"
#include "DT_DataCurso.h"
#include "enums.h"
#include "Usuario.h"
#include "Idioma.h"
#include "Curso.h"
#include "set"

class ICtrl {
	private:
	public:
		ICtrl();
		virtual ~ICtrl();
		virtual bool crearE(DT_DataRegistroUsuario* DataEst, std::string paisRes, DT_Date* fechaNac) = 0;
		virtual bool crearP(DT_DataRegistroUsuario* DataProf, std::string nombreInstituto) = 0;
		virtual bool crearCurso() = 0;
		virtual bool altaIdioma(std::string nombreIdioma) = 0;
		virtual int crearLeccion(std::string tema, std::string objetivo) = 0;

		virtual std::set<std::string> listarIdiomas() = 0;
		virtual std::set<std::string> listarIdiomasDeProfesor(std::string nicknameProf) = 0;
		virtual bool agregarIdiomaAProfesor(std::string nombreIdioma) = 0;
		virtual std::set<std::string> listarUsuarios() = 0;
		virtual std::set<std::string> listarNickEstudiantes() = 0;
		virtual DT_DataUsuarioGenerico* consultaUsuario(std::string nickname) = 0;
		virtual std::set<DT_DataCursoConContador*> muestroCursosDisponibles(std::string nicknameEst) = 0;
		virtual bool inscribirseACurso(string nombreCurso) = 0;
		virtual std::set<std::string> listarCursosPendientes(std::string nicknameEst) = 0;
		virtual std::set<int> listarEjerciciosPendientes(std::string nombreCurso) = 0;
		virtual DT_DataProblemaEjercicio* getProblemaEjercicio(int idEjercicio) = 0;
		virtual bool ingresarSolucionDeTraduccion(std::string solucion) = 0;
		virtual bool ingresarSolucionDeCompletar(std::vector<std::string> solucion) = 0;
		virtual std::set<std::string> listarProfesores() = 0;
		virtual bool recordarProfesorDeCurso(std::string nicknameProf) = 0;
		virtual bool existeCurso(std::string nombreCurso) = 0;
		virtual bool existeEstudiante(std::string nickEstudiante) = 0;
		virtual bool existeProfesor(std::string nickProfesor) = 0;
		virtual bool seleccionaIdiomaDeCurso(std::string nombreIdioma) = 0;
		virtual std::set<std::string> listarCursosHabilitados() = 0;
		virtual bool ingresarCursoPrevio(std::string nombreCurso) = 0;
		virtual std::set<std::string> listarCursosNoHabilitados() = 0;
		virtual std::set<DT_DataLeccion*> listarLecciones(std::string nombreCurso) = 0;
		virtual void recordarIdLeccion(int idLeccion) = 0;
		virtual void ingresarTipoEjercicio(tipoEjercicio tipo, std::string descEjercicio) = 0;
		virtual void ingresarEjercicioDeCompletar(std::string frase, std::vector<std::string> solucion) = 0;
		virtual void ingresarEjercicioDeTraduccion(std::string frase, std::string solucion) = 0;
		virtual bool habilitarCurso(std::string nombreCurso) = 0;
		virtual std::set<std::string> listarNombreCursos() = 0;
		virtual bool eliminarCurso(std::string nombreCurso) = 0;
		virtual std::set<DT_DataEstudiante*> listarEstudiantes() = 0;
		virtual std::set<DT_DataProgresoCurso*> listarCursosDeEstudiante(std::string nicknameEst) = 0;
		virtual std::set<DT_DataProfesor*> listarDataProfesores() = 0;
		virtual std::set<DT_DataPromedioCurso*> listarCursosDeProfesor(std::string nicknameProf) = 0;
		virtual std::set<DT_DataCurso*> listarDataCursos() = 0;
		virtual DT_DataCursoCompleto* getDataCursoCompleto(std::string nombreCurso) = 0;
		virtual DT_DataPromedioCurso* informacionCurso(std::string nombreCurso) = 0;
		//setters memoria
		virtual void setProfesorRecordado(Profesor* prof) = 0;
		virtual void setDataCursoRecordado(DT_DataCurso* dataCurso) = 0;
		virtual void setIdiomaCursoRecordado(Idioma* idioma) = 0;
		virtual void setNuevoCursoPrevioRecordado(Curso* curso) = 0;
		virtual void setNuevoNombreCursoPrevioRecordado(std::string nombreCurso) = 0;
		virtual void setNombreCursoRecordado(std::string nombreCurso) = 0;
		virtual void setIdLeccionRecordado(int id) = 0;
		virtual void setTipoEjercicioRecordado(tipoEjercicio tipo) = 0;
		virtual void setDescripcionEjercicioRecordado(std::string descripcionEj) = 0;
		virtual void setCursoRecordado(Curso* curso) = 0;
		virtual void setMemSetNombreCursosPrevio(set<string> setCtrlCPevios) = 0; 
		virtual void setMemEst(Estudiante* est) = 0;
		virtual void setIdEjercicioRecordado(int id) = 0;
		//getters de colecciones
		virtual IDictionary* getCursos() = 0;
		virtual IDictionary* getUsuarios() = 0;
		virtual IDictionary* getEstudiantes() = 0;
		virtual IDictionary* getProfesores() = 0;
		virtual IDictionary* getIdiomas() = 0;
		//getters de memoria
		virtual Profesor* getMemProf() = 0;
		virtual DT_DataCurso* getMemDataCurso() = 0;
		virtual Idioma* getMemIdiomaCurso() = 0;
		virtual std::set<Curso*> getMemSetCursosPrevios() = 0;
		virtual std::set<std::string> getMemSetNombreCursosPrevio() = 0;
		virtual std::string getNombreCursoRecordado() = 0;
		virtual int getIdLeccionRecordado() = 0;
		virtual int getIdEjercicioRecordado() = 0;
		virtual tipoEjercicio getTipoEjercicioRecordado() = 0;
		virtual std::string getDescripcionEjercicioRecordado() = 0;
		virtual Curso* getCursoRecordado() = 0;
		virtual Estudiante* getMemEstudiante() = 0;
		
		virtual Estudiante* buscarEstudiante(std::string nicknameEst) = 0;
		virtual Profesor* buscarProfesor(std::string nicknameProf) = 0;
		virtual Idioma* buscarIdioma(std::string nombreIdioma) = 0;
		virtual Curso* buscarCurso(std::string nombreCurso) = 0;
		virtual void cargarDatos() = 0;
		
};
#endif /* ICTRL_H_ */
