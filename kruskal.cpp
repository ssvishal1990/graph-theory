#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct edge{
    int src, dest,weight;
}edge;
typedef struct graph{
    int v, e1;
    edge *e;
}graph;
typedef struct subset{
    int parent,rank;
}subset;
typedef struct  span_tree{
    int v;
    edge *e;
}s_tree;
// THIS CLASS WILL CONTAIN EVERY GRAPH ALGORITH;
class graph_theory{
private:
    graph *g;
    subset *s;
    s_tree *st;
    int i;
    int qsort(edge *E, int s , int e){
        int p = E[e].weight;
        int i1 = s-1;
        edge t;
        for(int j=s;j<e;j++){
            if(E[j].weight < p){
                i1++;
                t = E[j];
                E[j] = E[i1];
                E[i1] = t;
            }
        }
        i1++;
        t = E[i1];
        E[i1]= E[e];
        E[e] = t;
        return i1;
    }
    void sort(edge *E, int s, int e){
        if(s<e){
            int p = qsort(E,s,e);
            sort(E,s,p-1);
            sort(E,p+1,e);
        }
    }
public:
    graph_theory(int a , int b){
        g = new graph();
        g->v = a;
        g->e1 = b;
        g->e = (edge *)malloc((g->e1)*sizeof(edge));
        i =0;
        s = (subset *)malloc((g->v)*sizeof(subset));
        for(int j =0 ;j<(g->v);j++){
            s[j].parent = j;
            s[j].rank = 0;
        }
        st = new s_tree();
        st->v = (g->v)-1;
        st->e = (edge *)malloc(((g->v)-1)*sizeof(edge));
    }
    void kruskal(){
        edge t ;int j2 = 0;
        for(int j = 0;j<g->e1;j++){
            if(cycle_detect(g->e[j].src,g->e[j].dest)){
                continue;
            }else{
                st->e[j2] = g->e[j];
                j2++;
                if(j2>=(g->v)-1){
                    break;
                }
            }
        }
    }
    void display_s_tree(){
        int sum = 0;
        for(int j = 0 ;j<((g->v)-1);j++){
            cout<<"\n SPANNING TREE EDGE :: SRC DEST WEIGHT\t"<<st->e[j].src<<"\t"<<st->e[j].dest<<"\t"<<st->e[j].weight;
            sum += st->e[j].weight;
        }
        cout<<"\n TOTAL LENGTH OF SPANNING TREE \t"<<sum;
    }
    void sort_by_weight(){
        sort(g->e,0,i-1);
    }
    void construct_graph(int src, int dest,int weight){
        g->e[i].src = src;
        g->e[i].dest = dest;
        g->e[i].weight = weight;
        i++;
    }
    int  find(int node){
        if(s[node].parent == node){
            return node;
        }else{
            return find(s[node].parent);
        }
    }
    void union1(int a, int b){
        int xr = find(a);
        int yr = find(b);
        if(s[xr].rank > s[yr].rank){
            s[yr].parent =xr;
        }else if(s[xr].rank < s[yr].rank){
            s[xr].parent = yr;
        }else{
            s[xr].parent = yr;
            s[yr].rank++;
        }
    }
    void display_sort_Edge(){
        for(int j=0;j<i;j++){
            cout<<"\nEDGE \t SRC  DEST  WEIGHT \t"<<g->e[j].src<<"\t"<<g->e[j].dest<<"\t"<<g->e[j].weight;
        }
        cout<<"\n\n";
    }
    int  cycle_detect(int src, int des){
        int x = find(src);
        int y = find(des);
        if(x == y){
            return 1;
        }else{
            union1(x,y);
            return 0;
        }


    }
    void find_cycle(){                   // DETECTION OF CYCLE IN A GRAPH
        int x,y;
        for(int j =0 ; j<(g->e1);j++){
             x = find(g->e[j].src);
             y = find(g->e[j].dest);
            if(x == y){
                //cout<<"\n CYCLE EXISTS \t VERTICES ::: \t"<<g->e[j].src<<"\t"<<g->e[j].dest;
            }
            union1(x,y);
        }
    }

};
int main(){
    graph_theory G(9,14);
    int s , d , w;
    for(int i = 0 ; i<14;i++){
        cin>>s>>d>>w;
        G.construct_graph(s,d,w);
    }
    /*
    G.construct_graph(0,1);
    G.construct_graph(0,2);
    G.construct_graph(1,3);
    G.construct_graph(1,4);
    G.construct_graph(3,4);
    G.find_cycle();
    */
    G.display_sort_Edge();
    G.sort_by_weight();
    G.display_sort_Edge();
    G.kruskal();
    G.display_s_tree();
    //G.find_cycle();
    return 0;

}
