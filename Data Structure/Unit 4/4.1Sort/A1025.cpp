#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Student {
	char id[14];		//准考证号 
	int score;			//分数 
	int location_number, local_rank;		//考场名和考场排名 
}stu[30010];
bool cmp(Student a, Student b)
{
	if (a.score != b.score)return a.score > b.score;	//从大到小排分数 
	else return strcmp(a.id, b.id) < 0;		//从小到大进行准考证号排名 
}
int main()
{
	int n, k, num = 0;		//num为总考生数
	scanf("%d", &n);		//n为考场数
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);		//该考场人数 
		for (int j = 0; j < k; j++) {
			scanf("%s %d/n", &stu[num].id, &stu[num].score);
			num++;
			stu[num].location_number = i;		//将该考场的考生号为i
		}
		sort(stu + num - k, stu + num, cmp);	//将该考场的考生排序
		stu[num - k].local_rank = 1;			//将该考场的第一名考场排名记为1 
		for (int j = num - k + 1; j < num; j++) {//对该考场剩余的考生
			if (stu[j].score == stu[j - 1].score) {
				stu[j].local_rank = stu[j - 1].local_rank;
			}
			else {
				stu[j].local_rank = j + 1 - (num - k);
			}
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	int r = 1;
	for (int i = 0; i < num; i++)
	{
		if (i > 0 && stu[i].score != stu[i - 1].score) {
			r = i + 1;
		}
		printf("%s", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
}