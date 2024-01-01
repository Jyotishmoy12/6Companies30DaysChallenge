class Solution {
    private:
    void backtrack(int start, int target, int k, vector<int>& path, vector<vector<int>>& result) {
    if (target == 0 && path.size() == k) {
        // target becomes zero anf path size is k so we found the answer
        result.push_back(path);
        return;
    }

    if (target < 0 || path.size() > k) {
        return;
    }

    for (int i = start; i <= 9; ++i) {
        // since we can take till 9 so iterate call recursion accordingly
        path.push_back(i);
        backtrack(i + 1, target - i, k, path, result);
        path.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(1, n, k, path, result);
    return result;  
    }
};
