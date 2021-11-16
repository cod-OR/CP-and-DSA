
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int st=1,en=m*n;
        int ans=1;
      
      // binary search the answer
        while(st<=en){
            int mid=(st+en)/2;
            int cnt=0;
          
          // Count number of numbers strictly less than mid
            for(int i=1;i<=m;i++){
                int c= mid/i;
                if(mid%i==0)c--;
                cnt+=min(n,c);
            }
            if(cnt<k){
                ans=mid;
                st=mid+1;
            }
            else{
                en=mid-1;
            }
        }
        return ans;
    }
};
