
// 1. two sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> freq;
       
        for(int i=0;i<nums.size();i++){
            
            if(freq[target-nums[i]])
                return {i, freq[target-nums[i]]-1};
            
            freq[nums[i]]=i+1;
            
        }
        return {};
    }
};


