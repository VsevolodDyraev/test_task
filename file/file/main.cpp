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
    ofstream fout;          // ����� ��� ������
    
    fout.open("I:\\coding\\c++\\work\\test_my_brain\\test_my_brain\\test_my_brain\\file.txt"); // �������� ���� ��� ������
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

    //setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
    //char buff[50]; // ����� �������������� �������� ������������ �� ����� ������
    //ifstream fin("cppstudio.txt"); // ������� ���� ��� ������
    //
    //fin >> buff; // ������� ������ ����� �� �����
    //cout << buff << endl; // ���������� ��� �����
    //
    //fin >> buff; // ������� ������ ����� �� �����
    //cout << buff << endl; // ���������� ��� �����
    //
    //fin >> buff; // ������� ������ ����� �� �����
    //cout << buff << endl; // ���������� ��� �����
    //
    //
    //fin >> buff; // ������� ������ ����� �� �����
    //cout << buff << endl; // ���������� ��� �����
    //
    //fin.close(); // ��������� �����
    //
    //system("pause");
    return 0;
}