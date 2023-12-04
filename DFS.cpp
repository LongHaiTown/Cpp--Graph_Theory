#include<stdio.h>
struct GRAPH
{
    int n;
    int c;
    int a[100][100];
};

void InputGraph(GRAPH &g){
    scanf("%d",&g.n);
    scanf("%d",&g.c);
    for(int i = 1; i<= g.n; i++){
        for(int j = 1; j<=g.n; j++){
            g.a[i][j]= 0;
        }
    }
    for(int i = 1; i <=g.c;i++){
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        g.a[x][y]= g.a[y][x]=1;
    }
}
void Xuatmatranke(GRAPH g){
    for(int i = 1; i<= g.n; i++){
        for(int j = 1; j<=g.n; j++){ 
            printf("%d ", g.a[i][j]);
        }
    printf("\n");
    }
}
int Luuvet[100];
int Chuaxet[100];
void DFS(int v, GRAPH g){
    Chuaxet[v] = 1;
    for(int i=1; i<=g.n;i++){
        if(g.a[v][i] ==1 && Chuaxet[i] == 0){
            Luuvet[i] = v;
            DFS(i,g);
        }
    }
}
void FindDFS(int s, int f, GRAPH g){
    for(int i =1; i<=g.n;i++){
        Luuvet[i] =-1;
        Chuaxet[i] =0;
    }
    DFS(s,g);
    if(Chuaxet[f] == 1 ){
        printf("%d",f);
        int i = Luuvet[f];
        while(i != -1){
            printf(" %d",i);
            i = Luuvet[i];
        }
    }
}
int main(){
    GRAPH g;
    InputGraph(g);
    Xuatmatranke(g);
    FindDFS(1,6,g);
    
}