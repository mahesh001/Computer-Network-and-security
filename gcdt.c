#include<stdio.h>
#include<gmp.h>
int main ()
{
mpz_t n,r0,r1,q,t;
mpz_init(r0);
mpz_init(r1);
mpz_init(t);
mpz_init(q);
mpz_init(n);
gmp_scanf("%Zd",r0);
gmp_scanf("%Zd",r1);
mpz_set_ui(n,0);
while(mpz_cmp(r1,n)!=0)
{

 mpz_fdiv_r(t,r0,r1);
 mpz_set(r0,r1);
 mpz_set(r1,t);
}
printf("gcd=");
mpz_abs(r0,r0);
gmp_printf("%Zd",r0);
printf("\n");
mpz_clear(r0);
mpz_clear(r1);
mpz_clear(t);
mpz_clear(q);
return 0;
}



