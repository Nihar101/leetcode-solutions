class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int a = abs(source[1]-target[1]);
        int b = abs(source[0]-target[0]);
        if(a==b)return 1;
        else if((a+b)%2==0)return 2;
        return -1;
    }
};