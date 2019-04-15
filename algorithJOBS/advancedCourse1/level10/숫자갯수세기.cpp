문제
n개의 숫자가 주어지고, q개의 질문이 주어진다. 각각의 질문은 n개의 숫자 중에서 특정 숫자가 몇개나 있는지를 묻는다. q개의 질문에 모두 답하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 숫자의 개수 n, 그리고 질문의 개수 q가 주어진다 ( 1 ≤ n ≤ 100,000, 1 ≤ q ≤ 100,000) 두 번째 줄에 n개의 숫자가 주어진다. 세 번째 줄에 q개의 질문이 주어진다. 주어지는 q개의 질문에 해당하는 숫자 범위는 100,000,000이하이다.  

출력
각 질문에 대하여 숫자의 개수를 한 줄에 하나씩 출력한다.  

예제 입력
10 4
1 3 4 3 2 3 1 2 5 10
1 3 9 10
예제 출력
2
3
0
1

#include <stdio.h>
#define max 100000
/*
문제

*/
int arr[max];
int ques[max];
int temp[max];
int count;

// 1 1 2 2 3 3 4 5 10

int binarySearch(int arry[], int start, int end, int target) {
	if (start > end) {
		return -1;
	}
	int mid = (start + end) / 2;

	if (arry[mid] == target) {
		count++;
		binarySearch(arry, start, mid - 1, target);
		binarySearch(arry, mid + 1, end, target);
	}
	else if (target < arry[mid]) return binarySearch(arry, start, mid - 1, target);
	else return binarySearch(arry, mid + 1, end, target);
}
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
	for (int i = start; i <= end; i++)arr[i] = temp[i - start];
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
int main(void) {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	mergeSort(arr, 0, n - 1);
	/*for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");*/
	

	for (int i = 0; i < q; i++) {
		scanf("%d", ques + i);
	}

	for (int i = 0; i < q; i++)
	{
		count = 0;
		binarySearch(arr, 0, n - 1, ques[i]);
		printf("%d\n", count);
	}
	return 0;
}

