#include<iostream>
#include <Windows.h> //Библиотека для подключения Windows библиотек
using namespace std;

#define StartUpWordRu -64
#define EndUpWordRu -33
#define StartLowWordRu -32
#define EndLowWordRu -1
#define UpERu -88
#define LoweRu -72
#define DifferenceE 16
#define StartUpWordEng 65
#define EndUpWordEng 90
#define StartLowWordEng 97
#define EndLowWordEng 122
#define DifferenceWord 32
#define Space 32
#define StartNum 48
#define EndNum 57

int StringLength(const char *str); //Подсчёт символов в строке
void ToLower(char *str); //Переводит строку в нижний регистр
void ToUpper(char *str); //Переводит строку в вержний регистр
void Shrink(char *str); //Удаляет лишние пробелы из строки
bool IsPalindrome(const char *str); //Проверка на полиндром
bool IsIntNumber(const char *str); //Проверка на целое число
int ToIntNumber(char *str); //Возврат целого числа

void main()
{
	SetConsoleCP(1251); //Выставление русской кодировки для ввод
	SetConsoleOutputCP(1251); //Для вывода

	//Способы инициализации строк
	//char str[] = {'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	int num = 0;
	const int SIZE = 256;
	char str[SIZE] = {};
	//char str[SIZE] = "лёша   на полке   клопа  нашёл"; // проверка на полиндром
	cout << "Введите строку: "; 
	cin.getline(str, SIZE); //Позволяет через cin вводить строки с пробелом и не позволяет выходить за пределы массива строки
	ToLower(str);
	cout << str << endl;
	ToUpper(str);
	cout << str << endl;
	Shrink(str);
	cout << str << endl;
	(IsPalindrome(str)) ? cout << "Строка является полиндромом" << endl : cout << "Строка не является полиндромом" << endl;
	(IsIntNumber(str)) ? cout << "Строка является целым числом и вреобразована в целочисленный тип: " << (num = ToIntNumber((str))) : cout << "Строка не является числом";
}

int StringLength(const char *str)
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void ToLower(char *str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] >= StartUpWordRu && str[i] <= EndUpWordRu) str[i] += DifferenceWord;
		if (str[i] == LoweRu) str[i] -= DifferenceE;
		if (str[i] >= StartUpWordEng && str[i] <= EndUpWordEng) str[i] += DifferenceWord;
	}
}
void ToUpper(char *str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] >= StartLowWordRu && str[i] <= EndLowWordRu) str[i] -= DifferenceWord;
		if (str[i] == UpERu) str[i] += DifferenceE;
		if (str[i] >= StartLowWordEng && str[i] <= EndLowWordEng) str[i] -= DifferenceWord;
	}
}
void Shrink(char *str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] == Space && str[i+1] == Space)
		{
			for (int j = i; str[j] != 0; j++) str[j] = str[j + 1];
			i--;
		}
	}
}
bool IsPalindrome(const char *str)
{
	int cnt = 0;
	bool chek = true;

	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] >= StartLowWordRu && str[i] <= EndLowWordRu ||
			str[i] >= StartLowWordEng && str[i] <= EndLowWordEng ||
			str[i] >= StartUpWordRu && str[i] <= EndUpWordRu ||
			str[i] >= StartUpWordEng && str[i] <= EndUpWordEng ||
			str[i] >= StartNum && str[i] <= EndNum ||
			str[i] == UpERu || str[i] == LoweRu) cnt++;
	}

	char *buff = new char[cnt+1]{};
	buff[cnt] = 0;

	for (int i = 0, j = 0; str[i] != 0; i++)
	{
		if (str[i] >= StartLowWordRu && str[i] <= EndLowWordRu ||
			str[i] >= StartLowWordEng && str[i] <= EndLowWordEng ||
			str[i] >= StartUpWordRu && str[i] <= EndUpWordRu ||
			str[i] >= StartUpWordEng && str[i] <= EndUpWordEng ||
			str[i] >= StartNum && str[i] <= EndNum ||
			str[i] == UpERu || str[i] == LoweRu)
			{
				buff[j] = str[i];
				j++;
			}
	}
	for (int i = 0, j = cnt - 1; i <= cnt - 1; i++, j--)
	{
		if ( buff[i] != buff[j])
		{
			chek = false;
			break;
		}
	}
	delete[] buff;
	return chek;
}
bool IsIntNumber(const char* str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] < 0 || str[i] > EndNum) return false;	
	}
	return true;
}
int ToIntNumber(char* str)
{
	int num = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		num *= 10;
		num += str[i] - StartNum;
	}
	return num;
}