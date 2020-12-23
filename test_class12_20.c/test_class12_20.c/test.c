#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


//int main()
//{
//	int ret = isdigit('8');
//	printf("%d\n", ret);
//	return 0;
//}
//int main()
//{
//	char arr[] = "i have a pen";
//	int i = 0;
//	while (arr[i])
//	{
//		if (islower(arr[i]))
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//	return 0;
//}
//my_memcopy(void* dest, const void* src, size_t count)
//{   
//	void* ret = dest;
//	assert(dest && src);
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
void* my_memmove(void* dest, const void*src, size_t count)
{
	void* ret = dest;
	assert(dest && src);
	if (dest < src)
	{
		while (count--)
		{
	        *(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{	
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	//my_memcopy(arr2, arr1, 20);
	my_memmove(arr3 + 2, arr3, 16);
	return 0;

}
