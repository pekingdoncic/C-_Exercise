#include <vector>
#include<iostream>
using namespace std;
int DFSVisited(vector<vector<bool>> lake, vector<vector<bool>> visited, int i, int j, int answer)
{
	//��ֹ��ַԽ�� 
	if ((i < 1) || (i > lake.size()) || (j < 1) || (j > lake[0].size())) {
		return answer;
	}
	if (visited[i][j] == false) {
		//�����Ƿ���δ���ʵ�ˮ�أ�
		visited[i][j] = true;
		if (lake[i][j] == true)
			answer++;
	}
	int temp;
	//�ݹ���ң� 
	
		DFSVisited(lake, visited, i--, j, answer);

		DFSVisited(lake, visited, i++, j, answer);

		DFSVisited(lake, visited, i, j--, answer);

		DFSVisited(lake, visited, i, j++, answer);

	
	return answer;
}
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<bool>> lake(N + 1, vector<bool>(M + 1, false));
	for (int i = 0; i < K; i++) {
		int R, C;
		cin >> R >> C;
		lake[R][C] = true;
	}
	//�Ƿ���ʹ���
	vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
	int answer = 0;
	int i = 1, j = 1;
	answer = DFSVisited(lake, visited, i, j, answer);
	cout << answer << endl;
	return 0;
}
