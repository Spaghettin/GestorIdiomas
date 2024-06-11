#ifndef DT_DATAPROFESOR_H
#define DT_DATAPROFESOR_H
#include<iostream>

using namespace std;

class DT_DataProfesor {
public:
	DT_DataProfesor();
	DT_DataProfesor(const DT_DataProfesor &arg);
	~DT_DataProfesor();
private:
	string nombre;
	string instituto;
};

#endif

