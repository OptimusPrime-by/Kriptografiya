#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

int NOD(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }

    }
    return a | b;
}

vector<int> Bezu(int a, int b) {
    vector<int> ans = { 1,0 };
    int r = b;
    int u0, u1, u2, v0, v1, v2;
    u0 = 1; v0 = 0; u1 = 0; v1 = 1; u2 = 0; v2 = 1;
    while ((a % b) != 0) {
        u2 = u0 - (a / b) * u1;
        v2 = v0 - (a / b) * v1;
        v0 = v1;
        u0 = u1;
        v1 = v2;
        u1 = u2;
        r = a % b;
        a = b;
        b = r;
        ans[0] = u2;
        ans[1] = v2;
    }
    return ans;
}

int InverseClass(int a, int m) {
    for (int i = 0; i < m; i++) {
        if ((i * a) % m == 1) {
            return i;
        }
    }
}

int InverseBezu(int a, int m) {
    vector<int> ans = Bezu(a, m);
    while(ans[0] < 0) {
        ans[0] += m;
    }
    if (ans[0] >= m) {
        ans[0] %= m;

    }
    return ans[0];
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m,n;
    cout << "Введите модуль ";
start:
    cin >> m;
    if (m < 2) {
        system("cls");
        cout << "Введено неверное число" << endl;
        cin.clear(1000);
        cin.ignore();
        goto start;
    }
    cout << "Введите элемент класса ";
    cin >> n;
    n %= m;
    if (NOD(n, m) != 1) {
        cout << "Элемент " << n << " не обратим в кольце классов вычетов по модулю " << m << endl;
        system("pause");
        return 0;
    }
    cout << "Обратный элемент по первому способу " << InverseClass(n, m) << endl;
    cout << "Обратный элемент по второму способу " << InverseBezu(n, m) << endl;
    system("pause");
    return 0;
}
