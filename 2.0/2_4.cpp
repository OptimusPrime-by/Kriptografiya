#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

int Degree1(int a, int m, int n) {
    int ost=1;
    vector<int> binM1;
    int x;
    while (m) {
        if (m != 1) {
            x = m % 2;
            binM1.push_back(x);
            m /= 2;
        }
        else {
            binM1.push_back(1);
            m = 0;
        }
    }
    vector<int> k;
    for (int i = 0; i < binM1.size(); i++) {
        if (binM1[i] == 1) {
            k.push_back(i);
        }
    }
    bool flag = true;
    vector<int> ans;
    int p;
    p = pow(2,0);
    x = pow(a, p); 
    x %= n;
    ans.push_back(x);
    int count = 0;
        while (flag) {
            x = (x * x) % n;
            ans.push_back(x);
            count++;
            if (count == k[k.size() - 1]) {
                flag = false;
            }
        }
        for (int i = 0; i < k.size(); i++) {
            ost *= ans[k[i]];
            ost %= n;
        }
    ost %= n;
    return ost;
}

int Degree2(int a, int m, int n) {
    int ost=1;
    vector<int> s;
    s.push_back(m);
    while (m) {
        if (m % 2 == 0) {
            s.push_back(m / 2);
            m /= 2;
        }
        else {
            s.push_back((m - 1) / 2);
            m = (m - 1) / 2;
        }
    }
    vector<int> ans;
    int x, y;
    int i = s.size() - 2;
    x = pow(a, s[i]);
    y = x % n;
    i--;
    while (true) {
        if (s[i] % 2 == 0) {
            y = y * y;
            y = y % n;
        }
        else {
            y = y * y;
            y = y % n;
            y *= (a%n);
            y %= n;
        }
        i--;
        if (i == -1) {
            break;
        }
    }
    ost = y;
    return ost;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a, m, n;
    cout << "Введите основание степени а, показатель степени m и число n: ";
    cin >> a >> m >> n;
    cout << "Остаток от деления по первому способу равен " << Degree1(a, m, n) << endl;
    cout << "Остаток от деления по второму способу равен " << Degree2(a, m, n) << endl;
    system("pause");
    return 0;
}

