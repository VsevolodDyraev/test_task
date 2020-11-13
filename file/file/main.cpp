#include <fstream>
#include <iostream>
#include<string.h>
#include<conio.h>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "how many values need to be generated? : ";
    unsigned long long int how_many;
    cin >> how_many;

    
    char* ch = new char[100];
    for (int z = 0; z < 100; z++)
    {
        ch[z] = ' ';
    }

    char z = ' ';
    ofstream fout;          // поток для записи
    
    fout.open("I:\\coding\\c++\\work\\test_my_brain\\test_my_brain\\test_my_brain\\file.txt"); // окрываем файл для записи
    if (fout.is_open())
       
    {
       for (int i = 0; i < how_many;i++)
       {
           int numb = 1 + rand() % 10;
           for (int j = 0; j < numb; j++)
           {
               z = 97 + rand() % 25;
               ch[j] = z;
           }
           ch[numb] = '\0';
           fout << ch<<endl;
           for (int z = 0; z < 100; z++)
           {
               ch[z] = ' ';
           }

       }
    }

    delete[] ch;
    std::cout << "End of program" << std::endl;
    return 0;
    


    //char* ch = new char[100];
    //
    //strcpy_s(ch,sizeof(char)*100 ,"Hello world");
    //
    //int z = strlen(ch);
    //
    //for (int i = 0; i < strlen(ch); i++)
    //    cout << ch[i];

    //setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    //char buff[50]; // буфер промежуточного хранения считываемого из файла текста
    //ifstream fin("cppstudio.txt"); // открыли файл для чтения
    //
    //fin >> buff; // считали первое слово из файла
    //cout << buff << endl; // напечатали это слово
    //
    //fin >> buff; // считали первое слово из файла
    //cout << buff << endl; // напечатали это слово
    //
    //fin >> buff; // считали первое слово из файла
    //cout << buff << endl; // напечатали это слово
    //
    //
    //fin >> buff; // считали первое слово из файла
    //cout << buff << endl; // напечатали это слово
    //
    //fin.close(); // закрываем файлу
    //
    //system("pause");
    return 0;
}