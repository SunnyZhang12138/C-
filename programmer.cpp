#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include<conio.h>
#include<windows.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>vec[200];//�����һ���ַ�������
#define ture 1
#define false -1
#pragma warning(disable:4996)
#pragma comment(lib, "Winmm.lib")
struct word
{
	char english[200];
	char chinese[200];
	char example[2000];
};

void wait()
{
	int c;
	rewind(stdin);
	printf("Press down any key to continue...\n");
	c = getch();//�����Զ���ȡһ���ַ������谴�س�Ҳ����ʾ����Ļ��
}

int ReadWordInfo(const char *filename, struct word **pwords)
{
	FILE *filer;
	int n = 0, i = 0, len = 0;
	filer = fopen(filename, "r"); //�����ļ���������
	if (filer == nullptr)		  //����ļ�����ʧ�ܣ������ʾ�������ش���
	{
		printf("Failed to load file!\n");
		return false;
	}
	while (!feof(filer)) //�����ļ��������������㵥������
	{
		char str[100] = { NULL };	 //Ϊ������������Ļ��з���ÿ�ζ���ʼ��str
		fgets(str, 1024, filer); //fgets()���з�ֹͣ
		if (((int)str[1] > 64 && (int)str[1] < 91) || ((int)str[1] > 96 && (int)str[1] < 123))
			n++; //���ݵ�ǰ��λ�ǲ���a~z��ͷ���ж��Ƿ��ǵ�����Ϣ,���򵥴�����һ
		else
		{
			if (strlen(str) > 1)
				len = len + 1 + strlen(str); //���㿪ͷ��Ҫ�������ַ���
		}
	}
	rewind(filer); //�ص��ļ���ͷ
	*pwords = (struct word*)malloc(n * sizeof(struct word));
	fseek(filer, len, SEEK_SET); //��λ�������ݵĿ�ͷ�������ݿ�ͷ
	word *p = *pwords;
	while (!feof(filer)) //ɨ���ļ�������ṹ�壬�������ļ�����ѧ��ѧϰ�Ĳ���
	{
		if (i == n)
			break;						   //��ɨ��ȷ��������֮��ֹͣɨ��
		fscanf(filer, "%s", (p + i)->english); //Ӣ��
		fscanf(filer, "%s", (p + i)->chinese); //����
		fscanf(filer, "%[^\n]%*c", (p + i)->example); //����
		i++;
	}
	fclose(filer);	return n;
}

void pronounce(int i)
{
	string str[] = { "D:/1/1", "D:/1/2","D:/1/3","D:/1/4","D:/1/5","D:/1/6","D:/1/7","D:/1/8","D:/1/9","D:/1/10","D:/1/11","D:/1/12","D:/1/13","D:/1/14",
		"D:/1/15","D:/1/16","D:/1/17","D:/1/18","D:/1/19","D:/1/20","D:/1/21","D:/1/22","D:/1/23","D:/1/24","D:/1/25","D:/1/26","D:/1/27","D:/1/28",
		"D:/1/29","D:/1/30","D:/1/31","D:/1/32","D:/1/33","D:/1/34","D:/1/35","D:/1/36","D:/1/37", "D:/1/38","D:/1/39","D:/1/40","D:/1/41","D:/1/42",
		"D:/1/43","D:/1/44","D:/1/45","D:/1/46","D:/1/47","D:/1/48","D:/1/49","D:/1/50","D:/1/51","D:/1/52","D:/1/53","D:/1/54","D:/1/55","D:/1/56",
		"D:/1/57","D:/1/58","D:/1/59","D:/1/60","D:/1/61","D:/1/62","D:/1/63","D:/1/64","D:/1/65","D:/1/66","D:/1/67","D:/1/68","D:/1/69","D:/1/70",
		"D:/1/71","D:/1/72","D:/1/73","D:/1/74","D:/1/75","D:/1/76","D:/1/77","D:/1/78","D:/1/79","D:/1/80","D:/1/81","D:/1/82","D:/1/83","D:/1/84",
		"D:/1/85","D:/1/86","D:/1/87","D:/1/88","D:/1/89","D:/1/90","D:/1/91","D:/1/92","D:/1/93","D:/1/94","D:/1/95","D:/1/96","D:/1/97","D:/1/98",
		"D:/1/99","D:/1/100","D:/1/101","D:/1/102","D:/1/103","D:/1/104","D:/1/105","D:/1/106","D:/1/107","D:/1/108","D:/1/109","D:/1/110","D:/1/111",
		"D:/1/112","D:/1/113","D:/1/114","D:/1/115","D:/1/116","D:/1/117","D:/1/118","D:/1/119","D:/1/120","D:/1/121","D:/1/122","D:/1/123","D:/1/124",
		"D:/1/125","D:/1/126","D:/1/127","D:/1/128","D:/1/129","D:/1/130","D:/1/131","D:/1/132","D:/1/133","D:/1/134","D:/1/135","D:/1/136","D:/1/137",
		"D:/1/138","D:/1/139","D:/1/140","D:/1/141","D:/1/142","D:/1/143","D:/1/144","D:/1/145","D:/1/146","D:/1/147","D:/1/148","D:/1/149","D:/1/150",
		"D:/1/151","D:/1/152","D:/1/153","D:/1/154","D:/1/155","D:/1/156","D:/1/157","D:/1/158","D:/1/159","D:/1/160","D:/1/161","D:/1/162","D:/1/163",
		"D:/1/164","D:/1/165","D:/1/166","D:/1/167","D:/1/168","D:/1/169","D:/1/170","D:/1/171","D:/1/172","D:/1/173","D:/1/174","D:/1/175","D:/1/176",
		"D:/1/177","D:/1/178","D:/1/179","D:/1/180","D:/1/181","D:/1/182","D:/1/183","D:/1/184","D:/1/185","D:/1/186","D:/1/187","D:/1/188","D:/1/189",
		"D:/1/190","D:/1/191","D:/1/192","D:/1/193","D:/1/194","D:/1/195","D:/1/196","D:/1/197","D:/1/198","D:/1/199","D:/1/200","\n" };
	vector<string> vec(str, str + sizeof(str) / sizeof(str[0]));
	PlaySound(TEXT(vec[i].c_str()), NULL, SND_FILENAME | SND_SYNC);
}

