문제
N과 시작 숫자 S가 주어지면 숫자 피라미드를 만드는 프로그램을 작성하시오. 예를 들어, N이 5이고 S가 3 이라면, 그 숫자 피라미드는

    3
   456
  21987
 3456789
987654321
가 된다.

 

입력
입력의 첫 번째 줄에 N과 시작 숫자 S가 주어진다. ( 1≤N≤100, 1 ≤S≤ 9)

 

출력
첫 번째 줄부터 숫자 피라미드를 출력한다. (각 줄에 존재하는 공백의 개수와 숫자의 개수를 정확하게 확인해주시바랍니다.)

 

예제 입력
5 3
예제 출력
    3
   456
  21987
 3456789
987654321


#include <stdio.h>


int main() {

/*
	3
   456
  21987
 3456789
987654321
*/
	int i, j;
	int num;
	int n, s;
	int arr[200];
	int size;
	scanf("%d %d", &n, &s);
	num = s;
	for (i = 0;i < n;i++) {
		if (i % 2) {//짝수줄 순행
			for (j = 0;j < n - i-1;j++)printf(" ");
			for (j = 0;j < 2 * i + 1;j++) {
				printf("%d", num);
				if (num != 9)num++;
				else num = 1;
			}
		}
		else {//홀수줄 역행
			for (j = 0;j < n - i - 1;j++)printf(" ");

			size = 0;
			for (j = 2 * i ;j >= 0 ;j--) {
				arr[size++] = num;
				if (num != 9)num++;
				else num = 1;
				
			}
			for (j = 2 * i;j >= 0;j--) {
				printf("%d", arr[j]);
			}
		}
		printf("\n");
	}

	return 0;
}

