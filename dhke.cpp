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
int main()
{
	mpz_t cq,q,a,xa,ya,xb,yb,ka,kb,p,tp;
	mpz_inits(q,cq,a,xa,ya,xb,yb,ka,kb,p,tp,NULL);
	gmp_randstate_t state;
	gmp_randinit_default(state);
	int bit;
	for(int i=0;i<5;i++)
	{
		cout<<"enter bit :"<<"\n";
		cin>>bit;
		//mpz_urandomb(cq,state,bit);	
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
			//mpz_set(cq,q);		
		}
		//mpz_set_ui(q,353);
		cout<<"choosen q is :"<<p<<"\n"<<"alpha is :"<<a<<"\n";
		mpz_urandomm(xa,state,p);
		//mpz_set_ui(xa,97);
		cout<<"choosen Xa is :"<<xa<<"\n";
		mpz_powm(ya,a,xa,p);
		cout<<"public key Ya is :"<<ya<<"\n";
		mpz_urandomm(xb,state,p);
		//mpz_set_ui(xb,233);
		cout<<"choosen Xb is :"<<xb<<"\n";
		mpz_powm(yb,a,xb,p);
		cout<<"Public key Yb is :"<<yb<<"\n";
		mpz_powm(ka,yb,xa,p);
		cout<<"Key of user A is : "<<ka<<"\n";
		mpz_powm(kb,ya,xb,p);
		cout<<"Key of user B is : "<<kb<<"\n";
		if(mpz_cmp(ka,kb)==0)
		cout<<"2 keys are same\n";
		else
		cout<<"verify your code\n";	
	}
	mpz_clears(q,cq,a,xa,ya,xb,yb,ka,kb,p,tp,NULL);	
	
}
