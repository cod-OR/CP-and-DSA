mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    freopen("input.txt", "w", stdout);   // Directs the output to file "input.txt"
    
    ll t=1;
    t= rng()%N+1;         // Testcases
    cout<<t<<endl;
    while(t--){
        
        n= rng() % A +1 ;
        cout<<n<<endl;

        std::vector<ll> ar(n);
        
        for(int i=0;i<n;i++){
            ar[i]= rng() % A + 1;
        }

        // to creat a permutation
        // for (int i = 0; i < N; i++)ar[i] = i;
        // shuffle(all(ar), rng);

        for(auto it:ar)cout<<it<<" ";
        cout<<endl;    
    }
}
