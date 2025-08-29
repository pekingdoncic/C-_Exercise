#include <bits/stdc++.h>
using namespace std;
#define MAXVALUE 1000
int main()
{
	int N,M,s,t;
	cin>>N>>M>>s>>t;
	//�洢ͼ�����ö�ά���飬�����ڽӱ�
	vector<vector<int>> graph(N+1);
	//��ӱߣ���ά�����У��洢��������������֮���бߣ� 
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	 //BFSѰ�Ҿ��룡
	 vector<int> distance(N+1,MAXVALUE);//�����s��ÿһ������ľ���洢��
	 distance[s]=0;//�Լ����Լ��ľ���Ϊ0��
	 //������н���BFS·������
	 queue<int> q;
	q.push(s);//���׽ڵ����
	while(!q.empty()){
		int current=q.front();//��ȡ����ͷ��㣬��ʼѰ��
		q.pop();
		for(auto neiber:graph[current]){
//			cout<<"1"<<endl;
//			cout<<"current: "<<current<<endl;
//			cout<<"distance[current]: "<<distance[current]<<" MAXVALUE: "<<MAXVALUE<<endl;
			//д�����߼�������Ӧ���Ǽ��neiber��value��������current��value�� 
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
//    vector<vector<int>> graph(N + 1); // ʹ���ڽӱ��ʾͼ����СΪ N + 1
//
//    for (int i = 0; i < M; ++i) {
//        int u, v;
//        cin >> u >> v;
//        graph[u].push_back(v);
//        graph[v].push_back(u); // ��ӷ�����Ա�ʾ����ͼ
//    }
//
//    vector<int> distance(N + 1, INT_MAX); // �������飬��ʼ��Ϊ�����
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
//            if (distance[neighbor] == INT_MAX) { // ����ڽڵ�δ����
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
