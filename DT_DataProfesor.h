#ifndef DT_DATAProfesor_H
#define DT_DATAProfesor_H

#include<iostream>

class DT_DataProfesor {
private:
	std::string nombre;
	std::string nickname;
public:
	DT_DataProfesor(std::string nickname,
					std::string nombre);
	~DT_DataProfesor();
	std::string getNickname();
	std::string getNombre();
	friend std::ostream& operator<<(std::ostream& os, DT_DataProfesor* dataProf);
	
};

#endif
