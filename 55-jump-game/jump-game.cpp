class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = 0;
        for(int i=0;i<nums.size();i++){
            if(maxjump < i) return false;
            maxjump = max(maxjump,nums[i]+i);
        }
        return true;
    }
};