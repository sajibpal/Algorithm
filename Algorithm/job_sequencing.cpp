
#include<bits/stdc++.h>
using namespace std;
int profit[100];
int deadline[100];
int ans[100];
int maximumdeadline=-99999;
int n;



void JS()
{
     for(int i=1;i<=n;i++)
    {
             int k= deadline[i];
                for(int j=k;j>=1;j--)
                {
                    if(ans[j]==0) { ans[j]=i;break;}
                }

    }

    int total_profit=0;
    for(int i=1;i<=maximumdeadline;i++)
    {
        cout<<ans[i]<<" ";
        total_profit +=profit[ans[i]];
    }
    cout<<endl<<" Total Profit is "<< total_profit<<endl;
}



int main()
{
    //freopen("in.txt","r",stdin);


    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>profit[i]>>deadline[i];
        maximumdeadline=max(maximumdeadline,deadline[i]);



    }

    JS();  //function calling

    return 0;
}

/*input            **profit should be short
  n=4;
  100 2
  27 1
  15 2
  10 1

*/


