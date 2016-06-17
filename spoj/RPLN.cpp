#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
using namespace std;
int getMid(int s, int e) {  return s + (e -s)/2;  }
int min(int a,int b){
    return a>b ? b:a;
}


int getMinUtil(int *st, int ss, int se, int query_start, int query_end, int index)
{
    if (query_start <= ss && query_end >= se)
        return st[index];
    if (se < query_start || ss > query_end)
        return INT_MAX;
    int mid = getMid(ss, se);
    return min(getMinUtil(st, ss, mid, query_start, query_end, 2*index+1),getMinUtil(st, mid+1, se, query_start, query_end, 2*index+2));
}
int getMin(int *st, int n, int query_start, int query_end)
{ 
    return getMinUtil(st, 0, n-1, query_start, query_end, 0);
}


int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  min(constructSTUtil(arr, ss, mid, st, si*2+1),constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}




int main()
{
    int t,n,q,l,r,i,T;
    fi(T);

    for(t=1;t<=T;t++){
        fi(n);fi(q);
        int arr[n];
        for(i=0;i<n;i++)
            fi(arr[i]);

        int *st = constructST(arr, n);

        cout<<"Scenario #"<<t<<":\n\n";
        while(q--){
            fi(l);fi(r);
            cout<< getMin(st,n,l-1,r-1)<<"\n\n";
        }

    }
    return 0;
}