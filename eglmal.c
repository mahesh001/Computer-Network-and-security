
#include<stdio.h>
#include<gmp.h>

void genkeys(mpz_t XA,mpz_t YA, mpz_t q,mpz_t g,gmp_randstate_t state)
{
mpz_t t;
mpz_inits(t,NULL);
mpz_sub_ui(t,q,1);
mpz_urandomm(XA,state,t);
mpz_powm(YA,g,XA,q);
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
void encrypt(mpz_t c1,mpz_t c2,mpz_t YB,gmp_randstate_t state,mpz_t g,mpz_t q,mpz_t M)
{
mpz_t K,k;
mpz_inits(K,k,NULL);
mpz_urandomm(k,state,q);
mpz_powm(K,YB,k,q);
mpz_powm(c1,g,k,q);
mpz_mul(c2,K,M);
mpz_mod(c2,c2,q);

}
void decrypt(mpz_t c1,mpz_t c2,mpz_t XB,mpz_t q,mpz_t M)
{
mpz_t K;
mpz_inits(K,NULL);
mpz_powm(K,c1,XB,q);
mpz_invert(K,K,q);
mpz_mul(M,K,c2);
mpz_mod(M,M,q);
}
int main()
{
mpz_t XA,YA,XB,YB,p,q,g,k,tq,t,M,c1,c2;
mpz_inits(XA,YA,XB,YB,p,q,g,k,tq,t,M,c1,c2,NULL);
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
printf("enter M:");
gmp_scanf("%Zd",M);
encrypt(c1,c2,YB,state,g,q,M);
gmp_printf("c1=%Zd\n",c1);
gmp_printf("c2=%Zd\n",c2);
decrypt(c1,c2,XB,q,M);
gmp_printf("M=%Zd\n",M);
}






