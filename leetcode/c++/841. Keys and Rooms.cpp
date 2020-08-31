/* dfs
时间复杂度：O(n+m)，其中 n 是房间的数量，m 是所有房间中的钥匙数量的总数。

空间复杂度：O(n)，其中 n 是房间的数量。主要为栈空间的开销。
 */

class Solution {
public:
    vector<int> vis;
    int num;

    void dfs(vector<vector<int>>& rooms, int x) {
        vis[x] = true;
        num++;
        for (auto& it : rooms[x]) {
            if (!vis[it]) {
                dfs(rooms, it);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        num = 0;
        vis.resize(n);
        dfs(rooms, 0);
        return num == n;
    }
};
/* bfs
时间复杂度：O(n+m)，其中 n 是房间的数量，m 是所有房间中的钥匙数量的总数。
空间复杂度：O(n)，其中 n 是房间的数量。主要为队列的开销。 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), num = 0;
        vector<int> vis(n);
        queue<int> que;
        vis[0] = true;
        que.emplace(0);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            num++;
            for (auto& it : rooms[x]) {
                if (!vis[it]) {
                    vis[it] = true;
                    que.emplace(it);
                }
            }
        }
        return num == n;
    }
};
