#include<gmp.h>
#include<stdio.h>

void modulo_add(mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t r;
	mpz_init(r);
	mpz_mod(a,a,n);
	mpz_mod(b,b,n);
	mpz_add(r,a,b);
	mpz_mod(r,r,n);
	gmp_printf("(a+b) mod n = %Zd \n",r);
}
void modulo_sub(mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t r;
	mpz_init(r);
	mpz_mod(a,a,n);
	mpz_mod(b,b,n);
	mpz_sub(r,a,b);
	mpz_mod(r,r,n);
	gmp_printf("(a-b) mod n = %Zd \n",r);
}
void modulo_mul(mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t r;
	mpz_init(r);
	mpz_mod(a,a,n);
	mpz_mod(b,b,n);
	mpz_mul(r,a,b);
	mpz_mod(r,r,n);
	gmp_printf("(a*b) mod n = %Zd \n",r);
}
void modulo_mul1(mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t r;
	mpz_init(r);
	mpz_mod(a,a,n);
	mpz_mod(b,b,n);
	mpz_mul(r,a,b);
	mpz_mod(r,r,n);
	gmp_printf("\n (a/b) mod n = %Zd \n",r);
}
void modulo_div(mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t x0,x1,x2,y0,y1,y2,x,m,r,q,i;
	mpz_init(i);
	mpz_set(i,n);
	mpz_init(x0);
	mpz_init(x1);
	mpz_init(x2);
	mpz_init(y0);
	mpz_init(y1);
	mpz_init(y2);
	mpz_abs(a,a);
	mpz_abs(b,b);
	mpz_set_ui(x0,1);
	mpz_set_ui(x1,0);
	mpz_set_ui(y1,1);
	mpz_set_ui(y0,0);
	mpz_init(x);
	mpz_set_ui(x,0);
	mpz_init(r);
	mpz_init(q);
	mpz_init(m);
	mpz_set_ui(m,1);
   
     if(mpz_cmp(b,x)!=0 && mpz_cmp(n,x)!=0)
     {

	while(mpz_cmp(n,x)!=0)
	{
	  mpz_fdiv_q(q,b,n);
	  mpz_fdiv_r(r,b,n);
	  gmp_printf("%Zd  ",r);
	  gmp_printf("%Zd  ",q);
	  mpz_set(b,n);
	  mpz_set(n,r);
	  mpz_set(x2,x1);
	  mpz_mul(x1,q,x1);
	  mpz_sub(x1,x0,x1);
	  mpz_set(x0,x2);
	  mpz_set(y2,y1);
	  mpz_mul(y1,q,y1);
	  mpz_sub(y1,y0,y1);
	  mpz_set(y0,y2);
	  if(mpz_cmp(n,x)!=0)
	  {
	   gmp_printf("%Zd  ",x1);
	   gmp_printf("%Zd\n",y1);
	  }			
	}
		//gmp_printf("%Zd ",x0);
	 	//gmp_printf("%Zd\n",y0);
	mpz_set(n,i);
        modulo_mul1(a,x0,n);
     }
  
else
{
	if(mpz_cmp(b,x)==0)
	gmp_printf("no inverse");
        else if(mpz_cmp(n,x)==0)
	gmp_printf("no inverse");
	
}


}
int main()
{
	mpz_t a,b,n;
	mpz_init(a);
	mpz_init(b);
	mpz_init(n);
	gmp_scanf("%Zd",a); 
	gmp_scanf("%Zd",b);
	gmp_scanf("%Zd",n);
	
	modulo_add(a,b,n);
	modulo_sub(a,b,n);
	modulo_mul(a,b,n);
	modulo_div(a,b,n);
}
