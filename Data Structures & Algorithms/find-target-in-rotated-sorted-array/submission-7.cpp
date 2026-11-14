class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int lo = 0, hi = n-1;

        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] > nums[hi]) lo = mid+1;
            else hi = mid;
        }

        int pivot = lo;

        int l1 = 0, h1 = max(0,pivot-1);
        int l2 = pivot, h2 = n-1;

        if(target >= nums[l1] and target <= nums[h1]) lo = l1, hi = h1;
        else lo = l2, hi = h2;
        

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) hi = mid-1;
            else lo = mid+1;
        }

        return -1;
    }
};
