class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> a;
        for(int i:nums)
            a[i]++;

        // now the map will look like this-->[3->0, 1->2, 4->1, 5->1]
        int ans=0;
        for(auto x:a)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
            // since in this condition k!=0 so k=2
            // in first iteration->
            // 3+2=5 which exist in the map so ans=1;
            // in 2 nd iteration 1+2=3 which exist in the map so ans=2
            // rests doesnot exist so ans=2
             else if(a.find(x.first+k)!=a.end())
                ans++;
        }
        
        return ans;
    }
};
