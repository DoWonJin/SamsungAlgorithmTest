NN단표
이전다음
문제
알랩이는 구구단표처럼 NN단표를 만들었다고 한다.

NN단표는 2차원 배열의 모양으로 곱셈 1단부터 N단까지의 값들을 적어놓은 형태이다.

NN단표의 배열을 A라고 했을 때, 배열의 들어가는 수 A[i][j]=i*j이다.(즉, 4행 7열에는 28, 7행 5열에는 35가 들어가 있다.)

알랩이는 N단까지 나온 숫자들 중에서 K번째로 작은 수를 찾고 싶어한다.

이때, 중복되는 여러 수들을 고려한다. 즉 N*N개의 모든 수들 중에서 K번째 수를 구하는 것이다.  

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 100,000보다 작거나 같은 자연수이다. 둘째 줄에 K가 주어진다. K는 N*N보다 작거나 같은 자연수이다.  

출력
K번째 원소를 출력한다.

 

예제 입력
3
7
예제 출력
6
 
 
 #include <stdio.h>

int n, seat;
int arr[100000];
int size;

int advisableSearch(int num) {
	int q, r;
	for (int i = 1; i <= n; i++)
	{
		r = num % i;
		q = num / i;
		if (r == 0 && 1 <= q && q <= n) {
			return true;
		}
	}
	return false;
}

long long int counCheck(int num) {
	long long int tot = 0;
	for (int i = 1; i <= n; i++) {
		int q = num / i;
		int add;
		if (num % i == 0)
			if (q > n)add = n;
			else add = q - 1;
		else
			if (q > n) add = n;
			else add = q;
		tot += add;
	}
	return tot;
}

void binarySearch(int s, int e, int seat) {
	//printf("탐색시작 [%d %d]\n", s, e);
	if (e < s) {
		//printf("탈출\n");
		return;
	}
	int mid = (s + e) / 2;
	long long int t = counCheck(mid), tNext = counCheck(mid + 1);
	//printf("count[%d] : %d count[%d]: %d\n", mid, t, mid + 1, tNext);
	
	if (t < seat && seat < tNext) {
		//printf("사에 껴있다\n");
		arr[size++] = mid;
		return;
	}

	/*if (e == s && t != seat)
	{
		arr[size++] = mid;
		return;
	}*/

	else if (t == seat) {
		//printf("count[mid]가 seat랑 같다\n");
		arr[size++] = mid;
		binarySearch(mid + 1, e, seat);
		binarySearch(s, mid - 1, seat);
	}
	else if (t < seat) {
		//printf("좌측 탐색대상제외\n");
		binarySearch(mid + 1, e, seat);
	}
	else {
		//printf("우측 탐색대상제외\n");
		binarySearch(s, mid - 1, seat);
	}

}

int main()
{

	scanf("%d\n%d", &n, &seat);
	binarySearch(1, n*n, seat - 1);
	for (int i = 0; i < size; i++) {
		if (advisableSearch(arr[i]) == true) {
			printf("%d\n", arr[i]);
			break;
		}
	}
	return 0;
}
