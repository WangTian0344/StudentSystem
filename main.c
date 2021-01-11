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
    printf("Input student number:");//确定学生人数
    while(1)
    {
        m=scanf("%d",&n);
        if(m==1&&n>0&&n<=30)
        {
            while(1)
            {
                selected=menu();//输入选择的功能
                switch (selected)
                {
                case 1:
                {
                    Input(number,name,score,n);
                    Orderoo(score,n,order);//输入学号和成绩
                    break;
                }
                case 2:
                {
                    SumAverage(score,n);//计算总分和平均值
                    break;
                }
                case 3:
                {
                    //按成绩由大到小排序
                    printf("\nSort in ascending order by score:\n");
                    Output(number,name,score,n);
                    break;
                }
                case 4://按成绩由小到大排序
                {
                    ScoreMintoMax(score,name,number,n);//按成绩由小到大排序
                    printf("\nSort in ascending order by score:\n");
                    Output(number,name,score,n);
                    break;
                }
                case 5:
                {
                    NumberMintoMax(number,name,score,n);//按学号由小到大排序
                    printf("\nSort in ascending order by number:\n");
                    Output(number,name,score,n);
                    break;
                }
                case 6://按姓名字典顺序派出成绩表
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
                    SearchNumber(number,name,score,order,n,x);//输入学号查找成绩
                    break;
                }
                case 8://按姓名查询学生排名和考试成绩
                {
                    ScoreMaxtoMin(score,name,number,n);
                    orderbyname(number,name,score,n);
                    SearchbyName(number,name,score,order,n);
                    break;
                }
                case 9:
                {
                    Sort(score,n);//将成绩分类
                    break;
                }
                case 10:
                {
                    Output(number,name,score,n);//输出学号，姓名和成绩
                    break;
                }
                case 0:
                {
                    printf("\nEnd of program!\n");//结束程序
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
//函数功能：输出菜单界面并且用户输入所选择的序数
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
    printf("Please Input your choice(第一次选择时必须选1):");
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
            temp1=score[k];//交换成绩
            score[k]=score[i];
            score[i]=temp1;
        }
    }
    for(i=0; i<n; i++)
    {
        order[i]=i+1;
    }
}
//函数功能：输入学号,姓名和成绩
void Input(long number[],char name[][N],float score[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nPlease input number ,name and score(0<=soore<=100)(学号↙姓名↙成绩):\n");
        scanf("%ld",&number[i]);
        getchar();
        gets(name[i]);
        scanf("%f",&score[i]);
        if(score[i]>100||score[i]<0)//当用户输入的成绩大于100或小于0时重新输入
        {
            printf("\nThe score is wrong.Please try again!\n");
            i=i-1;
            continue;
        }
    }
    printf("Input End.\n");
}
//函数功能：计算课程总分和平均分
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
//函数功能；按成绩由高到低排出名次表
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
//函数功能:按成绩由低到高排出名次表
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
//函数功能：按学号由小到大排出成绩表
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
//函数功能：交换学号，姓名和成绩
void change(long number[],char name[][N],float score[],int k,int i)
{
    int temp1,temp2;
    char chartemp[N];
    temp1=score[k];//交换成绩
    score[k]=score[i];
    score[i]=temp1;
    temp2=number[k];//交换学号
    number[k]=number[i];
    number[i]=temp2;
    strcpy(chartemp,name[k]);//交换姓名
    strcpy(name[k],name[i]);
    strcpy(name[i],chartemp);
}
//函数功能：按姓名的字典顺序排出成绩
void orderbyname(long number[],char name[][N],float score[],int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        {
            if(strcmp(name[j],name[i])<0)
            {
                change(number,name,score,j,i);//函数功能：交换学号，姓名和成绩
            }
        }
}
//函数功能：按学号查询学生排名和考试成绩 折半查找
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
//函数功能：按姓名查找成绩
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
/*函数功能：按优秀（90-100）、良好（80-89）、中等（70-79）、及格（60-69）、不及格（0-59）
统计每个类别的人数和所占百分比*/
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
    printf("\n优秀（90-100）人数：%d 优秀率：%.2f%%\n",a,a*1.0/n*100);
    printf("\n良好（80-89）人数：%d 良好率：%.2f%%\n",b,b*1.0/n*100);
    printf("\n中等（70-79）人数：%d 中等率：%.2f%%\n",c,c*1.0/n*100);
    printf("\n及格（60-69）人数：%d 及格率：%.2f%%\n",d,d*1.0/n*100);
    printf("\n不及格（0-59）人数：%d 不及格率：%.2f%%\n",e,e*1.0/n*100);
}
//函数功能：输出每个学生的学号，考试成绩
void Output(long number[],char name[][N],float score[],int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("\nnumber:%ld name:%s score:%.2f\n",number[i],name[i],score[i]);
}
