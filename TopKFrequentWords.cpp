class Solution {
    struct compare {
        bool operator()(const pair<string, int>& i, const pair<string, int>& j) {
            if (i.second == j.second) {
                return i.first > j.first; // Compare lexicographically if frequencies are equal
            }
            return i.second < j.second; // Compare frequencies
        }
    };

public:
    vector<string> topKFrequent(vector<string>& nums, int k) {
        map<string, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        } 
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> p(mp.begin(), mp.end()); 
        vector<string> ans;
        while (k--) {
            ans.push_back(p.top().first);
            p.pop(); 
        } 
        return ans;    
    }
};
