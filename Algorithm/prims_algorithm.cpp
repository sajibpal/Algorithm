
#include <bits/stdc++.h>
using namespace std;

int matarr[100][100];
#define INF 1000

void initial(int node)
{

    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(i==j)matarr[i][j]=0;
            else matarr[i][j]=INF;
        }

    }
}

int prim(int node,int k,int l,int mincost)
{

    int near[100];
    memset(near,0,sizeof(near));


    for(int i=1;i<=node;i++)
    {
        if(matarr[i][l] < matarr[i][k])
        near[i]=l;
        else
            near[i]=k;
    }
    near[l]=0;
    near[k]=0;

    for(int i=2;i<node;i++)
    {
        int j=1,cost=INF;
        for(int k=1;k<=node;k++)
        {
            if(matarr[k][ near[k] ]< cost  and near[k]!=0)
            {
                cost=matarr[k][ near[k] ];
                j=k;
            }
        }



        mincost += matarr[j] [ near[j]];
        near[j]=0;
        for(k=1;k<=node;k++)
            if(near[k]!=0 and matarr[k][ near[k] ] > matarr[k][j] )
                 near[k] =j;
    }
    return mincost;
}

int main()
{
   //freopen("in.txt","r",stdin);
   int node,edge;
    cin>>node>>edge;
    initial(node);

     int minu,minv,minw=1000;

    for(int i=1;i<=edge;i++)
    {
         int u,v,w;
         cin>>u>>v>>w;
         if(minw > w)
         {
             minu=u;minv=v;minw=w;
         }
         matarr[u][v]=w;
         matarr[v][u]=w;

    }

    cout<<"  "<<prim(node,minu,minv,minw);


    return 0;
}
