class Solution {
public:
    int countCollisions(string directions) {
        int k=0;
        int count=0;
        for(int i =0;i<directions.size();i++){
            if(directions[i]=='L'){
                count+=k;
            }
            else{
                k=1;
            }
        }
        k=0;
        for(int i =directions.size()-1;i>=0;i--){
            if(directions[i]=='R')count+=k;
            else k=1;
        }
        return count;
    }
};