class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    long long original_mass=mass;
    int n=asteroids.size();
    sort(asteroids.begin(), asteroids.end());
    for(int i=0;i<n;i++){
        if(original_mass>=asteroids[i])
        {
          original_mass+=asteroids[i];
        }
        else{
            return false;
        }
    }
    return true;  
    }
};
