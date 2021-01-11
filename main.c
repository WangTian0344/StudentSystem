#include <stdio.h>
#include <string.h>
#define A 30
#define N 20
int menu(void);
void Input(long number[],char name[][N],float score[],int n);
void SumAverage(float score[],int n);
void ScoreMaxtoMin(float score[],char name[][N],long number[],int n);
void ScoreMintoMax(float score[],char name[][N],long number[],int n);
void NumberMintoMax(long number[],char name[][N],float score[],int n);
void SearchNumber(long number[],char name[][N],float score[],int order[],int n,long x);
void Sort(float score[],int n);
void Output(long number[],char name[][N],float score[],int n);
void orderbyname(long number[],char name[][N],float score[],int n);
void change(long number[],char name[][N],float score[],int k,int i);
void SearchbyName(long number[],char name[][N],float score[],int order[],int n);
void Orderoo(float score[],int n,int order[]);
int main()
{
    long number[A],x;
    float score[A];
    char name[A][N];
    int order[A];
    int n,m;
    int selected;
    printf("Input student number:");//ȷ��ѧ������
    while(1)
    {
        m=scanf("%d",&n);
        if(m==1&&n>0&&n<=30)
        {
            while(1)
            {
                selected=menu();//����ѡ��Ĺ���
                switch (selected)
                {
                case 1:
                {
                    Input(number,name,score,n);
                    Orderoo(score,n,order);//����ѧ�źͳɼ�
                    break;
                }
                case 2:
                {
                    SumAverage(score,n);//�����ֺܷ�ƽ��ֵ
                    break;
                }
                case 3:
                {
                    //���ɼ��ɴ�С����
                    printf("\nSort in ascending order by score:\n");
                    Output(number,name,score,n);
                    break;
                }
                case 4://���ɼ���С��������
                {
                    ScoreMintoMax(score,name,number,n);//���ɼ���С��������
                    printf("\nSort in ascending order by score:\n");
                    Output(number,name,score,n);
                    break;
                }
                case 5:
                {
                    NumberMintoMax(number,name,score,n);//��ѧ����С��������
                    printf("\nSort in ascending order by number:\n");
                    Output(number,name,score,n);
                    break;
                }
                case 6://�������ֵ�˳���ɳ��ɼ���
                {
                    orderbyname(number,name,score,n);
                    printf("\nSort in dictionary order by name:\n");
                    Output(number,name,score,n);
                    break;
                }
                case 7:
                {
                    ScoreMintoMax(score,name,number,n);
                    printf("Please input the number you want to find:\n");
                    scanf("%ld",&x);
                    SearchNumber(number,name,score,order,n,x);//����ѧ�Ų��ҳɼ�
                    break;
                }
                case 8://��������ѯѧ�������Ϳ��Գɼ�
                {
                    ScoreMaxtoMin(score,name,number,n);
                    orderbyname(number,name,score,n);
                    SearchbyName(number,name,score,order,n);
                    break;
                }
                case 9:
                {
                    Sort(score,n);//���ɼ�����
                    break;
                }
                case 10:
                {
                    Output(number,name,score,n);//���ѧ�ţ������ͳɼ�
                    break;
                }
                case 0:
                {
                    printf("\nEnd of program!\n");//��������
                    exit(0);
                }
                default :
                    printf("Input Error!\n");
                }
            }
            break;
        }
        else
        {
            getchar();
            printf("\nInput Error!\nPlease try again.\n");
            printf("Input student number:");
        }
    }

    return 0;
}
//�������ܣ�����˵����沢���û�������ѡ�������
int menu(void)
{
    int a;
    printf("\n1.Input record\n");
    printf("2.Caculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sort in ascending order by score\n");
    printf("5.Sort in ascending order bu number\n");
    printf("6.Sort in dictionary order by name\n");
    printf("7.Search by number\n");
    printf("8.Search by name\n");
    printf("9.Statistic analysis\n");
    printf("10.List record\n");
    printf("0.Exit\n");
    printf("Please Input your choice(��һ��ѡ��ʱ����ѡ1):");
    scanf("%d",&a);
    return a;
}
void Orderoo(float score[],int n,int order[])
{
    int temp1;
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=k+1; j<n; j++)
        {
            if(score[j]>score[k])
                k=j;
        }
        if(k!=i)
        {
            temp1=score[k];//�����ɼ�
            score[k]=score[i];
            score[i]=temp1;
        }
    }
    for(i=0; i<n; i++)
    {
        order[i]=i+1;
    }
}
//�������ܣ�����ѧ��,�����ͳɼ�
void Input(long number[],char name[][N],float score[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nPlease input number ,name and score(0<=soore<=100)(ѧ�ŨL�����L�ɼ�):\n");
        scanf("%ld",&number[i]);
        getchar();
        gets(name[i]);
        scanf("%f",&score[i]);
        if(score[i]>100||score[i]<0)//���û�����ĳɼ�����100��С��0ʱ��������
        {
            printf("\nThe score is wrong.Please try again!\n");
            i=i-1;
            continue;
        }
    }
    printf("Input End.\n");
}
//�������ܣ�����γ��ֺܷ�ƽ����
void SumAverage(float score[],int n)
{
    int i,sum=0;
    float aver;
    for(i=0; i<n; i++)
    {
        sum+=score[i];
    }
    aver=sum*1.0/n;
    printf("\nsum=%d average=%.2f\n",sum,aver);
}
//�������ܣ����ɼ��ɸߵ����ų����α�
void ScoreMaxtoMin(float score[],char name[][N],long number[],int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=k+1; j<n; j++)
        {
            if(score[j]>score[k])
                k=j;
        }
        if(k!=i)
        {
            change(number,name,score,k,i);
        }
    }
}
//��������:���ɼ��ɵ͵����ų����α�
void ScoreMintoMax(float score[],char name[][N],long number[],int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=k+1; j<n; j++)
        {
            if(score[j]<score[k])
                k=j;
        }
        if(k!=i)
        {
            change(number,name,score,k,i);
        }
    }
}
//�������ܣ���ѧ����С�����ų��ɼ���
void NumberMintoMax(long number[],char name[][N],float score[],int n)
{
    int i,j,k;
    for(i=0; i<n; i++)
    {
        k=i;
        for(j=k+1; j<n; j++)
        {
            if(number[j]<number[k])
                k=j;
        }
        if(k!=i)
        {
            change(number,name,score,k,i);
        }
    }
}
//�������ܣ�����ѧ�ţ������ͳɼ�
void change(long number[],char name[][N],float score[],int k,int i)
{
    int temp1,temp2;
    char chartemp[N];
    temp1=score[k];//�����ɼ�
    score[k]=score[i];
    score[i]=temp1;
    temp2=number[k];//����ѧ��
    number[k]=number[i];
    number[i]=temp2;
    strcpy(chartemp,name[k]);//��������
    strcpy(name[k],name[i]);
    strcpy(name[i],chartemp);
}
//�������ܣ����������ֵ�˳���ų��ɼ�
void orderbyname(long number[],char name[][N],float score[],int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        {
            if(strcmp(name[j],name[i])<0)
            {
                change(number,name,score,j,i);//�������ܣ�����ѧ�ţ������ͳɼ�
            }
        }
}
//�������ܣ���ѧ�Ų�ѯѧ�������Ϳ��Գɼ� �۰����
void SearchNumber(long number[],char name[][N],float score[],int order[],int n,long x)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(x>number[mid])
            low=mid+1;
        else if(x<number[mid])
            high=mid-1;
        else
        {
            printf("\norder:%d name:%s score:%.0f\n",order[mid],name[mid],score[mid]);
            return;
        }
    }
    printf("\nNot found!\n");
}
//�������ܣ����������ҳɼ�
void SearchbyName(long number[],char name[][N],float score[],int order[],int n)
{
    int i=0,j=n-1,k;
    char sname[N];
    printf("\nPlease input the name you want to find:\n");
    getchar();
    gets(sname);
    while(i<=j)
    {
        k=(i+j)/2;
        if(strcasecmp(sname,name[k])>0)
            i=k+1;
        else if(strcasecmp(sname,name[i])<0)
            j=k-1;
        else
        {
            printf("\norder:%d number:%ld score:%.2f\n",order[i],number[i],score[i]);
            return ;
        }
    }
    printf("\nNot found!\n");
}
/*�������ܣ������㣨90-100�������ã�80-89�����еȣ�70-79��������60-69����������0-59��
ͳ��ÿ��������������ռ�ٷֱ�*/
void Sort(float score[],int n)
{
    int i,a=0,b=0,c=0,d=0,e=0;
    for(i=0; i<n; i++)
    {
        if(score[i]>=90&&score[i]<=100)
            a++;
        else if(score[i]>=80)
            b++;
        else if(score[i]>=70)
            c++;
        else if(score[i]>=60)
            d++;
        else if(score[i]>=0)
            e++;
    }
    printf("\n���㣨90-100��������%d �����ʣ�%.2f%%\n",a,a*1.0/n*100);
    printf("\n���ã�80-89��������%d �����ʣ�%.2f%%\n",b,b*1.0/n*100);
    printf("\n�еȣ�70-79��������%d �е��ʣ�%.2f%%\n",c,c*1.0/n*100);
    printf("\n����60-69��������%d �����ʣ�%.2f%%\n",d,d*1.0/n*100);
    printf("\n������0-59��������%d �������ʣ�%.2f%%\n",e,e*1.0/n*100);
}
//�������ܣ����ÿ��ѧ����ѧ�ţ����Գɼ�
void Output(long number[],char name[][N],float score[],int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("\nnumber:%ld name:%s score:%.2f\n",number[i],name[i],score[i]);
}
