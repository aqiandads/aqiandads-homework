#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MaxSize 50001
typedef int KeyType;
void swap(KeyType &x,KeyType &y)
{KeyType tmp=x;
x=y;y=tmp;
}
void initial(int R[],int low,int high)
{  int i;
srand((unsigned)time(NULL));
for(i=low;i<high;i++)
R[i]=rand()%99+1;
}
void copy(int R[],int R1[],int n)
{  for(int i=0;i<n;i++)
R1[i]=R[i];
}
void copy1(int R[],int R1[],int n)
{  for(int i=0;i<n;i++)
R1[i+1]=R[i];
}
bool test(KeyType R[],int low,int high)
{  int i;
for(i=low;i<high-1;i++)
if(R[i]>R[i+1])
return false;
return true;
}
//-------ֱ�Ӳ�������--
void InsertSort(KeyType R[],int n)
{  int i,j;KeyType tmp;
for(i=1;i<n;i++)
{  if(R[i]<R[i-1])
{  tmp=R[i];
j=i-1;
do
{  R[j+1]=R[j];
j--;
}while (j>=0 &&R[j]>tmp);
R[j+1]=tmp;
}
}
}
void InsertSortTime(KeyType R[],int n)
//��ֱ�Ӳ��������ʱ��
{clock_t t;
printf("ֱ�Ӳ�������\t");
t=clock();
InsertSort(R,n);
t=clock()-t;
printf("%lf��",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
printf("\t��ȷ\n");
else
printf("\t����\n");
}
void BinInsertSort(KeyType R[],int n)
{  int i,j,low,high,mid;
KeyType tmp;
for(i=1;i<n;i++)
{  if(R[i]<R[i-1])
//����ʱ//��R[i]���浽tmp��
{  tmp=R[i];
low =0;high=i-1;
while(low<=high)
//��R[low..high]�в��Ҳ����λ��//ȡ�м�λ��
{  mid=(low+high)/2;
if(tmp<R[mid])
high=mid-1;
//������������
else
low=mid+1;
//��������Ұ���
}
//��λ��high
for(j=i-1;j>=high+1;j--)
//���н���Ԫ�غ���
R[j+1]=R[j];
R[high+1]=tmp;
//����tmp
}
}
}
void BinInsertSortTime(KeyType R[],int n)
//���۰���������ʱ��
{  clock_t t;
printf("�۰��������\t");
t=clock();
BinInsertSort(R,n);
t=clock()-t;
printf("%lf��",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
//��������ȷ����֤
printf("\t��ȷ\n");
else
printf("\t����\n");
}
void ShellSort(KeyType R[],int n)
{  int i,j,d;
KeyType tmp;
d=n/2;
while(d>0)
{  for(i=d;i<n;i++)
{  tmp=R[i];
j=i-d;
while(j>=0 &&tmp<R[j])
{  R[j+d]=R[j];
j=j-d;
}
R[j+d]=tmp;
}
d=d/2;
}
}
void ShellSortTime(KeyType R[],int n)
{  clock_t t;
printf("ϣ������\t");
t=clock();
ShellSort(R,n);
t=clock()-t;
printf("%lf��",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
//��������ȷ����֤
printf("\t��ȷ\n");
else
printf("\t����\n");
}
//--------ð�������㷨--
void BubbleSort(KeyType R[],int n)
{  int i,j;
bool exchange;
for(i=0;i<n-1;i++)
{  exchange=false;
//һ��ǰexchange��Ϊ��//��λR[i],ѭ��n-i-1��//��������Ԫ�ط���ʱ
for(j=n-1;j>i;j--)
if(R[j]<R[j-1])
{  swap(R[j],R[j-1]);
//��R[j]��R[j-1]����Ԫ�ؽ���//һ���н�����exchange��Ϊ��
exchange =true;
}
if(!exchange)
//����û�з�����������;�����㷨
return;
}
}
void BubbleSortTime(KeyType R[],int n)
{  clock_t t;
printf("ð������\t");t=clock();BubbleSort(R,n);t=clock()-t;
printf("%lf��",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
printf("\t��ȷ\n");
else printf("\t����\n");
}
//--------���������㷨--
int partition(KeyType R[],int s,int t)
{  int i=s,j=t;
KeyType tmp=R[i];
//��R[i]Ϊ��׼//�����˽������м�ɨ�裬ֱ��i=jΪֹ
while(i<j)
{  while(j>i&&R[j]>=tmp)
j--;
//��������ɨ�裬��һ��С��tmp��R[j]//�ҵ�������R[j],����R[i]��
R[i]=R[j];
while(i<j&&R[i]<=tmp)
i++;
//��������ɨ�裬��һ������tmp��R[i]//�ҵ�������R[i],����R[j]��
R[j]=R[i];
}
R[i]=tmp;
return i;
}
void QuickSort(KeyType R[],int s,int t)
{  int i;
if(s<t)
{  i=partition(R,s,t);
QuickSort(R,s,i-1);
//��������ݹ�����
QuickSort(R,i+1,t);
//��������ݹ�����
}
}
void QuickSortTime(KeyType R[],int n)
//����������㷨��ʱ��
{  clock_t t;
printf("��������\t");
t=clock();
QuickSort(R,0,n-1);
t=clock()-t;
printf("%lf��",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
//��������ȷ����֤
printf("\t��ȷ\n");
else
printf("\t����\n");
}
void SelectSort(KeyType R[],int n)
{  int i,j,k;
for(i=0;i<n-1;i++)
//����i������
{  k=i;
for(j=i+1;j<n;j++)
//�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k]
if(R[j]<R[k])
k=j;
//k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��//R[i]��R[k]����Ԫ�ؽ���
if(k!=i)
swap(R[i],R[k]);
}
}
void SelectSortTime(KeyType R[],int n)
//���ѡ�������㷨��ʱ��
{  clock_t t;
printf("��ѡ������\t");t=clock();SelectSort(R,n);t=clock()-t;
printf("%lf��",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))printf("\t��ȷ\n");
else printf("\t����\n");
}
void sift(KeyType R[],int low,int high)
{  int i=low,j=2*i;
//R[j]��R[i]������
KeyType tmp=R[i];
while(j<=high)
{  if(j<high &&R[j]<R[j+1])//���Һ��ӽϴ󣬰�jָ���Һ���
j++;
if(tmp<R[j])
//�������С������ӵĹؼ���//��R[j]������˫�׽��λ����//�޸�i��jֵ���Ա��������ɸѡ
{  R[i]=R[j];
i=j;
j=2*i;
}
else break;
//���������ڵ�������ӹؼ��֣�ɸѡ����//��ɸѡ����������λ����
}
R[i]=tmp;
}
void HeapSort(KeyType R[],int n)
//������
{  int i;
for(i=n/2;i>=1;i--)
//ѭ��������ʼ�ѣ�����sift�㷨n/2��
sift(R,i,n);
for(i=n;i>=2;i--)
//����n-1�����������ÿһ�˶������Ԫ�ظ�����1//�����һ��Ԫ�����R[1]����
{  swap(R[1],R[i]);
sift(R,1,i-1);
//��R[1..i-1]����ɸѡ���õ�i-1�����Ķ�
}
}
void HeapSortTime(KeyType R[],int n)//��������㷨��ʱ��
{  clock_t t;
printf("������\t");
t=clock();
HeapSort(R,n);
t=clock()-t;
printf("        %lf��",((float)t)/CLOCKS_PER_SEC);
if(test(R,1,n))
//��������ȷ����֤
printf("\t��ȷ\n");
else
printf("\t����\n");
}
void Merge(KeyType R[],int low,int mid,int high)
{  KeyType *R1;
int i=low,j=mid+1,k=0;
//k��R1���±꣬i��j�ֱ�Ϊ��1��2�ε��±�
R1=(KeyType *)malloc((high-low+1)*sizeof(KeyType));
//��̬����ռ�
while(i<=mid &&j<=high)
//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
if(R[i]<=R[j])
//����1���е�Ԫ�ط���R1��
{  R1[k]=R[i];
i++;k++;
}
else
//����2���е�Ԫ�ط���R1��
{  R1[k]=R[j];
j++;k++;
}
while(i<=mid)
{  R1[k]=R[i];
i++;k++;
}
while(j<=high)
{  R1[k]=R[j];
j++;k++;
}
for(k=0,i=low;i<=high;k++,i++)
    R[i]=R1[k];
free(R1);
}
void MergePass(KeyType R[],int length,int n)
{  int i;
for(i=0;i+2*length-1<n;i=i+2*length)
Merge(R,i,i+length-1,i+2*length-1);
if(i+length-1<n-1)
Merge(R,i,i+length-1,n-1);
}
void MergeSort(KeyType R[],int n)
{int length;
for(length=1;length<n;length=2*length)
MergePass(R,length,n);
}
void MergeSortTime(KeyType R[],int n)
{  clock_t t;
printf("��·�鲢����\t");
t=clock();
MergeSort(R,n);
t=clock()-t;
printf("%lf��",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
printf("\t��ȷ\n");
else
printf("\t����\n");
}
int main()
{  KeyType R[MaxSize],R1[MaxSize];
printf("�������50000��1-99�����������������򷽷��ıȽ�\n");
int n =50000;
printf("-----------------------------\n");
printf("���򷽷�     ��ʱ      �����֤\n");
printf("-----------------------------\n");
initial(R,0,n-1);
copy(R,R1,n);
InsertSortTime(R1,n);
copy(R,R1,n);
BinInsertSortTime(R1,n);
copy(R,R1,n);
ShellSortTime(R1,n);
copy(R,R1,n);
BubbleSortTime(R1,n);
copy(R,R1,n);
QuickSortTime(R1,n);
copy(R,R1,n);
SelectSortTime(R1,n);copy1(R,R1,n);HeapSortTime(R1,n);
copy(R,R1,n);
MergeSortTime(R1,n);printf("---------\n");
return 1;
}