#include<iostream>
using namespace std;
#include<string>
#define PI 3.1415


class Figura {
private:
	char* culoare;
public:
	Figura();
	Figura(const char* culoare);
	virtual ~Figura();
	virtual double Aria()=0;
    virtual double Perimetru()=0;
	virtual void Afisare();
};
Figura* figCuArieMax(Figura** figuri, int n);
Figura* figCuPerimetruMax(Figura** figuri, int n);
void mySort(Figura** figuri, int n);

class Dreptunghi:public Figura {

private:
	double lung, lat;
public:
	Dreptunghi();
	Dreptunghi(const char* culoare, double lung, double lat);
	~Dreptunghi();
	double Aria();
	double Perimetru();
	void Afisare();
};

class Triunghi :public Figura
{
private:
	double a, b, c;
public:
	Triunghi();
	Triunghi(const char* culoare, double a, double b, double c);
	~Triunghi();
	double Aria();
	double Perimetru();
	void Afisare();
};

class Cerc:public Figura {

	double xc, yc;
	double raza;
public:
	Cerc();
	Cerc(const char* culoare, double xc, double yc, double raza);
	~Cerc();
	double Aria();
	double Perimetru();
	void Afisare();
};

int main(void)
{
	/*cout << "\nFigura:\n";
	Figura* f1 = new Figura();
	Figura* f2 = new Figura("Rosu");
	f1->Afisare();
	f2->Afisare();*/

	cout << "\nDreptunghi:\n";
	Dreptunghi* d1 = new Dreptunghi();
	Dreptunghi* d2 = new Dreptunghi("albastru", 12, 6);
	d1->Afisare();
	d2->Afisare();
	cout << "\nAria lui d1: " << d1->Aria();
	cout << "\nAria lui d2: " << d2->Aria();
	cout << "\nPerimetrul lui d1: " << d1->Perimetru();
	cout << "\nPerimetrul lui d2: " << d2->Perimetru();


	cout << "\nPolimorfism:\n";
	int n = 6;
	Figura** vf = new Figura * [n];
	vf[0] = new Dreptunghi();
	vf[1] = new Dreptunghi("verde", 18, 5);
	vf[2] = new Cerc("porto", 13, 6,5);
	vf[3] = new Cerc("negru", 17, 9,5);
	vf[4] = new Triunghi("mov", 51, 8,4);
	vf[5] = new Triunghi("maro", 20, 7,4);
	for (int i = 0; i < n; i++)
		vf[i]->Afisare();

	Figura* figMax1 = figCuArieMax(vf, n);
	Figura* figMax2 = figCuPerimetruMax(vf, n);
	cout << endl << endl;
	cout << "Dintre figurile:" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i << ". ";
		vf[i]->Afisare();
	}
	cout << endl << " Aria maxima o are:" << endl;
	figMax1->Afisare();
	cout << endl << " Perimetrul maxim il are:" << endl;
	figMax2->Afisare();

	cout << endl;
	mySort(vf, n);
	cout << " Dupa sortare: " << endl;
	for (int i = 1; i < 5; i++)
	{
		cout << i << ". "<<endl;
		vf[i]->Afisare();
		cout << endl;
	}



	cout << "\n Eliberare memorie:\n";
	/*delete f1;
	delete f2;*/
	delete d1;
	delete d2;
	for (int i = 0; i < n; i++)
		delete vf[i];
	if (vf)
		delete[] vf;
	vf = 0;
	cout << endl << endl;
	return 0;


	return 0;
}

Figura::Figura()
{
	char initializareFigura[] = { "Fara nume!" };
	culoare = new char[strlen(initializareFigura) + 1];
	strcpy_s(culoare, strlen(initializareFigura) + 1, initializareFigura);
	
}

Figura::Figura(const char* culoare)
{
	if (culoare)
	{
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
	}
	else
	{
		this->culoare = NULL;
	}
}
Figura::~Figura()
{
	if (culoare)
		delete[]culoare;
	culoare = nullptr;
}

