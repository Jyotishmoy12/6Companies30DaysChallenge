class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < 11) {
            return ans; // If the input string is less than 11 characters, there can't be any repeated 10-character substrings.
        }
        
        map<string, int> mp;
        for (int i = 0; i <= s.size() - 10; i++) {
            string substr = s.substr(i, 10); // finding the 10 length substring
            mp[substr]++; // add it into the map
        }
        
        for (auto it : mp) {
            // if the count of found substring is more than 1 so we have found an answer
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        } 
        return ans;
    }
};
