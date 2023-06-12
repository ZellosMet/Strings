#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <Windows.h> //Библиотека для подключения Windows библиотек
using namespace std;

int StringLength(const char *str); //Подсчёт символов в строке
char* ToLower(char *str); //Переводит строку в нижний регистр
char* ToUpper(char *str); //Переводит строку в вержний регистр
char* Shrink(char *str); //Удаляет лишние пробелы из строки
bool IsPalindrome(const char *str); //Проверка на полиндром
bool IsIntNumber(const char *str); //Проверка на целое число
int ToIntNumber(char *str); //Возврат целого числа
bool IsBinNumber(const char *str); // Проверят на двоичное число 
long long ToBinNumber(char *str); // Переводит двоичное в десятичное
bool IsHexNumber(const char *str); // Проверят на шестнацеричное число число 
long long ToHexNumber(char *str); // Переводит шестнацеричное в десятичное
int Degree(int base, int deg); // Возведение в степень

void main()
{
	SetConsoleCP(1251); //Выставление русской кодировки для ввод
	SetConsoleOutputCP(1251); //Для вывода

	//Способы инициализации строк
	//char str[] = {'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	long long num = 0;
	const int SIZE = 256;
	char str[SIZE];
	//char str[SIZE] = "E8F"; //29
	//char str[SIZE] = "1001100101"; //613
	//char str[SIZE] = "Аргентина    манит неграа!";
	//char str[SIZE] = "лёша   на полке   клопа  нашёл"; // проверка на полиндром
	cout << "Введите строку: "; 
	cin.getline(str, SIZE); //Позволяет через cin вводить строки с пробелом и не позволяет выходить за пределы массива строки
	cout << ToLower(str) << endl;
	cout << ToUpper(str) << endl;
	cout << Shrink(str) << endl;
	(IsPalindrome(str)) ? cout << "Строка является полиндромом" << endl : cout << "Строка не является полиндромом" << endl;
	(IsIntNumber(str)) ? cout << "Строка является целым числом и преобразована в целочисленный тип: " << (num = ToIntNumber((str))) << endl : cout << "Строка не является числом\n";
	IsBinNumber(str) ? cout << "Строка является двоичным числом и преобразована в десятичное число " << (num = ToBinNumber(str)) << endl : cout << "Строка не является двоичным числом\n";
	IsHexNumber(str) ? cout << "Строка является шестнадцатиричным числом и преобразована в десятичное число " << (num = ToHexNumber(str)) << endl : cout << "Строка не является шестнадцатиричным числом\n";
}

int StringLength(const char *str)
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* ToLower(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'А' && str[i] <= 'Я') str[i] += 32;
		if (str[i] == 'Ё') str[i] -= 16;
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
	}
	return str;
}
char* ToUpper(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'а' && str[i] <= 'я') str[i] -= 32;
		if (str[i] == 'ё') str[i] += 16;
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
	}
	return str;
}
char* Shrink(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j] != 0; j++) str[j] = str[j + 1];
			i--;
		}
	}
	while (str[0] == ' ') for (int i = 0; str[i]; i++) str[i] = str[i + 1];
	return str;
}
bool IsPalindrome(const char *str)
{
	int cnt = 0;
	bool chek = true;

	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] >= 'а' && str[i] <= 'я' ||
			str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= 'А' && str[i] <= 'Я' ||
			str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= '0' && str[i] <= '9' ||
			str[i] == 'Ё' || str[i] == 'ё') cnt++;
	}

	char *buff = new char[cnt+1]{};
	buff[cnt] = 0;

	for (int i = 0, j = 0; str[i]; i++)
	{
		if (str[i] >= 'а' && str[i] <= 'я' ||
			str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= 'А' && str[i] <= 'Я' ||
			str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= '0' && str[i] <= '9' ||
			str[i] == 'Ё' || str[i] == 'ё')
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
	for (int i = 0; str[i]; i++) 
		if (str[i] < '0' || str[i] > '9') return false;
	return true;
}
int ToIntNumber(char* str)
{
	int num = 0;
	for (int i = 0; str[i]; i++)
	{
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}
int Degree(int base, int deg)
{
	int res = 1;
	if (deg == 0) return 1;
	for (int i = 1; i <= deg; i++) res = res * base;
	return res;
}
bool IsBinNumber(const char *str)
{
	for (int i = 0; str[i]; i++) 
		if (str[i] < '0' || str[i] > '1') return false;
	return true;
}
long long ToBinNumber(char *str)
{
	long long num = 0;
	for (int i = StringLength(str)-1, j=0; i>=0; i--, j++) if (str[i]=='1') num += Degree(2, j);
	return num;
}
bool IsHexNumber(const char* str)
{
	char* buff = new char [StringLength(str) + 1] {};
	ToUpper(buff);
	strcpy(buff, str);
	for (int i = 0; buff[i]; i++)
	{
		if ((buff[i] < '0' || buff[i] > '9') && (buff[i] < 'A' || buff[i] > 'F')) return false;
	}
	delete buff;
	return true;
}
long long ToHexNumber(char* str)
{
	long long num = 0;
	for (int i = StringLength(str) - 1, j = 0; i >= 0; i--, j++)
	{
		if (str[i] < '0' || str[i] > '9') num += ((str[i] - 55) * Degree(16, j));
		else num += (str[i] - '0') * Degree(16, j);
	}
	return num;
}