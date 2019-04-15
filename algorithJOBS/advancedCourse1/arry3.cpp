문제
N이 주어질 때, 다음과 같은 프로그램을 작성해보자.  

입력
첫째 줄에 자연수 N이 주어진다.(1<=N<=100)

 

출력
예시를 참고하여 작성하자.

 

예제 입력
3 
예제 출력
1 2 4
3 5
6 
 

예제 입력
5
예제 출력
1 2 4 7 11
3 5 8 12 
6 9 13 
10 14
15 

#include <stdio.h>


int main() {
	int N;
	int i, j;
	int num;
	int d;
	scanf("%d", &N);
	
	for (i = 0;i < N;i++) {
		d = i + 1; //공차의 초항
		num = (i + 1)*(i + 2) / 2;
		for (j = 0;j < N - i;j++) {
			if (j) {
				num += (d + j - 1);
			}
			printf("%d ", num);
		}
		printf("\n");
	}

	return 0;
}

