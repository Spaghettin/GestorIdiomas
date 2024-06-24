#ifndef I_CTRL_H
#define I_CTRL_H
#include<iostream>
#include "date.h"
#include "set"
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
#include "enums.h"
using namespace std;


class I_Ctrl {
public:

	virtual void printSet(const std::set<std::string>& mySet) = 0;
	virtual void crearE(DT_DataEstudiante* DataEst) = 0;
	virtual void crearP(DT_DataProfesor* DataProf, std::string nombreInstituto) = 0;
	virtual set<std::string> listarIdiomas() = 0;
	virtual void seleccionarIdioma(string nombre) = 0;
	virtual set<std::string> listarUsuarios() = 0;
	virtual DT_DataUsuarioGenerico* consultaUsuario(string nickname) = 0;
	virtual set<DT_DataCursoConContador*> muestroCursosDisponibles(string nickncameEst) = 0;
	virtual void inscribirseACurso() = 0;
	virtual set<std::string> listarCursosPendientes(string nicknameEst) = 0;
	virtual set<int> listarEjercicios(string nombreCurso) = 0;
	virtual DT_DataProblemaEjercicio* getProblemaEjercicio(int idEjercicio) = 0;
	virtual bool ingresarSolucion(string solucion) = 0;
	virtual void altaIdioma(string nombreIdioma) = 0;
	virtual set<std::string> listarProfesores() = 0;
	virtual void seleccionaProfesor(string nicknameProf) = 0;
	virtual void ingesoDatosCurso(DT_DataCurso datosC) = 0;
	virtual void seleccionaIdiomaDeCurso(string nombreIdioma) = 0;
	virtual set<std::string> listarCursosHabilitados() = 0;
	virtual void ingresarCursoPrevio(string nombreCurso) = 0;
	virtual bool crearCurso() = 0;
	virtual set<std::string> listarCursosNoHabilitados() = 0;
	virtual void seleccionaCurso(string nombreCurso) = 0;
	virtual int ingresarLeccion(string tema, string objetivo) = 0;
	virtual set<DT_DataLeccion*> listarLecciones(string nombreCurso) = 0;
	virtual void seleccionaLecccion(int idLeccion) = 0;
	virtual void ingresarTipoEjercicio(tipoEjercicio tipo, string descEjercicio) = 0;
	virtual void ingresarEjercicioDeCompletar(string frase, set<string> solucion) = 0;
	virtual void ingresarEjercicioDeTraduccion(string frase, string solucion) = 0;
	virtual void habilitarCurso(string nombreCurso) = 0;
	virtual set<std::string> listarNombreCursos() = 0;
	virtual void eliminarCurso(string nombreCurso) = 0;
	virtual set<DT_DataEstudiante*> listarEstudiantes() = 0;
	virtual set<DT_DataProgresoCurso*> listarCursosDeEstudiante(string nicknameEst) = 0;
	virtual set<DT_DataProfesor*> listarDataProfesores() = 0;
	virtual set<DT_DataPromedioCurso*> listarCursosDeProfesores(string nicknameProf) = 0;
	virtual set<DT_DataCurso*> listarDataCursos() = 0;
	virtual DT_DataPromedioCurso* informacionCurso(string nombreCurso) = 0; 
private:
	
};

#endif

