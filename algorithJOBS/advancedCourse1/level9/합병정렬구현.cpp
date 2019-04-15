#include <stdio.h>
#include <stdlib.h>
/*
문제
서로 다른 n개의 정수가 주어질 때, 이를 합병정렬을 이용하여 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 두번째 줄에 n개의 정수가 주어진다.

출력
첫 번째 줄에 n개의 숫자를 합병정렬을 이용하여 오름차순으로 정렬한 결과를 출력한다.

예제 입력
10
2 5 3 4 8 7 -1 9 10 2
예제 출력
-1 2 2 3 4 5 7 8 9 10
*/
int arr[100000];
int temp[100000];
void merge(int arr[], int start, int mid, int end) {
	int s = start;
	int e = mid + 1;
	int temIdx = 0;
	while (s <= mid && e <= end) {
		if (arr[s] < arr[e])
			temp[temIdx++] = arr[s++];
		else
			temp[temIdx++] = arr[e++];
	}
	if (s > mid)
		for (int i = e; i <= end; i++)
			temp[temIdx++] = arr[i];
	else
		for (int i = s; i <= mid; i++)
			temp[temIdx++] = arr[i];
	for (int i = start; i <=end; i++)arr[i] = temp[i-start];
}
void mergeSort(int arr[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", arr + i);
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)printf("%d ", arr[i]);

	return 0;
}
