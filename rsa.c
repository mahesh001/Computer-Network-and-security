#include<stdio.h>


int phi,M,n,e,d,C,FLAG;

int check()
{
int i;
for(i=3;e%i==0 && phi%i==0;i+2)
{
FLAG = 1;
return;
}
FLAG = 0;
}

void encrypt()
{
int i;
C = 1;
for(i=0;i< e;i++)
C=C*M%n;
C = C%n;
printf("encrypterd keyword %d",C);
printf("\n");

}

void decrypt()
{
int i;
M = 1;
for(i=0;i< d;i++)
M=M*C%n;
M = M%n;
printf("Decrypted keyword : %d",M);
printf("\n");
}

int main()
{
int p,q,s;

printf("Enter Two Relatively Prime Number:");
scanf("%d %d",&p,&q);
n = p*q;
phi=(p-1)*(q-1);
printf("F(n) phi value= %d",phi);
printf("\n");
do
{
printf("Enter e which is prime number and less than phi :");
scanf("%d",&e);
check();
}while(FLAG==1);
d = 1;
do
{
s = (d*e)%phi;
d++;
}while(s!=1);
d = d-1;
printf("Public Keyt: {%d,%d}\n",e,n);
printf("Private Keyt: {%d,%d}\n",d,n);
printf("Enter The Plain Text:");
scanf("%d",&M);
encrypt();
printf("Enter the Cipher text:");
scanf("%d",&C);
printf("\n");
decrypt();
return 0;
}
/*************** OUTPUT *****************
Enter Two Relatively Prime Number:7 47
F(n) phi value= 276
Enter e which is prime number and less than phi :17
Public Keyt: {17,329}
Private Keyt: {65,329}
Enter The Plain Textt:88
encrypterd keyword 163
Enter the Cipher textt:163

Decrypted keyword : 88



Enter Two Relatively Prime Number:17 11
F(n) phi value= 160
Enter e which is prime number and less than phi :7
Public Keyt: {7,187}
Private Keyt: {23,187}
Enter The Plain Text:88
encrypterd keyword 11
Enter the Cipher text:11

Decrypted keyword : 88





Enter Two Relatively Prime Numbers : 7 17

F(n) = 96 

Enter e : 5 

Public Key : {5,119}
Private Key : {77,119}

Enter The Plain Text : 19

Encrypted keyword : 66

Enter the Cipher text : 66

Decrypted keyword : 19 */
