class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();

        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        int total_cost = accumulate(cost.begin(), cost.end(), 0);

        if(total_gas < total_cost) return -1;
        
        int start = 0, i = 0;
        int tank = 0;

        while(i < n){
            tank += gas[i];
            tank -= cost[i];

            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
            i++;
        }

        return start;
    }
};
