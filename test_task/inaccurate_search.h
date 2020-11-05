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
	

public:
	inaccurate_search();				//создание объекта
	inaccurate_search(const char*);		//создание объекта со объекта с искомым словом
	~inaccurate_search();				//деструктор
	char* w_verification(char*);	//основной алгоритм
	char* return_word();				//возвращение слова, по которуму ищут 
	void change_word(const char* ch);	//смена слова
};



