#include<stdio.h>
#define inputfile "D:/CODECURNG_inputfiles/DoThiLienThong1.txt"
#define MAX 100
typedef struct GRAPH{
    int n;
    int a[MAX][MAX];
}DOTHI;
int DocMaTranKe(const char TenFile[],DOTHI &g){
    FILE* f = fopen(TenFile,"rt");
    if (f== NULL){
        printf("Loi~ mo file!\n");
        return 0;
    }
    fscanf(f,"%d",&g.n);
    for(int i= 0;i<g.n;i++){
        for(int j = 0; j<g.n;j++){
            fscanf(f,"%d",&g.a[i][j]);
        }
    }
    fclose(f);
    return 1;
}
void XuatMaTranKe (DOTHI g) {
    printf("So dinh cua do thi la %d\n", g.n);
    printf("Ma tran ke cua do thi la:\n");
    for (int i = 0; i < g.n; i++) {
        printf ("\t");
        for (int j = 0; j < g.n; j++)
           printf("%4d ",g.a[i][j]);
        printf("\n");
    }
}
int KiemTraMaTranKeHopLe(DOTHI g) {
    for (int i = 0; i < g.n; i++) {
        if (g.a[i][i] != 0)
            return 0;
        }
    return 1;
}
int KiemTraDoThiVoHuong(DOTHI g) {
    for (int i=0; i<g.n; i++) {
        for (int j=0; j<g.n; j++) {
            if (g.a[i][j] != g.a[j][i])
                return 0;
            }
        }
    return 1;
}
void DitimCacDinhLienThong(DOTHI g, int nhan[MAX], int i){
    for(int j =0; j<g.n;j++){
        if(g.a[i][j]!= 0 && nhan[j] != nhan [i]){
            nhan[j] = nhan[i];
            DitimCacDinhLienThong(g,nhan,j);
        }
    }
}
void XetLienThong(DOTHI g){
    int Nhan[MAX];
    for(int i=0; i<g.n;i++)
        Nhan[i] =0;
    int SOTPLT = 0;
    for (int i = 0; i<g.n;i++){
        if(Nhan[i] ==0){ 
            SOTPLT ++;
            Nhan[i]= SOTPLT;
            DitimCacDinhLienThong(g,Nhan,i);
        }
    }
    printf ("So thanh phan lien thong la %d \n", SOTPLT);
    for (int i = 1; i<=SOTPLT; i++){
        printf("\nThanh phan lien thong %d gom cac dinh: ",i);
        for( int j =0;j<g.n;j++){
            if (Nhan[j] == i){
                printf("%d ",j);
            }
        }
    }
}
//
struct STACK{
    int array[100];
    int size;
};
void InitStack(STACK &s){
    s.size = 0;
}
void Push(STACK &s, int value){
    if(s.size <100){
        s.array[s.size] = value;
        s.size ++;
    }
}
void TimDuongDi(int i, DOTHI &g, STACK &s){
    for (int j =0 ; j<g.n; j++){
        if (g.a[i][j] != 0){
            g.a[i][j] = g.a[j][i] = 0;
            TimDuongDi(j,g,s);
        }
    }
    Push(s,i);
}
int BacDinh(DOTHI &g, int v){
    int bac = 0;
    for (int i = 0; i<g.n; i++ )
        if(g.a[v][i]!= 0)
            bac++;
    return bac;
}
int timChuTrinhEuler(DOTHI g){
    int i, j;
    int x= 0;
    for (int i = 0; i<g.n; i++)
        if(BacDinh(g,i)%2 != 0)
            return 0;
    DOTHI temp = g;
    STACK s;
    InitStack(s);
    TimDuongDi(x,temp,s);
    for(int i = 0; i<temp.n;i++)
        for(int j = 0; j<temp.n; j++)
            if(temp.a[i][j] != 0 || temp.a[j][i] != 0)
                return 0;
    if (s.array[0] != s.array[s.size-1])
        return 0;
    printf("\n Chu Trinh Euler: ");
    while(s.size != 0){
        printf("%d",s.array[--s.size]);
    }
    return 1;
}
void DFS (int v,DOTHI g,int LuuVet[], int ChuaXet[]){
    ChuaXet[v] = 1;
    for (int u = 0; u<g.n; u++){
        if (g.a[v][u] != 0 && ChuaXet[u] ==0){
            LuuVet[u] = v;
            DFS(u,g,LuuVet,ChuaXet);
        }
    }
}
void DuyetTheoDFS(int S, int F, DOTHI g){
    int LuuVet[MAX];
    int ChuaXet[MAX];
    for(int i =0; i<g.n;i++ ){
        LuuVet[i]= -1;
        ChuaXet[i] =0;
    }
    DFS(S,g,LuuVet,ChuaXet);
     if (ChuaXet[F] == 1) {
        printf("Duong di tu dinh %d den dinh %d la: \n\t", S, F);
        int current = F;
        while (current != S) {
            printf("%d - ", current);
            current = LuuVet[current];
        }
        printf("%d\n", S);
    } else 
        printf("Khong co duong di tu dinh %d den dinh %d\n", S, F);
}
struct QUEUE{
    int size;
    int array[MAX];
};
void InitQUEUE(QUEUE &Q){
    Q.size = 0;
}
int PushQUEUE(QUEUE &Q, int value){
    if(Q.size + 1 >= 100)
        return 0;
    Q.array[Q.size]= value;
    Q.size++;
    return 1;
}
int PopQUEUE(QUEUE &Q, int &value){
    if(Q.size <= 0)
        return 0;
    value = Q.array[0];
    for(int i =0; i<Q.size; i++)
        Q.array[i] = Q.array[i+1];
    Q.size--;
    return 1;
}
void BFS(int v, DOTHI g,int LuuVet[], int ChuaXet[]){
    QUEUE q;
    InitQUEUE(q);
    PushQUEUE(q,v);
    while(q.size > 0){
        PopQUEUE(q,v);
        ChuaXet[v]= 1;
        for(int u = 0; u<g.n; u++){
            if(g.a[v][u] != 0 && ChuaXet[u]== 0){
                PushQUEUE(q,u);
                if( LuuVet[u] == -1)
                    LuuVet[u] == v;
            }
        }
    }
}
void DuyetTheoBFS(int S, int F, DOTHI g){
    int LuuVet[MAX];
    int ChuaXet[MAX];
    for(int i =0; i<g.n;i++ ){
        LuuVet[i]= -1;
        ChuaXet[i] =0;
    }
    BFS(S,g,LuuVet,ChuaXet);
    if (ChuaXet[F] == 1) {
        printf("Duong di tu dinh %d den dinh %d la: \n\t", S, F);
        int current = F;
        while (current != S) {
            printf("%d - ", current);
            current = LuuVet[current];
        }
        printf("%d\n", S);
    } else 
        printf("Khong co duong di tu dinh %d den dinh %d\n", S, F);
}    

int main(){
    DOTHI g;

    if(DocMaTranKe(inputfile,g)==1){
        printf("Doc thong tin do thi tu file thanh cong.\n\n");
        XuatMaTranKe(g);
        printf("Do thi co ma tran ke: %s\n",
            KiemTraMaTranKeHopLe(g) == 1 ? "hop le" : "khong hop le");
        printf("Do thi thuoc dang: %s\n",
            KiemTraDoThiVoHuong(g) == 1? "vo huong" : "co huong");
        XetLienThong(g);
        printf("\n");
        // DuyetTheoDFS(5,6,g);
        DuyetTheoBFS(1,6,g);
        } 
}

