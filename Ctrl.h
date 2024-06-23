#ifndef CTRL_H
#define CTRL_H
#include<iostream>

#include "I_Ctrl.h"
#include "Usuario.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "Curso.h"

using namespace std;
class Ctrl  : public I_Ctrl{
public:
	Ctrl();
	Ctrl(const Ctrl &arg);
	~Ctrl();
	
	void crearE(DT_DataEstudiante* DataEst);
	void crearP(DT_DataProfesor* DataProf, std::string nombreInstituto);
	set<std::string> listarIdiomas();
	void seleccionaIdioma(string nombre);
	set<std::string> listarUsuarios();
	DT_DataUsuarioGenerico* consultaUsuario(string nickname);
	set<DT_DataCursoConContador*> muestroCursosDisponibles(string nickncameEst);
	void inscribirseACurso();
	set<std::string> listarCursosPendientes(string nicknameEst);
	set<int> listarEjercicios(string nombreCurso);
	DT_DataProblemaEjercicio* getProblemaEjercicio(int idEjercicio);
	bool ingresarSolucion(string solucion);
	bool altaIdioma(string nombreIdioma);
	set<std::string> listarProfesores();
	void seleccionaProfesor(string nicknameProf);
	void ingesoDatosCurso(DT_DataCurso datosC);
	void seleccionaIdiomaDeCurso(string nombreIdioma);
	set<std::string> listarCursosHabilitados();
	void ingresarCursoPrevio(string nombreCurso);
	bool crearCurso();
	set<std::string> listarCursosNoHabilitados();
	void seleccionaCurso(string nombreCurso);
	int ingresarLeccion(string tema, string objetivo);
	set<DT_DataLeccion*> listarLecciones(string nombreCurso);
	void seleccionaLecccion(int idLeccion);
	void ingresarTipoEjercicio(tipoEjercicio tipo, string descEjercicio);
	void ingresarEjercicioDeCompletar(string frase, set<string> solucion);
	void ingresarEjercicioDeTraduccion(string frase, string solucion);
	void habilitarCurso(string nombreCurso);
	set<std::string> listarNombreCursos();
	void eliminarCurso(string nombreCurso);
	set<DT_DataEstudiante*> listarEstudiantes();
	set<DT_DataProgresoCurso*> listarCursosDeEstudiante(string nicknameEst);
	set<DT_DataProfesor*> listarDataProfesores();
	set<DT_DataPromedioCurso*> listarCursosDeProfesores(string nicknameProf);
	set<DT_DataCurso*> listarDataCursos();
	DT_DataPromedioCurso* informacionCurso(string nombreCurso); 
	
private:
	IDictionary* Usuarios;
	IDictionary* Profesores;
	IDictionary* Estudiantes;
	IDictionary* Idiomas;
	IDictionary* Cursos;
};

#endif

