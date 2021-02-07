#include <bits/stdc++.h>
using namespace std;
string key[]={"int","if","else","else if","do","while","return"};
string specialChar="++--,;(){}*<>#,=";
string fun[]={"main","printf","scanf"};
int main()
{
freopen("Lexical_input.txt","r",stdin);
string input;
while(cin>>input)
{
if(find(key,key+7,input)!=key+7)
cout<<"This is keyword --- "<<input<<endl;
else if(specialChar.find(input)!=-1)
cout<<"This is Special Character --- "<<input<<endl;
else if(find(fun,fun+3,input)!=fun+3)
cout<<"This is function --- "<<input<<endl;
else if(input[0]==34)
{
cout<<"This is a String --- "<<input<<" ";
if (input[input.size()-1]!=34)
{cin>>input;cout<<input;}
cout<<endl;
}
else cout<<"This is a Identifier --- "<<input<<endl;
}
return 0;}
