문제
숫자를 입력 받아 이진수로 출력하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 숫자를 입력 받는다. 숫자의 크기는 1,000보다 작거나 같다.

 

출력
첫째 줄에 숫자를 이진수로 바꾸어 출력한다.

 

예제 입력
14
예제 출력
1110
 

예제 입력
31
예제 출력
11111

#include <stdio.h>


int main() {

	//Please Enter Your Code Here
	int num;
	int i, j;
	int res;
	int arr[10];
	int size = 0;
	scanf("%d", &num);
	
	while (1) {
		if (num == 0) {
			arr[0] = 0;
			break;
		}
		else if (num == 1) {
			arr[0] = 1;
			break;
		}
		arr[size++] = num % 2;
		num = num / 2;
		if (num == 1) {
			arr[size] = 1;
			break;
		}		
	}
	
	for (i = size;i >= 0;i--)printf("%d", arr[i]);



	return 0;
}

