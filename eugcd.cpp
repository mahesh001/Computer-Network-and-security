#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
void getgcd(mpz_t gcd,const mpz_t a,const mpz_t b)
{
	
	mpz_t tempa,tempb,temp,zero;
	mpz_inits(tempa,tempb,temp,zero,NULL);
	mpz_set(tempa,a);
	mpz_set(tempb,b);
	while(mpz_cmp(tempb,zero)!=0)
	{
		mpz_set(temp,tempb);
		mpz_mod(tempb,tempa,tempb);
		mpz_set(tempa,temp);
	}
	if(mpz_cmp(tempa,zero)<0)
	{
		mpz_sub(tempa,zero,tempa);
	}	
	mpz_set(gcd,tempa);
	mpz_clears(tempa,tempb,temp,NULL);
}
int main()
{
	int bit = 10;
	clock_t start,end;
	mpz_t a,b,gcd;
	mpz_inits(a,b,NULL);
	gmp_randstate_t state;
	gmp_randinit_default(state);
	for(int i=0;i<5;i++)
	{
	mpz_urandomb(a,state,bit);
	mpz_urandomb(b,state,bit);
	//gmp_printf("gcd of \t%Zd  ,  %Zd  = \t",a,b);
	mpz_init(gcd);
	start = clock();
	getgcd(gcd,a,b);
	end = clock();
	//gmp_printf("%Zd\n",gcd);
	float time = (float)(end-start);
	gmp_printf(" time for %d is %.lf  micro seconds\n",bit,time);
	bit*=10;
	}
	mpz_clears(a,b,gcd,NULL);
	return 0;
}
