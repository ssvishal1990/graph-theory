#include<iostream>
#include<stdlib.h>
using namespace std;
class graph{
private:
    int **g,*s,top,size;
    bool *v;
public:
    graph(int num){
        size = num;
        g = (int **)malloc(num*sizeof(int));
        v = (bool *)malloc(num*sizeof(bool));
        s = (int *)calloc(num,sizeof(int));
        top = -1;
        for(int i = 0;i<num;i++){
            g[i] = (int *)malloc(num*sizeof(int));
            v[i] = false;
        }
        for(int i = 0 ;i <num;i++){
            for(int j = 0;j<num;j++){
                g[i][j] = 0;
            }
        }

    }
    void init(int a, int b){
        g[a][b] = 1;
    }
    void tropological(int ind){
        int i;
        for( i=0;i<size;i++){
            if(g[ind][i] == 1 && v[i] == false){
                v[i] = true;
                tropological(i);
            }
        }
        push(ind);
    }
    void call_trop(){
        int cf = 0;
        for(int i = 0;i<size;i++){
            if(v[i] == false){
                v[i] = true;
                tropological(i);
                cf = 1;
            }
        }
        if(cf == 1){
            call_trop();
        }
        pop();
    }
    void pop(){
        cout<<"\n";
        while(top>=0){
            cout<<s[top--]<<"-->";
        }
    }
    void push(int num){
        s[++top]=num;
    }
};
int main(){
    graph g(8);
    int x, y;
    for(int i = 0;i<8;i++){
        cin>>x>>y;
        g.init(x,y);
    }
    g.call_trop();
}
