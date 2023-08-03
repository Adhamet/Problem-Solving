#include<iostream>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=n;++i){
			cin>>b[i];
		}
		for(int i=1,j=1;i<=n;++i){
			while(b[j]<a[i]) ++j;
			cout<<b[j]-a[i]<<" ";
		}
		cout<<"\n";
		for(int i=1,j=1;i<=n;++i){
			j=max(i,j);
			while(b[j]>=a[j+1] && j<n) ++j;
			cout<<b[j]-a[i]<<' ';
		}
		cout<<"\n";
	}
}
