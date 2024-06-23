TARGET= lab4
OBJS= Ctrl.o ICtrl.o Fabrica.o date.o DeCompletar.o DeTraduccion.o Ejercicio.o Estudiante.o Idioma.o Inscripcion.o Leccion.o main.o Profesor.o Usuario.o\
	DT_DataCurso.o DT_DataCursoCompleto.o DT_DataCursoConContador.o DT_DataDeCompletar.o DT_DataDeTraduccion.o DT_DataEstudiante.o DT_DataEstudianteCurso.o\
	DT_DataInfoEstudiante.o DT_DataInfoProfesor.o DT_DataLeccion.o DT_DataLeccionConEjercicio.o DT_DataProblemaEjercicio.o DT_DataProfesor.o\
	DT_DataProfesorCompleto.o DT_DataProgresoCurso.o DT_DataPromedioCurso.o DT_DataRegistroUsuario.o DT_DataUsuarioGenerico.o
CFLAGS= -Wall  #OPCIONES DEL COMPILADOR

#Compilador
$(TARGET) : $(OBJS)               
	g++ $(CFLAGS) $(OBJS) -o $(TARGET)

%.o : %.cpp
	g++ -c $(CFLAGS) $< -o $@

.PHONY : clean
clean : 
	rm -f $(OBJS) $(TARGET)