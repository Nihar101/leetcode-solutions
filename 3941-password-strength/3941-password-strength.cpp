class Solution {
public:
    int passwordStrength(string password) {
        map<int,int> m;
        for(int i=0;i<password.size();i++){
            if(password[i]>='a'&&password[i]<='z')m[password[i]]=1;
            else if(password[i]>='A'&&password[i]<='Z')m[password[i]]=2;
            else if(password[i]>='0'&&password[i]<='9')m[password[i]]=3;
            else if(password[i]=='!'||password[i]=='@'||password[i]=='#'||password[i]=='$')m[password[i]]=5;
        }
        int count=0;
        for(auto x:m){
            count+=x.second;
        }
        return count;
    }
};