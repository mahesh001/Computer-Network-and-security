
#include<stdio.h>
#include<gmp.h>
void gcd(mpz_t a,mpz_t b)
{
mpz_abs(a,a);
mpz_abs(b,b);
mpz_t e;
mpz_init(e);
if(mpz_cmp(a,e)==0)
{
mpz_out_str(NULL,10,b);
return;
}
else if(mpz_cmp(b,e)==0)
{
mpz_out_str(NULL,10,a);
return ;
}
while(mpz_cmp(a,b)!=0)
{
if(mpz_cmp(a,b)>0)
mpz_sub(b,b,a);
}
}
void exte(mpz_t x,mpz_t y,mpz_t u,mpz_t v)
{
mpz_t r0,r1,q0,q1,m,t,t1,c;
mpz_init(r0);
mpz_init(r1);
mpz_init(q0);
mpz_init(q1);

mpz_init(m);
mpz_init(t);
mpz_init(t1);
mpz_init(c);
mpz_set(r0,u);
mpz_set(r1,v);
if(!mpz_cmp(r1,c))
    {
       mpz_clear(c);
       mpz_set_ui(x,1);
        mpz_set_ui(y,0);
return;
    }
mpz_set(t1,y);
mpz_mod(t,r0,r1);
exte(x,y,r1,t);
mpz_sub(q0,x,t);
mpz_cdiv_q(q1,q0,r1);
mpz_mul(m,q1,y);
mpz_sub(t,x,m);
mpz_set(y,t);
mpz_set(x,t1);
gmp_printf("%Zd %Zd",x,y);
mpz_clear(t1);
mpz_clear(m);
mpz_clear(t);
mpz_clear(q0);


}
void div(mpz_t a,mpz_t b,mpz_t n)
{
mpz_t y,t1,t2,x,e;
mpz_init(y);
mpz_init(t1);
mpz_init(t2);
mpz_init(x);
mpz_set(t2,b);
mpz_init(e);
mpz_set_d(e,1);
gmp_printf("hii");
gcd(t2,n);
gmp_printf("hii");
if(!mpz_cmp(t2,e))
{
exte(x,y,a,b);
mpz_mul(t1,y,a);
mpz_mod(t1,t1,n);
gmp_printf("(a/b)modn=%Zd",t1);
}
else
printf("not possible\n");
}
void add(mpz_t a,mpz_t b,mpz_t n)
{
mpz_t t,t1,t2,x;
mpz_init(t);
mpz_init(t1);
mpz_init(t2);
mpz_init(x);
mpz_mod(t,a,n);
mpz_mod(t1,b,n);
mpz_add(t2,t,t1);
mpz_mod(x,t2,n);

gmp_printf("(a+b)modn=%Zd",x);
printf("\n");
}
void sub(mpz_t a,mpz_t b,mpz_t n)
{
mpz_t t,t1,t2,x;
mpz_init(t);
mpz_init(t1);
mpz_init(t2);
mpz_init(x);
mpz_mod(t,a,n);
mpz_mod(t1,b,n);
mpz_sub(t2,t,t1);
mpz_mod(x,t2,n);
gmp_printf("(a-b)modn=%Zd",x);
printf("\n");
}
void mul(mpz_t a,mpz_t b,mpz_t n)
{
mpz_t t,t1,t2,x;
mpz_init(t);
mpz_init(t1);
mpz_init(t2);
mpz_init(x);
mpz_mod(t,a,n);
mpz_mod(t1,b,n);
mpz_mul(t2,t,t1);
mpz_mod(x,t2,n);
gmp_printf("(a*b)modn=%Zd",x);
printf("\n");
}

int main()
{
mpz_t a,b,n,x,y,z;
mpz_init(a);
mpz_init(b);
mpz_init(n);
mpz_init(x);
mpz_init(y);
mpz_init(z);
gmp_printf("enter the value of a,b,n");
gmp_scanf("%Zd",a);

gmp_scanf("%Zd",b);

gmp_scanf("%Zd",n);
add(a,b,n);
sub(a,b,n);
mul(a,b,n);
div(a,b,n);

}
