class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used, permutation, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& permutation, vector<vector<int>>& result) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            
            used[i] = true;
            permutation.push_back(nums[i]);
            backtrack(nums, used, permutation, result);
            permutation.pop_back();
            used[i] = false;
        }
    }
};