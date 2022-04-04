#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

bool simple(int a) {
    bool flag = true;
    int p = 2;
    while (flag) {
        if (a % p == 0 && a!=p) {
            return false;
        }
        p++;
        if (a == p) {
            flag = false;
        }
    }
    return true;
}

bool powsimple(int a) {
    bool flag = true;
    int p = 2;
    vector<int> num;
    while (flag) {
        if (a % p == 0) {
            num.push_back(p);
            a /= p;
        }
        else {
            p++;
        }
        if (a == 1) {
            flag = false;
        }
        
    }
    for (int i = 1; i < num.size(); i++) {
        if (num[0] != num[i]) {
            return false;
        }
    }
    return true;
}

int getPow(int a) {
    bool flag = true;
    int p = 2;
    vector<int> num;
    while (flag) {
        if (a % p == 0) {
            num.push_back(p);
            a /= p;
        }
        else {
            p++;
        }
        if (a == 1) {
            flag = false;
        }

    }
    vector<int> ans;
    ans.push_back(p);
    ans.push_back(num.size());
    int answ;
    answ = (ans[0] - 1) * (pow(ans[0], ans[1] - 1));
    return answ;
}

int Case3(int a) {
    bool flag = true;
    int p = 2;
    vector<int> num;
    while (flag) {
        if (a % p == 0) {
            num.push_back(p);
            a /= p;
        }
        else {
            p++;
        }
        if (a == 1) {
            flag = false;
        }
    }
    int ans=1;
    int pow1=1;
    int prev = 0;
    for (int i = 1; i < num.size(); i++) {
        if (num[prev] != num[i]) {
            ans *= getPow(pow(num[prev], pow1));
            prev = i;
            pow1 = 1;
        }
        else {
            pow1++;
        }
    }
    ans *= getPow(pow(num[prev], pow1));
    return ans;
}
int Case4(int a) {
    bool flag = true;
    int p = 2;
     double ans = a;
    vector<int> num;
    while (flag) {
        if (a % p == 0) {
            num.push_back(p);
            a /= p;
        }
        else {
            p++;
        }
        if (a == 1) {
            flag = false;
        }
    }
    int prev = 0;
    double buf;
    for (int i = 1; i < num.size(); i++) {
        if (num[prev] != num[i]) {
            buf=(1.0 - (1.0 / num[prev]));
            ans *= buf;
            prev = i;
        }
        else {

        }
    }
    buf = (1.0 - (1.0 / num[prev]));
    ans *= buf;
    return (int)ans;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n,x;
    cout << "Введите натуральное число ";
start:
    cin >> n;
    if (n < 1) {
        cout << "Введено неверное число" << endl;
        cin.clear(1000);
        cin.ignore();
        goto start;
    }
    if (n == 1) {
        cout << "Функция Эйлера от 1 равна 1" << endl;
        system("pause");
        return 0;
    }
    cout << "Введите номер свойства(1-4) ";
    start2:
    cin >> x;
    if (x > 4 || x < 1) {
        cout << "Введено неверное число" << endl;
        cin.clear(1000);
        cin.ignore();
        goto start2;
    }
    switch (x) {
    case 1:
        if (!simple(n)) {
            cout << "Введено не простое число " << endl;
        }
        else {
            cout << "Функция Эйлера от числа " << n << " равна " << n - 1 << endl;
        }
        break;
    case 2:
        if (!powsimple(n)) {
            cout << "Введена не степень простого числa " << endl;
        }
        else {
            cout << "Функция Эйлера от числа " << n << " равна " << getPow(n) << endl;
        }
        break;
    case 3:
        cout << "Функция Эйлера от числа " << n << " равна " << Case3(n) << endl;
        break;
    case 4:
        cout << "Функция Эйлера от числа " << n << " равна " << Case4(n) << endl;
        break;
    }
    system("pause");
    return 0;
}