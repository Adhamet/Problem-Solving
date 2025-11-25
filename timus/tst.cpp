#include <bits/stdc++.h>

using i64 = long long;

struct SPF {
	int N;
	std::vector<int> spf;
	std::vector<int> numDiv, mobius, totient;
	std::vector<i64> sumDiv;
	bool spfDone = false;
	bool numDivDone = false, sumDivDone = false, mobiusDone = false, totientDone = false;

	SPF(int n) : N(n) {}

	// Explicitly compute SPF once
	void computeSPF() {
		if (spfDone) return;
		spf.resize(N+1); std::iota(spf.begin(), spf.end(), 0);
		for(int i=2;i*i<=N;i++)
			if(spf[i]==i) for(int j=i*i;j<=N;j+=i) if(spf[j]==j) spf[j]=i;
		spfDone = true;
	}

	// Compute multiplicative functions, assumes SPF is already computed
	void compute(bool wantNumDiv=false, bool wantSumDiv=false, bool wantMobius=false, bool wantTotient=false) {
		assert(spfDone && "SPF must be computed first!");
		if (wantNumDiv && !numDivDone) { numDiv.assign(N+1,1); numDiv[0]=0; numDivDone=true; }
		if (wantSumDiv && !sumDivDone) { sumDiv.assign(N+1,1); sumDiv[0]=0; sumDivDone=true; }
		if (wantMobius && !mobiusDone) { mobius.assign(N+1,1); mobiusDone=true; }
		if (wantTotient && !totientDone) { totient.assign(N+1,0); totient[0]=0; totient[1]=1; totientDone=true; }

		for(int i=2;i<=N;i++){
			int p = spf[i], cnt=0, x=i;
			while(x%p==0) x/=p, cnt++; // dont need for count if going to factorize already
			if (wantNumDiv) numDiv[i] = numDiv[x]*(cnt+1); // (exp1 + 1)*(exp2 + 1)*...*(expn + 1)
			if (wantSumDiv) sumDiv[i] = sumDiv[x]*((pow(p,cnt+1)-1)/(p-1)); // watchout for pow <--------
			if (wantMobius) mobius[i] = (x % p == 0 ? 0 : -mobius[x]);
			if (wantTotient) totient[i] = (x % p == 0 ? totient[x]*p : totient[x]*(p-1));
		}
	}

	// Factorize x <= N, assumes SPF is already computed
	std::vector<std::pair<int,int>> factorize(int x) {
		assert(spfDone && "SPF must be computed first!");
		std::vector<std::pair<int,int>> factors;
		while (x > 1) {
			int p = spf[x], cnt = 0;
			while (x % p == 0) { x /= p; cnt++; }
			factors.push_back({p, cnt});
		}
		return factors;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	
	
	return 0;
}
