#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int a;
    vector<int>number;
    cout << "Введите натуральное число а: ";
    start:
    cin >> a;

    if (a <= 0) {
        system("cls");
        cout << "Введено не натуральное число. Введите заново\n";
        cin.clear(1000);
        cin.ignore();
        goto start;
    }
    else if (a == 1) {
        cout << "Число 1 не простое и не составное.\n";
        system("pause");
        return 0;
    }
    bool flag = true;
    int p = 2;
     while(flag){
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
    cout << "a = ";
    for (int i = 0; i < number.size(); i++) {
        cout << number[i] << " * ";
    }
    cout << "1" << endl;
    system("pause");
    return 0;
}
