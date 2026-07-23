class Solution {
public:
    int count=0;  
    int minReorder(int n, vector<vector<int>>& connection) {
        vector<vector<int>> graph(n);
        vector<int> parent(n,-1);
        unordered_map<int,map<int,int>> m;
        for(int i=0;i<connection.size();i++){
            graph[connection[i][0]].push_back(connection[i][1]);
            graph[connection[i][1]].push_back(connection[i][0]);
            m[connection[i][0]][connection[i][1]]=1;
        }
        queue<int> q;
        vector<int> visited(n,0);
        q.push(0);
        visited[0]=1;
        while(q.size()){
            int k = q.size();
            while(k--){
                int t = q.front();
                q.pop();
                for(int i=0;i<graph[t].size();i++){
                    int h = graph[t][i];
                    if(visited[h]==0&&m[h][t]!=1){
                        count++;
                        std::cout<<h<<"->"<<t<<endl;
                    }
                    if(visited[h]==0)q.push(h);
                }
                visited[t]=1;
            }
        }
        return count;

    }
};