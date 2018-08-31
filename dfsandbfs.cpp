#include<iostream>
#include<stdlib.h>
using namespace std;
class graph{
private:
    int **g,*s,*q,*top,*f,*r,size,sa,sb;
    bool *st,*qt;

public:
    graph(int num){
        g = (int **)malloc(num*sizeof(int ));
        st = (bool *)malloc(num*sizeof(bool));
        qt = (bool *)malloc(num*sizeof(bool));
        s = (int *)malloc(num*sizeof(int));
        q = (int *)malloc(num*sizeof(int));
        for(int i = 0 ; i<num;i++){
               // cout<<"@@@@@\n";
            st[i] = false;
            qt[i] = false;
            g[i] = (int *)malloc(num*sizeof(int));
        }

        size = num;
        *top = -1;*f = -1;*r = -1;

        for(int i =0 ;i<size;i++){
            for(int j =0 ;j<size;j++){
                g[i][j] = 0;
            }
        }
    }
    void init(int a , int b){
        g[a][b] = 1;
        g[b][a] = 1;


    }
    void push_st(int i){
        ++(*top);
        s[*top] = i;
        cout<<s[*top]<<"-->";
    }
    void pop_st(){
        (*top)--;
    }
    void dfs(int ind){
        //st[sa] = true;int cf = 0;

        for(int i = 0;i<size;i++){

            if(g[ind][i]&&st[i] == false){

                push_st(i);
                st[i] = true;
                dfs(i);
            }
        }
        pop_st();

    }
    void push_q(int i){
        if((*f) == -1 && (*r) == -1){
                (*f)++;

            q[(*f)] = i;

            (*r)++;
            cout<<i<<"-->";
        }else{

            (*r)++;
            q[(*r)] = i;
            cout<<i<<"--->";
        }
    }
    void pop_q(){
        (*f)++;

    }
    void bdfs(int i)
    {
        st[i] = true;
        push_st(i);
        dfs(i);
        pop_st();

    }

    void bfs(int ind){

        for(int i =0 ; i<size;i++){
            if(g[ind][i] && qt[i] == false){
                push_q(i);
                qt[i] = true;
            }
        }

      while(*f <= *r){

            bfs(q[*f]);
            pop_q();
      }
    }
    void bbfs(int i){

        qt[i]= true;
        push_q(i);
        bfs(i);
    }
};
int main(){
    graph g(9);
    int x, y;
    for(int i = 0 ;i <10;i++){
        cin>>x>>y;
        g.init(x,y);
    }
    cout<<"\nDFS TRAVERSAL:::";
    g.bdfs(0);
    cout<<"\n BFS TRAVERSAL ::";
    g.bbfs(0);
}
