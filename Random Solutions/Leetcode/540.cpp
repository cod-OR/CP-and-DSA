class Solution {
  
    // return true iff id is equal to or to the right of required index
    bool check(int id, vector<int> nums){
        if(id%2==1 and nums[id]==nums[id-1]){
            return 0;
        }
        else if(id%2==0 and (id+1)<nums.size() and nums[id+1]==nums[id]){
            return 0;
        }
        else return 1;
        // To the left side of required index, number at even index will be equal to number at next odd index
        // Beyound the required index, this trend will change
    }
  
public:
  
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0, en=n-1;
        int ans;
        while(st<=en){     
          // binary searching the required index
            int mid = (st+en)/2;
            if(check(mid, nums)){
                ans=mid;
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return nums[ans];
    }
  
};
