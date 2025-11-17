class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = 0, i = 0;
        while(i < nums.size() && nums[i] != 1) i++;
        for(i = i + 1; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(n < k) return false;
                n = 0;
            } else n++;
        }
        return true;
    }
};