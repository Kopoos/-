#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    vector<int>vi;
    for(int i=1;i<=5;i++)
    {
        vi.push_back(i);       //push_back(x)就是在vector后面添加一个元素x
        vi.pop_back();        //删除vi的尾元素
    }
    vector<int>::iterator it=vi.begin();       //iterator为迭代器，定义了一个it的指针;vi.begin()为取vi的首地址
    for(int i=0;i<5;i++){
        printf("%d",*(it+i));       //输出vi[i]
    } 
    return 0;
}

