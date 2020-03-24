/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        queue<int>q;\
        int ans=0;
        for(auto it : employees){
            mp[it->id]=it;
            if(it->id==id){
                q.push(it->id);
            }
        }
        while(!q.empty()){
            Employee* e=mp[q.front()];
            q.pop();
            ans+=e->importance;
            for(auto it: e->subordinates){
                q.push(it);
            }
        }
        return ans;
    }
};