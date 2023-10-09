//   LIBRARY MANAGEMENT SYSTEM

// User Id : test
// Passwrod : pswd

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void welcome_msg(void);                 // Declaration of Welcome Screen
void username_pass(void);               // Declaration of Login screen
void mainmenu(void);                    // Declartion for main menu screen

void addbooks(void);
void displaybooks(void);
void searchbook(void);
void listbooks(void);
void totalbooks(void);
void deletebooks(void);
void endscreen(void);

struct library
{
	int bk_id;
	char bk_name[30];
	char author[30];
	int pages;
	float price;
} li; //Global declaration can be used from anywhere in the program

FILE *f1, *fr, *fd; //Global declaration of the files.

int main(void)
{

	welcome_msg();
	username_pass();
	mainmenu();
	return 0;
}

// WELCOME SCREEN

void welcome_msg(void)
{
	char c;
	printf("\n\n\n\n\n");
	printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\n\t\t\t\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\t\t\t\t       =                 WELCOME                   =");
	printf("\n\t\t\t\t       =                   TO                      =");
	printf("\n\t\t\t\t       =                 LIBRARY                   =");
	printf("\n\t\t\t\t       =               MANAGEMENT                  =");
	printf("\n\t\t\t\t       =                 SYSTEM                    =");
	printf("\n\t\t\t\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("\n\t\t\t\t  ..........................................................\n");
	printf("\n\n\n\t\t\t Enter any key to continue.....");
	getch();
}

/* login using id and pass */

void username_pass(void)
{

	system("cls"); // Used to clear the screen
	char str[] = "test";
	char pwd[] = "pswd";
	char str2[20];
	char pwd2[20];
	int i = 0;
	printf("\n\n\t\t\t   Enter Username and password : ");
	printf("\n\t\t*_*-----------------------------------------------*_*");
	while (i < 3)
	{
		printf("\n\n\n\t\t  Username: ");
		gets(str2);
		printf("\n\t\t  Password: ");
		gets(pwd2);

		if (strcmp(str, str2) == 0)
		{
			if (strcmp(pwd, pwd2) == 0)
			{
				printf("\n\n\t\t  Press any key to continue...");
				getch();
				mainmenu();
			}
			else
			{
				printf("\n\t\t*_* Wrong password\n");
				i++;
			}
		}
		else
		{
			printf("\n\t\t*_* Wrong username\n");
			i++;
		}
	}
	if (i == 3)
	{
		printf("\n\n\t\t**-** -- Too many wrong attempts -- **-** ");
		getch();
		exit(0);
	}
}

/* MAIN MENU */

void mainmenu(void)
{
	system("cls");

	char ar_nm[30], bk_nm[30];
	int i, j;
	i = j = 0;

	while (j != 6)
	{
		system("cls");
		printf("\n\n\n\t\t\t\t    MAIN MENU ");
		printf("\n\t\t*|*-------------------------------------------*|*");
		printf("\n\n\n\t\t1. Add book information \n");
		printf("\t\t2. Display Books information \n");
		printf("\t\t3. Search a Book \n");
		printf("\t\t4. List the title of books\n");
		printf("\t\t5. Number of books in the library\n");
		printf("\t\t6. Delete book information\n");
		printf("\t\t7. Exit");

		printf("\n\n\n\t\tEnter one of the above : ");
		scanf("%d", &j);

		if (j > 7)
		{
			printf("\n\t\tPlease Enter a valid option");
			getch();
			mainmenu();
		}

		switch (j)
		{

			/* Add book */
		case 1:
			addbooks();
			break;

			/* Display books */
		case 2:
			displaybooks();
			break;

			/* Search Book */
		case 3:
			searchbook();
			break;

			/* List by title of books */
		case 4:
			listbooks();
			break;

			/* Number of books */
		case 5:
			totalbooks();
			break;

			/* Delete book infomation */
		case 6:
			deletebooks();
			break;

			/* End screen */
		case 7:
			endscreen();
		}
	}
}

/* Add book FUNCTION*/

void addbooks(void)
{
	system("cls");

	f1 = fopen("myfile1.txt", "a");
	printf("\n\t\t   Enter book information below: ");
	printf("\n\t *_* -------------------------------------- *_*\n\n");
	fflush(stdin);

	printf("\t\tEnter book id : ");
	scanf("%d", &li.bk_id);
	fflush(stdin);

	printf("\t\tEnter book name : ");
	gets(li.bk_name);
	fflush(stdin);

	printf("\t\tEnter author name : ");
	gets(li.author);
	fflush(stdin);

	printf("\t\tEnter pages : ");
	scanf("%d", &li.pages);
	fflush(stdin);

	printf("\t\tEnter price : ");
	scanf("%f", &li.price);
	fwrite(&li, sizeof(li), 1, f1);
	fclose(f1);

	printf("\n\t **-** BOOK SUCCESSFULLY ADDED **-**");
	printf("\n\n\t *_* Enter any key to go back to main menu...");
	
	getch();
}

/* Display books FUNCTION */

void displaybooks(void)
{
	system("cls");
	fr = fopen("myfile1.txt", "r");
	printf("\n\t\t Books available in the library\n");
	printf("\n\t **-** --------------------------------------- **-**\n\n");

	while (fread(&li, sizeof(li), 1, fr) > 0)
	{
		printf("\n\t\t Book Id : %.2d", li.bk_id);
		printf("\n\t\t Book Name : %s", li.bk_name);
		printf("\n\t\t Author Name : %s", li.author);
		printf("\n\t\t Number of pages : %d", li.pages);
		printf("\n\t\t Price of book : %.2f", li.price);
		printf("\n");
	}
	fclose(fr);
	printf("\n\n\t *_* Enter any key to go back to main menu...");
	getch();
}

/* Search Book FUNCTION*/

void searchbook(void)
{
	int b_id, choice, found = 0;
	char Bookname[20];
	system("cls");
	printf("\n\n\n\n\t\t\t Search a book : ");
	printf("\n\t *_* ------------------------------------------ *_*\n\n");
	printf("\n\t\t *-* Search By BookID   : Type 1\n");
	printf("\n\t\t *-* Search By BookName   : Type 2");
	printf("\n\n\t *_* ------------------------------------------ *_*\n");

	fflush(stdin);
	printf("\n\n\t\tEnter Your Choice : ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\n\n\t\t**-** Enter Book Id you want to search : ");
		scanf("%d", &b_id);
		fflush(stdin);
		printf("\t *-*....................................................*-*\n");
		fr = fopen("myfile1.txt", "r");
		while (fread(&li, sizeof(li), 1, fr) > 0)
		{
			if (li.bk_id == b_id)
			{
				printf("\n\t\tBook Id : %.2d", li.bk_id);
				printf("\n\t\tBook Name : %s", li.bk_name);
				printf("\n\t\tAuthor Name : %s", li.author);
				printf("\n\t\tNumber of Pages : %d", li.pages);
				printf("\n\t\tPrice of Book : %.2f", li.price);
				printf("\n\n\n\t  **-** Enter any key to get back to main menu...");
				getch();
				mainmenu();
				found = 1;
			}
		}
		if (found == 0)
		{
			printf("\n\n\t\t *-* Book is Not Present in Library for Book ID : %d ", b_id);
			printf("\n\n\n\t  **-** Enter any key to get back to main menu...");
			getch();
			mainmenu();
		}
		fclose(fr);
		break;
	case 2:
		fflush(stdin);
		printf("\n\n\t\t *-* Enter Book Name you want to search : ");
		gets(Bookname);
		printf("\t *-*.....................................................*-*\n");
		fr = fopen("myfile1.txt", "r+");
		while (fread(&li, sizeof(li), 1, fr) > 0)
		{
			if (strcmp(Bookname, li.bk_name) == 0)
			{
				printf("\n\t\tBook Id : %.2d", li.bk_id);
				printf("\n\t\tBook Name : %s", li.bk_name);
				printf("\n\t\tAuthor Name : %s", li.author);
				printf("\n\t\tNumber of Pages : %d", li.pages);
				printf("\n\t\tPrice of Book : %.2f", li.price);
				printf("\n\n\n\t  **-** Enter any key to get back to main menu...");
				getch();
				mainmenu();
				found = 1;
			}
		}
		if (found == 0)
		{
			printf("\n\n\t\t *-* Book is Not Present in Library for Book name : %s ", Bookname);
			printf("\n\n\n\t  **-** Enter any key to get back to main menu...");
			getch();
			mainmenu();
		}
		fclose(fr);
		break;
	}
	if (choice != 1 && choice != 2)
	{
		printf("\n\n\n\t   **-** Please Enter a valid option...");
		getch();
		searchbook();
	}
	getch();
}

