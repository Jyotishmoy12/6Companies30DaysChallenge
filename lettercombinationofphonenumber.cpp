class Solution {
    private:
    void help(int i, string&s, string&temp, vector<string>&ans, unordered_map<char, string>m){
        // if i has reached till the end of given string we have reached a valid combination
        // we should include it into ans[][] and return back
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
       string str=m[s[i]]; // s[i]-->2 so m[s[i]]-->"abc" 
       for(int j=0;j<str.size();j++){
           // putting this char in temp and ask recursion to do rest of the task
           temp.push_back(str[j]);
           help(i+1, s, temp, ans, m);
           temp.pop_back();
       }
    }
public:
    vector<string> letterCombinations(string digits) {
    // for empty string we need to return an empty vector
    if(digits.size()==0)
    return {};
    // to solve this question we need to map all letters this is done using ,map
    unordered_map<char, string>m;
    m['2']="abc";
    m['3']="def";
    m['4']="ghi";
    m['5']="jkl";
    m['6']="mno";
    m['7']="pqrs";
    m['8']="tuv";
    m['9']="wxyz";
    vector<string>ans;
    string temp;
    help(0, digits, temp, ans, m);
    return ans;    
    }
};
