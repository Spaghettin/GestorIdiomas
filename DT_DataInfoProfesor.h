#ifndef DT_DATAINFOPROFESOR_H
#define DT_DATAINFOPROFESOR_H

#include<iostream>
#include <set>

class DT_DataInfoProfesor {
public:
	DT_DataInfoProfesor(std::string instituto, std::set<std::string> idiomas);
	~DT_DataInfoProfesor();
	std::string getInstituto();
	std::set<std::string> getIdiomas();
	std::string getIdiomasToString();
	friend std::ostream& operator<<(std::ostream& os, DT_DataInfoProfesor* dataInfo);
private:
	std::string instituto;
	std::set<std::string> idiomas;
};

#endif

