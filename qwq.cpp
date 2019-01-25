#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iterator>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define ll long long 
using namespace std;

int n,T,ans;
char str[10][10010];

template<typename int_t>
void readx(int_t& x)
{
	x=0; int_t k=1; char ch=0;
	while (ch<'0' || ch>'9') { ch=getchar(); if (ch=='-') k=-1; }
	while (ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	x*=k;
}

namespace SAM
{
	#define CH(a,b) node[a].ch[b]
	
	struct SAM_Node
	{
		int ch[27],suf,ends,maxs;
		int minlen[10],maxlen;
	}node[3000010];
	int end=1,samsiz=1;
	
	void Append(int c)
	{
		SAM_Node& now=node[++samsiz]; int pos=end;
		
		now.maxs=node[end].maxs+1; now.ends=1; end=samsiz;
		for (;pos && !CH(pos,c);pos=node[pos].suf)
			CH(pos,c)=samsiz;
			
		if (!pos)
			now.suf=1;
		else if (node[CH(pos,c)].maxs==node[pos].maxs+1)
			now.suf=CH(pos,c);
		else
		{
			int pre=CH(pos,c);
			SAM_Node& N=node[++samsiz],& O=node[pre];
			
			for (int i=1;i<=26;i++) N.ch[i]=O.ch[i];
			N.suf=O.suf; N.maxs=node[pos].maxs+1;
			O.suf=now.suf=samsiz;
			
			for (int i=pos;CH(i,c)==pre;i=node[i].suf)
				CH(i,c)=samsiz;
		}
	}
	
	struct ed { int pre,to; };
	ed edge[300010]; int at=1,ptr[300010];
	void Is(int fx,int tx)
	{
		at++;
		edge[at].pre=ptr[fx];
		edge[at].to=tx;
		ptr[fx]=at;
	}
	
	void BuildTree()
	{
		for (int i=2;i<=samsiz;i++)
			Is(node[i].suf,i);
	}
	
	void Get_Endpos(int now)
	{
		for (int v=ptr[now];v;v=edge[v].pre)
		{
			Get_Endpos(edge[v].to);
			node[now].ends+=node[edge[v].to].ends;
		}
	}
};



int main()
{
	readx(n); int len=0;
	scanf("%s",str[1]+1); len=strlen(str[1]+1);
	for (int i=1;i<=len;i++) SAM::Append(str[1][i]-'a'+1);
	
	for (int w=2;w<=n;w++)
	{
		
		
		
		
	}
	
}
