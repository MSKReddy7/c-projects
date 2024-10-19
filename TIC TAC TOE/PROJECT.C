#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

char a[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};//1D array to store 'X' && 'O'

//variable used to store player 1 'X` name
char name1[20];

//variable used to store player 2 'O` name
char name2[20];

//used to copy another array elements
char name12[20];


int count=0,z,i,board=0,won,start,scan;
//start variable is used to start or stop game
//board variable is used to select particular board
//won stores 1 if a player wins either stores 0
//scan variable used to make a choice after draw || won
//z to store 'X' || 'O' by index values
//i used for "loops"
//count used to count how many insertions occured in the array a[]


void title_board();//starting board text "TIC TAC TOE" with big letters
void selecting_board();//for selecting boards
void dboard();//default board with || and == with background black and borders blue
void with_background_board();//board with background blue and borders white
void without_background_board();//board with background DEFAULT and white borders
void game_over();//prints the text "GAME OVER" with big letters
void game_end();//prints the text"GAME END" with big letters

void info();//it shows what to enter while playing game

void print_board();//it prints the selected board

void condition(char ch);//checks the conditions of tic tac toe

void move();//board =1  deFault board
	    //board =2  blue board
	    //board =3  plane board

void read_names();//reads the players names

void newgame();//resets the board to default values and calls main function
void reset();//resets the selected board to default values
void option();//to give 3 choices after won a player or draw


/*-------------------------main function starts----------------------------*/
main()
{
	system("cls");
	if(board==0)//to print title board only once after starting game
	{
		title_board();//starting board
	}
	if(start==1)
	{
		system("cls");
		board=0;
		selecting_board();//selecting particular board
		scanf("%d",&board);
		if(board>=1&&board<=3)
		{
			read_names();
			system("cls");
			info();
			print_board();//goes to the fuction and print's the boards
			move();
		}
		else
		{
			game_end();
			exit(0);
		}
	}
	else
	{
		game_end();
		exit(0);
	}
	return 0;
}



void move()
{
	while(count<9)
	{
		z: //label
		if(count%2==0)
		{
			printf("\n\n $\033[1;35m\033[1;31m %s '\033[0mX\033[1;35m` Enter a Box Number\033[0m :- ",name1);
		}
		else
		{
			printf("\n\n $\033[1;35m\033[1;31m %s '\033[0mO\033[1;35m` Enter a Box Number\033[0m :- ",name2);
		}
		scanf("%d",&z);
		--z;
		if(z>=0&&z<=8&&a[z]==' ')
		{
			if(count%2==0)
			{
				system("cls");
				a[z]='X';
			}
			else
			{
				system("cls");
				a[z]='O';
			}

			info();
			print_board();
			condition(a[z]);
			count++;
		}
		else if(z==9)
		{
			reset();
		}
		else if(z>=0&&z<=8&&a[z]!=' ')
		{
			printf("\t\t   \033[1m\033[1;31mInvalid move Try again\33[0m");
			goto z;
		}
		else
		{
			game_end();
			exit(0);
		}
	}
	//draw condition
	if(won!=1&&count==9)
	{
		game_over();
		system("cls");
		print_board();
		printf("\n\n\033[43m----------------------------------\033[0mDRAW\033[43m---------------------------------------\033[0m\n\n\n");
		option();
	}
}




//conditions for winning
void condition(char ch)
{
	if(ch=='X')
	{
		strcpy(name12,name1);
	}
	else
	{
		strcpy(name12,name2);
	}

	//for horizontal 3 conditions
	for(i=0;i<7;i+=3)
	{
		if(a[i]==ch&&a[i+1]==ch&&a[i+2]==ch)
		{
			game_over();
			system("cls");
			print_board();
			printf("\n\n\t\t       \033[1;32m %s '\033[0m%c\033[1;32m' WON THE MATCH !!!\033[0m",name12,ch);
			won=1;
			Sleep(1500);
			option();
		}
	}

	//for vertical 3 conditions
	for(i=0;i<3;i++)
	{
		if(a[i]==ch&&a[i+3]==ch&&a[i+6]==ch)
		{
			game_over();
			system("cls");
			print_board();
			printf("\n\n\t\t       \033[1;32m %s '\033[0m%c\033[1;32m' WON THE MATCH !!!\033[0m",name12,ch);
			won=1;
			Sleep(1500);
			option();

		}
	}

	//for cross 2 conditions
	if(a[0]==ch&&a[4]==ch&&a[8]==ch||a[2]==ch&&a[4]==ch&&a[6]==ch)
	{
		game_over();
		system("cls");
		print_board();
		printf("\n\n\t\t       \033[1;32m %s '\033[0m%c\033[1;32m' WON THE MATCH !!!\033[0m",name12,ch);
		won=1;
		Sleep(1500);
		option();
	}


}

void newgame()
{
	count=0;
	won=0;
	for(i=0;i<9;i++)
	{
		a[i]=' ';
	}
	main();
}

void reset()
{
	int i;
	count=0;
	won=0;
	for(i=0;i<9;i++)
	{
		a[i]=' ';
	}
	system("cls");
	info();
	print_board();
	move();
}

void option()
{
		scan:
		printf("\n\033[1;35menter \033[1;34m 1\033[1;35m to reset board \033[0m\n\033[1;34m       2\033[1;35m to start a new game \033[0m\n\033[1;34m       any other character\033[1;35m to exit \033[0m:-");
		scanf("%d",&scan);
		if(scan==1)
		{
			reset();
		}
		else if(scan==2)
		{
			newgame();
		}
		else
		{
			game_end();
			exit(0);
		}
}




