class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      int n=s.length();
      int ans=-1, window=0, left=0;
      for(int right=0;right<n;right++){
          // in first iteration
          //window is 1
          // so it didnot enter the loop
          // when window=4
          // it enteres the loop
          window+=abs(s[right]-t[right]);
          while(window>maxCost){
              // 4>3
              // so remove a from s and b from t
              window-=abs(s[left]-t[left]);
              left++;
          }
          // updating the answer
          ans=max(ans, right-left+1);
      } 
      return ans; 
    }
};