/* List by title of books FUNCTION */

void listbooks(void)
{
	fflush(stdin);
	system("cls");
	printf("\n\n\n\n\t\t\t *_* Listed books according to the title ");
	printf("\n\t *_* -------------------------------------------------------------- *_*\n\n\n");
	fr = fopen("myfile1.txt", "r");
	int i = 1;

	while (fread(&li, sizeof(li), 1, fr) > 0)
	{
		printf("\n\t\t %.2d. Book Title : %s", i, li.bk_name);
		i++;
	}
	printf("\n\n\n\t  **-** Enter any key to get back to main menu...");
	if (i = 0)
	{
		printf("\n\n\t\t *-* No Book is available in the library ");
		printf("\n\n\n\t  **-** Enter any key to get back to main menu...");
		getch();
	}
	fclose(fr);
	getch();
}

/* Number of books FUNCTION */

void totalbooks(void)
{
	int num = 0;
	fr = fopen("myfile1.txt", "r");
	while (fread(&li, sizeof(li), 1, fr) > 0)
	{
		num++;
	}
	fclose(fr);
	if (num > 0)
	{
		printf("\n\t *_* ---------------------------------------------- *_*\n");
		printf("\n\t\t Total number of books in library : %d", num);
		printf("\n\n\t *_* ---------------------------------------------- *_*");
		printf("\n\n\n\t  **-** Enter any key to get back to main menu...");
		getch();
	}else
	{
		printf("\n\n\t\t *-* No Book is available in the library ");
		printf("\n\n\n\t  **-** Enter any key to get back to main menu...");
		getch();
	}
}

