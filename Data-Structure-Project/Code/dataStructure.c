#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#define MAX 50

typedef struct node1
{
    int data;
    struct node1 *link;
} SLL;

typedef struct node2
{
    int data;
    struct node2 *Plink;
    struct node2 *Nlink;
} DLL;
void frontpage_design();
void head_box(int, int, int);
void line(int, int, int);
void username_box(int, int, int);
void password_box(int, int, int);
void password_dot(int, int, int);
void username(char[]);
void password(char[]);
int checkusername(char[], char[]);
int checkpassword(char[], char[]);
void process_dots();
int check_y(char);
void data_structure();
void mainmenu();
void array(int[], int *);
void arraymenu();
int one_array(int[], int **);
void one_arraymenu();
void oneD_display(int[], int, int, int);
void oneD_insertion(int[], int ***);
void insertionmenu();
void array_insertatfirst(int[], int ****, int);
void array_insertatlast(int[], int ****, int);
void array_insertatmiddle(int[], int ****, int, int);
void array_insertafterposition(int[], int ****, int, int);
void array_insertinsorted(int[], int ****, int);
void oneD_deletion(int[], int ***);
void deletionmenu();
void array_deletefromfirst(int[], int ****);
void array_deletefromlast(int[], int ****);
void array_deletefrommiddle(int[], int ****, int);
void array_deleteallappearance(int[], int ****, int);
void array_deleteallduplicate(int[], int ****, int);
void array_dispose(int ****);
void oneD_searching(int[], int);
void searchingmenu();
int array_linearsearch(int[], int, int);
int array_binarysearchIT(int[], int, int, int);
int array_binarysearchRE(int[], int, int, int);
void oneD_sorting(int[], int);
void sortingmenu();
void array_selectionsort(int[], int);
void array_bubblesort(int[], int);
void array_length(int);
void array_reverse(int[], int);
int two_array();
void two_arraymenu();
void input_output();
void transpose();
void multiplication();
void linkedlist(SLL **, DLL **, DLL **);
void linkedlistmenu();
int singlyLL(SLL ***);
void singlyLLmenu();
void singlyLL_display(SLL *, int, int);
void singlyLL_insertion(SLL ****);
void singlyLL_insertatfirst(SLL *****, int);
void singlyLL_insertatlast(SLL *****, int);
void singlyLL_insertatmiddle(SLL *****, int, int);
void singlyLL_insertafterposition(SLL *, int, int);
void singlyLL_insertinsorted(SLL *****, int);
void singlyLL_deletion(SLL ****);
void singlyLL_deletefromfirst(SLL *****);
void singlyLL_deletefromlast(SLL *****);
void singlyLL_deletefrommiddle(SLL *****, int);
void singlyLL_deleteallappearance(SLL *****, int);
void singlyLL_deleteallduplicate(SLL *****, int);
void singlyLL_dispose(SLL *****);
void singlyLL_searching(SLL *);
int singlyLL_linearsearch(SLL *, int);
void singlyLL_sorting(SLL *);
void singlyLL_selectionsort(SLL *);
void singlyLL_bubblesort(SLL *);
int singlyLL_length(SLL *);
void singlyLL_reverse(SLL ****);
int doublyLL(DLL ***, DLL ***);
void doublyLLmenu();
void doublyLL_display(DLL *, int, int);
void doublyLL_insertion(DLL ****, DLL ****);
void doublyLL_insertatfirst(DLL *****, DLL *****, int);
void doublyLL_insertatlast(DLL *****, DLL *****, int);
void doublyLL_insertatmiddle(DLL *****, DLL *****, int, int);
void doublyLL_insertafterposition(DLL *, DLL *****, int, int);
void doublyLL_insertinsorted(DLL *****, DLL *****, int);
void doublyLL_deletion(DLL ****, DLL ****);
void doublyLL_deletefromfirst(DLL *****, DLL *****);
void doublyLL_deletefromlast(DLL *****, DLL *****);
void doublyLL_deletefrommiddle(DLL *****, DLL *****, int);
/*void doublyLL_deleteallappearance(SLL *****, int);
void doublyLL_deleteallduplicate(SLL *****, int);
void doublyLL_dispose(SLL *****);
void doublyLL_searching(SLL *);
int doublyLL_linearsearch(SLL *, int);
void doublyLL_sorting(SLL *);
void doublyLL_selectionsort(SLL *);
void doublyLL_bubblesort(SLL *);
int doublyLL_length(SLL *);
void doublyLL_reverse(SLL ****);*/
void gotoxy(int x, int y);
COORD coord = {0, 0};

