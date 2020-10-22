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

ll n;
std::vector<pair<int,int>> adj[1000007];
std::vector<ll> dist(1000007, 1e9);

void Dijkstra(int src){
	set<pair<int,int>> s;
	dist[src]=0;
	s.insert(mp(0,1));
	while(!s.empty()){
		auto p=*s.begin();
		s.erase(s.begin());
		int u=p.ss;
		for(auto it:adj[u]){
			if(dist[it.ff]>dist[u]+it.ss){
				dist[it.ff]=dist[u]+it.ss;
				s.insert(mp(dist[it.ff],it.ff));
			}
		}
	}
}


void solve(){
	ll m;
	cin>>n>>m;
	map<pair<int,int>,int> edges;
	for(int i=0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));// undirected
	}
	Dijkstra(1);
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
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


