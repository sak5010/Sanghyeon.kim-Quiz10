#define MAX 50
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct people {
	char name[20];
	char phone[20];
};

int main(void)
{
	int Ctr = 0;
	char password[20];
	char Rpassword[20] = "qwer1234";
	struct people* p[MAX];
	int count = 0;
	int i;
	int size = 0;
	char Sname[20];

	for (i = 0; i < MAX; ++i)
	{
		p[i] = (struct people*)malloc(sizeof(struct people));
	}

	while (Ctr != 5)
	{
		printf("전화번호 관리\n");
		printf("1.등록 2.전체검색 3.특정인검색 4.제거 5.종료\n");
		printf("메뉴선택: ");

		scanf("%d", &Ctr);

		switch (Ctr) {
		case 1:
			printf("\n비밀번호: ");
			scanf("%s", password);
			while (count != 3)
			{
				if ((strcmp(password, Rpassword)) == 0)
				{
					printf("\n등록할 이름: ");
					scanf("%s", p[size]->name);
					printf("\n전화번호: ");
					scanf("%s", p[size]->phone);
					printf("\n");
					printf("%s 정보 등록 완료!\n", 
						p[size]->name);
					size++;
					break;
				}
				else
				{
					++count;
					printf("비밀번호(%d회실패): ", count);
					printf("\n");
					printf("비밀번호: ");
					scanf("%s", password);
					printf("\n");
					if (count == 3)
					{
						printf("등록할 수 없음!\n\n");
						printf("프로그램을 종료합니다.\n");
						Ctr = 5;
					}
				}
			}
			break;
		case 2:
			printf(" << 전화번호 목록 >> \n");
			for (i = 0; i < size; ++i)
				printf("%s %s\n", p[i]->name, p[i]->phone);
			break;
		case 3:
			printf("검색할 이름: ");
			scanf("%s", Sname);
			i = 0;
			while (strcmp(Sname, p[i]->name) != 0)
			{
				i++;
			}
			printf("%s %s\n", p[i]->name, p[i]->phone);
			break;
		case 4:
			printf("삭제할 이름: ");
			scanf("%s", Sname);
			i = 0;
			while (strcmp(Sname, p[i]->name) != 0)
			{
				++i;
			}
			printf("%s ㅈ어보 삭제 완료!\n", p[i]->name);
			for (i; i < size-1; ++i)
				p[i] = p[i + 1];
			--size;
			break;
		case 5:
			printf("프로그램을 종료합니다.\n");
			break;
		}
	}
	for (i = 0; i < MAX; ++i)
	{
		free(p[i]);
	}

	return 0;
}

