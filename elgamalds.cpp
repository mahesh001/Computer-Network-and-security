#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
void getalpha(mpz_t a,mpz_t q,mpz_t p)
{
	//mpz_set_ui(a,3);
	mpz_t p1,p2,r,b,tp1,tp2;
	mpz_inits(p1,p2,b,r,tp1,tp2,NULL);
	mpz_set_ui(p1,2);
	mpz_set(p2,q);
	gmp_randstate_t state;
	gmp_randinit_default(state);
	while(1)
	{
		mpz_urandomm(r,state,p);
		cout<<"r is "<<r<<"\n";
		mpz_powm(tp1,r,p1,p);
		mpz_powm(tp2,r,p2,p);
		if(mpz_cmp_ui(tp1,1)!=0 && mpz_cmp_ui(tp2,1)!=0)
		{
			mpz_set(a,r);
			break;
		}
	}
}
void gethash(mpz_t M)
{

}

int main()
{
	mpz_t cq,q,a,xa,ya,p,tp,k,K,C1,C2,M,Ka,iKa,Ma;
	mpz_inits(q,cq,a,xa,ya,p,tp,K,k,C1,C2,M,Ka,iKa,Ma,NULL);
	gmp_randstate_t state;
	gmp_randinit_default(state);
	int bit;
	for(int i=0;i<5;i++)
	{
		cout<<"Enter bit : "<<"\n";
		cin>>bit;
		while(1)
		{
			mpz_urandomb(cq,state,bit);
			mpz_nextprime(q,cq);
			cout<<"current q is :"<<q<<"\n";
			mpz_mul_ui(tp,q,2);
			//mpz_set(tp,p);
			mpz_nextprime(p,tp);
			mpz_add_ui(tp,tp,1);
			//cout<<p<<"\n"<<tp<<"\n";
			if(mpz_cmp(tp,p)==0)
			{
				mpz_sub_ui(tp,p,1);
				getalpha(a,q,tp);
				break;
			}		
		}
		cout<<"choosen q is :"<<p<<"\n"<<"alpha is :"<<a<<"\n";
		mpz_urandomm(xa,state,p);
		cout<<"choosen Xa is :"<<xa<<"\n";
		mpz_powm(ya,a,xa,p);
		cout<<"public key Ya is :"<<ya<<"\n";
		//mpz_urandomm(k,state,p);
		//mpz_powm(K,ya,k,p);
		//cout<<"one time key of B is :"<<K<<"\n";
		mpz_urandomm(M,state,p);
		cout<<"M is :"<<M<<"\n";
		gethash(M);
	}
	mpz_clears(q,cq,a,xa,ya,p,tp,K,k,C1,C2,M,Ka,iKa,Ma,NULL);
}
