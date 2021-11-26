#include "Header.h"

int main()
{
	/*cout << "MAIN 1: " << endl << endl;
	cout << "\nGrupe studenti: 1109, 1110, 1111";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	char n1[] = "Nume1", n2[] = "Nume2", n3[] = "Nume3", n4[] = "Nume4", p1[] =
		"Prenume1", p2[] = "Prenume2", p3[] = "Prenume3", p4[] = "Prenume4";
	Data data1N(2001, 8, 23), data2N(1997, 2, 25), data3N(1985, 5, 13),
		data4N(1991, 9, 7);
	Student** v = new Student * [4];
	v[0] = new Student(n1, p1, &data1N, 1111);
	v[1] = new Student(n2, p2, &data2N, 1109);
	v[2] = new Student(n3, p3, &data3N, 1110);
	v[3] = new Student(n4, p4, &data4N, 1109);
	for (int i = 0; i < 4; i++)
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\nStudent nr. " << i + 1;
		v[i]->afisare();
	}
	int ok = 1;
	while (ok)
	{
		ok = 0;
		for (int i = 0; i < 3; i++)
		{
			if ((v[i]->getGrupa()) > (v[i + 1]->getGrupa()))
			{
				//s[i].mySwapStudent(s[i], s[i + 1]);
				swap(v[i], v[i + 1]);
				ok = 1;
			}
		}
	}
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nSORTARE DUPA GRUPA...";
	for (int i = 0; i < 4; i++)
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\nStudent nr. " << i + 1;
		v[i]->afisare();
	}*/

	cout << "Main 2: " << endl << endl;

	char n[] = { "Popescu" }, p[] = { "Ion" };
	Data dataN(1994, 11, 18);
	Data dataA(2018, 6, 17);
	//cout << "\nIntroduceti data angajarii: ";
	//dataA.citireData();
	int s = 4000;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	Angajat a(n, p, &dataN, &dataA, s);
	a.afisare();
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nApel getDataAngajare();";
	Data* d = a.getDataAngajare();
	cout << "\nData de angajare este: " << d->GetAn() << "." << d->GetLuna() << "."
		<< d->GetZi();
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nApel getSalariu();";
	cout << "\nSalariul este: " << a.getSalariu() << " lei.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nApel getVarstaAngajare();";
	cout << "\nVarsta la care s-a facut angajarea este: " << a.getVarstaAnagajare()
		<< " ani.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nApel afisarePerioadaMuncita();";
	cout << "\nIntroduceti data dorita: ";
	//dataC.citireData();
	Data dataC(2021, 11, 26);
	cout << "\nPerioada muncita este: "; a.afisarePerioadaMuncita(dataC);
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nLISTA ANGAJATI...";
	Data data1N(2001, 8, 23), data2N(1997, 2, 25), data3N(1985, 5, 13);
	Data data1A(2018, 4, 18), data2A(2015, 6, 15), data3A(2007, 7, 30);
	char n1[] = "Nume1", n2[] = "Nume2", n3[] = "Nume3", p1[] = "Prenume1", p2[] =
		"Prenume2", p3[] = "Prenume3";
	Data dataCurenta(2021, 11, 26);
	Angajat** v = new Angajat * [3];
	v[0] = new Angajat(n1, p1, &data1N, &data1A, 10156);
	v[1] = new Angajat(n2, p2, &data2N, &data2A, 18863);
	v[2] = new Angajat(n3, p3, &data3N, &data3A, 28100);
	for (int i = 0; i < 3; i++)
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n\nDetalii angajat " << i + 1 << ":";
		v[i]->afisare();
		cout << "\nVarsta angajare: " << v[i]->getVarstaAnagajare();
		cout << "\nPerioada muncita: ";
		v[i]->afisarePerioadaMuncita(dataCurenta);
	}
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	return 0;
}

