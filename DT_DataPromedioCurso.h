#ifndef DT_DATAPROMEDIOCURSO_H
#define DT_DATAPROMEDIOCURSO_H
#include<iostream>

using namespace std;

class DT_DataPromedioCurso {
public:
	DT_DataPromedioCurso();
	DT_DataPromedioCurso(const DT_DataPromedioCurso &arg);
	~DT_DataPromedioCurso();
private:
	string nombreCurso;
	float promedioProgresoCurso;
};

#endif

