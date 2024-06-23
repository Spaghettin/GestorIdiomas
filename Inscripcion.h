#ifndef INSCRIPCION_H_
#define INSCRIPCION_H_

#include "date.h"
#include "Curso.h"
#include "Usuario.h"
#include "Estudiante.h"
#include "DeCompletar.h"
#include "DeTraduccion.h"

class Curso;
class Estudiante;

class Inscripcion : public ICollectible {
private:
	date* fechaInsc;
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
	float getProgresoCurso();
	float getProgresoLeccion();
	void setProgresoCurso(float n);
	void setProgresoLeccion(float n);
	std::string getNicknameEstudiante();
	std::string getNombreCurso();
	int getIdLeccionActual();
	bool aprobado();
	std::set<int> listarEjerciciosPendientes();
	bool resolverEjercicioDeTraduccion(std::string solucion, int idEjercicio);
	bool resolverEjercicioDeCompletar(std::vector<std::string> solucion, int idEjercicio);
	DT_DataProblemaEjercicio* getDataProblemaEjercicio(int idEjercicio);
};

#endif /* INSCRIPCION_H_ */
