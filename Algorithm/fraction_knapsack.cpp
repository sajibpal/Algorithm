#include <bits/stdc++.h>
using namespace std;


int profit[100],weight[100],x[100];
int n,m;   //n=item m= beg size

void knapsack()
{
    double ans=0;
    int i;

    for(i=1;i<=n;i++)
    {
        if(weight[i]>m)break;
        x[i]=1;
        ans+=profit[i];
        m=m-weight[i];
    }
    if(i<=n) ans+= profit[i]/(weight[i]*1.0)*m ,x[i]=m/(weight[i]*1.0)  ;

    cout<<"Profit is "<<ans<<endl;

     // if you want to show choosing item then print x[] array other wise remove x array form total code
}



int main()
{
     cin>>n>>m;
     for(int i=1;i<=n;i++)
        cin>>profit[i]>>weight[i];
     knapsack();

}

/*
input must be sorted according p[i]/w[i]

 n=3,m=20
 24 15
 15 10
 25 18


/*
