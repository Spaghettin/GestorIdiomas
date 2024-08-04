#include "iostream"
#include "limits"
#include "enums.h"
#include "Fabrica.h"
#include "ICtrl.h"
#include "IOHandler.h"

void insertoFecha(const string &mensaje, int &numero) {
	while (true) {
		cout << mensaje;
		cin >> numero;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Entrada invalida. Por favor, introduce un numero." << endl;
		}else{
			cin.ignore();
			break;
		}
	}
}

int main(int argc, char** argv) {
	
	//ultima modificacion 1/7 4:34 matias
	
	Fabrica* fabrica = new Fabrica();
	ICtrl* controlador = fabrica->getControlador();
	IOHandler* iohandler = new IOHandler();
	
	char out;
	
	while(out != '9'){
		cout<<"Bienvenido al sistema de Idiomas \n\n"
			<<"1. Ingresar Usuario \n"
			<<"2. Ingresar Curso \n"
			<<"3. Ingresar Idioma \n"
			<<"4. Modificar Curso \n" // Dentro van Habilitar, Eliminar, AgregarLeccion, AgregarEjercicio
			<<"5. Inscribirse a Curso \n"
			<<"6. Consultas \n"       // Dentro van ConsultaCurso, ConsultaUsuario, ConsultaEstadisticas
			<<"7. Realizar Ejercicios \n"
			<<"8. Precargar Datos \n"
			<<"9. Salir"<< endl;
		
		cout<<"\n\nIngrese una opcion del menu: ";
		out = iohandler->readChar(out);
		system("clear");
		switch(out){
			
		case '1': {//INGRESAR USUARIO
			
			string nombre, descripcion, nickname, paisResidencia, contrasena, nombreInstituto;
			bool ok;
			char res;
			do {
				cout<<"Ingrese 'p' para ingresar un profesor.\nIngrese 'e' para ingresar un estudiante.\n";
				res = iohandler->readChar(res);
			} while (res != 'p' && res != 'e');
			
			if (res == 'e') {//INGRESAR ESTUDIANTE
				DT_DataRegistroUsuario* datosUsr;
				int ano, mes, dia;
				DT_Date* fechaNacimiento;
				string paisResidencia;
				
				cout<<"Ingrese nickname del estudiante que se ingresa: ";
				nickname = iohandler->read(nickname);
				
				cout<<"Ingrese nombre del estudiante que se ingresa: ";
				nombre = iohandler->read(nombre);
				
				cout<<"Ingrese contrasena del estudiante que se ingresa: ";
				contrasena = iohandler->read(contrasena);
				
				cout<<"Ingrese descripcion del estudiante que se ingresa: ";
				descripcion = iohandler->read(descripcion);
				
				cout<<"Ingrese pais de residencia del estudiante que se ingresa: ";
				paisResidencia = iohandler->read(paisResidencia);
				
				insertoFecha("Ingrese ano de nacimiento del estudiante que se ingresa: ", ano);
				
				insertoFecha("Ingrese mes de nacimiento del estudiante que se ingresa: ", mes);
				
				insertoFecha("Ingrese dia de nacimiento del estudiante que se ingresa: ", dia);
				
				fechaNacimiento = new DT_Date(ano, mes, dia);
				datosUsr = new DT_DataRegistroUsuario(nickname, nombre, contrasena, descripcion);
				
				if (controlador->crearE(datosUsr, paisResidencia, fechaNacimiento)) {
					cout << "Usuario estudiante " << nickname << " creado exitosamente." << endl;
				} else {
					cout << "Ya existe un usuario con ese nickname." << endl;
				};
			} else {//INGRESAR PROFESOR
				string nombreProfesor;
				bool existeIdiomaIngresado;
				set<string> listaIdiomas = controlador->listarIdiomas();
				
				if (listaIdiomas.empty()) {
					cout << "El sistema no tiene idiomas registrados." << endl;
				}else{
					cout<<"Ingrese nickname del profesor que se ingresa: ";
					nickname = iohandler->read(nickname);
					
					cout<<"Ingrese nombre del profesor que se ingresa: ";
					nombreProfesor = iohandler->read(nombreProfesor);
					
					cout<<"Ingrese contrasena del profesor que se ingresa: ";
					contrasena = iohandler->read(contrasena);
					
					cout<<"Ingrese descripcion del profesor que se ingresa: ";
					descripcion = iohandler->read(descripcion);
					
					cout<<"Ingrese nombre del instituto en el que el profesor trabaja: ";
					nombreInstituto = iohandler->read(nombreInstituto);
					
					DT_DataRegistroUsuario* datosProf = new DT_DataRegistroUsuario(nickname, nombreProfesor, contrasena, descripcion);
					
					ok = controlador->crearP(datosProf, nombreInstituto);
					
					cout << "\nIdiomas registrados:\n";
					iohandler->printSet(listaIdiomas);
					cout << "\n";
					int idiomasIngresados = 0;
					
					do {
						cout<<"Ingrese nombre del idioma que se especializa: ";
						nombre = iohandler->read(nombre);
						
						existeIdiomaIngresado = (controlador->agregarIdiomaAProfesor(nombre));
						if (!existeIdiomaIngresado) {
							cout<<"Idioma ya seleccionado o no existe en el sistema.\nIngrese nuevamente: "<<endl;
						} else {
							idiomasIngresados++;
						}
						
						do {
							cout<<"Quiere seguir agregando idiomas? y/n: ";
							res = iohandler->readChar(res);
						} while (res != 'y' && res != 'n' );
						
					} while (res == 'y');
					cout << "Profesor " << nickname << " ingresado exitosamente." << endl;
				}
				
			}
			break;
		}
		case '2': {//ALTA CURSO
			
			set<string> nickProfesores = controlador->listarProfesores();
			
			if (nickProfesores.empty()) {
				cout << "No se puede dar de alta un curso si no hay profesores registrados.\n" << endl;
			} else {
				bool okc, okp, oki;
				char res;
				std::string nickname, nombreCurso, descCurso, dificultad, nombreIdioma;
				DT_DataCurso* dataCurso;
				
				cout<<"Profesores registrados:\n";
				iohandler->printSet(nickProfesores);
				cout<< "\n";
				
				do {
					cout<<"Ingrese nickname del profesor que se ingresa: ";
					nickname = iohandler->read(nickname);
					
					okp = controlador->recordarProfesorDeCurso(nickname);
					
					if (!okp) {
						cout<<"El profesor no existe en el sistema, intentelo nuevamente.\n";
					}
				} while (!okp);
				
				cout<<"Ingrese nombre del curso: ";
				nombreCurso = iohandler->read(nombreCurso);
				
				cout<<"Ingrese descripcion del curso: ";
				descCurso = iohandler->read(descCurso);
				
				do {
					cout<<"Ingrese dificultad del curso(Avanzado-Medio-Principiante): ";
					dificultad = iohandler->read(dificultad);
				} while (dificultad != "Principiante" && dificultad != "Medio" && dificultad != "Avanzado");
				
				dataCurso = new DT_DataCurso(nombreCurso, descCurso, dificultad);
				controlador->setDataCursoRecordado(dataCurso);
				
				cout<<"Lista de idiomas del profesor:\n";
				iohandler->printSet(controlador->listarIdiomasDeProfesor(controlador->getMemProf()->getNickname()));
				
				do{
					cout<<"Ingrese el nombre del idioma que sera agregado al curso: ";
					nombreIdioma = iohandler->read(nombreIdioma);
					
					oki = controlador->seleccionaIdiomaDeCurso(nombreIdioma);
					
					if(!oki){
						cout<<"El Idioma no es dictado por el profesor seleccionado, intentelo nuevamente.\n";
					}
				} while(!oki);
				
				cout<<"Quiere ingresar cursos previos? y/n: ";
				res = iohandler->readChar(res);
				cout<< "\n";
				
				//INGRESO DE CURSOS PREVIOS	
				if(res == 'y'){
					std::string nombreCursoPrevio;
					do{
						bool existeCursoPrevio = false;
						do {
							cout<< "\n";
							cout<<"Cursos habilitados:\n ";
							iohandler->printSet(controlador->listarCursosHabilitados());
							cout<< "\n";
							
							cout<<"Ingrese el nombre del curso que sera agregado como previatura: ";
							nombreCursoPrevio = iohandler->read(nombreCursoPrevio);
							
							existeCursoPrevio = controlador->existeCurso(nombreCursoPrevio);
							if (!existeCursoPrevio) {
								cout << "El curso ingresado no existe." << endl;
							}else{
								existeCursoPrevio = controlador->ingresarCursoPrevio(nombreCursoPrevio);
								if(!existeCursoPrevio){
									cout<<"Este idioma ya esta ingresado o no esta habilitado.";
								}
							}
						} while (!existeCursoPrevio);
						
						do{
							cout<<"Quiere agregar mas cursos? y/n: ";
							res = iohandler->readChar(res);
						} while(res != 'y' && res != 'n');
						
					}while(res == 'y');
				}
				//CREO CURSO
				okc = controlador->crearCurso();
				if (!okc){
					cout<<"Ooops, ya hay un curso creado con ese nombre de profesor, nombre de curso o hay un problema con el idioma, intentelo nuevamente."
						<<"\nVerifique que el curso no exista actualmente en el sistema y que profesor e idioma si existan en el sistema.";
				}else{
					cout << "Curso " << nombreCurso << " creado exitosamente." << endl;
				}
				
				//INGRESO DE LECCIONES
				do{
					cout<<"Quiere agregar lecciones? y/n: ";
					res = iohandler->readChar(res);
				} while(res != 'y' && res != 'n');
				
				if (res == 'y'){
					int idLeccion;
					std::string tema, objetivo, solucion;
					controlador->setNombreCursoRecordado(nombreCurso);
					do{
						cout<<"Ingrese tema de la leccion: ";
						tema = iohandler->read(tema);
						cout<<"Ingrese objetivo de la leccion: ";
						objetivo = iohandler->read(objetivo);
						idLeccion = controlador->crearLeccion(tema, objetivo);
						
						controlador->recordarIdLeccion(idLeccion);
						//INGRESO DE EJERCICIOS
						
						do{
							cout<<"Quiere agregar ejercicios? y/n: ";
							res = iohandler->readChar(res);
						} while(res != 'y' && res != 'n');
						
						if (res == 'y'){
							std::string tipo, descrEjercicio, frase;
							do{
								cout<<"Ingrese el tipo de ejercicio a ingresar (Traduccion / Completar): ";
								tipo = iohandler->read(tipo);
								
								tipoEjercicio tipoEj;
								if (tipo == "Traduccion") {
									tipoEj = Traduccion;
									
								} else if (tipo == "Completar") {
									tipoEj = Completar;
									
								} else {
									cout << "Tipo de ejercicio no v�lido." << endl;
									break;
								}
								
								cout<<"Ingrese la descripcion del ejercicio a ingresar: ";
								descrEjercicio = iohandler->read(descrEjercicio);
								controlador->ingresarTipoEjercicio(tipoEj, descrEjercicio);
								
								switch(tipoEj){
								case Traduccion : {
									
									cout<<"Ingrese la frase del problema del ejercicio: ";
									frase = iohandler->read(frase);
									
									cout<<"Ingrese solucion del ejercicio: ";
									solucion = iohandler->read(solucion);
									
									controlador->ingresarEjercicioDeTraduccion(frase,solucion);
									
								}
								case Completar : {
									string fraseProblema, palabra;
									vector<string> solucion = {};
									int cantPalabras = 0;
									bool fraseDeCompletarValida;
									
									do {
										cout<<"\nIngrese frase problema del ejercicio indicando con '---' los espacios a completar: ";
										
										solucion = {};
										cantPalabras = 0;
										
										fraseProblema = iohandler->read(fraseProblema);
										
										cout<<"Ingrese la solucion del ejercicio, palabra por palabra.";
										cout<<"\nIngrese 0 para dejar de ingresar palabras a la solucion.";
										do {
											cout << "\nPalabra " << cantPalabras << ": ";
											palabra = iohandler->read(frase);
											if (palabra != "0") {
												solucion.push_back(palabra);
												cantPalabras++;
											}
										} while (palabra != "0");
										
										fraseDeCompletarValida = iohandler->validarFraseDeCompletar(fraseProblema, cantPalabras);
										if (!fraseDeCompletarValida) {
											cout << "Formato incorrecto. Ingrese '---' en los lugares donde tenga que completar." 
												<< "\nDebe ingresar tantos espacios para completar como palabras para completar." << endl;
											cout << "Ingreso " << cantPalabras << " palabras y la frase '" << fraseProblema << "'" << endl;
											getchar();
										}
									} while (!fraseDeCompletarValida);
									
									controlador->ingresarEjercicioDeCompletar(fraseProblema, solucion);
								}
								break;
								default : cout<<"\nValor invalido (" << out << "), intentelo nuevamente\n";
								}								
								
								do{
									cout<<"Quiere seguir agregando ejercicios? y/n: ";
									res = iohandler->readChar(res);
								}while (res != 'y' && res != 'n');
								
							}while(res == 'y');
						}
						
						do{
							cout<<"Quiere seguir agregando lecciones? y/n: ";
							res = iohandler->readChar(res);
						}while (res != 'y' && res != 'n');
						
					}while(res == 'y');
				}
			}
		}
		break;
		case '3': {	//ALTA IDIOMA
			
			string nombreIdioma;
			bool oki;
			cout <<"aca"<<endl;
			cout<<"Ingrese nombre del idioma que se desea ingresar: ";
			nombreIdioma = iohandler->read(nombreIdioma);
			
			oki = controlador->altaIdioma(nombreIdioma);
			if (!oki){
				cout<<"Ooops, ya hay un idioma registrado con ese nombre."
					<<"\nVerifique que el idioma no exista actualmente en el sistema.\n";
			}else{
				cout << "Idioma " << nombreIdioma << " creado exitosamente." << endl;
			}
			
			break;
		}
		case '4': {	//MODIFICAR CURSO
			while(out != '5'){
				cout<<"\n1. Habilitar Curso \n"
					<<"2. Ingresar Leccion \n"
					<<"3. Ingresar Ejercicio \n"
					<<"4. Eliminar Curso \n"
					<<"5. Volver al menu principal"<<endl;
				
				cout<<"\n\nIngrese una opcion del menu: ";
				out = iohandler->readChar(out);
				system("clear");
				switch(out){
					
				case '1': {	//HABILITAR CURSO
					string nombreC;
					set<string> cursosNoHabilitados = controlador->listarCursosNoHabilitados();
					
					if (cursosNoHabilitados.empty()) {
						cout << "No hay cursos no habilitados." << endl;
					} else {
						cout<<"Cursos no habilitados:\n";
						iohandler->printSet(cursosNoHabilitados);
						cout<< "\n";
						
						bool nombreCValido = false;
						cout<<"Ingrese nombre del curso que se desea habilitar: ";
						do {
							nombreC = iohandler->read(nombreC);
							nombreCValido = (cursosNoHabilitados.count(nombreC) != 0);
							if (!nombreCValido) {
								cout << "El nombre ingresado no es valido. Ingrese nuevamente." << endl;
							}
						} while (!nombreCValido);
						
						bool fueHabilitado = controlador->habilitarCurso(nombreC);
						
						if (fueHabilitado) {
							cout << "Curso " << nombreC << " habilitado exitosamente." << endl;
						} else {
							cout << "No se pudo habilitar el curso ingresado. Verifique que no tiene lecciones sin ejercicios." << endl;
						}
					}
					
					break;
				}
				case '2': { //INGRESO LECCION
					char res;
					string nombreCurso, tema, objetivo;
					cout<<"Cursos no habilitados:\n	";
					set<string> cursosNoHabilitados = controlador->listarCursosNoHabilitados();
						
					if (cursosNoHabilitados.empty()) {
						cout << "No hay cursos no habilitados." << endl;
					} else {
						iohandler->printSet(cursosNoHabilitados);
						cout<<"Ingrese nombre del curso que se desea seleccionar: ";
						
						bool nombreCValido = false;
						do {
							nombreCurso = iohandler->read(nombreCurso);
							nombreCValido = ( cursosNoHabilitados.count(nombreCurso) != 0 );
							
							if (!nombreCValido) {
								cout << "\nEl curso ingresado no es valido. Ingrese nuevamente: ";
							}
						} while (!nombreCValido);
						
						controlador->setNombreCursoRecordado(nombreCurso);
						
						do{
							cout<<"Ingrese tema de la leccion: ";
							tema = iohandler->read(tema);
							cout<<"Ingrese objetivo de la leccion: ";
							objetivo = iohandler->read(objetivo);
							int idLec = controlador->crearLeccion(tema, objetivo);
							
							do{
								cout<<"Quiere seguir agregando lecciones? y/n: ";
								res = iohandler->readChar(res);
							}while (res != 'y' && res != 'n');
							
						}while(res == 'y');
					}
					break;
				}
				case '3': { // INGRESO EJERCICIO						
					int idLec;
					string idString;
					string frase, tema, descEj, nombreCurso, solucion;
					vector<string> setSolucion;
					
					cout<<"Cursos no habilitados:\n";
					set<string> cursosNoHabilitados = controlador->listarCursosNoHabilitados();
					
					if (cursosNoHabilitados.empty()) {
						cout << "No hay cursos no habilitados." << endl;
					} else {
						iohandler->printSet(cursosNoHabilitados);
						cout<<"Ingrese nombre del curso que se desea seleccionar: ";
						
						bool nombreCValido = false;
						do {
							nombreCurso = iohandler->read(nombreCurso);
							nombreCValido = ( cursosNoHabilitados.count(nombreCurso) != 0 );
							
							if (!nombreCValido) {
								cout << "\nEl curso ingresado no es valido. Ingrese nuevamente: ";
							}
						} while (!nombreCValido);
						
						controlador->setNombreCursoRecordado(nombreCurso);
					}
					
					set<int> setIdLecciones = {};
					set<DT_DataLeccion*> SetDataLec = controlador->listarLecciones(nombreCurso);
					
					if (SetDataLec.empty()) {
						cout << "El curso no tiene lecciones." << endl;
					} else {
						for (DT_DataLeccion* dataLec : SetDataLec) {
							cout << dataLec << endl;
							setIdLecciones.insert(dataLec->getIdLeccion());
							delete dataLec;
						}
						cout<< "\n";
						
						cout << "Ingrese el id de la leccion a la cual desea agregar ejercicios: ";
						bool idLecValida, idLecNoContieneChar, idLecEsDeLeccionesListadas; 
						do {
							idString = iohandler->read(idString);
							idLecNoContieneChar = iohandler->validarNumeroSinCaracteres(idString);
							if (idLecNoContieneChar) {
								idLec = atoi(idString.c_str());
								idLecEsDeLeccionesListadas = ( setIdLecciones.count(idLec) != 0 );
								idLecValida = idLecEsDeLeccionesListadas && idLecNoContieneChar;
							} else {
								cout << "\nId ingresado invalido. Ingrese nuevamente: ";
							}
						} while (!idLecValida);
						
						controlador->recordarIdLeccion(idLec);
						
						cout << "Ingresar tipo de ejercicio (Traduccion-Completar): ";
						string tipoEjStr;
						tipoEjercicio tipoEj;
						bool tipoEjValido = false;
						
						do {
							tipoEjStr = iohandler->read(tipoEjStr);
							if (tipoEjStr == "Traduccion") {
								tipoEj = Traduccion;
								tipoEjValido = true;
							} else if (tipoEjStr == "Completar") {
								tipoEj = Completar;
								tipoEjValido = true;
							} else {
								tipoEjValido = false;
								cout << "Tipo de ejercicio invalido. Ingrese nuevamente el tipo (Traduccion-Completar): " << endl;
							}
						} while (!tipoEjValido);
						
						
						cout<<"Ingrese la descripcion del ejercicio a ingresar: ";
						descEj = iohandler->read(descEj);
						controlador->ingresarTipoEjercicio(tipoEj, descEj);
						
						switch(tipoEj){
						case Traduccion : {
							
							cout<<"Ingrese la frase del problema del ejercicio: ";
							frase = iohandler->read(frase);
							
							cout<<"Ingrese solucion del ejercicio: ";
							solucion = iohandler->read(solucion);
							
							controlador->ingresarEjercicioDeTraduccion(frase,solucion);
						}
						break;
						case Completar : {
							string fraseProblema, palabra;
							vector<string> solucion = {};
							int cantPalabras = 0;
							bool fraseDeCompletarValida;
							
							do {
								cout<<"\nIngrese frase problema del ejercicio indicando con '---' los espacios a completar: ";
								
								solucion = {};
								cantPalabras = 0;
								
								fraseProblema = iohandler->read(fraseProblema);
								
								cout<<"Ingrese la solucion del ejercicio, palabra por palabra.";
								cout<<"\nIngrese 0 para dejar de ingresar palabras a la solucion.";
								do {
									cout << "\nPalabra " << cantPalabras << ": ";
									palabra = iohandler->read(frase);
									if (palabra != "0") {
										solucion.push_back(palabra);
										cantPalabras++;
									}
								} while (palabra != "0");
								
								fraseDeCompletarValida = iohandler->validarFraseDeCompletar(fraseProblema, cantPalabras);
								if (!fraseDeCompletarValida) {
									cout << "Formato incorrecto. Ingrese '---' en los lugares donde tenga que completar." 
										<< "\nDebe ingresar tantos espacios para completar como palabras para completar." << endl;
									cout << "Ingreso " << cantPalabras << " palabras y la frase '" << fraseProblema << "'" << endl;
									getchar();
								}
							} while (!fraseDeCompletarValida);
							
							controlador->ingresarEjercicioDeCompletar(fraseProblema, solucion);
						}
						break;
					}
					}
					break;
				}
				break;
				case '4': {	//ELIMINAR CURSO
					string nombreCurso;
					bool ok;
					
					cout<<"Lista de Cursos:\n";
					iohandler->printSet(controlador->listarNombreCursos());
					cout<< "\n";
					
					cout<<"Ingresar nombre del curso que se quiere eliminar: ";
					nombreCurso = iohandler->read(nombreCurso);
					
					ok = controlador->eliminarCurso(nombreCurso);
					if (!ok){
						cout<<"Ooops, parece que el curso de nombre "<<nombreCurso<< "no existe." << endl;
					}else{
						cout << "Curso " << nombreCurso << " eliminado exitosamente." << endl;
					}
					break;
				}
				default: cout<< "\nValor invalido (" << out << "), intentelo nuevamente\n";
				}
			}
			break;
		}
		case '5': {	//INSCRIBIRSE A CURSO
			std::string nicknameEst, nombreCurso;
			set<string> setNicknameEstudiantes = controlador->listarNickEstudiantes();
			
			if (setNicknameEstudiantes.empty()) {
				cout << "No hay estudiantes registrados" << endl;
			} else {
				
				for (string est : setNicknameEstudiantes) {
					cout << est << endl;
				}
				
				cout<<"Ingrese nickname del estudiante a inscribir: ";
				bool esValidoNickEst = false;
				
				do {
					nicknameEst = iohandler->read(nicknameEst);
					esValidoNickEst = ( setNicknameEstudiantes.find(nicknameEst) != setNicknameEstudiantes.end() );
					if (!esValidoNickEst) {
						cout << "El nickname ingresado no es valido. Ingrese nuevamente:";
					}
				} while (!esValidoNickEst);
				
				set<DT_DataCursoConContador*> setCursoDis = controlador->muestroCursosDisponibles(nicknameEst);
				set<string> nombreCursosDisponibles = {};
				for (DT_DataCursoConContador* dataP : setCursoDis) {
					cout << dataP << endl;
					nombreCursosDisponibles.insert(dataP->getNombreCurso());
					delete dataP;
				}
				
				if (setCursoDis.empty()) {
					cout << "Este usuario no tiene cursos disponibles para inscribirse." << endl;
				} else {
					cout<<"Ingrese nombre del Curso al que el estudiante desea inscribirse: ";
					bool esValidoNombreCurso = false;
					
					do {
						nombreCurso = iohandler->read(nombreCurso);
						esValidoNombreCurso = ( nombreCursosDisponibles.find(nombreCurso) != nombreCursosDisponibles.end() );
						if (!esValidoNombreCurso) {
							cout << "Nombre de curso invalido. Ingrese nuevamente:";
						}
					} while (!esValidoNombreCurso);
					
					controlador->inscribirseACurso(nombreCurso);
					break;
				}
			}
		}
		case '6': {	//CONSULTAS
			while(out != '5'){
				
				cout<<"\n1. Consulta de Cursos \n"
					<<"2. Consulta de Usuario \n"
					<<"3. Consulta de Idiomas \n"
					<<"4. Consulta Estadisticas \n"
					<<"5. Volver al menu principal"<<endl;
				
				cout<<"\n\nIngrese una opcion del menu: ";
				out = iohandler->readChar(out);
				system("clear");
				switch (out) {
					
				case '1': {	//CONSULTA CURSOS REGISTRADOS
					
					string nombreCurso;
					set<string> setNombreCursos = controlador->listarNombreCursos();
					DT_DataCursoCompleto* dataCursoCompleto;
					
					if (setNombreCursos.empty()) {
						cout << "No hay cursos registrados." << endl;
					} else {
						cout<<"\nCursos:\n";
						for (string  nomc : setNombreCursos) {
							cout << nomc << endl;
						}
						
						bool ingresoValido = false;
						cout<<"Ingrese nombre del curso a consultar: ";
						do {
							nombreCurso = iohandler->read(nombreCurso);
							ingresoValido = ( setNombreCursos.find(nombreCurso) != setNombreCursos.end() );
							
							if (!ingresoValido) {
								cout << "\nEl nombre de curso ingresado no es valido. Ingrese nuevamente: "; 
							}
							
						} while (!ingresoValido);
						
						dataCursoCompleto = controlador->getDataCursoCompleto(nombreCurso);
						cout << dataCursoCompleto << "\n";
						delete dataCursoCompleto;
					}
				}
				break;
				case '2': {	//CONSULTA USUARIOS REGISTRADOS
					
					set<string> nicknameUsuarios = controlador->listarUsuarios();
					
					if (nicknameUsuarios.empty()) {
						cout << "\nNo hay usuarios registrados." << endl;
					} else {
						cout << "\nNicknames de usuarios registrados: \n";
						for (string nick : nicknameUsuarios) {
							cout << nick << endl;
						}
						
						DT_DataUsuarioGenerico* dataUsuarioGenerico;
						string nickUsr;
						bool esValido = false;
						
						cout << "Ingrese el nickname del usuario que desea consultar: ";
						do {
							nickUsr = iohandler->read(nickUsr);
							esValido = ( nicknameUsuarios.find(nickUsr) != nicknameUsuarios.end() );
							if (!esValido) {
								cout << "El nickname ingresado no es valido. Intente nuevamente: ";
							}
							
						} while (!esValido);
						
						dataUsuarioGenerico = controlador->consultaUsuario(nickUsr);
						cout << dataUsuarioGenerico << endl;
						delete dataUsuarioGenerico;
					}
				}
				break;
				case '3': {	//CONSULTA DE IDIOMAS REGISTRADOS
					
					set<string> idiomasRegistrados = controlador->listarIdiomas();
					
					cout << "Idiomas registrados: " << endl;
					for (string idm : idiomasRegistrados) {
						cout << idm << endl;
					}
				}
				break;
				
				case '4': {//CONSULTA ESTADISTICAS
					
					string res, nickname;
					
					cout<<"Ingrese el tipo de estadistica que desea ver (Estudiante | Profesor | Curso): ";
					res = iohandler->read(res);
					
					if (res == "Estudiante"){ //ESTADISTICAS DE ESTUDIANTE
						cout<<"Estudiantes:\n ";
						set<DT_DataEstudiante*> dataEstudiantes = controlador->listarEstudiantes();
						set<string> nickEstudiantes = {};
						
						if (dataEstudiantes.empty()) {
							cout << "No hay estudiantes registrados." << endl;
						} else {
							bool nickValido = false;
							
							for (DT_DataEstudiante* dtEst : dataEstudiantes) {
								nickEstudiantes.insert(dtEst->getNickname());
								cout << dtEst << endl;
								delete dtEst;
							}
							
							cout<<"Ingrese nickname del estudiante a consultar: ";
							do {
								nickname = iohandler->read(nickname);
								nickValido = (nickEstudiantes.find(nickname) == nickEstudiantes.end());
								if (!nickValido) {
									cout << "\nEl nickname ingresado es invalido. Ingrese nuevamente:";
								}
							} while (!nickValido);
						}
						
						set<DT_DataProgresoCurso*> setDataProgresoCurso = controlador->listarCursosDeEstudiante(nickname);
						
						if (setDataProgresoCurso.empty()) {
							cout << "Este estudiante no tiene inscripciones." << endl;
						} else {
							cout << "Progreso de cursos del estudiante " << nickname << ": " << endl;
							for (DT_DataProgresoCurso* dataP : setDataProgresoCurso) {
								cout << dataP << endl;
								delete dataP;
							}
						}
					}else if(res == "Profesor"){//ESTADISTICAS DE PROFESOR
						cout<<"Profesores:\n ";
						set<DT_DataProfesor*> dataProfesores = controlador->listarDataProfesores();
						set<string> nickProfesores = {};
						
						if (dataProfesores.empty()) {
							cout << "No hay profesores registrados." << endl;
						} else {
							
							bool nickValido = false;
							
							for (DT_DataProfesor* dataP : dataProfesores) {
								cout << dataP << endl;
								nickProfesores.insert(dataP->getNickname());
								delete dataP;
							}
							
							cout<<"Ingrese nickname del profesor a consultar: ";
							do {
								nickname = iohandler->read(nickname);
								nickValido = (nickProfesores.find(nickname) == nickProfesores.end());
								if (!nickValido) {
									cout << "El nickname ingresado no es valido. Ingrese nuevamente: ";
								}
							} while (!nickValido);
							
							set<DT_DataPromedioCurso*> setDataPromedioCurso = controlador->listarCursosDeProfesor(nickname);
							
							if (setDataPromedioCurso.empty()) {
								cout << "Este profesor no tiene cursos asignados." << endl;
							} else {
								cout<<"Cursos de Profesor " << nickname << " :" << endl;
								for (DT_DataPromedioCurso* dataPromC : setDataPromedioCurso) {
									cout << dataPromC << endl;
									delete dataPromC;
								}
							}
						}
					} else if (res == "Curso") {//ESTADISTICAS DE CURSO
						set<DT_DataCurso*> setDataCursos = controlador->listarDataCursos();
						
						if (setDataCursos.empty()) {
							cout << "No hay cursos registrados." << endl;
						} else {
							set<string> nombresDeCursos = {};
							for (DT_DataCurso* dataCurso : setDataCursos) {
								cout << dataCurso << endl;
								nombresDeCursos.insert(dataCurso->getNombreCurso());
								delete dataCurso;
							}
							
							string nomCurso;
							bool esValidoNomCurso = false;
							cout << "Ingrese el nombre del curso que quiere consultar: ";
							do {
								nomCurso = iohandler->read(nomCurso);
								esValidoNomCurso = ( nombresDeCursos.count(nomCurso) != 0 );
								if (!esValidoNomCurso) {
									cout << "El nombre de curso ingresado no es valido. Ingrese nuevamente: ";
								}
							} while (!esValidoNomCurso);
						
							system("clear");
							DT_DataPromedioCurso* dataPromCurso = controlador->informacionCurso(nomCurso);
							cout << dataPromCurso << endl;
							delete dataPromCurso;
						}
						
					}else {
						cout<<"Valor invalido '" << res << "'.";
					}
				}
				break;
				default: cout<< "\nValor invalido (" << out << "), intentelo nuevamente\n";
				}
			}
			break;
		}
		case '7': {	//REALIZAR EJERCICIOS
			bool esCorrecto, existeEstudiante, existeCurso, idEjercicioEsValido;
			int idEjercicio;
			set<int> idEjercicios = {};
			set<string> cursosPendientes = {};
			string nicknameEst, nombreCurso;
			DT_DataProblemaEjercicio* problemaEj;
			
			set<string> nickEstudiantes = controlador->listarNickEstudiantes();
			iohandler->printSet(nickEstudiantes);
			
			if (nickEstudiantes.empty()) {
				cout << "No hay estudiantes registrados.\n" << endl;
			} else {
				do {
					cout<<"Ingrese nickname del estudiante: ";
					nicknameEst = iohandler->read(nicknameEst);
					existeEstudiante = controlador->existeEstudiante(nicknameEst);
					if (!existeEstudiante) {
						cout << "El nickname ingresado no existe. Ingrese nuevamente." << endl;
					}
				} while (!existeEstudiante);
				
				cursosPendientes = controlador->listarCursosPendientes(nicknameEst);
				if (cursosPendientes.empty()) {
					cout << "El estudiante ingresado no tiene cursos pendientes." << endl;
				} else {
					iohandler->printSet(cursosPendientes);
					cout<< "\n";
					
					do {
						cout<<"Ingrese nombre del Curso: ";
						nombreCurso = iohandler->read(nombreCurso);
						existeCurso = (cursosPendientes.find(nombreCurso) != cursosPendientes.end());
						if (!existeCurso) {
							cout << "El curso ingresado no esta en la lista de cursos pendientes."
								<< "\nIngrese nuevamente el nombre del curso: ";
						}
						cout<< "\n";
					} while (!existeCurso);
					
					idEjercicios = controlador->listarEjerciciosPendientes(nombreCurso);
					
					if (idEjercicios.empty()) {
						cout << "No tiene ejercicios pendientes de este curso. " << endl;
					} else {
						
						cout << "Ejercicios pendientes:\n";
						for (int i : idEjercicios) {
							cout << i << " / ";
						}
						cout<< "\n";
						
						string idEjString;
						do {
							cout << "Ingrese el id del ejercicio que desea resolver: " << endl;
							cin>>idEjString;
							cin.ignore();
						
							idEjercicio = stoi( idEjString );
							
							idEjercicioEsValido = (find(idEjercicios.begin(), idEjercicios.end(), idEjercicio) != idEjercicios.end());
						
							if (!idEjercicioEsValido) {
								cout << "El Id de ejercicio ingresado no es valido. Ingrese nuevamente: \n";
							}
						} while (!idEjercicioEsValido);
						
						problemaEj = controlador->getProblemaEjercicio(idEjercicio);
						cout << problemaEj;
						
						cout<<"\nIngrese solucion al ejercicio: ";
						if (problemaEj->getTipoEjercicioToString() == "De Traduccion") {
							string solucionDeTraduccion;
							solucionDeTraduccion = iohandler->read(solucionDeTraduccion);
							
							esCorrecto = controlador->ingresarSolucionDeTraduccion(solucionDeTraduccion);
						} else {
						
							int contador = 0;
							string palabra;
							vector<string> palabrasDeSolucion = {};
							cout << "Ingrese una por una las palabras que componen la solucion e ingrese '!' cuando quiera terminar de ingresar: " << endl;
							while (palabra != "!") {
								contador++;
								cout << "\nPalabra " << contador << ": ";
								palabra = iohandler->read(palabra);
								if (palabra != "!") {
									palabrasDeSolucion.push_back(palabra);
								}
							}
							
							esCorrecto = controlador->ingresarSolucionDeCompletar(palabrasDeSolucion);
						}
						
						system("clear");
						if (esCorrecto) {
							cout<<"La solucion al ejercicio es correcta!";
						} else {
							cout<<"Oops, parece que hubo un error en tu respuesta :c" << endl;
						}
					}
				}
			}
			
			break;
		}
		case '8': {	//PRECARGAR DATOS
			
			controlador->cargarDatos();
			
			//			iohandler->printSet(controlador->listarUsuarios());
			//			cout<< "\n";
			//			iohandler->printSet(controlador->listarCursosNoHabilitados());
			//			cout<< "\n";
			break;
		}
		case '9': {
			cout<<"Gracias por usar el sistema de Idiomas!";
			break;
		}
		default: cout<< "\nValor invalido (" << out << "), intentelo nuevamente\n";
		}
	}
	
	return 0;
}
