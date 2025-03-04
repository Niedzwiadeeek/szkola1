#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int N=1000;

int main() {
    vector<int> liczby[10];
    int liczba;
    ifstream plik("liczby.txt");
    for (int i=0; i<N; i++) {
        plik >> liczba;
        liczby[liczba%10].push_back(liczba);
    }

    for (int i = 0; i < 10; i++) {
        if (!liczby[i].empty()) {
            for (int j = 0; j < liczby[i].size(); j++) {
                cout << liczby[i][j] << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
