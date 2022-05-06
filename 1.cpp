class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto it = um.find(target-nums[i]);
            if (it != um.end()) {
                return {i, it->second};
            } else {
                um.insert(pair<int,int>(nums[i], i));
            }
        }
        return {};
    }
};