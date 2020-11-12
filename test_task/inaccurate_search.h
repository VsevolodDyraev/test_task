#pragma once
#include<string>

const int MAX_SIZE_W_SEARCH = 100;

class inaccurate_search
{
	char* w_search; //слово, по которому идет поиск
	char* null_ch;  //тип возвращает '\0'
	int len_search; //длинна слова
	int index_w;	//индекс, по которому мы ходим по слову
	bool err_w;		//ошибка разных символов

	
	char** words;
	int i_w;
	
	
	unsigned long int cardinality;
	const int number_characters = 100;
	unsigned int right_index;

public:
	//inaccurate_search();				//создание объекта
	inaccurate_search(const char*,unsigned long int);		//создание объекта со объекта с искомым словом
	~inaccurate_search();				//деструктор
	void w_verification();		//основной алгоритм
	char* return_word();				//возвращение слова, по которуму ищут 
	void change_word(const char*);		//смена слова
	bool download(const char*);	
	void display_w();
};



