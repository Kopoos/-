#include<cstdio>
#include<algorithm>
using namespace std;

struct Student {
	int id;				//���6λ����id 
	int grade[4];		//���4������ 
}stu[2010];

char course[4] = { 'A','C','M','E' };	//�����ȼ���˳�����
int Rank[10000000][4] = { 0 };			//Ϊ4�ſ���Ӧѧ�������� 
int now; 							//��������cmp��������ʾ��ǰ��now�ŷ����ݼ����� 

bool cmp(Student a, Student b)
{
	return a.grade[now] > b.grade[now];
}

int main()
{
	int n, m;		//¼���������ʵ���� 
	scanf("%d%d", &n, &m);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
	}
	for (now = 0; now < 4; now++)	//ö��A��C��E��M
	{
		sort(stu, stu + n, cmp);		//�����꽫���е����ݽ�������
		Rank[stu[0].id][now] = 1;		//��������ߵ�����Ϊ1
		for (i = 1; i < n; i++)		//����ʣ�µ�ѧ��
		{
			if (stu[i].grade[now] == stu[i - 1].grade[now]) Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];	//������ͬ
			else Rank[stu[i].id][now] = i + 1;		//����Ϊ����������������
		}
	}

	int query[m];		//��ѯ�Ŀ���ID
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &query[i]);

	}
	for (i = 0; i < m; i++)
	{

		if (Rank[query[i]][0] == 0)printf("N/A\n");
		else {
			k = 0;
			for (int j = 0; j < 4; j++)
			{
				if (Rank[query[i]][j] < Rank[query[i]][k])k = j;
			}
			printf("%d %c\n", Rank[query[i]][k], course[k]);
		}
	}
	return 0;
}