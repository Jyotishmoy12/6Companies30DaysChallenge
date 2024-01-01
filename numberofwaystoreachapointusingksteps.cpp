class Solution {
public:
    // declare a dp
    int dp[3005][1005];
    long long mod=1e9+7;
    int help(int start, int end, int k){
        // base case since we need to count so we has to be return either 1 or 0
        if(k==0){
            // so number of steps are over
            // so check start reached the end or not if yes then return 1 either 0
            if(start==end)
            return 1;
            else
            return 0;
        }
        // if already calculated
        if(dp[start+1000][k]!=-1) return dp[start+1000][k];
        // count ways 
        long long ways=0;
        // move left so start will be -ve
        ways=(ways%mod+help(start-1, end, k-1)%mod)%mod;
       // move right so start will be +ve
       ways=(ways%mod+help(start+1, end, k-1)%mod)%mod;
       return dp[start+1000][k]=ways;
    }
    int numberOfWays(int startPos, int endPos, int k) {
      memset(dp, -1, sizeof(dp));
      return help(startPos, endPos, k);  
    }
};
