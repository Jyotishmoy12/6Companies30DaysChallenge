class Solution {
public:
    int minMoves2(vector<int>& nums) {
    int n=nums.size();
    int median=n/2;
    int noOfMoves=0;
    // dry run--> [1,2,9,10](sorted array)--> median will be at index 2 so element 9
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        // in first iteration--> nums[0]-nums[2]=8
        // in 2 nd iteration--> nums[1]-nums[2]=7
        // in 3 rd iteration--> nums[3]-nums[2]=1
        // hence total =16
      noOfMoves+=abs(nums[i]-nums[median]);

    }
    return noOfMoves;    
    }
};
