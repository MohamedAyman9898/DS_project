#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"INCLUDE\linkedList.h"
#include"INCLUDE\Search.h"
#include"INCLUDE\Sorting.h"


//-------------------------
//+      Definitions      +
//-------------------------
#define enter        13
#define esc          27
#define upArrow      72        //extended key
#define dwArrow      80        //extended key
#define normal       0x07
#define highlight    0x70
#define blinking     0xF0
#define numOfOptions 5
#define option1      0
#define option2      1
#define option3      2
#define option4      3
#define option5      4
#define option6      5


//------------------------
//+      Prototypes      +
//------------------------
void createEmp(int, int, char*,list*);
void getData(int*, int*, char*);
void printSearch(node*);
// char *toLower(char* str);
void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}

void main(void)
{
	//----------------------------
    //+      Initialization      +
    //----------------------------
    int terminate=0,i,j,size,pos=0,ex=0;
    int state,selection,data;
    int code;
    int salary;
    char name[25];
    node* result;
    list list1;
    //insert menu items here
	char menu[6][11] = {"  Add  ","  Search  ","  Delete  ","  Sort  ","  Print  ","  Exit  "};
	char ch;
    int choice,choice2;
	float temp;
    list1.end=0;
    list1.start=0;
    list1.numOfNodes=0;
    fflush(stdin);


	do
    {
		system("cls"); //clearing the screen
        printf("\n\n\tMy employees");

		//printing the menu depending on position
		for(i=0; i<=numOfOptions; i++)
        {
			if(pos==i)
            {
                gotoxy(35,10+2*i);
			    printf(">%s",menu[i]);
            }
			else
            {
                gotoxy(35,10+2*i);
			    printf("%s",menu[i]);
            }
		}

		//getting user input
		ch=getch();
        ex = 0;
		if(ch==NULL)
        {
            ch=getch();
            ex = 1;
        }
        if ( ex == 1)
        {
            switch (ch)
            {
                case upArrow:
                    pos--;
                    if ( pos < 0)
                    {
                        pos = numOfOptions;
                    }
                    break;
            
                case dwArrow:
                    pos++;
                    if ( pos > numOfOptions)
                    {
                        pos = 0;
                    }
                    break;

                default:
                    break;
            }
        }
        else
        {
            switch (ch)
            {
                case esc:
                    terminate = 1;
                    break;
            
                case enter:
                    //------------------------
                    //+      Opertaions      +
                    //------------------------
                    switch (pos)
                    {
                    case option1:       //Adding new employee
                        system("cls");
                        getData(&code, &salary, name);
                        createEmp(code, salary, name, &list1);
                        getch();
                        break;
                    
                    case option2:       //Searching for an employee
                        system("cls");
                        printf("Enter employee code: ");
                        scanf("%d",&code);
                        printf("\nChoose searching algorithm\n");
                        printf("Linear search -> 1\nBinary search  -> 2  ");
                        scanf("%d",&choice);
                        switch (choice)
                        {
                            case 1:     //linear search
                                result = linSearch(&list1,code);
                                printSearch(result);
                                break;
                        
                            case 2:     //binary search
                                result = binSearch(&list1, code);
                                printSearch(result);
                                break;

                            default:
                                break;
                        }
                        getch();

                    case option3:       //Deleting an employee
                        system("cls");
                        printf("big oof\n");
                        getch();
                        break;

                    case option4:       //Sorting by salary or alphabetically
                        system("cls");
                        printf("Sort by salary -> 1\nSort alphabetically -> 2  ");
                        scanf("%d",&choice);
                        printf("\nSelect Sorting algorithm\n");
                        printf("Selection sort -> 1\nBubble Sort -> 2  ");
                        scanf("%d",&choice2);

                        switch (choice2)
                        {
                        case 1:     //selection sort
                            selectionSortNew(&list1, choice);
                            printf("\nDone!\n");
                            break;
                        
                        case 2:     //bubble sort                         
                            bubbleSort(&list1, choice);
                            printf("\nDone!\n");
                            break;
                        
                        default:
                            break;
                        }
                        getch();
                        break;

                    case option5:       //printing
                        system("cls");
                        printList(&list1);
                        getch();
                        break;

                    case option6:       //terminating
                        terminate = 1;
                        break;

                    default:
                        break;
                    }

                default:
                    break;
            }
        }
    
    }while(!terminate);
}

void createEmp(int code, int salary, char* name, list* list)
{
    emp* newEmp;
    newEmp = (emp*)malloc(sizeof(emp));
    newEmp->code = code;
    newEmp->salary = salary;
    strcpy(newEmp->name, name);
    append(list, newEmp);
}

void getData(int* code, int* salary, char* name)
{
    printf("Enter employee name: ");
    scanf("%s", name);
    printf("Enter new employee code: ");
    scanf("%d", code);
    printf("Enter employee salary: ");
    scanf("%d", salary);
}

void printSearch(node* result)
{
    if(result == 0)
    {
        printf("Employee doesn't exist!");
    }
    else
    {
        printf("+-------------------+\n");
        printf("code: %d\n",result->emp->code);
        printf("name: %s\n",result->emp->name);
        printf("salary: %d\n",result->emp->salary);
        printf("+-------------------+");
    }
}


