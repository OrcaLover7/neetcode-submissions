class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = (int)nums.size()-1, target = r-k+1;

        return quickselect(nums, target, l, r);
    }

    int quickselect(vector<int>& nums, int k, int l, int r){

        while(l < r){
            int p = partition(nums, l, r);
            if(p == k) return nums[p];

            if(p > k) r = p-1;
            else l = p+1;
        }

        return nums[l];
    }

    int partition(vector<int>& nums, int l, int r){
        static thread_local std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> distrib(l, r);

        int rn = distrib(gen);
        swap(nums[r], nums[rn]);

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
