#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 生成特定的矩阵 
vector<vector<int>> generate_adjacency_matrix(vector<int> points, vector<pair<int, int>> edges) {
    int n = points.size();
    vector<vector<int>> graph_data(n, vector<int>(n, 0));
    for (auto edge : edges) {
        int i = edge.first;
        int j = edge.second;
        graph_data[i][j] = 1;
    }
    return graph_data;
}

// 寻找最短的路径 
int bfs_shortest_path(vector<vector<int>>& adjacency_matrix, int source_node, int target_node) {
    int n = adjacency_matrix.size();
    vector<int> distance(n, -1);
    queue<int> q;

    distance[source_node] = 0;
    q.push(source_node);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        if (current_node == target_node) {
            return distance[current_node];
        }

        for (int i = 0; i < n; ++i) {
            if (adjacency_matrix[current_node][i] == 1 && distance[i] == -1) {
                distance[i] = distance[current_node] + 1;
                q.push(i);
            }
        }
    }

    return -1;  // 如果找不到，就返回-1
}

// 
int main() {
    int N,M,s,t;
    cin>>N>>M>>s>>t; 
    vector<int> points;
    for(int i=0;i<=N;i++){
		points.push_back(i);
	
	}
	cout<<points.size()<<endl;
	vector<pair<int, int>> edges;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		pair<int,int> p={a,b}; 
		edges.push_back(p);	
	}
	
    int source_node = s;
    int target_node = t;

    vector<vector<int>> adjacency_matrix = generate_adjacency_matrix(points, edges);
    int shortest_path_length = bfs_shortest_path(adjacency_matrix, source_node, target_node);

    if (shortest_path_length != -1) {
        cout << shortest_path_length << endl;
    }
    else {
        cout << "No Path" << endl;
    }

    return 0;
}
