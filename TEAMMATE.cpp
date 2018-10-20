#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[1000001],mod=1000000007;
ll h[1000001];
void __init() {
	fac[0] = 1;
	for(int i=1;i<1000001;i++)
		fac[i] = (fac[i-1]*i)%mod;
}

ll fastmod(ll  base,ll p)
{
    if(p ==0)
        return 1;
    else if(p&1)
    {
 
        return (base*fastmod(base,p-1))%mod;
    }
    else
    {
        ll k =  fastmod(base,p/2);
        return (k*k)%mod;
    }
}

ll solve(ll n) {
	if(n==0) return 1;
	ll a = fac[n],b = fac[n/2],c = fastmod(2,n/2);
	a = (a*fastmod(b,mod-2))%mod;
	a = (a*fastmod(c,mod-2))%mod;
	return a;
}

int main() {
	ll t,n,s[100001];
	__init();
	cin>>t;
	while(t--) {
		ll ans = 1,ctr = 1,p=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>s[i];
		sort(s,s+n);
		s[n] = -1;
		for(int i=1;i<n+1;i++)
			if(s[i]==s[i-1])
				ctr++;
			else {
				h[p++] = ctr;
				ctr = 1;
			}
		//for(int i=0;i<p;i++)cout<<h[i]<<" ";cout<<endl;
		for(int i=p-1;i>=0;i--) {
			if((h[i])&1) {
				ans = ((ans * h[i-1])%mod * (solve(h[i]+1))%mod)%mod;//cout<<"1 "<<ans<<" \n";
				h[i-1] -= 1;
			}
			else {
				ans = (ans * solve(h[i]))%mod;//cout<<"2 "<<ans<<" \n";
			}
		}		
		cout<<ans<<endl;						
	}
	return 0;
}

