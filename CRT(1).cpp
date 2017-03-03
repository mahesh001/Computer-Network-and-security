#include <bits/stdc++.h>
#include <gmp.h>
using namespace std;

class CRT{

	mpz_t* A;
	mpz_t* M;
	mpz_t A_fin,M_fin;
	int n;

public:

	CRT()
	{
		mpz_inits(A_fin,M_fin,NULL);
	}

	void input()
	{
		cout<<"Enter the number of Ci and Mi pairs.\n";
		cin>>n;

		A=new mpz_t[n];
		M=new mpz_t[n];

		cout<<"Enter the Ci and Mi pairs.\n";

		for(int i=0;i<n;i++)
		{
			mpz_inits(A[i],M[i],NULL);

			gmp_scanf("%Zd%Zd",A[i],M[i]);
		}

		
	}

	void calculate()
	{
		mpz_init_set_str(M_fin,"1",10);
		for(int i=0;i<n;i++)
		{
			mpz_mul(M_fin,M[i],M_fin);
		}

		mpz_t* Ci=new mpz_t[n];

		for(int i=0;i<n;i++)
		{
			mpz_t Mi,Mi_inv;

			mpz_inits(Ci[i],Mi,Mi_inv,NULL);

			mpz_cdiv_q(Mi,M_fin,M[i]);

			mpz_invert(Mi_inv,Mi,M[i]);

			//gmp_printf("M%d %Zd %Zd\n",i,Mi,Mi_inv);

			mpz_mul(Ci[i],Mi,Mi_inv);
		}

		mpz_init_set_str(A_fin,"0",10);

		for(int i=0;i<n;i++)
		{
			mpz_t mul;
			mpz_init(mul);

			mpz_mul(mul,A[i],Ci[i]);

			mpz_add(A_fin,mul,A_fin);

			mpz_mod(A_fin,A_fin,M_fin);
		}
	}

	void result()
	{
		gmp_printf("A= %Zd\nM= %Zd\n",A_fin,M_fin);
	}
};

int main()
{
	CRT crt;

	crt.input();
	crt.calculate();
	crt.result();
}