int main()
{
    char str[MAX];
    char pass[7];
    char code[] = "696969";
    char user[] = "vicoderrr";
    char y;
    int u, p, ok;
    system("cls");
    frontpage_design();
    username(str);
    password(pass);
    gotoxy(3, 19);
    printf("Please wait! It may take a while");
    process_dots();
    u = checkusername(user, str);
    p = checkpassword(code, pass);
    gotoxy(3, 21);
    printf("Press \"y\" key to continue");
    gotoxy(3, 19);
    if (u == 1 && p == 1)
    {
        printf("Login Successful");
        printf("                ");
        while (1)
        {
            gotoxy(28, 21);
            ok = check_y(y);
            if (ok == 1)
            {
                data_structure();
                break;
            }
        }
    }
    else if (u == 0)
    {
        printf("The mobile number or username you entered isn't valid");
        while (1)
        {
            gotoxy(28, 21);
            ok = check_y(y);
            if (ok == 1)
            {
                main();
                break;
            }
        }
    }
    else
    {
        printf("Incorrect Password!!!");
        printf("            ");
        while (1)
        {
            gotoxy(28, 21);
            ok = check_y(y);
            if (ok == 1)
            {
                main();
                break;
            }
        }
    }
    return 0;
}
void frontpage_design()
{
    head_box(49, 1, 16);
    gotoxy(51, 2);
    printf("Data Structure");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("Mobile number or Username");
    username_box(3, 8, 60);
    gotoxy(3, 12);
    printf("Password ");
    password_box(3, 13, 60);
    password_dot(4, 14, 6);
    line(1, 17, 118);
}
void head_box(int x, int y, int v)
{
    int i;
    gotoxy(x, y);
    printf("%c", 201);
    for (i = 0; i < v; i++)
        printf("%c", 205);
    printf("%c", 187);
    gotoxy(x, ++y);
    printf("%c", 186);
    gotoxy(x, ++y);
    printf("%c", 200);
    for (i = 0; i < v; i++)
        printf("%c", 205);
    x = x + v + 1;
    gotoxy(x, y--);
    printf("%c", 188);
    gotoxy(x, y);
    printf("%c", 186);
}
void line(int x, int y, int v)
{
    int i;
    gotoxy(x, y);
    for (i = 0; i < v; i++)
        printf("%c", 196);
}
void username_box(int x, int y, int v)
{
    int i;
    gotoxy(x, y);
    printf("%c", 218);
    for (i = 0; i < v; i++)
        printf("%c", 196);
    printf("%c", 191);
    gotoxy(x, ++y);
    printf("%c", 179);
    gotoxy(x, ++y);
    printf("%c", 192);
    for (i = 0; i < v; i++)
        printf("%c", 196);
    x = x + v + 1;
    gotoxy(x, y);
    printf("%c", 217);
    gotoxy(x, --y);
    printf("%c", 179);
}
void password_box(int x, int y, int v)
{
    int i;
    gotoxy(x, y);
    printf("%c", 218);
    for (i = 0; i < v; i++)
        printf("%c", 196);
    printf("%c", 191);
    gotoxy(x, ++y);
    printf("%c", 179);
    gotoxy(x, ++y);
    printf("%c", 192);
    for (i = 0; i < v; i++)
        printf("%c", 196);
    x = x + v + 1;
    gotoxy(x, y);
    printf("%c", 217);
    gotoxy(x, --y);
    printf("%c", 179);
}
void password_dot(int x, int y, int v)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        gotoxy(x, y);
        printf("%c", '-');
        x = x + 3;
    }
}
void username(char str[])
{
    str[0] = '\0';
    gotoxy(4, 9);
    gets(str);
    if (str[0] == '\0')
        username(str);
}
void password(char pass[])
{
    int i, x = 4;
    for (i = 0; i < 6; i++)
    {
        gotoxy(x, 14);
        pass[i] = getch();
        if (pass[0] == 8)
        {
            printf("%c", '-');
            i--;
            continue;
        }
        else if (pass[i] == 8)
        {
            printf("%c", '-');
            x = x - 3;
            gotoxy(x, 14);
            printf("%c", '-');
            i = i - 2;
            continue;
        }
        printf("%c", '*');
        x = x + 3;
    }
    x = x - 3;
    gotoxy(x, 14);
    pass[i] = '\0';
}
int checkusername(char user[], char str[])
{
    int i;
    for (i = 0; user[i] != '\0' && str[i] != '\0'; i++) {
    	if (user[i] != str[i])
        	return 0;
	}
	if (user[i] == '\0' && str[i] == '\0')
	    return 1;
    return 0;
}
int checkpassword(char code[], char pass[])
{
    int i;
    for (i = 0; pass[i] != '\0' && code[i] != '\0'; i++) {
    	if (pass[i] != code[i])
        	return 0;
    }
    return (pass[i] == '\0' && code[i] == '\0');
}
void process_dots()
{
    int i = 0;
    while (i < 1)
    {
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf("\b\b\b   ");
        printf("\b\b\b");
        i++;
    }
}
int check_y(char y)
{
    y = getch();
    if (y == 'y')
        return 1;
    else
        return 0;
}
void data_structure()
{
    int a[MAX], n = 0;
    SLL *head = NULL;
    DLL *start = NULL, *end = NULL;
    int choice;
    do
    {
        system("cls");
        mainmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            array(a, &n);
            break;
        case 2:
            linkedlist(&head, &start, &end);
            break;
        case 0:
            break;
        default:
            gotoxy(3, 25);
            printf("Wrong Choice");
            gotoxy(3, 26);
            printf("Enter Valid Choice");
            getch();
        }
    } while (choice);
}
void mainmenu()
{
    head_box(46, 1, 21);
    gotoxy(48, 2);
    printf("Data Structure Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Array");
    gotoxy(3, 9);
    printf("2. Linked List");
    gotoxy(3, 11);
    printf("3. Stack");
    gotoxy(3, 13);
    printf("4. Queue");
    gotoxy(3, 15);
    printf("5. Tree");
    gotoxy(3, 17);
    printf("6. Graph");
    gotoxy(3, 19);
    printf("0. Exit");
    line(1, 21, 118);
    gotoxy(3, 23);
}
void array(int a[], int *n)
{
    int choice, v;
    while (1)
    {
        system("cls");
        arraymenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            v = one_array(a, &n);
            if (v == 44)
                return;
            else
                break;
        case 2:
            v = two_array();
            if (v == 44)
                return;
            else
                break;
        case 22:
            return;
        default:
            gotoxy(3, 17);
            printf("Wrong Choice");
            gotoxy(3, 18);
            printf("Enter Valid Choice");
            getch();
        }
    }
}
void arraymenu()
{
    head_box(49, 1, 12);
    gotoxy(51, 2);
    printf("Array Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. One Dimensional Array");
    gotoxy(3, 9);
    printf("2. Two Dimensional Array");
    gotoxy(3, 11);
    printf("22. Back");
    line(1, 13, 118);
    gotoxy(3, 15);
}
int one_array(int a[], int **n)
{
    int v, p, choice;
    while (1)
    {
        system("cls");
        one_arraymenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 29);
        switch (choice)
        {
        case 1:
            oneD_display(a, **n, 3, 30);
            break;
        case 2:
            oneD_insertion(a, &n);
            break;
        case 3:
            oneD_deletion(a, &n);
            break;
        case 4:
            oneD_searching(a, **n);
            break;
        case 5:
            oneD_sorting(a, **n);
            break;
        case 6:
            array_length(**n);
            break;
        case 7:
            array_reverse(a, **n);
            break;
        case 22:
            return choice;
        case 44:
            return choice;
        default:
            printf("Wrong Choice");
            gotoxy(3, 30);
            printf("Enter Valid Choice");
        }
        if (choice == 1 || choice == 6 || choice == 7)
            getch();
    }
}
void one_arraymenu()
{
    head_box(45, 1, 16);
    gotoxy(47, 2);
    printf("1-D Array Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Display");
    gotoxy(3, 9);
    printf("2. Insertion");
    gotoxy(3, 11);
    printf("3. Deletion");
    gotoxy(3, 13);
    printf("4. Searching");
    gotoxy(3, 15);
    printf("5. Sorting");
    gotoxy(3, 17);
    printf("6. Length");
    gotoxy(3, 19);
    printf("7. Reverse");
    gotoxy(3, 21);
    printf("22. Back");
    gotoxy(3, 23);
    printf("44. Data Structure Menu");
    line(1, 25, 118);
    gotoxy(3, 27);
}
void oneD_display(int a[], int n, int x, int y)
{
    int i;
    if (n == 0)
    {
        printf("List is empty");
        return;
    }
    printf("Values are");
    gotoxy(x, y);
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
void oneD_insertion(int a[], int ***n)
{
    int choice, v, p;
    while (1)
    {
        system("cls");
        insertionmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 23);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            array_insertatfirst(a, &n, v);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            array_insertatlast(a, &n, v);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            printf("Enter the position: ");
            scanf("%d", &p);
            gotoxy(3, 27);
            array_insertatmiddle(a, &n, v, p);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 24);
            printf("Enter the Position: ");
            scanf("%d", &p);
            gotoxy(3, 26);
            array_insertafterposition(a, &n, v, p);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            array_insertinsorted(a, &n, v);
            break;
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 24);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void insertionmenu()
{
    head_box(45, 1, 16);
    gotoxy(47, 2);
    printf("Insertion Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Insert At First");
    gotoxy(3, 9);
    printf("2. Insert At Last");
    gotoxy(3, 11);
    printf("3. Insert At Middle");
    gotoxy(3, 13);
    printf("4. Insert After Position");
    gotoxy(3, 15);
    printf("5. Insert In Sorted");
    gotoxy(3, 17);
    printf("22. Back");
    line(1, 19, 118);
    gotoxy(3, 21);
}
void array_insertatfirst(int a[], int ****n, int v)
{
    int i;
    if (****n == MAX)
    {
        printf("Array is full");
        return;
    }
    for (i = ****n - 1; i >= 0; i--)
        a[i + 1] = a[i];
    a[0] = v;
    printf("Value Inserted : %d", a[0]);
    (****n)++;
}
void array_insertatlast(int a[], int ****n, int v)
{
    if (****n == MAX)
    {
        printf("Array is Full");
        return;
    }
    a[****n] = v;
    printf("Value Inserted : %d", a[****n]);
    (****n)++;
}
void array_insertatmiddle(int a[], int ****n, int v, int p)
{
    int i;
    if (****n == MAX)
    {
        printf("Array is Full");
        return;
    }
    if (p < 1 || p > ****n + 1)
    {
        printf("Position not found");
        return;
    }
    for (i = ****n - 1; i >= p - 1; i--)
        a[i + 1] = a[i];
    a[p - 1] = v;
    printf("Value Inserted : %d", a[p - 1]);
    (****n)++;
}
void array_insertafterposition(int a[], int ****n, int v, int p)
{
    int i;
    if (****n == MAX)
    {
        printf("Array is Full");
        return;
    }
    if (p < 1 || p > ****n)
    {
        printf("Position not found");
        return;
    }
    for (i = ****n - 1; i >= p; i--)
        a[i + 1] = a[i];
    a[p] = v;
    printf("Value Inserted : %d", a[p]);
    (****n)++;
}
void array_insertinsorted(int a[], int ****n, int v)
{
    int i;
    if (****n == MAX)
    {
        printf("Array is Full");
        return;
    }
    for (i = ****n - 1; a[i] > v; i--)
        a[i + 1] = a[i];
    a[++i] = v;
    printf("Value Inserted : %d", a[i]);
    (****n)++;
}
void oneD_deletion(int a[], int ***n)
{
    int choice, p, v;
    while (1)
    {
        system("cls");
        deletionmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 25);
        switch (choice)
        {
        case 1:
            array_deletefromfirst(a, &n);
            break;
        case 2:
            array_deletefromlast(a, &n);
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d", &p);
            gotoxy(3, 27);
            array_deletefrommiddle(a, &n, p);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 27);
            array_deleteallappearance(a, &n, v);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 27);
            array_deleteallduplicate(a, &n, v);
            break;
        case 6:
            array_dispose(&n);
            break;
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 26);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void deletionmenu()
{
    head_box(45, 1, 16);
    gotoxy(47, 2);
    printf("Deletion Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Delete From First");
    gotoxy(3, 9);
    printf("2. Delete From Last");
    gotoxy(3, 11);
    printf("3. Delete From Middle");
    gotoxy(3, 13);
    printf("4. Delete All Appearance of Given Value");
    gotoxy(3, 15);
    printf("5. Delete All Duplicate Appearance of Given Value");
    gotoxy(3, 17);
    printf("6. Dispose");
    gotoxy(3, 19);
    printf("22. Back");
    line(1, 21, 118);
    gotoxy(3, 23);
}
void array_deletefromfirst(int a[], int ****n)
{
    int i;
    if (****n == 0)
    {
        printf("List is empty");
        return;
    }
    printf("Value Deleted : %d", a[0]);
    for (i = 0; i < ****n - 1; i++)
        a[i] = a[i + 1];
    (****n)--;
}
void array_deletefromlast(int a[], int ****n)
{
    if (****n == 0)
    {
        printf("List is empty");
        return;
    }
    printf("Value Deleted : %d", a[****n - 1]);
    (****n)--;
}
void array_deletefrommiddle(int a[], int ****n, int p)
{
    int i;
    if (****n == 0)
    {
        printf("List is empty");
        return;
    }
    if (p < 1 || p > ****n)
    {
        printf("Invalid Position");
        return;
    }
    printf("Value Deleted : %d", a[p - 1]);
    for (i = p - 1; i < ****n - 1; i++)
        a[i] = a[i + 1];
    (****n)--;
}
void array_deleteallappearance(int a[], int ****n, int v)
{
    int i, j, flag = 0;
    if (****n == 0)
    {
        printf("List is empty");
        return;
    }
    for (i = 0; i < ****n; i++)
    {
        if (a[i] == v)
        {
            flag = 1;
            for (j = i; j < ****n - 1; j++)
                a[j] = a[j + 1];
            i--;
            (****n)--;
        }
    }
    if (flag == 1)
        printf("All Appearances of Value %d are Deleted ", v);
    else
        printf("Value Not Found in the list");
}
void array_deleteallduplicate(int a[], int ****n, int v)
{
    int i, j, count = 0, flag = 0;
    if (****n == 0)
    {
        printf("List is empty");
        return;
    }
    for (i = 0; i < ****n; i++)
    {
        if (a[i] == v)
        {
            count++;
            if (count > 1)
            {
                flag = 1;
                for (j = i; j < ****n - 1; j++)
                    a[j] = a[j + 1];
                i--;
                (****n)--;
            }
        }
    }
    if (flag == 1)
        printf("All Duplicate Appearances of Value %d are Deleted", v);
    else
        printf("Value Not Found in the List");
}
void array_dispose(int ****n)
{
    (****n) = 0;
    printf("Array Disposed");
}
void oneD_searching(int a[], int n)
{
    int choice, v, r;
    while (1)
    {
        system("cls");
        searchingmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 19);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 21);
            if (n == 0)
                printf("List is empty");
            else
            {
                r = array_linearsearch(a, n, v);
                if (r != -1)
                    printf("%d found at Position : %d", v, r + 1);
                else
                    printf("%d not found in the list", v);
            }
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 21);
            if (n == 0)
                printf("List is empty");
            else
            {
                r = array_binarysearchIT(a, 0, n - 1, v);
                if (r != -1)
                    printf("%d found at Position : %d", v, r + 1);
                else
                    printf("%d not found in the list", v);
            }
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 21);
            if (n == 0)
                printf("List is empty");
            else
            {
                r = array_binarysearchRE(a, 0, n - 1, v);
                if (r != -1)
                    printf("%d found at Position : %d", v, r + 1);
                else
                    printf("%d not found in the list", v);
            }
            break;
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 20);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void searchingmenu()
{
    head_box(45, 1, 16);
    gotoxy(47, 2);
    printf("Searching Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Linear Search");
    gotoxy(3, 9);
    printf("2. Binary Search(Iterative)");
    gotoxy(3, 11);
    printf("3. Binary Search(Recursive)");
    gotoxy(3, 13);
    printf("22. Back");
    line(1, 15, 118);
    gotoxy(3, 17);
}
int array_linearsearch(int a[], int n, int v)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == v)
            return i;
    }
    return -1;
}
int array_binarysearchIT(int a[], int l, int r, int v)
{
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == v)
            return mid;
        else if (a[mid] < v)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int array_binarysearchRE(int a[], int l, int r, int v)
{
    int mid;
    if (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == v)
            return mid;
        else if (a[mid] < v)
            return array_binarysearchRE(a, mid + 1, r, v);
        else
            return array_binarysearchRE(a, l, mid - 1, v);
    }
    return -1;
}
void oneD_sorting(int a[], int n)
{
    int choice;
    while (1)
    {
        system("cls");
        sortingmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 21);
        switch (choice)
        {
        case 1:
            array_selectionsort(a, n);
            break;
        case 2:
            array_bubblesort(a, n);
            break;
        case 22:
            return;
        default:
            printf("Wrong choice");
            gotoxy(3, 22);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void sortingmenu()
{
    head_box(45, 1, 16);
    gotoxy(47, 2);
    printf("Sorting Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Selection Sort");
    gotoxy(3, 9);
    printf("2. Bubble Sort");
    gotoxy(3, 11);
    printf("3. Insertion Sort");
    gotoxy(3, 13);
    printf("4. Quick Sort");
    gotoxy(3, 15);
    printf("22. Back");
    line(1, 17, 118);
    gotoxy(3, 19);
}
void array_selectionsort(int a[], int n)
{
    int i, j, min, temp;
    if (n == 0)
    {
        printf("List is empty");
        return;
    }
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("Selection Sort is done");
}
void array_bubblesort(int a[], int n)
{
    int i, j, temp, flag;
    if (n == 0)
    {
        printf("List is empty");
        return;
    }
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    printf("Bubble Sort is done");
}
void array_length(int n)
{
    printf("Length = %d", n);
}
void array_reverse(int a[], int n)
{
    int i, j, temp;
    for (i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    printf("Reverse is done");
}
int two_array()
{
    int choice;
    while (1)
    {
        system("cls");
        two_arraymenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            input_output();
            break;
        case 2:
            system("cls");
            transpose();
            break;
        case 3:
            system("cls");
            multiplication();
            break;
        case 22:
            return choice;
        case 44:
            return choice;
        default:
            printf("Wrong Choice");
            gotoxy(3, 22);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void two_arraymenu()
{
    head_box(45, 1, 16);
    gotoxy(47, 2);
    printf("2-D Array Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Matrix Input Output");
    gotoxy(3, 9);
    printf("2. Transpose of Matrix");
    gotoxy(3, 11);
    printf("3. Multiplication of Two Given Matrix");
    gotoxy(3, 13);
    printf("22. Back");
    gotoxy(3, 15);
    printf("44. Data Structure Menu");
    line(1, 17, 118);
    gotoxy(3, 19);
}
void input_output()
{

    int a[MAX][MAX], m, n, i, j, y = 4;
    gotoxy(3, 1);
    printf("Enter Row: ");
    scanf("%d", &m);
    gotoxy(3, 2);
    printf("Enter Column: ");
    scanf("%d", &n);
    gotoxy(3, 4);
    if (m * n > MAX)
    {
        printf("Array hasn't enough space");
        return;
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            gotoxy(3, y++);
            if (j == 0 && i == 0)
                printf("Enter %dst value: ", j + 1);
            else if (j == 1 && i == 0)
                printf("Enter %dnd value: ", j + 1);
            else if (j == 2 && i == 0)
                printf("Enter %drd value: ", j + 1);
            else
                printf("Enter %dth value: ", i * n + j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    gotoxy(3, ++y);
    puts("Matrix is");
    gotoxy(3, ++y);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d\t", a[i][j]);
        }
        gotoxy(3, ++y);
    }
}
void transpose()
{
    int a[MAX][MAX], m, n, i, j, y = 4;
    gotoxy(3, 1);
    printf("Enter Row: ");
    scanf("%d", &m);
    gotoxy(3, 2);
    printf("Enter Column: ");
    scanf("%d", &n);
    gotoxy(3, 4);
    if (m * n > MAX)
    {
        printf("Array hasn't enough space");
        return;
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            gotoxy(3, y++);
            if (j == 0 && i == 0)
                printf("Enter %dst value: ", j + 1);
            else if (j == 1 && i == 0)
                printf("Enter %dnd value: ", j + 1);
            else if (j == 2 && i == 0)
                printf("Enter %drd value: ", j + 1);
            else
                printf("Enter %dth value: ", i * n + j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    gotoxy(3, ++y);
    puts("Actual Matrix");
    gotoxy(3, ++y);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d\t", a[i][j]);
        }
        gotoxy(3, ++y);
    }
    y = y + 2;
    gotoxy(3, y);
    puts("After Transpose");
    gotoxy(3, ++y);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%3d\t", a[j][i]);
        }
        gotoxy(3, ++y);
    }
}
void multiplication()
{

    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], m1, m2, n1, n2, i, j, k, sum = 0, y = 9;
    gotoxy(3, 1);
    printf("Enter Row of 1st Matrix: ");
    scanf("%d", &m1);
    gotoxy(3, 2);
    printf("Enter Column of 1st Matrix: ");
    scanf("%d", &n1);
    gotoxy(3, 4);
    printf("Enter Row of 2nd Matrix: ");
    scanf("%d", &m2);
    gotoxy(3, 5);
    printf("Enter Column of 2nd Matrix: ");
    scanf("%d", &n2);
    gotoxy(3, 7);
    if (m1 * n1 > MAX || m2 * n2 > MAX)
    {
        printf("Array hasn't enough space");
        return;
    }
    if (n1 != m2)
    {
        printf("Matrix Multiplication is not possible");
        return;
    }
    printf("Enter for 1st Matrix");
    gotoxy(3, 9);
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            gotoxy(3, y++);
            if (j == 0 && i == 0)
                printf("Enter %dst value: ", j + 1);
            else if (j == 1 && i == 0)
                printf("Enter %dnd value: ", j + 1);
            else if (j == 2 && i == 0)
                printf("Enter %drd value: ", j + 1);
            else
                printf("Enter %dth value: ", i * n1 + j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    gotoxy(3, ++y);
    printf("Enter for 2nd Matrix");
    y = y + 2;
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            gotoxy(3, y++);
            if (j == 0 && i == 0)
                printf("Enter %dst value: ", j + 1);
            else if (j == 1 && i == 0)
                printf("Enter %dnd value: ", j + 1);
            else if (j == 2 && i == 0)
                printf("Enter %drd value: ", j + 1);
            else
                printf("Enter %dth value: ", i * n2 + j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            sum = 0;
            for (k = 0; k < m2; k++)
                sum = sum + a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }
    gotoxy(3, ++y);
    puts("Matrix Multiplication of A and B are");
    gotoxy(3, ++y);
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%3d\t", c[i][j]);
        }
        gotoxy(3, ++y);
    }
}
void linkedlist(SLL **head, DLL **start, DLL **end)
{
    int choice, v;
    while (1)
    {
        system("cls");
        linkedlistmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            v = singlyLL(&head);
            if (v == 44)
                return;
            else
                break;
        case 2:
            v = doublyLL(&start, &end);
            if (v == 44)
                return;
            else
                break;
        /*case 2:
            v = two_array();
            if (v == 44)
                return;
            else
                break;*/
        case 22:
            return;
        default:
            gotoxy(3, 21);
            printf("Wrong Choice");
            gotoxy(3, 22);
            printf("Enter Valid Choice");
            getch();
        }
    }
}
void linkedlistmenu()
{
    head_box(45, 1, 18);
    gotoxy(47, 2);
    printf("Linked List Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Singly Linked List");
    gotoxy(3, 9);
    printf("2. Doubly Linked List");
    gotoxy(3, 11);
    printf("3. Circular Linked List");
    gotoxy(3, 13);
    printf("4. Doubly Circular Linked List");
    gotoxy(3, 15);
    printf("22. Back");
    line(1, 17, 118);
    gotoxy(3, 19);
}
int singlyLL(SLL ***head)
{
    int v, p, c, choice;
    while (1)
    {
        system("cls");
        singlyLLmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 29);
        switch (choice)
        {
        case 1:
            singlyLL_display(**head, 3, 30);
            break;
        case 2:
            singlyLL_insertion(&head);
            break;
        case 3:
            singlyLL_deletion(&head);
            break;
        case 4:
            singlyLL_searching(**head);
            break;
        case 5:
            singlyLL_sorting(**head);
            break;
        case 6:
            c = singlyLL_length(**head);
            printf("Length = %d", c);
            break;
        case 7:
            singlyLL_reverse(&head);
            break;
        case 22:
            return choice;
        case 44:
            return choice;
        default:
            printf("Wrong Choice");
            gotoxy(3, 30);
            printf("Enter Valid Choice");
        }
        if (choice == 1 || choice == 6 || choice == 7)
            getch();
    }
}
void singlyLLmenu()
{
    head_box(40, 1, 25);
    gotoxy(42, 2);
    printf("Singly Linked List Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Display");
    gotoxy(3, 9);
    printf("2. Insertion");
    gotoxy(3, 11);
    printf("3. Deletion");
    gotoxy(3, 13);
    printf("4. Searching");
    gotoxy(3, 15);
    printf("5. Sorting");
    gotoxy(3, 17);
    printf("6. Length");
    gotoxy(3, 19);
    printf("7. Reverse");
    gotoxy(3, 21);
    printf("22. Back");
    gotoxy(3, 23);
    printf("44. Data Structure Menu");
    line(1, 25, 118);
    gotoxy(3, 27);
}
void singlyLL_display(SLL *head, int x, int y)
{
    SLL *temp;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Values are");
    gotoxy(x, y);
    for (temp = head; temp != NULL; temp = temp->link)
        printf("%d\t", temp->data);
}
void singlyLL_insertion(SLL ****head)
{
    int choice, v, p;
    while (1)
    {
        system("cls");
        insertionmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 23);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            singlyLL_insertatfirst(&head, v);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            singlyLL_insertatlast(&head, v);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 24);
            printf("Enter the position: ");
            scanf("%d", &p);
            gotoxy(3, 26);
            singlyLL_insertatmiddle(&head, v, p);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 24);
            printf("Enter the Position: ");
            scanf("%d", &p);
            gotoxy(3, 26);
            singlyLL_insertafterposition(***head, v, p);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            singlyLL_insertinsorted(&head, v);
            break;
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 24);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void singlyLL_insertatfirst(SLL *****head, int v)
{
    SLL *newnode;
    newnode = (SLL *)malloc(sizeof(SLL));
    newnode->data = v;
    newnode->link = ****head;
    ****head = newnode;
    printf("Value Inserted : %d", newnode->data);
}
void singlyLL_insertatlast(SLL *****head, int v)
{
    SLL *newnode, *temp;
    newnode = (SLL *)malloc(sizeof(SLL));
    newnode->data = v;
    newnode->link = NULL;
    if (****head == NULL)
    {
        ****head = newnode;
    }
    else
    {
        for (temp = ****head; temp->link != NULL; temp = temp->link)
            ;
        temp->link = newnode;
    }
    printf("Value Inserted : %d", newnode->data);
}
void singlyLL_insertatmiddle(SLL *****head, int v, int p)
{
    SLL *newnode, *temp;
    int c;
    if ((****head == NULL && p > 1) || (p < 1))
    {
        printf("Invalid Position");
        return;
    }
    newnode = (SLL *)malloc(sizeof(SLL));
    newnode->data = v;
    if (p == 1)
    {
        newnode->link = ****head;
        ****head = newnode;
        printf("Value Inserted : %d", newnode->data);
    }
    else
    {
        for (temp = ****head, c = 1; temp->link != NULL && c < p - 1; c++)
            temp = temp->link;
        if (c < p - 1)
            printf("Invalid Position");
        else
        {
            newnode->link = temp->link;
            temp->link = newnode;
            printf("Value Inserted : %d", newnode->data);
        }
    }
}
void singlyLL_insertafterposition(SLL *head, int v, int p)
{
    SLL *newnode, *temp;
    int c;
    if ((head == NULL || p < 1))
    {
        printf("Invalid Position");
        return;
    }
    newnode = (SLL *)malloc(sizeof(SLL));
    newnode->data = v;
    for (temp = head, c = 1; temp->link != NULL && c < p; c++)
        temp = temp->link;
    if (c < p)
    {
        printf("Invalid Position");
    }
    else
    {
        newnode->link = temp->link;
        temp->link = newnode;
        printf("Value Inserted : %d", newnode->data);
    }
}
void singlyLL_insertinsorted(SLL *****head, int v)
{
    SLL *newnode, *temp;
    newnode = (SLL *)malloc(sizeof(SLL));
    newnode->data = v;
    if (****head == NULL || (****head)->data >= newnode->data)
    {
        newnode->link = ****head;
        ****head = newnode;
    }
    else
    {
        for (temp = ****head; temp->link != NULL && temp->link->data < newnode->data; temp = temp->link)
            ;
        newnode->link = temp->link;
        temp->link = newnode;
    }
    printf("Value Inserted : %d", newnode->data);
}
void singlyLL_deletion(SLL ****head)
{
    int choice, p, v;
    while (1)
    {
        system("cls");
        deletionmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 25);
        switch (choice)
        {
        case 1:
            singlyLL_deletefromfirst(&head);
            break;
        case 2:
            singlyLL_deletefromlast(&head);
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d", &p);
            gotoxy(3, 27);
            singlyLL_deletefrommiddle(&head, p);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 27);
            singlyLL_deleteallappearance(&head, v);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 27);
            singlyLL_deleteallduplicate(&head, v);
            break;
        case 6:
            singlyLL_dispose(&head);
            break;
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 26);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void singlyLL_deletefromfirst(SLL *****head)
{
    SLL *ptr;
    if (****head == NULL)
    {
        printf("List is empty");
        return;
    }
    ptr = ****head;
    ****head = ptr->link;
    printf("Value Deleted : %d", ptr->data);
    free(ptr);
}
void singlyLL_deletefromlast(SLL *****head)
{
    SLL *ptr, *temp;
    if (****head == NULL)
    {
        printf("List is empty");
        return;
    }
    if ((****head)->link == NULL)
    {
        ptr = ****head;
        ****head = ptr->link;
    }
    else
    {
        for (temp = ****head; temp->link->link != NULL; temp = temp->link)
            ;
        ptr = temp->link;
        temp->link = ptr->link;
    }
    printf("Value Deleted : %d", ptr->data);
    free(ptr);
}
void singlyLL_deletefrommiddle(SLL *****head, int p)
{
    SLL *ptr, *temp;
    int c;
    if (****head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (p < 1)
    {
        printf("Invalid Position");
        return;
    }
    if (p == 1)
    {
        ptr = ****head;
        ****head = ptr->link;
        printf("Value Deleted : %d", ptr->data);
        free(ptr);
    }
    else
    {
        for (temp = ****head, c = 1; temp->link != NULL && c < p - 1; c++)
            temp = temp->link;
        if (c < p - 1 || temp->link == NULL)
        {
            printf("Invalid Position");
        }
        else
        {
            ptr = temp->link;
            temp->link = ptr->link;
            printf("Value Deleted : %d", ptr->data);
            free(ptr);
        }
    }
}
void singlyLL_deleteallappearance(SLL *****head, int v)
{
    SLL *temp, *ptr, *s;
    int flag = 0;
    if (****head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = ****head;
    while (temp != NULL)
    {
        if (temp->data == v)
        {
            flag = 1;
            ptr = temp;
            if (temp == ****head)
                temp = ****head = (****head)->link;
            else
                temp = s->link = temp->link;
            free(ptr);
        }
        else
        {
            s = temp;
            temp = temp->link;
        }
    }
    if (flag == 1)
        printf("All Appearance of value %d are deleted", v);
    else
        printf("Value not found in the list");
}
void singlyLL_deleteallduplicate(SLL *****head, int v)
{
    SLL *temp, *ptr, *s;
    int count = 0, flag = 0;
    if (****head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = ****head;
    while (temp != NULL)
    {
        if (temp->data == v)
        {
            count++;
            if (count > 1)
            {
                flag = 1;
                ptr = temp;
                if (temp == ****head)
                {
                    s = ****head;
                    temp = s->link;
                }
                else
                    temp = s->link = temp->link;
                free(ptr);
            }
            else
            {
                s = temp;
                temp = temp->link;
            }
        }
        else
        {
            s = temp;
            temp = temp->link;
        }
    }
    if (flag == 1)
        printf("All Duplicate Appearance of value %d are deleted", v);
    else
        printf("Value not found in the list");
}
void singlyLL_dispose(SLL *****head)
{
    SLL *ptr;
    while (****head != NULL)
    {
        ptr = ****head;
        ****head = (****head)->link;
        free(ptr);
    }
    printf("List is disposed");
}
void singlyLL_searching(SLL *head)
{
    int choice, v, r;
    while (1)
    {
        system("cls");
        searchingmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 19);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 21);
            if (head == NULL)
                printf("List is empty");
            else
            {
                r = singlyLL_linearsearch(head, v);
                if (r != -1)
                    printf("%d found at Position : %d", v, r);
                else
                    printf("%d not found in the list", v);
            }
            break;
        case 2:
            printf("Binary Search is not possible in Linked List");
            break;
        case 3:
            printf("Binary Search is not possible in Linked List");
            break;
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 20);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
int singlyLL_linearsearch(SLL *head, int v)
{
    SLL *temp;
    int count = 0;
    for (temp = head; temp != NULL; temp = temp->link)
    {
        count++;
        if (temp->data == v)
            return count;
    }
    return -1;
}
void singlyLL_sorting(SLL *head)
{
    int choice;
    while (1)
    {
        system("cls");
        sortingmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 21);
        switch (choice)
        {
        case 1:
            singlyLL_selectionsort(head);
            break;
        case 2:
            singlyLL_bubblesort(head);
            break;
        case 22:
            return;
        default:
            printf("Wrong choice");
            gotoxy(3, 22);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void singlyLL_selectionsort(SLL *head)
{
    SLL *temp1, *temp2, *min;
    int swap;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    for (temp1 = head; temp1->link != NULL; temp1 = temp1->link)
    {
        min = temp1;
        for (temp2 = temp1->link; temp2 != NULL; temp2 = temp2->link)
        {
            if (temp2->data < min->data)
                min = temp2;
        }
        swap = temp1->data;
        temp1->data = min->data;
        min->data = swap;
    }
    printf("Selection Sort is done");
}
void singlyLL_bubblesort(SLL *head)
{
    SLL *temp1, *temp2;
    int flag, swap;
    for (temp1 = head; temp1->link != NULL; temp1 = temp1->link)
    {
        flag = 0;
        for (temp2 = head; temp2->link != NULL; temp2 = temp2->link)
        {
            if (temp2->data > temp2->link->data)
            {
                swap = temp2->data;
                temp2->data = temp2->link->data;
                temp2->link->data = swap;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    printf("Bubble Sort is done");
}
int singlyLL_length(SLL *head)
{
    SLL *temp;
    int count = 0;
    for (temp = head; temp != NULL; temp = temp->link)
        count++;
    return count;
}
void singlyLL_reverse(SLL ****head)
{
    SLL *start = NULL, *temp, *newnode, *ptr;
    if (***head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = ***head;
    while (temp != NULL)
    {
        ptr = temp;
        newnode = (SLL *)malloc(sizeof(SLL));
        newnode->data = temp->data;
        newnode->link = start;
        start = newnode;
        temp = temp->link;
        free(ptr);
    }
    ***head = start;
    printf("Reverse is done");
}
int doublyLL(DLL ***start, DLL ***end)
{
    int v, p, c, choice;
    while (1)
    {
        system("cls");
        doublyLLmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 29);
        switch (choice)
        {
        case 1:
            doublyLL_display(**start, 3, 30);
            break;
        case 2:
            doublyLL_insertion(&start, &end);
            break;
        case 3:
            doublyLL_deletion(&start, &end);
            break;
        /*case 4:
            singlyLL_searching(**head);
            break;
        case 5:
            singlyLL_sorting(**head);
            break;
        case 6:
            c = singlyLL_length(**head);
            printf("Length = %d", c);
            break;
        case 7:
            singlyLL_reverse(&head);
            break;*/
        case 22:
            return choice;
        case 44:
            return choice;
        default:
            printf("Wrong Choice");
            gotoxy(3, 30);
            printf("Enter Valid Choice");
        }
        if (choice == 1 || choice == 6 || choice == 7)
            getch();
    }
}
void doublyLLmenu()
{
    head_box(40, 1, 25);
    gotoxy(42, 2);
    printf("Doubly Linked List Menu");
    line(1, 5, 118);
    gotoxy(3, 7);
    printf("1. Display");
    gotoxy(3, 9);
    printf("2. Insertion");
    gotoxy(3, 11);
    printf("3. Deletion");
    gotoxy(3, 13);
    printf("4. Searching");
    gotoxy(3, 15);
    printf("5. Sorting");
    gotoxy(3, 17);
    printf("6. Length");
    gotoxy(3, 19);
    printf("7. Reverse");
    gotoxy(3, 21);
    printf("22. Back");
    gotoxy(3, 23);
    printf("44. Data Structure Menu");
    line(1, 25, 118);
    gotoxy(3, 27);
}
void doublyLL_display(DLL *start, int x, int y)
{
    DLL *temp;
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Values are");
    gotoxy(x, y);
    for (temp = start; temp != NULL; temp = temp->Nlink)
        printf("%d\t", temp->data);
}
void doublyLL_insertion(DLL ****start, DLL ****end)
{
    int choice, v, p;
    while (1)
    {
        system("cls");
        insertionmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 23);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            doublyLL_insertatfirst(&start, &end, v);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            doublyLL_insertatlast(&start, &end, v);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 24);
            printf("Enter the position: ");
            scanf("%d", &p);
            gotoxy(3, 26);
            doublyLL_insertatmiddle(&start, &end, v, p);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 24);
            printf("Enter the Position: ");
            scanf("%d", &p);
            gotoxy(3, 26);
            doublyLL_insertafterposition(***start, &end, v, p);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 25);
            doublyLL_insertinsorted(&start, &end, v);
            break;
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 24);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void doublyLL_insertatfirst(DLL *****start, DLL *****end, int v)
{
    DLL *newnode;
    newnode = (DLL *)malloc(sizeof(DLL));
    newnode->data = v;
    newnode->Plink = NULL;
    newnode->Nlink = ****start;
    if (****start == NULL)
        ****end = ****start = newnode;
    else
        (****start) = (****start)->Plink = newnode;
    printf("Value Inserted : %d", newnode->data);
}
void doublyLL_insertatlast(DLL *****start, DLL *****end, int v)
{
    DLL *newnode, *temp;
    newnode = (DLL *)malloc(sizeof(DLL));
    newnode->data = v;
    newnode->Plink = ****end;
    newnode->Nlink = NULL;
    if (****start == NULL)
        ****end = ****start = newnode;
    else
        (****end) = (****end)->Nlink = newnode;
    printf("Value Inserted : %d", newnode->data);
}
void doublyLL_insertatmiddle(DLL *****start, DLL *****end, int v, int p)
{
    DLL *newnode, *temp;
    int c, count = 0;
    for (temp = ****start; temp != NULL; temp = temp->Nlink)
        count++;
    if (p > count + 1 || p < 1)
    {
        printf("Invalid Position");
        return;
    }
    newnode = (DLL *)malloc(sizeof(DLL));
    newnode->data = v;
    if (p == 1)
    {
        newnode->Plink = NULL;
        newnode->Nlink = ****start;
        if (****start == NULL)
            ****start = ****end = newnode;
        else
            (****start) = (****start)->Plink = newnode;
    }
    else if (p == count + 1)
    {
        newnode->Plink = ****end;
        newnode->Nlink = NULL;
        (****end)->Nlink = newnode;
        ****end = newnode;
    }
    else if (p <= count / 2)
    {
        for (temp = ****start, c = 1; c < p - 1; c++)
            temp = temp->Nlink;
        newnode->Plink = temp;
        newnode->Nlink = temp->Nlink;
        temp->Nlink->Plink = newnode;
        temp->Nlink = newnode;
    }
    else
    {
        for (temp = ****end, c = count; c > p; c--)
            temp = temp->Plink;
        newnode->Plink = temp->Plink;
        newnode->Nlink = temp;
        temp->Plink->Nlink = newnode;
        temp->Plink = newnode;
    }
    printf("Value Inserted : %d", newnode->data);
}
void doublyLL_insertafterposition(DLL *start, DLL *****end, int v, int p)
{
    DLL *newnode, *temp;
    int c, count = 0;
    for (temp = start; temp != NULL; temp = temp->Nlink)
        count++;
    if (p > count || p < 1)
    {
        printf("Invalid Position");
        return;
    }
    newnode = (DLL *)malloc(sizeof(DLL));
    newnode->data = v;
    if (p == count)
    {
        newnode->Plink = ****end;
        newnode->Nlink = NULL;
        (****end) = (****end)->Nlink = newnode;
    }
    else if (p < count / 2)
    {
        for (temp = start, c = 1; c < p; c++)
            temp = temp->Nlink;
        newnode->Plink = temp;
        newnode->Nlink = temp->Nlink;
        temp->Nlink->Plink = newnode;
        temp->Nlink = newnode;
    }
    else
    {
        for (temp = ****end, c = count - 1; c > p; c--)
            temp = temp->Plink;
        newnode->Plink = temp->Plink;
        newnode->Nlink = temp;
        temp->Plink->Nlink = newnode;
        temp->Plink = newnode;
    }
    printf("Value Inserted : %d", newnode->data);
}
void doublyLL_insertinsorted(DLL *****start, DLL *****end, int v)
{
    DLL *newnode, *temp;
    newnode = (DLL *)malloc(sizeof(DLL));
    newnode->data = v;
    if (****start == NULL)
    {
        newnode->Plink = NULL;
        newnode->Nlink = ****start;
        ****end = ****start = newnode;
    }
    else if ((****start)->data >= newnode->data)
    {
        newnode->Plink = NULL;
        newnode->Nlink = ****start;
        
        ****start = (****start)->Plink = newnode;
    }
    else
    {
        for (temp = ****start; temp->Nlink != NULL && temp->Nlink->data < newnode->data; temp = temp->Nlink)
            ;
        newnode->Plink = temp;
        newnode->Nlink = temp->Nlink;
        if (temp->Nlink == NULL)
            ****end = temp->Nlink = newnode;
        else
        {
            temp->Nlink->Plink = newnode;
            temp->Nlink = newnode;
        }
    }
    printf("Value Inserted : %d", newnode->data);
}
void doublyLL_deletion(DLL ****start, DLL ****end)
{
    int choice, p, v;
    while (1)
    {
        system("cls");
        deletionmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 25);
        switch (choice)
        {
        case 1:
            doublyLL_deletefromfirst(&start, &end);
            break;
        case 2:
            doublyLL_deletefromlast(&start, &end);
            break;
        /*case 3:
            printf("Enter the position: ");
            scanf("%d", &p);
            gotoxy(3, 27);
            doublyLL_deletefrommiddle(&start, &end, p);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 27);
            singlyLL_deleteallappearance(&head, v);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 27);
            singlyLL_deleteallduplicate(&head, v);
            break;
        case 6:
            singlyLL_dispose(&head);
            break;*/
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 26);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void doublyLL_deletefromfirst(DLL *****start, DLL *****end)
{
    DLL *ptr;
    if (****start == NULL)
    {
        printf("List is empty");
        return;
    }
    ptr = ****start;
    if (****start == ****end)
        ****start = ****end = NULL;
    else
    {
        ****start = (****start)->Nlink;
        (****start)->Plink = NULL;
    }
    printf("Value Deleted : %d", ptr->data);
    free(ptr);
}
void doublyLL_deletefromlast(DLL *****start, DLL *****end)
{
    DLL *ptr, *temp;
    if (****start == NULL)
    {
        printf("List is empty");
        return;
    }
    ptr = ****end;
    if (****end == ****start)
        ****end = ****start = NULL;
    else
    {
        (****end)->Plink->Nlink = NULL;
        ****end = ptr->Plink;
    }
    printf("Value Deleted : %d", ptr->data);
    free(ptr);
}
void doublyLL_deletefrommiddle(DLL *****start, DLL *****end, int p)
{
    DLL *ptr, *temp;
    int c, count = 0;
    for (temp = ****start; temp != NULL; temp = temp->Nlink)
        count++;
    if (****start == NULL)
    {
        printf("List is empty");
        return;
    }
    if (p > count || p < 1)
    {
        printf("Invalid Position");
        return;
    }
    if (p == 1)
    {
        ptr = ****start;
        if (****start == ****end)
            ****end = ****start = NULL;
        else
        {
            (****start)->Nlink->Plink = NULL;
            ****start = ptr->Nlink;
        }
    }
    else if (p == count)
    {
        ptr = ****end;
        (****end)->Plink->Nlink = NULL;
        (****end) = ptr->Plink;
    }
    else if (p <= count / 2)
    {
        for (temp = ****start, c = 1; c < p - 1; c++)
            temp = temp->Nlink;
        ptr = temp->Nlink;
        temp->Nlink = ptr->Nlink;
        ptr->Nlink->Plink = ptr->Plink;
    }
    else
    {
        for (temp = ****end, c = count; c > p; c--)
            temp = temp->Plink;
        ptr = temp;
        temp->Plink->Nlink = ptr->Nlink;
        ptr->Nlink->Plink = ptr->Plink;
    }
    printf("Value Deleted : %d", ptr->data);
    free(ptr);
}
/*void singlyLL_deleteallappearance(SLL *****head, int v)
{
    SLL *temp, *ptr, *s;
    int flag = 0;
    if (****head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = ****head;
    while (temp != NULL)
    {
        if (temp->data == v)
        {
            flag = 1;
            ptr = temp;
            if (temp == ****head)
                temp = ****head = (****head)->Nlink;
            else
                temp = s->Nlink = temp->Nlink;
                temp->Plink = s;
            free(ptr);
        }
        else
        {
            s = temp;
            temp = temp->Nlink;
        }
    }
    if (flag == 1)
        printf("All Appearance of value %d are deleted", v);
    else
        printf("Value not found in the list");
}
void singlyLL_deleteallduplicate(SLL *****head, int v)
{
    SLL *temp, *ptr, *s;
    int count = 0, flag = 0;
    if (****head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = ****head;
    while (temp != NULL)
    {
        if (temp->data == v)
        {
            count++;
            if (count > 1)
            {
                flag = 1;
                ptr = temp;
                if (temp == ****head)
                {
                    s = ****head;
                    temp = s->link;
                }
                else
                    temp = s->link = temp->link;
                free(ptr);
            }
            else
            {
                s = temp;
                temp = temp->link;
            }
        }
        else
        {
            s = temp;
            temp = temp->link;
        }
    }
    if (flag == 1)
        printf("All Duplicate Appearance of value %d are deleted", v);
    else
        printf("Value not found in the list");
}
void singlyLL_dispose(SLL *****head)
{
    SLL *ptr;
    while (****head != NULL)
    {
        ptr = ****head;
        ****head = (****head)->link;
        free(ptr);
    }
    printf("List is disposed");
}
void singlyLL_searching(SLL *head)
{
    int choice, v, r;
    while (1)
    {
        system("cls");
        searchingmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 19);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &v);
            gotoxy(3, 21);
            if (head == NULL)
                printf("List is empty");
            else
            {
                r = singlyLL_linearsearch(head, v);
                if (r != -1)
                    printf("%d found at Position : %d", v, r);
                else
                    printf("%d not found in the list", v);
            }
            break;
        case 2:
            printf("Binary Search is not possible in Linked List");
            break;
        case 3:
            printf("Binary Search is not possible in Linked List");
            break;
        case 22:
            return;
        default:
            printf("Wrong Choice");
            gotoxy(3, 20);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
int singlyLL_linearsearch(SLL *head, int v)
{
    SLL *temp;
    int count = 0;
    for (temp = head; temp != NULL; temp = temp->link)
    {
        count++;
        if (temp->data == v)
            return count;
    }
    return -1;
}
void singlyLL_sorting(SLL *head)
{
    int choice;
    while (1)
    {
        system("cls");
        sortingmenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        gotoxy(3, 21);
        switch (choice)
        {
        case 1:
            singlyLL_selectionsort(head);
            break;
        case 2:
            singlyLL_bubblesort(head);
            break;
        case 22:
            return;
        default:
            printf("Wrong choice");
            gotoxy(3, 22);
            printf("Enter Valid Choice");
        }
        getch();
    }
}
void singlyLL_selectionsort(SLL *head)
{
    SLL *temp1, *temp2, *min;
    int swap;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    for (temp1 = head; temp1->link != NULL; temp1 = temp1->link)
    {
        min = temp1;
        for (temp2 = temp1->link; temp2 != NULL; temp2 = temp2->link)
        {
            if (temp2->data < min->data)
                min = temp2;
        }
        swap = temp1->data;
        temp1->data = min->data;
        min->data = swap;
    }
    printf("Selection Sort is done");
}
void singlyLL_bubblesort(SLL *head)
{
    SLL *temp1, *temp2;
    int flag, swap;
    for (temp1 = head; temp1->link != NULL; temp1 = temp1->link)
    {
        flag = 0;
        for (temp2 = head; temp2->link != NULL; temp2 = temp2->link)
        {
            if (temp2->data > temp2->link->data)
            {
                swap = temp2->data;
                temp2->data = temp2->link->data;
                temp2->link->data = swap;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    printf("Bubble Sort is done");
}
int singlyLL_length(SLL *head)
{
    SLL *temp;
    int count = 0;
    for (temp = head; temp != NULL; temp = temp->link)
        count++;
    return count;
}
void singlyLL_reverse(SLL ****head)
{
    SLL *start = NULL, *temp, *newnode, *ptr;
    if (***head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = ***head;
    while (temp != NULL)
    {
        ptr = temp;
        newnode = (SLL *)malloc(sizeof(SLL));
        newnode->data = temp->data;
        newnode->link = start;
        start = newnode;
        temp = temp->link;
        free(ptr);
    }
    ***head = start;
    printf("Reverse is done");
}*/
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}