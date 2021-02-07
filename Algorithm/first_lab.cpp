#include <bits/stdc++.h>

using namespace std;
string grammer[6]={"E->Tp","p->+Tp|z" ,"T->Fq","q->*Fq|z" ,"F->(E)","F->id"};


char rec(char ch)
{
	for(int i=0;i<6;i++)
	{
		if(grammer[i][0]==ch)
		{
			if(grammer[i][3]=='+' ) return '+';
		    else if(grammer[i][3]=='*' ) return '*';
		    else if(grammer[i][3]=='(' ) return '(';
		    else if(grammer[i][3]==')' ) return ')';
		    else if(grammer[i][3]=='i' )  return 'i';
		    else  return  rec(grammer[i][3]);
		}
	}
}

int main()
{


  for(int i=0;i<6;i++)
  {
  	cout<<"Grammer is  = "<<grammer[i] <<" \n First--->\t {";

    if(grammer[i][3]=='+' )cout<<"+";
    else if(grammer[i][3]=='*' )cout<<"*";
    else if(grammer[i][3]=='(' )cout<<"(";
    else if(grammer[i][3]==')' )cout<<")";
    else if(grammer[i][3]=='i' )cout<<"id";

    else
    {
    	char ch= rec(grammer[i][3]);
    	if(ch=='(') cout<<" ( id ";
    	else cout<<ch;
    }

    for(int j=0; j<grammer[i].size() ;j++)
    	if(grammer[i][j]=='|')
    	{
    		 if(grammer[i][j+1]='z')
                cout<<" z ";
            break;
    	}
    	cout<<"}"<<endl;



  }

	return 0;
}