void StudyWord(int num, struct word*p)
{
	int i, x = 0;
	printf("������Ϣ��\n");
	printf("------------------------------------------------------------------");
	printf("\n���\t����\t����\t����\t\n");
	while (1)
	{
		for (i = 0; i < num; i++)
		{
			printf("����1��ʼ����ѧϰ,����-1��������ѧϰ");
			scanf("%d", &x);
			if (x == 1)
			{
				printf("%d\t%s\t%s\t%s\t\n", i + 1, (p + i)->english, (p + i)->chinese, (p + i)->example);
				pronounce(i);
				printf("\n\n");
			}
			else if (x == -1)
			{
				break;
			}
		} break;
	 }
}

void EtoC(int num, struct word*p)
{
	int i, x = 0, n = 0;
	char ch[20];
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf("����1��ʼ����ѧϰ,����-1��������ѧϰ");
		scanf("%d", &x);
		if (x == 1)
		{
			i = rand() % num;
			printf("���ʣ�%s\t", (p + i)->english);
			printf("�������Ӧ���ģ�");
			scanf("%s", &ch);
			if (strcmp(ch, (p + i)->chinese) == 0)
			{
				printf("Congratulations��\n");
				n++;
			}
			else
			{
				printf("Sorry, your answer is wrong!\n");
				printf("������Ϣ��\n");
				printf("------------------------------------------------------------------");
				printf("\n����\t����\t����\t\n");
				printf("%s\t%s\t%s\t\n", (p + i)->english, (p + i)->chinese, (p + i)->example);
				pronounce(i);
			}
		}
		else if (x == -1)
		{
			printf("��ķ����ǣ�%d��\n", n);
			break;
		}
	}
}

void EtoC2(int num, struct word* p)
{
	int i, x = 0, q = 0;
	int s[4];
	int m, n, temp;
	char choice[2];
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf("����1��ʼ����ѧϰ,����-1��������ѧϰ");
		scanf("%d", &x);
		if (x == -1)
		{
			printf("��ķ����ǣ�%d��\n", q);
			break;
		}
		else if (x == 1)
		{
			i = rand() % num;
			s[0] = i;
			for (m = 1; m < 4; m++)
			{
				s[m] = rand() % num;
				for (n = 0; n < m; n++)
				{
					if (s[m] == s[n])
					{
						m--;
					}
				}
			}
			for (m = 1; m < 4; m++)
			{
				for (n = 0; n < (4 - m); n++)
				{
					if (s[n] < s[n + 1])
					{
						temp = s[n];
						s[n] = s[n + 1];
						s[n + 1] = temp;
					}
				}
			}
			printf("���ʣ�%s\t\n", (p + i)->english);
			printf("��������ѡ����ѡ����ȷѡ�\n");
			printf("A %s\tB %s\tC %s\tD %s\n", (p + s[0])->chinese, (p + s[1])->chinese, (p + s[2])->chinese, (p + s[3])->chinese);
			printf("����������ѡ��");
			scanf("%s", &choice[0]);
			switch (choice[0])
			{
			case 'A':
				if (s[0] == i)
				{
					printf("Congratulations��\n");
					q++;
				}
				else
				{
					printf("Sorry, your answer is wrong!\n");
					printf("������Ϣ��\n");
					printf("------------------------------------------------------------------");
					printf("\n����\t����\t����\t\n");
					printf("%s\t%s\t%s\t\n", (p + i)->english,(p + i)->chinese, (p + i)->example);
					pronounce(i);
				} break;
			case 'B':
				if (s[1] == i)
				{
					printf("Congratulations��\n");
					q++;
				}
				else
				{
					printf("Sorry, your answer is wrong!\n");
					printf("������Ϣ��\n");
					printf("------------------------------------------------------------------");
					printf("\n����\t����\t����\t\n");
					printf("%s\t%s\t%s\t\n", (p + i)->english, (p + i)->chinese, (p + i)->example);
					pronounce(i);
				} break;
			case 'C':
				if (s[2] == i)
				{
					printf("Congratulations��\n");
					q++;
				}
				else
				{
					printf("Sorry, your answer is wrong!\n");
					printf("������Ϣ��\n");
					printf("------------------------------------------------------------------");
					printf("\n����\t����\t����\t\n");
					printf("%s\t%s\t%s\t\n", (p + i)->english,(p + i)->chinese, (p + i)->example);
					pronounce(i);
				} break;
			case 'D':
				if (s[3] == i)
				{
					printf("Congratulations��\n");
					q++;
				}
				else
				{
					printf("Sorry, your answer is wrong!\n");
					printf("������Ϣ��\n");
					printf("------------------------------------------------------------------");
					printf("\n����\t����\t����\t\n");
					printf("%s\t%s\t%s\t\n", (p + i)->english,(p + i)->chinese, (p + i)->example);
					pronounce(i);
				} break;
			}
		}
	}
}


