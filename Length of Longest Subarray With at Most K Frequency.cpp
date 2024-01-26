class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
    int ans=0;
    unordered_map<int, int>mp;
    for(int i=0, j=0;j<nums.size();j++){
        mp[nums[j]]++;
        while(mp[nums[j]]>k){
            mp[nums[i]]--;
            i++;
        }
        ans=max(ans, j-i+1);
    }  
    return ans;  
    }
};

// Take two pointers i & j. where i is the slow/back pointer & j is the fast/front pointer.
// Keep iterating the jth pointer to next one and keep updating the frequency of jth item.
// If the jth item frequency is more than k then move ith pointer forward and keep decreasing the frequency of the ith item until the jth item frequncy is less than k
// Mean while keep checking the window size and storing the max window size.
