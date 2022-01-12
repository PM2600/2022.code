#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node* creat_list();
void insert_list(struct Node*, int);
void delete_list(struct Node*, int);
void search_stu(struct Node*, int);
void print_list(struct Node*);
void menu();

struct Node
{
	struct student
	{
		int id;
		char name[4];
		double score[3];
		double average;
	}stu;
	struct Node* Next;
};

void menu()
{
	printf("***************************************\n");
	printf("*******---(1)����ѧ������-------*******\n");
	printf("*******---(2)ɾ��ѧ������-------*******\n");
	printf("*******---(3)��ѯѧ������-------*******\n");
	printf("*******---(4)��ӡѧ��ƽ���ɼ�---*******\n");
	printf("***************************************\n");
}

struct Node* creat_list(int len)
{

	int i = 0;
	int j = 0;
	int sum = 0;
	struct student s;
	struct Node* pHead = (struct Node* )malloc(sizeof(struct Node));//ͷ���

	struct Node* pTail = pHead;
	pTail->Next = NULL;//β���

	for (i = 0; i < len; i++)
	{
		printf("�������%d��ѧ������Ϣ\n", i + 1);
		scanf("%d%s", &s.id, &s.name);
		for (j = 0; j < 3; j++)
		{
			scanf("%lf", &s.score[j]);
		}
		sum = s.score[0] + s.score[1] + s.score[2];
		s.average = sum / 3.0;

		struct Node* pNew = (struct Node*)malloc(sizeof(struct Node));//�½ڵ�
		pNew->stu = s;
		pTail->Next = pNew;
		pNew->Next = NULL;
		pTail = pNew;
	}
	return pHead;
}

void insert_list(struct Node* pHead, int pos)
{
	struct student v;
	int i = 0;
	struct Node* p = pHead;

	while (p != NULL && i < pos - 1)
	{
		p = p->Next;
		++i;
	}

	struct Node* pNew = (struct Node*)malloc(sizeof(struct Node));

	printf("����������ѧ����Ϣ:\n");
	scanf("%d%s", &v.id, &v.name);
	for (int j = 0; j < 3; j++)
	{
		scanf("%lf", &v.score[j]);
	}
	int sum = v.score[0] + v.score[1] + v.score[2];
	v.average = sum / 3.0;

	pNew->stu = v;
	struct Node* q = p->Next;
	p->Next = pNew;
	pNew->Next = q;
}

void delete_list(struct Node* pHead, int pos)
{
	int i = 0;
	struct Node* p = pHead;
	while (p->Next != NULL && i < pos - 1)
	{
		p = p->Next;
		++i;
	}

	struct Node* q = p->Next;
	p->Next = p->Next->Next;
	free(q);
	q = NULL;
}

void search_stu(struct Node* pHead, int num)
{
	int flag = 0;
	struct Node* p = pHead;
	while (p->Next != NULL)
	{
		p = p->Next;
		if (p->stu.id == num)
		{
			flag = 1;
		}
	}
	if (flag)
	{
		printf("ѧ��:%d  ����:%s  �ɼ�:", p->stu.id, p->stu.name);
		int i = 0;
		for (i = 0; i < 3; i++)
		{
			printf("%lf  ", p->stu.score[i]);
		}
		printf("\nƽ���ɼ�:%lf\n", p->stu.average);
	}
	else
		printf("δ�ҵ���ѧ��\n");
}

void print_list(struct Node* pHead)
{
	struct Node* p = pHead->Next;
	int i = 0;
	
	while (p != NULL)
	{
		printf("%s��ƽ���ɼ�:%lf\n", p->stu.name, p->stu.average);
		p = p->Next;
	}
}

int main()
{
	int len = 0;
	int pos = 0;
	int num = 0;
	//printf("������ѧ������:");
	scanf("%d", &len);

	struct Node* pHead = creat_list(len);//��������
	menu();
	int flag = 0;
	scanf("%d", &flag);
	while (flag != -1)
	{
		switch (flag)
		{
			case 1:
			{
				printf("���������ѧ����λ��:");
				scanf("%d", &pos);
				insert_list(pHead, pos, len);
				break;//��������
			}
			case 2:
			{
				printf("������ɾ��ѧ����λ��:");
				scanf("%d", &pos);
				delete_list(pHead, pos, len);//ɾ������
				break;
			}
			case 3:
			{
				//printf("����������ѯѧ����ѧ��:");
				scanf("%d", &num);
				search_stu(pHead, num);//��ѯ����
				break;
			}
			case 4:
			{
				print_list(pHead);
				break;//��ӡ
			}
			default:
			{
				printf("�����������������\n");
				break;
			}
		}
		menu();
		scanf("%d", &flag);
	}
	return 0;
}
