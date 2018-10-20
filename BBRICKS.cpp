#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1000000007, dp[1002][1002];
ll cal[1002], fac[1000001];
	
ll fastmod(ll  base,ll p)
{
    if(p ==0)
        return 1;
    else if(p&1)
        return (base*fastmod(base,p-1))%mod;
    else {
        ll k =  fastmod(base,p/2);
        return (k*k)%mod;
    }
}

ll nCr(ll n, ll r) {
	if(n>1000000) {
		ll a = cal[r-1];
		a = (a*fastmod(fac[r],mod-2))%mod;
		return a;
	}
	ll a = fac[n],b = fac[n-r],c = fac[r];
	a = (a*fastmod(b,mod-2))%mod;
	a = (a*fastmod(c,mod-2))%mod;
	return a;
}
void calc(int f) {
	cal[0] = f;
	for(int i=1;i<=1000;i++)
		cal[i] = (cal[i-1]*(f-i))%mod;
}

void __init() {
	fac[0] = 1;
	for(int i=1;i<=1000000;i++)
		fac[i] = (fac[i-1]*i)%mod;

	for(int i=1;i<=1000;i++)
		for(int j=1;j<=i;j++)
			dp[i][j] = nCr(i-1,i-j);
}
int main() {
	__init();
	ll t,n,k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		if(k>n) {
			cout<<0<<endl;
			continue;
		}
		ll ans = 0;
		if(n-k+1>1000000)
			calc(n-k+1);
		for(int i=1;i<=k;i++){
			if(n-k+1<i) break;
			ll a1 = (fastmod(2,i)*dp[k][i])%mod;
			a1 = (a1*nCr(n-k+1,i))%mod;
			ans = (ans + a1)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
