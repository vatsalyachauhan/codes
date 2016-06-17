#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

#define 	pb(x) 		push_back(x)
#define 	sz(a) 		int((a).size())
#define 	sortA(v)	sort(v.begin(), v.end())
#define 	sortD(v)	sort(v.begin(), v.end(), greater<auto>())
#define 	mp(x,y) 	make_pair(x,y)
#define 	all(v) 		v.begin(),v.end() //Don’t put the whole right-hand side of these macros into parentheses – that would be wrong!
#define 	it(i,v) 	__typeof(v.begin()) i;
#define 	set(a,val) 	memset(a,val,sizeof(a))
#define 	rep(i,a,b) 	for(__typeof(a) i = (a); i < (b) ; i++)
#define 	rev(i,a,b) 	for(__typeof(a) i = (a); i >= (b) ; i--)
#define 	tr(vec,it) 	for(__typeof(vec.begin()) it = vec.begin();it!=vec.end();++it)
#define 	present(container, element) (container.find(element) != container.end())
#define 	cpresent(container, element) (find(all(container),element) != container.end())
#define 	LL 			long long int

#define 	iss 		istringstream
#define 	oss 		ostringstream
#define 	sqr(x) 		(x)*(x)
#define 	ESP 		(1e-9)
#define 	PI 			3.1415926535897932384626433832795
#define 	ps 			printf(" ")
#define 	pn 			printf("\n")
#define 	MOD 		1000000007
#define     X 			first
#define     Y 			second
 
class suffixArray
{
public:
	suffixArray(char ss[], int n){
		N = n;
		POS = (int *)calloc(N+1, sizeof(int));
		SA  = (int *)calloc(N+1, sizeof(int));
		LCP = (int *)calloc(N+1, sizeof(int));
		str = (char *)calloc(N+1, sizeof(char));
		for(int i=0;i<=n;++i) str[i] = ss[i];
		SuffixArray(N, str, SA, POS);
	}
	~suffixArray(){
		free(POS);
		free(SA);
		free(LCP);
		free(str);
	}
 
	void getSuffixArray(int a[]){
		for(int i=1;i<=N;++i)
			a[i] = SA[i-1]+1;
		return ;
	}
 
	void getPosArray(int a[]){
		for(int i=1;i<=N;++i)
			a[i] = POS[i-1]+1;
		return ;
	}
 
	void getLCPArray(int a[]){
		buildLCP();
		for(int i=2;i<=N;++i)
			a[i] = LCP[i-2];
		a[1] = 0;
		return ;
	}
 
private:
	int * POS, * SA, *LCP , N;
	char * str;
 
