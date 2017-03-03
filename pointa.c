#include<stdio.h>
#include<gmp.h>
void slop(mpz_t x1,mpz_t y1,mpz_t x2,mpz_t y2,mpz_t m,mpz_t p)
{ mpz_t r,s,x;
mpz_inits(r,s,x,NULL);
mpz_sub(r,x2,x1);
mpz_sub(s,y2,y1);
mpz_invert(x,r,p);
mpz_mul(m,s,x);
}
int main()
{
mpz_t x1,y1,x2,y2,x3,y3,m,c,mx,m2,p;
mpz_inits(x1,x2,y1,y2,x3,y3,m,c,mx,m2,p,NULL);
printf("enter point1:");
gmp_scanf("%Zd%Zd",x1,y1);
printf("enter point2:");
gmp_scanf("%Zd%Zd",x2,y2);
printf("enter the prime number:");
gmp_scanf("%Zd",p);
slop(x1,y1,x2,y2,m,p);
gmp_printf("slop is:%Zd",m);
mpz_mul(mx,m,x1);
mpz_sub(c,y1,mx);
mpz_mul(m2,m,m);
mpz_sub(m2,m2,x1);
mpz_sub(x3,m2,x2);

mpz_add(mx,mx,c);
mpz_set(y3,mx);
mpz_neg(y3,y3);
gmp_printf("point3 is:%Zd%Zd",x3,y3);


}
