#include"Header.h"


StudentAC::StudentAC(std::string nume, int nota)
{
	this->nume = nume;
	if (nota > 0 && nota <= 10)
		this->nota = nota;
	else
	{
		std::cout << "Nota invalida\n";
		this->nota = 0;
	}
}

void StudentAC::afisare()
{
	std::cout << "Nume: ";
	if (nume != "")
		std::cout << nume;
	else
		std::cout << "Fara nume! ";

	std::cout << "\nNota: ";
	if (nota != 0)
		std::cout << nota << "\n";
	else
		std::cout << "Fara nota! \n";
}

void StudentAC::modificareNota(int nouaNota)
{
	if (nouaNota > 0 && nouaNota <= 10)
		nota = nouaNota;
	else
		std::cout << "Nota invalida\n";
}
bool StudentAC::operator<(const StudentAC& stud)
{
	if (nota < stud.nota)
		return 1;
	return 0;
}

void afisareStudenti(std::vector<StudentAC>* s)
{
	std:: vector<StudentAC>::iterator i;
	for (i = (*s).begin(); i != (*s).end(); ++i)
	{
		i->afisare();
	}
}

std::vector<StudentAC> convertire(StudentAC* s, int n)
{
	std::vector<StudentAC> stud;
	for (int i = 0; i < n; ++i)
	{
		stud.push_back(*(s + i));
	}
	return stud;
}
