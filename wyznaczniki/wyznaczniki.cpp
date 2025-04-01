#include <iostream>
using namespace std;

double wyznacznik(double a, double b, double c, double d) {
    return a * d - b * c;
}

void wyznacznik_main(){
    double a, b, c, a1, b1, c1, d1;
    cout<<"Podaj a, b, c, a1, b1, c1: "<<endl;
    cin>>a>>a1>>b>>b1>>c>>c1;
    double delta = wyznacznik(a, b, a1, b1);

    if(delta==0){
        cout<<"Układ równań nie ma rozwiązań"<<endl;
    }
    else{
        double delta_x = wyznacznik(c, b, c1, b1);
        double delta_y = wyznacznik(a, c, a1, c1);
        double x = delta_x / delta;
        double y = delta_y / delta;
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
    }
}

int main() {
    wyznacznik_main();
    return 0;
}