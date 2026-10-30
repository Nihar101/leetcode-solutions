class Solution {
public:
    string sortVowels(string s) {
        map<char,int> m;
        vector<char> ff;
        map<char,int> order;
        order['a']=-1;
        order['e']=-1;
        order['i']=-1;
        order['o']=-1;
        order['u']=-1;
        int count=5;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                if(order[s[i]]==-1){
                    order[s[i]]=count--;
                }    
                m[s[i]]++;
            }
        }
        priority_queue<pair<pair<int,int>,char>> pq;
        for(auto x:m){
            pq.push({{x.second,order[x.first]},x.first});
        }

        string l="";
        while(pq.size()){
            pair<pair<int,int>,int> p;
            p=pq.top();
            pq.pop();
            int k=p.first.first;
            while(k--)l+=p.second;
        }
        string ans=s;
        int u=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                ans[i]=l[u++];
            }
            else{
                ans[i]=s[i];
            }
        }
        return ans;
    }
};