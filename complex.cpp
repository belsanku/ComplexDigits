#include <iostream>
#include <cmath>
#include <string>

#define PI 3.141592654

using namespace std;

class ComplexDigits 
{
private:
	double re, im;  // для хра-ия дейст и мним части
public:
	ComplexDigits() 
	{
		re = 0; im = 0;
	}
	ComplexDigits(double a, double b) 
	{
		re = a; im = b;
	}
	ComplexDigits(const ComplexDigits& ob) 
	{
		re = ob.re; im = ob.im;
	}

	void setSoprDigit(ComplexDigits& Comp) 
	{
		Comp.im *= -1;
	}

	void getDigits(ComplexDigits& Comp) 
	{
		cout << "Действительная часть: " << Comp.re << endl;
		cout << "Мнимая часть: " << Comp.im << endl;
	}

	void getAbsAndArg(ComplexDigits& Comp) 
	{
		double result = 0.0;
		result = sqrt(Comp.re * Comp.re + Comp.im * Comp.im);
		cout << "Модуль комплесного числа: " << result << endl;
		result = atan2(Comp.im, Comp.re);
		result = result / PI * 180.0; //перевод в градусы
		cout << "Аргумент комплексного числа: " << result <<" градусов"<< endl;
	}

	void getPower(ComplexDigits& Comp, int power) 
	{
		double result1 = 0.0;
		result1 = atan2(Comp.im, Comp.re);
		double result2 = 0.0;
		result2 = sqrt(Comp.re * Comp.re + Comp.im * Comp.im);
		double step = pow(result2, power);
		double answer = power * result1;
		double X, Y;
		X = step * cos(answer);
		Y = step * sin(answer);
		cout << "Результат: " << endl;
		string str = to_string(X);
		if (to_string(X) == "0.000000") 
		{
			cout << "(0 + i(" << Y << "))" << endl;
		}else
		cout << "(" << X << " + i(" << Y << "))" << endl;
		//cout << "Действительная часть: " << X << endl;
		//cout << "Мнимая часть: " << Y << endl;
	}

	void getAlgForm(ComplexDigits& Comp) 
	{
		if (Comp.im >= 0) 
		{
			cout << "Алгебраическая форма: " << Comp.re << "+i*" << Comp.im << endl;
		}
		if (0 > Comp.im)
		{
			cout << "Алгебраическая форма: " << Comp.re << " - i *" << Comp.im * (-1) << endl;
		}
	}

	void getTrigAndPokazForm(ComplexDigits& Comp) 
	{
		double result1 = 0.0;
		result1 = sqrt(Comp.re * Comp.re + Comp.im * Comp.im);
		double result2 = 0.0;
		result2 = atan2(Comp.im, Comp.re);
		cout<<"Тригонометрическая форма: " << result1 << "*(cos(" << result2 << ") + i*sin(" << result2 << "))" << endl;
		cout << "Показательная форма: " << result1 << "*exp(i*" << result2 << ")" << endl;
	}

	void getRoot(ComplexDigits& Comp) 
	{
		double x, y;
		double z, phi;
		x = Comp.re; y = Comp.im;
		phi = atan2(y, x);
		z = sqrt(x * x + y * y);
		cout << "Вычисление квадратного корня комплексного числа: " << endl;
		cout << "z1 = " << sqrt(z) << "*exp(" << phi / 2 << "*j) = " << sqrt(z) * cos(phi / 2) << " + " << sqrt(z) * sin(phi / 2) << "*j" << endl;
		cout << "z2 = " << sqrt(z) << "*exp(" << phi / 2 + asin(1.0) << "*j) = " << sqrt(z) * cos(phi / 2 + asin(1.0)) << " + " << sqrt(z) * sin(phi / 2 + asin(1.0)) << "*j" << endl;

	}

