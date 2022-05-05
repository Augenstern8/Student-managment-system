#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	int stuId;
	int stuAge;
	char stuName[100];
	
	
	struct student*next; 
};

struct student*headp=NULL;
struct student*tailp=NULL;

void printStudent(struct student*curp)
{
	printf("ѧ�ţ�%d  ���䣺%d  ������%s\n",curp->stuId,curp->stuAge,curp->stuName);
}

void printLinkedList(struct student*headp)
{
	while(headp!=NULL)
	{
		printStudent(headp);
		headp=headp->next;
	}
 } 
 
 void addStudent()
 {
 	struct student*nodep=(struct student*)malloc(sizeof(struct student));
 	printf("������ѧ�ţ�",&nodep->stuId);
 	scanf("%d",&nodep->stuId);
 	printf("���������䣺",&nodep->stuAge);
 	scanf("%d",&nodep->stuAge);
 	printf("������������",&nodep->stuName);
 	scanf("%s",&nodep->stuName);
 	nodep->next=NULL;
 	
 	if(headp==NULL)
 	{
 		headp=nodep;
 		tailp=nodep;
	 }
	 else
	 {
	 	tailp->next=nodep;
		tailp=nodep; 
	 }
	 printf("��ӳɹ���\n");
 }
 
 void findStudent()
 {
 	printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�");
	 int id;
	 scanf("%d",&id);
	 struct student*curp=headp;
	 int flag=0;
	 while(curp!=NULL)
	 {
	 	if(curp->stuId==id)
	 	{
	 		printStudent(curp);
	 		flag=1;
	 		break;
		 }
		 else
		 {
		 	curp=curp->next;
		 }
	  } 
	  if(flag==0)
	  {
	  	printf("û�����ѧ��!\n"); 
	  }
 }
 void printStudent()
 {
 	if(headp==NULL)
 	{
 		printf("��ǰû��ѧ��!\n");
	 }
	 else
	 {
	 	printLinkedList(headp);
	 }
 	
 }
 
 void deleteStudent()
 {
 	printf("��������Ҫɾ��ѧ����ѧ�ţ�");
 	int id;
 	scanf("%d",&id);
 	struct student*curp=headp;
 	if(curp->stuId==id)
 	{
 		headp=headp->next;
 		free(curp);
 		curp=NULL;
 		return;
	 }
	 struct student*prep=curp;
	 curp=curp->next;
	 while(curp!=NULL)
	 {
	 	if(curp->stuId==id)
	 	{
	 		struct student*next=curp->next;
	 		prep->next=next;
	 		free(curp);
	 		curp=NULL;
	 		printf("ɾ�����!\n");
	 		return;
		 }
		 else
		 {
		 	prep=curp;
		 	curp=curp->next;
		 	
		 }
	 }
	
	printf("��ѧ�������ڣ�\n"); 
 }

 int main()
 {
 	printf("��ӭʹ�ý���ѧ����Ϣϵͳ(�񡦡���)\n\n");
	printf("��1���ѧ����Ϣ��\n");
	printf("��2��ѯѧ����Ϣ:\n"); 
	printf("��3��ӡ����ѧ����Ϣ:\n"); 
	printf("��4ɾ��ѧ����Ϣ:\n");
	printf("��5�˳�����\n\n") ;
	printf("�������������\n"); 
	
	while(1)
	{
		char c;
		scanf("%c",&c);
		switch(c)
		{
			case '1':
				addStudent();
				break;
			case '2':
				findStudent();
				break;
			case '3':
				printStudent();
				break;
			case '4':
				deleteStudent();
				break;
			case '5':
			exit(0);
			default:
				break;
		}
	}
	return 0;
 }

