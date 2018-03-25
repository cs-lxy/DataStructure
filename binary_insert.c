/*使用二分插入法，将一个整数插入到一个升序数组int[6]中，插入后保持数组依然为升序。*/
#include <stdio.h>

void print(int *pa,int len);
void binary_insert(int *pa,int len,int val);
int binary_search(int *pa,int low,int high,int val);

int main(int argc, char const *argv[])
{
	int arr[6] = {1,3,5,7,10};
	int val = 9;
	printf("--------before-------\n");
	print(arr,6);
	binary_insert(arr,5,val);
	printf("--------after-------\n");
	print(arr,6);
	return 0;
}
/*二分查找-插入*/
void binary_insert(int *pa,int len,int val)
{
	//1.查找插入位置
	int index;
	index = binary_search(pa,0,len-1,val);
	printf("index = %d \n", index);
	//2.后移元素，插入目标
	for (int i = len-1; i >= index; --i)
	{
		pa[i+1] = pa[i];
	}
	pa[index] = val;
}
/*查找合适位置*/
int binary_search(int *pa,int low,int high,int val)
{
	int mid = (low + high)/2;

	if(low >= high)//如果要插入的位置在最前面，则low>high
	{
		return (val >= pa[low] ? low+1:low); 
	}
	
	if(val == pa[mid])//如果相等，则在后面位置插入
	{
		return mid+1;
	}
	if(val < pa[mid])//如果小于中间值，则在前半部分继续寻找
	{
		return binary_search(pa,low,mid-1,val);
	}
	if(val > pa[mid])//如果大于中间值，则在后半部分继续寻找
	{
		return binary_search(pa,mid+1,high,val);
	}
	return -1;
}
/*打印输出数组*/
void print(int *pa,int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", pa[i]);
	}
	printf("\n");
}
