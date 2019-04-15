공통조상찾기
이전다음
문제
트리의 노드 X에 대하여 “조상"을 정의할 수 있다. X의 “조상"이란, 루트까지 올라가는 중에 만나는 모든 노드를 말한다. 예를 들어, 아래와 같이 트리가 주어질 경우, 노드 8의 “조상"은 노드 0, 노드 2, 노드 6이 된다.

alt text

두 노드 X, Y의 공통 조상이란, X와 Y가 공통으로 갖는 조상을 말한다. 예를 들어, 노드 7과 노드 10의 공통조상은 노드 2, 노드 0이 된다. 가장 가까운 공통 조상이란, X와 Y가 공통으로 갖는 조상들 중에서 X, Y와 가장 가까운 조상을 말한다. 예를 들어, 노드 7과 노드 10의 가장 가까운 공통 조상은 노드 2가 된다. 트리가 주어지고, 두 노드 X, Y가 주어질 때, 가장 가까운 공통 조상을 찾는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 트리의 노드 개수 n, 두 노드 X, Y의 번호가 주어진다. ( 1 ≤ X, Y ≤ n ≤ 1000 ) 두 번째 줄부터 트리의 간선 정보가 주어진다. 각 줄은 2개의 숫자 a, b로 이루어지며, 이는 노드 a가 노드 b의 부모노드라는 것을 의미한다. 루트는 노드 0이라고 가정한다.  

출력
두 노드 X, Y의 공통 조상을 출력한다.

 

예제 입력
11 7 10
0 1
0 2
1 3
1 4
1 5
2 6
2 10
6 7
6 8
6 9
예제 출력
2

#include <stdio.h>
const int MAX = 1000;
struct Tree {
	int parent;
	int left = -1;
	int mid = -1;
	int right = -1;
};

Tree tree[MAX];

void preOrder(int x) {
	if (tree[x].left == -1 && tree[x].right == -1)
	{
		printf("%d ", x);
	}
	else {
		printf("%d ", x);
		if (tree[x].left != -1)
			preOrder(tree[x].left);
		if (tree[x].mid != -1)
			preOrder(tree[x].mid);
		if (tree[x].right != -1)
			preOrder(tree[x].right);
	}
}


int main() {
	int n, start, end;
	scanf("%d %d %d", &n,&start,&end);
	int arr1[MAX], arr2[MAX];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		tree[b].parent = a;

		if (tree[a].left == -1)
			tree[a].left = b;
		else if (tree[a].mid == -1)
			tree[a].mid = b;
		else
			tree[a].right = b;
		
	}
	//preOrder(0);
	int i = 0;
	while (start != 0) {
		arr1[i] = tree[start].parent;
		start = arr1[i];
		i++;
	}
	int j = 0;
	while (end != 0) {
		arr2[j] = tree[end].parent;
		end = arr2[j];
		j++;
	}
	int comon[MAX];
	int count = 0;
	for (int k = 0;k < i;k++)
	{
		int flag = false;
		for (int g = 0;g < j;g++)
			if (arr1[k] == arr2[g])
			{
				printf("%d\n", arr1[k]);
				flag = true;
				break;
			}
		if (flag == true)break;
	}

	return 0;
}
