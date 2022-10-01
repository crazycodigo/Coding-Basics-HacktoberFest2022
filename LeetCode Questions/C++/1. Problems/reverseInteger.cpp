class Solution {
public:
// taking x as input
  
    int reverse(int x) {
// initializing a reverse integer
        int rev = 0;
//  taking remainder and dividing number by 10 through looping
      
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
