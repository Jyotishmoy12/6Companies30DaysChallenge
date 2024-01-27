class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    unordered_set<string> mySet;
    // sort the startWords and add them it the set 
    //-->["ant", "act", "ackt"]

    for (const string& s : startWords) {
        string charStr = s;
        sort(charStr.begin(), charStr.end());
        mySet.insert(charStr);
    }

    int cnt = 0;

    for (const string& t : targetWords) {
        int n = t.length();
        
        for (int i = 0; i < n; ++i) {
            // in first iteation--> remove t from "tack" and sort it so it will look like this--> "ack" not present in the startWords 
            // and remove k from "tack" and sort it now it will look like this
            //"act" which is present in the startWords so increase the count
            // keep removing one character from each string, sort, and then check
            string reducedStr = t.substr(0, i) + t.substr(i + 1);
            sort(reducedStr.begin(), reducedStr.end());

            if (mySet.count(reducedStr) > 0) {
                cnt++;
                break;
            }
        }
         
    }
      return cnt; 
    }
};
