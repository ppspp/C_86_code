#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人
typedef struct person{
	char Name[1000];
	int Sex;
	int Age;
	char Num[12000];
	char Address[32000];
}list;
//添加联系人
void add(list *people){ 
	printf("请输入用户姓名:");
	scanf("%s", people->Name);
	printf("\n请输入用户性别（1.男 ， 2.女 ）：");
	scanf("%d", &(people->Sex));
	printf("\n请输入用户年龄:");
	scanf("%d", &(people->Age));
	printf("\n请输入用户的电话号码：");
	scanf("%s", people->Num);
	printf("\n请输入用户的地址:");
	scanf("%s", people->Address);
}
//查找指定联系人，存在的话返回1
int searchfor(list people, char *s){
	if (strcmp(people.Name, s) == 0){
		return 1;
	}
	else{
		return 0;
	}
}
//打印函数
void showlist(list people){
		if (strcmp(people.Name, "NULL") == 0) {
			return;
		}
		printf("\n姓名：%s", people.Name);
		if (people.Sex == 1){
			printf("\n性别: 男");
		}
		else{
			printf("\n性别: 女");
		}
		printf("\n年龄：%d", people.Age);
		printf("\n电话号码：%s", people.Num);
		printf("\n地址：%s", people.Address);
}
//删除指定联系人
void delete(list *people){
	printf("输入要删除联系人的姓名：");
	char n[50] = {0};
	scanf("%s",n);
	for (int i = 0; i < 1000; i++){
		if (searchfor(people[i], n)){
			strcpy(people[i].Name, "NULL");
			printf("已删除\n");
			return;
		}
	}
	printf("没有这个人");
}
//修改指定联系人信息
void change(list *people){
	printf("输入你被修改的联系人:");
	char s[50];
	scanf("%s", s);
	for (int i = 0; i < 1000; i++){
		if (searchfor(people[i], s)){
			printf("\n请输入修改后的内容");
			add(&(people[i]));
			break;
		}
	}
}
////清空所有联系人
//void clear(list *people){
//	printf("是否要清空所有联系人? Y or N\n");
//	
//}
int main()
{
	//添加信息
	list people[1000];
	for (int i = 0; i < 5; i++){
		add(&(people[i]));
	}
	printf("\n");
	

	return 0;
}