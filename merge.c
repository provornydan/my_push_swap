#include <stdio.h>
#include <stdlib.h> 

long long notations(long long *n, long long *mid, long long *i)
{
	if(*n < 2)
		return (0);
	*mid = *n/2;
	*i = -1;
}

void merge(long long *a,long long *l,long long arr[2],long long *r) 
{
	long long i;
	long long j;
	long long k;

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

void merge_sort(long long *a,long long n) 
{
	long long mid;
	long long i; 
	long long *l;
	long long *r;
	long long arr[2];

	if(!notations(&n, &mid, &i))
		return ;
	l = (long long*)malloc(mid*sizeof(long long)); 
	r = (long long*)malloc((n- mid)*sizeof(long long)); 
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

/*long long main() {
	long long A[] = {9, 8, 7,6,5,4,3,2,1};
	long long i,numberOfElements;
	numberOfElements = sizeof(A)/sizeof(A[0]); 
	merge_sort(A,numberOfElements);
	for(i = 0;i < numberOfElements;i++) prlong longf("%d ",A[i]);
	return 0;
}*/
