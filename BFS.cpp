#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct GRAPH{
	int n;
	int c;
	int a[100][100];
};
struct QUEUE{
	int a[100];
	int size;
};
void InitQUEUE(QUEUE &q){
    q.size = 0;
};
int enQUEUE (QUEUE &q, int i){
    if(q.size <=100){
        q.a[q.size++] = i;
        return 1;
    }
    return 0;
}
int deQUEUE(QUEUE &q, int &value){
    if(q.size <=0)
        return 0;
    value = q.a[0];
    for (int i =0; i<=q.size; i++)
    	q.a[i]=q.a[i+1];
    q.size--;
    return 1;
}
void Taodothi(GRAPH &g){
    scanf("%d",&g.n);
    scanf("%d",&g.c);
    for(int i = 1; i<=g.n;i++){
        for(int j=1; j<=g.n;j ++){
            g.a[i][j]= 0;
        }
    }
    for(int i=1; i<=g.c; i++){
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        g.a[x][y]= g.a[y][x]= 1;
    }
}
int IsEmpty(QUEUE q){
    return q.size<= 0;
}
int Luuvet[100];
int Chuaxet[100];
void BFS(int v, GRAPH g){
    QUEUE q;
    InitQUEUE(q);
    enQUEUE(q,v);
    while(!IsEmpty(q)){
        deQUEUE(q,v);
        Chuaxet[v]= 1;
        for(int i= 1; i<=g.n; i++){
            if(g.a[v][i]!= 0 && Chuaxet[i] == 0){ 
                enQUEUE(q,i);
                if(Luuvet[i]== -1)
                    Luuvet[i]= v;
            }
            
        }
    }
}
void FindBFS(int S, int F,GRAPH g){
    for(int i=1; i<= g.n; i++){
        Luuvet[i] = -1;
        Chuaxet[i] = 0;
    }
    BFS(S,g);
    if(Chuaxet[F] == 1){
        
        int keq[100];
        int size = 0;
        int i = Luuvet[F];
        while( i!= -1 ){
            printf("%d ",i);
            keq[size] = i;
            size++;
            i= Luuvet[i];
        } 
        for(int i =size; i>0; i--)
            printf("%d ",keq[i]);
        printf("%d ", F);
    }else printf("Not Found");
}
void Xuatmatranke(GRAPH g){
    for(int i = 1; i<= g.n; i++){
        for(int j = 1; j<=g.n; j++){ 
            printf("%d ", g.a[i][j]);
        }
    printf("\n");
    }
}
int main() {
    //Tiếp tục hoàn thiện mã nguồn
    GRAPH g;
    Taodothi(g);
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    FindBFS(a,b,g);
    return 0;
}