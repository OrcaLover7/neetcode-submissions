class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> freq;

        for(int& i : hand) freq[i]++;

        while(!freq.empty()){
            int curr = freq.begin()->first;
            int size = 0;

            while(size != groupSize){
                auto it = freq.find(curr);

                if(it == freq.end()) return false;
                if(--it->second == 0) freq.erase(curr);
                curr++;
                size++;
            }
            
        }

        return true;
    }
};
