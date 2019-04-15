중복없는구간
이전다음
문제
n개의 숫자가 주어지고, 이 중에서 r개의 연속된 숫자를 선택했을 때, 이 연속 부분 내에는 숫자가 중복되지 않기를 원한다. 예를 들어, 다음과 같이 10개의 숫자에서 3개의 연속된 숫자를 선택할 수 있다.

중복없는구간

이렇게 선택을 하면, 선택된 숫자들 사이에서는 중복이 존재하지 않는다. r의 최댓값을 구하는 프로그램을 작성하시오. 위의 경우, (4, 2, 1, 3)을 선택하면 되므로 r의 최댓값은 4이다. r이 5 이상이 될 경우, 중복 없이 연속 부분을 선택하는 것이 불가능하다.

 

입력
첫째 줄에는 숫자의 개수 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 둘째 줄에 n개의 숫자가 주어진다. 각 숫자는 항상 1보다 크거나 같고, n보다 작거나 같다.  

출력
r의 최댓값을 출력한다.

 

예제 입력
10
1 3 1 2 4 2 1 3 2 1
예제 출력
4
 

예제 입력
7
7 1 4 2 5 3 6
예제 출력
7

#include<stdio.h>

const int MAX = 100001;
int arr[MAX];
int n;

int maxLength = 0;

int isLength(int searchLen) {
	int check[MAX];
	for (int i = 0;i < MAX;i++)
		check[i] = -1;
	int len = 0;
	int start = 0;
	for (int idx = 0; start <= n - searchLen; idx++) {
		/*for (int i = 0;i < n;i++)
			printf("%d ", arr[i]);
		printf("\n");
		printf("start: %d, idx: %d, len: %d\n", start, idx,len+1);*/
		int num = arr[idx];

		if (check[num] == -1)
		{
			check[num] = idx;
			len++;
			if (len == searchLen) {
				//printf("길이만족!\n");
				len = 0;
				return 1;
			}

		}
		else
		{
			int tmp = check[num];
			//printf("중복발생 이유: %d위치 때문\n",tmp);
			
			
			for (int x = start;x <= tmp;x++) {
				check[arr[x]] = -1;
				len--;
			}
			check[num] = idx;
			len++;
			start = tmp + 1;
			
			//printf("%d로 start이동, len: %d\n", start, len);
		}

		//test
		
		/*for (int i = 1;i < 20;i++)
			if (check[i] == -1)
				printf("X ");
			else
				printf("%d ", check[i]);
		printf("\n\n");*/

	}
	//printf("불가능\n");
	return 0;

}

void BinerySearch(int s, int e) {
	//printf("길이구간 (%d, %d)\n", s, e);
	if (e < s)
		return;
	int mid = (s + e) / 2;
	//printf("길이 %d\n", mid);
	if (isLength(mid)) {
		if (mid > maxLength)
			maxLength = mid;
		BinerySearch(mid + 1, e);
	}
	else
		BinerySearch(s, mid - 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", arr + i);
	BinerySearch(1, n);
	printf("%d\n", maxLength);

	return 0;
}