void title_board()
{
	printf("\n\n\t\t\033[1m\033[1;36mThis Is a Popular 2D Game Over The WORLD\033[0m");
	printf("\n\n\n\n");
	printf("\n\t    \033[47m======\033[0m  \033[47m||\033[0m  \033[47m======\033[0m           \033[47m======\033[0m  \033[47m=======\033[0m  \033[47m======\033[0m     ");
	printf("\n\t      \033[47m||\033[0m    \033[47m||\033[0m  \033[47m||\033[0m	           \033[47m||\033[0m    \033[47m||\033[0m   \033[47m||\033[0m  \033[47m||\033[0m	  ");
	printf("\n\t      \033[47m||\033[0m    \033[47m||\033[0m  \033[47m||\033[0m	           \033[47m||\033[0m    \033[47m||\033[0m   \033[47m||\033[0m  \033[47m||\033[0m	  ");
	printf("\n\t      \033[47m||\033[0m    \033[47m||\033[0m  \033[47m||\033[0m	           \033[47m||\033[0m    \033[47m||===||\033[0m  \033[47m||\033[0m	  ");
	printf("\n\t      \033[47m||\033[0m    \033[47m||\033[0m  \033[47m======\033[0m             \033[47m||\033[0m    \033[47m||\033[0m   \033[47m||\033[0m  \033[47m======\033[0m      ");

	printf("\n\n");

	printf("\n\t\t\t   \033[47m======\033[0m \033[47m=======\033[0m  \033[47m======\033[0m");
	printf("\n\t\t\t     \033[47m||\033[0m   \033[47m||\033[0m   \033[47m||\033[0m  \033[47m||\033[0m  \033[47m\033[0m");
	printf("\n\t\t\t     \033[47m||\033[0m   \033[47m||\033[0m   \033[47m||\033[0m  \033[47m||==||\033[0m");
	printf("\n\t\t\t     \033[47m||\033[0m   \033[47m||\033[0m   \033[47m||\033[0m  \033[47m||\033[0m    ");
	printf("\n\t\t\t     \033[47m||\033[0m   \033[47m=======\033[0m  \033[47m======\033[0m ");

	printf("\n\n\n\n\t\t   \033[1;31menter \033[1;32m`\033[1;33m1\033[1;32m'\033[1;31m to start the game\033[0m");
	printf("\n\n\t\t\033[1;31m   enter \033[1;33many other character\033[1;31m to exit \033[0m:-");
	scanf("%d",&start);
}


void selecting_board()
{
	system("cls");
	printf("\n\n\t\033[43m\033[1;35m===========------Choose a Board To Play------===========\033[0m");
	printf("\n\n\n\033[1;31mEnter \033[0m1\033[1;36m-\033[0m3\033[1;31m to select a board\033[0m");
	printf("\033[1;35m (or) \033[0many other character \033[1;31mto exit\033[0m\n\n");

	printf("\033[1;31m1\033[0m.\033[1;36mDefault board           \033[1;31m2\033[0m.\033[1;36mBlue board               \033[1;31m3\033[0m.\033[1;36mPlane board\n");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");
	printf("\n\033[1;34m=====||=====||=====\033[0m	  \033[47m                     \033[0m	      \033[47m                     \033[0m");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");
	printf("\n\033[1;34m=====||=====||=====\033[0m	  \033[47m                     \033[0m	      \033[47m                     \033[0m");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");
	printf("\n\033[1;34m     ||     ||     \033[0m	  \033[44m      \033[47m  \033[0m\033[44m     \033[47m  \033[44m      \033[0m	            \033[47m  \033[0m     \033[47m  \033[0m");

	printf("\n\n\n\033[1;35mEnter Board Number\033[0m:-");
}


void read_names()
{


	read_names:
	system("cls");

	printf("\n\n\n");
	printf("\033[1;35mEnter Name for PLAYER 1 '\033[0mX\033[1;35m`\033[0m :-");
	gets(name1);
	gets(name1);

	printf("\n\n");
	printf("\033[1;35mEnter Name for PLAYER 2 '\033[0mO\033[1;35m`\033[0m :-");
	gets(name2);

	if(name1[0]=='\0')
	{
		name1[0]='p';
		name1[1]='l';
		name1[2]='a';
		name1[3]='y';
		name1[4]='e';
		name1[5]='r';
		name1[6]=' ';
		name1[7]='1';
		printf("\n\n\033[1;36mNo names entered for 'X' using default name player 1\033[0m");
	}
	if(name2[0]=='\0')
	{
		name2[0]='p';
		name2[1]='l';
		name2[2]='a';
		name2[3]='y';
		name2[4]='e';
		name2[5]='r';
		name2[6]=' ';
		name2[7]='2';
		printf("\n\n\033[1;36mNo names entered for 'O' using default name player 2\033[0m");
	}
	if(strcmp(name1,name2)==0)
	{
		printf("\n\n\t\t\t  ");
		printf("\033[1;35mNames Should Be Different\033[0m");
		Sleep(1500);
		goto read_names;
	}
	else
	{
		printf("\n\n\033[1;31mGame Loading...................\033[0m");
		Sleep(3500);
	}
}


void info()
{
	printf("\t\t\t \033[4m \033[1m \033[1;33m    TIC TAC TOE\n\033[0m");

	printf("\033[1;33m/\033[1;35m/\033[0menter \033[1;36m10\033[0m for RESET\n");
	printf("\033[1;33m/\033[1;35m/\033[0menter \033[1;36m1\033[0m-\033[1;36m9\033[0m for inserting `\033[1;31mX\033[0m' or `\033[1;31mO\033[0m'\n");
	printf("\033[1;33m/\033[1;35m/\033[0menter \033[1;36many other Character\033[0m for exit");
}



void print_board()
{
	if(board==1)
	{
		dboard();
	}
	else if(board==2)
	{
		with_background_board();
	}
	else if(board==3)
	{
		without_background_board();
	}
}



