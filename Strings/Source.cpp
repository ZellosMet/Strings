#include<iostream>
#include <Windows.h> //Библиотека для подключения Windows библиотек
using namespace std;

int StringLength(const char *str);

void main()
{
	//setlocale(LC_ALL, "ru");
	SetConsoleCP(1251); //Выставление русской кодировки для ввод
	SetConsoleOutputCP(1251); //Для вывода

	//Способы объявления строк
	//char str[] = {'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: "; 
	//cin >> str;
	cin.getline(str, SIZE); //позволяет через cin вводить строки с пробелом и не позволяет выходить за пределы массива
	cout << str << endl;
	cout << "Размер введённой строки: " << StringLength(str) << endl;
}

int StringLength(const char *str)
{
	int cnt=0;
	while (str[cnt]!='\0') cnt++;
	return cnt;
}