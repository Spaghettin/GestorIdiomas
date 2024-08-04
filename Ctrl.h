/*
 * Ctrl.h
 *
 *  Created on: Jun 23, 2024
 *      Author: mat
 */


#ifndef CTRL_H_
#define CTRL_H_

#include "ICtrl.h"
#include "OrderedDictionary.h"

class Ctrl : public ICtrl {
	private:
		Ctrl();
		static Ctrl* instancia;
		//colecciones
		IDictionary* Profesores;
		IDictionary* Estudiantes;
		IDictionary* Idiomas;
		IDictionary* Cursos;
		IDictionary* Usuarios;
		//memoria del controlador
		tipoEjercicio mem_tipoEjercicio;
		std::string mem_descripcionEjercicio;
		int mem_idEjercicio;
		int mem_idLeccion;
		std::string mem_nombreCurso;
		Profesor* mem_profesor;
		DT_DataCurso* mem_dataCurso;
		Idioma* mem_idiomaCurso;
		std::set<std::string> mem_nombreCursosPrevios;
		std::set<Curso*> mem_cursosPrevios;
		Curso* mem_Curso;
		Estudiante* mem_estudiante;
	public:
		static Ctrl* getInstance();
		Ctrl(const Ctrl &arg);
		~Ctrl();
		//
		bool crearE(DT_DataRegistroUsuario* DataEst, std::string paisRes, DT_Date* fechaNac);
		bool crearP(DT_DataRegistroUsuario* DataProf, std::string nombreInstituto);
		bool altaIdioma(std::string nombreIdioma);
		std::set<std::string> listarIdiomas();
		std::set<std::string> listarIdiomasDeProfesor(std::string nicknameProf);
		bool agregarIdiomaAProfesor(std::string nombreIdioma);
		std::set<std::string> listarUsuarios();
		DT_DataUsuarioGenerico* consultaUsuario(std::string nickname);
		std::set<DT_DataCursoConContador*> muestroCursosDisponibles(std::string nicknameEst);
		bool inscribirseACurso(string nombreCurso);
		std::set<std::string> listarCursosPendientes(std::string nicknameEst);
		std::set<int> listarEjerciciosPendientes(std::string nombreCurso);
		DT_DataProblemaEjercicio* getProblemaEjercicio(int idEjercicio);
		bool ingresarSolucionDeTraduccion(std::string solucion);
		bool ingresarSolucionDeCompletar(std::vector<std::string> solucion);

		std::set<std::string> listarProfesores();
		std::set<std::string> listarNickEstudiantes();
		bool recordarProfesorDeCurso(std::string nicknameProf);
		bool seleccionaIdiomaDeCurso(std::string nombreIdioma);
		void recordarIdLeccion(int idLeccion);
		std::set<std::string> listarCursosHabilitados();
		bool ingresarCursoPrevio(std::string nombreCurso);
		bool crearCurso();
		bool existeCurso(std::string nombreCurso);
		bool existeEstudiante(std::string nickEstudiante);
		bool existeProfesor(std::string nickProfesor);
		std::set<std::string> listarCursosNoHabilitados();
		int crearLeccion(std::string tema, std::string objetivo);
		std::set<DT_DataLeccion*> listarLecciones(std::string nombreCurso);
		void ingresarTipoEjercicio(tipoEjercicio tipo, std::string descEjercicio);
		void ingresarEjercicioDeCompletar(std::string frase, std::vector<std::string> solucion);
		void ingresarEjercicioDeTraduccion(std::string frase, std::string solucion);
		bool habilitarCurso(std::string nombreCurso);
		std::set<std::string> listarNombreCursos();
		bool eliminarCurso(std::string nombreCurso);
		std::set<DT_DataEstudiante*> listarEstudiantes();
		std::set<DT_DataProgresoCurso*> listarCursosDeEstudiante(std::string nicknameEst);
		std::set<DT_DataProfesor*> listarDataProfesores();
		std::set<DT_DataPromedioCurso*> listarCursosDeProfesor(std::string nicknameProf);
		std::set<DT_DataCurso*> listarDataCursos();
		DT_DataCursoCompleto* getDataCursoCompleto(std::string nombreCurso);
		DT_DataPromedioCurso* informacionCurso(std::string nombreCurso);
		//setters memoria
		void setProfesorRecordado(Profesor* prof);
		void setDataCursoRecordado(DT_DataCurso* dataCurso);
		void setIdiomaCursoRecordado(Idioma* idioma);
		void setNuevoCursoPrevioRecordado(Curso* curso);
		void setNuevoNombreCursoPrevioRecordado(std::string nombreCurso);
		void setNombreCursoRecordado(std::string nombreCurso);
		void setIdLeccionRecordado(int id);
		void setTipoEjercicioRecordado(tipoEjercicio tipo);
		void setDescripcionEjercicioRecordado(std::string descripcionEj);
		void setCursoRecordado(Curso* curso);
		void setMemSetNombreCursosPrevio(std::set<std::string> setCtrlCPevios);
		void setMemEst(Estudiante* est);
		void setIdEjercicioRecordado(int id);
		//getters de colecciones
		IDictionary* getCursos();
		IDictionary* getUsuarios();
		IDictionary* getEstudiantes();
		IDictionary* getProfesores();
		IDictionary* getIdiomas();
		//getters de memoria
		int getIdEjercicioRecordado();
		int getIdLeccionRecordado();
		std::string getNombreCursoRecordado();
		Profesor* getMemProf();
		Idioma* getMemIdiomaCurso();
		std::set<std::string> getMemSetNombreCursosPrevio();
		std::set<Curso*> getMemSetCursosPrevios();
		DT_DataCurso* getMemDataCurso();
		tipoEjercicio getTipoEjercicioRecordado();
		std::string getDescripcionEjercicioRecordado();
		Curso* getCursoRecordado();
		Estudiante* getMemEstudiante();
		
		Estudiante* buscarEstudiante(std::string nicknameEst);
		Profesor* buscarProfesor(std::string nicknameProf);
		Idioma* buscarIdioma(std::string nombreIdioma);
		Curso* buscarCurso(std::string nombreCurso);
		void cargarDatos();
		
};


#endif /* CTRL_H_ */
