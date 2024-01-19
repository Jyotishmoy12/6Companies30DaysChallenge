class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
     map<int, int> wins, losses;

    for (const auto& match : matches) {
        wins[match[0]]++;
        losses[match[1]]++;
    }

    vector<int> notLostAny, lostOneMatch;

    // Find players who have not lost any matches
    for (const auto& pair : wins) {
        // if not able to find in the losses map then it is the winner and hasnot lost any match
        if (losses.find(pair.first) == losses.end()) {
            notLostAny.push_back(pair.first);
        }
    }

    // Find players who have lost exactly one match
    for (const auto& pair : losses) {
        if (pair.second == 1) {
            lostOneMatch.push_back(pair.first);
        }
    }

    // Sort the result vectors
    sort(notLostAny.begin(), notLostAny.end());
    sort(lostOneMatch.begin(), lostOneMatch.end());

    return {notLostAny, lostOneMatch};    
    }
};

//create two maps winners and losses and then store the elements with it's counts.
// iterate in the winners map and check if that element is present or not in the losses map if not then we have found a player with zero losses .
// iterate in the losses map anc check if the element has count==1 if yes then we have found a player with one losses
