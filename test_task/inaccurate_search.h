#pragma once
#include<string>

const int MAX_SIZE_W_SEARCH = 100;

class inaccurate_search
{
	char* w_search; //�����, �� �������� ���� �����
	char* null_ch;  //��� ���������� '\0'
	int len_search; //������ �����
	int index_w;	//������, �� �������� �� ����� �� �����
	bool err_w;		//������ ������ ��������

	
	char** words;
	int i_w;
	
	
	unsigned long int cardinality;
	const int number_characters = 100;
	unsigned int right_index;

public:
	//inaccurate_search();				//�������� �������
	inaccurate_search(const char*,unsigned long int);		//�������� ������� �� ������� � ������� ������
	~inaccurate_search();				//����������
	void w_verification();		//�������� ��������
	char* return_word();				//����������� �����, �� �������� ���� 
	void change_word(const char*);		//����� �����
	bool download(const char*);	
	void display_w();
};



