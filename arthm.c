#include<stdio.h>
#include<gmp.h>

void exgcd(mpz_t x,mpz_t y,mpz_t a,mpz_t b)
{
     mpz_t zero;
      mpz_init(zero);
       if(!mpz_cmp(b,zero))
        {
         mpz_clear(zero);
          mpz_set_ui(x,1);
          mpz_set_ui(y,0);
            return;
       }
       mpz_t mod; 
       mpz_init(mod);
       mpz_mod(mod,a,b);
       exgcd(x,y,b,mod);
       mpz_t tmp;
       mpz_init(tmp);
       mpz_set(tmp,y);
   mpz_t quotient;  
    mpz_init(quotient);
   mpz_t quot;  mpz_init(quot);
 mpz_sub(quot,a,mod);
 mpz_cdiv_q(quotient,quot,b);

mpz_t mul;  mpz_init(mul);
mpz_mul(mul,quotient,y);
mpz_t sub;  mpz_init(sub);
mpz_sub(sub,x,mul);
mpz_set(y,sub);
mpz_set(x,tmp);
mpz_clear(tmp);
mpz_clear(sub);
mpz_clear(mul);
mpz_clear(quot);
mpz_clear(quotient);
  
//mpz_out_str(NULL,10,a);
  //return a;
}
void add(mpz_t a,mpz_t b,mpz_t n)
{
  mpz_t t1;
  mpz_init(t1);
 mpz_t t2;
  mpz_init(t2);
  //mpz_add(t,a,b);
  mpz_mod(t1,a,n);
  mpz_mod(t2,b,n);
  mpz_add(t1,t1,t2);
  mpz_mod(t1,t1,n);
  gmp_printf("%Zd\n",t1);
}
void sub(mpz_t a,mpz_t b,mpz_t n)
{
  mpz_t t1;
  mpz_init(t1);
 mpz_t t2;
  mpz_init(t2);
  //mpz_add(t,a,b);
  mpz_mod(t1,a,n);
  mpz_mod(t2,b,n);
  mpz_sub(t1,t1,t2);
  mpz_mod(t1,t1,n);
  gmp_printf("sub %Zd\n",t1);
}
void gcd(mpz_t a,mpz_t b)
{
   mpz_abs(a,a);
   mpz_abs(b,b);
   mpz_t e;
  mpz_init(e);
       if(mpz_cmp(a,e)==0)
        {
         mpz_out_str(NULL,10,b);
         return;
         }
       else if(mpz_cmp(b,e)==0)
        {
        mpz_out_str(NULL,10,a);
        return;
         } 
  while(mpz_cmp(a,b)!=0)
  {
    if(mpz_cmp(a,b)>0)
    mpz_sub(a,a,b);
    else 
     mpz_sub(b,b,a);
//mpz_out_str(NULL,10,a);
//mpz_out_str(NULL,10,b);
  }
//mpz_out_str(NULL,10,a);
  //return a;
}
void mul(mpz_t a,mpz_t b,mpz_t n)
{
  mpz_t t1;
  mpz_init(t1);
 mpz_t t2;
  mpz_init(t2);
  //mpz_add(t,a,b);
  mpz_mod(t1,a,n);
  mpz_mod(t2,b,n);
  mpz_mul(t1,t1,t2);
  mpz_mod(t1,t1,n);
  gmp_printf(" mul %Zd\n",t1);
}
 
void div(mpz_t a,mpz_t b,mpz_t n)
{
   mpz_t x,y,t1,t2,e;
   mpz_init(x);
    mpz_init(t1);
   mpz_init(t2);
   mpz_set(t2,b);
   mpz_init(e);
   mpz_set_d(e,1);
   gmp_printf("val %Zd\n",e);
   mpz_init(y); 
   gcd(t2,n);
   if(!mpz_cmp(t2,e))
   {
  exgcd(x,y,a,b);
  mpz_mul(t1,y,a);
  mpz_mod(t1,t1,n);
  gmp_printf("div %Zd\n",t1);
}
else
gmp_printf("not possible\n");
}
int main()
{
  mpz_t a;  
  mpz_init(a);
  mpz_t b;
  mpz_init(b);
  mpz_t n;
  mpz_init(n);
     gmp_scanf("%Zd",a);
     gmp_scanf("%Zd",b);
     gmp_scanf("%Zd",n);
     add(a,b,n);
     sub(a,b,n);
     mul(a,b,n);
     div(a,b,n);
     mpz_clear(a);
    mpz_clear(b);
    mpz_clear(n);

}
