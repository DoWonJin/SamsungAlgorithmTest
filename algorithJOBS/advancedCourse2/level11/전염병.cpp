전염병
이전다음
문제
철수네 마을에는 갑자기 전염병이 유행하기 시작하였다. 이 전염병은 전염이 매우 강해서, 이웃한 마을끼리는 전염되는 것을 피할 수 없다.
철수네 마을은 1번부터 N번까지 번호가 매겨져 있다. 철수네 마을의 구조는 꽤나 복잡한데, i번 마을에서 출발하면 i * 2 번 마을에 갈 수 있고, 또한 i / 3(i를 3으로 나눈 몫) 번째 마을에도 갈 수 있다. 전염병은 사람에 의하여 옮는 것으로 알려져 있다. 따라서 i번 마을에 전염병이 돌게 되면, i * 2 번 마을과 i / 3(i를 3으로 나눈 몫) 번 마을 역시 전염병이 돌게 된다.
K번 마을이 가장 처음으로 전염병이 돌기 시작했을 때, 전염병이 돌지 않는 마을의 개수를 구하는 프로그램을 작성하시오.

 

입력
첫째 줄에 전체 마을의 개수 N과, 처음으로 전염병이 돌기 시작한 마을 번호 K가 주어진다. ( 1 ≤ N, K ≤ 100,000 )  

출력
전염병이 돌지 않는 마을의 개수를 출력한다.

 

예제 입력
10 3
예제 출력
4


#include <stdio.h>

struct Queue {
	int data[100000] = { 0 };
	int num = 0;
	int f, r;
	int capacity;
	void create(int s) {
		capacity = s;
		f = 0;
		r = 0;
	}

	void push(int y) {
		if (num == capacity)
			printf("overflow\n");
		else {
			data[r++] = y;
			r = r % capacity;
			num++;
		}
	}
	int pop() {
		if (num == 0)
			printf("underflow\n");
		else
		{
			int res = data[f++];
			data[f - 1] = 0;
			f = f % capacity;
			num--;
			return res;
		}
	}
	int front() {
		if (num <= 0)
		{
			return -1;
		}
		else {
			return data[f];
		}
	}
	int size() {
		return num;
	}
	void print() {
		for (int i = 0; i <= capacity; i++)
			printf("%d ", data[i]);
		printf("\n");
	}
};

int main() {
	Queue q;
	int n, lo;
	int arr[100000] = { 0 };
	scanf("%d %d", &n, &lo);
	q.create(n);
	q.push(lo);
	arr[lo] = 1;
	while (1) {
		if (q.front() == -1)break;
		//q.print();
		int tmp = q.pop();
		if (tmp / 3 >= 1 && arr[tmp / 3] == 0) {
			q.push(tmp / 3);
			arr[tmp / 3] = 1;
		}
		if (tmp * 2 <= n && arr[tmp*2] == 0) {
			q.push(tmp * 2);
			arr[tmp * 2] = 1;
		}
		
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		//printf("%d ", arr[i]);
		if (arr[i] == 1)count++;
	}
	
	printf("%d\n", n-count);



	return 0;
}
