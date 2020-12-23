

#include<stdio.h>
#include <string.h>

bubble_sort(int* arr, int sz)//简单的冒泡排序
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 1; j < sz - i; j++)
		{
			if (arr[j - 1]>arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
//生成自己的qsort排序函数
//void qsort(
//			void *base, 
//			size_t sz, 
//			size_t width, 
//			int( *cmp)(const void *e1, 
//			const void *e2
//							)
int cmp_int(const void *e1, const void *e2)
{
	return *(int*)e1 - *(int*)e2;
}
void swap(char* buf1, char* buf2, int width)
{

	for (int i = 0; i < width; i++)
	{
		char tem = *buf1;
		*buf1 = *buf2;
		*buf2 = tem;
		buf1++;
		buf2++;

	}
}
void my_qsort(void *base, size_t sz, size_t width, int(*cmp)(const void *e1, const void *e2))//cmp用来比较两个值的大小
{
	for (size_t i = 0; i < sz - 1; i++)
	{
		for (size_t j = 1; j < sz - i; j++)
		{
			if (cmp((char*)base + (j - 1)*width, (char*)base + j*width)>0)
			{
				swap((char*)base + (j - 1)*width, (char*)base + j*width, width);
			}
		}
	}
}

void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test1()
{
	//整形排序
	int arr[] = { 3, 1, 5, 2, 4, 9, 8, 7, 6, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	//bubble_sort(arr, sz);//简单的冒泡排序
	my_qsort(arr, sz, sizeof(int), cmp_int);
	print(arr, sz);
}
struct Book
{
	char name[20];
	int price;
};
int cmp_name(const void *e1, const void *e2)
{
	return strcmp(((struct Book*)e1)->name, ((struct Book*)e2)->name);
}
int cmp_price(const void *e1, const void *e2)
{
	return ((struct Book*)e1)->price - ((struct Book*)e2)->price;
}
void test2()
{
	struct Book book[3] = { { "laorenyuhai", 40 }, { "zhaohuaxishi", 30 }, { "haidenver", 100 } };
	//my_qsort(book, 3, sizeof(struct Book), cmp_name);
	my_qsort(book, 3, sizeof(struct Book), cmp_price);
}


int main()
{
	//test1();
	test2();
	return 0;

}

