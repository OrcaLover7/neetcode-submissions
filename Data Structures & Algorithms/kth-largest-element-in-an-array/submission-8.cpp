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
        // int mid = l + (r-l)/2;
        std::random_device rd;
        // 2. Standard mersenne_twister_engine seeded with rd()
        std::mt19937 gen(rd());

        // 3. Define the distribution range [l, r] (inclusive)
        std::uniform_int_distribution<int> distrib(l, r);

        // 4. Generate the random number
        int mid = distrib(gen);
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
