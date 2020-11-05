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
	char y;
	string name_file;
	const int MAX_SIZE_WORD = 100;
	unsigned long long int all_time = 0;
	
	
	char* buff = new char[MAX_SIZE_WORD];
	for (int i = 0; i < MAX_SIZE_WORD; i++)
		buff[i] = ' ';
	
	ifstream fin;
	ofstream fout;
	int start_time;	
	char* hell = new char[MAX_SIZE_WORD];
	inaccurate_search search_w(hell);
	

	while (1)
	{	
		cout << "enter name file: ";
		cin >> name_file;
		fin.open(name_file);
		fout.open("result.txt");
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

		cout << "Enter serch word: ";
		cin >> hell;
		search_w.change_word(hell);
		
		int j = 0;
		char* tmp;
	
		do
		{
			start_time = clock();//---------------------------------------------------------------
			fin >> buff;
			tmp = search_w.w_verification(buff);
			unsigned long long int end_time = clock();//-------------------------------------------------
			all_time += end_time - start_time;


			if(*tmp)
				fout << tmp << "; ";
	
		} while (buff[0]);

		tmp = NULL;
		cout << "time: " <<all_time<< " mlsec";
		fin.close();
		fout.close();
		
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
























