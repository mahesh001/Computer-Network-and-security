#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
struct point{
	mpz_t x;
	mpz_t y;
	point()
	{
		mpz_init(x);
		mpz_init(y);
	}
};
typedef point *ptr;
struct curve{
	mpz_t p;
	mpz_t a;
	mpz_t b;
	curve()
	{
		mpz_init(p);
		mpz_init(a);
		mpz_init(b);
	}
};
typedef curve *ec;
ptr pointadd(ptr f,ptr s,ec c)
{
	ptr sum = new point();
	mpz_t m,mx,my;
	mpz_inits(m,mx,my,NULL);
	//find slope
	mpz_sub(my,f->y,s->y);
	mpz_sub(mx,f->x,s->x);
	mpz_invert(mx,mx,c->p);
	mpz_mul(m,my,mx);
	mpz_mod(m,m,c->p);
	//find next point x3
	mpz_mul(sum->x,m,m);
	mpz_sub(sum->x,sum->x,f->x);
	mpz_sub(sum->x,sum->x,s->x);
	mpz_mod(sum->x,sum->x,c->p);	
	//FIND Y3
	mpz_sub(sum->y,f->x,sum->x);
	mpz_mul(sum->y,sum->y,m);
	mpz_sub(sum->y,sum->y,f->y);
	mpz_mod(sum->y,sum->y,c->p);
	return sum;
}
ptr pointdoubling(ptr p,ec c)
{
	ptr sum = new point();
	mpz_t m,mx,my;
	mpz_inits(m,mx,my,NULL);
	//slope
	mpz_mul(mx,p->x,p->x);
	mpz_mul_ui(mx,mx,3);
	mpz_add(mx,mx,c->a);
	mpz_mul_ui(my,p->y,2);
	mpz_invert(my,my,c->p);
	mpz_mul(m,my,mx);
	mpz_mod(m,m,c->p);
	cout<<"slpoe m : "<<m<<"\n";
	//calculate X3
	mpz_mul(sum->x,m,m);
	mpz_sub(sum->x,sum->x,p->x);
	mpz_sub(sum->x,sum->x,p->x);
	mpz_mod(sum->x,sum->x,c->p);
	//FIND Y3
	mpz_sub(sum->y,p->x,sum->x);
	mpz_mul(sum->y,sum->y,m);
	mpz_sub(sum->y,sum->y,p->y);
	mpz_mod(sum->y,sum->y,c->p);
	return sum;
}
void scalarm(ptr prod,mpz_t k,ptr p,ec c)
{
	char *str;
	mpz_get_str(str,2,k);
	cout<<str<<"\n";
	cout<<strlen(str)<<"\n";
	int first=0;
	ptr temp = new point();
	for(int i=strlen(str)-1;i>=0;i--)
	{
		if(str[i] == '1')
		{
			if(first == 0)
			{
				mpz_set(prod->x,p->x);
				mpz_set(prod->y,p->y);
				first++;
			}
			else
			{
				temp = pointadd(prod,p,c);
				//prod = temp;
				mpz_set(prod->x,temp->x);
				mpz_set(prod->y,temp->y);
			}
		}
		 = pointdoubling(p,c);
		//p = temp;
		mpz_set(p->x,temp->x);
		mpz_set(p->y,temp->y);
	}
}
int main()
{
	ptr p1 = new point();
	ptr p2 = new point();
	ptr p3 = new point();
	ptr dp1 = new point();
	ptr prod = new point();
	ec c = new curve();
	cout<<"enter p : ";
	cin>>c->p;
	cout<<"enter a : ";
	cin>>c->a;
	cout<<"enter b : ";
	cin>>c->b;
	cout<<"enter point p1[x1,y1] : ";
	cin>>p1->x>>p1->y;
	cout<<"enter point p2[x2,y2] : ";
	cin>>p2->x>>p2->y;
	cout<<p1->x<<","<<p1->y<<"\n"<<p2->x<<","<<p2->y<<"\n";
	p3 = pointadd(p1,p2,c);
	cout<<"added point is : ";
	cout<<p3->x<<","<<p3->y<<"\n";
	dp1 = pointdoubling(p1,c);
	cout<<"doubled point is : ";
	cout<<dp1->x<<","<<dp1->y<<"\n";
	mpz_t k;
	mpz_init(k);
	//cout<<"enter k :";
	//cin>>k;
	for(int q = 1;q<31;q++)
	{
		mpz_set_ui(k,q);
		cout<<"enter point p : ";
		cin>>p1->x>>p1->y;
	
	
		scalarm(prod,k,p1,c);
		cout<<"scalar product point is : ";
		cout<<prod->x<<","<<prod->y<<"\n";
	}
}
