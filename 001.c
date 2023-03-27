/********************************ͷ�ļ�����*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

/***************************���пͻ���Ϣ�ṹ�����Ա***********************************/
struct Client;                         // ���пͻ���Ϣ�ṹ������
typedef struct Client Client, *Ptrone; // �ṹ��ָ�붨��
typedef Ptrone List;                   // ����ͷָ�붨��
typedef Ptrone Position;               // ������ָ�붨��

/********************************��ȡ���¼�ṹ��**************************************/
struct Records;                         // ְ�ƽṹ������
typedef struct Records Records, *PtrRe; // �ṹ��ָ�붨��
typedef PtrRe List1;                    // ����ͷָ�붨��
typedef PtrRe Position1;                // ������ָ�붨��

/********************************����������******************************************/
void DeleteList(List L);   // ����ɾ������(�ͻ���Ϣ
List MakeEmpty(List L);    // ������������(�ͻ���Ϣ
void BianliList(List L);   // �����ͻ���Ϣ������
List SortMoney(List L);    // ����ð��������(���
List SortNum(List L);      // ����ð��������(�˺�
void DeleteList1(List1 L); // ����ɾ������(��֧��¼
List1 MakeEmpty1(List1 L); // ������������(��֧��¼
void BianliList1(List1 L); // ������֧��¼������
List1 SortNum1(List1 L);   // ������¼(�˺�
List1 SortTime1(List1 L);  // ������¼(ʱ��

/********************************�ļ���������******************************************/
List Load(List L);     // ���ͻ���Ϣ���ص��ڴ溯��
void Save(List L);     // ���ͻ���Ϣ���浽���̺���
void MakeFileEmpty();  // ����ļ�����
List1 Load1(List1 L);  // ����֧��¼��Ϣ���ص��ڴ溯��
void Save1(List1 L);   // ����֧��¼��Ϣ���浽���̺���
void MakeFileEmpty1(); // ����ļ�����

/********************************�˵���������******************************************/
void Choose();                                      // �ÿ�ѡ�����
void MainMeun1(List L, List1 L1);                   // ����Ա���˵�
void MainMeun2(char[], List L, List1 L1, int flag); // �ͻ����˵�
void ViewMeun(List L, List1 L1);                    // ��ѯ�ͻ���Ϣ�˵�
void RecordMeun(List1 L);                           // ��ѯ�ͻ���ȡ���¼�˵�
void OrderMeun(List L, List1 L1);                   // �ͻ���Ϣ����˵�
void ModMeun(List L, List1 L1);                     // �޸Ĳ˵�
void ModMeun1(Position p, List L, List1 L1);        // �޸ĵĲ��ֲ˵�

/********************************�ͻ���Ϣ����������**********************************/

void Add(List L);                                           // ��Ϣ¼�뺯��
void ViewNum(char num[], List L);                           // �˺���ʾ����
void ViewName(char name[], List L);                         // ������Ϣ��ʾ����
void ViewTel(char tel[], List L);                           // �绰��Ϣ��ʾ����
void ViewID(char ID[], List L);                             // ���֤��ʾ����
void ViewCom(List L);                                       // �ۺϲ�ѯ
void CircleTel(char tel[], Position p, List L, List1 L1);   // �绰
void CircleName(char name[], Position p, List L, List1 L1); // ����
void CircleID(char ID[], Position p, List L, List1 L1);     // ���֤��ѯ
void ModName(Position p, List L, List1 L1);                 // �ͻ������޸ĺ���
void ModTel(Position p, List L);                            // �ͻ��绰�޸ĺ���
void ModPassword(Position p, List L);                       // �ͻ������޸ĺ���
void Delete(List L, List1 L1);                              // ɾ���������ͻ���Ϣ

/********************************��֧��¼����������**********************************/
void Add1(char sj[], Position p, List L, List1 L1); // ��֧��¼¼�뺯��
void ViewNum1(char num[], List1 L);                 // ��֧��¼��ѯ����(���˺�
void ViewName1(char name[], List1 L);               // ��֧��¼��ѯ����(������
void ViewCom1(List1 L);                             // �ۺϲ�ѯ

/********************************���ܺ�������******************************************/
Position Logon(List L);
int Mimayincan(char a[]);       // �������غ���
void PrintRecords(Position1 p); // ��֧��¼��ӡ����
void PrintClient(Position P);   // �ͻ���Ϣ��ӡ����
int Testl(int a, int b, int c); // �˵������⺯��
void jieshuo(List L, List1 L1);

/*********************************�ṹ�嶨��*******************************************/
struct Client // �ͻ���Ϣ�ṹ��ͻ�
{
    char num[20];      // �˺�
    char ID[19];       // ���֤��
    char name[10];     // ����
    char tel[12];      // �绰
    char password[20]; // ����
    double money;  // ���
    char sd[5];    // ����
    char time[20]; // ��������
    int type;      // ������1.�����2.���ÿ�
    int point;     // ���û���
    Position next; // nextָ�� (ָ����һ�ṹ��)
};
struct Records // ������¼�ṹ��
{
    char num[30];  // �˺�
    char name[20]; // ����
    char ID[20];
    char time[20];        // ����ʱ�� ��/��/��,ʱ:�� 2022/12/10-22.14
    double rmb;           // ��ȡ��
    char sd[5];           // ����
    struct Records *next; // nextָ��
};
/********************************��������**********************************************/
int main() // ������
{
    system("color F0");
    List L = NULL;
    List1 L1 = NULL;
    int x;
    system("cls");
    printf("\n\n\n\n\t\t\t��ӭ����С��������\n\n");
    L = Load(L);
    L1 = Load1(L1);
    printf("\n\t\t����س�������");
    getchar();
    system("cls"); // ʵ������
    Choose();      // ���÷ÿ�ѡ����ݺ���
    scanf("%d", &x);
    x = Testl(x, 0, 2);
    while (1)
    {
        fflush(stdin); // ������̻�����
        switch (x)
        {
        case 1:
        {
            system("cls");
            char a[] = "123123";
            if (Mimayincan(a) == 1)
                MainMeun1(L, L1);
            exit(0); // ���ù���Ա���˵�����
        }
        case 2:
        {
            int flag = 1;
            system("cls");
            Position p = Logon(L);
            if (p)
                MainMeun2(p->num, L, L1, flag); // ���ÿͻ����˵�����
            else
                main();
        }
        case 0:
            exit(0); // �˳�ϵͳ
        }
    }
    return 0;
}

