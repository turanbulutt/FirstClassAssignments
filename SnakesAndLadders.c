//Ahmet Turan Bulut 2315174
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void display_results(int round,int human,int computer,int select){
	if(human>=(select*select)||computer>=(select*select)){
		if(human>computer)
			printf("Congratulations! The player has won :) The board is completed in %d rounds. ",round);
		else
			printf("Sorry computer has won you in %d rounds :( Try again...",round);
	}
}
void check_snakes(int *player,int *snake1_1,int *snake1_7,int *snake2_1,int *snake2_7,int *snake3_1,int *snake3_6){
	if(*player==*snake1_1)			// in here player mean both computer or human if they in head of snake they goes to tail of snake
		*player=*snake1_7;
	else if(*player==*snake2_1)
		*player=*snake2_7;
	else if(*player==*snake3_1)
		*player=*snake3_6;
}
void check_ladders(int *player,int *l31_1,int *l31_3,int *l32_1,int *l32_3,int *l5_1,int *l5_5,int *l6_1,int *l6_6){
	if(*player==*l31_1)				//in here player mean both computer or human if the in hestart of ladder the goes to top of ladder
		*player=*l31_3;
	else if(*player==*l32_1)
		*player=*l32_3;
	else if(*player==*l5_1)
		*player=*l5_5;
	else if(*player==*l6_1)
		*player=*l6_6;
}
void display_board(int select,int **board,int *l5_1,int *l5_2,int *l5_3,int *l5_4,int *l5_5,int *l31_1,int *l31_2,int *l31_3,int *l32_1,int *l32_2,int *l32_3,int *snake1_1,int *snake1_2,int *snake1_3,int *snake1_4,int *snake1_5,int *snake1_6,int *snake1_7,int *snake2_1,int *snake2_2,int *snake2_3,int *snake2_4,int *snake2_5,int *snake2_6,int *snake2_7,int *l6_1,int *l6_2,int *l6_3,int *l6_4,int *l6_5,int *l6_6,int *snake3_1,int *snake3_2,int *snake3_3,int *snake3_4,int *snake3_5,int *snake3_6,int *computer,int *human){
	int i,a;
	for(i=0;i<select;i++){							// in here function prints the board with ladder,snake etc.
		for(a=0;a<select;a++){
			if(board[i][a]==*snake1_1)
				printf("%7c",'S');
			else if(board[i][a]==*snake2_1)
				printf("%7c",'N');
			else if(board[i][a]==*snake3_1)
				printf("%7c",'A');
			else if(board[i][a]==*computer)
				printf("%7c",'@');
			else if(board[i][a]==*human)
				printf("%7c",'#');
			else if(board[i][a]==*snake3_6)
				printf("%7c",'a');
			else if(board[i][a]==*snake1_7)
				printf("%7c",'s');
			else if(board[i][a]==*snake2_7)
				printf("%7c",'n');
			else if(board[i][a]==*l5_1 ||board[i][a]==*l5_2||board[i][a]==*l5_3||board[i][a]==*l5_4||board[i][a]==*l5_5||board[i][a]==*l31_1||board[i][a]==*l31_2||board[i][a]==*l31_3||board[i][a]==*l32_1||board[i][a]==*l32_2||board[i][a]==*l32_3||board[i][a]==*l6_1||board[i][a]==*l6_2||board[i][a]==*l6_3||board[i][a]==*l6_4||board[i][a]==*l6_5||board[i][a]==*l6_6)
				printf("%7c",'_');
			else if(board[i][a]==*snake1_2||board[i][a]==*snake1_3||board[i][a]==*snake1_4||board[i][a]==*snake1_5||board[i][a]==*snake1_6)
				printf("%7c",'s');
			else if(board[i][a]==*snake2_2||board[i][a]==*snake2_3||board[i][a]==*snake2_4||board[i][a]==*snake2_5||board[i][a]==*snake2_6)
				printf("%7c",'n');
			else if(board[i][a]==*snake3_2||board[i][a]==*snake3_3||board[i][a]==*snake3_4||board[i][a]==*snake3_5)
				printf("%7c",'a');
			else
				printf("%7d",board[i][a]);
		}
		printf("\n");
	}
}
int step_size(int *dice1,int *dice2){
	if(*dice1==*dice2){
		return ((-1)*(*dice1));				// decide the size of step with special cases
	}
	else if((*dice1==5 && *dice2==6)||(*dice1==6&&*dice2==5))
		return 14;
	else
		return (*dice1)+(*dice2);

}
void move(int *player,int *l31_1,int *l31_3,int *l32_1,int *l32_3,int *l5_1,int *l5_5,int *l6_1,int *l6_6,int *snake1_1,int *snake1_7,int *snake2_1,int *snake2_7,int *snake3_1,int *snake3_6){
	int dice1,dice2,dicevalue=0;
	dice1=rand()%6+1;
	dice2=rand()%6+1;								// first i roll two dice then decide step size with other function after move check if there are lhave ladder or snake
	printf("Dice1=%d Dice2=%d\n",dice1,dice2);
	dicevalue=step_size(&dice1,&dice2);
	*player+=dicevalue;
	if(*player<0)
		*player=0;
	check_snakes(player,snake1_1,snake1_7,snake2_1,snake2_7,snake3_1,snake3_6);
	check_ladders(player,l31_1,l31_3,l32_1,l32_3,l5_1,l5_5,l6_1,l6_6);
	
}
void initailizeSnakesLadders(int select,int **board,int *l5_1,int *l5_2,int *l5_3,int *l5_4,int *l5_5,int *l31_1,int *l31_2,int *l31_3,int *l32_1,int *l32_2,int *l32_3,int *snake1_1,int *snake1_2,int *snake1_3,int *snake1_4,int *snake1_5,int *snake1_6,int *snake1_7,int *snake2_1,int *snake2_2,int *snake2_3,int *snake2_4,int *snake2_5,int *snake2_6,int *snake2_7,int *l6_1,int *l6_2,int *l6_3,int *l6_4,int *l6_5,int *l6_6,int *snake3_1,int *snake3_2,int *snake3_3,int *snake3_4,int *snake3_5,int *snake3_6){
	int i,j,row,collumn,count=1,a=0,count2=1,b=0,row2,collumn2,row3,collumn3,c=0,count3=1,row4,collumn4,d=0,e=0,row5,collumn5,count4=1;
	if(select==10){
		*snake1_1=rand()%50+50;
		for(i=0;i<select;i++){
			for(j=0;j<select;j++){						// i split some snakes and ladders in the board because avoid the confliction points
				if(board[i][j]==*snake1_1){				//firstly i choose a point for bot of ladder or head of snake then i equate the value in the board then take this row and collumn number
					row4=i;								//after that decide the other part of ladder or snake. I split this part for 15x15 and 10x10
					collumn4=j;
				}		
			}
		}
		if(row4<=7)
			e=1;
		if(collumn4<=5)
			d=1;
		if(d){
			*snake1_2=board[row4][collumn4+1];
			*snake1_3=board[row4][collumn4+2];
			if(e){
				*snake1_4=board[row4+1][collumn4+2];
				*snake1_5=board[row4+2][collumn4+2];
				*snake1_6=board[row4+2][collumn4+3];
				*snake1_7=board[row4+2][collumn4+4];
			}
			else{
				*snake1_4=board[row4-1][collumn4+2];
				*snake1_5=board[row4-2][collumn4+2];
				*snake1_6=board[row4-2][collumn4+3];
				*snake1_7=board[row4-2][collumn4+4];
			}
		}
		else{
			*snake1_2=board[row4][collumn4-1];
			*snake1_3=board[row4][collumn4-2];
			if(e){
				*snake1_4=board[row4+1][collumn4-2];
				*snake1_5=board[row4+2][collumn4-2];
				*snake1_6=board[row4+2][collumn4-3];
				*snake1_7=board[row4+2][collumn4-4];
			}
			else{
				*snake1_4=board[row4-1][collumn4-2];
				*snake1_5=board[row4-2][collumn4-2];
				*snake1_6=board[row4-2][collumn4-3];
				*snake1_7=board[row4-2][collumn4-4];
			}
		}
		*snake2_1=rand()%25+25;
		for(i=0;i<select;i++){
			for(j=0;j<select;j++){
				if(board[i][j]==*snake2_1){
					row5=i;
					collumn5=j;
				}		
			}
		}
		e=0;
		d=0;
		if(row5<=7)
			e=1;
		if(collumn5<=5)
			d=1;
		if(d){
			*snake2_2=board[row5][collumn5+1];
			*snake2_3=board[row5][collumn5+2];
			if(e){
				*snake2_4=board[row5+1][collumn5+2];
				*snake2_5=board[row5+2][collumn5+2];
				*snake2_6=board[row5+2][collumn5+3];
				*snake2_7=board[row5+2][collumn5+4];
			}
			else{
				*snake2_4=board[row5-1][collumn5+2];
				*snake2_5=board[row5-2][collumn5+2];
				*snake2_6=board[row5-2][collumn5+3];
				*snake2_7=board[row5-2][collumn5+4];
			}
		}
		else{
			*snake2_2=board[row5][collumn5-1];
			*snake2_3=board[row5][collumn5-2];
			if(e){
				*snake2_4=board[row5+1][collumn5-2];
				*snake2_5=board[row5+2][collumn5-2];
				*snake2_6=board[row5+2][collumn5-3];
				*snake2_7=board[row5+2][collumn5-4];
			}
			else{
				*snake2_4=board[row5-1][collumn5-2];
				*snake2_5=board[row5-2][collumn5-2];
				*snake2_6=board[row5-2][collumn5-3];
				*snake2_7=board[row5-2][collumn5-4];
			}
		}
		*l5_1=*snake2_1;
		*l5_2=*snake2_1;
		*l5_3=*snake2_1;
		*l5_4=*snake2_1;
		*l5_5=*snake2_1;
		while(*l5_1==*snake2_1||*l5_1==*snake2_2||*l5_1==*snake2_3||*l5_1==*snake2_4||*l5_1==*snake2_5||*l5_1==*snake2_6||*l5_1==*snake2_7||*l5_2==*snake2_1||*l5_2==*snake2_2||*l5_2==*snake2_3||*l5_2==*snake2_4||*l5_2==*snake2_5||*l5_2==*snake2_6||*l5_2==*snake2_7||*l5_3==*snake2_1||*l5_3==*snake2_2||*l5_3==*snake2_3||*l5_3==*snake2_4||*l5_3==*snake2_5||*l5_3==*snake2_6||*l5_3==*snake2_7||*l5_4==*snake2_1||*l5_4==*snake2_2||*l5_4==*snake2_3||*l5_4==*snake2_4||*l5_4==*snake2_5||*l5_4==*snake2_6||*l5_4==*snake2_7||*l5_5==*snake2_1||*l5_5==*snake2_2||*l5_5==*snake2_3||*l5_5==*snake2_4||*l5_5==*snake2_5||*l5_5==*snake2_6||*l5_5==*snake2_7){
			*l5_1=rand()%10+41;
			for(i=0;i<select;i++){
				for(j=0;j<select;j++){
					if(board[i][j]==*l5_1){
						row=i;
						collumn=j;
					}	
				}
			}
			*l5_2=board[row+1][collumn];
			*l5_3=board[row+2][collumn];
			*l5_4=board[row+3][collumn];
			*l5_5=board[row+4][collumn];
		}
		*l31_1=*snake1_1;
		*l31_2=*snake1_1;
		*l31_3=*snake1_1;
		while(*l31_1==*snake1_1||*l31_1==*snake1_2||*l31_1==*snake1_3||*l31_1==*snake1_4||*l31_1==*snake1_5||*l31_1==*snake1_6||*l31_1==*snake1_7||*l31_2==*snake1_1||*l31_2==*snake1_2||*l31_2==*snake1_3||*l31_2==*snake1_4||*l31_2==*snake1_5||*l31_2==*snake1_6||*l31_2==*snake1_7||*l31_3==*snake1_1||*l31_3==*snake1_2||*l31_3==*snake1_3||*l31_3==*snake1_4||*l31_3==*snake1_5||*l31_3==*snake1_6||*l31_3==*snake1_7){
			*l31_1=rand()%10+61;
			for(i=0;i<select;i++){
				for(j=0;j<select;j++){
					if(board[i][j]==*l31_1){
						row2=i;
						collumn2=j;
					}
					
				}
			}
			*l31_2=board[row2-1][collumn2];
			*l31_3=board[row2-2][collumn2];
		}
		*l32_1=*snake1_1;
		*l32_2=*snake1_1;
		*l32_3=*snake1_1;
		while(*l32_1==*snake1_1||*l32_1==*snake1_2||*l32_1==*snake1_3||*l32_1==*snake1_4||*l32_1==*snake1_5||*l32_1==*snake1_6||*l32_1==*snake1_7||*l32_2==*snake1_1||*l32_2==*snake1_2||*l32_2==*snake1_3||*l32_2==*snake1_4||*l32_2==*snake1_5||*l32_2==*snake1_6||*l32_2==*snake1_7||*l32_3==*snake1_1||*l32_3==*snake1_2||*l32_3==*snake1_3||*l32_3==*snake1_4||*l32_3==*snake1_5||*l32_3==*snake1_6||*l32_3==*snake1_7||*l32_1==*l31_1){
			*l32_1=rand()%10+61;
			for(i=0;i<select;i++){
				for(j=0;j<select;j++){
					if(board[i][j]==*l32_1){
						row2=i;
						collumn2=j;
					}		
				}
			}
			*l32_2=board[row2-1][collumn2];
			*l32_3=board[row2-2][collumn2];
		}
	}
	else if(select==15){						//start of 15x15 board snakes and ladders
		*snake1_1=rand()%29+196;
		for(i=0;i<select;i++){
			for(j=0;j<select;j++){
				if(board[i][j]==*snake1_1){
					row4=i;
					collumn4=j;
				}		
			}
		}
		if(row4<=12)
			e=1;
		if(collumn4<=10)
			d=1;
		if(d){
			*snake1_2=board[row4][collumn4+1];
			*snake1_3=board[row4][collumn4+2];
			if(e){
				*snake1_4=board[row4+1][collumn4+2];
				*snake1_5=board[row4+2][collumn4+2];
				*snake1_6=board[row4+2][collumn4+3];
				*snake1_7=board[row4+2][collumn4+4];
			}
			else{
				*snake1_4=board[row4-1][collumn4+2];
				*snake1_5=board[row4-2][collumn4+2];
				*snake1_6=board[row4-2][collumn4+3];
				*snake1_7=board[row4-2][collumn4+4];
			}
		}
		else{
			*snake1_2=board[row4][collumn4-1];
			*snake1_3=board[row4][collumn4-2];
			if(e){
				*snake1_4=board[row4+1][collumn4-2];
				*snake1_5=board[row4+2][collumn4-2];
				*snake1_6=board[row4+2][collumn4-3];
				*snake1_7=board[row4+2][collumn4-4];
			}
			else{
				*snake1_4=board[row4-1][collumn4-2];
				*snake1_5=board[row4-2][collumn4-2];
				*snake1_6=board[row4-2][collumn4-3];
				*snake1_7=board[row4-2][collumn4-4];
			}
		}
		*snake2_1=rand()%26+35;
		for(i=0;i<select;i++){
			for(j=0;j<select;j++){
				if(board[i][j]==*snake2_1){
					row5=i;
					collumn5=j;
				}		
			}
		}
		e=0;
		d=0;
		if(row5<=12)
			e=1;
		if(collumn5<=10)
			d=1;
		if(d){
			*snake2_2=board[row5][collumn5+1];
			*snake2_3=board[row5][collumn5+2];
			if(e){
				*snake2_4=board[row5+1][collumn5+2];
				*snake2_5=board[row5+2][collumn5+2];
				*snake2_6=board[row5+2][collumn5+3];
				*snake2_7=board[row5+2][collumn5+4];
			}
			else{
				*snake2_4=board[row5-1][collumn5+2];
				*snake2_5=board[row5-2][collumn5+2];
				*snake2_6=board[row5-2][collumn5+3];
				*snake2_7=board[row5-2][collumn5+4];
			}
		}
		else{
			*snake2_2=board[row5][collumn5-1];
			*snake2_3=board[row5][collumn5-2];
			if(e){
				*snake2_4=board[row5+1][collumn5-2];
				*snake2_5=board[row5+2][collumn5-2];
				*snake2_6=board[row5+2][collumn5-3];
				*snake2_7=board[row5+2][collumn5-4];
			}
			else{
				*snake2_4=board[row5-1][collumn5-2];
				*snake2_5=board[row5-2][collumn5-2];
				*snake2_6=board[row5-2][collumn5-3];
				*snake2_7=board[row5-2][collumn5-4];
			}
		}
		*snake3_1=rand()%15+151;
		for(i=0;i<select;i++){
			for(j=0;j<select;j++){
				if(board[i][j]==*snake3_1){
					row4=i;
					collumn4=j;
				}		
			}
		}
		*snake3_2=board[row4+1][collumn4];
		*snake3_3=board[row4+2][collumn4];
		*snake3_4=board[row4+3][collumn4];
		*snake3_5=board[row4+4][collumn4];
		*snake3_6=board[row4+5][collumn4];
		*l5_1=*snake2_1;
		*l5_2=*snake2_1;
		*l5_3=*snake2_1;
		*l5_4=*snake2_1;
		*l5_5=*snake2_1;
		while(*l5_1==*snake2_1||*l5_1==*snake2_2||*l5_1==*snake2_3||*l5_1==*snake2_4||*l5_1==*snake2_5||*l5_1==*snake2_6||*l5_1==*snake2_7||*l5_2==*snake2_1||*l5_2==*snake2_2||*l5_2==*snake2_3||*l5_2==*snake2_4||*l5_2==*snake2_5||*l5_2==*snake2_6||*l5_2==*snake2_7||*l5_3==*snake2_1||*l5_3==*snake2_2||*l5_3==*snake2_3||*l5_3==*snake2_4||*l5_3==*snake2_5||*l5_3==*snake2_6||*l5_3==*snake2_7||*l5_4==*snake2_1||*l5_4==*snake2_2||*l5_4==*snake2_3||*l5_4==*snake2_4||*l5_4==*snake2_5||*l5_4==*snake2_6||*l5_4==*snake2_7||*l5_5==*snake2_1||*l5_5==*snake2_2||*l5_5==*snake2_3||*l5_5==*snake2_4||*l5_5==*snake2_5||*l5_5==*snake2_6||*l5_5==*snake2_7){
			*l5_1=rand()%15+1;
			for(i=0;i<select;i++){
				for(j=0;j<select;j++){
					if(board[i][j]==*l5_1){
						row=i;
						collumn=j;
					}	
				}
			}
			*l5_2=board[row-1][collumn];
			*l5_3=board[row-2][collumn];
			*l5_4=board[row-3][collumn];
			*l5_5=board[row-4][collumn];
		}
		*l6_1=*snake3_1;
		while(*l6_1==*snake3_1)
			*l6_1=rand()%15+61;
		for(i=0;i<select;i++){
			for(j=0;j<select;j++){
				if(board[i][j]==*l6_1){
					row4=i;
					collumn4=j;
				}		
			}
		}
		*l6_2=board[row4-1][collumn4];
		*l6_3=board[row4-2][collumn4];
		*l6_4=board[row4-3][collumn4];
		*l6_5=board[row4-4][collumn4];
		*l6_6=board[row4-5][collumn4];
		*l31_1=*snake1_1;
		*l31_2=*snake1_1;
		*l31_3=*snake1_1;
		while(*l31_1==*snake1_1||*l31_1==*snake1_2||*l31_1==*snake1_3||*l31_1==*snake1_4||*l31_1==*snake1_5||*l31_1==*snake1_6||*l31_1==*snake1_7||*l31_2==*snake1_1||*l31_2==*snake1_2||*l31_2==*snake1_3||*l31_2==*snake1_4||*l31_2==*snake1_5||*l31_2==*snake1_6||*l31_2==*snake1_7||*l31_3==*snake1_1||*l31_3==*snake1_2||*l31_3==*snake1_3||*l31_3==*snake1_4||*l31_3==*snake1_5||*l31_3==*snake1_6||*l31_3==*snake1_7){
			*l31_1=rand()%30+166;
			for(i=0;i<select;i++){
				for(j=0;j<select;j++){
					if(board[i][j]==*l31_1){
						row2=i;
						collumn2=j;
					}
					
				}
			}
			*l31_2=board[row2-1][collumn2];
			*l31_3=board[row2-2][collumn2];
		}
		*l32_1=*snake1_1;
		*l32_2=*snake1_1;
		*l32_3=*snake1_1;
		while(*l32_1==*snake1_1||*l32_1==*snake1_2||*l32_1==*snake1_3||*l32_1==*snake1_4||*l32_1==*snake1_5||*l32_1==*snake1_6||*l32_1==*snake1_7||*l32_2==*snake1_1||*l32_2==*snake1_2||*l32_2==*snake1_3||*l32_2==*snake1_4||*l32_2==*snake1_5||*l32_2==*snake1_6||*l32_2==*snake1_7||*l32_3==*snake1_1||*l32_3==*snake1_2||*l32_3==*snake1_3||*l32_3==*snake1_4||*l32_3==*snake1_5||*l32_3==*snake1_6||*l32_3==*snake1_7||*l32_1==*l31_1){
			*l32_1=rand()%30+166;
			for(i=0;i<select;i++){
				for(j=0;j<select;j++){
					if(board[i][j]==*l32_1){
						row2=i;
						collumn2=j;
					}		
				}
			}
			*l32_2=board[row2-1][collumn2];
			*l32_3=board[row2-2][collumn2];
		}	
	}	
}
void initailizeBoard(int **board,int select){
	int i,count=1,j,*opposite;
	opposite=(int *)malloc(select*(sizeof(int)));
	for(i=select-1;i>=0;i--)
	{
		for(j=0;j<select;j++){										// in this function i initialize the board according to selected size(15x15 or 10x10)
			board[i][j]=count;
			count++;
		}
	}
	for(i=0;i<select;i++){
		if(i%2==1&&select==15){
			for(j=0;j<select;j++){
				opposite[j]=board[i][j];
			}
			for(j=0;j<select;j++){
				board[i][select-1-j]=opposite[j];
			}
		}
		else if(i%2==0 &&select==10){
			for(j=0;j<select;j++){
				opposite[j]=board[i][j];
			}
			for(j=0;j<select;j++){
				board[i][select-1-j]=opposite[j];
			}
			
		}
		
	}	
}
int main(){
	int select,humand=0,computerd=0,**board,i,a,l5_1=0,l5_2=0,l5_3=0,l5_4=0,l5_5=0,l31_1=0,l31_2=0,l31_3=0,l32_1=0,l32_2=0,l32_3=0,snake1_1=0,snake1_2=0,snake1_3=0,snake1_4=0,snake1_5=0,snake1_6=0,snake1_7=0;
	char c,forenter;
	int human=0,computer=0,check=0,round=0;
	int snake2_1=0,snake2_2=0,snake2_3=0,snake2_4=0,snake2_5=0,snake2_6=0,snake2_7=0,l6_1=0,l6_2=0,l6_3=0,l6_4=0,l6_5=0,l6_6=0,snake3_1=0,snake3_2=0,snake3_3=0,snake3_4=0,snake3_5=0,snake3_6=0;
	srand(time(0));
	printf("Hello the game Snakes and Ladders!!!\n\nPlease select the size of the board:\n1-Board size 10x10\n2-Board size 15x15\nSelect:");
	scanf("%d",&select);
	if(select==1){
		printf("10x10 board selected.");
		select=10;
		}														//first ask user which board that s/he want to play
	else{
		printf("15x15 board selected");
		select=15;
		}
	printf("\nDeciding who goes first!!!\n");
	
	while(humand==computerd){
		humand=rand()%6+1;
		computerd=rand()%6+1;									// decide who start the game
	}
	if(humand>computerd)
		check=1;
	printf("Player:%d	Computer:%d",humand,computerd);
	if(humand>computerd)
		printf("\nPlayer goes first!");
	else
		printf("\nComputer goes first!");
	printf("\nPlayer will shows like # in the board and computer will shows like @ in the board.\nLadders will show like _ and snakes will show like(Ss,Nn,Aa)\n");
	board=(int **)malloc(select*(sizeof(int*)));
	for(i=0;i<select;i++)
		board[i]=(int *)malloc(select*(sizeof(int*)));
	initailizeBoard(board,select);
	initailizeSnakesLadders(select,board,&l5_1,&l5_2,&l5_3,&l5_4,&l5_5,&l31_1,&l31_2,&l31_3,&l32_1,&l32_2,&l32_3,&snake1_1,&snake1_2,&snake1_3,&snake1_4,&snake1_5,&snake1_6,&snake1_7,&snake2_1,&snake2_2,&snake2_3,&snake2_4,&snake2_5,&snake2_6,&snake2_7,&l6_1,&l6_2,&l6_3,&l6_4,&l6_5,&l6_6,&snake3_1,&snake3_2,&snake3_3,&snake3_4,&snake3_5,&snake3_6);
	display_board(select,board,&l5_1,&l5_2,&l5_3,&l5_4,&l5_5,&l31_1,&l31_2,&l31_3,&l32_1,&l32_2,&l32_3,&snake1_1,&snake1_2,&snake1_3,&snake1_4,&snake1_5,&snake1_6,&snake1_7,&snake2_1,&snake2_2,&snake2_3,&snake2_4,&snake2_5,&snake2_6,&snake2_7,&l6_1,&l6_2,&l6_3,&l6_4,&l6_5,&l6_6,&snake3_1,&snake3_2,&snake3_3,&snake3_4,&snake3_5,&snake3_6,&computer,&human);
	if(select==10){
		while(human<100||computer<100){
			if(check){						//i split this part in to 2 part according to size of board after that i split again according to who goes first
				round++;
				printf("Round:%d\n",round);
				printf("Your ");
				move(&human,&l31_1,&l31_3,&l32_1,&l32_3,&l5_1,&l5_5,&l6_1,&l6_6,&snake1_1,&snake1_7,&snake2_1,&snake2_7,&snake3_1,&snake3_6);
				if(human>=100)
					break;
				printf("Computer's ");
				move(&computer,&l31_1,&l31_3,&l32_1,&l32_3,&l5_1,&l5_5,&l6_1,&l6_6,&snake1_1,&snake1_7,&snake2_1,&snake2_7,&snake3_1,&snake3_6);
				if(computer>=100)
					break;
				display_board(select,board,&l5_1,&l5_2,&l5_3,&l5_4,&l5_5,&l31_1,&l31_2,&l31_3,&l32_1,&l32_2,&l32_3,&snake1_1,&snake1_2,&snake1_3,&snake1_4,&snake1_5,&snake1_6,&snake1_7,&snake2_1,&snake2_2,&snake2_3,&snake2_4,&snake2_5,&snake2_6,&snake2_7,&l6_1,&l6_2,&l6_3,&l6_4,&l6_5,&l6_6,&snake3_1,&snake3_2,&snake3_3,&snake3_4,&snake3_5,&snake3_6,&computer,&human);
			}
			else{
				round++;
				printf("Round:%d\n",round);
				printf("Computer's ");
				move(&computer,&l31_1,&l31_3,&l32_1,&l32_3,&l5_1,&l5_5,&l6_1,&l6_6,&snake1_1,&snake1_7,&snake2_1,&snake2_7,&snake3_1,&snake3_6);
				if(computer>=100)
					break;
				printf("Your ");
				move(&human,&l31_1,&l31_3,&l32_1,&l32_3,&l5_1,&l5_5,&l6_1,&l6_6,&snake1_1,&snake1_7,&snake2_1,&snake2_7,&snake3_1,&snake3_6);
				if(human>=100)
					break;
				display_board(select,board,&l5_1,&l5_2,&l5_3,&l5_4,&l5_5,&l31_1,&l31_2,&l31_3,&l32_1,&l32_2,&l32_3,&snake1_1,&snake1_2,&snake1_3,&snake1_4,&snake1_5,&snake1_6,&snake1_7,&snake2_1,&snake2_2,&snake2_3,&snake2_4,&snake2_5,&snake2_6,&snake2_7,&l6_1,&l6_2,&l6_3,&l6_4,&l6_5,&l6_6,&snake3_1,&snake3_2,&snake3_3,&snake3_4,&snake3_5,&snake3_6,&computer,&human);
			}
			fflush(stdin);
			printf("Player:%d Computer:%d\n",human,computer);
			printf("Do you want the continue?(y/n):");
			scanf("%c",&c);								
			while(c!='y'|| c!='Y'){
				if(c=='n'||c=='N')
					break;
				else if(c=='y'|| c=='Y')
					break;
				fflush(stdin);
				printf("Please enter correct words\nDo you want the continue?(y/n):");
				scanf("%c",&c);
				
				
			}	
			if(c=='n'||c=='N')
				break;						
			system("cls");
		}
	}
	else if(select==15){								//start for 15x15 board
		while(human<225||computer<225){
			if(check){
				round++;
				printf("Round:%d\n",round);
				printf("Your ");
				move(&human,&l31_1,&l31_3,&l32_1,&l32_3,&l5_1,&l5_5,&l6_1,&l6_6,&snake1_1,&snake1_7,&snake2_1,&snake2_7,&snake3_1,&snake3_6);
				if(human>=225)
					break;
				printf("Computer's ");
				move(&computer,&l31_1,&l31_3,&l32_1,&l32_3,&l5_1,&l5_5,&l6_1,&l6_6,&snake1_1,&snake1_7,&snake2_1,&snake2_7,&snake3_1,&snake3_6);
				if(computer>=225)
					break;
				display_board(select,board,&l5_1,&l5_2,&l5_3,&l5_4,&l5_5,&l31_1,&l31_2,&l31_3,&l32_1,&l32_2,&l32_3,&snake1_1,&snake1_2,&snake1_3,&snake1_4,&snake1_5,&snake1_6,&snake1_7,&snake2_1,&snake2_2,&snake2_3,&snake2_4,&snake2_5,&snake2_6,&snake2_7,&l6_1,&l6_2,&l6_3,&l6_4,&l6_5,&l6_6,&snake3_1,&snake3_2,&snake3_3,&snake3_4,&snake3_5,&snake3_6,&computer,&human);
			}
			else{
				round++;
				printf("Round:%d\n",round);
				printf("Computer's ");
				move(&computer,&l31_1,&l31_3,&l32_1,&l32_3,&l5_1,&l5_5,&l6_1,&l6_6,&snake1_1,&snake1_7,&snake2_1,&snake2_7,&snake3_1,&snake3_6);
				if(computer>=225)
					break;
				printf("Your ");
				move(&human,&l31_1,&l31_3,&l32_1,&l32_3,&l5_1,&l5_5,&l6_1,&l6_6,&snake1_1,&snake1_7,&snake2_1,&snake2_7,&snake3_1,&snake3_6);
				if(human>=225)
					break;
				display_board(select,board,&l5_1,&l5_2,&l5_3,&l5_4,&l5_5,&l31_1,&l31_2,&l31_3,&l32_1,&l32_2,&l32_3,&snake1_1,&snake1_2,&snake1_3,&snake1_4,&snake1_5,&snake1_6,&snake1_7,&snake2_1,&snake2_2,&snake2_3,&snake2_4,&snake2_5,&snake2_6,&snake2_7,&l6_1,&l6_2,&l6_3,&l6_4,&l6_5,&l6_6,&snake3_1,&snake3_2,&snake3_3,&snake3_4,&snake3_5,&snake3_6,&computer,&human);
			}
			fflush(stdin);
			printf("Player:%d Computer:%d\n",human,computer);
			printf("Do you want the continue?(y/n):");
			scanf("%c",&c);	
			while(c!='y'||c!='Y'){
				if(c=='n'||c=='N')
					break;
				else if(c=='y'|| c=='Y')
					break;
				fflush(stdin);
				printf("Please enter correct words\nDo you want the continue?(y/n):");
				scanf("%c",&c);
				
				
			}
			if(c=='n'||c=='N')
				break;
			system("cls");
		}
	}
	system("cls");
	display_results(round,human,computer,select);
	
	
	
	
	return 0;
}
