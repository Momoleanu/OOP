#include "Header.h"
#include<algorithm>


int main()
{
	std::vector<StudentAC> s;
	s.push_back(StudentAC("Paul", 10));
	s.push_back(StudentAC("Mihai", -1));
	s.push_back(StudentAC("Ion", 14));
	s.push_back(StudentAC("Alex", 10));
	s.push_back(StudentAC());
	std::cout << "\nStudentii :\n";
	afisareStudenti(&s);

	std::cout << "\nFunctie modificare nota:\n";
	s.at(1).modificareNota(1);
	s.at(2).modificareNota(2);
	s.at(3).modificareNota(3);
	afisareStudenti(&s);

	int n = 5;
	StudentAC* stud2 = new StudentAC[n];
	stud2[0] = s.at(0);
	stud2[1] = s.at(1);
	stud2[2] = s.at(2);
	stud2[3] = s.at(3);
	stud2[4] = s.at(4);

	std::cout << "\nConvertire:\n";
	std::vector<StudentAC> stud3;
	stud3 = convertire(stud2, n);
	afisareStudenti(&stud3);

	std::sort(stud3.begin(), stud3.end());
	std::cout << "\nmySort:\n";
	afisareStudenti(&stud3);

	if (stud2)
		delete[] stud2;

	return 0;

}
