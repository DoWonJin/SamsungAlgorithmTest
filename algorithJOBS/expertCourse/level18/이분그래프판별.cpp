문제
이분 그래프란, 아래 그림과 같이 정점을 크게 두 집합으로 나눌 수 있는 그래프를 말한다. 여기서 같은 집합에 속한 정점끼리는 간선이 존재해서는 안된다. 예를 들어, 아래 그래프의 경우 정점을 크게 {1, 4, 5}, {2, 3, 6} 의 두 개의 집합으로 나누게 되면, 같은 집합에 속한 정점 사이에는 간선이 존재하지 않으므로 이분 그래프라고 할 수 있다.

ec-14 그래프가 입력으로 주어질 때, 이 그래프가 이분그래프인지를 판별하는 프로그램을 작성하시오.

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. (1 ≤ a, b ≤ N)

 

출력
주어진 그래프가 이분 그래프이면 Yes, 아니면 No를 출력한다.

 

예제 입력
6 5
1 2
2 4
3 4
3 5
4 6



예제 출력
Yes


 

예제 입력
4 5
1 2
1 3
1 4
2 4
3 4




예제 출력
No

#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
const int MAX = 1001;

int n, m;
vector <int> myGraph[MAX];
bool judge = true;
int arr[MAX]; // 0으로 셋팅  1or2팀으로 구별
queue <int> Queue[MAX];
void BFS() {
	arr[1] = 1;
	Queue->push(1);
	while (!Queue->empty()) {

		int curr = Queue->front();
		Queue->pop();
		for (int i = 0;i < myGraph[curr].size();i++) {
			int next = myGraph[curr][i];
			if (arr[next] == 0)//방문하지 않는 노드
			{
				if (arr[curr] == 1)
					arr[next] = 2;
				else if (arr[curr] == 2)
					arr[next] = 1;
				Queue->push(next);
			}
			else {//방문했던 이웃한 노드들 중
				if (arr[curr] == arr[next]) { // 같은 그룹일 경우
					judge = false;
					return;
				}
			}
		}


	}


}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}
	BFS();
	judge ? printf("Yes") : printf("No");


	return 0;
}

