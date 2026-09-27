class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int k=0;
        for(int i =0;i<source.size();i++){
            k+= source[i];
            k-= target[i];
        }
        return (k==0);
    }
};