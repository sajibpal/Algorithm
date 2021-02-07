

#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int n,m,edge,x[100];   //n= number of vertex and m=number of color and edge=number of edge


void nextvalue(int k)
{
    for(int i=1;i<=m;i++)
    {
        x[k] = i%m;
        if(x[k]==0)  return ;

         int j;
         for(j=1;j<=n;j++)
         {
             if(graph[k][j]!=0 and x[k]==x[j] ) break;
         }
         if(j>n) break;

    }
}


void mcoloring()
{
    for(int k=1;k<=n;k++)
    {
        nextvalue(k);
        if(x[k]==0){  cout<<"no color possible"; return;}

        if(k==n)
            for(int i=1;i<=n;i++)cout<<x[i]<<" ";

    }
}

int main()
{
  //  freopen("in.txt","r",stdin);
    cin>>n>>m>>edge;

    for(int i=1;i<=edge;i++)
    {
      int u,v;
        cin>>u>>v;
        graph[u][v]=1;  //u to v  connected
        graph[v][u]=1;  // v to u connected
    }
    mcoloring();
}

/*input
n=4 m=3
edge =4
1 3
1 2
2 4
3 4

*/
