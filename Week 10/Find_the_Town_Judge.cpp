//https://leetcode.com/problems/find-the-town-judge/description/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if( n == 1 ){
            return n;
        }

        vector<int> indegree(n,0);
        vector<int> outdegree(n,0);

        for(size_t i = 0 ; i < trust.size() ; i++){
            outdegree[trust[i][0] - 1] ++;
            indegree[trust[i][1] - 1 ] ++;
        }

        for(size_t i = 0; i < n; i++){
            if(outdegree[i] == 0 && indegree[i] == n-1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};


//Faster
  int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < n - 1) {
            return -1;
        }
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        for(auto& relation: trust) {
            outdegree[relation[0]]++;
            indegree[relation[1]]++;
        }
        
        for(size_t i = 1; i <= n; i++) {
            if(indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
