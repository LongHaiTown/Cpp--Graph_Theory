#include <stdio.h>

struct GRAPH
{
    int n;
    int c;
    int a[100][100];
};
struct STACK{
    int array[100];
    int size;
};
void InitSTACK(STACK &s){
    s.size = 0;
}
void PushSTACK(STACK &s,int value){
    if(s.size <100){
        s.array[s.size]= value;
        s.size++;
    }
}
void ShowSTACK(STACK &s){
    while(s.size!= 0){
        printf("%d ",s.array[--s.size]);
    }
}
void Taodothi1(GRAPH &g){
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
int BacDinh(GRAPH &g,int v){
    int bac = 0;
    for(int i = 1; i<=g.n;i++){
        if(g.a[v][i] != 0)
            bac++;
    }
    return bac;
}
int CheckEulerS(GRAPH g){
    for(int i= 1; i<= g.n; i++){
        if(BacDinh(g,i) %2!= 0)
            return 0;
    }
    return 1;
}
void Findtour(int i, GRAPH &g, STACK &s){
    for(int j=1; j<=g.n; j++){
        if(g.a[i][j]!= 0){
            g.a[i][j]= g.a[j][i] = 0;
            Findtour(j,g,s);
        }
    }
    PushSTACK(s,i);
}
int FindEulerCycle(GRAPH g){
    if(CheckEulerS(g)== 0){
        return 0;
    }else{
        printf("Yes\n");
        GRAPH temp= g;
        STACK s;
        InitSTACK(s);
        Findtour(1,temp,s);
		ShowSTACK(s);
        return 1;
    }
}
int FindEulerPath(GRAPH g){
    int x=0;
    int dem =0;
    int check =0;
    for(int i = 1; i<=g.n;i++){
        printf("\n%d = %d ",i,BacDinh(g,i));
        if(BacDinh(g,i)%2 != 0){
            x=i;
            dem++;
            check += 1;
        }
    }
    printf("\n%d\n",check);
    printf("%d\n",dem);
    if(check == 0 || dem!= 2)
       return 0;
    GRAPH temp =g;
    STACK s;
    InitSTACK(s);
    Findtour(x,temp,s);
    for(int i =1; i<=temp.n;i++){
        for(int j =1; j<=temp.n;j++){
            if(temp.a[i][j]!= 0 || temp.a[j][i]!= 0)
                return 0;
        }
    }
    ShowSTACK(s);
    return 1;
}

int main(){
    GRAPH g;
    Taodothi1(g);
    Xuatmatranke(g);
    if(!FindEulerCycle(g)){
        if(!FindEulerPath(g))
            printf("No");
    }
    printf("\n---------------\n");
    
}


