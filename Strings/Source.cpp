#include<iostream>
#include <Windows.h> //���������� ��� ����������� Windows ���������
using namespace std;

int StringLength(const char *str);

void main()
{
	//setlocale(LC_ALL, "ru");
	SetConsoleCP(1251); //����������� ������� ��������� ��� ����
	SetConsoleOutputCP(1251); //��� ������

	//������� ���������� �����
	//char str[] = {'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "������� ������: "; 
	//cin >> str;
	cin.getline(str, SIZE); //��������� ����� cin ������� ������ � �������� � �� ��������� �������� �� ������� �������
	cout << str << endl;
	cout << "������ �������� ������: " << StringLength(str) << endl;
}

int StringLength(const char *str)
{
	int cnt=0;
	while (str[cnt]!='\0') cnt++;
	return cnt;
}