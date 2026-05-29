class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();

        vector<int> diff(n);
        bool positive = false;
        vector<int> cand;

        for(int i = 0; i < n; i++){
            diff[i] = gas[i] - cost[i];
            if(diff[i] >= 0){
                positive = true;
                cand.push_back(i);
            }
        }

        if(!positive) return -1;

        for(int can : cand){
            int start = can;
            int gas_tot = 0;
            int k = n+1;

            while(k){
                start = start%n;
                gas_tot += diff[start];
                if(gas_tot < 0) break;
                start++;
                k--;
            }

            if(!k) return can;
        }

        return -1;

    }
};
