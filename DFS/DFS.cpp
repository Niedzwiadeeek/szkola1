#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<int>> tgraf;

void Czytaj(tgraf &Graf){
    int n,m,w1,w2;
    ifstream plik("graf.txt");
    plik >> n >> m;
    Graf.resize(n);
    for(int i=0; i<m; i++){
        plik >> w1 >> w2;
        Graf[w1].push_back(w2);
    }
    plik.close();
}

void DFS(int w1, tgraf &Graf, vector<bool> &Odwiedzone){
    cout<<"Odwiedzony wierzcholek: "<<w1<<endl;
    Odwiedzone[w1]=true;
    for(int i=0; i<Graf[w1].size(); i++){
        int w2=Graf[w1][i];
        if(!Odwiedzone[w2]){
            DFS(w2,Graf,Odwiedzone);
        }
    }
}

int main(){
    tgraf Graf;
    vector<bool> Odwiedzone;
    Czytaj(Graf);
    Odwiedzone.resize(Graf.size(),false);
    int w1;
    cout<<"Podaj numer wierzcholka startowego: ";
    cin>>w1;
    DFS(w1,Graf,Odwiedzone);
    return 0;
}