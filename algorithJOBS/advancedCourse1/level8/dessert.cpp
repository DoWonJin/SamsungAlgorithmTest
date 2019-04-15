dessert
이전다음
문제
농부 존은 소들의 저녁식사 줄 세우는 새로운 방법을 개발 했다. N(1~15)마리의 소들을 순서대로 세 워놓은 후, 각 소들 사이에 +, - , . 셋 중 1가지가 써져있는 냅킨을 배치해서 최종 결과가 0 이 되게 해야 하는 것이다. 점(.)이 써져있는 냅킨을 통해 더 큰 수를 만들 수 있게 된다. 아래와 같은 경우를 보자. (ps .이 써져있는 냅킨은 '공백'이라고 생각하면 된다.) 1-2.3-4.5+6.7 이와 같은 배치는 1-23-45+67 을 나타낸다. 결과는 0 이다. 10.11은 1011 로 해석된다.

 

입력
첫 째 줄에는 소들의 수 N(1 ≤ N ≤ 15)이 입력된다.

 

출력
처음 20줄에 대해 가능한 20가지 답을 출력하는데, 사전 순으로 앞선 것을 출력한다. 순서는 +가 가장 앞서고 -와 . 이 순서대로 뒤따른다. 답이 20개 미만이면 가능한 답을 각 숫자와 문자 사이에 공백을 두고 출력한다. 모두 출력한다. 마지막 줄에는 가능한 답의 총 가지수를 출력한다.

 

예제 입력
7
예제 출력
1 + 2 - 3 + 4 - 5 - 6 + 7
1 + 2 - 3 - 4 + 5 + 6 - 7
1 - 2 + 3 + 4 - 5 + 6 - 7
1 - 2 - 3 - 4 - 5 + 6 + 7 
1 - 2 . 3 + 4 + 5 + 6 + 7 
1 - 2 . 3 - 4 . 5 + 6 . 7
6
 

출처
USACO 2002, poj 1950  


#include <stdio.h>
#include <math.h>

int arr[15];
int num[15];
int numSize;
char op[14];
char opTmp[14];
int opSize;
int n;
int total;
bool state = false;
int checkFuc() {

	int res = num[0];
	for (int i = 0;i < numSize - 1;i++)
	{
		switch (opTmp[i]) {
		case '+':
			res += num[i + 1];
			break;
		case '-':
			res -= num[i + 1];
			break;
		}
	}
	return res;
}

void reformNum() {
	numSize = 0;
	num[numSize++] = arr[0];
	int mul;
	for (int i = 0;i < n - 1;i++) {
		switch (op[i]) {
		case '.':
			if (arr[i + 1] >= 10)mul = 100;
			else mul = 10;
			num[numSize - 1] = num[numSize - 1] * mul + arr[i + 1];
			break;
		case '+':
			opTmp[numSize - 1] = '+';
			num[numSize] = arr[i + 1];
			numSize++;
			opSize++;
			break;
		case '-':
			opTmp[numSize - 1] = '-';
			num[numSize] = arr[i + 1];
			numSize++;
			opSize++;
			break;
		}
	}
}

/*
	arr   1  2  3  4
	op    +  -  +
*/
void func(int step, char oper) {
	if (step == 1)arr[0] = step;
	if (step >= 2) {
		arr[step - 1] = step;
		op[step - 2] = oper;
	}
	if (step == n) {

		reformNum();
		int res = checkFuc();
		if (res == 0 ) {
			if (total <= 19) {
				for (int i = 0;i < n - 1;i++) {
					printf("%d ", arr[i]);
					printf("%c ", op[i]);
				}
				printf("%d", arr[n - 1]);
				printf("\n");
				
			}
			total++;
		}
		return;
	}

	func(step + 1, '+');
	func(step + 1, '-');
	func(step + 1, '.');
}

int main(void) {

	scanf("%d", &n);
	func(1, 1);
	printf("%d\n", total);

	return 0;
}
