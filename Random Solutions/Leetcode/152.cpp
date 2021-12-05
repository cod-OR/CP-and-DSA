
// 152. Maximum Product Subarray


// There are many possible approach for this problem


//  The simplest one according to me is as follows: 
//  1. if size of array is 1 the first elemnt is the solution
//  2. if array contains at least a zero, the least possible answer is 0
//     And, the candidates for optimal subarrays are the subarrays that lie between two zeroes
//  3. Now, if the candidate subarray contains only +ve numbers or number of -ve numbers is even , product of them will be the solution
//  4. Else, it is obvious that we cannot take all the negative numbers because it will make our product -ve
//     So, we will make two cases - subarray to the right of first -ve number
//     and the subarray liying to the left of last -ve number



class Solution {
    int findProd(vector<int> &nums, int l, int r){
        
        if(l>r)
            return INT_MIN;
        if(r==l)
            return nums[l];
        
        vector<int> negId;
        for(int i=l;i<=r;i++){
            if(nums[i]<0)
            negId.push_back(i);
        }
        
        int prod=1;
        if(negId.empty() or (negId.size())%2==0){
            for(int i=l;i<=r;i++)
                prod *= nums[i];
        }
        else{
            int p1=1, p2=1;
            for(int i=l;i<negId.back();i++)
                p1*=nums[i];
            for(int i=r;i>negId[0];i--)
                p2*=nums[i];
            
            prod=max(p1,p2);
        }
        
        return prod;
        
    }
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int prev=-1;
        int ans=INT_MIN;
        
        if(len==1)
            return nums[0];
        
        for(int i=0;i<len;i++){
            if(nums[i]==0){
                ans=max(ans, findProd(nums, prev+1,i-1));
                prev=i;
            }
        }
        ans=max(ans, findProd(nums, prev+1,len-1));
        if(prev>-1)
            ans=max(ans, 0);
        
        return ans;
    }
};
