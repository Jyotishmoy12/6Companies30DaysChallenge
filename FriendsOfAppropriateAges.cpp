class Solution {
public:
    bool isFriend(int x, int y){
        bool cond1 = (y <= (x * 0.5) + 7);
        bool cond2 = (y > x);
        bool cond3 = (x < 100 && y > 100); 

        return !(cond1 || cond2 || cond3);
    }

    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> mp;
        for(int age : ages){
            mp[age]++;
        }

        int ans = 0;

        for(auto it1 : mp){
            for(auto it2 : mp){
                if(isFriend(it1.first, it2.first)){
                    ans += it1.second * (it2.second - (it1.first == it2.first ? 1 : 0));
                }
            }
        }

        return ans;
    }
};


// Outer Loop (it1):

// it1 is an iterator over the unordered_map mp, representing a unique age and its count.
// it1.first is the age.
// it1.second is the count of that age.
// Inner Loop (it2):

// Similar to the outer loop, it2 represents a unique age and its count.
// Condition (if (isFriend(it1.first, it2.first))):

// It checks if a friend request can be sent from the person with age it1.first to the person with age it2.first using the isFriend function.
// Update ans:

// If the condition is true, it means a friend request can be sent.
// it1.second represents the count of people with age it1.first.
// (it2.second - (it1.first == it2.first ? 1 : 0)) represents the count of people with age it2.first excluding the case where it1.first and it2.first are the same (hence subtracting 1 in that case).
// The product it1.second * (it2.second - (it1.first == it2.first ? 1 : 0)) represents the total number of friend requests that can be sent from people of age it1.first to people of age it2.first.
// This value is added to the ans variable.
// In summary, the nested loops iterate over all pair
