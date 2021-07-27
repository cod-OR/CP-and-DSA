        	//    I solemnly swear that I am upto no good //

#include <bits/stdc++.h>
#define sub   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define mp make_pair
#define ff first
#define ss second
#define NN cout<<"NO"<<endl;
#define YY cout<<"YES"<<endl;
#define ub upper_bound
#define lb lower_bound
#define A 1000001
#define make(a,b,c) make_pair(a,make_pair(b,c)) 
bool comp(ll a,ll b){
	return a>b;
}


int KMP(string &text, string &patt, int n){
	
	// longest prefix suffix
	vector<int> lps(n); 
	ll cnt=0;
	int i=0,j=0;

	for(int j=1;j<n;j++){

		while(i>0 && patt[i]!=patt[j]){
			i=lps[i-1];
		}
		lps[j]=lps[i];

		if(patt[j]==patt[i]){
			i++;
			lps[j]++;
		}
		
	}

	i=0;
	j=0;

	while(i<text.size()){
		if(text[i]==patt[j]){
			j++;
			if(j==n){
				// cout<<"found at "<<i-n+1<<endl;
				cnt++;
				j=lps[j-1];
			}
		}
		else{
			if(j!=0)j=lps[j-1];
		}
		
		i++;
	}
	return cnt;
}

void solve(){
	
	ll n;
	string text,patt;
	
	cin>>patt; cin>>text;
	n=patt.size();
	int ans= 
	KMP(text,patt,n);
	cout<<ans<<endl;
}


int main(){	
    sub;    
    fast;
   	int t=1;
    // cin>>t;
    while(t--){
    	solve();
	}
    return 0;
}        

        		        // Mischief Managed //    