//double Figura::Aria()
//{
//	double rez = 0;
//	return rez;
//}
//
//double Figura::Perimetru()
//{
//	double rez = 0;
//	return rez;
//}

void Figura::Afisare()
{
	
	if (culoare)
		cout << "Culoare: " << culoare<<endl;
}

Dreptunghi::Dreptunghi():Figura()
{
	lung = 10;
	lat = 5;
}

Dreptunghi::Dreptunghi(const char* culoare, double lung, double lat):Figura(culoare)
{
	this->lung = lung;
	this -> lat = lat;
}

Dreptunghi::~Dreptunghi()
{
	lung = 0;
	lat = 0;
}

double Dreptunghi::Aria() {

	double rez;
	rez = lung * lat;
	return rez;

}

double Dreptunghi::Perimetru()
{
	double rez;
	rez = 2 * lung + 2 * lat;
	return rez;
}

void Dreptunghi::Afisare()
{
	
	cout << "\nTip figura: Dreptunghi";
	cout << "\nLungime: " << lung;
	cout << "\nLatime: "<<lat<<endl;
	Figura::Afisare();
}

Cerc::Cerc():Figura()
{
	xc = 0;
	yc = 0;
	raza = 0;
}

Cerc::Cerc(const char* culoare, double xc, double yc, double raza):Figura(culoare),xc(xc),yc(yc),raza(raza){}

Cerc::~Cerc()
{
	xc = -1;
	yc = -1;
	raza = -1;
}

double Cerc::Aria()
{
	double rez;
	rez = PI * raza * raza;
	return rez;
}
double Cerc::Perimetru()
{
	double rez = 0;
	rez = 2 * PI * raza;
	return rez;
}

void Cerc::Afisare()
{
	
	cout << endl;
	cout << "Cerc cu coordonatele (" << xc << "," << yc << "), raza " << raza << ", aria " << Aria() << " si perimetrul " << Perimetru() << endl;
	Figura::Afisare();
}

Triunghi::Triunghi()
{
	a = 0;
	b = 0;
	c = 0;
}
Triunghi::Triunghi(const char*culoare, double a, double b, double c):Figura(culoare),a(a),b(b),c(c){}

Triunghi::~Triunghi()
{
	a = -1;
	b = -1;
	c = -1;
}

double Triunghi::Aria()
{
	double rez = 0;
	double p;
	p = (a + b + b) / 2;
	rez = sqrt(p * (p - a) * (p - b) * (p - c));
	return rez;
}
double Triunghi::Perimetru()
{
	return (a + b + c);
}
void Triunghi::Afisare()
{
	
	cout << "\nTip figura: triunghi";
	cout << "\nLatura a: " << a;
	cout << "\nLatura b: " << b;
	cout << "\nLatura c: " << c<<endl;
	Figura::Afisare();
}

Figura* figCuArieMax(Figura** figuri, int n)
{
	int i = 0;
	float max = -1;
	Figura* figMax = NULL;
	for (; i < n; i++)
	{
		float arie = figuri[i]->Aria();
		if (arie > max)
		{
			max = arie;
			figMax = figuri[i];
		}
	}
	return figMax;
	
}
Figura* figCuPerimetruMax(Figura** figuri, int n)
{
	float max = -1;
	Figura* figMax = NULL;
	for (int i = 0; i < n; i++)
	{
		float perimetru = figuri[i]->Perimetru();
		if (perimetru > max)
		{
			max = perimetru;
			figMax = figuri[i];
		}
	}
	return figMax;
}
void mySort(Figura** figuri, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (figuri[i]->Aria() < figuri[j]->Aria())
			{
				Figura* aux;
				aux = figuri[i];
				figuri[i] = figuri[j];
				figuri[j] = aux;

			}
		}
	}
}
