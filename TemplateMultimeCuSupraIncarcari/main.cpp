#include<iostream>
using namespace std;

template <typename T>
class Multime
{
private:
	T* elem;
	int n;
	int dim;
public:
	Multime();
	Multime(int dim);
	Multime(const Multime& m);
	~Multime();
	void afisare();
	void adauga(const T& el);

	T operator!();					
	Multime operator+(const Multime& m);
	Multime& operator=(const Multime& m);
};

template <typename T> T Aduna(T& v1, T& v2);


template <typename T> Multime<T>::Multime(void)
{
	n = 0;
	dim = 0;
	elem = nullptr;
}

template <typename T> Multime<T>::Multime(int dim)
{
	n = 0;
	if (dim > 0)
	{
		this->dim = dim;
		elem = new T[dim]{ 0 };		
	}
	else
	{
		cout << "\nInvalid";
		this->dim = 0;
		elem = nullptr;
	}
}

template <typename T> Multime<T>::Multime(const Multime<T>& m)
{
	n = m.n;
	dim = m.dim;
	if (m.elem)
	{
		elem = new T[dim]{ 0 };
		for (int i = 0; i < dim; ++i)
		{
			elem[i] = m.elem[i];
		}
	}
	else
	{
		elem = nullptr;
	}
}

template <typename T> Multime<T>::~Multime()
{
	n = 0;
	dim = 0;
	if (elem)
		delete[] elem;
	elem = nullptr;
}

template <typename T> void Multime<T>::afisare()
{
	if (elem)
	{
		cout << "\nMultimea este: {";
		for (int i = 0; i < n; ++i)
		{
			cout << elem[i];
			if (i < n - 1)
			{
				cout << ", ";
			}
		}
		cout << "};";
	}
	else
	{
		cout << "\nMultimea nu exista.";
	}
}

template <typename T> void Multime<T>::adauga(const T& el)
{
	if (n < dim)
	{
		int ok = 0;
		for (int i = 0; i < n; ++i)
		{
			if (el == elem[i])
			{
				ok = 1;
				break;
			}
		}
		if (ok == 0)
		{
			elem[n] = el;
			n++;
		}
		else
		{
			cout << "\nElementul exista in multime";
		}
	}
	else {
		cout << "\nMultime plina";
	}
}

template <typename T> T Multime<T>::operator!()
{
	T max = 0;
	if (n > 0)
	{
		max = elem[0];
		for (int i = 1; i < n; ++i)
		{
			if (max < elem[i])
				max = elem[i];
		}
	}
	else
		throw 0;
	return max;
}

template <typename T> Multime<T> Multime<T>::operator+(const Multime<T>& m)
{
	if (n == m.n)
	{
		Multime<T> m3(dim);

		for (int i = 0; i < n; ++i)
		{
			m3.adauga(Aduna(elem[i], m.elem[i]));
		}
		return m3;
	}
	else
		throw 0;

	Multime<T> m3;
	return m3;
}

template <typename T> Multime<T>& Multime<T>::operator=(const Multime<T>& m)
{
	if (elem)
	{
		delete[] elem;
		n = 0;
		dim = 0;
	}
	n = m.n;
	dim = m.dim;
	elem = new T[dim]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		elem[i] = m.elem[i];
	}
	return *this;
}

template <typename T> T Aduna(T& v1, T& v2)
{
	T elem = v1 + v2;
	return elem;
}


int main(void)
{
	Multime<int> m1;
	m1.afisare();

	int n = 10;
	Multime<double> m2(10);
	m2.adauga(3.34);
	m2.adauga(123.12);
	m2.adauga(2.691);
	m2.adauga(1.45);
	m2.afisare();

	Multime < double > mCopiat2 = m2;
	cout << "\nMultime copiata: ";
	mCopiat2.afisare();

	Multime<int> m3(n);
	m3.adauga(2);
	m3.adauga(1231);
	m3.adauga(420);
	m3.adauga(13);
	m3.afisare();

	
	int maxM3, maxM1;
	double maxM2;
	try {
		maxM2 = !m2;
		cout << "\nMax m2: " << maxM2;
		maxM3 = !m3;
		cout << "\nMax m3: " << maxM3;
		maxM1 = !m1;
		cout << "\nMax m1: " << maxM1;
	}
	catch (int)
	{
		cout << "\nMultimea nu exista! ";
	}

	cout << "\n=======================================================\n";
	cout << "Adunare multimi: \n";

	Multime<double> m4(n);
	Multime<double> m5(n);
	m4.adauga(4.2);
	m4.adauga(5231);
	m4.adauga(198.7);
	m4.adauga(19.121);

	m5.adauga(847);
	m5.adauga(165.3);
	m5.adauga(-2.429);
	m5.adauga(-37);
	m4.afisare();
	m5.afisare();
	cout << "\nOperatorul +";
	Multime<double> multimeAduna;
	try {
		multimeAduna = m4 + m5;
	}
	catch (int)
	{
		cout << "\nMultimile nu au acelasi numar de elemente.";
	}
	multimeAduna.afisare();

	cout << "\n==============================================================\n";
	cout << "Aduna:\n";
	Multime<double> m6;
	m6=Aduna(m4, m5);
	m6.afisare();
	cout << "\n";

	return 0;
}
