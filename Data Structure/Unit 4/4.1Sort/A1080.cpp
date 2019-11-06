#include<cstdio>
#include<algorithm>
using namespace std;

struct Student {
	int GE, GI, sum;		//���Գɼ������Գɼ������ܳɼ��ܺ�
	int r, stuID;			//�������������
	int cho[6];				//K��ѡ��ѧУ�ı��
}stu[40010];

struct School {
	int quota;				//���������ܶ��
	int stuNum;				//��ǰʵ����������
	int id[40010];			//������ѧ�����
	int lastAdmit;			//��¼���һ�����յ�ѧ�����
}sch[110];

bool cmpStu(Student a, Student b)
{
	if (a.sum != b.sum)return a.sum > b.sum;	//���ִܷӸߵ�������
	else return a.GE > b.GE;					//�ܷ���ͬ����GE�Ӹߵ�������
}

bool cmpID(int a, int b)
{
	return stu[a].stuID < stu[b].stuID;			//��������Ŵ�С��������
}

int main()
{
	int n, m, k;				
	scanf("%d%d%d", & n, & m, & k);		//����������ѧУ����ÿ���˿������ѧУ��
	for (int i = 0; i < m; i++) {		//��ʼ��ÿ��ѧУ
		scanf("%d", &sch[i].quota);		//�������������ܶ��	
		sch[i].stuNum = 0;				//��ǰʵ����������Ϊ0
		sch[i].lastAdmit = -1;			//���һ�������յ�ѧ�����Ϊ-1����ʾ������
	}
	for (int i = 0; i < n; i++)	{		//��ʼ��ÿ������
		stu[i].stuID = i;				//�������Ϊi
		scanf("%d%d", &stu[i].GE, &stu[i].GI);		//���Գɼ������Գɼ�
		stu[i].sum = stu[i].GE + stu[i].GI;			//�ܳɼ�
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &stu[i].cho[j]);			//k��������ѧУ���
		}
	}
	sort(stu, stu + n, cmpStu);						//��nλ�������ɼ�����
	for (int i = 0; i < n; i++){					//����ÿ������������
	
		if (i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE) {
			stu[i].r = stu[i - 1].r;
		}
		else {
			stu[i].r = i;
		}
	}
	for (int i = 0; i < n; i++){					//��ÿ������i,�ж��䱻����ѧУ¼ȡ
	
		for (int j = 0; j < k; j++) {				//ö�ٿ���i��k��ѡ��ѧУ
			int choice = stu[i].cho[j];				//����i�ĵ�j��ѡ��ѧУ���
			int num = sch[choice].stuNum;			//ѡ��ѧУ�ĵ�ǰ��������
			int last = sch[choice].lastAdmit;		//ѡ��ѧУ�����һλ¼ȡ�������
			//�������δ�����ѧУ���һ��¼ȡ�Ŀ����뵱ǰ������������ͬ
			if (num < sch[choice].quota || (last != -1 && stu[i].r == stu[last].r)) {
				sch[choice].id[num] = i;			//¼ȡ�ÿ���
				sch[choice].lastAdmit = i;			//��ѧУ�����һ��¼ȡ����Ϊi
				sch[choice].stuNum++;				//��ǰ����������1
				break;
			}
		}
	}
	for (int i = 0; i < m; i++)						//��m��ѧУ
	{
		if (sch[i].stuNum > 0) {						//������е�ѧ��
			//��ID�Ӵ�С����
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
			for (int j = 0; j <sch[i].stuNum; j++)
			{
				printf("%d", stu[sch[i].id[j]].stuID);
				if (j < sch[i].stuNum - 1) {
					printf(" ");
				}
			}

		}
		printf("\n");
	}
	return 0;
}