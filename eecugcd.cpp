#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
void getxy(mpz_t x,mpz_t y,mpz_t r,const mpz_t a,const mpz_t b)
{
	
	mpz_t x0,y0,x1,y1,x2,y2,r1,r2,q,zero,mul,sub;
	mpz_inits(q,x0,y0,x1,y1,x2,y2,zero,mul,sub,r1,r2,NULL);
	mpz_set_ui(x0,1);
	mpz_set_ui(y1,1);
	mpz_set(r1,a);
	mpz_set(r2,b);
	gmp_printf("%Zd\t%Zd\n",r1,r2);
	while(1)
	{
		mpz_fdiv_qr(q,r,r1,r2);
		if(mpz_cmp_ui(r,0)==0)
		break;
		mpz_set(r1,r2);
		mpz_set(r2,r);
		mpz_mul(mul,q,x1);
		mpz_sub(sub,x0,mul);
		mpz_set(x2,sub);
		mpz_mul(mul,q,y1);
		mpz_sub(sub,y0,mul);
		mpz_set(y2,sub);
		mpz_set(x0,x1);
		mpz_set(y0,y1);
		mpz_set(x1,x2);
		mpz_set(y1,y2);
		gmp_printf("%Zd\t%Zd\t%Zd\t%Zd\n",q,r,x2,y2);
	}
	mpz_set(x,x1);
	mpz_set(y,y1);
	mpz_set(r,r2);
	mpz_clears(q,x0,y0,x1,y1,x2,y2,zero,mul,sub,r1,r2,NULL);
}
int main()
{
	mpz_t a,b,x,y,r;
	
	mpz_inits(a,b,x,y,r,NULL);
	
	for(int i=0;i<5;i++)
	{
	
	gmp_scanf("%Zd%Zd",a,b);
	if(mpz_cmp_ui(a,0)!=0 && mpz_cmp_ui(b,0) != 0)
	{
		getxy(x,y,r,a,b);
		gmp_printf("x:%Zd\ty:%Zd\tgcd:%Zd\n",x,y,r);
	}
	else 
	{
		if(mpz_cmp_ui(a,0)==0){
			mpz_abs(b,b);			
			cout<<"x:1\ty:-1\tgcd:"<<b<<"\n";
		}
		if(mpz_cmp_ui(b,0)==0){
			mpz_abs(a,a);
			cout<<"x:-1\ty:1\tgcd:"<<a<<"\n";
		}
	}
		
	}
	mpz_clears(a,b,x,y,r,NULL);
	return 0;
}
