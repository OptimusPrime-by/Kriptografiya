#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;
vector<int> Fact(int a) {
        vector<int> number;
        bool flag = true;
        int p = 2;
        while (flag) {
            if (a % p == 0) {
                number.push_back(p);
                a /= p;
            }
            else {
                p++;
            }
            if (a == 1) {
                flag = false;
            }
        }
	return number;
}

int main() {
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
    vector<int>FactA, FactB;
    FactA = Fact(a);
    FactB = Fact(b);
    int NOD = 1;
    vector<int> buf;
    int i, j;
        for ( i = 0; i < FactA.size(); i++) {
            for ( j = 0; j < FactB.size(); j++) {
                if (FactA[i] == FactB[j]) {
                    NOD *= FactA[i];
                    i++;
                    if (i == FactA.size()) {
                        break;
                    }
                }
                else {
                    buf.push_back(FactB[j]);
                }
            }
            FactB = buf;
            buf.clear();
        }
    
    cout << "НОД этих чисел равен " << NOD << endl;
	system("pause");
	return 0;
}