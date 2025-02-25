#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

const int N = 20;

void WczytajLabirynt(int Lab[][N]){
    string s;
    ifstream plik("labirynt.txt");
    for(int i = 0; i < N; i++){
        plik >> s;
        for(int j = 0; j < N; j++){
            if(s[j] == 'X') Lab[i][j] = -1;
            else Lab[i][j] = 0;
        }
    }
    plik.close();
}

void WypiszLabirynt(int Lab[][N]){
    cout<<"   ";
    for(int j = 0; j < N; j++)
    cout<<setw(3)<<j;
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<setw(3)<<i;
        for(int j=0;j<N;j++){
            if(Lab[i][j]==-1) cout<<"  X";
            else if (Lab[i][j]==-2) cout<<"  D";
            else cout<<"   ";
        }
        cout<<endl;
    }
}
bool DrogaRek(int (*Lab)[N], int w, int k, int x, int &w1, int &k1){ //Pisz to jesli każe ci napisać droge rekurencyjnie
    Lab[w][k] = x;
    if(w == 0 || w == N-1 || k == 0 || k == N-1){
        w1 = w;
        k1 = k;
        return true;
    }
    if(Lab[w-1][k] == 0 && DrogaRek(Lab, w-1, k, x+1, w1, k1)) return true;
    if(Lab[w+1][k] == 0 && DrogaRek(Lab, w+1, k, x+1, w1, k1)) return true;
    if(Lab[w][k-1] == 0 && DrogaRek(Lab, w, k-1, x+1, w1, k1)) return true;
    if(Lab[w][k+1] == 0 && DrogaRek(Lab, w, k+1, x+1, w1, k1)) return true;
    return false;
}

void OznaczDroge(int Lab[][N], int w, int k){
    int x=Lab[w][k];
    Lab[w][k] = -2;
    while(x>1){
        x--;
        if(w>0 && Lab[w-1][k]==x) w--;   
            else if(w<N-1 && Lab[w+1][k]==x) w++;
                else if(k>0 && Lab[w][k-1]==x) k--;   
                    else k++;
        Lab[w][k]=-2;
    }
}

int main(){
    int w, k, w1, k1;
    int Lab[N][N];
    WczytajLabirynt(Lab);
    WypiszLabirynt(Lab);
    cout<<"Podaj wspolrzedne startowe: "<<endl;
    cout<<"w = "; cin>>w; 
    cout<<"k = "; cin>>k;
    if(DrogaRek(Lab, w, k, 1, w1, k1)){
        cout<<"Droga istnieje"<<endl;
        OznaczDroge(Lab, w1, k1);
        WypiszLabirynt(Lab);
    }
    else cout<<"Droga nie istnieje"<<endl;
    return 0;
}