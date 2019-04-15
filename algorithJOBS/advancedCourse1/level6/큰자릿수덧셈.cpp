큰 자릿수 덧셈
이전다음
문제
두 자연수가 주어질 때 그들의 덧셈을 계산하는 프로그램을 작성하시오. 각 수는 1 이상 10^100 미만의 범위를 가진다.  

입력
첫 번째 줄과 두 번째 줄에 각각 하나의 자연수가 주어진다.  

출력
첫 번째 줄에 덧셈의 결과를 출력한다.

 

예제 입력
123112981293812938139
1298928491101221811
예제 출력
124411909784914159950


#include <stdio.h>
#include <string.h>
/*
문제
두 자연수가 주어질 때 그들의 덧셈을 계산하는 프로그램을 작성하시오. 각 수는 1 이상 10^100 미만의 범위를 가진다.

입력
첫 번째 줄과 두 번째 줄에 각각 하나의 자연수가 주어진다.

출력
첫 번째 줄에 덧셈의 결과를 출력한다.
*/
int main() {
	char strA[101];
	char strB[101];
	char sum[101];
	memset(sum, '\0', sizeof(sum));
	scanf("%s\n%s", strA, strB);

	char *ptrA = strA;
	char *ptrB = strB;
	char *tmp;
	if (strlen(ptrA) < strlen(ptrB)) {
		tmp = ptrA;
		ptrA = ptrB;
		ptrB = tmp;
	} // A > B : A가 길다

	int add = 0;
	int tot;
	int idxA, idxB;
	bool check = false;
	for (int i = 0; i < strlen(ptrB); i++) {
		idxA = strlen(ptrA) - i - 1;
		idxB = strlen(ptrB) - i - 1;
		tot = ptrA[idxA] - '0' + ptrB[idxB] - '0' + add;
		if (tot >= 10) {
			add = 1;
			tot -= 10;
			if (strlen(ptrA) == strlen(ptrB) && idxA == 0)
				check = true;
		}
		else
			add = 0;
		sum[idxA] = tot;
	}
	
	if (strlen(ptrA) != strlen(ptrB))
		for (int i = strlen(ptrA) - strlen(ptrB) - 1; i >= 0; i--) {
			tot = ptrA[i] - '0' + add;
			if (tot >= 10) {
				add = 1;
				tot -= 10;
				if (i == 0) {
					check = true;
				}
			}
			else
				add = 0;
			sum[i] = tot;
		}

	if (check)printf("1");
	for (int i = 0; i < strlen(ptrA); i++)
		printf("%d", sum[i]);
	return 0;
}