	// операторы действия
	ComplexDigits& operator = (ComplexDigits);
	ComplexDigits operator + (ComplexDigits);
	ComplexDigits operator - (ComplexDigits);
	ComplexDigits operator * (ComplexDigits&);
	ComplexDigits operator / (ComplexDigits&);
	ComplexDigits& operator += (ComplexDigits);
	ComplexDigits& operator -= (ComplexDigits);
	ComplexDigits& operator *= (ComplexDigits);
	ComplexDigits& operator /= (ComplexDigits);

	// работа с потоками
	friend istream& operator >> (istream&, ComplexDigits&);
	friend ostream& operator << (ostream&, const ComplexDigits&);

	// операторы сравнения
	bool operator == (ComplexDigits& Comp);
	bool operator != (ComplexDigits& Comp);
	bool operator > (ComplexDigits& Comp);
	bool operator < (ComplexDigits& Comp);
};

/*реализация*/
bool ComplexDigits:: operator > (ComplexDigits& Comp)
{
	if (this->re > Comp.re)
	{
		return 1;
	}
	else if (this->re == Comp.re && this->im > Comp.im)
	{
		return 1;
	}
	else return 0;
}

bool ComplexDigits:: operator < (ComplexDigits& Comp)
{
	if (this->re < Comp.re)
	{
		return 1;
	}
	else if (this->re == Comp.re && this->im < Comp.im)
	{
		return 1;
	}
	else return 0;
}

bool ComplexDigits:: operator != (ComplexDigits& Comp)
{
	if (this->re != Comp.re || this->im != Comp.im)
	{
		return 1;
	}else
		return 0;
}

bool ComplexDigits:: operator == (ComplexDigits& Comp)
{
	if (this->re == Comp.re && this->im == Comp.im)
	{
		return 1;
	}
	else
		return 0;
}

ComplexDigits ComplexDigits:: operator * (ComplexDigits& Comp)
{
	double i, j;
	i = re * Comp.re - im * Comp.im;
	j = re * Comp.im + Comp.re * im;
	re = i;
	im = j;
	return *this;
}

ComplexDigits ComplexDigits:: operator / (ComplexDigits& Comp)
{
	double i, j, k;
	k = re * re + Comp.im * Comp.im;
	i = (re * Comp.re + im * Comp.im) / k;
	j = (Comp.re * im - re * Comp.im) / k;
	re = i;
	im = j;
	return *this;
}

ComplexDigits& ComplexDigits:: operator = (ComplexDigits Comp)
{
	this->re = Comp.re;
	this->im = Comp.im;
	return *this;
}

ComplexDigits ComplexDigits:: operator + (ComplexDigits Comp)
{
	this->re = this->re + Comp.re;
	this->im = this->im + Comp.im;
	return *this;
}

ComplexDigits ComplexDigits::operator - (ComplexDigits Comp)
{
	this->re = this->re - Comp.re;
	this->im = this->im - Comp.im;
	return *this;
}

ComplexDigits& ComplexDigits::operator += (ComplexDigits a) 
{ 
    re += a.re; 
    im += a.im; 
    return *this;
}
 
ComplexDigits& ComplexDigits::operator -= (ComplexDigits a)
{ 
    re -= a.re; 
    im -= a.im; 
    return *this;
} 
 
ComplexDigits& ComplexDigits::operator*=(ComplexDigits a)
{ 
    re *= a.re; 
    im *= a.im; 
    return *this;
} 
 
ComplexDigits& ComplexDigits::operator/=(ComplexDigits a)
{ 
    re /= a.re; 
    im /= a.im; 
    return *this;
} 

ostream& operator << (ostream& out, const ComplexDigits& Comp)
{
	if (Comp.im < 0)
		out << Comp.re << "+i(" << Comp.im << ")\n";
	else
		out << Comp.re << "+i" << Comp.im << "\n";
	return out;
}

istream& operator >> (istream& in, ComplexDigits& Comp)
{
	cout << "Введите действительную часть комплексного числа: ";
	in >> Comp.re;
	cout << "Введите мнимую часть комплексного числа: ";
	in >> Comp.im;
	return in;
}

