#include <stdio.h>

struct Queue {
	int data[100];
	int f, r;
	int capacity;

	void create(int y) {
		capacity = y;
		f = 0;
		r = 0;
	}
	void push(int y) {
		if (r == capacity)
			printf("Overflow\n");
		else
			data[r++] = y;
	}
	void pop() {
		if (r - f <= 0)
			printf("Underflow\n");
		else
			data[f++] = 0;
	}
	int front() {
		if (r - f <= 0)
		{
			printf("NULL\n");
			return -1;
		}
		else
		{
			printf("%d\n", data[f]);
			return data[f];
		}
			
	}
	int size() {
		return r - f;
	}

};

int main() {
	/*
	0 1 2 3
	      

	*/
	Queue q;
	int n, m;
	int inp[2];
	scanf("%d %d", &n, &m);
	q.create(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", inp);
		if (inp[0] == 1) {
			scanf("%d", inp + 1);
			q.push(inp[1]);

		}
		else if(inp[0]==2) {
			q.pop();
		}
		else {
			q.front();
		}
	}
	return 0;
}
