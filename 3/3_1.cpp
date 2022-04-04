#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m;
    cout << "Введите модуль ";
    start:
    cin >> m;
    if (m < 2) {
        cout << "Введено неверное число" << endl;
        cin.clear(1000);
        cin.ignore();
        goto start;
    }
    int** plus = new int* [m+1];
    for (int i = 0; i < m+1; i++) {
        plus[i] = new int[m+1];
    }
    int** mult = new int* [m+1];
    for (int i = 0; i < m+1; i++) {
        mult[i] = new int[m+1];
    }
    int count = 0;
    plus[0][0] = 0;
    mult[0][0] = 0;
    for (int i = 1; i < m + 1; i++) {
        mult[0][i] = count;
        mult[i][0] = count;
        plus[0][i] = count;
        plus[i][0] = count;
        count++;
    }
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            plus[i][j] = (plus[i][0] + plus[0][j])%m;
            mult[i][j] = (plus[i][0] * plus[0][j]) % m;
        }
    }

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            cout <<' '<< plus[i][j] << " ";
        }
        cout << endl ;
    }
    cout << endl << endl;
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            cout<<' ' << mult[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
