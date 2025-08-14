class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Step 1: Create a min-heap of first k elements
        priority_queue<int, vector<int>, greater<int>> minh(nums.begin(), nums.begin() + k);

        // Step 2: Process the rest of the elements
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > minh.top()) {
                minh.pop();        // remove smallest
                minh.push(nums[i]); // insert current number
            }
        }

        // Step 3: The root of min-heap is the kth largest
        return minh.top();
    }
};
