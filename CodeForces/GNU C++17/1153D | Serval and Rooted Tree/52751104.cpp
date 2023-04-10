#include<stdio.h> 
int main(){int n;scanf("%d",&n);int a[n+1],p[n+1],i,x,ans[n+1],k=0,c[n+1];
for(i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]) ans[i]=n+1;else ans[i]=0;c[i]=-1;}
for(i=2;i<=n;i++){scanf("%d",&x);p[i]=x;c[x]=i;}
for(i=n;i>1;i--){if(c[i]==-1){ans[i]=1;k++;}x=p[i];if(a[x]){if(ans[x]>ans[i]) ans[x]=ans[i];}else ans[x]+=ans[i];}
printf("%d\n",k+1-ans[1]);return 0;}