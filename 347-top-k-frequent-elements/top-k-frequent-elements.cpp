class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Use hash map to store frequency of every number
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        // Copy the hash map to a vector of pair and sort
        vector<pair<int, int>> vec(count.begin(), count.end());
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        // Build result vector
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i].first);
        }
        return result;
    }
};