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
       cout<<"welcome";
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
			cout<<k<<" "<<j<<matrix[k][j]<<" ";
			alpha[s[i]-'a']=1;
			cout<<alpha[matrix[k][j]-'a']<<"\n";
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
			if(i==8)
			{
				alpha[9]=1;
			}
			cout<<k<<" "<<j<<matrix[k][j]<<"\n";
		}
		
	}
	cout<<"\n";
}
void pfc(string &s,char **matrix,map<char,int> xc,map<char,int> yc)
{
	for(int i=0;i<s.length()-1;i+=2)
	{
		char a= s[i];
		char b = s[i+1];
		int i1 = xc[a];
		int j1 = yc[a];
		int i2 = xc[b];
		int j2 = yc[b];
		if(i1 == i2)
		{	
			j1=(j1+1)%5;
			s[i] = matrix[i1][j1];
			j2=(j2+1)%5;
			s[i+1]= matrix[i2][j2];
		}
		else if(j1 == j2)
		{
			i1=(i1+1)%5;
			s[i] = matrix[i1][j2];
			i2=(i2+1)%5;
			s[i+1]= matrix[i2][j2];
		}
		else
		{
			s[i] = matrix[i1][j2];
			s[i+1] = matrix[i2][j1];
		}		
	}
}
void pfd(string &s,char **matrix,map<char,int> xc,map<char,int> yc)
{
	for(int i=0;i<s.length()-1;i+=2)
	{
		char a= s[i];
		char b = s[i+1];
		int i1 = xc[a];
		int j1 = yc[a];
		int i2 = xc[b];
		int j2 = yc[b];
		if(i1 == i2)
		{	
			j1=(5+j1-1)%5;
			s[i] = matrix[i1][j1];
			j2=(5+j2-1)%5;
			s[i+1]= matrix[i2][j2];
		}
		else if(j1 == j2)
		{
			i1=(5+i1-1)%5;
			s[i] = matrix[i1][j2];
			i2=(5+i2-1)%5;
			s[i+1]= matrix[i2][j2];
		}
		else
		{
			s[i] = matrix[i1][j2];
			s[i+1] = matrix[i2][j1];
		}		
	}
}
void pac(string &s,string &key)
{
	for(int i=0; i<s.length(); i++)
	{
		int k = key[i]-'a';
		int c = s[i]-'a';
		s[i] = ((c+k)%26)+'a';
	}
}
void pad(string &s,string &key)
{
	for(int i=0; i<s.length(); i++)
	{
		int k = key[i]-'a';
		int c = s[i]-'a';
		s[i] = ((26+(c-k))%26)+'a';
	}
}
void otpc(string &s,string key)
{
	for(int i=0; i<s.length(); i++)
	{
		int k,c;
		if(key[i] >='a' && key[i] <= 'z')
		k = key[i]-'a';
		else
		k = 26;
		if(s[i] >='a' && s[i] <= 'z')
		c = s[i]-'a';
		else
		c = 26;
		c = ((c+k)%27);
		if(c == 26)
		s[i] = ' ';
		else
		s[i] = c+'a';
	}
}
void otpd(string &s,string key)
{
	for(int i=0; i<s.length(); i++)
	{
		int k,c;
		if(key[i] >='a' && key[i] <= 'z')
		k = key[i]-'a';
		else
		k = 26;
		if(s[i] >='a' && s[i] <= 'z')
		c = s[i]-'a';
		else
		c = 26;
		//cout<<c<<" "<<k<<" ";
		c = ((27+(c-k))%27);
		//cout<<c<<"\n";
		if(c == 26)
		s[i] = ' ';
		else
		s[i] = c+'a';
	}
}
int main()
{
	string pt;
	string ct;
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
		ct[i]=((26+(ct[i]-'a')-k)%26)+'a';
		else if(ct[i]>='A' && ct[i]<='Z')
		ct[i]=((26+(ct[i]-'A')-k)%26)+'A'; 
	}
	cout<<"plain text of cipher ceaser is : ";
	cout<<ct<<"\n";
	/* mono alphabetic cipher*/ 
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
	char **matrix;
	matrix = new char*[5];	
	for(int i=0;i<5;i++)
	matrix[i]= new char[5];
	string playfair;
	cout<<"enter play fair cipher : ";
	getline(cin,playfair);
      //cout<<"i m here";
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
	if(pt.length()%2==1)
	pt = pt+"x";
	cout<<pt<<"\n";
	map<char,int> xc;
	map<char,int> yc;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			char c = matrix[i][j];
			xc[c] = i;
			yc[c] = j;
			if(c =='i')
			{
				xc[c+1] = i;
				yc[c+1] = j;
			}
			if(c =='j')
			{
				xc[c-1] = i;
				yc[c-1] = j;
			}
		}
	}
	pfc(pt,matrix,xc,yc);
	cout<<"play faired cipher text is :"<<pt<<"\n";
	cout<<"enter cipher text of platy fair  to deciphered :";
	getline(cin,ct);
	pfd(ct,matrix,xc,yc);
	cout<<"plain text is : "<<ct<<"\n";
	/*matrix=NULL;
	//hill cipher//
	cout<<"enter plain text to be ciphered : ";
	getline(cin,pt);
	//to do
	cout<<"hill ciphered cipher text is : "<<pt<<"\n";
	cout<<"enter cipher text to be deciphered : ";
	getline(cin,ct);
	//to do
	cout<<"plain text is : "<<ct<<"\n";*/
	/*poly alphabetic cipher*/
	cout<<"enter plain text to be poly alphabetic ciphered : ";
	getline(cin,pt);
	cout<<"enter key :";
	string key;
	getline(cin,key);
	pac(pt,key);
	cout<<"poly alphabetic encryped text is : "<<pt<<"\n";
	cout<<"enter  poly alphabetic ciphered text to be deciphered : ";
	getline(cin,ct);
	pad(ct,key);
	cout<<"plain text is : "<<ct<<"\n";
	/*one time pad */
	cout<<"enter plain text to be one time pad ciphered : ";
	getline(cin,pt);
	cout<<"enter key :";
	getline(cin,key);
	otpc(pt,key);
	cout<<"one time pad encryped text is : "<<pt<<"\n";
	cout<<"enter onetimepad ciphered text to be deciphered : ";
	getline(cin,ct);
	cout<<"enter key :";
	getline(cin,key);
	otpd(ct,key);
	cout<<"plain text is : "<<ct<<"\n";
}

