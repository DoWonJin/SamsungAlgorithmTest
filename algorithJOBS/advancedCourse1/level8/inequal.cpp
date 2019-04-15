inequal
이전다음
문제
두 종류의 부등호 기호 ‘<’와 ‘>’가 k 개 나열된 순서열 A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자.

A ⇒ < < < > < < > < >

부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

여러분은 제시된 k 개의 부등호 순서를 만족하는 (k+1) 자리의 정수 중에서 최대값과 최소값을 찾아야 한다. 앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } 중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다. 프로그램의 실행시간은 0.5초를 넘을 수 없다.

 

입력
첫 줄에 부등호 문자의 개수를 나타내는 정수 가 주어진다. 그 다음 줄에는 k 개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k 의 범위는 2 <= k <= 9이다.

 

출력
여러분은 제시된 부등호 관계를 만족하는 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다.

 

예제 입력
2
< >
예제 출력
897
021
 

예제 입력
9
> < < < > > > < <
예제 출력
9567843012
1023765489
 

출처
KOI 지역본선 2012 초등부 5번  


#include <stdio.h>


char ineqaul[10];
int numList[10];
int number;
bool state;
int overlapNum(int prevNum, int nextNum, int step) {
	for (int i = 0;i < step - 1;i++)
		if (numList[i] == nextNum)return 1;
	
	switch (ineqaul[step-2]) {
	case '<':
		if (prevNum < nextNum)return 0;
		else return -1;
	default:
		if (prevNum > nextNum)return 0;
		else return -1;
	}
	
	
	return 0;
}

void Func1(int step,int prevNum, int currNum) {
	if (state == true) {
		return;
	}
	if (step > 0) {
		numList[step - 1] = currNum;
		if (step >= 2) {
			int check = overlapNum(prevNum, currNum, step);
			if (check == 1) {
				/*printf("숫자중복됨\n");
				for (int i = 0;i < step;i++)
					printf("%d", numList[i]);
				printf("\n");*/
				return;
			}
			else if (check == -1) {
				/*printf("부등호 부적절\n");
				for (int i = 0;i < step;i++)
					printf("%d", numList[i]);
				printf("\n");*/
				return;
			}
			else {
				/*printf("정상진행\n");
				for (int i = 0;i < step;i++)
					printf("%d", numList[i]);
				printf("\n");*/
			}
		}
	}
	if (step == number+1) {
		for (int i = 0;i < step;i++)
			printf("%d", numList[i]);
		printf("\n");
		state = true;
	}

	for (int i = 9;i >= 0;i--)
		Func1(step + 1, currNum, i);
}
void Func2(int step, int prevNum, int currNum) {
	if (state == true) {
		return;
	}
	if (step > 0) {
		numList[step - 1] = currNum;
		if (step >= 2) {
			int check = overlapNum(prevNum, currNum, step);
			if (check == 1) {
				/*printf("숫자중복됨\n");
				for (int i = 0;i < step;i++)
					printf("%d", numList[i]);
				printf("\n");*/
				return;
			}
			else if (check == -1) {
				/*printf("부등호 부적절\n");
				for (int i = 0;i < step;i++)
					printf("%d", numList[i]);
				printf("\n");*/
				return;
			}
			else {
				/*printf("정상진행\n");
				for (int i = 0;i < step;i++)
					printf("%d", numList[i]);
				printf("\n");*/
			}
		}
	}
	if (step == number + 1) {
		for (int i = 0;i < step;i++)
			printf("%d", numList[i]);
		printf("\n");
		state = true;
	}

	for (int i = 0;i <= 9;i++)
		Func2(step + 1, currNum, i);
}

int main(void) {
	scanf("%d", &number);
	getchar();
	for (int i = 0;i < number;i++)
	{
		scanf("%c", ineqaul + i);
		getchar();
	}
	
	state = false;
	Func1(0, 0, 0);
	state = false;
	for (int i = 0;i < 10;i++)
		numList[i] = -1;
	Func2(0, 0, 0);
	return 0;
}
