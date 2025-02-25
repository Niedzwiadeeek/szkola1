#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct krawedz{
    int w2;

    int waga;
};

typedef vector<vector<krawedz>> tgraf;

void Czytaj(tgraf &Graf){
    int n, m, w1;
    krawedz k;
    ifstream plik("graf_1.txt");
    plik>>n>>m;
    Graf.resize(n);
    for(int i=0; i<m; i++){
        plik>>w1>>k.w2>>k.waga;
        Graf[w1].push_back(k);
    }
    plik.close();
}

void Dijkstra(tgraf Graf, int pocz, vector<int> &Koszt){
    krawedz kraw;
    int i, j, k, w1;
    vector<bool> Odwiedzone(Graf.size(), false);
    Koszt[pocz]=0;
    for(i=0; i<Graf.size(); i++){
        k=0; 
        while(Odwiedzone[k]) k++; w1=k;
        for(j=k+1; j<Graf.size(); j++){
            if(!Odwiedzone[j] && Koszt[j]<Koszt[w1]) w1=j;
        }
        Odwiedzone[w1]=true;
        for(j=0; j<Graf[w1].size(); j++){
            kraw=Graf[w1][j];
            if(!Odwiedzone[kraw.w2] && Koszt[kraw.w2]>Koszt[w1]+kraw.waga){
                Koszt[kraw.w2]=Koszt[w1]+kraw.waga;
            }
        }
    }
}

int main(){
    tgraf Graf;
    vector<int> Koszt;
    int pocz, i;
    Czytaj(Graf);
    cout<<"Podaj wierzcholek poczatkowy: ";
    cin>>pocz;
    Koszt.resize(Graf.size(), 1000000);
    Dijkstra(Graf, pocz, Koszt);
    for(i=0; i<Koszt.size(); i++){
        if(i!=pocz) cout<<i<<": "<<Koszt[i]<<endl;
    }
    return 0;
}