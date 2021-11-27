
// 1. two sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(m.find(target - nums[i]) != m.end() and i !=m[target - nums[i]]){
                   return {i,m[target - nums[i]]};
            }
        }
        return {-1,-1};
    }
};
