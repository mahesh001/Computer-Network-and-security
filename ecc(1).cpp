#include<iostream>
#include<gmp.h>
using namespace std;
struct point
{
	mpz_t x;
	mpz_t y;

	point()
	{
		mpz_init(x);
		mpz_init(y);
	}
};



int main()
{

	point a,b,c;
	gmp_scanf("%Zd%Zd",a.x,a.y);
	gmp_scanf("%Zd%Zd",b.x,b.y);
	mpz_t m; mpz_init(m);
	mpz_t p; mpz_init(p);
	mpz_set_ui(p,29);
	mpz_t k1,k2; 
        mpz_inits(k1,k2,NULL);
	mpz_sub(k1,b.y,a.y);
	mpz_sub(k2,b.x,a.x);
	mpz_t k3; mpz_init(k3);
	mpz_invert(k3,k2,p);
	mpz_mul(m,k1,k3);
	mpz_t m2; mpz_init(m2);
	mpz_mul(m2,m,m);
	mpz_sub(m2,m2,a.x);
	mpz_sub(c.x,m2,b.x);
	mpz_mod(c.x,c.x,p);
	mpz_sub(m2,a.x,c.x);
	mpz_mul(m2,m2,m);
	mpz_sub(c.y,m2,a.y);
	mpz_mod(c.y,c.y,p);
	gmp_printf(" %Zd  %Zd \n",c.x,c.y);
}
