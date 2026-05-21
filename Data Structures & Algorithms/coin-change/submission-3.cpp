class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return amount;

        queue<int> q;
        q.push(0);
        vector<int> seen(amount+1, 0);
        int steps = 0;
        seen[0] = 1;
        // sort(coins.begin(), coins.end());

        while(!q.empty()){
            steps++;
            int size = (int)q.size();

            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();

                for(int& coin : coins){
                    int nxt = coin + cur;
                    if(nxt == amount) return steps;
                    // if(seen[nxt]) continue;
                    // if(nxt > amount) break;
                    if(nxt > amount || seen[nxt]) continue;
                    seen[nxt] = 1;
                    q.push(nxt);
                }
            }
        }

        return -1;

    }
};
