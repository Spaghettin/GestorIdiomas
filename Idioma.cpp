
#include "Idioma.h"

Idioma::Idioma() {}

Idioma::Idioma(std::string nombreIdioma) {
	this->nombreIdioma = nombreIdioma;
}

Idioma::~Idioma() {
	// TODO Auto-generated destructor stub
}

std::string Idioma::getNombre() {
	return this->nombreIdioma;
}
