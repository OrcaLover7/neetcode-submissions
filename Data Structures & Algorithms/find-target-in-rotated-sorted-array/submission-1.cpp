class Solution {
public:

    int bin_search(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();

        int l = 0, r = n-1;

        while(l < r){
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]) l = mid+1;
            else r = mid;
        }

        int pivot = l;

        if(pivot == 0) return bin_search(nums, 0, n-1, target);

        if(target >= nums[0] and target <= nums[pivot-1]) return bin_search(nums, 0, pivot-1, target);

        return bin_search(nums, pivot, n-1, target);

    }
};
