class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = (int)hand.size();

        if(n%groupSize) return false;
        
        map<int, int> freq;

        for(int card : hand) freq[card]++;

        while(!freq.empty()){
            auto start_iter = freq.begin();

            int start = start_iter->first;
            int count = 0;

            while(count < groupSize){
                auto it = freq.find(start);
                if(it == freq.end()) return false;
                count++;
                if(!--it->second) freq.erase(start);
                start++;
            }
        }

        return true;
    }
};
