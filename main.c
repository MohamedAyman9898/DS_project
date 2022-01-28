#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
int createEmp(int, int, char*,list*);
void getData(int*, float*, char*);
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
    float salary;
    char name[25];
    node* result;
    list list1;
    //insert menu items here
	char menu[6][11] = {"  Add  ","  Search  ","  Delete  ","  Sort  ","  Print  ","  Exit  "};
	char ch;
	float temp;
    list1.end=0;
    list1.start=0;
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
                        printf("big oof\n");
                        getch();
                        break;

                    case option3:       //Deleting an employee
                        system("cls");
                        printf("big oof\n");
                        getch();
                        break;

                    case option4:       //Sorting by salary or alphabetically
                        system("cls");
                        printf("big oof\n");
                        getch();
                        break;

                    case option5:       //printing
                        system("cls");
                        node* temp = list1.start;
                        while(temp!=0)
                        {
                            printf("%s",temp->emp->name);
                            temp = temp->next;
                        }
                        getch();
                        break;

                    case option6:
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

int createEmp(int code, int salary, char* name, list* list)
{
    emp* temp;
    temp = (emp*)malloc(sizeof(emp));
    temp->code = code;
    temp->salary = salary;
    temp->name = name;
    append(list, temp);
    return temp;
}

void getData(int* code, float* salary, char* name)
{
    printf("Enter new employee code: ");
    scanf("%d", code);
    printf("Enter employee name: ");
    scanf("%s", name);
    printf("Enter employee salary: ");
    scanf("%f", salary);
}
