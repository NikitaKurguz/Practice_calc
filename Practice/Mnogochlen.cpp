#include <iostream>
#include "mnogochleni.h"
using namespace std;
void run_calc()
{
	int n;
	cout << "����������� �����������." << endl;
	while (1)
	{
		cout << "'b' - ������� � ������� ����" << endl;
		cout << "1 - �������� �����������" << endl;
		cout << "2 - ��������� �����������" << endl;
		cout << "3 - ��������� ���������� �� �����" << endl;
		cout << "4 - ���������� ����������� �� ����������" << endl;
		cout << "5 - ������� ����������� � �������" << endl;
		cout << "�������� ����� ������������: "; cin >> n;
		if (n > 0 && n <= 5) break;
	}
}