void CtoE(int num, struct word *p)
{
	int i, x = 0, n = 0;
	char en[20];
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf("����1��ʼ����ѧϰ,����-1��������ѧϰ");
		scanf("%d", &x);
		if (x == 1)
		{
			i = rand() % num;
			printf("���ģ�%s\t", (p + i)->chinese);
			printf("�������Ӧ���ʣ�");
			scanf("%s", &en);
			if (strcmp(en, (p + i)->english) == 0)
			{
				printf("Congratulations��\n");
				n++;
			}
			else
			{
				printf("Sorry, your answer is wrong!\n");
				printf("������Ϣ��\n");
				printf("------------------------------------------------------------------");
				printf("\n����\t����\t����\t\n");
				printf("%s\t%s\t%s\t\n", (p + i)->english, (p + i)->chinese, (p + i)->example);
				pronounce(i);
			}
		}
		else if (x == -1)
		{
			printf("��ķ����ǣ�%d��\n", n); break;
		}
	}
}

void SearchWord(int num, struct word* p)
{
	int i, x = 0;
	int flag;
	char* str;
	str = (char*)malloc(20 * sizeof(double));
	while (1)
	{
		flag = 0;
		printf("����1��ʼ���ֲ���,����-1�������ֲ���");
		scanf("%d", &x);
		if (x == -1)
			break;
		else if (x == 1)
		{
			printf("��������Ҫ���ҵĵ��ʣ�");
			scanf("%s", str);
			for (i = 0; i < num; i++)
			{
				if (strcmp(str, (p + i)->english) == 0)
				{
					printf("������Ϣ��\n");
					printf("------------------------------------------------------------------");
					printf("\n����\t����\t\t����\t\n");
					printf("%s\t%s\t%s\t\n", (p + i)->english, (p + i)->chinese, (p + i)->example);
					flag = 1;
					pronounce(i);
					break;
				}
			}
			if (flag == 0)
			{
				printf("Sorry!We don't have this word\n");
			}

		}
	}
}

int menu()
{
	int n = -1;
	system("cls");
	printf("���е��ʳ�����ѡ���ܣ�������Ӧ�����֣�                              \n");
	printf("************************************************************************\n");
	printf("=    1:�������Ӣ�ġ����ġ��������ѧϰ                                =\n");
	printf("=    2:����Ӣ�ﵥ�ʣ�Ĭд������˼                                      =\n");
	printf("=    3:����Ӣ�ﵥ�ʣ�ѡ��������˼                                      =\n");
	printf("=    4:����������˼��ĬдӢ�ﵥ��                                      =\n");
	printf("=    5:����Ӣ�ﵥ�ʣ�����������˼                                      =\n");
	printf("=    0:������                                                          =\n");
	printf("========================================================================\n");
	while (n < 0 || n > 5)
	{
		scanf("%d", &n);
	}
	return n;
}

int main()
{
	int n = -1;
	int num;
	struct word *p = {};
	const char *filename = "D:/wordData.txt";
	num = ReadWordInfo(filename, &p); //��ȡ�������ݣ����ص�����
	while (1)
	{
		n = menu();
		switch (n)
		{
		case 1:
		{
			StudyWord(num, p); wait(); break;
		}
		case 2:
		{
			EtoC(num, p); wait(); break;
		}
		case 3:
		{
			EtoC2(num, p); wait(); break;
		}
		case 4:
		{
			CtoE(num, p); wait(); break;
		}
		case 5:
		{
			SearchWord(num, p);	wait();	break;
		}
		case 0:
		{
			exit(0);
		}
		}
	}
	return 0;
}


