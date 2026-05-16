class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, nums.size()-k, 0, nums.size()-1);
    }

    int quickselect(vector<int>& nums, int k, int l, int r){

        while(l < r){
            int p = partition(nums, l, r);

            if(p == k) return nums[p];
            else if(p > k) r = p-1;
            else l = p+1;
        }
        return nums[l];
    }

    int partition(vector<int>& nums, int l, int r){
        int mid = l + (r-l)/2;
        swap(nums[mid], nums[r]);
        int pivot = nums[r];
        int i = l;

        for(int j = l; j < r; j++){
            if(nums[j] <= pivot){
                swap(nums[j], nums[i]);
                i++;
            }
        }

        swap(nums[i], nums[r]);
        return i;
    }
};
