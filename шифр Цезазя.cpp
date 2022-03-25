/*1. Носж Ызррср етзуеюз пгхзпгхлъзфнл фхусёс фчсупцолусего естусфю с хзсузхлъзфнсм фхсмнсфхл ылчусе.Г лпзррс, ргфнсоянс цфхсмълесм веовзхфв ылчуфлфхзпг жов косцпюыозррлнг, сдогжгбьзёс рзсёугрлъзррюпл узфцуфгпл (еузпзрзп, тгпвхяб л х.ж.) ?*/
/*2. Лхщюфн э гиьш тйн дхинжблы. */

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char smal[37] = "эюяабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	char big[37] = "ЭЮЯАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char buff[512];
	cout << "Введите шифр : ";
	cin.getline(buff, 512);
	cout << "Расшифровка : ";
	for (int i = 0; i < strlen(buff); i++) {
		for (int j = 3; j < 37; j++) {
			if (buff[i] == smal[j]) {
				buff[i] = smal[j - 3];
				break;
			}
			else {
				if (buff[i] == big[j]) {
					buff[i] = big[j - 3];
					break;
				}
			}
		}

	}
	cout << buff << endl;


	system("pause");
	return 0;
}
