// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long l=1,r=n;
        while(l<=r){
            long long g=(l+r);
            g=g>>1;
        	int ans=guess(g);
        	if(ans==-1){
        		r=g-1;
        	}
        	else if(ans==1){
        		l=g+1;
        	}
        	else{
        		return g;
        	}
        }
        return -1;
    }
};