#include<iostream>
#define L 18

void swap(int *a, int i , int j)
{
	// printf("swap a[%d]=%d ,a[%d]=%d\n", i , *(a+i), j, *(a+j));
	int temp = *(a+i);
	*(a+i) = *(a+j);
	*(a+j) = temp;
}

void bubleSort(int *a, int num)
{
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<num-i-1; j++)
		{
			if(*(a+j) > *(a+j+1))
				swap(a,j,j+1);
		}
	}
}

void printArray(int *array, int num_element = L)
{
	printf("--------------------------------\n");
	for(int i=0; i<num_element; i++)
	{
		printf("%d ",*(array+i) );
	}

	printf("\n--------------------------------\n");
}

void mergeArray(int *a, int s_1, int l_1, int s_2, int l_2)
{
	// printf("merge array : %d, %d , %d , %d \n", s_1, l_1, s_2, l_2);
	int s1 = s_1;
	int s2 = s_2;

	int *temp = (int*)malloc(sizeof(int)*(l_1 - s_1 + 1 + l_2 - s_2 + 1));
	int i=0;

	while(s_1 <= l_1 and s_2 <= l_2)
	{
		if(*(a+s_1) < *(a+s_2))
		{
			*(temp+i++) = (*(a+s_1++));
		}

		else 
		{
			*(temp+i++) = (*(a+s_2++));
		}
	}

	while(s_1 <= l_1)
		*(temp+i++) = (*(a+s_1++));
	while(s_2 <= l_2)
		*(temp+i++) = (*(a+s_2++));

	for(int i=0; i< (l_1 - s1 + 1 + l_2 - s2 + 1); i++)
	{
		*(a+i+s1) = *(temp+i);
	}

	free(temp);
	temp = NULL;
}


void mergeSort(int *a, int start, int last)
{
	// printf("----------------------------------------\n\n\n\n");
	int mid = (start + last)/2;

	// printf("%d=start, %d=mid, %d=last\n", start, mid, last);
	// printArray(a);

	if((last-start) == 1 and *(a+start) > *(a+last))
	{
		swap(a,start, last);
	}

	else if((mid - start) >= 1 or (last-(mid+1)) >= 1) 
	{
		mergeSort(a,start, mid);
		mergeSort(a, mid+1, last);	
		mergeArray(a,start, mid, mid+1, last);
		// printf("after merge\n");
		// printArray(a);

	}
}


int main()
{
	int num_element = 25;
	int *a = (int*)malloc(num_element*sizeof(int));
	int *b = (int*)malloc(num_element*sizeof(int));

	for(int i=0; i<num_element; i++)
	{
		*(a+i) = rand()%(num_element+i);
		*(b+i) = rand()%(num_element+2*i);
	}

	printArray(a,num_element);
	mergeSort(a,0, num_element-1);
	printArray(a,num_element);

	// bubleSort(a,num_element);
	// bubleSort(b,num_element);

	// printArray(a,num_element);
	// printArray(b,num_element);

	// int *merged = (int*)malloc((num_element+num_element)*sizeof(int));

	// for(int i=0; i<num_element; i++)
	// {
	// 	*(merged+i) = *(a+i);
	// 	*(merged+i+num_element) = *(b+i);
	// }
	// printArray(merged,2*num_element);

	// mergeArray(merged, 0, num_element-1, num_element, 2*num_element-1);

	// printArray(merged, 2*num_element);


}