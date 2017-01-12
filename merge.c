#include <stdio.h>
#include <stdlib.h> 

int notations(int *n, int *mid, int *i)
{
	if(*n < 2)
		return (0);
	*mid = *n/2;
	*i = -1;
}

void merge(int *a,int *l,int arr[2],int *r) 
{
	int i;
	int j;
	int k;

	i = 0; 
	j = 0; 
	k = 0;
	while(i<arr[0] && j< arr[1]) {
		if(l[i]  < r[j]) 
			a[k++] = l[i++];
		else 
			a[k++] = r[j++];
	}
	while(i < arr[0]) 
		a[k++] = l[i++];
	while(j < arr[1]) 
		a[k++] = r[j++];
}

void merge_sort(int *a,int n) 
{
	int mid;
	int i; 
	int *l;
	int *r;
	int arr[2];

	if(!notations(&n, &mid, &i))
		return ;
	l = (int*)malloc(mid*sizeof(int)); 
	r = (int*)malloc((n- mid)*sizeof(int)); 
	while(++i < mid) 
		l[i] = a[i];
	i = mid - 1; 
	while(++i < n) 
		r[i-mid] = a[i];
	arr[0] = mid;
	arr[1] = n-mid;
	merge_sort(l,mid);  
	merge_sort(r,n-mid);
	merge(a,l,arr,r);
    free(l);
    free(r);
}

/*int main() {
	int A[] = {9, 8, 7,6,5,4,3,2,1};
	int i,numberOfElements;
	numberOfElements = sizeof(A)/sizeof(A[0]); 
	merge_sort(A,numberOfElements);
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}*/
