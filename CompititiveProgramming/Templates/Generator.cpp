void solve(){
    
    n= rand() % A +1 ;
    cout<<n<<endl;

    std::vector<ll> ar(n);
    
    for(int i=0;i<n;i++){
        ar[i]= rand() % A + 1;
    }

    for(auto it:ar)cout<<it<<" ";
    cout<<endl;    

}
