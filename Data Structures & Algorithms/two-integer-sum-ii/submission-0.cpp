class Solution {
public:

    //normally, I would just use a set or a map I guess? What about potential duplicates in the array? how would the set wowrk then?
    //since they are saying O(1) additional space, and also given that the array is sorted in non-decreasing order, something like binary search
    //or two pointers would wowrk out
    //will have to weed out the duplicates
    //binary search - iterate through the array, and for each element, try to find the complement of that number using binary search
    //but let me go with 2 pointers
    vector<int> twoSum(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l < r){
            int sum = nums[l] + nums[r];

            if(sum == target){
                return {l+1, r+1};
            }
            else if(sum > target){
                //need to take care of duplicates
                if(r > l and nums[r] == nums[r-1])
                    while(r > l and nums[r] == nums[r-1]) r--;
                r--;
            }
            else{
                //need to take care of duplicates
                if(l < r and nums[l] == nums[l+1])
                    while(l < r and nums[l] == nums[l+1]) l++;
                l++;
            }
        }

        return {-1, -1};
    }
};
