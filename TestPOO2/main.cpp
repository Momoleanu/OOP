#include<iostream>
using namespace std;
 
class Persoana {
protected:
    char* nume;
public:
    Persoana();
    Persoana(const char* nume);
    Persoana(const Persoana& p);
    ~Persoana();//virtual ~Persoana();
 
    void citire(); //virtual void citire();
    void afisare();//virtual void afisare();
};
 
class Angajat :public Persoana {
 
protected:
    double salar;
public:
    Angajat();
    Angajat(const char* nume, double salar);
    Angajat(const Angajat& a);
    ~Angajat();
 
    void citire();
    void afisare();
 
    Angajat& operator=(const Angajat& a);
};
 
int main(void)
{
    cout << "Citire initiala fara vector. Apel constructori + destructori + teste obiecte de tip Angajat" << endl;
    cout << "=================================" << endl;
 
    //Afisare constructor vid
    Angajat a;
    a.afisare();
 
    //Afisare constructor cu parametri nullptr si 0
    Angajat a2(nullptr,0);
    a2.afisare();
 
    //Afisare constructor cu parametri
 
    Angajat a3("Robert", 2450);
    a3.afisare();
 
    //Citire+afisare Angajat
 
    Angajat a4;
    a4.citire();
    a4.afisare();
 
    //Constructor de copiere la un obiect cu parametri
 
    Angajat a5(a3);
    a5.afisare();
 
    //Constructor de copiere la un obiect cu parametri nullptr si 0
 
    Angajat a6(a2);
    a6.afisare();
    cout << endl;
 
    cout << "===================================================" << endl;
    cout << "Citiri + Afisari folosind pointer la un vector de obiecte la clasa de baza fara a folosi virtual" << endl;
 
    int n = 6;
    Persoana** p = new Persoana * [n];
    //Instantiere obiecte de tip Persoana
    //Citire+Afisari+Teste
    //Constructor fara parametri+citire
    p[0] = new Persoana();
    p[0]->citire();
    p[0]->afisare();
 
    //Constructor cu parametri
 
    p[1] = new Persoana("Robert");
    p[1]->afisare();
 
    //Constructor de copiere
    p[2] = new Persoana(*(Persoana*)p[1]);
    p[2]->afisare();
 
    //Instantiere obiecte de tip Angajat
    //Constructor cu parametri
 
    p[3] = new Angajat("Victor", 2500);
    ((Angajat*)p[3])->afisare();
 
    //Constructor fara parametri citire+afisare
 
    p[4] = new Angajat();
    ((Angajat*)p[4])->citire();
    ((Angajat*)p[4])->afisare();
 
    //Constructor de copiere Angajat
    p[5] = new Angajat(*(Angajat*)p[3]);
    ((Angajat*)p[5])->afisare();
 
    //Cu virtual la obiectele de tip Angajat se putea folosi doar citire si afisarea de baza p[4]->citire, p[4]->afisare
    //Evidentiere operator=
    Angajat angajat1("Cristi", 2000);
    Angajat angajat2;
    angajat2 = angajat1;
    angajat2.afisare();
 
    cout << "============================" << endl;
    cout << "Eliberare memorie: " << endl<<endl;
 
    for (int i = 0; i < n; i++)
    {
        if (p[i])
            delete p[i];
        p[i] = 0;
    }
    if (p)
        delete[]p;
    p = nullptr;
 
    return 0;
}
 
Persoana::Persoana()
{
    cout << "Constructor vid Persoana" << endl;
    char initPers[] = { "Fara nume" };
    nume = new char[strlen(initPers) + 1];
    strcpy_s(nume, strlen(initPers) + 1, initPers);
}
 
Persoana::Persoana(const char* nume)
{
    cout << "Constructor cu parametri Persoana" << endl;
    if (nume)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
    }
    else
    {
        this->nume = nullptr;
    }
}
 
Persoana::Persoana(const Persoana& p)
{
    cout << "Constructor de copiere Persoana" << endl;
    if (p.nume)
    {
        nume = new char[strlen(p.nume) + 1];
        strcpy_s(nume, strlen(p.nume) + 1, p.nume);
    }
    else
    {
        nume = NULL;
    }
}
 
Persoana::~Persoana()
{
    cout << "Destructor Persoana" << endl;
    if (nume)
        delete[]nume;
    nume = nullptr;
}
 
void Persoana::citire()
{
    char buff[100];
    cout << "Nume: ";
    cin.getline(buff, 100);
    if (nume)
        delete[]nume;
    nume = new char[strlen(buff) + 1];
    strcpy_s(nume, strlen(buff) + 1, buff);
}
 
void Persoana::afisare()
{
    if (nume)
        cout << "Nume: " << nume<<endl;
    else
        cout << "Nume: Fara nume" << endl;
}
 
Angajat::Angajat() :Persoana()
{
    cout << "Constructor vid Angajat" << endl;
    salar = 0;
}
Angajat::Angajat(const char* nume, double salar) : Persoana(nume), salar(salar)
{
    cout << "Constructor cu parametri Angajat" << endl;
}
Angajat::Angajat(const Angajat& a):Persoana(a)
{
    cout << "Constructor de copiere Angajat" << endl;
    salar = a.salar;
}
 
void Angajat::citire()
{
    Persoana::citire();
    cout << "Salar: ";
    cin >> salar;
}
 
void Angajat::afisare()
{
    Persoana::afisare();
    cout << "Salar: " << salar<<endl ;
}
 
Angajat& Angajat::operator=(const Angajat& a)
{
    salar = a.salar;
    if (nume)
        delete[]nume;
    if (a.nume)
    {
        nume = new char[strlen(a.nume) + 1];
        strcpy_s(nume, strlen(a.nume) + 1, a.nume);
    }
    else
    {
        nume = nullptr;
    }
    cout << "Operator= " << endl;
    return *this;
}
 
Angajat::~Angajat()
{
    cout << "Destructor Angajat" << endl;
    salar = -1;//salar--;
}
