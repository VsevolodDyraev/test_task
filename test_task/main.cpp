#include<conio.h>
#include<iostream>
#include<time.h>
#include<fstream>
#include<Windows.h>
#include<string>
#include"inaccurate_search.h"


using namespace std;

int main()
{
	//Извините, что не смог ускорить в 500 раз, но по моим подсчетам я ускорил ~200р
	//-----------------------------------------------------------------

	char y;
	string name_file;
	const int MAX_SIZE_WORD = 100;
	unsigned long long int all_time = 0;
	
	
	char* buff = new char[MAX_SIZE_WORD];
	for (int i = 0; i < MAX_SIZE_WORD; i++)
		buff[i] = ' ';
	

	ifstream fin;
	
	int start_time;	
	int end_time;
	char* hell = new char[MAX_SIZE_WORD];
	//inaccurate_search search_w(hell,in);
	
	bool ne_overfl = true;
	int time = 1;
	while (1)
	{
		bool f = true;
		cout << "enter name file: ";
		cin >> name_file;
		fin.open(name_file);
		time = 1;
		
		bool h = fin.is_open();
		if (!fin.is_open())
		{
			cout << "ERROR: file not open!\nwould you like to continue ? (y / ...)";
			y = _getch();
			if (y != 'y' && y != 'Y')
			{
				system("cls");
				break;
			}
			system("cls");
			continue;
		}
		fin.close();

		fin.open(name_file);
		int size = 0;
		fin.seekg(0, std::ios::end);
		size = fin.tellg();
		cout << "Size file: " << size << endl;
		fin.close();

		if (size > 225002468)
			size = 225002468;
		unsigned long int in = size / 12;


		cout << "Enter serch word: ";
		cin >> hell;
		inaccurate_search search_w(hell, in);
		
		int j = 0;
		char* tmp;

		fin.open(name_file);
		
		do {
			cout << "Load file...\n";
			do
			{

				fin >> buff;
				ne_overfl = search_w.download(buff);
				f *= ne_overfl;
				f *= buff[0] != '\0';

			} while (f);

			cout << "File loaded!\n";

			start_time = clock();//---------------------------------------------------------------
			search_w.w_verification();
			end_time = clock();	//----------------------------------------------------------------

			cout <<time <<" time: " << end_time - start_time << " mlsec\n";
			all_time += end_time - start_time;
			time++;
			search_w.display_w();
		} while (!ne_overfl);
		tmp = NULL;
		cout << "all time: " <<all_time<< " mlsec\n";
		fin.close();
		
		
		all_time = 0;
	
		cout << endl << "would you like to continue? (y/...)";
		y = _getch();
		cout << endl;	
		if (y != 'y' && y != 'Y')
		{
			cout << "See you soon!";
			break;
		}
		system("cls");
	}

	
	
	
 	_getch();
	return 0;
}



















