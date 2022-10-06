class Solution {
public:
    int countSetBits(int n){
        if(n==0)
            return 0;
        
        return (n&1)+countSetBits(n>>1);
    }
    
    int bitSetter(int n, int x){
        int curr = n;
        int loc = 0;
        while(x!=0){
            if(!(curr & (1<<loc))){
                curr = curr|(1<<loc);
                x--;
            }
            loc++;
        }
        return curr;
    }
    
    int bitUnsetter(int n, int x){
        int curr = n;
        int loc = 0;
        while(x!=0){
            if(curr & (1<<loc)){
                curr = (curr & ~(1 << (loc)));
                x--;
            }
            loc++;
        }
        return curr;
    }
    
    int minimizeXor(int num1, int num2) {
        int n1 = countSetBits(num1);
        int n2 = countSetBits(num2);
        //cout<<n1<<" "<<n2<<endl;
        if(n1==n2)
            return num1;
        if(n1<n2){
            int x = n2-n1;
            //We need to set first X unset bits of num1
            int z = bitSetter(num1,x);
            return z;
        }
        if(n1>n2){
            //Here we need to keep the first n2 bits from left of num1 as set and make the rest unset
            //i.e. we need to unset the first n1-n2 bits
            int z = bitUnsetter(num1,n1-n2);
            return z;
        }
        return -1;
    }
};