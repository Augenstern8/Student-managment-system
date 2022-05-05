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
	printf("学号：%d  年龄：%d  姓名：%s\n",curp->stuId,curp->stuAge,curp->stuName);
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
 	printf("请输入学号：",&nodep->stuId);
 	scanf("%d",&nodep->stuId);
 	printf("请输入年龄：",&nodep->stuAge);
 	scanf("%d",&nodep->stuAge);
 	printf("请输入姓名：",&nodep->stuName);
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
	 printf("添加成功！\n");
 }
 
 void findStudent()
 {
 	printf("请输入想要查询的学生学号：");
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
	  	printf("没有这个学生!\n"); 
	  }
 }
 void printStudent()
 {
 	if(headp==NULL)
 	{
 		printf("当前没有学生!\n");
	 }
	 else
	 {
	 	printLinkedList(headp);
	 }
 	
 }
 
 void deleteStudent()
 {
 	printf("请输入想要删除学生的学号：");
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
	 		printf("删除完毕!\n");
	 		return;
		 }
		 else
		 {
		 	prep=curp;
		 	curp=curp->next;
		 	
		 }
	 }
	
	printf("该学生不存在！\n"); 
 }

 int main()
 {
 	printf("欢迎使用建议学生信息系统(●ˇˇ●)\n\n");
	printf("按1添加学生信息：\n");
	printf("按2查询学生信息:\n"); 
	printf("按3打印所有学生信息:\n"); 
	printf("按4删除学生信息:\n");
	printf("按5退出程序。\n\n") ;
	printf("请输入操作数：\n"); 
	
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

