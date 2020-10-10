/**
 * BFS: breadth first search.
 *
 * 广度优先算法．
 * 一般用于在一幅图中找到从起点到终点的最短距离．
 * Find the minimum distance from the starting point to a target in a graph.
 */

int BFS(Node start, Node target)
{
    queue<Node> q;
    set<Node> visited; // avoid repeat visiting visited nodes.

    q.push(start);
    visited.insert(start);
    int steps = 0; // record the number of searching steps.

    while (!q.empty()) {
        int sz = q.size(); // the size of current queue.

        for (size_t i = 0; i < sz; ++i) {
            // get the front element and remove it from queue.
            Node cur = q.poll();

            // check if `cur` is the target we want.
            if (cur == target)
                return steps;

            // Now, we still need to searching based on all adjacent elements of
            // `cur`.
            // `cur.adj()` returns all its neighbors.
            for (Node x : cur.adj()) {
                if (x not in visited) {
                    // push new element in queue and mark it visited.
                    q.push(x);
                    visited.insert(x);
                }
            }
        }
    }

    // at this point, we traversed all the tree without solution.
    return -1; // failure.
}