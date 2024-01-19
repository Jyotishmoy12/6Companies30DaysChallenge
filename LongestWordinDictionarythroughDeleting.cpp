class Solution {
    public:
    string findLongestWord(string s, vector<string>& d) {
    string res="";
    for(string str:d){
        if(isSubsequence(s, str)){
            // The length of "apple" (5) is greater than the length of the current res (0), so res is updated to "apple".
            //The length of "plea" (4) is shorter than the length of the current res ("apple"), so res remains "apple". Additionally, since "plea" is lexicographically larger than "apple", the res value is not updated
            //(str.size() == res.size() && str.compare(res) < 1): If the lengths of str and res are the same, it means they have the same length. In this case, the comparison str.compare(res) < 1 is used to check if str is lexicographically smaller than or equal to res. If it is, then res is updated to str.
            if(str.size()>res.size() ||(str.size()==res.size() && str.compare(res)<1))
            res=str; // dictionary word should be subsequence of s
        } 
    }
    return res;    
    }
    bool isSubsequence(string s, string D){
        int i=0, j=0;
        if(D.size()>s.size()) return false;
        while(i<s.size() && j<D.size()){
            if(s[i]==D[j]){
                i++;
                j++;
            }
            else if(s[i]!=D[j]){
                i++;
            }
        }
        return j==D.size(); // reach the end
    }
};
// Tc=0(n*x)
// sc-0(1)
