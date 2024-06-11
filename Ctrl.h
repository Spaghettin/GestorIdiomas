#ifndef CTRL_H
#define CTRL_H
#include<iostream>

#include "I_Ctrl.h"

using namespace std;
class Ctrl  : public I_Ctrl{
public:
	Ctrl();
	Ctrl(const Ctrl &arg);
	~Ctrl();
	
	bool crearE(DT_DataEstudiante* DataEst);
	bool crearP(DT_DataProfesor DataProf);
	set<string> listarIdiomas();
	void seleccionaIdioma(string nombre);
	set<string> listarUsuarios();
	DT_DataUsuarioGenerico consultaUsuario(string nickname);
	set<DT_DataCursoConContador> muestroCursosDisponibles(string nickncameEst);
	void inscribirseACurso();
	set<string> listarCursosPendientes(string nicknameEst);
	set<int> listarEjercicios(string nombreCurso);
	DT_DataProblemaEjercicio getProblemaEjercicio(int idEjercicio);
	bool ingresarSolucion(string solucion);
	bool altaIdioma(string nombreIdioma);
	set<string> listarProfesores();
	void seleccionaProfesor(string nicknameProf);
	void ingesoDatosCurso(DT_DataCurso datosC);
	void seleccionaIdiomaDeCurso(string nombreIdioma);
	set<string> listarCursosHabilitados();
	void ingresarCursoPrevio(string nombreCurso);
	bool crearCurso();
	set<string> listarCursosNoHabilitados();
	void seleccionaCurso(string nombreCurso);
	int ingresarLeccion(string tema, string objetivo);
	set<DT_DataLeccion> listarLecciones(string nombreCurso);
	void seleccionaLecccion(int idLeccion);
	void ingresarTipoEjercicio(tipoEjercicio tipo, string descEjercicio);
	void ingresarEjercicioDeCompletar(string frase, set<string> solucion);
	void ingresarEjercicioDeTraduccion(string frase, string solucion);
	void habilitarCurso(string nombreCurso);
	set<string> listarNombreCursos();
	void eliminarCurso(string nombreCurso);
	set<DT_DataEstudiante> listarEstudiantes();
	set<DT_DataProgresoCurso> listarCursosDeEstudiante(string nicknameEst);
	set<DT_DataProfesor> listarDataProfesores();
	set<DT_DataPromedioCurso> listarCursosDeProfesores(string nicknameProf);
	set<DT_DataCurso> listarDataCursos();
	DT_DataPromedioCurso informacionCurso(string nombreCurso); 
	
private:
};

#endif

