#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct m_heap{
    int N_index,value;
}m;
void swap(m *a ,m *b){
    m t = *a;
    *a = *b;
    *b = t;
}
class djikstra{
private:
    int v,**graph,*dist,*parent,size;
    bool *b;m *m_heap;
public:
    void display_heap(){
        cout<<"\n HEAP\t";
        for(int i  =0 ;i<size;i++){
            cout<<m_heap[i].value<<"\t";
            // <<"H IND ::"<<m_heap[i].N_index<<"\t"
        }
        cout<<"\n\t";
        for(int i  =0 ;i<size;i++){
            cout<<m_heap[i].N_index<<"\t";
            //
        }
        cout<<"\n";
        //cout<<"\n --->"<<graph[4][5];
    }
    void select_node(){
        //display_heap();
        int k = extract_min();
        neighbours(k);
        if(size > 0){
            select_node();
        }
    }
    void neighbours(int u ){
        int j;
        for(int i = 0;i<v;i++){
            j = 0;
            if(graph[u][i] != INT_MAX && b[i] == false  && graph[u][i] != 0){
                while(m_heap[j].N_index != i){
                    j++;
                }
                if(m_heap[j].value > dist[u] + graph[u][i]){
                    parent[i] = u ;
                    m_heap[j].value = dist[u] + graph[u][i];
                    heapify(size);
                    //dec_key(u,dist[u] + graph[u][i]);
                }
            }
        }
        b[u] = true;

    }
    /*
    void dec_key(int k,int nvalue){
        m_heap[k].value = nvalue;
        int i = k;
        while(i>0 && m_heap[i].value<m_heap[i/2].value){
            swap(&m_heap[i],&m_heap[i/2]);
            i= i/2;
        }
        heapify(size);
    }*/
    int  extract_min(){
        int min = m_heap[0].value;
        int index = m_heap[0].N_index;
        m_heap[0] = m_heap[--size];
        heap(0);
        dist[index] = min;
        return index;
    }
    void heap(int i){
        int lc = 2*i+1,rc =2*i+2 , min;
        if(lc <size && m_heap[lc].value<m_heap[i].value){
            min = lc;
        }else{
            min = i;
        }
        if(rc<size && m_heap[rc].value<m_heap[min].value){
            min = rc;
        }
        if(min != i){
            swap(&m_heap[min],&m_heap[i]);
            heap(min);
        }
    }
    void heapify(int n){
        for(int i = size/2;i>=0;i--){
            heap(i);
        }
    }
    void construct(int a , int b , int num){
        graph[a][b] = num;
        graph[b][a] = num;
    }
    void display_s(){
        for(int i = 0 ; i<v;i++){
            cout<<"DISTANCE FROM ROOT :: \t"<<dist[i]<<"\t PARENT "<<parent[i]<<"\n";

        }
    }
    djikstra(int n){
        v = n;
        size = v;
        b = new bool[v];
        m_heap= new  m[v];
        dist = new int[v];
        parent = new int[v];
        graph = (int **)malloc(v*sizeof(int));
        for(int i = 0;i<v;i++){
            graph[i] = (int *)malloc(v*sizeof(int));
            m_heap[i].value = INT_MAX;
            m_heap[i].N_index = i;
            b[i] = false;
        }
        parent[0] = 0;
        dist[0] = 0;
        m_heap[0].value = 0;
        for(int i = 0 ; i<v;i++){
            for(int j=0;j<v;j++){
                if(i == j){
                    graph[i][j] = 0;
                }else
                    graph[i][j] = INT_MAX;
            }
        }

    }
};
int main(){
    djikstra d(9);
    int x , y , z;
    for(int i = 0 ; i< 14 ;i++){
        cin>>x>>y>>z;
        d.construct(x,y,z);
    }
    d.select_node();
    d.display_s();
    return 0;
}
