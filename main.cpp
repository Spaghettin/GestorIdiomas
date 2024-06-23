#include<iostream>
#include "I_Ctrl.h"
#include "Fabrica.h"

//No van
#include "DT_DataEstudiante.h"
#include "DT_DataProfesor.h"

int main (int argc, char *argv[]) {
	
	Fabrica* fb = new Fabrica();
	I_Ctrl* con = fb->getControlador();
	
	int out = 0;
	
	while(out != 8){
		cout<<"Bienvenido al sistema de Idiomas \n\n"
			<<"1. Ingresar Usuario \n"
			<<"2. Ingresar Curso \n"
			<<"3. Ingresar Idioma \n"
			<<"4. Modificar Curso \n" // Dentro van Habilitar, Eliminar, AgregarLeccion, AgregarEjercicio
			<<"5. Inscribirse a Curso \n"
			<<"6. Consultas \n"       // Dentro van ConsultaCurso, ConsultaUsuario, ConsultaEstadisticas
			<<"7. Realizar Ejercicios \n"
			<<"8. Salir"<<endl;
		
		cout<<"\n\nIngrese una opcion del menu: ";
		cin >> out;
		system("cls");
		switch(out){
			
			case 1: {
				
				char res;
				cout<<"Quiere ingresar un estudiante? y/n: ";
				cin>>res;
			if(res == 'y'){
				DT_DataEstudiante* datosEst;
				std::string nombre, descripcion, nickname, paisResidencia, contrasena;
				int ano, mes, dia;
				date* fechaNacimiento;
				
				cout<<"Ingrese nickname del estudiante que se ingresa: ";
				cin>>nickname;
				cout<<"Ingrese nombre del estudiante que se ingresa: ";
				cin>>nombre;
				cout<<"Ingrese contrasena del estudiante que se ingresa: ";
				cin>>contrasena;
				cout<<"Ingrese descripcion del estudiante que se ingresa: ";
				cin>>descripcion;
				cout<<"Ingrese pais de residencia del estudiante que se ingresa: ";
				cin>>paisResidencia;
				
				cout<<"Ingrese ano de nacimiento del estudiante que se ingresa: ";
				cin>>ano;
				cout<<"Ingrese mes de nacimiento del estudiante que se ingresa: ";
				cin>>mes;
				cout<<"Ingrese dia de nacimiento del estudiante que se ingresa: ";
				cin>>dia;
				
				fechaNacimiento = new date(ano, mes, dia);
				
				datosEst = new DT_DataEstudiante(nickname, nombre, contrasena, descripcion, fechaNacimiento, paisResidencia);
				
				con->crearE(datosEst);
			}else{
				DT_DataProfesor* datosProf = new DT_DataProfesor("Pedroo", "Pedro", "123", "si");
				con->crearP(datosProf, "Liceo 1");
				
				//con->listarIdiomas();
				do{
					string nombre;
					cout<<"Ingrese nombre del idioma que se especializa: ";
					cin>>nombre;
					con->seleccionaIdioma(nombre);
					cout<<"Quiere seguir agregando idiomas? y/n: ";
					cin>>res;
				}while(res == 'y');
			}
				break;
			}
			case 2: {
				
			
				
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				while(out != 5){
					cout<<"1. Habilitar Curso \n"
						<<"2. Ingresar Leccion \n"
						<<"3. Ingresar Ejercicio \n"
						<<"4. Eliminar Curso \n"
						<<"5. Volver al menu principal"<<endl;
					
					cout<<"\n\nIngrese una opcion del menu: ";
					cin >> out;
					system("cls");
					switch(out){
						
					case 1: {
						break;
					}
					case 2: {
						break;
					}
					case 3: {
						break;
					}
					case 4: {
						break;
					}
					case 5: {
						break;
					}
					default: cout<<"Valor invalido, intentelo nuevamente";
					}
				}
				break;
			}
			case 5: {
				break;
			}
			case 6: {
				while(out != 4){
					cout<<"1. Consulta Curso \n"
						<<"2. Consulta Usuario \n"
						<<"3. Consulta Estadisticas \n"
						<<"4. Volver al menu principal"<<endl;
					
					cout<<"\n\nIngrese una opcion del menu: ";
					cin >> out;
					system("cls");
					switch(out){
						
					case 1: {
						break;
					}
					case 2: {
						break;
					}
					case 3: {
						break;
					}
					case 4: {
						break;
					}
					default: cout<<"Valor invalido, intentelo nuevamente";
					}
				}
				break;
			}
			case 7: {
				break;
			}
			case 8: {
				cout<<"Gracias por usar el sistema de Idiomas!";
				break;
			}
			default: cout<<"Valor invalido, intentelo nuevamente";
		}
	}
	
		
	
	return 0;
}

