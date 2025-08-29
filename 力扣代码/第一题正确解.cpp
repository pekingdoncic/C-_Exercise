#include <bits/stdc++.h>
using namespace std;
#define MAXVALUE 1000
int main()
{
	int N,M,s,t;
	cin>>N>>M>>s>>t;
	//存储图，利用二维数组，即是邻接表
	vector<vector<int>> graph(N+1);
	//添加边：二维数组中，存储的是哪两个顶点之间有边！ 
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	 //BFS寻找距离！
	 vector<int> distance(N+1,MAXVALUE);//从起点s到每一个定点的距离存储！
	 distance[s]=0;//自己到自己的距离为0；
	 //定义队列进行BFS路径查找
	 queue<int> q;
	q.push(s);//将首节点入队
	while(!q.empty()){
		int current=q.front();//获取队列头结点，开始寻找
		q.pop();
		for(auto neiber:graph[current]){
//			cout<<"1"<<endl;
//			cout<<"current: "<<current<<endl;
//			cout<<"distance[current]: "<<distance[current]<<" MAXVALUE: "<<MAXVALUE<<endl;
			//写错了逻辑！这里应该是检测neiber的value，而不是current的value！ 
		//	if(distance[current]==MAXVALUE){
			if(distance[neiber]==MAXVALUE){
				distance[neiber]=distance[current]+1;
				cout<<"current: "<<current<<" neiber: "<<neiber<<endl;
				q.push(neiber);
		} 
		}
	} 
	for(auto i:distance ){
		cout<<i<<" ";
	}
	cout<<endl;
	if(distance[t]==MAXVALUE){
		cout<<"No Path!"<<endl;
	}
	else
	{
		cout<<distance[t]<<endl;
	}
	return 0;

}
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <limits.h>
//
//using namespace std;
//
//int main() {
//    int N, M, s, t;
//    cin >> N >> M >> s >> t;
//
//    vector<vector<int>> graph(N + 1); // 使用邻接表表示图，大小为 N + 1
//
//    for (int i = 0; i < M; ++i) {
//        int u, v;
//        cin >> u >> v;
//        graph[u].push_back(v);
//        graph[v].push_back(u); // 添加反向边以表示无向图
//    }
//
//    vector<int> distance(N + 1, INT_MAX); // 距离数组，初始化为无穷大
//    queue<int> q;
//
//    distance[s] = 0;
//    q.push(s);
//
//    while (!q.empty()) {
//        int current = q.front();
//        q.pop();
//
//        for (int neighbor : graph[current]) {
//            if (distance[neighbor] == INT_MAX) { // 如果邻节点未访问
//                distance[neighbor] = distance[current] + 1;
//                q.push(neighbor);
//            }
//        }
//    }
//
//    if (distance[t] == INT_MAX) {
//        cout << "No path" << endl;
//    } else {
//        cout << distance[t] << endl;
//    }
//
//    return 0;
//}
