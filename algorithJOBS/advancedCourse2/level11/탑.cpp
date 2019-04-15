탑
이전다음
문제
KOI 통신연구소는 레이저를 이용한 새로운 비밀 통신 시스템 개발을 위한 실험을 하고 있다. 실험을 위하여 일직선 위에 N개의 높이가 서로 다른 탑을 수평 직선의 왼쪽부터 오른쪽 방향으로 차례로 세우고, 각 탑의 꼭대기에 레이저 송신기를 설치하였다. 모든 탑의 레이저 송신기는 레이저 신호를 지표면과 평행하게 수평 직선의 왼쪽 방향으로 발사하고, 탑의 기둥 모두에는 레이저 신호를 수신하는 장치가 설치되어 있다. 하나의 탑에서 발사된 레이저 신호는 가장 먼저 만나는 단 하나의 탑에서만 수신이 가능하다. 예를 들어 높이가 6, 9, 5, 7, 4인 다섯 개의 탑이 수평 직선에 일렬로 서 있고, 모든 탑에서는 주어진 탑 순서의 반대 방향(왼쪽 방향)으로 동시에 레이저 신호를 발사한다고 하자. 그러면, 높이가 4인 다섯 번째 탑에서 발사한 레이저 신호는 높이가 7인 네 번째 탑이 수신을 하고, 높이가 7인 네 번째 탑의 신호는 높이가 9인 두 번째 탑이, 높이가 5인 세 번째 탑의 신호도 높이가 9인 두 번째 탑이 수신을 한다. 높이가 9인 두 번째 탑과 높이가 6인 첫 번째 탑이 보낸 레이저 신호는 어떤 탑에서도 수신을 하지 못한다. 탑들의 개수 N과 탑들의 높이가 주어질 때, 각 각의 탑에서 발사한 레이저 신호를 어느 탑에서 수신하는지를 알아내는 프로그램을 작성하라.  

입력
첫째 줄에 탑의 수를 나타내는 정수 N이 주어진다. N은 1 이상 500,000 이하이다. 둘째 줄에는 N개의 탑들의 높이가 직선상에 놓인 순서대로 하나의 빈칸을 사이에 두고 주어진다. 탑들의 높이는 1 이상 100,000,000 이하의 정수이다.  

출력
첫째 줄에 주어진 탑들의 순서대로 각각의 탑들에서 발사한 레이저 신호를 수신한 탑들의 번호를 하나의 빈칸을 사이에 두고 출력한다. 만약 레이저 신호를 수신하는 탑이 존재하지 않으면 0을 출력한다.

 

예제 입력
5
6 9 5 7 4
예제 출력
0 0 2 2 4
 

출처
2009 한국정보올림피아드 지역본선 고등부 2번

#include <stdio.h>
#include <string.h>
/*
문제
접시가 a, b, c, d 가 있고, 알파벳 순으로 한쪽이 막혀 있는 세척기에 들어간다고 할 때, b a c d 순으로 꺼내기 위해서는 push, push, pop, pop, push, pop, push, pop을 하면 된다. 세척기에서 꺼내는 순서가 주어질 때 그 동작을 출력하는 프로그램을 작성하시오. 만약 주어진 순서대로 접시를 꺼낼 수 없다면 “impossible”을 출력한다.

입력
첫째 줄에 소문자 알파벳이 주어진다. 중복된 소문자 알파벳은 입력되지 않는다. 알파벳 소문자는 26개이다.

출력
접시를 꺼내는 것이 가능한 경우 push, pop의 순서를 출력한다. 이것이 불가능하다면 impossible을 출력한다.

예제 입력
bacd
예제 출력
push
push
pop
pop
push
pop
push
pop

예제 입력
dabc
예제 출력
impossible

*/
struct Stack {
	int data[100];
	int len = 0;
	int capacity;

	void create(int y) {
		capacity = y;
	}
	int push(int y) {
		if (len >= capacity) {
			printf("overflow\n");
			return -1;
		}
		else {
			data[len++] = y;
			return y;
		}
	}
	int pop() {
		if (len <= 0) {
			printf("underflow\n");
			return -1;
		}
		else {
			int res = data[len - 1];
			len--;
			return res;
		}
	}
	int top() {
		if (len <= 0)
			return -1;
		else
			return data[len - 1];
	}
	int nexttop() {
		if (len <= 1)
			return -1;
		else
			return data[len - 2];
	}
	int size() {
		return len;
	}
	void print() {
		printf("스택정보: ");
		for (int i = 0; i < len; i++)
			printf("%d ", 1 + data[i]);
		printf("\n");
	}

};

int main()
{
	Stack s;
	s.create(50);
	int n;
	int arry[100000] = { 0 };
	int ans[100000];
	int i = 0;
	int j = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arry + i);
	while (true) {
		s.print();
		
		if(i==n)

		if (s.top() == -1) {
			s.push(arry[i++]);
			if (i == 1) {
				s.pop();
				ans[0] = 0;
				printf("0 ");
			}
		}
		else if (s.top() > arry[i]) {
			s.push(arry[i++]);
		}
		else if (s.top() < arry[i]) {
			ans[s.top()] = s.nexttop()+1;
			s.pop();
		}
		


	}



	return 0;
}
