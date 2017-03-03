#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<gmp.h>


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

int main ()
{
mpz_t a,b,x,y;
int t=10;
mpz_init(a);
mpz_init(b);
mpz_init(x);
mpz_init(y);
while(t--){
gmp_scanf("%Zd",a);
gmp_scanf("%Zd",b);
exte(x,y,a,b);
}
mpz_clear(a);
mpz_clear(b);
mpz_clear(x);
mpz_clear(y);

return 0;
}



