#include<iostream>
#include <Windows.h> //Библиотека для подключения Windows библиотек
using namespace std;

#define StartNum 48
#define EndNum 57

int StringLength(const char *str); //Подсчёт символов в строке
char* ToLower(char *str); //Переводит строку в нижний регистр
char* ToUpper(char *str); //Переводит строку в вержний регистр
char* Shrink(char *str); //Удаляет лишние пробелы из строки
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
	//char str[SIZE] = "Аргентина    манит неграа!";
	char str[SIZE] = "0123456789";	
	//char str[SIZE] = "лёша   на полке   клопа  нашёл"; // проверка на полиндром
	//cout << "Введите строку: "; 
	//cin.getline(str, SIZE); //Позволяет через cin вводить строки с пробелом и не позволяет выходить за пределы массива строки
	cout << ToLower(str) << endl;
	cout << ToUpper(str) << endl;
	cout << Shrink(str) << endl;
	(IsPalindrome(str)) ? cout << "Строка является полиндромом" << endl : cout << "Строка не является полиндромом" << endl;
	(IsIntNumber(str)) ? cout << "Строка является целым числом и преобразована в целочисленный тип: " << (num = ToIntNumber((str))) : cout << "Строка не является числом";
}

int StringLength(const char *str)
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* ToLower(char *str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] >= 'А' && str[i] <= 'Я') str[i] += 32;
		if (str[i] == 'Ё') str[i] -= 16;
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
	}
	return str;
}
char* ToUpper(char *str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] >= 'а' && str[i] <= 'я') str[i] -= 32;
		if (str[i] == 'ё') str[i] += 16;
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
	}
	return str;
}
char* Shrink(char *str)
{
	for (int i = 0; str[i] != 0; i++)
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

	for (int i = 0, j = 0; str[i] != 0; i++)
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
	for (int i = 0; str[i] != 0; i++) 
		if (str[i] < '0' || str[i] > '9') return false;
	return true;
}
int ToIntNumber(char* str)
{
	int num = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}