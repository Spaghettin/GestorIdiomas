#ifndef DT_DATAPROFESORCOMPLETO_H
#define DT_DATAPROFESORCOMPLETO_H
#include<iostream>
#include <set>
using namespace std;

class DT_DataProfesorCompleto {
private:
	std::string nombre;
	std::string nickname;
	std::string instituto;
	set<std::string> idiomas;
public:
	DT_DataProfesorCompleto(
			std::string nombreProf,
			std::string nicknameProf,
			std::string instituto,
			std::set<std::string> idiomasEspecializacion);
	~DT_DataProfesorCompleto();
	std::string getNombre();
	std::string getNickname();
	std::string getInstituto();
	std::set<std::string> getIdiomasEspecializacion();
	std::string getIdiomasToString();
	friend std::ostream& operator<<(std::ostream& os, DT_DataProfesorCompleto* dataProf);
};

#endif

