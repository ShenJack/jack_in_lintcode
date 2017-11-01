#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/*
 * 如下图:

A----->B----->C
 \     |
  \    |
   \   |
    \  v
     ->D----->E
for s = B and t = E, return true

for s = D and t = C, return false*/
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;

    DirectedGraphNode(int x) : label(x) {};
};


/*
     * @param graph: A list of Directed graph node
     *
     * @param s: the starting Directed graph node
     *
     * @param t: the terminal Directed graph node
     *
     * @return: a boolean value
     *
     */
bool hasRoute(vector<DirectedGraphNode *> graph, DirectedGraphNode *starting, DirectedGraphNode *terminal) {
    // write your code here
    queue<DirectedGraphNode*> q;
    map<DirectedGraphNode*,bool> visited;
    q.push(starting);
    visited[starting]=true;
    while(!q.empty())
    {
        DirectedGraphNode* cur = q.front();
        q.pop();
        /*到达终点*/
        if(cur==terminal){
            return true;
        }

        /*for each*//*遍历neighbors 未访问的进入待访问队列 在 之后进行访问 并且记录当前的已经访问*/
        for(auto neighbour:cur->neighbors)
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=true;
            }
        }
    }
    return false;
}

int main() {

    return 0;
}
