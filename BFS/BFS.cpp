#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

typedef vector<vector<int> > tgraf;


void Czytaj(tgraf &Graf){
    int n, m, w1, w2;
    ifstream plik("graf.txt");
    plik>>n>>m;
    Graf.resize(n);
    for(int i=0; i<m; i++){
        plik>>w1>>w2;
        Graf[w1].push_back(w2);
    }
    plik.close();
}

void BFS(int w1, tgraf Graf){
    int w2;
    vector<bool> Odwiedzone;
    Odwiedzone.resize(Graf.size(), false);
    queue<int> Kolejka;
    Kolejka.push(w1); Odwiedzone[w1]=true;
    while(!Kolejka.empty()){
        w1=Kolejka.front();
        Kolejka.pop();
        cout<<"Odwiedzone Wierzcholki: "<<w1<<endl;
        for(int i=0; i<Graf[w1].size(); i++){
            w2=Graf[w1][i];
            if(!Odwiedzone[w2]){
                Kolejka.push(w2);
                Odwiedzone[w2]=true;
            }
        }
    }
}

int main(){
    tgraf Graf;
    Czytaj(Graf);
    BFS(0, Graf);
    return 0;
}