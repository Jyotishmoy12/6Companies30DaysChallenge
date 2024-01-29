class Solution {
public:
// this will find the peakIndex 
    int peakIndexInMountainArray(MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int l = 0;
        int r = n-1;
        
        while(l < r) {
            
            int mid = l + (r-l)/2;
            
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid+1;
            else
                r = mid-1;
            
        }
        
        return l;
    }
    // this will check in increasing part--> [1,2,3,5,6,4,2,1] and target =4 
    // so here we can't find 4 using binarySearch function from 1->low to 6->peakIndex
    int binarySearch(MountainArray &mountainArr, int l, int r, int target) {
        
        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return -1;
        
    }
// so here comes the reversebinarySearch function this will check from 6 to 1 here we find the target if we didnot find the target here also we simply return -1;
    int reverseBinarySearch(MountainArray &mountainArr, int l, int r, int target) {
        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) { //Because the array in right side of peak is in descending order
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return -1;
        
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int peakIndex = peakIndexInMountainArray(mountainArr);
        
        int idx = binarySearch(mountainArr, 0, peakIndex, target);
        
        if(idx == -1) {
            return reverseBinarySearch(mountainArr, peakIndex, n-1, target);
        }
        
        return idx;
        
    }
};
