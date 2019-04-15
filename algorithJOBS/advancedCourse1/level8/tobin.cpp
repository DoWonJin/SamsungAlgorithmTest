tobin
이전다음
문제
두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.

 

입력
두 정수 n, k가 입력으로 주어진다. ( 0 < n <= 30, 0 <= k < 8 , n >= k )

 

출력
결과를 내림차순으로 출력한다.

 

예제 입력
2 1
예제 출력
10
01
 

예제 입력
2 0
예제 출력
00
 

예제 입력
4 2
예제 출력
1100
1010
1001
0110
0101
0011
 

출처
uwaterloo junior contest  

#include<stdio.h>
/*
문제
두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.
입력
두 정수 n,k가 입력으로 주어진다. ( 0< n <= 30, 0 <= k < 8 , n>=k )
출력
결과를 내림차순으로 출력한다.
*/


void func(int n, int k, int n2, int k2, int *arry,bool j) {
	//두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.
	if (n > n2)return;//자리수가 넘어가면 취소해야함
	if (j && n>=1)
		arry[n - 1] = 1;
	else
		arry[n - 1] = 0;
	if (n <= n2 && k == k2) {
		for (int i = 0; i < n2; i++) {
			printf("%d", arry[i]);
		}
		printf("\n");
		return;
	}

	func(n + 1, k + 1, n2, k2, arry,true);
	func(n + 1, k    , n2, k2, arry,false);
}

int main() {
	int n2,k2;
	scanf("%d %d", &n2,&k2);
	int arry[30] = { 0 };
	func(0, 0, n2, k2, arry,true);
	return 0;
}
