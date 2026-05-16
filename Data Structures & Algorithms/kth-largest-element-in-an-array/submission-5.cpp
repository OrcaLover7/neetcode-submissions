class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, nums.size()-k, 0, nums.size()-1);
    }

    int quickselect(vector<int>& nums, int k, int l, int r){
        if(l == r) return nums[l];
        int p = partition(nums, l, r);

        if(p == k) return nums[p];
        else if(p > k) return quickselect(nums, k, l, p-1);
        else return quickselect(nums, k, p+1, r);
    }

    int partition(vector<int>& nums, int l, int r){
        // std::random_device rd;

        // // 2. Standard mersenne_twister_engine seeded with rd()
        // std::mt19937 gen(rd());

        // // 3. Define the distribution range [l, r] (inclusive)
        // std::uniform_int_distribution<int> distrib(l, r);

        // // 4. Generate the random number
        // int random_num = distrib(gen);
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
        //important, this is nums[i] and nums[r], not pivot that gets swapped. i did that mistake first time and it tle'd
        swap(nums[i], nums[r]);

        return i;
    }
};
