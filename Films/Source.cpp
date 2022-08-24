#include<iostream>
#include<chrono>
#include<thread>
#include<vector>
#include<conio.h>
#include <iomanip>
#include<fstream>
#include <string>
using namespace std;

class Film
{
private:
	string s;
	string pl;
	struct fm
	{
		string ganre;
		string name;
		string year;
		string autor;
		string op;
	};
	fm F;
	vector<fm>film;

public:

	void create()
	{
		cout << "Enter ganre\n";
		cin >> F.ganre;
		cout << "Enter name\n";
		cin >> F.name;
		cout << "Enter Year\n";
		cin >> F.year;
		cout << "Enter autor\n";
		cin >> F.autor;
		cout << "Enter opisanie\n";
		cin >> F.op;
		film.push_back(F);
	}

	void Print()
	{
		for (int i = 0; i < film.size(); i++)
		{
			Pr(i);
		}
	}

	void Del()
	{
		int n;
		Print();
		cout << "Enter number del film\n";
		cin >> n;
		n--;
		film.erase(film.begin()+n);
	}


	void Pr(int i)
	{
		cout << "--->>>" << i+1 << "<<<---\n";
		cout << "Autor: " << film[i].autor << "\n";
		cout << "Gangre: " << film[i].ganre << "\n";
		cout << "Name film: " << film[i].name << "\n";
		cout << "Opisanie: " << film[i].op << "\n";
		cout << "Year: " << film[i].year << "\n\n";
	}
	void Edit()
	{
		int n;
		Print();
		cout << "Enter number edit film\n";
		cin >> n;
		n--;
		char vvod;
		do
		{
			system("cls");
			Pr(n);
			cout << "\n";
			cout << "1 - Edit autor\n";
			cout << "2 - Edit name\n";
			cout << "3 - Edit year\n";
			cout << "4 - Edit ganre\n";
			cout << "5 - Edit Opisanie\n";
			cout << "Exit - Esc\n";

			vvod = _getch();
			switch (vvod)
			{
			case'1':
			{
				cout << "Edit autor\n";
				cin >> film[n].autor;
				break;
			}
			case'2':
			{
				cout << "Edit name\n";
				cin >> film[n].name;
				break;
			}
			case'3':
			{
				cout << "Edit year\n";
				cin >> film[n].year;
				break;
			}
			case'4':
			{
				cout << "Edit ganre\n";
				cin >> film[n].ganre;
				break;
			}
			case'5':
			{
				cout << "Edit Opisanie\n";
				cin >> film[n].op;
				break;
			}
			}
		} while (vvod != 27);
	}

	void Read()
	{
		string q;
		ifstream r2("Zap.txt");
		if (r2.is_open())
		{
			while (!r2.eof())
			{
				getline(r2, q);
				s += q;
			}
			r2.close();
		}

	}

	void Prov(char &vvod)
	{
		while (vvod!=27)
		{
			if (!film.empty())
			{
				Read();
				string a;
				for (int i = 0; i < film.size(); i++)
				{
					a = "Autor: " + film[i].autor  + "Gangre: " + film[i].ganre  + "Name film: " + film[i].name  + "Opisanie: " + film[i].op  + "Year: " + film[i].year;
					pl += a;
				}
				if (s != pl)
				{
					cout << "s = " << s << "\n\n";
					cout << pl << "\n\n";
					ofstream r1("Zap.txt");
					for (int i = 0; i < film.size(); i++)
					{
						/*r1 << "--->>>" << i + 1 << "<<<---\n";*/
						r1 << "Autor: " << film[i].autor << "\n";
						r1 << "Gangre: " << film[i].ganre << "\n";
						r1 << "Name film: " << film[i].name << "\n";
						r1 << "Opisanie: " << film[i].op << "\n";
						r1 << "Year: " << film[i].year << "\n\n";
					}
					cout << "ZAPISANA!\n";
					r1.close();
				}
				else
				{
					cout << "No zap.\n";
				}
				pl.clear();
				s.clear();
			}
			this_thread::sleep_for(chrono::seconds(15));
		}
	}
};

int main()
{
	Film F;

	char vvod;
	thread Pot(&Film::Prov, &F, ref(vvod));
	do
	{
		system("cls");
		cout << "1 - Add film\n";
		cout << "2 - Del film\n";
		cout << "3 - Edit film\n";
		cout << "4 - Print\n";
		cout << "Exit - Esc\n";
		vvod = _getch();
		switch (vvod)
		{
		case'1':
		{
			thread p1(&Film::create, &F);
			p1.join();
			system("pause");
			break;
		}
		case'2':
		{
			thread p2(&Film::Del, &F);
			p2.join();
			system("pause");
			break;
		}
		case'3':
		{
			thread p3(&Film::Edit, &F);
			p3.join();
			system("pause");
			break;
		}
		case'4':
		{
			thread p4(&Film::Print, &F);
			p4.join();
			system("pause");
			break;
		}
		}
		
	} while (vvod != 27);
	Pot.join();
}