void dboard() //default board==1
{
	printf("\n\n\n");

	printf("\n\t\t  \033[1;34m         ||         ||       \033[0m  ");
	printf("\n\t\t      \033[1;31m%c    \033[1;34m||    \033[1;31m%c    \033[1;34m||    \033[1;31m%c    \033[0m",a[0],a[1],a[2]);
	printf("\n\t\t         \033[1;30m 1\033[1;34m||        \033[1;30m2\033[1;34m||       \033[1;30m 3\033[1;34m");

	printf("\n\t\t  \033[1;34m ========||=========||=========\033[0m");

	printf("\n\t\t  \033[1;34m         ||         ||       \033[0m  ");
	printf("\n\t\t      \033[1;31m%c    \033[1;34m||    \033[1;31m%c    \033[1;34m||    \033[1;31m%c    \033[0m",a[3],a[4],a[5]);
	printf("\n\t\t         \033[1;30m 4\033[1;34m||        \033[1;30m5\033[1;34m||       \033[1;30m 6\033[1;34m");

	printf("\n\t\t  \033[1;34m ========||=========||=========\033[0m");

	printf("\n\t\t  \033[1;34m         ||         ||       \033[0m  ");
	printf("\n\t\t      \033[1;31m%c    \033[1;34m||    \033[1;31m%c    \033[1;34m||    \033[1;31m%c    \033[0m",a[6],a[7],a[8]);
	printf("\n\t\t         \033[1;30m 7\033[1;34m||        \033[1;30m8\033[1;34m||       \033[1;30m 9\033[1;34m\n");

}




void with_background_board()//background board==2
{
	printf("\n\t\t  \033[44m           \033[47m||\033[44m           \033[47m||\033[44m           ");					
	printf("\033[0m");
	printf("\n\t\t  \033[44m     %C     \033[47m||\033[44m     %c     \033[47m||\033[44m      %c    ",a[0],a[1],a[2]);	
	printf("\033[0m");
	printf("\n\t\t  \033[44m           \033[47m||\033[44m           \033[47m||\033[44m           ");					
	printf("\033[0m");

	printf("\n\t\t  \033[47m===========||===========||===========\033[0m");												
	printf("\033[0m");

	printf("\n\t\t  \033[44m           \033[47m||\033[44m           \033[47m||\033[44m           ");					
	printf("\033[0m");
	printf("\n\t\t  \033[44m     %C     \033[47m||\033[44m     %c     \033[47m||\033[44m      %c    ",a[3],a[4],a[5]);	
	printf("\033[0m");
	printf("\n\t\t  \033[44m           \033[47m||\033[44m           \033[47m||\033[44m           ");					
	printf("\033[0m");

	printf("\n\t\t  \033[47m===========||===========||===========\033[0m");												
	printf("\033[0m");

	printf("\n\t\t  \033[44m           \033[47m||\033[44m           \033[47m||\033[44m           ");					
	printf("\033[0m");
	printf("\n\t\t  \033[44m     %C     \033[47m||\033[44m     %c     \033[47m||\033[44m      %c    ",a[6],a[7],a[8]);	
	printf("\033[0m");
	printf("\n\t\t  \033[44m           \033[47m||\033[44m           \033[47m||\033[44m           ");					
	printf("\033[0m");
}





