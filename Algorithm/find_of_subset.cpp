
#include <bits/stdc++.h>
using namespace std;

int n,m,w[50],x[50];


void SumOfsub(int sum,int k)
{
        if(k>n) return;

         x[k]=1;
        if(sum+w[k]==m)
        {
            for(int i=1;i<=n;i++)
                cout<<x[i]<<" ";
              cout<<endl;
        }
        else if(sum+w[k] <=m)             //same item i add
            SumOfsub(sum+w[k],k+1);


           x[k]=0;                               //same item reject
           SumOfsub(sum,k+1);


}

int main()
{
    freopen("in.txt","r",stdin);

    int reminig=0;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
       {
           cin>>w[i];
           reminig+=w[i];
       }

     SumOfsub(0,1);

    return 0;
}




/*---

input
7 35
5 7 10 12 15 18 20

---*/
