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

void insertion_sort(std::vector<ll> &ar, ll n){
	for(int i=0;i<n;i++){
		int temp=ar[i],j=i;
		while(j>0 && ar[j-1]>temp){
			ar[j]=ar[j-1];
			j--;
		}
		ar[j]=temp;
	}
}

void solve(){
	ll n;
	cin>>n;
	std::vector<ll> ar(n);
	input(ar,n);
	insertion_sort(ar,n);
	for (auto it:ar)cout<<it<<" ";cout<<endl;
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