	inline bool leq(int a1,int a2,int b1,int b2)
	{
		return (a1<b1 || a1==b1 && a2<=b2);
	}
	inline bool leq(int a1,int a2,int a3,int b1,int b2,int b3)
	{
		return (a1<b1 || a1==b1 && leq(a2,a3,b2,b3)); 
	}
	void RadixPass(int *a,int *b,int *r,int n,int K) 
	{
		int *cnt=new int[K+1];
		memset(cnt,0,(K+1)*sizeof(int));
		for (int i=0;i<n;i++) cnt[r[a[i]]]++;
		for (int i=1;i<=K;i++) cnt[i]+=cnt[i-1];
		for (int i=n-1;i>=0;i--) b[--cnt[r[a[i]]]]=a[i];
		delete[] cnt;
	}
	void GetSuffixArray(int *s,int *SA,int n,int K)
	{
		if (n<=8)
		{
			bool c[8][8];
			for (int i=n-1;i>=0;i--) for (int j=i+1;j<n;j++)
			{
				if (s[i]==s[j]) c[i][j]=(j+1<n && c[i+1][j+1]);
				else c[i][j]=(s[i]<s[j]);
				c[j][i]=!c[i][j];
			}
			for (int i=0;i<n;i++) SA[i]=i;
			for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (c[SA[j]][SA[i]]) swap(SA[i],SA[j]);
			return;
		}
		int n0=(n+2)/3,n1=(n+1)/3,n2=n/3,n02=n0+n2;
		int *s12=new int[n02+3];
		s12[n02]=s12[n02+1]=s12[n02+2]=0; 
		int *SA12=new int[n02+3];
		SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
		int *s0=new int[n0];
		int *SA0=new int[n0];
		for (int i=0,j=0;i<n+(n0-n1);i++) if (i%3!=0) s12[j++]=i;
		RadixPass(s12,SA12,s+2,n02,K);
		RadixPass(SA12,s12,s+1,n02,K);  
		RadixPass(s12,SA12,s,n02,K);
		int name=0,c0=-1,c1=-1,c2=-1;
		for (int i=0;i<n02;i++)
		{
			if (s[SA12[i]]!=c0 || s[SA12[i]+1]!=c1 || s[SA12[i]+2]!=c2)
				name++,c0=s[SA12[i]],c1=s[SA12[i]+1],c2=s[SA12[i]+2];
			if (SA12[i]%3==1)
				s12[SA12[i]/3]=name;
			else 
				s12[SA12[i]/3+n0]=name;
		}
		if (name<n02)
		{
			GetSuffixArray(s12,SA12,n02,name);
			for (int i=0;i<n02;i++) s12[SA12[i]]=i+1;
		}
		else
		{
			for (int i=0;i<n02;i++) SA12[s12[i]-1]=i; 
		}
		for (int i=0,j=0;i<n02;i++) if (SA12[i]<n0) s0[j++]=3*SA12[i];
		RadixPass(s0,SA0,s,n0,K);
		for (int p=0,t=n0-n1,k=0;k<n;k++)
		{
			int i=(SA12[t]<n0?SA12[t]*3+1:(SA12[t]-n0)*3+2);
			int j=SA0[p];
			if (SA12[t]<n0?leq(s[i],s12[SA12[t]+n0],s[j],s12[j/3]):
				           leq(s[i],s[i+1],s12[SA12[t]-n0+1],s[j],s[j+1],s12[j/3+n0]))
			{
				SA[k]=i;
				if ((++t)==n02) for (k++;p<n0;p++,k++) SA[k]=SA0[p];
			}
			else
			{ 
				SA[k]=j;
				if ((++p)==n0) for (k++;t<n02;t++,k++) SA[k]=(SA12[t]<n0?SA12[t]*3+1:(SA12[t]-n0)*3+2); 
			}
		}
		delete[] s12;
		delete[] SA12;
		delete[] s0;
		delete[] SA0;
	}
	void SuffixArray(int n,char *s,int *SA,int *Rank)
	{
		int *A=new int[n+3];
		for (int i=0;i<n;i++) A[i]=(int)((unsigned char)s[i]);
		A[n]=A[n+1]=A[n+2]=0;
		GetSuffixArray(A,SA,n,256);
		for (int i=0;i<n;i++) Rank[SA[i]]=i;
	}
	void SuffixArray(int n,int *s,int *SA,int *Rank)
	{
		int maxs=0;
		for (int i=0;i<n;i++) if (s[i]>maxs) maxs=s[i];
		maxs++;
		int *A=new int[n+3];
		A[n]=A[n+1]=A[n+2]=0;
		if (maxs<(1<<16))
		{
			for (int i=0;i<n;i++) A[i]=s[i];
			GetSuffixArray(A,SA,n,maxs);
		}
		else
		{
			int *C=new int[1<<16];
			int *t=new int[n];
			memset(C,0,(1<<16)*sizeof(int));
			for (int i=0;i<n;i++) C[s[i]&65535]++;
			for (int i=1;i<(1<<16);i++) C[i]+=C[i-1];
			for (int i=n-1;i>=0;i--) A[--C[s[i]&65535]]=i;
			memset(C,0,(1<<16)*sizeof(int));
			for (int i=0;i<n;i++) C[s[i]>>16]++;
			for (int i=1;i<(1<<16);i++) C[i]+=C[i-1];
			for (int i=n-1;i>=0;i--) t[--C[s[A[i]]>>16]]=A[i];
			for (int d=0,i=0;i<n;i++) A[t[i]]=(i>0 && s[t[i]]!=s[t[i-1]])?(++d):d;
			GetSuffixArray(A,SA,n,n);
			delete[] C;
			delete[] t;
		}
		for (int i=0;i<n;i++) Rank[SA[i]]=i;
	}
	void PrepareD(int *s,int *SA,int *Rank,int *D,int n)
	{
		for (int k=0,i=0;i<n;i++)
			if (Rank[i]==n-1)
				D[n-1]=k=0;
			else
			{
				if (k>0) k--;
				int t=SA[Rank[i]+1];
				for (;i+k<n && i+k<n && s[i+k]==s[t+k];k++);
				D[Rank[i]]=k;
			}
	}
	void PrepareD(char *s,int *SA,int *Rank,int *D,int n)
	{
		for (int k=0,i=0;i<n;i++)
			if (Rank[i]==n-1)
				D[n-1]=k=0;
			else
			{
				if (k>0) k--;
				int t=SA[Rank[i]+1];
				for (;i+k<n && i+k<n && s[i+k]==s[t+k];k++);
				D[Rank[i]]=k;
			}
	}
 
	void buildLCP(){
		int k = 0;
		for(int i=0;i<N;++i) if(POS[i] != N-1){
			// POS[i] actually gives the 0 based successor of current suffix in the suffix array, hence 
			// SA[POS[i]] - 1 should give the actual index of the successor in the actual string str
			for(int j = SA[POS[i]+1] ; str[j + k] == str[i + k] ; )
				k = k + 1;
			LCP[POS[i]] = k;
			if(k > 0) k = k - 1;
		}
		POS[N-1] = 0; // for no other reason than safety :D
		return ;
	}
 
};


int SA[50001];
int LCP[50001];
char str[50001];

int main(){
	int t,n;
	LL ans;
	cin>>t;
	while(t--){
		scanf("%s",str);
		n = strlen(str);
		suffixArray sa(str, n);
		sa.getSuffixArray(SA);
		sa.getLCPArray(LCP);
		ans = 0;
		rep(j,1,n+1){
			ans += n-SA[j]+1 - LCP[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}