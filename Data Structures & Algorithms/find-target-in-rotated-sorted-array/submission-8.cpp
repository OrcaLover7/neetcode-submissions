class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int lo = 0, hi = n-1;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target) return mid;

            if(nums[lo] <= nums[mid]){
                if(target < nums[lo] or target > nums[mid]) lo = mid+1;
                else hi = mid-1;
            }
            else{
                if(target < nums[mid] or target > nums[hi]) hi = mid-1;
                else lo = mid+1;
            }
        }

        return -1;
    }
};
