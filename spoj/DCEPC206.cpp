#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#define fi(n) scanf("%d",&n)
#define lli long long int
using namespace std;




int getMid(int s, int e) {  return s + (e -s)/2;  }



lli getSumUtil(lli *st, int ss, int se, int query_start, int query_end, int index)
{
    if (query_start <= ss && query_end >= se)
        return st[index];
    if (se < query_start || ss > query_end)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, query_start, query_end, 2*index+1) +
           getSumUtil(st, mid+1, se, query_start, query_end, 2*index+2);
}
lli getSum(lli *st, int n, int query_start, int query_end)
{ 
    return getSumUtil(st, 0, n-1, query_start, query_end, 0);
}



void updateValue(lli *st, int ss, int se, int i, int val, int index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + val;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValue(st, ss, mid, i, val, 2*index + 1);
        updateValue(st, mid+1, se, i, val, 2*index + 2);
    }
}



lli *constructST(int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    lli *st = new lli[max_size];
    return st;
}




int main()
{
    int t,n,i,temp;
    lli result;
    cin>>t;
    while(t--){
        cin>>n;
        result = 0;
        lli *st = constructST(1000001);
        for(i=0;i<n;i++){
            fi(temp);
            updateValue(st,0, 1000000, temp, temp,0);
            result += getSum(st,1000001,0,temp-1);
        }
        cout<<result<<endl;
    }
    return 0;
}