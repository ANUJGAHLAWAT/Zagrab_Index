#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
#include<cctype>
using namespace std;

int l;
string s,x;
int br(int a)
{
	int e=a,f,h=0;
	label1:for(e;s[e]!=')'&&e<l;e++)
	{
		if(s[e]=='(')
			h++;
	}
	for(f=e;h!=0;f++)
	{
		if(s[f]=='(')
		{
			e=f;
			goto label1;
		}
		if(s[f]==')')
			h--;
	}
	return f;
}
int br1(int a)
{
	int e=a,f,h=0;
	label2:for(e;s[e]!='('&&e>=0;e--)
	{
		if(s[e]==')')
			h++;
	}
	for(f=e;h!=0;f--)
	{
		if(s[f]==')')
		{
			e=f;
			goto label2;
		}
		if(s[f]=='(')
			h--;
	}
	return f;
}

int main()
{
	double M1=0,M2=0,MM=0;
	int p;
	ifstream f;
	f.open("smile10.txt");
	if(f.good())
	cout<<" file is opened now"<<endl;
	getline(f,x);
	f.close();
	p=x.length();
	cout<<" main string is "<<x<<endl;
	cout<<"length of main string is :"<<p<<endl;
	for(int i=0;i<p;i++)
	{
		if((isalpha(x[i])||x[i]=='('||x[i]==')')&&x[i]!='H'||isdigit(x[i]))
			s+=x[i];
	}
	cout<<" substring is "<<s<<endl;
	l=s.length();
	int y[l];
	cout<<" length of substring is "<<l<<endl;
	int z=0;
	for(int i=0;i<l;i++)
	{
		z=0;
	   	if(isalpha(s[i]))
	   	{	
	   		if(isalpha(s[i+1]))
	   			z++;
	   		if(isdigit(s[i+1]))
	   		{
	   			z++;
				if(isalpha(s[i+2]))
					z++;
				int g=i+2;
			label4:if(s[g]=='(')
				{
					int f;
					z++;
					f=br(g);
					if(isalpha(s[f]))
						z++;
					else if(s[f]=='(')
					{
						g=f;
						goto label4;
					}
				}	
			}
			int e=i+1;
	label3:if(s[e]=='(')
	   		{
	   			z++;
    			int f=0;
    			f=br(e);
				if(isalpha(s[f]))
					z++;
				else if(s[f]=='(')
				{
					e=f;
					goto label3;
				}
	   		}
	   		if((isalpha(s[i-1])||isdigit(s[i-1])||s[i-1]==')'||s[i-1]=='(')&&i!=0)
				z++;
		//cout<<z<<",    ";
		M1+=z*z;
		MM+=1/z*z;
	   	}
		y[i]=z;
		//cout<<y[i]<<",";			
	}
	for(int i=1;i<l;i++)
	{
		if(isalpha(s[i]))
		{
			int e=i-1;
			if(s[e]==')')
			{
		label5:{
					int f;
						f=br1(e);
					if(isalpha(s[f]))
					{
						M2+=y[i]*y[f];
						//cout<<" "<<y[i]<<" * "<<y[f]<<"  "<<y[i]*y[f]<<endl; 
					}
					else if(s[f]==')')
					{
						e=f;
						goto label5;
					}
				}
			}
			else
			{
				int e,t=1;
				for(e=i-1;t!=0;e--)
					if(isalpha(s[e]))
						t=0;
				M2+=y[i]*y[e+1];
				//cout<<"  "<<y[i]<<" * "<<y[e+1]<<"  "<<y[i]*y[e+1]<<endl;
			}
		}
	}
	int n=0;
    for(int i=0;i<l;i++)
    	if(isdigit(x[i]))
    		n++;
    n=n/2;
    for(int i=1;i<=n;i++)
    {
    	int a=0,b=0;
    	for(int j=0;j<l;j++)
    	{
    		if(s[j]-48==n&&a!=0)
    			b=j-1;
    		if((s[j]-48)==n&&a==0&&b==0)
    			a=j-1;
		}
		M2+=y[a]*y[b];
		//cout<<" ghgggdgf "<<y[a]<<" * "<<y[b]<<" "<<y[a]*y[b]<<endl;
    }
	cout<<endl;
	cout<<" Zagrab index(M1) of the molecule is "<<M1<<endl;
	cout<<" Zagrab index(M2) of the molecule is "<<M2<<endl;
	cout<<" Modified Zagrab index of the molecule is "<<MM<<endl;
	system("PAUSE");
    return 0;
}
