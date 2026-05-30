class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = (int)hand.size();
        if(n%groupSize) return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> freq;

        for(int i : hand) freq[i]++;

        for(int i = 0; i < n; i++){
            int start = hand[i];
            if(!freq[start]) continue;
            
            int count = 1;
            freq[start]--;
            while(count != groupSize && freq[start+1]){
                start = start + 1;
                freq[start]--;
                count++;
            }

            if(count != groupSize) return false;
        }

        return true;
    }
};
