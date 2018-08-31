#include<iostream>
#include<limits.h>
#define V 5
using namespace std;

int minkey(int *a , bool *b, int n){
    int m = INT_MAX,mi = 0;
    for(int i = 0 ;i<V;i++){
        if(b[i] == false && a[i]<m){
            m = a[i];
            mi = i;
        }

    }
    return mi;
}
void printMST(int graph[V][V],int n,int *parent){
    cout<<"  edge \tweight\n";
    for(int i=1;i<V;i++){
        cout<<i<<"\t"<<parent[i]<<"\t"<<graph[i][parent[i]]<<"\n";
    }
}
void mst(int graph[V][V]){
    int key[V];
    int parent[V];
    bool mstSet[V];
    for(int i = 0 ; i<V;i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1 ;count++){
        int u = minkey(key,mstSet,V);
        mstSet[u] = true;
        for(int v = 0 ; v<V;v++){
            if(graph[u][v] && mstSet[v] == false && graph[u][v]<key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(graph,V,parent);
}
int main(){
     int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
        mst(graph);
}