Data::Data()
{
	//cout << "\nData();";
	an = 0;
	luna = 0;
	zi = 0;
}
Data::Data(int an, int luna, int zi)
{
	//cout << "\nData(int, int, int);";
	this->an = an;
	this->zi = zi;
	this->luna = luna;
}
int Data::GetAn()
{
	return an;
}
int Data::GetLuna()
{
	return luna;
}
int Data::GetZi()
{
	return zi;
}
int Data::maiMare(Data data2)
{
	if (an > data2.an)
		return 1;
	else
	{
		if (an < data2.an)
			return 0;
		else
		{
			if (luna > data2.luna)
				return 1;
			else
			{
				if (luna < data2.luna)
					return 0;
				else
				{
					if (zi < data2.zi)
						return 0;
					else
						return 1;
				}
			}
		}
	}
}
void Data::citireData()
{
	cout << "\nAn: ";
	cin >> an;
	while (an > 2021 || an < 0)
	{
		cout << "\nAn invalid! Reintroduceti anul!";
		cout << "\nAn: ";
		cin >> an;
	}
	cout << "\nLuna: ";
	cin >> luna;
	while (luna < 0 || luna>12)
	{
		cout << "\nLuna invalida! Reintroduceti luna!";
		cout << "\nLuna: ";
		cin >> luna;
	}
	cout << "\nZi: ";
	cin >> zi;
	while (zi < 0 || zi>30)
	{
		cout << "\nZi invalida! Reintroduceti ziua!";
		cout << "\nZi: ";
		cin >> zi;
	}
}

