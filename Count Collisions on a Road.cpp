class Solution {
public:
    int countCollisions(string directions) {
    int left=0, right=directions.size()-1;
    int count=0;
    while(left<directions.size() && directions[left]=='L'){
        left++;
    } 
    while(right>=0 && directions[right]=='R'){
        right--;
    } 
    for(int i=left;i<=right;i++){
        if(directions[i]!='S'){
            count++;
        }
    } 
    return count; 
    }
};

/*
cars on left side which are moving in left direction are never going to collide,
Similarly, cars on right side which are moving right side are never going to collide.

In between them every car is going to collide.
*/

