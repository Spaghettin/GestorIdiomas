/*
 * Idioma.h
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#ifndef IDIOMA_H_
#define IDIOMA_H_

#include "string"
#include "ICollectible.h"

class Idioma : public ICollectible {
private:
	std::string nombreIdioma;
public:
	Idioma(std::string nombreIdioma);
	virtual ~Idioma();
	std::string getNombre();
};

#endif /* IDIOMA_H_ */
