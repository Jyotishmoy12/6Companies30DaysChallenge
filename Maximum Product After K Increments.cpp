class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
    priority_queue <int, vector<int>, greater<int> > pq; 
    for(int x:nums){
        pq.push(x);
        // now it will look like this-->[2,3,3,6]
    } 
    long long int mod=1000000007;
    long long i=0, ans=1;
    while(i<k){
        // in first iteration--> while(0<k)
        int m=pq.top(); // m=2
        pq.pop();
        pq.push(m+1); // so now m=3 and again push it in the pq->[3,3,3,6]
        i++;
        // in 2 nd iteration m=3
        // now --> pq.push(m+1)-> m=4 and pq->[3,4,3,6]
    }
    while(!pq.empty()){
        ans=(ans*pq.top())%mod;
        pq.pop();
    }
    return ans%mod;
    }

};

// We can increment minimum number in all k operations and take their product in end.

// But why it works ?

// Let's take two integers x and y and (x > y)

// Now if you increment x by 1 then your product will be
// product = (x + 1) * y = x * y + y

// And if you increment y by 1 then your product will be
// product = x * (y + 1) = x * y + x

// As x * y is common in both, and as x > y so (x * y + x > x * y + y)
// That's why it's always optimal to increment minimum number if you want to maximize their product

// So, we do this for all k operations.
