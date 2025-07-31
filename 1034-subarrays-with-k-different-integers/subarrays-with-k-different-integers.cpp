class Solution {
public:
    int helper(vector<int>& nums,int k){
        int n=nums.size();
        unordered_map<int ,int> m;
        int l=0,r=0,ans=0,dif=0;
        
        while(r<n){
            if(m[nums[r]]==0) dif++;
            m[nums[r]]++;

            while(l<n && dif>k){
                m[nums[l]]--;
                if(m[nums[l]]==0) dif--;
                l++;
            }

            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};