void ShowAll(ComplexDigits& Comp) 
{
	//вывод частей
	Comp.getDigits(Comp);

	//Модуль и аргумент
	Comp.getAbsAndArg(Comp);

	//Алгебраическая форма
	Comp.getAlgForm(Comp);

	//Тригоном и Показ форм
	Comp.getTrigAndPokazForm(Comp);

	//Вычисление Корня
	Comp.getRoot(Comp);

	//Возведение в степень
	cout << "Возведение в степень, введите степень: ";
	int power = 0;
	cin >> power;
	Comp.getPower(Comp, power);

	/////////////////////////
	cout << endl;
	////////////////////////
}


int main()
{
	system("chcp 1251");
	ComplexDigits Comp;
	cin >> Comp;
	ComplexDigits Temp = Comp;

	cout << endl << "Введеное комплексное число: " << Comp << endl;
	Temp.setSoprDigit(Temp);
	cout << "Сопряженное комплексное число: " << Temp << endl;
	Temp = Comp;

	ShowAll(Comp);

	/*Операции с комплексными числами*/
	cout << "Операции с комплексными числами" << endl;
	ComplexDigits Comp1;
	ComplexDigits Comp2;
	cin >> Comp1;
	Temp = Comp1;

	Temp.setSoprDigit(Temp);
	cout << "Сопряженное комплексное число: " << Temp << endl;

	ShowAll(Comp1);
	Comp1 = Temp;

	cin >> Comp2;

	ComplexDigits Temp1;
	Temp1 = Comp2;
	Temp1.setSoprDigit(Temp);
	cout << "Сопряженное комплексное число: " << Temp1 << endl;
	ShowAll(Comp2);
	Comp2 = Temp1;

	cout << "Первое комплексное число: " << Comp1 << endl;
	cout << "Второе комплексное число: " << Comp2 << endl;
	cout << "Сумма: " << Comp1 + Comp2 << endl;
	Comp1 = Temp;
	Comp2 = Temp1;
	cout << "Разность: " << Comp1 - Comp2 << endl;
	Comp1 = Temp;
	Comp2 = Temp1;
	cout << "Произведение: " << Comp1 * Comp2 << endl;
	Comp1 = Temp;
	Comp2 = Temp1;
	cout << "Частное: " << Comp1 / Comp2 << endl << endl;
	Comp1 = Temp;
	Comp2 = Temp1;

	cout << "Проверка на равенство комплексных чисел: " << endl;

	if (Comp1 == Comp2)
	{
		cout << "Равны" << endl;
	}
	else
	{
		cout << "Не Равны" << endl;
	}
	/*Конец операций*/
	
	cout << endl << endl<<"Решение квадратного уравнения."<<endl;
	double a, b, c, D, x1, x2;
	cout << "a = "; cin >> a; 
	cout << "b = "; cin >> b; 
	cout << "c = "; cin >> c; 
	D = pow(b, 2) - 4 * a * c; 
	cout << "D = " << b * b - 4 * a * c << endl;
	if (0 < D)
	{
		x1 = (-b - sqrt(D)) / (2 * a);
		x2 = (-b + sqrt(D)) / (2 * a);
		cout << "Два корня" << endl; 
		cout<< "x1 = " << x1 << "  i x2 = " << x2 << endl;
	}
	if (0 == D)
	{
		x1 = (-b) / (2 * a);
		cout << "Один корень: " << x1 << endl;
	}

	if (0 > D)
	{
		cout << "Уравнение имеет комплексные корни"<<endl;
		D = fabs(D);
		cout << "x1 = " << -b / (2 * a) << " - i * " << sqrt(D) / (2 * a) << endl;
		cout << "x2 = " << -b / (2 * a) << " + i * " << sqrt(D) / (2 * a) << endl;
	}

	system("pause");
}