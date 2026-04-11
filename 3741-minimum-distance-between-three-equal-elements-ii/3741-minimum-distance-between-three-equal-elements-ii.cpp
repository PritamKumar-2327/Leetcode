class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> last_indices; // stores {prev, second_prev}
        int min_dist = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (last_indices.count(val)) {
                auto& p = last_indices[val];
                if (p.second != -1) {
                    min_dist = min(min_dist, 2 * (i - p.second));
                }
                // Shift indices: second_prev becomes prev, prev becomes current
                p.second = p.first;
                p.first = i;
            } else {
                last_indices[val] = {i, -1};
            }
        }

        return (min_dist == INT_MAX) ? -1 : min_dist;
    }
};