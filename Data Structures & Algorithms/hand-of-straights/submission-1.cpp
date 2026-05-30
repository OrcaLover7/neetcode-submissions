class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = (int)hand.size();
        if(n%groupSize) return false;

        map<int, int> freq;

        for(int i : hand) freq[i]++;


        while(!freq.empty()){
            auto start = freq.begin();
            int start_val = start->first;
            
            int count = 0;

            while(count != groupSize && freq.find(start_val) != freq.end()){
                count++;
                int curr_freq = --freq[start_val];
                if(!curr_freq) freq.erase(start_val);
                start_val++;
            }

            if(count != groupSize) return false;

        }

        return true;
    }
};
