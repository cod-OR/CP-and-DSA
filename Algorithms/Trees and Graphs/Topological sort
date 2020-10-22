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

void solve(){
	ll n,m;
	cin>>n>>m;
	std::vector<ll> adj[n+1];
	std::vector<ll> indeg(n+1);
	for(int i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		adj[a].pb(b);
		indeg[b]++;
	}	
	queue<ll> q;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0)q.push(i);
	}
	std::vector<ll> topo_sorted;
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		topo_sorted.pb(u);
		for(auto it:adj[u]){
			indeg[it]--;
			if(indeg[it]==0){
				q.push(it);
			}
		}
	}
	if(topo_sorted.size()!=n)cout<<"Contains cycles"<<endl;
	else
		for(auto it:topo_sorted)cout<<it<<" ";cout<<endl;
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
