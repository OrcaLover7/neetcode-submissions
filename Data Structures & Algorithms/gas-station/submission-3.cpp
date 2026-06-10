class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();

        vector<int> diff(n, 0);

        for(int i = 0; i < n; i++) diff[i] = gas[i] - cost[i];

        for(int i = 0; i < n; i++){
            int sum = 0;
            int k = n;
            int j = i;
            bool possible = true;

            while(k--){
                int index = j%n;
                sum += diff[index];
                if(sum < 0){
                    possible = false;
                    break;
                }
                j++;
            }

            if(possible) return i;
        }

        return -1;
    }
};
