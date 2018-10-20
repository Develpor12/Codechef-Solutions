#include<bits/stdc++.h>
using namespace std;
int n,m,qv,q,a[202][202],b[202][202], c[202][202],dp1[202][202],dp2[202][202];
vector <int> ch(201);

void init() {
	for(int i=1;i<=200;i++)
		for(int j=1;j<=200;j++){
			b[i][j] = (i+j)&1;
			c[i][j] = !((i+j)&1);
		}
}

void make_dp() {
	for(int i=1;i<=200;i++) ch[i] = INT_MAX;
	for(int i=1;i<=200;i++)
		for(int j=1;j<=200;j++) {
			if(a[i][j]!=b[i][j])
				dp1[i][j] = dp1[i][j-1] + 1;
			else
				dp1[i][j] = dp1[i][j-1];
			if(a[i][j]!=c[i][j])
				dp2[i][j] = dp2[i][j-1] + 1;
			else
				dp2[i][j] = dp2[i][j-1];
		}
	for(int i=1;i<=200;i++)
		for(int j=1;j<=200;j++)
			dp1[i][j] += dp1[i-1][j],
			dp2[i][j] += dp2[i-1][j];

	for(int i=n;i>=1;i--)
		for(int j=i;j<=n;j++)
			for(int k=i;k<=m;k++) {
				ch[i] = min(ch[i],dp1[j][k]+dp1[j-i][k-i]-dp1[j-i][k]-dp1[j][k-i]);
				ch[i] = min(ch[i],dp2[j][k]+dp2[j-i][k-i]-dp2[j][k-i]-dp2[j-i][k]);
			}
}

int main() {
	char cha;
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			cin>>cha;
			a[i][j] = 0;
			if(cha=='1')
				a[i][j] = 1;				
		}
	make_dp();
	cin>>q;
	while(q--) {
		cin>>qv;
		cout<<upper_bound(ch.begin(),ch.end(),qv)-ch.begin()-1<<endl;
	}
	return 0;
}
