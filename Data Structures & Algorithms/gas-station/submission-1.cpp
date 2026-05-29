class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();

        int tot = 0;
        int tank = 0;
        int start = 0;

        for(int i = 0; i < n; i++){
            int d = gas[i] - cost[i];
            tot += d;
            tank += d;
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        }

        return tot >= 0 ? start : -1;
    }
};
