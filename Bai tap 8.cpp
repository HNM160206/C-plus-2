#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 11;
const int VC = 1000000;

string TenTinh[MAX] = {
    "HN","TN","BN","BG","UB","HP","HD","HY","PL","HB","ST"
};

struct DoThi {
    int n;
    int a[MAX][MAX];
};

struct Canh {
    int dau, cuoi, ts;
};

void TaoDoThi(DoThi &g, int n) {
    g.n = n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g.a[i][j]=0;
}
void ThemCanh(DoThi &g,int u,int v,int w){
    g.a[u][v]=w;
    g.a[v][u]=w;
}
void InMaTran(int a[MAX][MAX],int n){
    cout<<setw(5)<<" ";
    for(int i=0;i<n;i++)
        cout<<setw(5)<<TenTinh[i];
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<setw(5)<<TenTinh[i];
        for(int j=0;j<n;j++)
            cout<<setw(5)<<a[i][j];
        cout<<endl;
    }
}
void Dijkstra(DoThi g){
    int d[MAX];
    int truoc[MAX];
    bool chon[MAX];

    for(int i=0;i<g.n;i++){
        d[i]=VC;
        truoc[i]=-1;
        chon[i]=false;
    }
     int xp=9;      // Hoa Binh
    int dich=4;    // Uong Bi

    d[xp]=0;

    while(true){

        int u=-1;
        int Min=VC;

        for(int i=0;i<g.n;i++){
            if(!chon[i] && d[i]<Min){
                Min=d[i];
                u=i;
            }
        }

        if(u==-1) break;

        chon[u]=true;

        if(u==dich) break;

        for(int v=0;v<g.n;v++){
            if(g.a[u][v]>0 && !chon[v]){
                if(d[v] > d[u]+g.a[u][v]){
                    d[v]=d[u]+g.a[u][v];
                    truoc[v]=u;
                }
            }
        }

        cout<<"\nChon dinh "<<TenTinh[u]<<endl;

        cout<<"Khoang cach: ";
        for(int i=0;i<g.n;i++){
            if(d[i]==VC) cout<<"INF ";
            else cout<<d[i]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nDuong di ngan nhat:\n";

    int stack[MAX];
    int top=0;

    int x=dich;

    while(x!=-1){
        stack[top++]=x;
        x=truoc[x];
    }

    for(int i=top-1;i>=0;i--){
        cout<<TenTinh[stack[i]];
        if(i) cout<<" -> ";
    }

    cout<<"\nTong trong so = "<<d[dich]<<endl;
}
void Prim(DoThi g){

    bool daCo[MAX]={false};
    int Cay[MAX][MAX];

    for(int i=0;i<g.n;i++)
        for(int j=0;j<g.n;j++)
            Cay[i][j]=0;
 daCo[9]=true;          // Bat dau tu Hoa Binh

    cout<<"\nPRIM \n";

    int dem=0;

    while(dem<g.n-1){

        int Min=VC;
        int x=-1,y=-1;

        for(int i=0;i<g.n;i++){
            if(daCo[i]){
                for(int j=0;j<g.n;j++){
                    if(!daCo[j] && g.a[i][j]>0){
                        if(g.a[i][j]<Min){
                            Min=g.a[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }

        if(x==-1) break;

        cout<<"Lay canh: "
            <<TenTinh[x]
            <<" - "
            <<TenTinh[y]
            <<" = "
            <<Min<<endl;

        daCo[y]=true;

        Cay[x][y]=Min;
        Cay[y][x]=Min;

        dem++;
    }

    cout<<"\nMa tran cay khung Prim:\n";
    InMaTran(Cay,g.n);

}

int TimCha(int cha[],int x){

    while(cha[x]!=x)
        x=cha[x];

    return x;
}
void Kruskal(DoThi g){

    Canh ds[30];
    int m=0;

    for(int i=0;i<g.n;i++){
        for(int j=i+1;j<g.n;j++){
            if(g.a[i][j]>0){
                ds[m].dau=i;
                ds[m].cuoi=j;
                ds[m].ts=g.a[i][j];
                m++;
            }
        }
    }
     for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            if(ds[i].ts>ds[j].ts){
                Canh t=ds[i];
                ds[i]=ds[j];
                ds[j]=t;
            }
        }
    }

    int cha[MAX];

    for(int i=0;i<g.n;i++)
        cha[i]=i;

    int Cay[MAX][MAX];

    for(int i=0;i<g.n;i++)
        for(int j=0;j<g.n;j++)
            Cay[i][j]=0;

    cout<<"\n KRUSKAL\n";

    int dem=0;
     for(int i=0;i<m;i++){

        int r1=TimCha(cha,ds[i].dau);
        int r2=TimCha(cha,ds[i].cuoi);

        if(r1!=r2){

            cout<<"Lay canh: "
                <<TenTinh[ds[i].dau]
                <<" - "
                <<TenTinh[ds[i].cuoi]
                <<" = "
                <<ds[i].ts<<endl;

            cha[r1]=r2;

            Cay[ds[i].dau][ds[i].cuoi]=ds[i].ts;
            Cay[ds[i].cuoi][ds[i].dau]=ds[i].ts;

            dem++;

            if(dem==g.n-1)
                break;
        }
    }

    cout<<"\nMa tran cay khung Kruskal:\n";
    InMaTran(Cay,g.n);

}
int main(){

    DoThi g;

    TaoDoThi(g,MAX);

    int data[][3]={
        {0,6,1},
        {6,7,2},
        {7,8,3},
        {0,8,4},
        {0,9,5},
        {0,10,6},
        {0,1,7},
        {0,2,8},
        {2,3,9},
        {3,4,10},
        {2,4,11},
        {4,5,12},
        {6,5,13}
    };

    int soCanh=sizeof(data)/sizeof(data[0]);

    for(int i=0;i<soCanh;i++){
        ThemCanh(g,
                 data[i][0],
                 data[i][1],
                 data[i][2]);
    }

    cout<<" MA TRAN DO THI \n";
    InMaTran(g.a,g.n);

    cout<<"\nDIJKSTRA \n";
    Dijkstra(g);

    Prim(g);

    Kruskal(g);

    return 0;
}