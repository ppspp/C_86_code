#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��
typedef struct person{
	char Name[1000];
	int Sex;
	int Age;
	char Num[12000];
	char Address[32000];
}list;
//�����ϵ��
void add(list *people){ 
	printf("�������û�����:");
	scanf("%s", people->Name);
	printf("\n�������û��Ա�1.�� �� 2.Ů ����");
	scanf("%d", &(people->Sex));
	printf("\n�������û�����:");
	scanf("%d", &(people->Age));
	printf("\n�������û��ĵ绰���룺");
	scanf("%s", people->Num);
	printf("\n�������û��ĵ�ַ:");
	scanf("%s", people->Address);
}
//����ָ����ϵ�ˣ����ڵĻ�����1
int searchfor(list people, char *s){
	if (strcmp(people.Name, s) == 0){
		return 1;
	}
	else{
		return 0;
	}
}
//��ӡ����
void showlist(list people){
		if (strcmp(people.Name, "NULL") == 0) {
			return;
		}
		printf("\n������%s", people.Name);
		if (people.Sex == 1){
			printf("\n�Ա�: ��");
		}
		else{
			printf("\n�Ա�: Ů");
		}
		printf("\n���䣺%d", people.Age);
		printf("\n�绰���룺%s", people.Num);
		printf("\n��ַ��%s", people.Address);
}
//ɾ��ָ����ϵ��
void delete(list *people){
	printf("����Ҫɾ����ϵ�˵�������");
	char n[50] = {0};
	scanf("%s",n);
	for (int i = 0; i < 1000; i++){
		if (searchfor(people[i], n)){
			strcpy(people[i].Name, "NULL");
			printf("��ɾ��\n");
			return;
		}
	}
	printf("û�������");
}
//�޸�ָ����ϵ����Ϣ
void change(list *people){
	printf("�����㱻�޸ĵ���ϵ��:");
	char s[50];
	scanf("%s", s);
	for (int i = 0; i < 1000; i++){
		if (searchfor(people[i], s)){
			printf("\n�������޸ĺ������");
			add(&(people[i]));
			break;
		}
	}
}
////���������ϵ��
//void clear(list *people){
//	printf("�Ƿ�Ҫ���������ϵ��? Y or N\n");
//	
//}
int main()
{
	//�����Ϣ
	list people[1000];
	for (int i = 0; i < 5; i++){
		add(&(people[i]));
	}
	printf("\n");
	

	return 0;
}