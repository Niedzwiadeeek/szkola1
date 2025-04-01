#include <iostream>
#include <vector>

using namespace std;

void Czytaj(vector<float> &A){
    int n;
    cout<<"Podaj stopien wielomianu: ";
    cin>>n;
    A.resize(n+1);
    for(int i=0; i<=n; i++){
        cout<<"Podaj wspolczynnik a["<<i<<"]: ";
        cin>>A[i];
    }
}

float W(vector<float> &A, float x){
    float y=A[0], z=1;
    for(int i=1; i<A.size(); i++){
        z*=x;
        y+=A[i]*z;
    }
    return y;
}

float horner(vector<float> &A, float x){
    int n=A.size()-1;
    float y=A[n];
    for(int i=n-1; i>=0; i--){
        y=x*y+A[i];
    }
    return y;
}

int main(){
    vector<float> A;
    Czytaj(A);
    float x;
    cout<<"Podaj x: ";
    cin>>x;
    cout<<"W(x) = "<<W(A, x)<<endl;
    cout<<"Horner(x) = "<<horner(A, x)<<endl;
    return 0;
}