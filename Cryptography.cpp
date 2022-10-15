#include <iostream>
using namespace std;

int powerMod(int a, int b, int m); //a^b mod m = x
int phi(int n);
int nsd(int a, int b);
int linEqWithPhi(int a, int b, int m); //������� ��������� ���� a*x = b mod m
void simpleNumbers(int a, int b); //������� ����� � ��������� �� � �� �




int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    while (1) {
        cout << endl << "�������� ����� �������" << endl;
        cout << "1 - ������� ��������� ���� a mod m = x" << endl << "2 - ������� ��������� ���� a^b mod m = x" << endl << "3 - ������� ��������� ���� a*x = b mod m" << endl << "4 - ������� ����� � ��������� �� � �� �";
        cout << endl <<  "0 - ����� �� ���������" << endl << endl;
        int ch, x, number, mod, power, a, b;

        cin >> ch;

        switch (ch) {
        case 0:
            exit(0);
        case 1:
            cout << endl << "������� ��������� ���� a mod m = x" << endl << "������� ����� �: ";
            cin >> number;
            cout << "������� ������ m: ";
            cin >> mod;
            x = number % mod;
            cout << endl << "�����: " << x << endl;
            break;
        case 2:
            cout << endl << "������� ��������� ���� a^b mod m = x" << endl << "������� ����� �: ";
            cin >> number;
            cout << endl << "������� ������� b: " << endl;
            cin >> power;
            cout << endl << "������� ������ m: ";
            cin >> mod;
            x = powerMod(number, power, mod);
            cout << endl << "�����: " << x << endl;
            break;
        case 3:
            cout << endl << "������� ��������� ���� a*x = b mod m" << endl << "������� ����� �: ";
            cin >> number;
            cout << endl << "������� ������� b: " << endl;
            cin >> power;
            cout << endl << "������� ������ m: ";
            cin >> mod;
            x = linEqWithPhi(number, power, mod);
            cout << endl << "�����: " << x << endl;
            break;
        case 4:
            cout << endl << "������� ��������� ���� a*x = b mod m" << endl << "������� ����� �: ";
            cin >> a;
            cout << endl << "������� ����� b: ";
            cin >> b;
            cout << endl << "������� ����� � ���������: "<< endl;
            simpleNumbers(a, b);
            cout << endl;
            break;
        }
    }

    return 0;
}

int powerMod(int a, int b, int m) 
{
    int b_2[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    int i = 0;
    while (b > 0)
    {
        b_2[i] = b % 2;
        b = b / 2;
        i++;

    }
    int n = i;
    int d = 1, t = a;
    for (int j = 0; j < n; j++)
    {
        if (b_2[j] == 1) {
            d = d * t % m;
            t = (t * t) % m;
        }
        else if (b_2[j] == 0) {
            t = t * t % m;
        }
        else cout << " Oh no, you are a faliure!";
    }
    int x = d;
    return x;
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
        return result;
    }
}

int nsd(int a, int b) {
    if (a == 0) return b;
    while (b != 0) {
        if (a > b) a = a - b;
        else b = b - a;

    }
    return a;
}
int linEqWithPhi(int a, int b, int m) { 
    if (nsd(a, m) == 1) {
        int power = phi(m) - 1;
        int x = powerMod(a, power, m);
        x = x * b % m;
        return x;
    }
}

void simpleNumbers(int a, int b) { 
    int n = a;
    if (a == 1) n = 2;

    int* mas = new int[b + 1];
    for (int i = 0; i < b + 1; i++)
        mas[i] = i;
    for (int p = n; p < b + 1; p++)
    {
        if (mas[p] != 0)
        {
            cout << mas[p] << "\t";
            for (int j = p * p; j < b + 1; j += p)
                mas[j] = 0;
        }
    }
    free(mas);
}