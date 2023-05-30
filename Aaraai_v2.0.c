#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
FILE *sk;
long int drcnt[10], flh[10], *fldFndDatI, *fldFndDatJ, fnd = 0, yy = 4;
char dr[10] = {'D', 'E', 'F', 'C'}, str[200], ***fldrs, ***fldrsm;
int xy(int x, int y)
{
	COORD san = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), san);
}
display()
{
	xy(0, 0);
	system("color 1b");
	printf("\t\t\tWELCOME TO AARAAI!!!");
	printf("\n\t\t\t    Version 2.0");
	printf("\n\t\t\t    Developer: Sanjeev Kumar S K");
	printf("\n\nSearch --> ");
}
returnArr()
{
	char d = 0, c;
	long int m;
	c = getch();
	if (c == -32)
	{
		d = getch();
	}
	if (d != 0)
	{
		c = 6;
	}
	m = (d * 1000) + c;
	return m;
}
main()
{
	int loc;
	display();
	folderScan();
	folderHScan();
	while (1)
	{
		loc = nameGet();
		openFolder(loc);
	}
}
openFolder(int loc)
{
	loc = (yy - 7) / 3;
	char cmdc[300] = {"start "};
	cmdc[6] = '"';
	cmdc[7] = '"';
	cmdc[8] = ' ';
	cmdc[9] = '"';
	strcat(cmdc, fldrsm[fldFndDatI[loc]][fldFndDatJ[loc]]);
	int x = strlen(cmdc);
	cmdc[x - 1] = '"';
	cmdc[x] = '\0';
	system(cmdc);
}
refreshDB()
{
	printf("\n\n Refreshing Database.. Please wait..\n");
	FILE *fd, *sfd;
	int i, k, j;
	char c[300], adr[40] = {"dir x:\\* /b /s >>xfilsdt.txt"}, sdr[15] = "xfhsh.txt", fdr[15] = {"xfilsdt.txt"};
	for (i = 0; i < 10 && dr[i] != '\0'; i++)
	{
		adr[4] = dr[i];
		adr[17] = dr[i];
		fdr[0] = dr[i];
		sdr[0] = dr[i];
		sfd = fopen(sdr, "w+");
		system(adr);
		fd = fopen(fdr, "r+");
		while (fgets(c, 300, fd) != NULL)
		{
			k = 0;
			char tmp[300] = {"\0"};
			drcnt[i]++;
			for (j = strlen(c) - 1; j >= 0; j--)
			{
				if (c[j] == '\\' || c[j] == '//')
					break;
				tmp[k++] = c[j];
			}
			strrev(tmp);
			strupr(tmp);
			fputs(tmp, sfd);
		}
		fclose(sfd);
		printf("Done-%c\n", dr[i]);
	}
	fclose(fd);
}
get_drives()
{
	FILE *drvs;
	char c[20];
	long int i = 0;
	system("wmic logicaldisk get name >>drvlst.dat");
	drvs = fopen("drvlst.dat", "r+");
	while (fgets(c, 20, drvs) != NULL)
	{
		printf("%s\n", c);
	}
	printf("%d\n", i);
	fclose(drvs);
}
findHash(char ch[100])
{
	int i, j, stlen, chi, chlen, fo, kp, l, k;
	strupr(ch);
	fnd = 0;
	for (i = 0; i < 10 && dr[i] != '\0'; i++)
	{
		for (j = 0; j < flh[i] && j >= 0; j++)
		{
			stlen = strlen(fldrs[i][j]);
			chlen = strlen(ch);
			fo = 0;
			for (k = 0; k < stlen; k++)
			{
				if (fldrs[i][j][k] == ch[0])
				{
					chi = 1;
					kp = k + chlen;
					for (l = k + 1; l < kp && l < stlen; l++)
					{
						if (fldrs[i][j][l] != ch[chi++])
						{
							break;
						}
						if (l == kp - 1)
						{
							fo = 1;
						}
					}
				}
				if (fo == 1)
				{
					fldFndDatI[fnd] = i;
					fldFndDatJ[fnd] = j;
					fnd++;
					break;
				}
			}
		}
	}
}
nameGet()
{
	int ii = 0, i, ch;
	char string[100] = {"\0"};
	yy = 7;
	display();
	while (1)
	{
		xy(ii + 11, 3);
		ch = returnArr();
		system("cls");
		if (ch / 1000 == 0)
		{
			ch %= 1000;
			if (ch == 8 && ii > 0)
			{
				--ii;
				string[ii] = '\0';
			}
			else if (ch >= 32 && ch <= 122)
			{
				string[ii] = ch;
				string[ii + 1] = '\0';
				ii++;
			}
			else if (ch == 13)
			{
				return yy;
			}
		}
		else
		{
			ch /= 1000;
			switch (ch)
			{
			case 72:
			{
				if (yy > 8)
					yy -= 3;
				break;
			}
			case 75:
			{

				break;
			}
			case 77:
			{

				break;
			}
			case 80:
			{
				if (yy < 35)
					yy += 3;
				break;
			}
			}
		}

		if (strcmp(string, "```-```") == 0)
		{
			system("cls");
			printf("Do you want to refresh? (Y/N):\n");
			char c = getchar();
			if (c == 'Y' | c == 'y')
			{

				refreshDB();
			}
			break;
		}
		if (ii > -1)
		{
			findHash(string);
			display();
			printf("%s", string);
			if (fnd == 0)
				printf("\n\nNo Files..");
			else
			{
				printf("\n\nFiles found..\n\n");
				for (i = 0; i < fnd && i < 10; i++)
				{
					printf("\t%d. %s\t\tDrive - %c\n\n", i + 1, fldrs[fldFndDatI[i]][fldFndDatJ[i]], dr[fldFndDatI[i]]);
				}
				xy(4, yy);
				printf("%c", 175);
			}
		}
	}
}
folderHScan()
{
	long int i = 0, j, maxn = 0;
	char fl[10] = "xfhsh.txt", ch[10];
	fldrs = (char ***)malloc(10 * sizeof(char **));
	FILE *sk;
	for (i = 0; i < 10; i++)
	{
		fldrs[i] = (char **)malloc((flh[i]) * sizeof(char *));
		for (j = 0; j < (flh[i]); j++)
		{
			fldrs[i][j] = (char *)malloc(300 * sizeof(char));
		}
	}
	for (i = 0; i < 10 && dr[i] != '\0'; i++)
	{
		j = 0;
		fl[0] = dr[i];
		sk = fopen(fl, "r");
		while (fgets(fldrs[i][j], 300, sk) != NULL)
		{
			j++;
		}
		fclose(sk);
	}
}
folderScan()
{
	long int i = 0, j, maxn = 0;
	char fl[15] = "xfilsdt.txt", tmp[400], ch[10];
	fldrsm = (char ***)malloc(10 * sizeof(char **));
	FILE *sk;
	for (i = 0; i < 10 && dr[i] != '\0'; i++)
	{
		j = 0;
		fl[0] = dr[i];
		sk = fopen(fl, "r+");
		while (fgets(tmp, 400, sk) != NULL)
		{
			j++;
		}
		if (j > maxn)
			maxn = j;
		flh[i] = j + 100;
	}
	fldFndDatJ = (int *)malloc(maxn * sizeof(int));
	fldFndDatI = (int *)malloc(maxn * sizeof(int));
	for (i = 0; i < 10; i++)
	{
		fldrsm[i] = (char **)malloc((flh[i]) * sizeof(char *));
		for (j = 0; j < (flh[i]); j++)
		{
			fldrsm[i][j] = (char *)malloc(400 * sizeof(char));
		}
	}
	for (i = 0; i < 10 && dr[i] != '\0'; i++)
	{
		j = 0;
		fl[0] = dr[i];
		sk = fopen(fl, "r++");
		while (fgets(fldrsm[i][j], 400, sk) != NULL)
		{
			j++;
		}
		fclose(sk);
	}
}
