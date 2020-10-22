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

//  A Very Simple , Wonderful algorithm
// Uses Disjoint set

map<int,int> root;

int root_of(int a){
	while(root[a]!=a){
		root[a]=root[root[a]];
		a=root[a];
	}
	return a;
}

void unionn(int a, int b){
	int p=root_of(a);
	int q=root_of(b);
	root[p]=q;
}

bool find(int a, int b){
	return root_of(a)==root_of(b);
}

vector< pair< int,pair<int,int > > >v;

void Kruskal(){
	ll m,n;
	cin>>n>>m;
	for(int i=0;i<=n;i++)root[i]=i;
	
	for(int i=0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		v.pb(mp(c,mp(a,b)));
	}
	sprt(all(v));
	ll ans=0;
	for(int i=0;i<m;i++){
		auto it=v[i];
		int a=it.ss.ff;
		int b=it.ss.ss;
		int c=it.ff;
		if(find(a,b))continue;
		else{
			unionn(a,b);
			ans+=c;
		}
	}
	cout<<ans<<endl;

}


int main(){	
    sub;    
    fast;
   	int t=1;
    // cin>>t;
    while(t--){
    	Kruskal();
	}
    return 0;
}        

        		        // Mischief Managed //    
