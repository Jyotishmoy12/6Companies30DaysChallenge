class Solution {
public:
    string frequencySort(string s) {
        // Map to store character frequencies
        unordered_map<char, int> mp;

        // Count character frequencies
        for (char c : s) {
            mp[c]++;
        }

        // Priority queue to store pairs in descending order of frequency
        priority_queue<pair<int, char>> pq;

        // Insert characters and their frequencies into the priority queue
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        // Build the result string based on the priority queue
        string res = "";
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            res += string(top.first, top.second);
        }

        return res;
    }
};
