#include <iostream>
#include <windows.h>
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
    vector<int> ans= { 1,0 };
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
    vector<int>ans;
    ans = Bezu(a, b);
    cout << a << " * " << ans[0] << " + " << b << " * " << ans[1] << " = " << NOD(a, b) << endl;
    system("pause");
    return 0;
}