Persoana::Persoana()
{
	//cout << "\nPersoana();" << endl;
	this->dataNastere = new Data(0, 0, 0);
	nume = new char[1];
	prenume = new char[1];
}
Persoana::Persoana(char* nume, char* prenume, Data* dataNastere)
{
	//cout << "\nPersoana(char, char, data);"<<endl;
	this->nume = new char[strlen(nume) + 1];
	this->prenume = new char[strlen(prenume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
	this->dataNastere = new Data(*dataNastere);
}
Persoana::Persoana(const Persoana& p)
{
	this->nume = new char[strlen(p.nume) + 1];
	this->prenume = new char[strlen(p.prenume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	strcpy_s(this->prenume, strlen(p.prenume) + 1, p.prenume);
	this->dataNastere = p.dataNastere;
}
Persoana::~Persoana()
{
	//cout << "\n~Persoana();"<<endl;
	if (nume)
		delete[] nume;
	nume = nullptr;
	if (prenume)
		delete[] prenume;
	prenume = nullptr;
	delete dataNastere;
}
char* Persoana::getNume()
{
	return nume;
}
char* Persoana::getPrenume()
{
	return prenume;
}
Data* Persoana::getDataNastere()
{
	return dataNastere;
}
void Persoana::afisarePersoana()
{
	cout << endl;
	cout << "\nNume: " << nume;
	cout << "\nPrenume: " << prenume;
	cout << "\nData nastere: " << dataNastere->GetAn() << "." <<
		dataNastere->GetLuna() << "." << dataNastere->GetZi();
}
void Persoana::afisare()
{
	afisarePersoana();
	cout << endl;
}
void Persoana::citirePersoana()
{
	cin.ignore(100, '\n');
	char buff1[100], buff2[100];
	cout << "\nNume: ";
	cin.getline(buff1, 100);
	nume = new char[strlen(buff1) + 1];
	strcpy_s(nume, strlen(buff1) + 1, buff1);
	cout << "\nPrenume: ";
	cin.getline(buff2, 100);
	prenume = new char[strlen(buff2) + 1];
	strcpy_s(prenume, strlen(buff2) + 1, buff2);
	cout << "\nData nastere: ";
	dataNastere->citireData();
}
void Persoana::setNume(char* nume)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}
void Persoana::setPrenume(char* prenume)
{
	this->prenume = new char[strlen(prenume) + 1];
	strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
}
void Persoana::setDataNastere(Data* data)
{
	this->dataNastere->setData(data);
}

Student::Student()
{
	this->grupa = 0;
}
Student::Student(char* nume, char* prenume, Data* dataNastere, int grupa)
	:Persoana(nume, prenume, dataNastere)
{
	this->grupa = grupa;
}
Student::Student(const Student& s)
{
	this->grupa = s.grupa;
}
Student::~Student()
{
	this->grupa = -1;
}
void Student::afisare()
{
	afisarePersoana();
	cout << "\nGrupa: " << grupa << endl;
}
void Student::citire()
{
	cout << "\nGrupa: ";
	cin >> grupa;
	while (grupa < 1001 || grupa>1999)
	{
		cout << "\nGrupa invalida! Reintroduceti grupa!";
		cout << "\nGrupa: ";
		cin >> grupa;
	}
	citirePersoana();
}
int Student::getGrupa()
{
	return grupa;
}
void Student::setGrupa(int grupa)
{
	this->grupa = grupa;
}
void Student::mySwapStudent(Student& s1, Student& s2)
{
	Student aux;
	aux.setNume(s1.getNume());
	aux.setPrenume(s1.getPrenume());
	aux.setDataNastere(s1.getDataNastere());
	aux.setGrupa(s1.getGrupa());
	s1.setNume(s2.getNume());
	s1.setPrenume(s2.getPrenume());
	s1.setDataNastere(s2.getDataNastere());
	s1.setGrupa(s2.getGrupa());
	s2.setNume(aux.getNume());
	s2.setPrenume(aux.getPrenume());
	s2.setDataNastere(aux.getDataNastere());
	s2.setGrupa(aux.getGrupa());
}

Angajat::Angajat()
{
	//cout << "\nAngajat();";
	this->dataAngajare = new Data(0, 0, 0);
	this->salariu = 0;
}
Angajat::Angajat(char* nume, char* prenume, Data* dataNastere, Data* dataAngajare,
	int salariu) :Persoana(nume, prenume, dataNastere)
{
	//cout << "\nAngajat(char, char, data, data, int);";
	this->dataAngajare = new Data(*dataAngajare);
	this->salariu = salariu;
}
Angajat::~Angajat()
{
	//cout << "\n~Angajat()";
	delete dataAngajare;
	this->salariu = -1;
}
void Angajat::citire()
{
	citirePersoana();
	cout << "\n\nData angajare: ";
	this->dataAngajare->citireData();
	cout << "\n\nSalariu :";
	cin >> this->salariu;
}
void Angajat::afisare()
{
	afisarePersoana();
	cout << "\n\tData angajare: " << dataAngajare->GetAn() << "." <<
		dataAngajare->GetLuna() << "." << dataAngajare->GetZi();
	cout << "\n\tSalariu: " << salariu;
	cout << endl;
}
Data* Angajat::getDataAngajare()
{
	//Data d(this->dataAngajare->GetAn(), this->dataAngajare->GetLuna(),
	this->dataAngajare->GetZi();
	//return d;
	return dataAngajare;
}
int Angajat::getSalariu()
{
	return salariu;
}
int Angajat::getVarstaAnagajare()
{
	int ani=0;
	if (this->dataAngajare->GetLuna() > this->getDataNastere()->GetLuna())
	{
		ani = this->dataAngajare->GetAn() - this->getDataNastere()->GetAn();
	}
	else
	{
		if (this->dataAngajare->GetLuna() < this->getDataNastere()->GetLuna())
		{
			ani = this->dataAngajare->GetAn() -
				this->getDataNastere()->GetAn() - 1;
		}
		else
		{
			if (this->dataAngajare->GetLuna() ==
				this->getDataNastere()->GetLuna())
			{
				if (this->dataAngajare->GetZi() >
					this->getDataNastere()->GetZi())
				{
					ani = this->dataAngajare->GetAn() -
						this->getDataNastere()->GetAn();
				}
				else
				{
					if (this->dataAngajare->GetZi() <
						this->getDataNastere()->GetZi())
					{
						ani = this->dataAngajare->GetAn() -
							this->getDataNastere()->GetAn() - 1;
					}
					else
					{
						ani = this->dataAngajare->GetAn() -
							this->getDataNastere()->GetAn();
					}
				}
			}
		}
	}
	return ani;
}
void Angajat::afisarePerioadaMuncita(Data& dataCurenta)
{
	int an, luna, zi;
	an = dataCurenta.GetAn() - dataAngajare->GetAn();
	luna = dataCurenta.GetLuna() - dataAngajare->GetLuna();
	zi = dataCurenta.GetZi() - dataAngajare->GetZi();
	if (zi > 30)
		while (zi > 30)
		{
			zi = zi - 30;
			luna++;
		}
	if (zi < 0)
	{
		luna--;
		zi = zi + 30;
	}
	if (luna > 12)
		while (luna > 12)
		{
			luna = luna - 12;
			an++;
		}
	if (luna < 0)
	{
		an--;
		luna = luna + 12;
	}
	cout << an << "." << luna << "." << zi;
}
