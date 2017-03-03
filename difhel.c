
#include<stdio.h>
#include<gmp.h>

void genkeys(mpz_t XA,mpz_t YA, mpz_t q,mpz_t g,gmp_randstate_t state)
{
mpz_urandomm(XA,state,q);
mpz_powm(YA,g,XA,q);
}
void secreatekey(mpz_t k,mpz_t X,mpz_t Y,mpz_t q)
{
mpz_powm(k,Y,X,q);
}
void generator(mpz_t g,mpz_t tq,mpz_t p, mpz_t q)
{
mpz_t a,t1,t2,p2;
mpz_inits(a,t1,t2,p2,NULL);
gmp_randstate_t state;
gmp_randinit_default(state);
mpz_set_ui(p2,2);
while(1)
{
mpz_urandomm(a,state,q);
mpz_powm(t1,a,p2,q);
mpz_powm(t2,a,p,q);
 if(mpz_cmp_ui(t1,1)!=0 && mpz_cmp_ui(t2,1)!=0)
break;
}
mpz_set(g,a);
}

int main()
{
mpz_t XA,YA,XB,YB,p,q,g,k,tq,t;
mpz_inits(XA,YA,XB,YB,p,q,g,k,tq,t,NULL);
gmp_randstate_t state;
gmp_randinit_default(state);
mpz_urandomb(p,state,10);
while(mpz_cmp_ui(t,1)!=0)
{
mpz_nextprime(p,p);mpz_mul_ui(tq,p,2);
mpz_nextprime(q,tq);
mpz_sub(t,q,tq);
}
gmp_printf("p=%Zd\n",p);
gmp_printf("q=%Zd\n",q);
generator(g,tq,p,q);

gmp_printf("g=%Zd\n",g);
genkeys(XA,YA,q,g,state);
gmp_printf("XA=%Zd\n",XA);
gmp_printf("YA=%Zd\n",YA);
genkeys(XB,YB,q,g,state);
gmp_printf("XB=%Zd\n",XB);
gmp_printf("YB=%Zd\n",YB);
secreatekey(k,XA,YB,q);
gmp_printf("k=%Zd\n",k);
secreatekey(k,XB,YA,q);
gmp_printf("k=%Zd\n",k);
}






