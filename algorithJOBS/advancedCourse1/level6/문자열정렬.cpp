문제
n개의 문자열이 주어질 때, 이 문자열을 사전순으로 빠른 순서대로 정렬하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 문자열의 개수 n이 주어진다 ( 1 ≤ n ≤ 100 ) 그 후 n개의 줄에 대하여 정렬하고자 하는 문자열이 주어진다 ( 1 ≤ 문자열의 길이 ≤ 100 )  

출력
문자열을 사전순으로 빠른 순서대로 정렬한 결과를 출력한다.

 

예제 입력
9
acid
apple
banana
acquire
cat
crop
crab
power
cat
예제 출력
acid
acquire
apple
banana
cat
cat
crab
crop
power

	#include <stdio.h>
	#include <string.h>
/*
문제
n개의 문자열이 주어질 때, 이 문자열을 사전순으로 빠른 순서대로 정렬하는 프로그램을 작성하시오.

입력
첫 번째 줄에 문자열의 개수 n이 주어진다 ( 1 ≤ n ≤ 100 ) 그 후 n개의 줄에 대하여 정렬하고자 하는 문자열이 주어진다
( 1 ≤ 문자열의 길이 ≤ 100 )

출력
문자열을 사전순으로 빠른 순서대로 정렬한 결과를 출력한다.
*/
	int main() {
		int num;
		char ptr[100][100];
		char tmp[100];
		scanf("%d", &num);
		for (int i = 0;i < num;i++) {
			scanf("%s", &ptr[i]);
		}
		for (int i = 0;i < num - 1;i++) {
			for (int j = 0;j < num - 1 - i;j++) {
				if (strcmp(ptr[j], ptr[j + 1]) > 0) {
					strcpy(tmp, ptr[j]);
					strcpy(ptr[j],ptr[j+1] );
					strcpy(ptr[j + 1],tmp );
				}
			}
		}
		for (int i = 0;i < num;i++) {
			printf("%s\n", ptr[i]);
		}

		

		return 0;
	}
