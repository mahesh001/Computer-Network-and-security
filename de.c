#include<gmp.h>
#include<stdio.h>

long long int power( int a,int b,int n)
{
long long int t;
if(b==1)
return a;
else{
t=power(a,b/2,n);
if(b%2==0){
return (t*t)%n;
}
else
return (((t*t)%n)*a)%n;
}
}
long long int calkey(int a, int x, int n)
{
return power(a,x,n);
}
int main()
{
int a,b,n,g,x,y;
printf("enter the value of n and g");
scanf("%d%d",&n,&g);
printf("enter the value for 1st person");
scanf("%d",&x);
a=power(g,x,n);
printf("enter the value of y for second");
scanf("%d",&y);
b=power(g,y,n);
printf("key for 1:%lld",power(b,x,n));
printf("key for 1:%lld",power(a,y,n));
return 0;
}
