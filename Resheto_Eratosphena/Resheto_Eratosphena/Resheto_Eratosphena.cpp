#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    cout << "Введите число "<<endl;
    cin >> n;
    int* arr = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
        arr[i] = i;

    for (int p = 2; p < n + 1; p++)
    {
        if (arr[p] != 0)
        {
            for (int j = p * p; j < n + 1; j += p)
                arr[j] = 0;
        }
    }

    if (arr[n] != 0)
    {
        cout << "Простое"<<endl;
    }
    else cout << "Составное"<<endl;

    system("pause");
}
