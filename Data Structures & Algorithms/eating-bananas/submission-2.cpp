class Solution {
public:

    bool feasible(int k, vector<int>& piles, int h){
        int time = 0;

        for(int pile : piles){
            time += (pile+k-1)/k;
            if(time > h) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while(lo < hi){
            int mid = lo + (hi-lo)/2;

            if(feasible(mid, piles, h)) hi = mid;
            else lo = mid+1;
        }

        return lo;
    }
};
