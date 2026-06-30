class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        if(n < 0){
            int z = -n;
            while(z--) ans/=x;
        }
        else if(n > 0){
            int z = n;
            while(z--) ans*=x;
        }

        return ans;
    }
};
