#include <iostream>
#include <Windows.h>

using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char msg[256];
	cout << "Введите сообщение " << endl;
	cin.getline(msg, 256);
	cout <<"Введите размерность: " << strlen(msg) << endl;

	int row, col;
	cout << endl << "Введите ключ" << endl;
	cin >> row; cin >> col;
	if (row * col != strlen(msg)) {
		cout << endl << "Неверный ключ" << endl;
		system("pause");
		return 0;
	}

	char** mas = new char* [row];
	for (int i = 0; i < row; i++) {
		mas[i] = new char[col];
	}

	int k = 0;
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			mas[i][j] = msg[k];
			k++;
			cout << mas[i][j];
		}
		cout << endl;

	}
	k = 0;
	for (int j = 0; j < col; j++) {

		for (int i = 0; i < row; i++) {
			msg[k] = mas[i][j];
			k++;
		}

	}
	cout << endl << "Полученное зашифрованное сообщение: " << endl << msg << endl;
	//расшифровка
	cout << endl << "Введите ключ расшифровки" << endl;
	cin >> row; cin >> col;
	if (row * col != strlen(msg)) {
		cout << endl << "Неверный ключ" << endl;
		system("pause");
		return 0;
	}
	char** m = new char* [row];
	for (int i = 0; i < row; i++) {
		m[i] = new char[col];
	}


	k = 0;

	for (int j = 0; j < col; j++) {

		for (int i = 0; i < row; i++) {
			m[i][j] = msg[k];
			k++;

		}

	}
	

	k = 0;
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
				msg[k] = m[i][j];
			k++;
		}

	}
	cout << endl << "Полученное расшифрованное сообщение: " << endl << msg << endl;

	system("pause");
	return 0;
}
