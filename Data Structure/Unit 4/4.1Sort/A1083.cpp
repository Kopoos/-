#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student {
	char name[11];
	char ID[11];
	int grade;
}stu[50];

bool cmp(Student a, Student b)
{
	return a.grade > b.grade;
}

int main()
{
	int num;
	int grade1, grade2;
	bool flag = false;
	scanf("%d", &num);
	int i;
	for (i = 0; i < num; i++) {
		scanf("%s %s %d", stu[i].name, stu[i].ID, &stu[i].grade);
	}
	scanf("%d %d", &grade1, &grade2);
	sort(stu, stu + num, cmp);
	for (i = 0; i < num; i++)
	{
		if (stu[i].grade >= grade1 && stu[i].grade <= grade2) {
			flag = true;
			printf("%s %s\n", stu[i].name, stu[i].ID, stu[i].grade);
		}
			
	}
	if (flag == false)printf("NONE");

}