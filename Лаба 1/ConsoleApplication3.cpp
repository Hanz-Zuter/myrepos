#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int alreadyset = 0;


class bus //Фамилия и инициалы водителя, Номер автобуса, Номер маршрута, Марка, Год начала эксплуатации, Пробег.
{
private:
	 char m_fiona[20];
	 int m_bus_num;
	 int m_race_num;
	 char m_label[20];
	 int m_year;
	 int m_run;
	 bus* next;
public:
	bus(char fiona[34], int bus_num, int race_num, char label[20], int year, int run)
	{
		strcpy(m_fiona,fiona);
		m_bus_num = bus_num;
		m_race_num = race_num;
		strcpy(m_label,label);
		m_year = year;
		m_run = run;
	}
	bus() 
	{
		m_fiona[0]=0;
		m_bus_num = 0;
		m_race_num = 0;
		m_label[0]=0;
		m_year = 0;
		m_run = 0;
	}
	void setfiona(char fiona[34])	{	strcpy(m_fiona, fiona);		}
	void setbusnum(int busnum)		{	m_bus_num = busnum;			}
	void setracenum(int racenum)	{	m_race_num = racenum;		}
	void setlabel(char label[20])	{	strcpy(m_label, label);		}
	void setyear(int year)			{	m_year = year;				}
	void setrun(int run)			{	m_run = run;				}

	char* getfiona()				{	return (m_fiona);			}
	int getbusnum()					{	return (m_bus_num);			}
	int  getracenum()				{	return (m_race_num);		}
	char * getlabel()				{	return (m_label);			}
	int getyear()					{	return (m_year);			}
	int getrun()					{	return (m_run);				}

	void setnext(bus*p)				{	next = p;					}
//	void sethead(bus* p)			{	head = p;					}
	bus* getnext()					{	return next;				}
//	bus* gethead()					{	return(head);				}
};


int main() 
{
	setlocale(LC_ALL, "Rus");

	while (true) 
	{
		bus* mass;
		cout << "Введите номер элемента";
		int n;
		cin >> n;
		bus* massive = new bus[n];

		
		int choose;
		cin >> choose;
		if (choose == 1)	//создание элемента
		{
			while (true)
			{
				char temp1[20];
				int temp2;
				bus*element = &massive[0];
				char temp1[20];
				int temp2;
				cout << "Введите ФИО водителя: ";
				cin >> temp1;
				element->setfiona(temp1);
				cout << endl << "Введите номер автобуса: ";
				cin >> temp2;
				element->setbusnum(temp2);
				cout << endl << "Введите номер рейса: ";
				cin >> temp2;
				element->setracenum(temp2);
				cout << endl << "Введите марку автобуса: ";
				cin >> temp1;
				element->setlabel(temp1);
				cout << endl << "Введите год: ";
				cin >> temp2;
				element->setyear(temp2);
				cout << endl << "Введите пробег: ";
				cin >> temp2;
				element->setrun(temp2);



				temp2 = element->getrun();
				cout << temp2;
				break;
			}
			
			
		}
	}








	return 0;
}