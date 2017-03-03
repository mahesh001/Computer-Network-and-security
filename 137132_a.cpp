#include<bits/stdc++.h>
#include"137132_b.h"
using namespace std;
string key,K,K_,C[17],D[17],k[17],msg,M,IP_,L[17],R[17];
void print(string str,int gap)
{
	int l=str.length();
	for(int i=0;i<str.length();i++)
	{
		cout<<str[i];
		if(i%gap==gap-1)
			cout<<" ";
	}
	cout<<endl;
}
string XOR(string s1,string s2)
{
	string res="";
	int l=s1.length();
	for(int i=0;i<l;i++)
	{
		if(s1[i]==s2[i])
			res+="0";
		else
			res+="1";
	}
	return res;
}

string hexToBinary(string str)
{
	string result="",temp;
	int l=str.length(),num;
	for(int i=0;i<l;i++)
	{
		if((str[i]>='0')&&(str[i]<='9'))
		num=str[i]-'0';
		else
		num=10+str[i]-'A';
		string res="";
		for(int j=0;j<4;j++)
		{
			temp=res;
			res=num%2?"1":"0";
			res+=temp;
			num=num/2;
		}	
		result+=res;
	}
	return result;
}
string binaryToHex(string str)
{
	int l=str.length();
	string res="";
	for(int i=0;i<l;i+=4)
	{
		int num=8*(str[i]-48)+4*(str[i+1]-48)+2*(str[i+2]-48)+(str[i+3]-48);
		if(num<10)
			res+=(char)(num+48);
		else
			res+=(char)('A'+num-10);
	}
	return res;
}
string permute(string key,int map[],int size)
{
	string res="";
	for(int i=0;i<size;i++)
	{
		res+=key[map[i]-1];
	}
	return res;
}
string shiftBytes(string str,int n)
{
	string res="";
	res+=str.substr(n);
	res+=str.substr(0,n);
	return res;
}
string encrypt_decrypt(string msg,int tag)
{
	M=hexToBinary(msg);
	cout<<"M = ";print(M,4);
	IP_=permute(M,IP,16);
	cout<<"C0 = ";print(IP_,4);
	L[0]=IP_.substr(0,10);
	R[0]=IP_.substr(10,16);
	cout<<"L[0] = ";print(L[0],10);
	cout<<"R[0] = ";print(R[0],6);
	cout<<endl;
	
		L[1]=R[0];
                cout<<"L[1] = ";print(L[1],6);
		string temp;
		if(tag)
		temp=XOR(permute(R[0],E,8),k[1]);
		else
		temp=XOR(permute(R[0],E,8),k[1]);
		string sBoxed="";
		for(int j=1;j<8;j+=2)
		{
			int row=(temp[j])+(temp[j+1]);
			int col=(temp[j-1])+(temp[j+1]);
			int n=S[j/2][row][col];
			string x="";
			if(n<=2)
				x+=(char)(n+8);
			else
				x+=(char)('A'+n-2);
			sBoxed+=hexToBinary(x);
		}
		R[1]=XOR(L[0],permute(sBoxed,P,10));	
		cout<<"R[1] = ";print(R[1],10);
		cout<<endl;
	
	string res=R[1]+L[1];
	res=permute(res,FP,16);
	return binaryToHex(res);
}
int main()
{
	cout<<"Enter the hexadecimal key : ";
	cin>>key;
	K=hexToBinary(key);
	cout<<"K = ";print(K,8);
	cout<<endl;
	K_=permute(K,PC1,8);
	cout<<"K+ = ";print(K_,8);
	cout<<endl;
	C[0]=K_.substr(0,4);
	D[0]=K_.substr(4,8);
	cout<<"C[0] = ";print(C[0],7);
	cout<<"D[0] = ";print(D[0],7);
	cout<<endl;
	for(int i=1;i<=2;i++)
	{
		C[i]=shiftBytes(C[i-1],shift[i-1]);
		D[i]=shiftBytes(D[i-1],shift[i-1]);
		cout<<"C["<<i<<"] = ";print(C[i],7);
		cout<<"D["<<i<<"] = ";print(D[i],7);
		cout<<endl;
	}
	for(int i=1;i<=2;i++)
	{
		k[i]=permute(C[i]+D[i],PC2,8);
		cout<<"K["<<i<<"] = ";print(k[i],7);
	}
	cout<<"Enter Hexadecimal message to encrypt : ";
	cin>>msg;
	cout<<"Encrypted Text : "<<encrypt_decrypt(msg,0)<<endl;
	/*cout<<"Enter Hexadecimal message to decrypt : ";
	cin>>msg;
	cout<<"Decrypted Text : "<<encrypt_decrypt(msg,1)<<endl;*/	
}
//133457799BBCDFF1
//0123456789ABCDEF
//85E813540F0AB405



