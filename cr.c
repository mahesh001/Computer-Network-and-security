
#include<gmp.h>
#include<stdio.h>
int i;
void getm(mpz_t M,mpz_t m[],int n)
{
mpz_set_ui(M,1);
for(i=0;i<n;i++){
mpz_mul(M,M,m[i]);
}
}
int main()
{
int n;
mpz_t x;
printf("enter the number");
scanf("%d",n);
mpz_t a[n];
mpz_t m[n];
mpz_t mi[n];
mpz_t ci[n];
for( i=0;i,n;i++)
{
mpz_init(a[i],NULL);
mpz_init(m[i],NULL);
mpz_init(ci[i],NULL);
mpz_init(mi[i],NULL);
}
mpz_init(x,NULL);
for( i=0;i<n;i++)
{
printf("enter a[%d",i+1,"]and m[%d",i+1,"]");
scanf("%d ,%d" a[i],m[i]);
}
mpz_t M;
mpz_init(M,NULL);
getm(M,m,n);
printf("%d",M );
printf("\n");
mpz_set_ui(x,0);
for( i=0;i<n;i++)
{
mpz_divexact(ci[i],M,m[i]);
mpz_invert(mi[i],ci[i],m[i]);
printf("invert of%d"m[i]"is:%d"mi[i]"\n");
mpz_mul(ci[i],mi[i],ci[i]);
mpz_mul(ci[i],ci[i],a[i]);
mpz_add(x,x,ci[i]);
}
mpz_mod(x,x,M);
cout<<x<<"\n";
mpz_t t;
mpz_init(t,NULL);
for( i=0;i,n;i++)
{

mpz_set(t,x);
mpz_mod(t,x,m[i]);
printf("%d",x,"mod/%d",m[i],"=%d",t,"\n");
return 0;
}
}

