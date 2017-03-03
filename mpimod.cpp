#include<bits/stdc++.h>
using namespace std;
vector<char> add(vector<char> a,vector<char> b);
void print(vector<char> c)
{
	for(int i=0;i<c.size();i++)
	cout<<c[i];
}
int cmp(vector<char> a,vector<char> b)
{
	if(a==b)
	return 0;
	else if(a[0]=='-' && b[0]=='-')
	{
		a.erase(a.begin());
		b.erase(b.begin());
		if(cmp(a,b) == 0)
		return 0;
		else if (cmp(a,b)>0 )
		return -1;
		else
		return 1;
	}
	else if(a[0]=='-')
	{
		return -1;
	}
	else if(b[0]=='-')
	{
		return 1;
	}
	else if(a.size()<b.size())
	{
		return -1;
	}
	else if(a.size()>b.size())
	{
		return 1;
	}
	else if(a.size()==0 && b.size()==0)
		return 0;
	else if(a.size()==b.size())
	{
		if(a[0]>b[0])
			return 1;
		else if(a[0]<b[0])
			return -1;
		else
		{
			a.erase(a.begin());
			b.erase(b.begin());
			return cmp(a,b);
		}
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
			while(c[0]=='0' && c.size()>1)
			c.erase(c.begin());
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
vector<char> sum(vector<vector<char> > prod)
{
	vector<char> tsum=prod[0];
	for(int i=1;i<prod.size();i++)
	{
		tsum =add(prod[i],tsum);
	}
	if(tsum[0]=='0' && tsum.size()>1)
	tsum.erase(tsum.begin());
	return tsum;
}
vector<char> mul(vector<char> a,vector<char> b)
{
	int neg = 0;
	if(a[0]=='-')
	{
		a.erase(a.begin());
		neg = (neg+1)%2;
	}
	if(b[0]=='-')
	{
		b.erase(b.begin());
		neg = (neg+1)%2;
	}
	int alen = a.size();
	int blen = b.size();
	if(alen<blen)
	return mul(b,a);
	int carry=0;
	vector<vector<char> >prod(blen,vector<char> (alen+1));
	for(int i = 0; i< blen ; i++)
	{
		for(int j=0 ; j<alen ; j++)
		{
			int sp = (a[alen-1-j]-'0') *(b[blen-1-i]-'0')+carry;
			prod[i][alen-j]=sp%10+'0';
			carry = sp/10;
		}
		prod[blen-1-i][0]=carry+'0';
		for(int k=1;k<=i;k++)
		{
			prod[i].insert(prod[i].end(),'0');
		}
	}
	if(prod.size()==1)
	return prod[0];
	else
	return sum(prod);
}
vector<char> mod(vector<char> a,vector<char> n)
{
	static vector<char> zero(1,'0');
	if(a[0]=='-')
	{
		a.erase(a.begin());
		return (sub(n,mod(a,n)));
	}
	if(a==n)
	return zero;
	else if(cmp(a,n)<0)
	{
		return a;
	}
	else
	{
		a = sub(a,n);
		return mod(a,n);
	}
}
vector<char> mod_add(vector<char> a,vector<char> b,vector<char> n)
{
	a = mod(a,n);
	b= mod(b,n);
	vector<char> sum = add(a,b);
	return mod(sum,n);	
}
vector<char> mod_sub(vector<char> a,vector<char> b,vector<char> n)
{
	a=mod(a,n);
	b=mod(b,n);
	vector<char> diff = sub(a,b);
	return mod(diff,n);
}
vector<char> mod_mul(vector<char> a,vector<char> b,vector<char> n)
{
	static vector<char> zero(1,'0');
	a=mod(a,n);
	b=mod(b,n);
	if(a==zero || b == zero)
	return zero;
	else
	{
		vector<char> prod = mul(a,b);
		return mod(prod,n);
	}
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
	vector<char> sum = mod_add(a,b,n);
	print(a);
	cout<<"   +  ";
	print(b);
	cout<<" mod ";
	print(n);
	cout<<"  is  ";
	print(sum);
	cout<<"\n";
	sum = mod_sub(a,b,n);
	print(a);
	cout<<"   -  ";
	print(b);
	cout<<" mod ";
	print(n);
	cout<<"  is  ";
	print(sum);
	cout<<"\n";
	vector<char> prod = mod_mul(a,b,n);
	print(a);
	cout<<"  *  ";
	print(b);
	cout<<" mod ";
	print(n);
	cout<<"  is  ";
	print(prod);
	cout<<"\n";
}
