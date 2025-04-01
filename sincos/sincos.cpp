#include <iostream>
#include <cmath>

using namespace std;

double silnia(int n) {
    double wynik = 1;
    for (int i = 1; i <= n; i++) wynik *= i;
    return wynik;
}

double taylor_sin(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double wyraz = pow(x, 2 * i + 1) / silnia(2 * i + 1);
        if (i % 2 == 0) 
            suma += wyraz;
        else 
            suma -= wyraz;
    }
    return suma;
}

double taylor_cos(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double wyraz = pow(x, 2 * i) / silnia(2 * i);
        if (i % 2 == 0) 
            suma += wyraz;
        else 
            suma -= wyraz;
    }
    return suma;
}

int main() {
    double x;
    int n;
    cin >> x >> n;
    cout << "sin(x) = " << taylor_sin(x, n) << endl;
    cout << "cos(x) = " << taylor_cos(x, n) << endl;
}