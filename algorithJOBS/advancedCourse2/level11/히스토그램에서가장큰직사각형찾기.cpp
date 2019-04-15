아래코드는 100점짜리 코드는 아님...... ㅠㅠ

히스토그램에서가장큰직사각형찾기
이전다음
문제
히스토그램이란, 아래 그림과 같이 직사각형이 배열되어 있는 것을 말한다. 각 직사각형의 가로 길이는 1로 모두 같고, 세로 길이는 다를 수 있다. 예를 들어, 아래 그림은 높이가 2, 1, 4, 5, 1, 3, 3 인 직사각형으로 이루어진 히스토그램이다.

alt text

히스토그램이 주어질 때, 가장 큰 직사각형의 너비를 출력하는 프로그램을 작성하시오. 위의 예제에서는 최대 직사각형의 너비가 그림과 같이 8이다.

 

입력
첫째 줄에 히스토그램을 이루는 직사각형의 개수 N이 주어진다. ( 1 ≤ N ≤ 100,000 ) 둘째 줄에는 각 직사각형의 높이가 주어진다. 높이는 10,000보다 작은 양의 정수이다.  

출력
최대 직사각형의 너비를 출력한다.

 

예제 입력
7
2 1 4 5 1 3 3
예제 출력
8
 

출처
University of Ulm local contest 2003 H  



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
const int max = 200000;
struct Stack {
	int data[max];
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
	s.create(max);
	int n;
	int arry[max] = { 0 };
	int i = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arry + i);

	int max = 0;
	while (1) {
		//	s.print();
		if (s.top() == -1)
			s.push(i++);
		else if (arry[s.top()] <= arry[i])
			s.push(i++);
		else if (arry[s.top()] > arry[i] || i == n) {
			int behind = s.top();
			int exceptNum = 0;
			int area;
			int flag = false;
			while (arry[s.top()] > arry[i]) {
				area = (behind - s.top() + 1)*arry[s.top()];
				//			printf("높이 : %d 너비 : %d\n", arry[s.top()], behind - s.top() + 1);
				if (area > max) {
					max = area;
					//printf("우로 계산한 방식,갱신된 max값: %d\n", max);
				}
				s.pop();
				if (s.size() == 0) {
					flag = true;
					area = (i + 1)*arry[i];
					break;
				}
				exceptNum++;
			}
			if (flag == false)
				area = (exceptNum + 1)*arry[i];
			if (area > max) {
				max = area;
				//		printf("좌로 계산한 방식,갱신된 max값: %d\n", max);
			}
			if (i == n)break;
		}

	}
	int minH = 98765654;
	for (int i = 0;i < n;i++)
		if (arry[i] < minH) minH = arry[i];
	if (max < minH*n)max = minH * n;
	printf("%d\n", max);


	return 0;
}
