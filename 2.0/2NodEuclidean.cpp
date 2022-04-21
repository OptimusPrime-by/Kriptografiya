#include <iostream>
#include <windows.h>

using namespace std;

int NOD(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        }
        else{
            b %= a;
        }
        
    }
    return a | b;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b;
    cout << "Введите числа a и b: ";
start:
    cin >> a >> b;
    if (a <= 0 || b <= 0) {
        system("cls");
        cout << "Введены не натуральные числа. Введте заново.";
        cin.clear(1000);
        cin.ignore();
        goto start;
    }

    cout << "НОД этих чисел равен " << NOD(a,b) << endl;
    system("pause");
    return 0;
}

