#ifndef IDIOMA_H
#define IDIOMA_H
#include<iostream>

using namespace std;

class Idioma {
public:
	Idioma();
	Idioma(const Idioma &arg);
	~Idioma();
private:
	string nombreIdioma;
};

#endif

