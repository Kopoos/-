#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student {
	char id[10];
	int de;
	int cai;
	int flag;
	int sum;
}stu[100010];
bool cmp(Student a, Student b)
{
	if (a.flag != b.flag)return a.flag < b.flag;
	else if (a.sum != b.sum)return a.sum > b.sum;
	else if (a.de != b.de)return a.de > b.de;
	else return strcmp(a.id, b.id) < 0;
}
int main()
{
	int N, L, H;
	int count;
	scanf("%d %d %d", &N, &L, &H);		//N为考生总数，L为录取最低分，H为优先录取线
	int i;
	count = N;
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;
		if (stu[i].de >= H && stu[i].cai >= H)stu[i].flag = 1;
		else if (stu[i].de >= H && stu[i].cai >= L)stu[i].flag = 2;
		else if (stu[i].de >= L && stu[i].cai >= L && stu[i].de >= stu[i].cai)stu[i].flag = 3;
		else if (stu[i].de >= L && stu[i].cai >= L)stu[i].flag = 4;
		else {
			stu[i].flag = 5; count--;
		}

	}
	sort(stu, stu + N, cmp);
	printf("%d\n", count);
	for (i = 0; i < count; i++)
	{

		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}

}