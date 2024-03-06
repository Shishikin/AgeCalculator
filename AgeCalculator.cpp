// AgeCalculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

void PrintResult(int another_age, int another_age_month, int another_year, int another_month)
{
	if ((another_age % 100 - another_age % 10) / 10 == 1)
	{
		if (another_age % 10 <= 4 && another_age % 10 >= 2)
		{
			std::cout << "В " << another_year << " году " << another_month << " месяце вам будет " << another_age << " года и ";
		}
		else
		{
			std::cout << "В " << another_year << " году " << another_month << " месяце вам будет " << another_age << " лет и ";
		}
	}
	else
	{
		if (another_age % 10 <= 4 && another_age % 10 >= 2)
		{
			std::cout << "В " << another_year << " году " << another_month << " месяце вам будет " << another_age << " года и ";
		}
		else
		{
			if (another_age % 10 == 1)
			{
				std::cout << "В " << another_year << " году " << another_month << " месяце вам будет " << another_age << " год и ";
			}
			else
			{
				std::cout << "В " << another_year << " году " << another_month << " месяце вам будет " << another_age << " лет и ";
			}
		}
	}
	if ((another_age_month - another_age_month % 10) / 10 == 1)
	{
		if (another_age_month % 10 <= 4 && another_age_month % 10 >= 2)
		{
			std::cout << another_age_month << " месяца.";
		}
		else
		{
			std::cout << another_age_month << " месяцев";
		}
	}
	else
	{
		if (another_age_month % 10 <= 4 && another_age_month % 10 >= 2)
		{
			std::cout << another_age_month << " месяца.";
		}
		else
		{
			if (another_age_month % 10 == 1)
			{
				std::cout << another_age_month << " месяц.";
			}
			else
			{
				std::cout << another_age_month << " месяцев.";
			}
		}
	}

}

int main()
{

#ifdef _WIN32
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif
	int year_now = 0, age_now = 0, another_year = 0, another_age = 0, month_now = 0, month_birthday = 0, another_month = 0, another_age_month = 0;

	std::cout << "Введите текущий год и нажмите ENTER.\n";
	std::cin >> year_now;
	do
	{
		std::cout << "Введите текущий месяц и нажмите ENTER.\n";
		std::cin >> month_now;
	} while (month_now > 12 || month_now < 1);

	std::cout << "Введите свой возраст (в годах).\n";
	std::cin >> age_now;
	do
	{
		std::cout << "Введите месяц своего рождения (число от 1 до 12).\n";
		std::cin >> month_birthday;
	} while (month_birthday > 12 || month_birthday < 1);

	std::cout << "Введите год, для которого вы хотите узнать свой возраст.\n";
	std::cin >> another_year;
	do
	{
		std::cout << "Введите месяц этого года (число от 1 до 12).\n";
		std::cin >> another_month;
	} while (another_month > 12 || another_month < 1);

	if (another_month - month_birthday < 0)
	{
		if (month_now - month_birthday < 0)
		{
			another_age = another_year - (year_now - age_now);
			another_age_month = 12 + another_month - month_birthday;
		}
		else
		{
			another_age = another_year - (year_now - age_now) - 1;
			another_age_month = 12 + another_month - month_birthday;
		}

	}
	else
	{
		if (month_now - month_birthday < 0)
		{
			another_age = another_year - (year_now - age_now) + 1;
			another_age_month = another_month - month_birthday;
		}
		else
		{
			another_age = another_year - (year_now - age_now);
			another_age_month = another_month - month_birthday;
		}

	}

	if (another_age >= 0)
	{
		if (another_age > 150)
		{
			std::cout << "Извините, но вы вряд ли доживете до " << another_year << " года!";

		}
		else
		{
			PrintResult(another_age, another_age_month, another_year, another_month);
		}
	}
	else
	{
		std::cout << "В " << another_year << " вы еще не родились!\n";
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
