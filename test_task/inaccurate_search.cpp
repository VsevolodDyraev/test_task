#include"inaccurate_search.h"
#include <iostream>
#include<fstream>

using namespace std;



void inaccurate_search::change_word(const char* ch)
{
	if (w_search != nullptr)
	{
		delete[]w_search;
		len_search = strlen(ch);
		w_search = new char[len_search + 1];
		strcpy(w_search, ch);
	}
}

//создание объекта со объекта с искомым словом
inaccurate_search::inaccurate_search(const char* ch, unsigned long int inc) :index_w(0), err_w(false), cardinality(inc), right_index(0)
{
	//cardinality = 

	null_ch = new char[1];
	null_ch[0] = '\0';
	len_search = strlen(ch);

	w_search = new char[len_search + 1];
	strcpy(w_search, ch);

	i_w = 0;
	words = new char* [cardinality];
	char* temp = new char[cardinality * number_characters];
	for (int i = 0; i < cardinality; i++)
	{
		words[i] = temp + i * number_characters;
	}

	for (int i = 0; i < cardinality; i++)
		for (int j = 0; j < number_characters; j++)
			words[i][j] = '\0';



}

//деструктор
inaccurate_search::~inaccurate_search()
{
	delete[]w_search;
	delete null_ch;
	delete[]words[0];
	delete[]words;
}

//возвращение слова, по которуму ищут 
char* inaccurate_search::return_word()
{
	return w_search;
}

//основной алгоритм
void inaccurate_search::w_verification()
{
	bool return_f = false;
	unsigned int write_index = 0;

	for (int j = 0; j < i_w; j++)
	{
		index_w = 0;
		return_f = false;
		err_w = false;

		switch (words[j][0])
		{
		case 'f':
		{
			for (int i = 1; i < len_search; i++)
			{
				if (words[j][i] != w_search[index_w])
				{
					if (/*words[j][i] != w_search[++index_w] ||*/ err_w)
					{
						return_f = true;
						break;
					}
					err_w = true;
					++index_w;
					i--;
				}
				else
					index_w++;
			}
			if (return_f == false)
			{
				for (int i = 0; i < len_search - 1; i++)
				{
					words[write_index][i] = words[j][i + 1];
				}
				words[write_index][len_search - 1] = '\0';
				//strcpy_s(words[write_index], 100, words[j]);
				write_index++;
				break;
			}
			break;
		}
		case 's':
		{
			for (int i = 1; i < len_search + 2; i++)
			{
				if (words[j][i] != w_search[index_w])
				{
					if (err_w)
					{
						return_f = true;
						break;
					}
					err_w = true;

					//if (index_w < len_search)
					//{
					//	if (words[j][i] == w_search[index_w + 1])
					//	{
					//		return_f = true;
					//		break;
					//	}
					//}
				}
				else
					index_w++;
			}
			if (return_f == false)
			{
				for (int i = 0; i < len_search + 1; i++)
				{
					words[write_index][i] = words[j][i + 1];
				}
				words[write_index][len_search + 1] = '\0';
				//strcpy_s(words[write_index], 100, words[j]);
				write_index++;
				char* q = words[write_index];
				break;
			}
			break;
		}
		case 't':
		{
			for (int i = 1; i < len_search + 1; i++)
			{
				if (words[j][i] != w_search[index_w])
				{
					//if (words[j][i] == w_search[index_w + 1])
					//{
					//	return_f = true;
					//	break;
					//}
					if (err_w)
					{
						return_f = true;
						break;
					}
					err_w = true;
					index_w++;
				}
				else
					index_w++;
			}
			if (return_f == false)
			{
				for (int i = 0; i < len_search; i++)
				{
					words[write_index][i] = words[j][i + 1];
				}
				words[write_index][len_search] = '\0';
				//strcpy_s(words[write_index], 100, words[j]);
				char* q = words[write_index];
				write_index++;
				break;
			}
			break;
		}

		default:
		{
			continue;
		}
		}
	}

	words[write_index][0] = '\0';

}


bool inaccurate_search::download(const char* ch)
{

	if (i_w == cardinality)
	{
		std::cout << "error:owerflow\n";
		return false;
	}

	int len_ch = strlen(ch);
	int i = 0;

	switch (len_search - len_ch)
	{
	case 1:
	{
		words[i_w][0] = 'f';
		while (ch[i])
		{
			words[i_w][i + 1] = ch[i];
			i++;
		}
		i_w++;
		if (i_w < cardinality - 1)
			return true;
		return false;
	}
	case -1:
	{
		words[i_w][0] = 's';
		while (ch[i])
		{
			words[i_w][i + 1] = ch[i];
			i++;
		}
		i_w++;
		if (i_w < cardinality - 1)
			return true;
		return false;
	}
	case 0:
	{
		words[i_w][0] = 't';
		while (ch[i])
		{
			words[i_w][i + 1] = ch[i];
			i++;
		}
		i_w++;
		if (i_w < cardinality - 1)
			return true;
		return false;
	}
	default:
		return true;
	}

	return false;

}

void inaccurate_search::display_w()
{
	ofstream fout;
	fout.open("result.txt");

	for (int i = 0; i < cardinality; i++)
	{
		if (words[i][0])
			fout << words[i] << "; ";
		else
			break;
	}

	fout.close();
}