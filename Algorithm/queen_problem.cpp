#include <bits/stdc++.h>
using namespace std;

int n,x[20];


bool palce(int k,int i)       //k row and i column
{
    for(int j=1;j<=k-1;j++)
    {
        if(x[j]==i or  abs(x[j]-i)==abs(k-j)) return false;
    }
    return true;
}


void NQueen(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(palce(k,i))
        {
            x[k]=i;
            if(k==n)
                {
                    for(int i=1;i<=n;i++)cout<<x[i]<<" ";
                    cout<<endl;
                }
            else NQueen(k+1);
        }
    }
}

int main()
{
    cin>>n;
    NQueen(4);

}


/*
  n=3

*/
