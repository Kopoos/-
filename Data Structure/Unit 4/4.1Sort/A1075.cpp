#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10010;

struct Student {
	int id;						//׼��֤��
	int score[6];				//ÿ����ĵ÷�
	bool flag;					//�Ƿ�����ͨ��������ύ	
	int score_all;				//�ܷ�
	int solve;					//�����Ľ�����Ŀ
}stu[maxn];

int n, k, m;
int full[6];					//û���������

bool cmp(Student a, Student b)	//������
{
	if (a.score_all != b.score_all)return a.score_all > b.score_all;
	else if (a.solve != b.solve)return a.solve > b.solve;
	else return a.id < b.id;
}

void init()						//��ʼ������
{
	for (int i = 0; i <= n; i++)
	{
		stu[i].id = i;			//׼��֤�ż�Ϊi
		stu[i].score_all = 0;	//�ֳܷ�ʼ��Ϊ0
		stu[i].solve = 0;		//������������ʼ��Ϊ0
		stu[i].flag = false;	//��ʼ��Ϊû����ͨ���ı����ύ
		memset(stu[i].score, -1, sizeof(stu[i].score));		//��Ŀ�ĵ÷�Ϊ-1
	}
}

int main()
{
	scanf("%d%d%d", &n, &k, &m);		//ʹ���ߵ��������������������ύ������
	init();
	for (int i = 1; i <= k; i++)		//��¼ÿ����Ŀ���ֵķ�ֵ
	{
		scanf("%d", &full[i]);
	}
	int u_id, p_id, score_obtained;		//����ID����ĿID������õķ���
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u_id, &p_id, &score_obtained);
		if (score_obtained != -1) {		//�����Ǳ��������ÿ�������ͨ��������ύ
			stu[u_id].flag = true;
		}
		if (score_obtained == -1 && stu[u_id].score[p_id] == -1){
			//ĳ��ĵ�һ�α��뷢�����󣬷�ֵ��Ϊ0���������
			stu[u_id].score[p_id] = 0;
		}
		if (score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id]){
			stu[u_id].solve++;			//ĳ���һ�λ��������������������1
		}
		if (score_obtained > stu[u_id].score[p_id]) {
			stu[u_id].score[p_id] = score_obtained;		//ĳ���ø��ߵķ������򸲸�
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] != -1) {		//�����ܷ�
				stu[i].score_all += stu[i].score[j];
			}
		}
	}
	sort(stu + 1, stu + n + 1, cmp);			//��Ҫ������
	int r = 1;						//��ǰ����
	for (int i = 1; i <= n && stu[i].flag == true; i++) {
		if (i > 1 && stu[i].score_all != stu[i - 1].score_all) {
			//��ǰ������������ǰһλ�����������������ڸÿ���֮ǰ���ܿ�����
			r = i;
		}
		printf("%d %05d %d", r, stu[i].id, stu[i].score_all);
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] == -1) {
				printf(" -");		//û���ύ��
			}
			else {
				printf(" %d", stu[i].score[j]);
			}
		}
		printf("\n");
	}
	return 0;


}