/* Delete books function */

void deletebooks(void)
{
	int b_id, found = 0;
	system("cls");
	printf("\n\n\n\n\t\t\t Delete a book : ");
	printf("\n\t *_* ------------------------------------------ *_*\n\n");
	printf("\n\n\t\tEnter Book Id you want to Delete : ");
	scanf("%d", &b_id);

	fr = fopen("myfile1.txt", "r");
	while (fread(&li, sizeof(li), 1, fr) > 0)
	{
		if (li.bk_id == b_id)
		{
			found = 1;
			printf("\n\t\tBook Id : %d", li.bk_id);
			printf("\n\t\tBook Name : %s", li.bk_name);
			printf("\n\t\tAuthor Name : %s", li.author);
			printf("\n\t\tNumber of Pages : %d", li.pages);
			printf("\n\t\tPrice of Book : %.2f", li.price);
			char yn;
			printf("\n\n\t\tAre you sure You want to delete this book  ");
			fflush(stdin);
			printf("\n\t\tEnter 'y' character to confirm you want to delete the book : ");
			scanf("%c",&yn);
			
			if(yn=='y'){
				fflush(stdin);
				continue;
			}else{
				fflush(stdin);
				fclose(fr);
				printf("\n\n\t *-* Book has not been deleted");
				printf("\n\n\t *-* Enter any key to return to main menu...");
				getch();
				mainmenu();
			}
		}
	}
	if (found == 0)
	{
		printf("\n\n\t\t *_*  Book Record Not Found");
		printf("\n\n\t *_* ------------------------------------------ *_*");
		printf("\n\n\n\t *-* Enter any key to go back to main menu ...");
		getch();
		system("cls");
		fflush(stdin);
		mainmenu();
	}
	rewind(fr);
	fd = fopen("testfile1.txt", "w");
	while (fread(&li, sizeof(li), 1, fr) > 0)
	{
		if (li.bk_id != b_id)
			fwrite(&li, sizeof(li), 1, fd);
	}
	fclose(fr);
	fclose(fd);
	remove("myfile1.txt");
	rename("testfile1.txt", "myfile1.txt");

	if (found == 1)
	{
		printf("\n\n\t\t*-* This Book has been Deleted");
		printf("\n\n\t\t*-* Enter any key to go back to main menu...");
	}
	getch();
	system("cls");
	mainmenu();
}

/* End screen FUNCTION */

void endscreen(void)
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\n\t\t\t    **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\n\t\t\t         =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\t\t\t         =                                           =");
	printf("\n\t\t\t         =            T H A N K    Y O U             =");
	printf("\n\t\t\t         =                                           =");
	printf("\n\t\t\t         =     H A V E    A    N I C E    D A Y      =");
	printf("\n\t\t\t         =                                           =");
	printf("\n\t\t\t         =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("\n\t\t\t   **_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
	exit(0);
}
