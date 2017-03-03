#include<bits/stdc++.h>
using namespace std;
void monoalphac(string &s,map<char,int> mam)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			//cout<<mam[s[i]]<<"\t";
			s[i]=mam[s[i]]+'a';			
		}
		else if(s[i]>='A' && s[i]<='Z')
		{
			s[i]=mam[s[i]-'A'+'a']+'A';		
		}
	}
}
void monoalphad(string &s,map<int,char> mam)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			s[i]=mam[s[i]-'a'];			
		}
		else if(s[i]>='A' && s[i]<='Z')
		{
			s[i]=mam[s[i]-'A'];		
		}
	}
}
void buildmatrix(char **matrix,string s)
{
	vector<int> alpha(26,0);
	int k=0,j=-1;
	for(int i=0;i<s.length();i++)
	{
		if(alpha[s[i]-'a']==0)
		{
			j=j+1;
			if(j==5)
			{
				k++;
				if(k==5)
				k=0;
				j=0;
			}	
			matrix[k][j]=s[i];
			//cout<<k<<j<<matrix[k][j]<<" ";
			alpha[s[i]-'a']=1;
			//cout<<alpha[matrix[k][j]-'a']<<" ";
			if(s[i]=='i'||s[i]=='j')
			{
				alpha[8]=1;
				alpha[9]=1;
			}
		}
	}
	for(int i=0;i<alpha.size();i++)
	{
		if(alpha[i]==0)
		{
			j=j+1;
			if(j==5)
			{
				k++;
				if(k==5)
				k=0;
				j=0;
			}	
			matrix[k][j]=i+'a';
			//cout<<k<<j<<matrix[k][j]<<"\t";
		}
	}
	cout<<"\n";
}
void pfc(string &s,char **matrix)
{
	for(int i=0;i<s.length()-1;i+=2)
	{
			
	}
}
void pfd(string &s,char **matrix)
{

}
int main()
{
	string pt;
	string ct;
	/**********************ceaser cipher***************************/
	cout<<"enter plain text to be ceaser ciphered :";
	getline(cin,pt);
	int k;
	cout<<"enter value of k : ";
	cin>>k;
	for(int i=0;i<pt.length();i++)
	{
		if(pt[i]>='a' && pt[i]<='z')
		pt[i]=(((pt[i]-'a')+k)%26)+'a';
		else if(pt[i]>='A' && pt[i]<='Z')
		pt[i]=(((pt[i]-'A')+k)%26)+'A';
	}
	cout<<"encoded ceaser text is :";
	cout<<pt<<"\n";
	cout<<"enter cipher text to be ceaser ciphered :";
	getline(cin,ct);
	getline(cin,ct);
	for(int i=0;i<ct.length();i++)
	{
		if(ct[i]>='a' && ct[i]<='z')
		ct[i]=(((ct[i]-'a')-k)%26)+'a';
		else if(ct[i]>='A' && ct[i]<='Z')
		ct[i]=(((ct[i]-'A')-k)%26)+'A';
	}
	cout<<"palin text of cipher ceaser is : ";
	cout<<ct<<"\n";
	/************************** mono alphabetic cipher***************************/ 
	map<char,int> mam;
	map<int,char> dmam;
	int a[26]={5,4,3,2,1,0,25,24,20,19,18,16,14,13,11,10,6,9,8,7,12,15,17,23,21,22};
	for(int i=0;i<26;i++)
	{
		char c=i+'a';
		mam[c]=a[i];
		//cout<<a[i]<<"\n";
		dmam[a[i]] = c;
	}	
	cout<<"enter plain text to be mono alphabetic ciphered :";
	getline(cin,pt);
	monoalphac(pt,mam);
	cout<<"encoded mono alphabetic text is :";
	cout<<pt<<"\n";
	cout<<"enter cipher text to be mono alphabetic to deciphered :";
	getline(cin,ct);
	monoalphad(ct,dmam);
	cout<<"decoded mono alphabetic text is :";
	cout<<ct<<"\n";
	/************************************ play fair cipher*********************************************/
	char **matrix;
	matrix = new char*[5];	
	for(int i=0;i<5;i++)
	matrix[i]= new char[5];
	string playfair;
	cout<<"enter play fair cipher : ";
	getline(cin,playfair);
	buildmatrix(matrix,playfair);
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		cout<<matrix[i][j]<<"\t";
		cout<<"\n";
	}
	cout<<"enter plain text to be play fair ciphered :";
	getline(cin,pt);
	int flag=1;
	if(pt.length()%2==1)
	pt = pt+"x";
	while(flag == 1)
	{
		flag = 0;
		for(int i=0;i<pt.length()-1;i++)
		{
			if(pt[i] == pt[i+1])
			{
				pt = pt.substr(0,i+1)+"x"+pt.substr(i+1,pt.length()-i+1);
				flag=1;
			}
		}
	}
	cout<<pt<<"\n";
	pfc(pt,matrix);
	cout<<"enter cipher text of platy fair  to deciphered :";
	getline(cin,ct);
	pfd(ct,matrix);
}