/********************************����������******************************************/
void DeleteList(List L) // ����ɾ������
{
    Position P;
    P = L->next;      // ȡ����ͷ������н��
    L->next = NULL;   // ����ͷָ��ս��
    while (P != NULL) // �����ͷ�����ͷ�����н��Ŀռ�
    {
        free(P);
        P = P->next;
    }
}
void DeleteList1(List1 L)
{
    Position1 p;
    p = L->next;      // ȡ����ͷ������н��
    L->next = NULL;   // ����ͷָ��ս��
    while (p != NULL) // �����ͷ�����ͷ�����н��Ŀռ�
    {
        free(p);
        p = p->next;
    }
}
List MakeEmpty(List L) // ������������
{
    if (L)                                   // �൱�� if(L!=NULL) ,��ָ��Lָ��Ŀռ䲻Ϊ��
        DeleteList(L);                       // ɾ��ԭ������
    L = (List)malloc(sizeof(struct Client)); // �����µĿ�����
    if (!L)                                  // �൱�� if(L==NULL) ,��ָ��Lָ��Ŀռ�Ϊ��
    {
        printf("����ʧ��,�ڴ治��!!!"); // ����ʧ�ܣ���ʾ�ڴ治��
        system("pause");                // ��ͣ��Ļ��ʾ
        return NULL;                    // ������һ���˵�
    }
    L->next = NULL; // Nextָ��ָ���
    return L;       // ��������ͷ
}
List1 MakeEmpty1(List1 L)
{
    if (L)                                     // �൱�� if(L!=NULL) ,��ָ��Lָ��Ŀռ䲻Ϊ��
        DeleteList1(L);                        // ɾ��ԭ������
    L = (List1)malloc(sizeof(struct Records)); // �����µĿ�����
    if (!L)                                    // �൱�� if(L==NULL) ,��ָ��Lָ��Ŀռ�Ϊ��
    {
        printf("����ʧ��,�ڴ治��!!!"); // ����ʧ�ܣ���ʾ�ڴ治��
        system("pause");                // ��ͣ��Ļ��ʾ
        return NULL;                    // ������һ���˵�
    }
    L->next = NULL; // Nextָ��ָ���
    return L;       // ��������ͷ
}
void BianliList(List L) // ����������
{
    Position p = L->next;
    printf("\n�ͻ���Ϣ����:\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("�˺�\t\t\t����\t\t�绰\t\t���\t\t״̬                  \n");
    while (p)
    {
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("%-20s\t%-10s\t%-11s\t%-.2lf\t\t%-5s\n", p->num, p->name, p->tel, p->money, p->sd);
        p = p->next;
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - -\n");
    system("pause");
}
void BianliList1(List1 L)
{
    printf("\n\t\t\t\t��֧��¼����:\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("�˺�\t\t\t����\t\t��������\t\t��ȡ��                  \n");
    Position1 p = L->next;
    while (p)
    {
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("%-20s\t%-10s\t%-18s\t%-.2lf          \n", p->num, p->name, p->time, p->rmb);
        p = p->next;
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - -\n");
    system("pause");
}

/********************************�ļ���������******************************************/
List Load(List L) // ��ʼ������
{
    FILE *fp;
    Position a;
    int num = 0;
    fp = fopen("�ͻ���Ϣ.txt", "r+");
    if (fp == NULL)
    {
        printf("\n\t\t�޷����ļ����ļ�������\n"); // ��ʾ����
        printf("\n\t\t���ڳ��Դ������ļ�....\n");
        fp = fopen("�ͻ���Ϣ.txt", "w"); // �����ͻ���Ϣ�ļ�
        if ((fp = fopen("�ͻ���Ϣ.txt", "r+")) == NULL)
        {
            printf("\t\t�ļ�����ʧ��!!!\n");
            system("pause"); // ��ͣ��Ļ��ʾ
            return NULL;
        }
    }
    fp = fopen("�ͻ���Ϣ.txt", "r+"); // ��ֻ���ķ�ʽ��"�ͻ���Ϣ.txt"�ı��ļ�
    L = MakeEmpty(L);                 // ���������Ա�洢�ı��ļ��е���Ϣ
    while (1)
    {
        a = (List)malloc(sizeof(struct Client)); // �����½��
        if (a == NULL)
        {
            printf("\n\t\t�ļ���Ϣ��ȡʧ�ܣ�ϵͳ�ڴ治�㣡");
            system("pause"); // ��ͣ��Ļ��ʾ
            return NULL;
        }
        if (fscanf(fp, "%s %s %s %s %s %lf %s %d %d %s", a->num, a->ID, a->name, a->tel, a->password, &a->money, a->time, &a->type, &a->point, a->sd) < 0)
            break;         // ���ͻ���Ϣ¼���ļ�
        a->next = L->next; // ͷ�巨
        L->next = a;
        num++;
    }
    printf("\n\t\t�ͻ���Ϣ��ȡ��ɣ�Ŀǰ����%d���ͻ�\n", num);
    fclose(fp);
    return L;
}
List1 Load1(List1 L)
{
    FILE *fp;
    Position1 a;
    int num = 0;
    fp = fopen("��֧��¼.txt", "r+");
    if (fp == NULL)
    {
        printf("\n\t\t�޷����ļ����ļ�������\n"); // ��ʾ����
        printf("\n\t\t���ڳ��Դ������ļ�....\n");
        fp = fopen("��֧��¼.txt", "w"); // �����ͻ���Ϣ�ļ�
        if ((fp = fopen("��֧��¼.txt", "r+")) == NULL)
        {
            printf("\t\t�ļ�����ʧ��!!!\n");
            system("pause");
            return NULL; // ��ͣ��Ļ��ʾ
        }
    }
    fp = fopen("��֧��¼.txt", "r+"); // ��ֻ���ķ�ʽ��"��֧��¼.txt"�ı��ļ�
    L = MakeEmpty1(L);                // ���������Ա�洢�ı��ļ��е���Ϣ
    while (1)
    {
        a = (List1)malloc(sizeof(struct Records)); // �����½��
        if (a == NULL)
        {
            printf("\n\t\t�ļ���Ϣ��ȡʧ�ܣ�ϵͳ�ڴ治�㣡");
            system("pause"); // ��ͣ��Ļ��ʾ
            return NULL;
        }
        if (fscanf(fp, "%s %s %s %s %lf %s\n", a->num, a->name, a->time, a->ID, &a->rmb, a->sd) < 0)
            break;         // ���ͻ���֧��¼¼���ļ�
        a->next = L->next; // ͷ�巨
        L->next = a;
        num++;
    }
    fclose(fp);
    printf("\n\t\t������¼��Ϣ��ȡ��ɣ�Ŀǰ����%d��������¼\n", num);
    return L;
}
void Save(List L) // ��Ϣ���溯��
{
    FILE *fp;
    Position p = L;
    if ((fp = fopen("D:\\�ͻ���Ϣ.txt", "w+")) == NULL)
    {
        printf("���ļ�ʧ��\n");
        system("pause");
        return;
    }
    fp = fopen("�ͻ���Ϣ.txt", "w+");
    for (; p->next != NULL;)
    {
        p = p->next;
        if (fprintf(fp, "%s\t %s\t %s\t %s\t %s\t%.2lf\t %s\t %d\t %d\t %s\n", p->num, p->ID, p->name, p->tel, p->password, p->money, p->time, p->type, p->point, p->sd) < 0)
            break; // ����Ϣд�����
    }
    printf("��Ϣ¼��ɹ���\n");
    fclose(fp);
    return;
}
void Save1(List1 L)
{
    FILE *fp;
    Position1 p = L;
    if ((fp = fopen("D:\\��֧��¼.txt", "w+")) == NULL)
    {
        printf("���ļ�ʧ��\n");
        exit(0);
    }
    fp = fopen("��֧��¼.txt", "w+");
    for (; p->next != NULL;)
    {
        p = p->next;
        if (fprintf(fp, "%s\t %s\t %s\t %s\t %.2lf\t %s\n", p->num, p->name, p->time, p->ID, p->rmb, p->sd) < 0)
            break; // ����Ϣд�����
    }
    printf("��Ϣ¼��ɹ���\n");
    fclose(fp);
}
void MakeFileEmpty() // ����ļ�����
{
    FILE *fp;
    fp = fopen("�ͻ���Ϣ.txt", "w"); // �½�һ���ļ�������֮ǰ���ļ�ɾ��
    if (fp == NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("��Ϣ��ճɹ�!\n");
    fclose(fp);
}
void MakeFileEmpty1()
{
    FILE *fp;
    fp = fopen("��֧��¼.txt", "w"); // �½�һ���ļ�������֮ǰ���ļ�ɾ��
    if (fp == NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("��Ϣ��ճɹ�!\n");
    fclose(fp);
}

/********************************�˵���������******************************************/
void Choose() // �ÿ�ѡ����� @
{
    printf("\n\t\t**         ѡ���������          **");
    printf("\n\t\t**                               **");
    printf("\n\t\t**          1.����Ա             **");
    printf("\n\t\t**          2.�ͻ�               **");
    printf("\n\t\t**          0.�˳�ϵͳ           **");
    printf("\n\t\t**                               **");
    printf("\n\n\t\t\t����������ѡ��:");
}
void MainMeun1(List L, List1 L1) // ����Ա���˵�
{
    system("cls");
    printf("\n\t\t**            ���˵�                  **"); //
    printf("\n\t\t**                                    **"); //
    printf("\n\t\t**         1.ע���˻�                 **"); //
    printf("\n\t\t**         2.ע���˻�                 **"); //
    printf("\n\t\t**         3.��ѯ�ͻ���Ϣ             **"); //
    printf("\n\t\t**         4.��ѯ�ͻ�������¼         **"); //
    printf("\n\t\t**         5.�޸Ŀͻ���Ϣ             **"); //
    printf("\n\t\t**         6.��Ϣ�鿴                 **"); //
    printf("\n\t\t**         7.�ͻ���̨����             **"); //
    printf("\n\t\t**         8.����ϵͳ                 **"); //
    printf("\n\t\t**         9.�˻���������ʧ��ȡ����ʧ **"); //
    printf("\n\t\t**         0.������һ��               **"); //
    printf("\n\t\t**                                    **");
    printf("\n\n\t\t\t����������ѡ��:");
    int x;
    scanf("%d", &x);
    while (1)
    {
        system("cls"); // ʵ������
        x = Testl(x, 0, 9);
        fflush(stdin); // ������̻�����
        switch (x)
        {
        case 1:
            system("cls");
            Add(L);
            system("cls");
            MainMeun1(L, L1); // ע���˻�
        case 2:
            system("cls");
            Delete(L, L1);
            system("cls");
            MainMeun1(L, L1); // ע���˻�
        case 3:
            system("cls");
            ViewMeun(L, L1);
            system("cls");
            MainMeun1(L, L1); // ��ѯ�ͻ���Ϣ
        case 4:
            system("cls");
            RecordMeun(L1);
            return; // ��ѯ�ͻ���ȡ����Ϣ
        case 5:
            system("cls");
            ModMeun(L, L1);
            return; // �޸Ŀͻ���Ϣ
        case 6:
            system("cls");
            OrderMeun(L, L1);
            return; // ��Ϣ�鿴
        case 7:
        {
            system("cls");
            Position p = Logon(L);
            if (p == NULL)
            {
                MainMeun1(L, L1);
            }
            else
            {
                MainMeun2(p->num, L, L1, 0);
                MainMeun1(L, L1);
                break; // �ͻ���ȡ��,�޸�����Ȳ���
            }
        }
        case 8:
        {
            system("cls");
            printf("�Ƿ���Ҫ����ϵͳ���ظ�'Y'/'N'\n");
            if (getchar() == 'Y')
            {
                MakeFileEmpty(), MakeFileEmpty1();
                system("cls");
                return;
            } // ����ϵͳ
            MainMeun1(L, L1);
        }
        case 9:
            system("cls");
            jieshuo(L, L1);
            MainMeun1(L, L1);
            break; // ������һ��
        case 0:
            system("cls");
            main();
            break; // ������һ��
        }
        return;
    }
}
void MainMeun2(char num[], List L, List1 L1, int flag) // �ͻ����˵�
{
    Position p = L->next;
    Position1 p1 = L1->next;
    char sj[20], b[20] = "00";
    while (p1 != NULL && strcmp(num, p1->num) != 0)
        p1 = p1->next;
    while (p != NULL && strcmp(num, p->num) != 0)
        p = p->next;
    printf("\n\t\t**           ���˵�              **");
    printf("\n\t\t**                               **");
    if (p->type == 1)
        printf("\n\t\t**         1.��ȡ��              **"); //
    else
        printf("\n\t\t**         1.�����뻹��          **"); //
    printf("\n\t\t**         2.������¼��ѯ        **");     //
    printf("\n\t\t**         3.������Ϣ��ѯ        **");     //
    printf("\n\t\t**         4.�޸�����            **");     //
    printf("\n\t\t**         5.�˳��ͻ�ϵͳ        **");     //
    printf("\n\t\t**                               **");
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime); // ��ȡϵͳʱ��

    printf("\n\t\t%4d/%02d/%02d-%02d.%02d.%02d\n", 1900 + timeinfo->tm_year, 1 + timeinfo->tm_mon,
           timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    printf("\n\t\t����������ʱ��(��/��/��-ʱ.��.��):  ");
    scanf("%s", sj);
    if (p->money < 0 && strcmp(p->time, sj) <= 0) // ��ʱδ�������÷�δ�����������
    {
        p->point = -1;
        p->money = 1.1 * p->money;
        printf("\n\t\t%4d/%02d/%02d-%02d.%02d.%02d\n", 1900 + timeinfo->tm_year, 1 + timeinfo->tm_mon + 1,
               timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        printf("\n\t\t����������ʱ��(��/��/��-ʱ.��.��):  "); // �����������
        scanf("%s", p->time);
        Save(L);
        printf("\n\t\t�������÷ֲ�������ϣ���������Ȼ���Ŷ������Ҫ����%.2lfԪ��", -p->money);
    }
    if (p->money > 0)
    {
        strcpy(p->time, b);
        Save(L);
    }
    printf("\n\n\t\t\t����������ѡ��:");
    int x;
    scanf("%d", &x);
    while (1)
    {
        system("cls"); // ʵ������
        x = Testl(x, 1, 5);
        fflush(stdin);
        // ������̻�����
        switch (x)
        {
        case 1:
            system("cls");
            Add1(sj, p, L, L1);
            system("cls");
            MainMeun2(p->num, L, L1, flag); // ���
        case 2:
            system("cls");
            if (p1 == NULL)
            {
                printf("\n�޲�����¼�� ");
                system("pause");
                return;
            }
            ViewNum1(num, L1);
            system("cls");
            MainMeun2(p->num, L, L1, flag); // ������¼��ѯ
        case 3:
            system("cls");
            ViewNum(num, L);
            system("cls");
            MainMeun2(p->num, L, L1, flag); // ������Ϣ��ѯ
        case 4:
            system("cls");
            ModPassword(p, L);
            system("cls");
            MainMeun2(p->num, L, L1, flag); // �޸�����
        case 5:
        {
            system("cls");
            if (flag == 1)
                main();
            else
                MainMeun1(L, L1);
        }
        }
    }
}
void OrderMeun(List L, List1 L1) // ��Ϣ�鿴�˵�
{
    printf("\n\t\t**           ��Ϣ�鿴             **");
    printf("\n\t\t**                                **");
    printf("\n\t\t**    1.���˺�����(�ͻ���Ϣ)      **"); //@
    printf("\n\t\t**    2.���������(�ͻ���Ϣ)      **"); //@
    printf("\n\t\t**    3.���˺�����(������¼)      **"); //@
    printf("\n\t\t**    4.��ʱ������(������¼)      **"); //@
    printf("\n\t\t**    5.������һ���˵�            **"); //
    printf("\n\t\t**                                **");
    printf("\n\n\t\t\t����������ѡ��:");
    int x;
    scanf("%d", &x);
    while (1)
    {
        system("cls"); // ʵ������
        x = Testl(x, 1, 5);
        fflush(stdin); // ������̻�����
        switch (x)
        {
        case 1:
            system("cls");
            L = SortNum(L);
            system("cls");
            OrderMeun(L, L1); // ���˺�����
        case 2:
            system("cls");
            L = SortMoney(L);
            system("cls");
            OrderMeun(L, L1); // ���������
        case 3:
            system("cls");
            L1 = SortNum1(L1);
            system("cls");
            OrderMeun(L, L1); // ���˺�����
        case 4:
            system("cls");
            L1 = SortTime1(L1);
            system("cls");
            OrderMeun(L, L1); // ��ʱ������
        case 5:
            system("cls");
            MainMeun1(L, L1); // ������һ��
        }
    }
}
void ViewMeun(List L, List1 L1) // ��ѯ�ͻ���Ϣ�˵�
{
    printf("\n\t\t**        ��ѯ�ͻ���Ϣ            **");
    printf("\n\t\t**                                **");
    printf("\n\t\t**        1.���˺Ų�ѯ            **"); //@
    printf("\n\t\t**        2.�����֤��ѯ          **"); //@
    printf("\n\t\t**        3.��������ѯ            **"); //@
    printf("\n\t\t**        4.���绰��ѯ            **"); //@
    printf("\n\t\t**        5.���绰��������ѯ      **"); //@
    printf("\n\t\t**        6.������һ��            **"); //@
    printf("\n\t\t**                                **");
    printf("\n\n\t\t\t����������ѡ��:");
    int x;
    scanf("%d", &x);
    while (1)
    {
        system("cls"); // ʵ������
        x = Testl(x, 1, 6);
        fflush(stdin); // ������̻�����
        switch (x)
        {
        case 1:
            system("cls");
            char num[30];
            printf("\n��������Ҫ��ѯ���˺�:  ");
            gets(num);
            ViewNum(num, L);
            system("cls");
            ViewMeun(L, L1);
            break; // ���˺Ų�ѯ
        case 2:
            system("cls");
            char ID[20];
            printf("\n��������Ҫ��ѯ�����֤�� ");
            gets(ID);
            ViewID(ID, L);
            system("cls");
            ViewMeun(L, L1);
            break; // �����֤�Ų�ѯ
        case 3:
            system("cls");
            char name[10];
            printf("\n��������Ҫ��ѯ�������� ");
            gets(name);
            ViewName(name, L);
            system("cls");
            ViewMeun(L, L1);
            break; // ��������ѯ
        case 4:
            system("cls");
            char tel[20];
            printf("\n��������Ҫ��ѯ�ĵ绰�� ");
            gets(tel);
            ViewTel(tel, L);
            system("cls");
            ViewMeun(L, L1);
            break; // ���绰��ѯ
        case 5:
            system("cls");
            ViewCom(L);
            MainMeun1(L, L1);
            break; // ���绰��������ѯ
        case 6:
            system("cls");
            MainMeun1(L, L1);
            break; // ������һ��
        }
    }
}
void RecordMeun(List1 L1) // ��ѯ�ͻ���ȡ���¼�˵�
{
    printf("\n\t\t**       ��ѯ�ͻ�������¼         **");
    printf("\n\t\t**                                **");
    printf("\n\t\t**        1.���˺Ų�ѯ            **"); //@
    printf("\n\t\t**        2.��������ѯ            **"); //@
    printf("\n\t\t**        3.���˺źͲ���ʱ���ѯ  **"); //@
    printf("\n\t\t**        4.������һ��            **"); //@
    printf("\n\t\t**                                **");
    printf("\n\n\t\t\t����������ѡ��:");
    int x;
    List L = NULL;
    L = Load(L);
    char num[30], name[10];
    scanf("%d", &x);
    while (1)
    {
        system("cls"); // ʵ������
        x = Testl(x, 1, 4);
        fflush(stdin); // ������̻�����
        switch (x)
        {
        case 1:
            system("cls");
            printf("\n��������Ҫ��ѯ���˺�:  ");
            gets(num);
            ViewNum1(num, L1);
            system("cls");
            RecordMeun(L1);
        case 2:
            system("cls");
            printf("\n��������Ҫ��ѯ������:  ");
            gets(name);
            ViewName1(name, L1);
            system("cls");
            RecordMeun(L1);
        case 3:
            system("cls");
            ViewCom1(L1);
            MainMeun1(L, L1);
            break; // ���˺źͲ���ʱ���ѯ
        case 4:
            system("cls");
            MainMeun1(L, L1); // ������һ��
        }
    }
}
void ModMeun(List L, List1 L1) // �޸Ĳ˵�
{
    printf("\n\t\t**        �޸Ŀͻ���Ϣ            **");
    printf("\n\t\t**                                **");
    printf("\n\t\t**        1.���˺Ų�ѯ�޸�        **"); //
    printf("\n\t\t**        2.��������ѯ�޸�        **"); //
    printf("\n\t\t**        3.���绰��ѯ�޸�        **"); //
    printf("\n\t\t**        4.�����֤�Ų�ѯ�޸�    **"); //
    printf("\n\t\t**        5.������һ��            **"); //
    printf("\n\t\t**                                **");
    printf("\n\n\t\t\t����������ѡ��:");
    int x;
    char name[10], tel[20], ID[20], num[30], a[20];
    Position p = L->next;
    scanf("%d", &x);
    while (1)
    {
        system("cls"); // ʵ������
        x = Testl(x, 1, 5);
        fflush(stdin); // ������̻�����
        switch (x)
        {
        case 1:
            system("cls");
            printf("\n�������ѯ�޸ĵ��˺�: ");
            gets(num); // ���˺Ų�ѯ
            while (p)  // �ж�P��Nextָ���Ƿ�Ϊ�գ���P����һ�����Ŀͻ��绰�Ƿ�Ϊ�����˺�
            {
                if (strcmp(num, p->num) == 0)
                {
                    PrintClient(p);
                    printf("\n�Ƿ��������޸ĵ��˻����ظ�'Y'/'N'\n");
                    if (getchar() == 'Y')
                    {
                        strcpy(a, p->password);
                        Mimayincan(a);
                        ModMeun1(p, L, L1);
                    }
                    else
                    {
                        printf("δ�ҵ�����Ҫ�޸ĵ��˺�~\n");
                        system("pause");
                        system("cls");
                        ModMeun(L, L1);
                    }
                }
                p = p->next;
                if (!p)
                {
                    printf("\n���˺Ų����ڣ� ");
                    system("pause");
                    system("cls");
                    ModMeun(L, L1);
                }
            }
            system("cls");
            ModMeun(L, L1);
        case 2:
            system("cls");
            printf("\n�������ѯ�޸ĵ�����: ");
            gets(name); // ��������ѯ
            CircleName(name, p, L, L1);
            system("cls");
            ModMeun(L, L1);
        case 3:
            system("cls");
            printf("\n�������ѯ�޸ĵĵ绰: ");
            gets(tel); // ���绰��ѯ
            CircleTel(tel, p, L, L1);
            system("cls");
            ModMeun(L, L1);
        case 4:
            system("cls");
            printf("\n�������ѯ�޸ĵ����֤��: ");
            gets(ID); // �����֤��ѯ
            CircleID(ID, p, L, L1);
            system("cls");
            ModMeun(L, L1);
        case 5:
            system("cls");
            MainMeun1(L, L1); // ������һ��
        }
    }
}
void ModMeun1(Position p, List L, List1 L1) // �޸Ŀͻ���Ϣ�˵�
{
    printf("\n\t\t**        �޸Ŀͻ���Ϣ            **");
    printf("\n\t\t**                                **");
    printf("\n\t\t**        1.�޸�����              **"); //
    printf("\n\t\t**        2.�޸�����              **"); //
    printf("\n\t\t**        3.�޸ĵ绰              **"); //
    printf("\n\t\t**        4.������һ��            **"); //
    printf("\n\t\t**                                **");
    printf("\n\n\t\t\t����������ѡ��:");
    int x;
    scanf("%d", &x);
    while (1)
    {
        system("cls"); // ʵ������
        x = Testl(x, 1, 4);
        fflush(stdin); // ������̻�����
        switch (x)
        {
        case 1:
            system("cls");
            ModName(p, L, L1);
            system("cls");
            ModMeun1(p, L, L1); // �޸�����
        case 2:
            system("cls");
            ModPassword(p, L);
            system("cls");
            ModMeun1(p, L, L1); // �޸�����
        case 3:
            system("cls");
            ModTel(p, L);
            system("cls");
            ModMeun1(p, L, L1); // �޸ĵ绰
        case 4:
            system("cls");
            ModMeun(L, L1); // ������һ��
        }
    }
}

/********************************�ͻ�����������********************************************/
// ��Ϣ¼�뺯����ɾ��
void Add(List L) // �ͻ���Ϣ
{
    Position p = L->next;
    char num[20], a[7] = "����", b[20] = "00";
    int t;
    printf("\n��������Ҫ�������˺�:  "); // ��ʾ�����˺�
    gets(num);
    while (p != NULL && strcmp(num, p->num) != 0)
        p = p->next;
    if (p != NULL)
    {
        printf("\n���˺��Ѵ��� ");
        system("pause");
        return;
    }
    p = (Position)malloc(sizeof(struct Client)); // �����½��
    if (p == NULL)
    {
        printf("\n���ʧ��,�ڴ治��!!!\n\n"); // ���ʧ�ܣ���ʾ�ڴ治��
        system("pause");                      // ��ͣ��Ļ��ʾ
        return;                               // ������һ���˵�
    }
    strcpy(p->num, num); // �����˺�
    printf("\n����������Ҫ����Ŀ�����(1.���2.���ÿ�)�� ");
    scanf("%d", &t);
    t = Testl(t, 1, 2);
    p->type = t;
    printf("\n������ͻ����֤��:  "); // �������֤��
    scanf("%s", p->ID);
    printf("\n������ͻ��绰:  "); // ����绰
    scanf("%s", p->tel);
    printf("\n������ͻ��������� "); // ��������
    scanf("%s", p->name);
    printf("\n������ͻ����룺 "); // ��������
    scanf("%s", p->password);
    p->money = 0.00;    // ���
    p->point = 0;       // ���û���
    strcpy(p->time, b); // ��������
    strcpy(p->sd, a);   // ״̬
    p->next = L->next;  // �����p���뵽������
    L->next = p;
    Save(L); // ���� ��Ϣ���溯��
    system("pause");
    return;
}
void Add1(char sj[], Position p, List L, List1 L1) // ��֧��¼
{
    char a[7] = "����", b[20] = "00";
    Position1 p1;
    p1 = (Position1)malloc(sizeof(struct Records)); // �����½��
    if (p1 == NULL)
    {
        printf("\n���ʧ��,�ڴ治��!!!\n\n"); // ���ʧ�ܣ���ʾ�ڴ治��
        system("pause");                      // ��ͣ��Ļ��ʾ
    }
    strcpy(p1->num, p->num);
    strcpy(p1->name, p->name);
    strcpy(p1->ID, p->ID);
    strcpy(p1->time, sj);
    if (p->type == 1) // ���
    {
        printf("\n�������ȡ����(������)�� "); // �����ȡ��
        scanf("%lf", &p1->rmb);
        if (p->money + p1->rmb < 0)
        {
            printf("\n���㣡");
            system("pause");
            return;
        }
        p->money = p->money + p1->rmb;
    }
    else if (p->type == 2) // ���ÿ�
    {
        printf("\n���������ѻ򻹿���(������)�� ");
        scanf("%lf", &p1->rmb);
        if (p1->rmb < 0) // ���ѽ���͸֧���
        {
            if (p->money + p1->rmb < -500 && p->point == 0) // ͸֧��Ȳ���ʱ
            {
                printf("\n͸֧��Ȳ���,������������%.2lfԪ\n", 500 + p->money);
                system("pause");
                return;
            }
            else if (p->point < 0)
            {
                printf("\n�������÷ֲ��������Ȼ���Ŷ������Ҫ����%.2lfԪ��", p->money);
                system("pause");
                return;
            }
        }
        p->money = p->money + p1->rmb;
        if (p->money < 0 && p->point == 0)
        {
            time_t rawtime;
            struct tm *timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime); // ��ȡϵͳʱ��

            printf("%4d/%02d/%02d-%02d.%02d.%02d\n", 1900 + timeinfo->tm_year, (1 + timeinfo->tm_mon + 1) % 12,
                   timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); // �������ڣ���һ����
            printf("\n����������ʱ��(��/��/��-ʱ.��.��):  ");                                 // �����������
            scanf("%s", p->time);
            printf("\n����%4d/%02d/%02d-%02d.%02d.%02d֮ǰ����", 1900 + timeinfo->tm_year, (1 + timeinfo->tm_mon + 1) % 12,
                   timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); // ���ѻ���
        }

        if (p1->rmb + p->money >= 0) // ΥԼ�󻹿����÷ָֻ�
        {
            p->point = 0;
            strcpy(p->time, b);
        }
    }
    p1->next = L1->next; // �����p���뵽������
    L1->next = p1;
    strcpy(p1->sd, a);
    Save1(L1); // ���� ��Ϣ���溯��
    Save(L);
    system("pause");
    return;
}
void Delete(List L, List1 L1) // �ͻ���Ϣ
{
    Position p = L->next, a = L;
    Position1 p1 = L1->next, b;
    char num[10];
    printf("\n��������ע�����˺�: ");
    gets(num); // ���˺�ɾ��
    while (p != NULL && strcmp(p->num, num) != 0)
    {
        a = p;       // ��סǰһ�����
        p = p->next; // ������һ�����
    }

    if (p == NULL)
    {
        printf("\n�����ڸ��˻�Ŷ~\n");
        system("pause");
        return;
    }
    PrintClient(p); // ���ÿͻ���Ϣ��ӡ����
    fflush(stdin);  // ������̻�����
    if (p->money > 0)
    {
        printf("\n����ȡ���˻���");
        system("pause");
        return;
    }
    printf("\n�Ƿ�ȷ��Ҫɾ�����ظ�'Y'/'N'\n");
    char x;
    scanf("%c", &x);
    if (x == 'Y')
    {
        Mimayincan(p->password);
        a->next = p->next;
        free(p);
        printf("\nɾ���ɹ�!!!\n\n");
        Save(L); // ������Ϣ���溯��
        Save1(L1);
    }
}
// ��ѯ����
void ViewNum(char num[], List L) // �˺�
{
    Position p = L->next;
    int f = 0;
    while (p)
    {
        if (strstr(p->num, num))
        {
            PrintClient(p);
            f = 1;
        }
        p = p->next;
    }
    if (f == 0) // �ж��Ƿ���ڸÿͻ�
        printf("\nû��ƥ�����Ϣ");
    system("pause");
}
void ViewName(char name[], List L) // ����
{
    int f = 0;
    Position p = L->next;
    while (p)
    {
        if (strstr(p->name, name))
        {
            PrintClient(p);
            f = 1;
        }
        p = p->next;
    }
    if (f == 0) // �ж��Ƿ���ڸÿͻ�
        printf("\nû��ƥ�����Ϣ");
    system("pause");
}
void ViewTel(char tel[], List L) // �绰
{
    Position p = L->next;
    int f = 0;
    while (p)
    {
        if (strstr(p->tel, tel))
        {
            PrintClient(p);
            f = 1;
        }
        p = p->next;
    }
    if (f == 0) // �ж��Ƿ���ڸÿͻ�
        printf("\nû��ƥ�����Ϣ");
    system("pause");
}
void ViewID(char ID[], List L) // ���֤��
{
    Position p = L->next;
    int f = 0;
    while (p)
    {
        if (strstr(p->ID, ID))
        {
            PrintClient(p);
            f = 1;
        }
        p = p->next;
    }
    if (f == 0) // �ж��Ƿ���ڸÿͻ�
        printf("\nû��ƥ�����Ϣ");
    system("pause");
}
void ViewCom(List L) // �ۺϲ�ѯ
{
    Position p = L->next;
    char name[10], tel[12];
    printf("��������: \n");
    gets(name);
    printf("������绰: \n");
    gets(tel);
    int f = 0;
    while (p)
    {
        if (strcmp(p->name, name) == 0 && strcmp(p->tel, tel) == 0)
        {
            PrintClient(p);
            f = 1;
        }
        p = p->next;
    }
    if (f == 0) // �ж��Ƿ���ڸÿͻ�
        printf("\nû��ƥ�����Ϣ");
    system("pause");
}
// ��֧��¼��ѯ
void ViewName1(char name[], List1 L) // ��������ѯ
{
    int f = 0;
    Position1 p = L->next;
    while (p) // �ж�P��Nextָ���Ƿ�Ϊ�գ���P����һ�����Ŀͻ��˺��Ƿ�Ϊ�����˺�
    {
        if (strcmp(p->name, name) == 0)
        {
            PrintRecords(p);
            f = 1;
        }
        p = p->next;
    }
    if (f == 0) // �ж��Ƿ���ڸÿͻ�
        printf("\nû��ƥ�����Ϣ");
    system("pause");
}
void ViewNum1(char num[], List1 L) // ���˺Ų�ѯ
{
    int f = 0;
    Position1 p = L->next;
    while (p) // �ж�P��Nextָ���Ƿ�Ϊ�գ���P����һ�����Ŀͻ��˺��Ƿ�Ϊ�����˺�
    {
        if (strstr(p->num, num))
        {
            PrintRecords(p);
            f = 1;
        }
        p = p->next;
    }
    if (f == 0)
        printf("\nû��ƥ�����Ϣ");
    system("pause");
}
void ViewCom1(List1 L) // �ۺϲ�ѯ
{
    Position1 p = L->next;
    char num[30], time[12];
    printf("�����˺�: \n");
    gets(num);
    printf("���������ʱ��: \n");
    gets(time);
    int f = 0;
    while (p)
    {
        if (strcmp(p->num, num) == 0 && strstr(p->time, time) != NULL)
        {
            PrintRecords(p);
            f = 1;
        }
        p = p->next;
    }
    if (f == 0) // �ж��Ƿ���ڸÿͻ�
        printf("\nû��ƥ�����Ϣ");
    system("pause");
}
// ������(����
List SortMoney(List L) // ���(�ͻ���Ϣ
{
    Position a, b, p = L->next;
    int i, j, num = 0;
    while (p)
    {
        num++;
        p = p->next;
    }
    for (j = 0; j < num - 1; j++)
    {
        a = L->next;
        b = a->next;
        p = L;
        for (i = 0; i < num - 1 - j; i++)
        {
            if (a->money < b->money)
            {
                a->next = b->next;
                p->next = b;
                b->next = a;
            }
            p = p->next;
            a = p->next;
            b = a->next;
        }
    }
    Save(L);
    BianliList(L);
    return L;
}
List SortNum(List L) // �˺�(�ͻ���Ϣ
{
    Position a, b, p = L->next;
    int i, j, num = 0;
    while (p)
    {
        num++;
        p = p->next;
    }
    for (j = 0; j < num - 1; j++)
    {
        p = L;
        a = L->next;
        b = a->next;
        for (i = 0; i < num - 1 - j; i++)
        {
            if (strcmp(a->num, b->num) > 0)
            {
                a->next = b->next;
                p->next = b;
                b->next = a;
            }
            p = p->next;
            a = p->next;
            b = a->next;
        }
    }
    Save(L);
    BianliList(L);
    return L;
}
List1 SortNum1(List1 L) // �˺�(��֧��¼
{
    Position1 a, b, p = L->next;
    int i, j, num = 0;
    while (p)
    {
        num++;
        p = p->next;
    }
    for (j = 0; j < num - 1; j++)
    {
        p = L;
        a = L->next;
        b = a->next;
        for (i = 0; i < num - 1 - j; i++)
        {
            if (strcmp(a->num, b->num) > 0)
            {
                a->next = b->next;
                p->next = b;
                b->next = a;
            }
            p = p->next;
            a = p->next;
            b = a->next;
        }
    }
    Save1(L);
    BianliList1(L);
    return L;
}
List1 SortTime1(List1 L) // ���(��֧��¼
{
    Position1 a, b, p = L->next;
    int i, j, num = 0;
    while (p)
    {
        num++;
        p = p->next;
    }
    for (j = 0; j < num - 1; j++)
    {
        a = L->next;
        b = a->next;
        p = L;
        for (i = 0; i < num - 1 - j; i++)
        {
            if (strcmp(a->time, b->time) > 0)
            {
                a->next = b->next;
                p->next = b;
                b->next = a;
            }
            p = p->next;
            a = p->next;
            b = a->next;
        }
    }
    Save1(L);
    BianliList1(L);
    return L;
}
// ��ѯ�޸�
void CircleName(char name[], Position p, List L, List1 L1) // ����
{
    system("cls");
    while (p) // �ж�P��Nextָ���Ƿ�Ϊ�գ���P����һ�����Ŀͻ��绰�Ƿ�Ϊ�����˺�
    {
        if (strcmp(name, p->name) == 0)
        {
            PrintClient(p);
            printf("\n�Ƿ��������޸ĵ��˻����ظ�'Y'/'N'\n");
            if (getchar() == 'Y')
            {
                char a[20];
                strcpy(a, p->password);
                Mimayincan(a);
                ModMeun1(p, L, L1);
            }
            else if (getchar() == 'N')
                CircleName(name, p->next, L, L1);
        }
        p = p->next;
        if (!p)
        {
            printf("\n���˺Ų����ڣ� ");
            system("pause");
        }
    }
}
void CircleID(char ID[], Position p, List L, List1 L1) // ���֤
{
    system("cls");
    while (p) // �ж�P��Nextָ���Ƿ�Ϊ�գ���P����һ�����Ŀͻ��绰�Ƿ�Ϊ�����˺�
    {
        if (strcmp(ID, p->ID) == 0)
        {
            PrintClient(p);
            printf("\n�Ƿ��������޸ĵ��˻����ظ�'Y'/'N'\n");
            if (getchar() == 'Y')
            {
                char a[20];
                strcpy(a, p->password);
                Mimayincan(a);
                ModMeun1(p, L, L1);
            }
            else if (getchar() == 'N')
                CircleID(ID, p->next, L, L1);
        }
        p = p->next;
        if (!p)
        {
            printf("\n���˺Ų����ڣ� ");
            system("pause");
        }
    }
}
void CircleTel(char tel[], Position p, List L, List1 L1) // �绰
{
    system("cls");
    while (p) // �ж�P��Nextָ���Ƿ�Ϊ�գ���P����һ�����Ŀͻ��绰�Ƿ�Ϊ�����˺�
    {
        if (strcmp(tel, p->tel) == 0)
        {
            PrintClient(p);
            printf("\n�Ƿ��������޸ĵ��˻����ظ�'Y'/'N'\n");
            if (getchar() == 'Y')
            {
                char a[20];
                strcpy(a, p->password);
                Mimayincan(a);
                ModMeun1(p, L, L1);
            }
            else if (getchar() == 'N')
                CircleTel(tel, p->next, L, L1);
        }
        p = p->next;
        if (!p)
        {
            printf("\n���˺Ų����ڣ� ");
            system("pause");
        }
    }
}
// �޸ĺ���
void ModName(Position p, List L, List1 L1) // ����
{
    char name[10];
    Position1 p1 = L1->next;
    Position p2 = L->next;
    printf("\n�������µ�����: ");
    gets(name);
    while (p2)
    {
        if (strcmp(p->ID, p2->ID) == 0)
        {
            strcpy(p2->name, name);
            Save(L);
        }
        p2 = p2->next;
    }
    while (p1)
    {
        if (strcmp(p->ID, p1->ID) == 0)
        {
            strcpy(p1->name, name);
            Save1(L1);
        }
        p1 = p1->next;
    }
    system("pause");
}
void ModTel(Position p, List L) // �绰
{
    char tel[20];
    printf("\n�������µĵ绰��:  ");
    gets(tel);
    strcpy(p->tel, tel);
    Save(L); // ������Ϣ���溯��
    system("pause");
}
void ModPassword(Position p, List L) // ����
{
    char a[20];
    printf("\n�������µ�����: ");
    gets(a);
    strcpy(p->password, a);
    Save(L);
    system("pause");
}

/********************************���ܺ�������******************************************/
Position Logon(List L) // ��¼����
{
    char password[20], num[30], a[7] = "����", b[7] = "����", c[7] = "��ʧ"; // ���룬�˺�
    int f;
    printf("\n\t\t�����������˺�: ");
    gets(num);
    Position p = L->next;
    while (p != NULL && strcmp(num, p->num) != 0)
        p = p->next;
    if (!p)
    {
        printf("\n\t\t���˺Ų����ڣ�");
        system("pause");
        return NULL;
    }
    if (strcmp(p->sd, b) == 0)
    {
        printf("\n\t\t���˺��ѱ��������뵽��̨������");
        system("pause");
        return NULL;
    }
    if (strcmp(p->sd, c) == 0)
    {
        printf("\n\t\t���˺��Ա���ʧ���뵽��̨ȡ����ʧ��");
        system("pause");
        return NULL;
    }
    strcpy(password, p->password);
    if (strcmp(p->sd, a) == 0)
        f = Mimayincan(password);
    if (f == 1)
        return p;
    else
    {
        printf("\n\t\t���˺��ѱ��������뵽��̨������\n");
        strcpy(p->sd, b);
        Save(L);
        system("pause");
        return NULL;
    }
}
int Mimayincan(char a[]) // �������غ���//�˸�ɾ*
{
    int i, j = 0, flag = 0;
    char b[20];
    int n = strlen(a);
    while (j < 3)
    {
        printf("\n\t\t��������������(����20λ)��");
        for (i = 0; i < n; i++)
        {
            b[i] = getch();
            if (i > 0 && b[i] == '\b')
            {
                i = i - 2;
                printf("\b");
            }
            else
                printf("*");
        }
        b[i] = '\0';
        j++;
        if (strncmp(a, b, n) == 0)
            return 1;
        else if (j < 3)
            printf("\n\t\t�����������������\n\a");
        else if (flag == 0)
        {
            printf("\n\t\t��Ǹ�����˺���ʱ�ѱ�����\n");
            return 0;
        }
    }
    return 1;
}
void PrintClient(Position p) // �ͻ���Ϣ��ӡ����
{
    printf("\n�ͻ���Ϣ����:\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("�˺�\t\t\t����\t\t�绰  \t\t���\t\t\t\t״̬\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("%-20s\t%-10s\t%-11s\t%-20.2lf\t\t%-5s\n", p->num, p->name, p->tel, p->money, p->sd);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}
void PrintRecords(Position1 p) // ��֧��¼��ӡ����
{
    printf("\n\t\t\t\t��֧��¼����:\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - -\n");
    printf("�˺�\t\t\t����\t\t��������\t\t��ȡ��                  \n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - -\n");
    printf("%-20s\t%-10s\t%-18s\t%-.2lf          \n", p->num, p->name, p->time, p->rmb);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - -\n");
}
int Testl(int a, int b, int c) // �˵������⺯��
{
    while (a < b || a > c)
    {
        fflush(stdin); // ������̻�����
        printf("\n\t\t\t�����������������: ");
        scanf("%d", &a);
    }
    return a;
}
void jieshuo(List L, List1 L1)
{
    char ID[20], num[30], a[7] = "����", c[7] = "��ʧ";
    int x;
    Position p = L->next;
    Position1 p1 = L1->next;
    printf("\n\t\t��������Ҫѡ��Ĳ�����1.�����˺� 2.�˺Ź�ʧ 3.ȡ����ʧ 0.������һ��");
    printf("\n\n\t\t����������ѡ��:\n");
    while (1)
    {
        scanf("%d", &x);
        x = Testl(x, 0, 3);
        fflush(stdin); // ������̻�����
        switch (x)
        {
        case 1:
            printf("\n\t\t����������Ҫ�������˺ţ�");
            gets(num);
            while (p != NULL && strcmp(num, p->num) != 0)
                p = p->next;
            if (!p)
            {
                printf("\n\t\t���˺Ų�����");
                system("pause");
                return;
            }
            else if (strcmp(p->sd, a) == 0)
            {
                printf("\n\t\t���˺�δ������");
                system("pause");
                return;
            }
            printf("\n\t\t�������������֤�ţ� "); // ȷ�������Ϣ
            gets(ID);
            if (strcmp(ID, p->ID) == 0)
            {
                strcpy(p->sd, a);
                Save(L);
                ModPassword(p, L);
            }
            while (p1) // �޸���֧��¼��Ϣ
            {
                if (strcmp(p->num, p1->num) == 0)
                {
                    strcpy(p1->sd, a);
                    Save1(L1);
                }
                p1 = p1->next;
            }
            MainMeun1(L, L1);
            break;
        case 2:
            printf("\n\t\t����������Ҫ��ʧ���˺ţ�");
            gets(num);
            while (p != NULL && strcmp(num, p->num) != 0)
                p = p->next;
            if (!p)
            {
                printf("\n\t\t���˺Ų�����");
                system("pause");
                return;
            }
            else if (strcmp(p->sd, c) == 0)
            {
                printf("\n\t\t���˺��ѹ�ʧ");
                system("pause");
                return;
            }
            printf("\n\t\t�������������֤�ţ� "); // ȷ�������Ϣ
            gets(ID);
            if (strcmp(ID, p->ID) != 0)
            {
                printf("\n\t\t���֤��������");
                system("pause");
                return;
            }
            Mimayincan(p->password);
            strcpy(p->sd, c);
            Save(L);
            while (p1) // �޸���֧��¼����Ϣ
            {
                if (strcmp(p->num, p1->num) == 0)
                {
                    strcpy(p1->sd, c);
                    Save1(L1);
                }
                p1 = p1->next;
            }
            MainMeun1(L, L1);
            break;
        case 3:
            printf("\n\t\t����������Ҫȡ����ʧ���˺ţ�");
            gets(num);
            while (p != NULL && strcmp(num, p->num) != 0)
                p = p->next;
            if (!p)
            {
                printf("\n\t\t���˺Ų�����");
                system("pause");
                return;
            }
            else if (strcmp(p->sd, a) == 0)
            {
                printf("\n\t\t���˺�δ��ʧ");
                system("pause");
                return;
            }
            printf("\n\t\t�������������֤�ţ� "); // ȷ�������Ϣ
            gets(ID);
            if (strcmp(ID, p->ID) != 0)
            {
                printf("\n\t\t���֤��������");
                system("pause");
                return;
            }
            Mimayincan(p->password);
            strcpy(p->sd, a);
            Save(L);
            while (p1) // �޸���֧��¼����Ϣ
            {
                if (strcmp(p->num, p1->num) == 0)
                {
                    strcpy(p1->sd, a);
                    Save1(L1);
                }
                p1 = p1->next;
            }
            MainMeun1(L, L1);
            break;
        case 0:
            MainMeun1(L, L1);
            break; // ������һ��
        }
    }
}
