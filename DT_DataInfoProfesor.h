#ifndef DT_DATAINFOPROFESOR_H
#define DT_DATAINFOPROFESOR_H
#include<iostream>
#include <set>

using namespace std;

class DT_DataInfoProfesor {
public:
	DT_DataInfoProfesor();
	DT_DataInfoProfesor(const DT_DataInfoProfesor &arg);
	~DT_DataInfoProfesor();
private:
	string instituto;
	set<string> idiomas;
};

#endif

