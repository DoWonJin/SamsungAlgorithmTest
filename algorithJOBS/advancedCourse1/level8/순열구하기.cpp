순열구하기
이전다음
문제
서로 다른 n개의 원소들 중에서 r개만을 뽑아 일렬로 나열하는 것을 순열이라 한다. 예를 들어, 3개의 원소 a, b, c 중에서 2개만을 뽑아 나열하면 ab, ac, ba, bc, ca, cb 의 6가지 경우가 있다. n과 r이 주어질 때, n개의 소문자 중에서 r개만을 뽑아 나열하는 모든 경우를 출력하는 프로그램을 작성하시오. 단, a부터 시작하여 연속으로 n개의 알파벳을 갖고 있다고 하자.  

입력
첫 번째 줄에 n과 r이 주어진다. ( 1 ≤ n ≤ 10, 0 ≤ r ≤ min(n, 7) )  

출력
각 줄에 n개의 소문자 중에서 r개만을 뽑아 나열하는 경우를 사전순으로 나열한 결과를 출력한다.

 

예제 입력
4 2
예제 출력
ab
ac
ad
ba
bc
bd
ca
cb
cd
da
db
dc

#include<stdio.h>
#include<string.h>
/*
문제
서로 다른 n개의 원소들 중에서 r개만을 뽑아 일렬로 나열하는 것을 순열이라 한다.

예를 들어, 3개의 원소 a, b, c 중에서 2개만을 뽑아 나열하면 ab, ac, ba, bc, ca, cb 의 6가지 경우가 있다. 

n과 r이 주어질 때, n개의 소문자 중에서 r개만을 뽑아 나열하는 모든 경우를 출력하는 프로그램을 작성하시오.

단, a부터 시작하여 연속으로 n개의 알파벳을 갖고 있다고 하자.

입력
첫 번째 줄에 n과 r이 주어진다. ( 1 ≤ n ≤ 10, 0 ≤ r ≤ min(n, 7) )

출력
각 줄에 n개의 소문자 중에서 r개만을 뽑아 나열하는 경우를 사전순으로 나열한 결과를 출력한다.
*/
int tot;

void func(int n, int step, int branch, int *alCheck, int r, const char *alpha, char *answer);

int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	const char alpha[11] = "abcdefghij";
	int alCheck[10] = { 0 };
	//for (int i = 0;i < 10;i++)printf("%d", alCheck[i]);
	char answer[8];
	memset(answer, '\0', sizeof(answer));
	func(n, 0, n, alCheck, r, alpha, answer);
	//printf("%d\n", tot);
	return 0;

}
void func(int n, int step, int branch, int *alCheck, int r, const char *alpha, char *answer) {
	//alCheck[]은 사용한 알파벳체크하는 배열
	//printf("n: %d, r: %d, step: %d, branch: %d\n", n, r, step, branch);

	if (step == r) {
		tot++;
		answer[step] = '\0';
		printf("%s\n", answer);
		return;
	}

	int brTmp[10];
	memcpy(brTmp, alCheck, sizeof(int)*n);
	for (int i = 0;i < branch;i++) {
		int alTmp[10];
		memcpy(alTmp, alCheck, sizeof(int)*n);
		for (int j = 0;j < n;j++) {
			if (brTmp[j] == 0) {
				brTmp[j] = 1;
				alTmp[j] = 1;
				answer[step] = alpha[j];
				//test
				//printf("%s\n", answer);
				break;
			}
			else {
				continue;
			}
		}
		func(n, step + 1, branch - 1, alTmp, r, alpha, answer);
	}

}
/*

*/
