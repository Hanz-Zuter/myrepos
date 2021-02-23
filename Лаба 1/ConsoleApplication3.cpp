#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class bus //Фамилия и инициалы водителя, Номер автобуса, Номер маршрута, Марка, Год начала эксплуатации, Пробег.
{
private:				// поля класса bus
	char m_fiona[100];
	int m_bus_num;
	int m_race_num;
	char m_label[21];
	int m_year;
	int m_run;
public:
	bus(char fiona[100], int bus_num, int race_num, char label[21], int year, int run) //конструктор 
	{
		strcpy(m_fiona, fiona);
		m_bus_num = bus_num;
		m_race_num = race_num;
		strcpy(m_label, label);
		m_year = year;
		m_run = run;
	}
	bus()						//конструктор
	{
		m_fiona[100] = 0;
		m_bus_num = 0;
		m_race_num = 0;
		m_label[21] = 0;
		m_year = 0;
		m_run = 0;
	}
	bus(const bus& bus)			//конструктор копирования
	{
		strcpy(m_fiona, bus.m_fiona);
		m_bus_num = bus.m_bus_num;
		m_race_num = bus.m_race_num;
		strcpy(m_label, bus.m_label);
		m_year = bus.m_year;
		m_run = bus.m_run;
	};
	~bus() {};					//диструктор

	void setfiona(char fiona[100]) { strcpy(m_fiona, fiona); }
	void setbusnum(int busnum) { m_bus_num = busnum; }
	void setracenum(int racenum) { m_race_num = racenum; }
	void setlabel(char label[21]) { strcpy(m_label, label); }
	void setyear(int year) { m_year = year; }
	void setrun(int run) { m_run = run; }

	char* getfiona() { return (m_fiona); }
	int getbusnum() { return (m_bus_num); }
	int  getracenum() { return (m_race_num); }
	char* getlabel() { return (m_label); }
	int getyear() { return (m_year); }
	int getrun() { return (m_run); }
};


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов >> ";
	int n, count = 0;
	cin >> n;
	bus* massive;			//объявляем массив объектов класса bus
	massive = new bus[n];	// выделяем место для N объектов класса bus далее к объектам обращаемся через имя массива и индекс элемента
	while (true)
	{
		cout << "1. Заполнить" << endl << "2. Вывести" << endl << "3. Список автобусов для заданного номера маршрута" << endl << "4. Список автобусов, которые эксплуатируются больше 10 лет" << endl << "5. Список автобусов, пробег у которых больше 10 000 км" << endl << "6. Выход" << endl << ">> ";
		int choose;
		cin >> choose;
		if (choose == 1)	//заполнение массива
		{
			char temp1[20];
			int temp2;

			for (int i = 0; i < n; i++)									//заполняем поля объектов класса
			{
				massive[i] = bus();
				cout << "Введите ФИО водителя " << i + 1 << ": ";
				cin >> temp1;
				massive[i].setfiona(temp1);
				cout << endl << "Введите номер автобуса: ";
				cin >> temp2;
				massive[i].setbusnum(temp2);
				cout << endl << "Введите номер рейса: ";
				cin >> temp2;
				massive[i].setracenum(temp2);
				cout << endl << "Введите марку автобуса: ";
				cin >> temp1;
				massive[i].setlabel(temp1);
				cout << endl << "Введите год: ";
				cin >> temp2;
				massive[i].setyear(temp2);
				cout << endl << "Введите пробег: ";
				cin >> temp2;
				massive[i].setrun(temp2);
				cout << endl;
			}


		}
		if (choose == 2)												//выводим поля объектов класса
		{
			for (int i = 0; i < n; i++)
			{
				cout << "ФИО водителя " << i + 1 << ": " << massive[i].getfiona();
				cout << endl << "Номер автобуса: " << massive[i].getbusnum();
				cout << endl << "Номер рейса: " << massive[i].getracenum();
				cout << endl << "Марка автобуса: " << massive[i].getlabel();
				cout << endl << "Год: " << massive[i].getyear();
				cout << endl << "Пробег: " << massive[i].getrun();
				cout << endl;
				cout << endl;
			}
		}
		if (choose == 3)
		{
			int t;
			cout << "Введите номер маршрута " << endl << ">> ";
			cin >> t;
			for (int i = 0; i < n; i++)
			{
				if (massive[i].getracenum() == t)
				{
					count++;
					cout << "ФИО водителя " << i + 1 << ": " << massive[i].getfiona();
					cout << endl << "Номер автобуса: " << massive[i].getbusnum();
					cout << endl << "Номер рейса: " << massive[i].getracenum();
					cout << endl << "Марка автобуса: " << massive[i].getlabel();
					cout << endl << "Год: " << massive[i].getyear();
					cout << endl << "Пробег: " << massive[i].getrun();
					cout << endl;
					cout << endl;
				}
			}
			if (count == 0)
			{
				cout << "Подходящих элементов не найдено" << endl;
			}
			count = 0;
			system("pause");
			system("cls");
		}
		if (choose == 4)
		{
			int god = 2021;
			for (int i = 0; i < n; i++)
			{
				if (god - massive[i].getyear() > 10)
				{
					count++;
					cout << "ФИО водителя " << i + 1 << ": " << massive[i].getfiona();
					cout << endl << "Номер автобуса: " << massive[i].getbusnum();
					cout << endl << "Номер рейса: " << massive[i].getracenum();
					cout << endl << "Марка автобуса: " << massive[i].getlabel();
					cout << endl << "Год: " << massive[i].getyear();
					cout << endl << "Пробег: " << massive[i].getrun();
					cout << endl;
					cout << endl;
				}
			}
			if (count == 0)
			{
				cout << "Подходящих элементов не найдено" << endl;
			}
			count = 0;
			system("pause");
			system("cls");
		}
		if (choose == 5)
		{
			for (int i = 0; i < n; i++)
			{
				if (massive[i].getrun() > 10000)
				{
					count++;
					cout << "ФИО водителя " << i + 1 << ": " << massive[i].getfiona();
					cout << endl << "Номер автобуса: " << massive[i].getbusnum();
					cout << endl << "Номер рейса: " << massive[i].getracenum();
					cout << endl << "Марка автобуса: " << massive[i].getlabel();
					cout << endl << "Год: " << massive[i].getyear();
					cout << endl << "Пробег: " << massive[i].getrun();
					cout << endl;
					cout << endl;
				}
			}
			if (count == 0)
			{
				cout << "Подходящих элементов не найдено" << endl;
			}
			count = 0;
			system("pause");
			system("cls");
		}
		if (choose == 6)
		{
			break;
		}
	}

	return 0;
}
