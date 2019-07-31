#include "header.h"

int notations_s(int *n, int *mid, int *i)
{
	if(*n < 2)
		return (0);
	*mid = *n/2;
	*i = -1;
}

void merge_s(sss *a,sss *l,int arr[2],sss *r) 
{
	int i;
	int j;
	int k;

	i = 0; 
	j = 0; 
	k = 0;
	while(i<arr[0] && j< arr[1]) {
		if(l[i].val  < r[j].val) 
			a[k++] = l[i++];
		else 
			a[k++] = r[j++];
	}
	while(i < arr[0]) 
		a[k++] = l[i++];
	while(j < arr[1]) 
		a[k++] = r[j++];
}

void merge_sort_s(sss *a, int n) 
{
	int mid;
	int i; 
	sss *l;
	sss *r;
	int arr[2];

	if(!notations_s(&n, &mid, &i))
		return ;
	l = (sss*)malloc(mid*sizeof(sss)); 
	r = (sss*)malloc((n- mid)*sizeof(sss)); 
	while(++i < mid)
		l[i] = a[i];
	i = mid - 1; 
	while(++i < n)
		r[i-mid] = a[i];
	arr[0] = mid;
	arr[1] = n-mid;
	merge_sort_s(l,mid);  
	merge_sort_s(r,n-mid);
	merge_s(a,l,arr,r);
    free(l);
    free(r);
}
