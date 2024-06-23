#ifndef DATE_H
#define DATE_H
#include "iostream"
class date {
private:
	int ano;
	int mes;
	int dia;
public:
	date();
	date(int ano, int mes, int dia);
	date(const date &arg);
	~date();
	int getDia();
	int getMes();
	int getAno();
	friend std::ostream& operator<<(std::ostream& os, date* fecha);
	
};

#endif

