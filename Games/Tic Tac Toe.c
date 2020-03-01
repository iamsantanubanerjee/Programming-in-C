#include<stdio.h>
void display(char []);
void play(char [],int);
void main()
{
  int count=1,i,flag=0;
  char symbol[9]={'1','2','3','4','5','6','7','8','9'};
  while(flag!=1)
	{
		printf("\033c");//clearing the screen
		display(symbol);
		play(symbol,count);
		for(i=0;i<=6;i+=3)//checking for row
			if(symbol[i]==symbol[i+1]&&symbol[i]==symbol[i+2])
			{
				printf("\033c");
				display(symbol);
				if(symbol[i]=='X')
					printf("\n\nThe winner is player 1\n");
				else
					printf("\n\nThe winner is player 2\n");
				flag=1;
			}
		for(i=0;i<3;i++)//checking for column
			if(symbol[i]==symbol[i+3]&&symbol[i]==symbol[i+6])
			{
				printf("\033c");
				display(symbol);
				if(symbol[i]=='X')
					printf("\n\nThe winner is player 1\n");
				else
					printf("\n\nThe winner is player 2\n");
				flag=1;
			}
		if(symbol[0]==symbol[4]&&symbol[0]==symbol[8])//checking for left diagonal
		{
			printf("\033c");
			display(symbol);
			if(symbol[0]=='X')
				printf("\n\nThe winner is player 1\n");
			else
				printf("\n\nThe winner is player 2\n");
			flag=1;
		}
		else if(symbol[2]==symbol[4]&&symbol[2]==symbol[6])//checking for right diagonal
		{
			printf("\033c");
			display(symbol);
			if(symbol[2]=='X')
				printf("\n\nThe winner is player 1\n");
			else
				printf("\n\nThe winner is player 2\n");
			flag=1;
		}
		else if(count==9)//for draw
		{
			printf("\033c");
			display(symbol);
			printf("\n\nThe game is draw\n");
			flag=1;
		}
	count++;
	}
}
void display(char symbol[])//displaying the game
{
	printf("\n\t     (Created by Santanu Banerjee)");
	printf("\n\nPlayer 1: X");
	printf("\t\t\t\t %c | %c | %c",symbol[0],symbol[1],symbol[2]);
	printf("\nPlayer 2: O");
	printf("\t\t\t\t---|---|---");
	printf("\n\t\t\t\t\t %c | %c | %c",symbol[3],symbol[4],symbol[5]);
	printf("\n\t\t\t\t\t---|---|---");
	printf("\n\t\t\t\t\t %c | %c | %c",symbol[6],symbol[7],symbol[8]);
}
void play(char symbol[],int count)//taking input from users
{
	int choice;
	if((count%2)==1)
	{
		printf("\n\nPlayer %d's turn - Enter the position: ",(count%2));
		scanf("%d",&choice);
		while(symbol[choice-1]=='X'||symbol[choice-1]=='O')
		{
			printf("Enter valid position: ");
			scanf("%d",&choice);
		}
		symbol[choice-1]='X';
	}
	else
	{
		printf("\n\nPlayer %d's turn - Enter the position: ",((count%2)+2));
		scanf("%d",&choice);
		while((int)symbol[choice-1]<49||(int)symbol[choice-1]>57)
		{
			printf("Enter valid position: ");
			scanf("%d",&choice);
		}
		symbol[choice-1]='O';
	}
}
