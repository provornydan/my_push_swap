#include <stdio.h>
#include <stdlib.h> 

typedef struct  arrn
{
	long long val;
	int ord; 
}				str;

long long notations(long long *n, long long *mid, long long *i)
{
	if(*n < 2)
		return (0);
	*mid = *n/2;
	*i = -1;
}

void merge(str *a,str *l,long long arr[2],str *r) 
{
	long long i;
	long long j;
	long long k;

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

void merge_sort(str *a, long long n) 
{
	long long mid;
	long long i; 
	str *l;
	str *r;
	long long arr[2];

	if(!notations(&n, &mid, &i))
		return ;
	l = (str*)malloc(mid*sizeof(str)); 
	r = (str*)malloc((n- mid)*sizeof(str)); 
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

long long main() {
	
	str *here = (str *)malloc(sizeof(str)*5);
	str one,two,three,four,five;
	one.val = 3; one.ord = 0;
	two.val = 1; two.ord = 1;
	three.val = 7; three.ord = 2;
	four.val = 6; four.ord = 3;
	five.val = 5; five.ord = 4;
	here[0] = one; here[1] = two; here[2] = three; here[3] = four; here[4] = five;
	long long numberOfElements = 5; 
	merge_sort(here, numberOfElements);
	for(long long i = 0; i< numberOfElements; i++)
		printf("%5lu", here[i].val);
	printf("\n");
	for(long long i = 0; i< numberOfElements; i++)
		printf("%5d", here[i].ord);
	return 0;
}
