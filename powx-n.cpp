class Solution {
public:
    double myPow(double x, int n) {
                
   if (n < 0 && n != -n) {
            return 1.0 / myPow(x, -n);
        }
        if (n == 0) {
            return 1;
        }
        double v = myPow(x, n / 2);
        if (n % 2 == 0) {
            return v * v;
        } else {
            return v * v * x;
        }
    }
    }
};