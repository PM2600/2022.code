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
	printf("*******---(1)插入学生数据-------*******\n");
	printf("*******---(2)删除学生数据-------*******\n");
	printf("*******---(3)查询学生数据-------*******\n");
	printf("*******---(4)打印学生平均成绩---*******\n");
	printf("***************************************\n");
}

struct Node* creat_list(int len)
{

	int i = 0;
	int j = 0;
	int sum = 0;
	struct student s;
	struct Node* pHead = (struct Node* )malloc(sizeof(struct Node));//头结点

	struct Node* pTail = pHead;
	pTail->Next = NULL;//尾结点

	for (i = 0; i < len; i++)
	{
		printf("请输入第%d个学生的信息\n", i + 1);
		scanf("%d%s", &s.id, &s.name);
		for (j = 0; j < 3; j++)
		{
			scanf("%lf", &s.score[j]);
		}
		sum = s.score[0] + s.score[1] + s.score[2];
		s.average = sum / 3.0;

		struct Node* pNew = (struct Node*)malloc(sizeof(struct Node));//新节点
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

	printf("输入所插入学生信息:\n");
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
		printf("学号:%d  姓名:%s  成绩:", p->stu.id, p->stu.name);
		int i = 0;
		for (i = 0; i < 3; i++)
		{
			printf("%lf  ", p->stu.score[i]);
		}
		printf("\n平均成绩:%lf\n", p->stu.average);
	}
	else
		printf("未找到此学生\n");
}

void print_list(struct Node* pHead)
{
	struct Node* p = pHead->Next;
	int i = 0;
	
	while (p != NULL)
	{
		printf("%s的平均成绩:%lf\n", p->stu.name, p->stu.average);
		p = p->Next;
	}
}

int main()
{
	int len = 0;
	int pos = 0;
	int num = 0;
	//printf("请输入学生个数:");
	scanf("%d", &len);

	struct Node* pHead = creat_list(len);//创建链表
	menu();
	int flag = 0;
	scanf("%d", &flag);
	while (flag != -1)
	{
		switch (flag)
		{
			case 1:
			{
				printf("请输入插入学生的位置:");
				scanf("%d", &pos);
				insert_list(pHead, pos, len);
				break;//插入数据
			}
			case 2:
			{
				printf("请输入删除学生的位置:");
				scanf("%d", &pos);
				delete_list(pHead, pos, len);//删除数据
				break;
			}
			case 3:
			{
				//printf("请输入所查询学生的学号:");
				scanf("%d", &num);
				search_stu(pHead, num);//查询数据
				break;
			}
			case 4:
			{
				print_list(pHead);
				break;//打印
			}
			default:
			{
				printf("输入错误，请重新输入\n");
				break;
			}
		}
		menu();
		scanf("%d", &flag);
	}
	return 0;
}
