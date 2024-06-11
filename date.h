#ifndef DATE_H
#define DATE_H

class date {
public:
	date();
	date(int ano, int mes, int dia);
	date(const date &arg);
	~date();
private:
	int ano;
	int mes;
	int dia;
};

#endif

