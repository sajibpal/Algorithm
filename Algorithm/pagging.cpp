#include <bits/stdc++.h>
using namespace std;

int main(){
{
int n,m,arr[100];
     //logical address space 2^m and page size 2^n
for(int i=0;i<100;i++)arr[i]=-1;

int logical_address,pagesize;
string text="";

cout<<"Enter page size = ";
cin>>pagesize;
cout<<"Enter logical address space =";
cin>>logical_address;
cout<<"Enter Logical memory Information = ";
cin>>text;
int pagetable;
cout<<"Enter Page table Size = ";
cin>>pagetable;
cout<<"Enter Page table number = "<<endl;
for(int i=0;i<pagetable;i++) {
   cin>>arr[i];
 }

cout<<"Frame Number\t\tpageInfromation"<<endl<<endl;

for(int i=0;i<logical_address/pagesize;i++)
{
cout<<endl;
bool check=false;
cout<<i*pagesize;
for(int j=0;j<pagesize;j++)
{
    if(i==arr[j])
    {
    check=true;
    for(int k=0;k<pagesize;k++)
    {
      cout<<"\t\t"<<text[pagesize*(j)+k]<<endl;
      }
      break;
     }
}
if(check==false)
 cout<<endl<<endl<<endl;
 }
 return 0;
 }
}

