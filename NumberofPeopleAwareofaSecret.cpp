class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long>dp(n+1);
    long mod=(long)1e9+7;
    long noOfpeopleSharingSecret=0;
    long ans=0;  
    // day 1 only 1 person know the secret
    dp[1]=1;

    // i stands for days 
    for(int i=2;i<=n;i++){
        long noOfNewPeopleSharingSecret=dp[max(i-delay, 0)];
        long noOfPeopleForgettingSecret=dp[max(i-forget, 0)];
        noOfpeopleSharingSecret+=(noOfNewPeopleSharingSecret-noOfPeopleForgettingSecret+mod)%mod;
        dp[i]=noOfpeopleSharingSecret;
    }
    for(int i=n-forget+1;i<=n;i++){
        ans=(ans+dp[i])%mod;
    }
    return ans;
    }
};
