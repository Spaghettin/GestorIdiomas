#ifndef DT_DATAPROMEDIOCURSO_H
#define DT_DATAPROMEDIOCURSO_H
#include<iostream>

using namespace std;

class DT_DataPromedioCurso {
private:
	std::string nombreCurso;
	float promedioProgresoCurso;
public:
	DT_DataPromedioCurso(std::string nombreC, float promedioProgresoC);
	virtual ~DT_DataPromedioCurso();
	std::string getNombreCurso();
	float getPromedioProgresoCurso();
	friend std::ostream& operator<<(std::ostream& os, DT_DataPromedioCurso* dataPC);
};

#endif

