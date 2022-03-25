#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char smal[67] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char buff[256], code[256];
	int num = 0, k, l;
	cout << "Введите шифр : ";
	cin.getline(buff, 256);
	cout << "Введите код-слово : ";
	cin >> code;
	cout << "Расшифровка : ";
	for (int i = 0; i < strlen(buff); i++) {
		for (int j = 0; j < 67; j++) {
			if (buff[i] == smal[j]) {
				l = j;
				for (int j = 0; j < 67; j++) {
					num %= strlen(code);
					if (code[num] == smal[j]) {
						k = j;
						if (l - k < 0)
							buff[i] = smal[l - k + 33];
						else
							buff[i] = smal[l - k];
						num++;
						break;
					}
				}
				break;
			}
		}
	}


	cout << buff << endl;


	system("pause");
	return 0;
}



/*
num %= strlen(code);
for (int j = 0; j < 33; j++) {
	if (code[num] == smal[j]) {
		k = j;
		break;
	}
}
for (int j = 0; j < 33; j++) {
	if (buff[i] == smal[j]) {
		l=j;
		break;
	}
}
*/