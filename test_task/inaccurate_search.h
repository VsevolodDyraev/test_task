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
	

public:
	inaccurate_search();				//�������� �������
	inaccurate_search(const char*);		//�������� ������� �� ������� � ������� ������
	~inaccurate_search();				//����������
	char* w_verification(char*);	//�������� ��������
	char* return_word();				//����������� �����, �� �������� ���� 
	void change_word(const char* ch);	//����� �����
};



