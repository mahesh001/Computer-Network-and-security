#include<bits/stdc++.h>
using namespace std;
void print(vector<char> c)
{
	for(int i=0;i<c.size();i++)
	cout<<c[i];
}
vector<char> add(vector<char> a,vector<char> b);
int cmp(vector<char> a,vector<char> b)
{
	if(a[0]=='-' && b[0]=='-')
	{
		a.erase(a.begin());
		b.erase(b.begin());
		int r = cmp(a,b);
		if(r<0)
		return 1;
		else if(r>0)
		return -1;
		else 
		return 0;		
	}
	if(a[0]=='-' || a.size()<b.size())
	{
		return -1;
	}
	else if(b[0]=='-' || a.size()>b.size())
	{
		return 1;
	}
	else
	{
		for(int i=a.size()-1;i>=0;i--)
		{
			if(a[i]>b[i])
				return 1;
			else if(b[i]>a[i])
				return -1;
		}
		return 0;
	}
}
vector<char> sub(vector<char> a,vector<char> b)
{
	if(a[0]=='-')
	{
		a.erase(a.begin());
		vector<char> c= add(a,b);
		if(c[0]!='-')
		c.insert(c.begin(),'-');
		else
		c.erase(c.begin());
		return c;
	}
	else if(b[0]=='-')
	{
		b.erase(b.begin());
		return add(a,b);
	}
	else
	{
		int alen = a.size()-1;
		int blen = b.size()-1;
		vector<char> c;
		if(alen<blen)
		{
			c= sub(b,a);
			c.insert(c.begin(),'-');
			return c;
		}
		else
		{
			int borrow=0;
			for(int i=0;i<=blen;i++)
			{
				int cdif = a[alen-i]-'0'-(b[blen-i]-'0')-borrow;
				if(cdif<0)
				{
					cdif +=10;
					borrow=1;
					c.insert(c.begin(),cdif+'0');
				}
				else
				{
					borrow=0;
					c.insert(c.begin(),cdif+'0');
				}
			}
			for(int i=alen-blen-1;i>=0;i--)
			{
				int cdif = a[i]-'0'-borrow;
				if(cdif<0)
				{
					cdif +=10;
					borrow=1;
					c.insert(c.begin(),cdif+'0');
				}
				else
				{
					borrow=0;
					c.insert(c.begin(),cdif+'0');
				}
			}
			if(borrow == 1)
			{
				vector<char> temp(c.size()+1,'0');
				temp[0]='1';
				c=sub(temp,c);
				while(c[0]=='0')
				c.erase(c.begin());
				c.insert(c.begin(),'-');
			}
			return c;
		}
	}
}
vector<char> add(vector<char> a,vector<char> b)
{
	if(a[0]=='-')
	{
		a.erase(a.begin());
		return sub(b,a);
	}
	else if(b[0]=='-')
	{
		b.erase(b.begin());
		return sub(a,b);
	}
	if(a.size()<b.size())
	return add(b,a);
	int blen = b.size()-1;
	int alen = a.size()-1;
	int carry = 0;
	vector<char> c;
	for(int i = 0;i<=blen;i++)
	{
		int csum  = a[alen - i]-'0'+b[blen - i]-'0'+carry;
		c.insert(c.begin(),csum%10+'0');
		carry = csum/10;
	}
	for(int i=alen-blen-1;i>=0;i--)
	{
		int csum = a[i]-'0'+carry;
		c.insert(c.begin(),csum%10+'0');
		carry = carry/10;
	}
	if(carry == 1)
	c.insert(c.begin(),1+'0');
	return c;
}
vector<char> mod(vector<char> a,vector<char> b)
{
	vector<char> zero(1,'0');
	vector<char> tempb = add(b,b);
	cout<<"tempb is :";
	print(tempb);
	cout<<"\n";
	if(tempb == a)
	{
		cout<<"here\n";
		return zero;
	}
	else if(tempb > a)
	{
		cout<<"here\n";
		return sub(a,b);
	}
	else
	 return mod(a,tempb);
}
vector<char> addmodn(vector<char> a,vector<char> b,vector<char> n)
{
	vector<char> zero(1,'0');
	vector<char> tempa,tempb; 
	if(a==n)
	{
		tempa = zero;
	}
	else if(a>n)
	{
		tempa = mod(a,n);
	}
	else
	{
		tempa = a;
	}
	if(b==n)
	{
		tempb = zero;
	}
	else if(b>n)
	{
		tempb = mod(b,n);
	}
	else
	{
		tempb = b;		
	}
	vector<char> sum = add(tempa,tempb);
	if(sum<n)
		return sum;
	else if(sum==n)
		return zero;
	else
		return mod(sum,n);
}

int main()
{
	string num1,num2,num3;
	getline(cin,num1);
	getline(cin,num2);
	getline(cin,num3);
	vector<char> a(num1.begin(),num1.end());
	vector<char> b(num2.begin(),num2.end());
	vector<char> n(num3.begin(),num3.end());
	vector<char> c = addmodn(a,b,n);
	print(c);
	cout<<"\n";
	/*print(a);
	cout<<"   +  ";
	print(b);
	cout<<"  is  ";
	print(c);
	cout<<"\n";
	c = sub(a,b);
	print(a);
	cout<<"   -  ";
	print(b);
	cout<<"  is  ";
	print(c);
	cout<<"\n";*/
		
}
