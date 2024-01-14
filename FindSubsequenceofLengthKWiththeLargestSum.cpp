class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    priority_queue<pair<int, int>>pq;
    // pushing nums and it's indexes in the pq;
    for(int i=0;i<nums.size();i++){
        pq.push({nums[i], i});
        // now it will look like this-->[3->3, 3->2, 1->1, 2->0]
    } 
    vector<int>index;
    while(k--){
        // here k=2 so pop out the indexes from the pq
        // so in 1 st iteration k=2-> index=[3]
        // in 2 nd iteration k=1->index=[3,2]
        pair<int, int>it=pq.top();
        index.push_back(it.second);
        pq.pop();
    } 
    // sort the index array  
    sort(index.begin(), index.end());
    // index array=>[2,3];
    vector<int>ans;
    for(int i=0;i<index.size();i++){
        // nums[index[0]]->3
        // nums[index[1]]->3
        ans.push_back(nums[index[i]]);
    }
    return ans;
    }
};
