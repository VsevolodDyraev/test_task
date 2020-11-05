#include"inaccurate_search.h"

inaccurate_search::inaccurate_search() :index_w(0), err_w(false)
{
	null_ch = new char;
	*null_ch = '\0';
	len_search = 2;
	w_search = new char[2];
	for (int i = 0; i < 2; i++)
	{
		w_search[i] = ' ';
	}
}

void inaccurate_search::change_word(const char* ch)
{
	if (w_search != nullptr)
	{
		delete[]w_search;
		len_search = strlen(ch);
		w_search = new char[len_search + 1];
		strcpy_s(w_search, sizeof(char) * len_search + 1, ch);
	}
}

//создание объекта со объекта с искомым словом
inaccurate_search::inaccurate_search(const char* ch) :index_w(0), err_w(false)
{
	null_ch = new char;
	*null_ch = '\0';
	len_search = strlen(ch);
	w_search = new char[len_search + 1];
	strcpy_s(w_search, sizeof(char) * len_search + 1, ch);
}

//деструктор
inaccurate_search::~inaccurate_search()
{
	delete[]w_search;
	delete null_ch;
}

//возвращение слова, по которуму ищут 
char* inaccurate_search::return_word()
{
	return w_search;
}

//основной алгоритм
char* inaccurate_search::w_verification(char* ch)
{
	index_w = 0;
	err_w = false;
	int len_ch = strlen(ch);
	switch (len_search - len_ch)
	{
	case -1:
	{
		for (int i = 0; i < len_ch; i++)
		{
			if (ch[i] != w_search[index_w])
			{
				if (err_w)
					return null_ch;
				err_w = true;

				if (index_w < 4)
				{
					if (ch[i] == w_search[index_w + 1])
						return null_ch;
				}
			}
			else
				index_w++;
		}
		return ch;
	}
	case 1:
	{
		for (int i = 0; i < len_ch; i++)
		{
			if (ch[i] != w_search[index_w])
			{
				char q = ch[i];
				char s = w_search[index_w];
				if (ch[i] != w_search[++index_w] || err_w)
					return null_ch;
				err_w = true;
				++index_w;
			}
			else
				index_w++;
		}
		return ch;
	}
	case 0:
	{
		for (int i = 0; i < len_ch; i++)
		{
			if (ch[i] != w_search[index_w])
			{
				if (ch[i] == w_search[index_w + 1])
					return null_ch;
				if (err_w)
					return null_ch;
				err_w = true;
				index_w++;
			}
			else
				index_w++;
		}
		return ch;
	}

	default:
	{
		return null_ch;

	}
	}
}


