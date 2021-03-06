#include<stdio.h>
#include<gmp.h>
void gcd(mpz_t res,mpz_t inv, mpz_t a, mpz_t b)
{
	mpz_t x0,x1,y0,y1,t,tx,ty,q;
	mpz_inits(x0,x1,y0,y1,tx,ty,t,q,NULL);
	int flag=0;
	//if a and b are negative
	if(mpz_cmp_ui(a,0)<0 && mpz_cmp_ui(b,0)<0)
		flag=1;
	
	mpz_set_ui(x0,1);
	mpz_set_ui(x1,0);
	mpz_set_ui(y0,0);
	mpz_set_ui(y1,1);
	while(mpz_cmp_ui(b,0)!=0)                 
	{
		mpz_set(t,b);
		mpz_fdiv_qr(q,b,a,b);
		//gmp_printf(" q: %Zd \t r: %Zd \t",q,b);
		mpz_set(a,t);

		//save x1 and y1
		mpz_set(tx,x1);
		mpz_set(ty,y1);
		
		//update x1
		mpz_mul(x1,q,x1);
		mpz_sub(x1,x0,x1);
		//update y1
		mpz_mul(y1,q,y1);
		mpz_sub(y1,y0,y1);
		//set x0 to previous x1 stored in tx
		mpz_set(x0,tx);
		//set y0 to previous y1 stored in ty
		mpz_set(y0,ty);
		
		//gmp_printf(" x0: %Zd \t x0: %Zd \t",x0,x1);
		//gmp_printf(" x1: %Zd \t y1: %Zd \n",x1,y1);
		
		//printf("\n------------------\n");
	}
	
	if(flag==1)
	{
		mpz_neg(x0,x0);
		mpz_neg(y0,y0);
	}
	gmp_printf("GCD : %Zd \n",a);
	gmp_printf("x0: %Zd \t y0: %Zd \n",x0,y0);
	mpz_set(res,a);
	mpz_set(inv,x0);
	mpz_clears(x0,x1,y0,y1,tx,ty,t,q,NULL);
	
	
}
void mod_add(mpz_t r,mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t t1,t2;
	mpz_inits(t1,t2,NULL);

	mpz_mod(t1,a,n);
	mpz_mod(t2,b,n);
	mpz_add(t1,t1,t2);
	mpz_mod(r,t1,n);

	mpz_clears(t1,t2,NULL);
}
void mod_sub(mpz_t r,mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t t1,t2;
	mpz_inits(t1,t2,NULL);

	mpz_mod(t1,a,n);
	mpz_mod(t2,b,n);
	mpz_sub(t1,t1,t2);
	mpz_mod(r,t1,n);

	mpz_clears(t1,t2,NULL);
}
void mod_mul(mpz_t r,mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t t1,t2;
	mpz_inits(t1,t2,NULL);

	mpz_mod(t1,a,n);
	mpz_mod(t2,b,n);
	mpz_mul(t1,t1,t2);
	mpz_mod(r,t1,n);

	mpz_clears(t1,t2,NULL);
}
void mod_div(mpz_t re,mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t g,inv,t1,t2;
	mpz_inits(g,inv,t1,t2,NULL);
	mpz_set(t1,n);
	gcd(g,inv,b,n);
	if(mpz_cmp_ui(g,1)!=0)
	{
		printf("Not possible\n");
		mpz_set_ui(re,0);
		return ;
	}
	else
	{
		
		mpz_mul(re,a,inv);
		gmp_printf("%Zd \n",re);
		mpz_mod(re,re,t1);
	}

	mpz_clears(g,inv,t1,t2,NULL);
}
int main()
{
	mpz_t a,b,n,r;
	mpz_inits(r,a,b,n,NULL);
	
	printf("Enter a:");
	gmp_scanf("%Zd",a);
	printf("Enter b:");
	gmp_scanf("%Zd",b);
	printf("Enter n:");
	gmp_scanf("%Zd",n);
	
	mod_add(r,a,b,n);
	gmp_printf("a+b RESULT : %Zd \n",r);
	mod_sub(r,a,b,n);
	gmp_printf("a-b RESULT : %Zd \n",r);
	mod_mul(r,a,b,n);
	gmp_printf("a*b RESULT : %Zd \n",r);
	mod_div(r,a,b,n);
	gmp_printf("a/b RESULT : %Zd \n",r);

	mpz_clears(r,a,b,n,NULL);
}
