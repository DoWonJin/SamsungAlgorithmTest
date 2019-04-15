문제
두 개의 자연수를 입력받아 최대공약수(GCD)와 최소공배수(LCM)를 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000 이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

 

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소공배수를 출력한다.

 

예제 입력
24 18
예제 출력
6
72
 

출처
한국정보올림피아드 지역본선 2004 중등부 1번, 고등부 1번

#include <stdio.h>

int find(int a, int b) {
	int GCD;
	int i = a;
	if (b%a == 0) {
		return a;
	}
	i--;
	while (1) {
		if (b%i == 0 && a%i == 0)return i;
		else i--;
	}
}

int main() {
	
	int a, b;
	int GCD, LCM;


	scanf("%d %d", &a, &b);

	if (a < b) {
		GCD = find(a, b);
		LCM = GCD * (a/GCD) *(b/GCD);
	}
	else if (a > b) {
		GCD = find(b, a);
		LCM = GCD * (a / GCD) *(b / GCD);
	}
	else {
		GCD = a;
		LCM = a;
	}
	printf("%d\n", GCD);
	printf("%d\n", LCM);


	return 0;
}


//#include <stdio.h>
//
//
//
//int main() {
//
//	int arr[1000];
//	int dice[6];
//	int typeNum;
//
//	for (int i = 0;i < 6;i++) {
//		dice[i] = 0;
//	}
//
//	scanf("%d", &typeNum);
//	for (int i = 0;i < typeNum;i++) {
//		scanf("%d", arr + i);
//	}
//	for (int i = 0;i < typeNum;i++) {
//		switch (arr[i]) {
//		case 1:
//			dice[0]++;
//			break;
//		case 2:
//			dice[1]++;
//			break;
//		case 3:
//			dice[2]++;
//			break;
//		case 4:
//			dice[3]++;
//			break;
//		case 5:
//			dice[4]++;
//			break;
//		case 6:
//			dice[5]++;
//			break;
//		}
//	}
//
//
//
//
//
//	return 0;
//}


/*
#include <stdio.h>


int main() {

	return 0;
}


*/
