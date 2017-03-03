#include<bits/stdc++.h>
using namespace std;
int inv(int a,int m)
{
int m0=m,t,q;
int x0=0,x1=1;
if(m==1)
return 0;
while(a>1)
{
q=a/m;
t=m;
m=a%m;
a=t;
t=x0;
x0=x1-q*x0;
x1=t;
}
if(x1<0)
x1+=m0;

return x1;
}

int find_minX(int num[],int rem[],int k)
{
int i,x=1;
for(i=0;i<k;i++)
x*=num[i];
int res=0;
for(i=0;i<k;i++){
int y=x/num[i];
res+=rem[i]*inv(y,num[i])*y;
}
return res%x;
}
int main()
{
int num[]={3,4,5,7,11,17};
int rem[]={2,3,1,4,5,2};
int k=sizeof(num)/sizeof(num[0]);
cout<<"x is:"<<find_minX(num,rem,k);
cout<<"\n";
return 0;
}
