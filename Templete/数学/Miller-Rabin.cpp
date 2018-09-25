#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<iterator>
#include<ctime>
#define ll long long
using namespace std;

ll prime,opt;

inline void readx(ll& x)
{
	x=0; ll k=1; register char ch=0;
	while (ch<'0' || ch>'9') { ch=getchar(); if (ch=='-') k=-1; }
	while (ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	x*=k;
}
inline ll fastpow(ll a,ll p)
{
	ll ret=1;
	for (;p;p>>=1,a=(a*a)%prime) if (p&1) ret=(ret*a)%prime;
	return ret;
}
inline ll lowbit(ll xx) { return (xx&(-xx)); }

inline bool MillerRabin()
{
	ll prx=prime-1,u=prime-1,lim=0,pox,rec,a;
	
	lim=lowbit(u); u/=lim;
	for (int i=1;i<=10;i++)
	{
		a=rand()%prime; lim=lowbit(prx);
		while (!a) a=rand()%prime;
		pox=fastpow(a,u);
		for (;lim;lim>>=1)
		{
			rec=(pox*pox)%prime;
			if (rec==1 && pox!=prime-1 && pox!=1) return false;
			pox=rec; 
		}
		if (pox!=1) return false;
	}
	return true;
}

int main()
{
	srand(time(0)); readx(opt); readx(opt);
	for (int i=1;i<=opt;i++)
	{
		readx(prime); if (prime==1) prime=4;
		if (prime==2 || MillerRabin()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