void without_background_board()//plane board==3
{
	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t      \033[1;31m%c\033[0m      \033[47m||\033[0m     \033[1;31m%c\033[0m     \033[47m||\033[0m     \033[1;31m%c\033[0m    ",a[0],a[1],a[2]);
	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t  	    \033[1;30m1\033[0m\033[47m||\033[0m          \033[1;30m2\033[0m\033[47m||\033[0m         \033[1;30m 3\033[0m");

	printf("\n\t\t  \033[47m===========||===========||===========\033[0m");

	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t      \033[1;31m%c\033[0m      \033[47m||\033[0m     \033[1;31m%c\033[0m     \033[47m||\033[0m     \033[1;31m%c\033[0m    ",a[3],a[4],a[5]);
	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t  	    \033[1;30m4\033[0m\033[47m||\033[0m          \033[1;30m5\033[0m\033[47m||\033[0m         \033[1;30m 6\033[0m");

	printf("\n\t\t  \033[47m===========||===========||===========\033[0m");

	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t      \033[1;31m%c\033[0m      \033[47m||\033[0m     \033[1;31m%c\033[0m     \033[47m||\033[0m     \033[1;31m%c\033[0m    ",a[6],a[7],a[8]);
	printf("\n\t\t  	     \033[47m||\033[0m	          \033[47m||\033[0m	   ");
	printf("\n\t\t  	    \033[1;30m7\033[0m\033[47m||\033[0m          \033[1;30m8\033[0m\033[47m||\033[0m         \033[1;30m 9\033[0m");


}



void game_over()
{

	for(i=0;i<2;i++)
	{
	system("cls");
	//game
	//first line
	printf("\n\n\n\n\n\n\n\n\t   \033[41m          \033[0m  ");
	printf("\033[41m          \033[0m  ");
	printf("\033[41m              \033[0m  ");
	printf("\033[41m          \033[0m  ");
	//second line
	printf("\n\t   \033[41m  \033[0m          ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m     ");
	//third line
	printf("\n\t   \033[41m  \033[0m          ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m     ");
	//fourth line
	printf("\n\t   \033[41m  \033[0m  ");
	printf("\033[41m      \033[0m  ");
	printf("\033[41m        ");
	printf("  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m");
	printf("\033[41m  \033[0m");
	printf("\033[41m  \033[0m");
	printf("\033[41m  \033[0m");
	printf("\033[41m  \033[0m");
	//fifth line
	printf("\n\t   \033[41m  \033[0m      \033[41m  \033[0m  ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m     ");
	//sixth line
	printf("\n\t   \033[41m  \033[0m      \033[41m  \033[0m  ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m     ");
	//seventh line
	printf("\n\t   \033[41m          \033[0m  ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m          \033[0m  ");
	//over
	printf("\n\n\t     \033[47m          \033[0m  \033[47m   \033[0m    \033[47m   \033[0m  \033[47m           \033[0m  \033[47m          \033[0m");
	printf("\n\t     \033[47m  \033[0m      \033[47m  \033[0m   \033[47m  \033[0m    \033[47m  \033[0m   \033[47m  \033[0m           \033[47m  \033[0m      \033[47m  \033[0m");
	printf("\n\t     \033[47m  \033[0m      \033[47m  \033[0m   \033[47m  \033[0m    \033[47m  \033[0m   \033[47m  \033[0m           \033[47m  \033[0m      \033[47m  \033[0m");
	printf("\n\t     \033[47m  \033[0m      \033[47m  \033[0m    \033[47m  \033[0m  \033[47m  \033[0m    \033[47m           \033[0m  \033[47m          \033[0m");
	printf("\n\t     \033[47m  \033[0m      \033[47m  \033[0m     \033[47m \033[0m  \033[47m \033[0m     \033[47m  \033[0m           \033[47m  \033[0m   \033[47m  \033[0m");
	printf("\n\t     \033[47m  \033[0m      \033[47m  \033[0m     \033[47m  \033[0m\033[47m  \033[0m     \033[47m  \033[0m           \033[47m  \033[0m    \033[47m  \033[0m");
	printf("\n\t     \033[47m          \033[0m      \033[47m  \033[0m      \033[47m           \033[0m  \033[47m  \033[0m     \033[47m   \033[0m");
	Sleep(100);

	system("cls");
	//game
	//first line
	printf("\n\n\n\n\n\n\n\n\t   \033[42m          \033[0m  ");
	printf("\033[42m          \033[0m  ");
	printf("\033[42m              \033[0m  ");
	printf("\033[42m          \033[0m  ");
	//second line
	printf("\n\t   \033[42m  \033[0m          ");
	printf("\033[42m  \033[0m      ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m     ");
	//third line
	printf("\n\t   \033[42m  \033[0m          ");
	printf("\033[42m  \033[0m      ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m     ");
	//fourth line
	printf("\n\t   \033[42m  \033[0m  ");
	printf("\033[42m      \033[0m  ");
	printf("\033[42m        ");
	printf("  \033[0m  ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m");
	printf("\033[42m  \033[0m");
	printf("\033[42m  \033[0m");
	printf("\033[42m  \033[0m");
	printf("\033[42m  \033[0m");
	//fifth line
	printf("\n\t   \033[42m  \033[0m      \033[42m  \033[0m  ");
	printf("\033[42m  \033[0m      ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m     ");
	//sixth line
	printf("\n\t   \033[42m  \033[0m      \033[42m  \033[0m  ");
	printf("\033[42m  \033[0m      ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m     ");
	//seventh line
	printf("\n\t   \033[42m          \033[0m  ");
	printf("\033[42m  \033[0m      ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m    ");
	printf("\033[42m  \033[0m  ");
	printf("\033[42m          \033[0m  ");
	//over
	printf("\n\n\t     \033[46m          \033[0m  \033[46m   \033[0m    \033[46m   \033[0m  \033[46m           \033[0m  \033[46m          \033[0m");
	printf("\n\t     \033[46m  \033[0m      \033[46m  \033[0m   \033[46m  \033[0m    \033[46m  \033[0m   \033[46m  \033[0m           \033[46m  \033[0m      \033[46m  \033[0m");
	printf("\n\t     \033[46m  \033[0m      \033[46m  \033[0m   \033[46m  \033[0m    \033[46m  \033[0m   \033[46m  \033[0m           \033[46m  \033[0m      \033[46m  \033[0m");
	printf("\n\t     \033[46m  \033[0m      \033[46m  \033[0m    \033[46m  \033[0m  \033[46m  \033[0m    \033[46m           \033[0m  \033[46m          \033[0m");
	printf("\n\t     \033[46m  \033[0m      \033[46m  \033[0m     \033[46m \033[0m  \033[46m \033[0m     \033[46m  \033[0m           \033[46m  \033[0m   \033[46m  \033[0m");
	printf("\n\t     \033[46m  \033[0m      \033[46m  \033[0m     \033[46m  \033[0m\033[46m  \033[0m     \033[46m  \033[0m           \033[46m  \033[0m    \033[46m  \033[0m");
	printf("\n\t     \033[46m          \033[0m      \033[46m  \033[0m      \033[46m           \033[0m  \033[46m  \033[0m     \033[46m   \033[0m");
	Sleep(100);

	system("cls");
	//game
	//first line
	printf("\n\n\n\n\n\n\n\n\t   \033[43m          \033[0m  ");
	printf("\033[43m          \033[0m  ");
	printf("\033[43m              \033[0m  ");
	printf("\033[43m          \033[0m  ");
	//second line
	printf("\n\t   \033[43m  \033[0m          ");
	printf("\033[43m  \033[0m      ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m     ");
	//third line
	printf("\n\t   \033[43m  \033[0m          ");
	printf("\033[43m  \033[0m      ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m     ");
	//fourth line
	printf("\n\t   \033[43m  \033[0m  ");
	printf("\033[43m      \033[0m  ");
	printf("\033[43m        ");
	printf("  \033[0m  ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m");
	printf("\033[43m  \033[0m");
	printf("\033[43m  \033[0m");
	printf("\033[43m  \033[0m");
	printf("\033[43m  \033[0m");
	//fifth line
	printf("\n\t   \033[43m  \033[0m      \033[43m  \033[0m  ");
	printf("\033[43m  \033[0m      ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m     ");
	//sixth line
	printf("\n\t   \033[43m  \033[0m      \033[43m  \033[0m  ");
	printf("\033[43m  \033[0m      ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m     ");
	//seventh line
	printf("\n\t   \033[43m          \033[0m  ");
	printf("\033[43m  \033[0m      ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m    ");
	printf("\033[43m  \033[0m  ");
	printf("\033[43m          \033[0m  ");
	//over
	printf("\n\n\t     \033[45m          \033[0m  \033[45m   \033[0m    \033[45m   \033[0m  \033[45m           \033[0m  \033[45m          \033[0m");
	printf("\n\t     \033[45m  \033[0m      \033[45m  \033[0m   \033[45m  \033[0m    \033[45m  \033[0m   \033[45m  \033[0m           \033[45m  \033[0m      \033[45m  \033[0m");
	printf("\n\t     \033[45m  \033[0m      \033[45m  \033[0m   \033[45m  \033[0m    \033[45m  \033[0m   \033[45m  \033[0m           \033[45m  \033[0m      \033[45m  \033[0m");
	printf("\n\t     \033[45m  \033[0m      \033[45m  \033[0m    \033[45m  \033[0m  \033[45m  \033[0m    \033[45m           \033[0m  \033[45m          \033[0m");
	printf("\n\t     \033[45m  \033[0m      \033[45m  \033[0m     \033[45m \033[0m  \033[45m \033[0m     \033[45m  \033[0m           \033[45m  \033[0m   \033[45m  \033[0m");
	printf("\n\t     \033[45m  \033[0m      \033[45m  \033[0m     \033[45m  \033[0m\033[45m  \033[0m     \033[45m  \033[0m           \033[45m  \033[0m    \033[45m  \033[0m");
	printf("\n\t     \033[45m          \033[0m      \033[45m  \033[0m      \033[45m           \033[0m  \033[45m  \033[0m     \033[45m   \033[0m");
	Sleep(100);

	system("cls");
	//game
	//first line
	printf("\n\n\n\n\n\n\n\n\t   \033[44m          \033[0m  ");
	printf("\033[44m          \033[0m  ");
	printf("\033[44m              \033[0m  ");
	printf("\033[44m          \033[0m  ");
	//second line
	printf("\n\t   \033[44m  \033[0m          ");
	printf("\033[44m  \033[0m      ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m     ");
	//third line
	printf("\n\t   \033[44m  \033[0m          ");
	printf("\033[44m  \033[0m      ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m     ");
	//fourth line
	printf("\n\t   \033[44m  \033[0m  ");
	printf("\033[44m      \033[0m  ");
	printf("\033[44m        ");
	printf("  \033[0m  ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m");
	printf("\033[44m  \033[0m");
	printf("\033[44m  \033[0m");
	printf("\033[44m  \033[0m");
	printf("\033[44m  \033[0m");
	//fifth line
	printf("\n\t   \033[44m  \033[0m      \033[44m  \033[0m  ");
	printf("\033[44m  \033[0m      ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m     ");
	//sixth line
	printf("\n\t   \033[44m  \033[0m      \033[44m  \033[0m  ");
	printf("\033[44m  \033[0m      ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m     ");
	//seventh line
	printf("\n\t   \033[44m          \033[0m  ");
	printf("\033[44m  \033[0m      ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m    ");
	printf("\033[44m  \033[0m  ");
	printf("\033[44m          \033[0m  ");
	//over
	printf("\n\n\t     \033[43m          \033[0m  \033[43m   \033[0m    \033[43m   \033[0m  \033[43m           \033[0m  \033[43m          \033[0m");
	printf("\n\t     \033[43m  \033[0m      \033[43m  \033[0m   \033[43m  \033[0m    \033[43m  \033[0m   \033[43m  \033[0m           \033[43m  \033[0m      \033[43m  \033[0m");
	printf("\n\t     \033[43m  \033[0m      \033[43m  \033[0m   \033[43m  \033[0m    \033[43m  \033[0m   \033[43m  \033[0m           \033[43m  \033[0m      \033[43m  \033[0m");
	printf("\n\t     \033[43m  \033[0m      \033[43m  \033[0m    \033[43m  \033[0m  \033[43m  \033[0m    \033[43m           \033[0m  \033[43m          \033[0m");
	printf("\n\t     \033[43m  \033[0m      \033[43m  \033[0m     \033[43m \033[0m  \033[43m \033[0m     \033[43m  \033[0m           \033[43m  \033[0m   \033[43m  \033[0m");
	printf("\n\t     \033[43m  \033[0m      \033[43m  \033[0m     \033[43m  \033[0m\033[43m  \033[0m     \033[43m  \033[0m           \033[43m  \033[0m    \033[43m  \033[0m");
	printf("\n\t     \033[43m          \033[0m      \033[43m  \033[0m      \033[43m           \033[0m  \033[43m  \033[0m     \033[43m   \033[0m");
	Sleep(100);

	system("cls");
	//game
	//first line
	printf("\n\n\n\n\n\n\n\n\t   \033[45m          \033[0m  ");
	printf("\033[45m          \033[0m  ");
	printf("\033[45m              \033[0m  ");
	printf("\033[45m          \033[0m  ");
	//second line
	printf("\n\t   \033[45m  \033[0m          ");
	printf("\033[45m  \033[0m      ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m     ");
	//third line
	printf("\n\t   \033[45m  \033[0m          ");
	printf("\033[45m  \033[0m      ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m     ");
	//fourth line
	printf("\n\t   \033[45m  \033[0m  ");
	printf("\033[45m      \033[0m  ");
	printf("\033[45m        ");
	printf("  \033[0m  ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m");
	printf("\033[45m  \033[0m");
	printf("\033[45m  \033[0m");
	printf("\033[45m  \033[0m");
	printf("\033[45m  \033[0m");
	//fifth line
	printf("\n\t   \033[45m  \033[0m      \033[45m  \033[0m  ");
	printf("\033[45m  \033[0m      ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m     ");
	//sixth line
	printf("\n\t   \033[45m  \033[0m      \033[45m  \033[0m  ");
	printf("\033[45m  \033[0m      ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m     ");
	//seventh line
	printf("\n\t   \033[45m          \033[0m  ");
	printf("\033[45m  \033[0m      ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m    ");
	printf("\033[45m  \033[0m  ");
	printf("\033[45m          \033[0m  ");
	//over
	printf("\n\n\t     \033[42m          \033[0m  \033[42m   \033[0m    \033[42m   \033[0m  \033[42m           \033[0m  \033[42m          \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m   \033[42m  \033[0m    \033[42m  \033[0m   \033[42m  \033[0m           \033[42m  \033[0m      \033[42m  \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m   \033[42m  \033[0m    \033[42m  \033[0m   \033[42m  \033[0m           \033[42m  \033[0m      \033[42m  \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m    \033[42m  \033[0m  \033[42m  \033[0m    \033[42m           \033[0m  \033[42m          \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m     \033[42m \033[0m  \033[42m \033[0m     \033[42m  \033[0m           \033[42m  \033[0m   \033[42m  \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m     \033[42m  \033[0m\033[42m  \033[0m     \033[42m  \033[0m           \033[42m  \033[0m    \033[42m  \033[0m");
	printf("\n\t     \033[42m          \033[0m      \033[42m  \033[0m      \033[42m           \033[0m  \033[42m  \033[0m     \033[42m   \033[0m");
	Sleep(100);

	system("cls");
	//game
	//first line
	printf("\n\n\n\n\n\n\n\n\t   \033[46m          \033[0m  ");
	printf("\033[46m          \033[0m  ");
	printf("\033[46m              \033[0m  ");
	printf("\033[46m          \033[0m  ");
	//second line
	printf("\n\t   \033[46m  \033[0m          ");
	printf("\033[46m  \033[0m      ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m     ");
	//third line
	printf("\n\t   \033[46m  \033[0m          ");
	printf("\033[46m  \033[0m      ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m     ");
	//fourth line
	printf("\n\t   \033[46m  \033[0m  ");
	printf("\033[46m      \033[0m  ");
	printf("\033[46m        ");
	printf("  \033[0m  ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m");
	printf("\033[46m  \033[0m");
	printf("\033[46m  \033[0m");
	printf("\033[46m  \033[0m");
	printf("\033[46m  \033[0m");
	//fifth line
	printf("\n\t   \033[46m  \033[0m      \033[46m  \033[0m  ");
	printf("\033[46m  \033[0m      ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m     ");
	//sixth line
	printf("\n\t   \033[46m  \033[0m      \033[46m  \033[0m  ");
	printf("\033[46m  \033[0m      ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m     ");
	//seventh line
	printf("\n\t   \033[46m          \033[0m  ");
	printf("\033[46m  \033[0m      ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m    ");
	printf("\033[46m  \033[0m  ");
	printf("\033[46m          \033[0m  ");
	//over
	printf("\n\n\t     \033[41m          \033[0m  \033[41m   \033[0m    \033[41m   \033[0m  \033[41m           \033[0m  \033[41m          \033[0m");
	printf("\n\t     \033[41m  \033[0m      \033[41m  \033[0m   \033[41m  \033[0m    \033[41m  \033[0m   \033[41m  \033[0m           \033[41m  \033[0m      \033[41m  \033[0m");
	printf("\n\t     \033[41m  \033[0m      \033[41m  \033[0m   \033[41m  \033[0m    \033[41m  \033[0m   \033[41m  \033[0m           \033[41m  \033[0m      \033[41m  \033[0m");
	printf("\n\t     \033[41m  \033[0m      \033[41m  \033[0m    \033[41m  \033[0m  \033[41m  \033[0m    \033[41m           \033[0m  \033[41m          \033[0m");
	printf("\n\t     \033[41m  \033[0m      \033[41m  \033[0m     \033[41m \033[0m  \033[41m \033[0m     \033[41m  \033[0m           \033[41m  \033[0m   \033[41m  \033[0m");
	printf("\n\t     \033[41m  \033[0m      \033[41m  \033[0m     \033[41m  \033[0m\033[41m  \033[0m     \033[41m  \033[0m           \033[41m  \033[0m    \033[41m  \033[0m");
	printf("\n\t     \033[41m          \033[0m      \033[41m  \033[0m      \033[41m           \033[0m  \033[41m  \033[0m     \033[41m   \033[0m");
	Sleep(100);

system("cls");
	//game
	//first line
	printf("\n\n\n\n\n\n\n\n\t   \033[41m          \033[0m  ");
	printf("\033[41m          \033[0m  ");
	printf("\033[41m              \033[0m  ");
	printf("\033[41m          \033[0m  ");
	//second line
	printf("\n\t   \033[41m  \033[0m          ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m     ");
	//third line
	printf("\n\t   \033[41m  \033[0m          ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m     ");
	//fourth line
	printf("\n\t   \033[41m  \033[0m  ");
	printf("\033[41m      \033[0m  ");
	printf("\033[41m        ");
	printf("  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m");
	printf("\033[41m  \033[0m");
	printf("\033[41m  \033[0m");
	printf("\033[41m  \033[0m");
	printf("\033[41m  \033[0m");
	//fifth line
	printf("\n\t   \033[41m  \033[0m      \033[41m  \033[0m  ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m     ");
	//sixth line
	printf("\n\t   \033[41m  \033[0m      \033[41m  \033[0m  ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m     ");
	//seventh line
	printf("\n\t   \033[41m          \033[0m  ");
	printf("\033[41m  \033[0m      ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m    ");
	printf("\033[41m  \033[0m  ");
	printf("\033[41m          \033[0m  ");
	//over
	printf("\n\n\t     \033[42m          \033[0m  \033[42m   \033[0m    \033[42m   \033[0m  \033[42m           \033[0m  \033[42m          \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m   \033[42m  \033[0m    \033[42m  \033[0m   \033[42m  \033[0m           \033[42m  \033[0m      \033[42m  \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m   \033[42m  \033[0m    \033[42m  \033[0m   \033[42m  \033[0m           \033[42m  \033[0m      \033[42m  \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m    \033[42m  \033[0m  \033[42m  \033[0m    \033[42m           \033[0m  \033[42m          \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m     \033[42m \033[0m  \033[42m \033[0m     \033[42m  \033[0m           \033[42m  \033[0m   \033[42m  \033[0m");
	printf("\n\t     \033[42m  \033[0m      \033[42m  \033[0m     \033[42m  \033[0m\033[42m  \033[0m     \033[42m  \033[0m           \033[42m  \033[0m    \033[42m  \033[0m");
	printf("\n\t     \033[42m          \033[0m      \033[42m  \033[0m      \033[42m           \033[0m  \033[42m  \033[0m     \033[42m   \033[0m");
	Sleep(100);
	}
}



void game_end()
{
	for(i=0;i<2;i++)
	{
		system("cls");
		//first line
		printf("\n\n\n\n\n\n\n\n\t   \033[41m          \033[0m  ");
		printf("\033[41m          \033[0m  ");
		printf("\033[41m              \033[0m  ");
		printf("\033[41m          \033[0m  ");
		//second line
		printf("\n\t   \033[41m  \033[0m          ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m    ");
		printf("\033[41m  \033[0m    ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m     ");
		//third line
		printf("\n\t   \033[41m  \033[0m  ");
		printf("\033[41m      \033[0m  ");
		printf("\033[41m        ");
		printf("  \033[0m  ");
		printf("\033[41m  \033[0m    ");
		printf("\033[41m  \033[0m    ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m");
		printf("\033[41m  \033[0m");
		printf("\033[41m  \033[0m");
		printf("\033[41m  \033[0m");
		printf("\033[41m  \033[0m");
		//fourth line
		printf("\n\t   \033[41m  \033[0m      \033[41m  \033[0m  ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m    ");
		printf("\033[41m  \033[0m    ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m     ");
		//fifth line
		printf("\n\t   \033[41m          \033[0m  ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m    ");
		printf("\033[41m  \033[0m    ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m          \033[0m  ");
		//end
		//first line
		printf("\n\n\t\t  \033[41m          \033[0m  ");
		printf("\033[41m          \033[0m  ");
		printf("\033[41m         \033[0m  ");
		//second line
		printf("\n\t\t  \033[41m  \033[0m          ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m      ");
		//third line
		printf("\n\t\t  \033[41m          \033[0m  ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m      ");
		//fourth line
		printf("\n\t\t  \033[41m  \033[0m          ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m  ");
		printf("\033[41m  \033[0m      ");
		printf("\033[41m  \033[0m      ");
		//fifth line
		printf("\n\t\t  \033[41m          \033[0m  ");
		printf("\033[41m  \033[0m      \033[41m  \033[0m  ");
		printf("\033[41m         \033[0m  ");
		Sleep(100);

		system("cls");
		//first line
		printf("\n\n\n\n\n\n\n\n\t   \033[42m          \033[0m  ");
		printf("\033[42m          \033[0m  ");
		printf("\033[42m              \033[0m  ");
		printf("\033[42m          \033[0m  ");
		//second line
		printf("\n\t   \033[42m  \033[0m          ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m    ");
		printf("\033[42m  \033[0m    ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m     ");
		//third line
		printf("\n\t   \033[42m  \033[0m  ");
		printf("\033[42m      \033[0m  ");
		printf("\033[42m        ");
		printf("  \033[0m  ");
		printf("\033[42m  \033[0m    ");
		printf("\033[42m  \033[0m    ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m");
		printf("\033[42m  \033[0m");
		printf("\033[42m  \033[0m");
		printf("\033[42m  \033[0m");
		printf("\033[42m  \033[0m");
		//fourth line
		printf("\n\t   \033[42m  \033[0m      \033[42m  \033[0m  ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m    ");
		printf("\033[42m  \033[0m    ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m     ");
		//fifth line
		printf("\n\t   \033[42m          \033[0m  ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m    ");
		printf("\033[42m  \033[0m    ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m          \033[0m  ");
		//end
		//first line
		printf("\n\n\t\t  \033[42m          \033[0m  ");
		printf("\033[42m          \033[0m  ");
		printf("\033[42m         \033[0m  ");
		//second line
		printf("\n\t\t  \033[42m  \033[0m          ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m      ");
		//third line
		printf("\n\t\t  \033[42m          \033[0m  ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m      ");
		//fourth line
		printf("\n\t\t  \033[42m  \033[0m          ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m  ");
		printf("\033[42m  \033[0m      ");
		printf("\033[42m  \033[0m      ");
		//fifth line
		printf("\n\t\t  \033[42m          \033[0m  ");
		printf("\033[42m  \033[0m      \033[42m  \033[0m  ");
		printf("\033[42m         \033[0m  ");

		Sleep(100);

		system("cls");
		//first line
		printf("\n\n\n\n\n\n\n\n\t   \033[43m          \033[0m  ");
		printf("\033[43m          \033[0m  ");
		printf("\033[43m              \033[0m  ");
		printf("\033[43m          \033[0m  ");
		//second line
		printf("\n\t   \033[43m  \033[0m          ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m    ");
		printf("\033[43m  \033[0m    ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m     ");
		//third line
		printf("\n\t   \033[43m  \033[0m  ");
		printf("\033[43m      \033[0m  ");
		printf("\033[43m        ");
		printf("  \033[0m  ");
		printf("\033[43m  \033[0m    ");
		printf("\033[43m  \033[0m    ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m");
		printf("\033[43m  \033[0m");
		printf("\033[43m  \033[0m");
		printf("\033[43m  \033[0m");
		printf("\033[43m  \033[0m");
		//fourth line
		printf("\n\t   \033[43m  \033[0m      \033[43m  \033[0m  ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m    ");
		printf("\033[43m  \033[0m    ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m     ");
		//fifth line
		printf("\n\t   \033[43m          \033[0m  ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m    ");
		printf("\033[43m  \033[0m    ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m          \033[0m  ");
		//end
		//first line
		printf("\n\n\t\t  \033[43m          \033[0m  ");
		printf("\033[43m          \033[0m  ");
		printf("\033[43m         \033[0m  ");
		//second line
		printf("\n\t\t  \033[43m  \033[0m          ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m      ");
		//third line
		printf("\n\t\t  \033[43m          \033[0m  ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m      ");
		//fourth line
		printf("\n\t\t  \033[43m  \033[0m          ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m  ");
		printf("\033[43m  \033[0m      ");
		printf("\033[43m  \033[0m      ");
		//fifth line
		printf("\n\t\t  \033[43m          \033[0m  ");
		printf("\033[43m  \033[0m      \033[43m  \033[0m  ");
		printf("\033[43m         \033[0m  ");

		Sleep(100);


		system("cls");
		//first line
		printf("\n\n\n\n\n\n\n\n\t   \033[44m          \033[0m  ");
		printf("\033[44m          \033[0m  ");
		printf("\033[44m              \033[0m  ");
		printf("\033[44m          \033[0m  ");
		//second line
		printf("\n\t   \033[44m  \033[0m          ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m    ");
		printf("\033[44m  \033[0m    ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m     ");
		//third line
		printf("\n\t   \033[44m  \033[0m  ");
		printf("\033[44m      \033[0m  ");
		printf("\033[44m        ");
		printf("  \033[0m  ");
		printf("\033[44m  \033[0m    ");
		printf("\033[44m  \033[0m    ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m");
		printf("\033[44m  \033[0m");
		printf("\033[44m  \033[0m");
		printf("\033[44m  \033[0m");
		printf("\033[44m  \033[0m");
		//fourth line
		printf("\n\t   \033[44m  \033[0m      \033[44m  \033[0m  ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m    ");
		printf("\033[44m  \033[0m    ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m     ");
		//fifth line
		printf("\n\t   \033[44m          \033[0m  ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m    ");
		printf("\033[44m  \033[0m    ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m          \033[0m  ");
		//end
		//first line
		printf("\n\n\t\t  \033[44m          \033[0m  ");
		printf("\033[44m          \033[0m  ");
		printf("\033[44m         \033[0m  ");
		//second line
		printf("\n\t\t  \033[44m  \033[0m          ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m      ");
		//third line
		printf("\n\t\t  \033[44m          \033[0m  ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m      ");
		//fourth line
		printf("\n\t\t  \033[44m  \033[0m          ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m  ");
		printf("\033[44m  \033[0m      ");
		printf("\033[44m  \033[0m      ");
		//fifth line
		printf("\n\t\t  \033[44m          \033[0m  ");
		printf("\033[44m  \033[0m      \033[44m  \033[0m  ");
		printf("\033[44m         \033[0m  ");

		Sleep(100);



		system("cls");
		//first line
		printf("\n\n\n\n\n\n\n\n\t   \033[45m          \033[0m  ");
		printf("\033[45m          \033[0m  ");
		printf("\033[45m              \033[0m  ");
		printf("\033[45m          \033[0m  ");
		//second line
		printf("\n\t   \033[45m  \033[0m          ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m    ");
		printf("\033[45m  \033[0m    ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m     ");
		//third line
		printf("\n\t   \033[45m  \033[0m  ");
		printf("\033[45m      \033[0m  ");
		printf("\033[45m        ");
		printf("  \033[0m  ");
		printf("\033[45m  \033[0m    ");
		printf("\033[45m  \033[0m    ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m");
		printf("\033[45m  \033[0m");
		printf("\033[45m  \033[0m");
		printf("\033[45m  \033[0m");
		printf("\033[45m  \033[0m");
		//fourth line
		printf("\n\t   \033[45m  \033[0m      \033[45m  \033[0m  ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m    ");
		printf("\033[45m  \033[0m    ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m     ");
		//fifth line
		printf("\n\t   \033[45m          \033[0m  ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m    ");
		printf("\033[45m  \033[0m    ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m          \033[0m  ");
		//end
		//first line
		printf("\n\n\t\t  \033[45m          \033[0m  ");
		printf("\033[45m          \033[0m  ");
		printf("\033[45m         \033[0m  ");
		//second line
		printf("\n\t\t  \033[45m  \033[0m          ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m      ");
		//third line
		printf("\n\t\t  \033[45m          \033[0m  ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m      ");
		//fourth line
		printf("\n\t\t  \033[45m  \033[0m          ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m  ");
		printf("\033[45m  \033[0m      ");
		printf("\033[45m  \033[0m      ");
		//fifth line
		printf("\n\t\t  \033[45m          \033[0m  ");
		printf("\033[45m  \033[0m      \033[45m  \033[0m  ");
		printf("\033[45m         \033[0m  ");

		Sleep(100);


		system("cls");
		//first line
		printf("\n\n\n\n\n\n\n\n\t   \033[46m          \033[0m  ");
		printf("\033[46m          \033[0m  ");
		printf("\033[46m              \033[0m  ");
		printf("\033[46m          \033[0m  ");
		//second line
		printf("\n\t   \033[46m  \033[0m          ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m    ");
		printf("\033[46m  \033[0m    ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m     ");
		//third line
		printf("\n\t   \033[46m  \033[0m  ");
		printf("\033[46m      \033[0m  ");
		printf("\033[46m        ");
		printf("  \033[0m  ");
		printf("\033[46m  \033[0m    ");
		printf("\033[46m  \033[0m    ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m");
		printf("\033[46m  \033[0m");
		printf("\033[46m  \033[0m");
		printf("\033[46m  \033[0m");
		printf("\033[46m  \033[0m");
		//fourth line
		printf("\n\t   \033[46m  \033[0m      \033[46m  \033[0m  ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m    ");
		printf("\033[46m  \033[0m    ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m     ");
		//fifth line
		printf("\n\t   \033[46m          \033[0m  ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m    ");
		printf("\033[46m  \033[0m    ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m          \033[0m  ");
		//end
		//first line
		printf("\n\n\t\t  \033[46m          \033[0m  ");
		printf("\033[46m          \033[0m  ");
		printf("\033[46m         \033[0m  ");
		//second line
		printf("\n\t\t  \033[46m  \033[0m          ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m      ");
		//third line
		printf("\n\t\t  \033[46m          \033[0m  ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m      ");
		//fourth line
		printf("\n\t\t  \033[46m  \033[0m          ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m  ");
		printf("\033[46m  \033[0m      ");
		printf("\033[46m  \033[0m      ");
		//fifth line
		printf("\n\t\t  \033[46m          \033[0m  ");
		printf("\033[46m  \033[0m      \033[46m  \033[0m  ");
		printf("\033[46m         \033[0m  ");

		Sleep(100);
	}
}