class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        
        // Generate all coordinates and calculate distances
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.push_back({i, j});
            }
        }
        
        // Custom comparator function to sort based on distance
        sort(result.begin(), result.end(), [rCenter, cCenter](const vector<int>& a, const vector<int>& b) {
            return (abs(a[0] - rCenter) + abs(a[1] - cCenter)) < (abs(b[0] - rCenter) + abs(b[1] - cCenter));
        });
        
        return result;
    }
};
