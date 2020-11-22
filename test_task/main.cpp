#include<conio.h>
#include<iostream>
#include<time.h>
#include<fstream>
#include<Windows.h>
#include<string>
#include"inaccurate_search.h"
#include<thread>

using namespace std;

int main()
{
	/*auto ch_tmp = chrono::high_resolution_clock::now();
	chrono::duration<float> all_time =  ch_tmp;*/

	char y;
	string name_file;
	const int MAX_SIZE_WORD = 100;


	char* buff = new char[MAX_SIZE_WORD];
	for (int i = 0; i < MAX_SIZE_WORD; i++)
		buff[i] = ' ';


	ifstream fin;

	float all_time = 0.0f;

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
			y = getchar();
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
		unsigned long long int size = 0;
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
			f = true;
			cout << "Load file...\n";
			do
			{
				fin >> buff;
				ne_overfl = search_w.download(buff);
				f *= ne_overfl;
				f *= buff[0] != '\0';
			} while (f);



			cout << "File loaded!\n";

			auto start = chrono::high_resolution_clock::now();//---------------------------------------------------------------
			search_w.w_verification();
			auto end = chrono::high_resolution_clock::now();	//----------------------------------------------------------------

			chrono::duration<float> duration = end-start;

			cout << time << " time: " << duration.count() << " sec\n";
			all_time += duration.count();
			time++;
			search_w.display_w();
			search_w.i_w_is_zero();

		} while (!ne_overfl);
		tmp = NULL;
		cout << "all time: " << all_time << " sec\n";
		fin.close();


		//all_time = 0;

		cout << endl << "would you like to continue? (y/...)";
		y = getchar();
		cout << endl;
		if (y != 'y' && y != 'Y')
		{
			cout << "See you soon!";
			break;
		}
		system("cls");
	}




	getchar();
	return 0;
}



















