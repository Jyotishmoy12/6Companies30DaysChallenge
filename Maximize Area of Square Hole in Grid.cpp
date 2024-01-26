/* Approach : Sort and find consecutive horizontal and vertical bars
Time : O(nlogn) // n is max of hBars and vBars length (100)
Space : O(logn)
*/

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // sort hbars and vBars in ascending order        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        
        // find max consecutive horizontal bars
        int maxContHorizontalBars = 1;
        int currContHorizontalBars = 1;
        
        for(int i=0; i<hBars.size()-1; i++){
            if(hBars[i] + 1 == hBars[i+1])      // consecutive bar
                currContHorizontalBars++;
            else 
                currContHorizontalBars = 1;
            maxContHorizontalBars = max(maxContHorizontalBars, currContHorizontalBars);
        }

        // find max consecutive vertical bars
        int maxContVerticalBars = 1;
        int currContVerticalBars = 1;
        
        for(int i=0; i<vBars.size()-1; i++){
            if(vBars[i] + 1 == vBars[i+1])      // consecutive bar
                currContVerticalBars++;
            else 
                currContVerticalBars = 1;
            maxContVerticalBars = max(maxContVerticalBars, currContVerticalBars);
        }

        // gap created will be +1 of consecutive bars
        // and square side will be min of horizonal and vertical gap as both side must be equal
        int squareSide = min(maxContHorizontalBars, maxContVerticalBars) + 1;
        return squareSide * squareSide;
    }
};
