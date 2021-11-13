//Header.h

#pragma once

#include<iostream>
using namespace std;

class Animal {

private:
	char* specie;
	int varsta;
	static int nr_animale;
public:
	Animal();
	Animal(char* specie, int varsta);
	~Animal();
	Animal(const Animal& a);

	void citire();
	void afisare();

	static int getNrAnimale();

	//*Optional

	friend ostream& operator<<(ostream& out, Animal& a);

};

//////////////////////////////////////////////////

//Functii.cpp

#include"Header.h"


Animal::Animal()
{
	varsta = 0;
	char initializareNume[15] = { "Fara nume" };
	specie = new char[strlen(initializareNume) + 1];
	strcpy_s(specie, strlen(initializareNume) + 1, initializareNume);

	nr_animale++;
}

Animal::Animal(char* specie, int varsta)
{
	this->varsta = varsta;
	if (specie != NULL)
	{
		this->specie = new char[strlen(specie) + 1];
		strcpy_s(this->specie, strlen(specie) + 1, specie);
	}
	else
	{
		this->specie = NULL;
	}
	this->nr_animale++;
}

Animal::~Animal()
{
	if (specie)
		delete[]specie;
	specie = nullptr;
	varsta--;
	nr_animale--;
}

Animal::Animal(const Animal& a)
{
	varsta = a.varsta;
	specie = new char[strlen(a.specie) + 1];
	strcpy_s(specie, strlen(a.specie) + 1, a.specie);
	nr_animale++;
}
void Animal:: citire()
{
	cout << endl;
	cin.ignore(100, '\n');
	char buff[100];
	cout << "Specie: ";
	cin.getline(buff, 100);
	specie = new char[strlen(buff) + 1];
	strcpy_s(specie, strlen(buff) + 1, buff);
	cout << "Varsta: ";
	cin >> varsta;
	cout << endl;
}
void Animal::afisare()
{
	cout << "Specie: ";
	if (specie)
		cout << specie<<endl;
	cout << "Varsta: " << varsta << endl;
	cout << endl;
}
int Animal::getNrAnimale()
{
	return nr_animale;
}
//*Optional

ostream& operator<<(ostream& out, Animal& a)
{
	cout << "Numarul animalelor este: ";
	out << a.getNrAnimale() << endl;
	return out;
}

///////////////////////////////

//main.cpp

#include"Header.h"


int Animal::nr_animale = 0;

int main(void)
{
	cout << "Se apasa Enter pentru inceperea programului! ";
	//Constructor fara parametri
	Animal a1;
	a1.citire();
	a1.afisare();

	//Constructor cu parametri
	char specieConstructorCuParamtetru[15] = { "Leu " };
	Animal a2(specieConstructorCuParamtetru, 10);
	a2.afisare();

	//Constrctor de copiere

	Animal a3(a1);

	a3.afisare();

	cout << endl;
	//Apel getContor
	cout << "Numarul animalelor este: ";
	cout << a3.getNrAnimale()<<endl;

	//*Optional cu supraincarcare de operator

	cout << a3;


	return 0;
}
