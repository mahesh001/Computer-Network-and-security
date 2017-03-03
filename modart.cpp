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
	}
	mpz_set(x,x1);
	mpz_set(y,y1);
	mpz_set(r,r2);
	mpz_clears(q,x0,y0,x1,y1,x2,y2,zero,mul,sub,r1,r2,NULL);
}
void addition(const mpz_t a,const mpz_t b,const mpz_t p)
{
	mpz_t ta,tb,sum; 
	mpz_inits(ta,tb,sum,NULL);
	mpz_mod(ta,a,p);
	mpz_mod(tb,b,p);
	mpz_add(sum,ta,tb);
	mpz_mod(sum,sum,p);
	cout<<"mod "<<p<<"\tsum of \t"<<a<<"\t"<<b<<"\t"<<"is :"<<sum<<"\n";
	mpz_clears(ta,tb,sum,NULL);
}
void subtraction(const mpz_t a,const mpz_t b,const mpz_t p)
{
	mpz_t ta,tb,sum; 
	mpz_inits(ta,tb,sum,NULL);
	mpz_mod(ta,a,p);
	mpz_mod(tb,b,p);
	mpz_sub(sum,ta,tb);
	mpz_mod(sum,sum,p);
	cout<<"mod "<<p<<"\tdifference  of \t"<<a<<"\t"<<b<<"\t"<<"is :"<<sum<<"\n";
	mpz_clears(ta,tb,sum,NULL);
}
void multiplication(const mpz_t a,const mpz_t b,const mpz_t p)
{
	mpz_t ta,tb,sum;
	mpz_inits(ta,tb,sum,NULL);
	mpz_mod(ta,a,p);
	mpz_mod(tb,b,p);
	mpz_mul(sum,ta,tb);
	mpz_mod(sum,sum,p);
	cout<<"mod "<<p<<"\tproduct of \t"<<a<<"\t"<<b<<"\t"<<"is :"<<sum<<"\n";
	mpz_clears(ta,tb,sum,NULL);
}
void multi(const mpz_t a,const mpz_t b,const mpz_t bb,const mpz_t p)
{
	mpz_t ta,tb,sum;
	mpz_inits(ta,tb,sum,NULL);
	mpz_mod(ta,a,p);
	mpz_mod(tb,b,p);
	mpz_mul(sum,ta,tb);
	mpz_mod(sum,sum,p);
	cout<<a<<"\t"<<bb<<"\t"<<"is :"<<sum<<"\n";
	mpz_clears(ta,tb,sum,NULL);
}
void inverse(mpz_t tb,const mpz_t b,const mpz_t p)
{
	mpz_t x,y,r;
	mpz_inits(x,y,r,NULL);
	getxy(tb,y,r,b,p);
}
void division(const mpz_t a,const mpz_t b,const mpz_t p)
{
	mpz_t ta,tb,sum,gcd;
	mpz_inits(ta,tb,sum,gcd,NULL);
	mpz_gcd(gcd,b,p);
	if(mpz_cmp_ui(gcd,1)!=0)
	{
		cout<<"inverse of "<<b<<"doesn't exist \n";
	}
	else
	{
		inverse(tb,b,p);
		cout<<"inverse of "<<b<<"is :"<<tb<<"\n";
		cout<<"mod "<<p<<"\tdivision of \t";	
		multi(a,tb,b,p);
		
		//cout<<a<<"\t"<<b<<"\t"<<"is :"<<sum<<"\n";
	}
}
int main()
{
	
	mpz_t a,b,p;
	mpz_t cp;
	mpz_inits(a,b,p,cp,NULL);
	mpz_set_ui(cp,1000);
	gmp_scanf("%Zd%Zd",a,b);
	mpz_nextprime(p,cp);
	cout<<a<<"\t"<<b<<"\t"<<p<<"\n";
	//addition
	addition(a,b,p);
	//subtraction
	subtraction(a,b,p);
	//multiplication
	
	multiplication(a,b,p);
	//division
	
	division(a,b,p);
	return 0;
}
