#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student {
	int ID;
	char name[9];
	int grade;
	int flag;
}stu[100000];

int flag;

bool cmp(Student a, Student b)
{
	int s;
	if (flag == 1)return a.ID < b.ID;
	else if (flag == 2) {
		s=strcmp(a.name, b.name);
		if (s != 0)return s < 0;
		else return a.ID < b.ID;
		}
	else {
		if (a.grade != b.grade)return a.grade < b.grade;
		else return a.ID < b.ID;
	}
}

int main()
{
	int N, C;
	scanf("%d %d\n", &N, &C);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s %d", &stu[i].ID, stu[i].name, &stu[i].grade);
	}
	flag = C;
	sort(stu, stu + N, cmp);
	for (int i = 0; i < N; i++) {
		printf("%06d %s %d\n", stu[i].ID, stu[i].name, stu[i].grade);
	}
	

}