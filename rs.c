#include <stdio.h>
#include <gmp.h>
int main()
{
	int check=0;
	mpz_t p,q,n,phi_n,N,one,d,e,m,x,y,gcd,mul;
	mpz_inits(p,q,n,phi_n,n,N,one,d,e,m,x,y,gcd,mul,NULL);
	mpz_set_si(N,16);
	mpz_set_si(one,1);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	char str[100];
	printf("Enter message to be encrypted : ");
	scanf("%s",str);
	mpz_set_str(m,str,10);

       printf("Enter the first prime p : ");
	scanf("%s",str);
	mpz_set_str(p,str,10);
        printf("Enter the second prime q : ");
	scanf("%s",str);
	mpz_set_str(q,str,10);
	gmp_printf("p = %Zd\n",p);
	gmp_printf("q = %Zd\n",q);

	mpz_mul(n,p,q);
	gmp_printf("n = %Zd\n",n);

	mpz_sub(p,p,one);
	mpz_sub(q,q,one);
	mpz_mul(phi_n,p,q);
	gmp_printf("phi(n) = %Zd\n",phi_n);

	do
	{       
		mpz_urandomm(e,state,phi_n);
		check=mpz_invert(d,e,phi_n);
		mpz_gcd(gcd,e,n);
	}while((check==0)||(mpz_cmp(gcd,one)));
	gmp_printf("e = %Zd\n",e);
	gmp_printf("d = %Zd\n",d);

	mpz_mul(mul,d,e);
	mpz_mod(mul,mul,phi_n);
	gmp_printf("d*e mod phi_n: %Zd\n",mul);
	mpz_powm(x,m,d,n);
	gmp_printf("Encrypted Message : %Zd\n",x);
	mpz_powm(y,x,e,n);
	gmp_printf("Decrypted Message : %Zd\n",y);

}
