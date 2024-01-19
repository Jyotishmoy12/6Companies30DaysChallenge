class Solution {
public:
// all the directions all the 9 cells
    vector<vector<int>>directions={
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0, 0},{0,1},
        {1, -1},{1,0},{1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int n=img.size();
    int m=img[0].size();
    vector<vector<int>>res(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // becoz for every cell we need sum and count of itself and it's neighbours
         int sum=0;
         int count=0;
          for(auto &it:directions){
              // valid neighbours
              int i_=i+it[0];
              int j_=j+it[1];
              //cout<<j_<<endl;
              if(i_>=0 && i_<n && j_>=0 && j_<m){
                  sum+=img[i_][j_];
                  count++;
                 // cout<<count<<endl;
              }
          }
          res[i][j]=sum/count;
        }
    } 
    return res; 
    }
};
