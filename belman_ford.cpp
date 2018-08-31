#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct edge{
    int src,dest,weight;
}edge;
typedef struct map1{
    int v_id,dist_r;
}map1;
typedef struct graph{
    int v,en,*p;
    edge *e;
    map1 *m;
}graph;
class bell{
private:
    graph g;int df ;
public:
    void init_edges(edge *e,int n){
        int s, d, w;
        for(int i  = 0;i<n;i++){
            cin>>s>>d>>w;
            e[i].src = s;
            e[i].dest =d;
            e[i].weight = w;
        }
    }
    void  init_map1(map1 *m,int  v, int *p){
        for(int i = 0 ;i <v;i++){
            m[i].v_id = i;
            m[i].dist_r = 999999;
            p[i] = i;
        }
        m[0].dist_r = 0;
    }
    bell(int num,int n){
        g.v = num;
        g.en = n;
        g.e = new edge[n];
        g.m = new map1[num];
        g.p = new int[num];
        init_map1(g.m,num,g.p);
        init_edges(g.e,n);
        df = 0;
    }
    void relax(int *dr,int *du,int *w){
            if((*dr)<0){
                cout<<*du<<"\t"<<*w<<"\n";
            }
        if( (*dr) > (*du) + (*w) ){
            (*dr) = (*du) + (*w);/*
            if((*dr)<0){
                cout<<*du<<*w;
            }*/
        }
    }
    void call_relax(){
        int v = g.en,v2 = g.v;
        for(int i = 0;i<v;i++){

                relax(&(g.m[(g.e[i].dest)].dist_r),&(g.m[(g.e[i].src)].dist_r),&(g.e[i].weight));

        }
    }
    void short_dist(){
        int v = g.en,v2 = g.v;
        for(int j =0 ; j<v2-1;j++){
            call_relax();
        }
    }
    void show_edge(){

        cout<<"\n -----------------\n";
        for(int i = 0 ;i <g.en;i++){
            cout<<"source "<<g.e[i].src<<"\t dest  "<<g.e[i].dest<<"\t weight  :"<<g.e[i].weight<<"\n";
        }
        cout<<"\n -----------------\n";

    }
    void show_short(){
        cout<<"\n -----------------\n";
        for(int i = 0 ;i <g.v;i++){
            cout<<"node "<<g.m[i].v_id<<"\t dist  "<<g.m[i].dist_r<<"\n";
        }
        cout<<"\n -----------------\n";
    }
    void test(){
        relax(&(g.m[(g.e[7].dest)].dist_r),&(g.m[(g.e[7].src)].dist_r),&g.e[7].weight);
    }
};
int  main(){
    bell b(6,8);
    b.show_short();
    b.show_edge();
    b.short_dist();
    b.show_short();
    //b.test();
    //b.show_short();
    return 0;
}
