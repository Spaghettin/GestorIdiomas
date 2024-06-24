#ifndef IDIOMA_H_
#define IDIOMA_H_

#include "string"
#include "iostream"
#include "IDictionary.h"

class Idioma : public ICollectible {
private:
	std::string nombreIdioma;
public:
	Idioma();
	Idioma(std::string nombreIdioma);
	virtual ~Idioma();
	std::string getNombre();
};

#endif /* IDIOMA_H_ */
