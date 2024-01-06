class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    vector<int>ans;
    // iterating the queries
    for(auto &it:queries){
        int k=it[0];
        int trim=it[1];
        // pq will look like this somehow-->[["2", 0],["3", 1],["1", 2],["4", 3]]
        priority_queue<pair<string, int>>pq;
        for(int i=0;i<nums.size();i++){
            int wSize=nums[i].size(); // nums[0].size()--> 2
            string temp=nums[i].substr(wSize-trim, trim); 
            pq.push({temp, i}); // storing the string as well as the index in sorted fashion

            if(pq.size()>k){
                pq.pop();
            }
        }
      //top will contain rank as we are poping element from priority queue when its size exceed than rank
      ans.push_back(pq.top().second);  
    } 
    return ans;   
    }
};
