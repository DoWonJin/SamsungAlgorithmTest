#include <stdio.h>
#define max 1000000000
/*
문제
2차식 f(x) = x*x+ x 가 있고, 숫자 a가 주어진다. 우리는 f(x) = a 를 만족하는 x의 값을 찾고 싶지만, 보통 이 값은 정수로 떨어지지 않는 경우가 많다. 예를 들어, f(x) = 20 을 풀고자 한다면, x = 4이기 때문에 이는 정수이지만, f(x) = 103 을 풀고자 한다면 이는 x = 9.6612... 로써 정수가 아니다.

이 문제에서는 x의 정수부분이 얼마인지를 구하는 프로그램을 작성하시오. 예를 들어, f(x) = 103 을 풀고자 한다면, x = 9.6612... 이기 때문에 정수부분은 9가 된다.



입력
첫 번째 줄에 숫자 a가 주어진다. ( 1 ≤ a ≤ 1,000,000,000,000,000,000)

출력
f(x) = a 를 만족하는 x의 정수부분을 출력한다.

예제 입력
103
예제 출력
9
*/

//int binarySearch(int arry[], int start, int end, int target) {
//
//	if (start > end) {
//		return -1;
//	}
//	int mid = (start + end) / 2;
//	
//	if (target == arry[mid])return mid;
//	else if (arry[mid] <= target && target < arry[mid + 1])return mid;
//	else if (target <= arry[mid-1]) return binarySearch(arry, start, mid - 1, target);
//	else if(target >= arry[mid+1]) return binarySearch(arry, mid + 1, end, target);
//	
//}
long long int binarySearch(long long int start, long long int end, long long int target) {

	if (start > end) {
		return -1;
	}
	//printf("(%3d, %3d)\n", start, end);
	long long int m = (start + end) / 2;
	long long int value = m * m + m;
	long long int next_val = (m + 1)*(m + 1) + m + 1;
	if (value <= target && target < next_val)return m;
	else if (target < value) return binarySearch(start, m - 1, target);
	else return binarySearch( m + 1, end, target);

}

int main(void) {
	long long int a;
	long long int ans;
	scanf("%lld", &a);
	long long int res = binarySearch(0, max - 1, a);
	printf("%lld\n", res);
	return 0;
}
