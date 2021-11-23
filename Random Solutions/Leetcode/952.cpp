

//  952. Largest Component Size by Common Factor

// idea is to use DSU, 
// every disjoin set consists of numbers whose gcd is more than 1

// first make 1e5 different sets.
// traverse through prime factors of each element in the array.
// connect this element to sets of all its prime factors, 
// this way if two components were not connected earlier, they will get connected through this element


class Solution {
    vector<int> primefactorize(int n){
        vector<int> primefactors;
        if(n%2==0)primefactors.push_back(2);
        while(n%2==0)n/=2;
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0)
                primefactors.push_back(i);
            while(n%i==0)
                n/=i;
        }
        if(n>1)
            primefactors.push_back(n);
        
        return primefactors;
    }
    vector<int> par;
    int find(int a){
        if(par[a]==a)return a;
        else 
            return par[a]=find(par[par[a]]);
    }
    void unionn(int a, int b){
        a=find(a);    
        b=find(b);
        par[a]=b;
    }
public:
    Solution(){
        par = vector<int> (100001);
        for(int i=1;i<=100000;i++){
            par[i]=i;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        for(auto it:nums){
            vector<int> primefactors = primefactorize(it);
            for(auto factor:primefactors){
                unionn(factor, it);
            }
        }
        
        vector<int> roots(100001);
        int ans=1;
        for(auto it:nums){
            int p= find(it);
            roots[p]++;
            ans=max(ans, roots[p]);
        }
        return ans;
    }
};

