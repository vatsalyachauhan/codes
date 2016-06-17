#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#define fi(n) scanf("%d",&n)
using namespace std;

int min(int a,int b){
	return a<b?a:b;
}

typedef struct node{
	int totalsum, cumsum;
}node;

int getMid(int s, int e) {  return s + (e -s)/2;  }


void updateValueUtil(int *arr, node *st, int ss, int se, int i,int index)
{
    if(ss==se){
    	st[index].totalsum = st[index].cumsum = arr[ss];
        return;
    }
    int mid = getMid(ss, se);
    if(i<=mid)
    	updateValueUtil(arr, st,ss, mid, i, index*2+1);
    else
    	updateValueUtil(arr, st, mid+1, se, i, index*2+2);

    st[index].totalsum =  st[index*2+1].totalsum + st[index*2+2].totalsum;
    st[index].cumsum =  min(st[index*2+1].cumsum, st[index*2+1].totalsum + st[index*2+2].cumsum);
    return;
}
void updateValue(int *arr, node *st, int n, int i)
{
    arr[i] = -arr[i];
    updateValueUtil(arr, st, 0, n-1, i, 0);
}
 


void constructSTUtil(int arr[], int ss, int se, node *st, int index)
{
    if (ss == se)
    {
        st[index].totalsum = st[index].cumsum = arr[ss];
        return;
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, index*2+1);
    constructSTUtil(arr, mid+1, se, st, index*2+2);

    st[index].totalsum =  st[index*2+1].totalsum + st[index*2+2].totalsum;
    st[index].cumsum =  min(st[index*2+1].cumsum, st[index*2+1].totalsum + st[index*2+2].cumsum);
    return;
}
node *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    node *st = new node[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}


int main(){
	int i,n,m,j,t=10,q;
	while(t--){
		fi(n);
		string str;
		cin>>str;
		int arr[n];
		for(i=0;i<n;i++){
			arr[i] = str[i]=='('?1:-1;
		}

		node *st = constructST(arr, n);
		fi(m);
		printf("Test %d:\n",10-t);
		while(m--){
			fi(q);
			if(q)
				updateValue(arr,st,n,q-1);
			else{
				if(!st[0].totalsum && !st[0].cumsum)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}