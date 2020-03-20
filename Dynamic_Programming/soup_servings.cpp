class Solution {
public:
    map< pair<int,int> ,double>mp;
    double find(int A,int B){
        if(A<=0&&B>0) return 1;
        if(A<=0&&B<=0) return 0.5;
        if(A>0&&B<=0) return 0;
        if(mp.find({A,B})!=mp.end()){
            return mp[{A,B}];
        }
        double ans=0.0;
        ans=find(A-100,B)+find(A-75,B-25)+find(A-50,B-50)+find(A-25,B-75);
        ans=ans/4.0;
        mp[{A,B}]=ans;
        return ans;
    }
    double soupServings(int N) {
        if(N>=4800) return 1.0;
        return find(N,N);
    }
};