combinationzero
이전다음
문제
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.

nCm은 수식으로 n!/m!(n-m)! 으로 구할 수 있다. (5! = 1 * 2 * 3 * 4 * 5)

n과 m이 주어졌을때 nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에 정수 n, m(0≤m≤n≤1,000,000)이 들어온다.

 

출력
첫째 줄에 0의 개수를 출력한다.

 

예제 입력
25 12
예제 출력
2

#include <stdio.h>

/*
문제
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.

nCm은 수식으로 n!/m!(n-m)! 으로 구할 수 있다. (5! = 12345)

n과 m이 주어졌을때 nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤1,000,000)이 들어온다.



출력
첫째 줄에 0의 개수를 출력한다.

예제 입력
25 12
예제 출력
2
*/
int arr[2];

void countFunc1(int num, int r) {
	for (int n = r + 1; n <= num; n++) {
		int target = n;
		while(1){
			if (target % 2 == 0) {
				arr[0]++;
				target /= 2;
			}
			else if (target % 5 == 0) {
				arr[1]++;
				target /= 5;
			}
			else break;
		}
	}
}
void countFunc2(int num) {
	for (int n = 1; n <= num; n++) {
		int target = n;
		while(1){
			if (target % 2 == 0) {
				arr[0]--;
				target /= 2;
			}
			else if (target % 5 == 0) {
				arr[1]--;
				target /= 5;
			}
			else break;
		}
	}
}


int main(void) {
	int n, m;
	int res;

	scanf("%d %d", &n, &m);
	countFunc1(n, m);
	countFunc2(n - m);
	int a, b, r;
	int GCN;
	a = arr[0];
	b = arr[1];
	if (a >= b)printf("%d\n", b);
	else printf("%d\n", a);

	return 0;
}
