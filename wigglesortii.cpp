class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    int n=nums.size();
    // max heap
    priority_queue<int>pq;
    for(int x:nums) pq.push(x);
    // odd postion elements
    int i=1; // 1, 3, 5 positions were occupied by [_6_5_4_] 
    while(pq.size()>0 && i<n){
        nums[i]=pq.top();
        pq.pop();
        i+=2;
    }
    // even postion elements 
    int j=0; // 2, 4, 6 postions were occupied by 1's so answer is
    // [1, 6, 1, 5, 1, 4] 
    while(pq.size()>0 && j<n){
        nums[j]=pq.top();
        pq.pop();
        j+=2;
    }  
    }
};
