class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()) swap(nums1, nums2);

        int m = nums1.size(), n= nums2.size();
        int half = m + (n-m+1)/2;
        int lo = 0, hi = m;

        while(lo <= hi){
            int i = lo + (hi-lo)/2;
            int j = half - i;

            int a_l_m = (i == 0) ? INT_MIN : nums1[i-1];
            int a_r_m = (i == m) ? INT_MAX : nums1[i];
            int b_l_m = (j == 0) ? INT_MIN : nums2[j-1];
            int b_r_m = (j == n) ? INT_MAX : nums2[j];

            if(a_l_m <= b_r_m and b_l_m <= a_r_m){
                int left_max = max(a_l_m, b_l_m);
                if((m+n) % 2) return static_cast<double>(left_max);

                int right_min = min(a_r_m, b_r_m);
                return (left_max + right_min)/2.0;
            }
            else if(a_l_m > b_r_m) hi = i-1;
            else lo = i+1;
        }

        return 0.0;
    }
};
