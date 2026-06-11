class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = (int)hand.size();

        unordered_map<int, int> freq;

        for(int& i : hand) freq[i]++;

        sort(hand.begin(), hand.end());

        for(int i = 0; i < n; i++){
            int curr = hand[i];
            int size = 0;

            if(!freq.count(curr)) continue;

            while(size != groupSize){
                auto it = freq.find(curr);
                if(it == freq.end()) return false;

                if(--it->second ==0 ) freq.erase(curr);
                curr++;
                size++;
            }
        }

        return true;
    }
};
