#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <climits>
typedef unsigned long long int ulli;
using namespace std;
int main()
{
   /* int t,n,i,q,temp=1,lo,hi,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        int a[n];
        int dp[n][n];
        i=0;
        scanf("%d",&a[i]);
        dp[i][i]=a[i];
        for(i=1;i<n;i++)
        {
             scanf("%d",&a[i]);
             dp[i][i]=a[i];
             dp[0][i]=INT_MIN(dp[0][i-1],a[i]);
        }
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                dp[i][j]=INT_MIN(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("Scenario #%d:\n",temp++);
        while(q--)
        {
            scanf("%d%d",lo,hi);
            printf("%d\n",dp[lo-1][hi-1]);
        }
    }*/
        cout<<INT_MIN<<"ramu"<<INT_MAX;
    return 0;
}