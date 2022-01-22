#pragma once
#include <iostream>
#include <vector>


class StudentAC
{
	std::string nume;
	int nota;
public:
	StudentAC()
	{
		nota = 0;
		nume = "Fara nume!";
	}
	StudentAC(std::string nume, int nota);
	void afisare();
	void modificareNota(int nouaNota);
	bool operator<(const StudentAC& st);
};
void afisareStudenti(std:: vector<StudentAC>* vect);
std::vector<StudentAC>convertire(StudentAC* s, int n);


