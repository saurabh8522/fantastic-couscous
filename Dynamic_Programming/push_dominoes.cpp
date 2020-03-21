class Solution {
public:
    string pushDominoes(string d) {
        if(d.size()<2) return d;
        int n=d.size();
        int i,j;
        for(i=0;i<d.size();){
            // cout<<i<<endl;
            if(d[i]!='.'){i++;continue;} 
            for(j=i+1;j<d.size();j++){
                // cout<<j<<endl;
                if(d[j]!='.'){
                    // i=j+1;
                    break;
                }
            }
            // cout<<i<<" "<<j<<endl;
            if(i==0&&j==d.size()) return d;
            if(i==0&&d[j]=='L'){
                for(int k=0;k<j;k++){
                    d[k]='L';
                }
                int k;
                for(k=j;k<d.size();k++){
                    if(d[k]=='.'){
                        i=k;
                        break;
                    }
                }
                if(k==d.size()) return d;
                continue;
            }
            else if(i==0&&d[j]=='R'){
                int k;
                for(k=j;k<d.size();k++){
                    if(d[k]=='.'){
                        i=k;
                        break;
                    }
                }
                if(k==d.size()) return d;
                continue;
            }
            if(j==d.size()&&d[i-1]=='R'){
                for(int k=i;k<j;k++){
                    d[k]='R';
                }
            }
            else if(j==d.size()&&d[i-1]=='L') return d;
            int l=i,r=j-1;
             if(l==r&&l!=0&&r!=n-1){
                    if(d[l-1]==d[r+1]){
                        d[l]=d[l-1];
                    }
                }
            while(l<r){
                if(d[i-1]=='L'&&d[j]=='R'){
                    break;
                }
                if(d[i-1]=='R'){
                    d[l]='R';
                    l++;
                }
                if(d[j]=='L'){
                    d[r]='L';
                    r--;
                }
                if(l==r&&l!=0&&r!=n-1){
                    if(d[l-1]==d[r+1]){
                        d[l]=d[l-1];
                    }
                }
            }
            int k;
            for(k=j;k<d.size();k++){
                if(d[k]=='.'){
                    i=k;
                    break;
                }
            }
            if(k==d.size()) return d;
            // cout<<d<<endl;
        }
        return d;
    }
};