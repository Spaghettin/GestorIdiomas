#include "Profesor.h"

Profesor::Profesor() {
	
}

Profesor::Profesor(DT_DataProfesor* datosProf, std::string nombreInstituto){
	this->nombre = datosProf->getNombre();
	this->contrasena = datosProf->getContrasena();
	this->nickname = datosProf->getNickname();
	this->descripcion = datosProf->getDescripcion();
	this->nombreInstituto = nombreInstituto;
	this->idiomas = new OrderedDictionary();
}

Profesor::Profesor(const Profesor &arg) {
	
}

Profesor::~Profesor() {
	
}

std::string Profesor::getnombreInstituto() {
	return this->nombreInstituto;
}

Profesor* Profesor::crearP(DT_DataProfesor* datosProfe, std::string nombreInstituto){
	return new Profesor(datosProfe, nombreInstituto);
}

std::ostream& operator<<(std::ostream& os, Profesor* prof) {
	os  << "\nNickname: " << prof->getNickname()
		<< "\nNombre: " << prof->getNombre()
		<< "\nContrasena: " << prof->getContrasena()
		<< "\nDescripcion: " << prof->getDescripcion()
		<< "\nNombre Instituto: " << prof->getnombreInstituto();
	
	return os;
}

void Profesor::listarIdiomas(){
	Idioma* idiomas;
	//std::set<string> setIdiomas;
	IIterator* it = this->idiomas->getIterator();	//Se crea el iterador para el diccionario idiomas
	
	while(it->hasCurrent()){
		idiomas = (Idioma*)it->getCurrent();		//Se inicializa el puntero a obj "idiomas" al objeto que esta apuntando el it
		//setIdiomas.insert(idiomas->getNombre());
		if(idiomas){
			cout << idiomas->getNombre() << "\n";
		}
		it->next();
	}
	
	//return setIdiomas;
}

//Falta hacer el control si ya existe idiomaS en el ctrl
void Profesor::seleccionarIdioma(Idioma* idiomaS){
	
	std::string nIdioma = idiomaS->getNombre(); 	//Guardo el string nombre del objeto idioma que recibo por parametros en nIdioma
	IKey* ik = new String(nIdioma.c_str());     	//Se hace un identificador(key) con el nombre del idioma
	
	this->idiomas->add(ik, idiomaS);	       		//Se añade el objeto y el id que lo identifica al diccionario idiomas de profesor
}
