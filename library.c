#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char *studentName;
    int studentID;
} Student;

struct Book
{
    int ID;          // Unique ID of the book
    char *title;     // Title of the book
    char *author;    // Author(s) of the book
    int isIssued;    // If the book is issued, it's value is 1, else 0
    Student student; // Store the details of the student to whom the book has been issued
};

Student arrstudent[100];
struct Book arrbook[100];

int pos = 0; // index for new book

void Library_menu();
void add_book(); 
void issue_book();
void display_books(); 
void exit_menu();

void Library_menu()
{
    system("cls");
    re:
    {
        system("cls");
        char choice;
        printf("Enter one of the options (a/b/c/d): ");
        printf("\na. Add Book:\n");
        printf("\nb. Display Books:\n");
        printf("\nc. Issue a Book:\n");
        printf("\nd. Exit Menu:\n");

        scanf("%c", &choice);
        switch (choice)
        {
        case 'a':
            add_book();
            break;

        case 'b':
            display_books();
            break;

        case 'c':
            issue_book();
            break;

        case 'd':
            exit_menu();
            break;

        default:
            printf("Invalid Choice!\n Please Enter again!\n");
            goto re;
        }
    }
}

void add_book()
{
    system("cls");
    int book_id;
    char *book_title;
    book_title = (char *)malloc(100);
    char *book_author;
    book_author = (char *)malloc(100);
    int flag = 0;
    
    re:
    {   
        printf("Enter the following details the information of the book:\n");
        printf("Book Id : ");
        fflush(stdin);
        scanf("%d", &book_id);
        printf("Book Title : ");
        fflush(stdin);
        scanf("%[^\n]%*c", book_title);
        printf("Book Author : ");
        fflush(stdin);
        scanf("%[^\n]%*c", book_author);
        for (int i = 0; i < pos; i++)
        {
            int id_temp = arrbook[i].ID;
            while(id_temp == book_id)
            {
                flag = 1;
                printf("Book with same ID present already!\nPlease enter the details again!\n");
                printf("Enter the following details the information of the book:\n");
                printf("Book Id : ");
                fflush(stdin);
                scanf("%d", &book_id);
                printf("Book Title : ");
                fflush(stdin);
                scanf("%[^\n]%*c", book_title);
                printf("Book Author : ");
                fflush(stdin);
                scanf("%[^\n]%*c", book_author);
            }
            if(id_temp != book_id)  {flag=0; break;}
        }
        if (flag == 0)
        {
            arrbook[pos].ID = book_id;
            arrbook[pos].title = book_title;
            arrbook[pos].author = book_author;
            pos++;

            printf("%s is successfully added!\n", book_title);
            printf("Thank You!\n\n");
            printf("Press Enter to coninue!\n");
            getchar();
        }
    }
    if (flag == 0)
        Library_menu();
}

void issue_book()
{
    system("cls");
    char *btitle;
    btitle = (char *)malloc(100);
    char *sname;
    sname = (char *)malloc(100);
    int sid;
    sid = (int)malloc(10);
    printf("Enter the Book Title you want to issue: ");
    fflush(stdin);
    scanf("%[^\n]%*c", btitle);
    // printf("%s", btitle);
    Student s;
    for (int i = 0; i < pos; i++)
    {
        if (strcmp(arrbook[i].title, btitle) == 0 && arrbook[i].isIssued == 0)
        {
            printf("Book is available!\nEnter Student Name & ID:\n");
            printf("Student ID: ");
            fflush(stdin);
            scanf("%d", &sid);
            s.studentID = sid;
            // printf("%d", sid);
            fflush(stdin);
            printf("Student Name: ");
            scanf("%[^\n]%*c", sname);
            s.studentName = sname;
            fflush(stdin);
            arrbook[i].isIssued = 1; //book is now issued
            printf("'%s' with book ID %d has been issued to %s (ID: %d).", arrbook[i].title, arrbook[i].ID, s.studentName, s.studentID);
            arrbook[i].student = s;
        }
    }
    printf("\nPress Enter to Continue!\n");
    fflush(stdin);
    getchar();
    Library_menu();
}

void display_books()
{
    // printf("ok");
    // printf("%s", arrbook[0].title); 
    system("cls");
    for (int i = 0; i < pos; i++)
    {
        printf("Book Details-->\n");
        printf("Book Id: %d\n", arrbook[i].ID);
        printf("Book Title: %s\n", arrbook[i].title);
        printf("Book Author: %s\n", arrbook[i].author);
        printf("--------------------------------------\n\n");
    }
    printf("Press Enter to continue!\n");
    fflush(stdin);
    getchar();
    Library_menu();
}

void exit_menu()
{
    system("cls");
    printf("Good-Bye!\n");
    exit(0);
}


int main()
{
    Library_menu();
    return 0;
}
