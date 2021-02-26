#include<stdio.h>
//Ahmet Turan Bulut 2315174
void scoresheet (int total_human,int total_pc, int round)
{// to show score sheet
	printf("Round %d Scoresheet\n---------------------------------------\n",round);
	printf("Computer: %d",total_pc);
	printf("\nPlayer: %d\n",total_human);

}
float computer_strategy_decider(float total1,float total2,float total3,float total4,float total5,float total6)
{//first I calculate the total point of each option then in here decide which one is best for computer
	if(total1>total2 && total1>total3 && total1>total4 && total1>total5 && total1>total6)
	{
		printf("Computer selects Fives\n");
		return total1+0.1;
	}
	else if(total2>total1 && total2>total3 && total2>total4 && total2>total5 && total2>total6)
	{
		printf("Computer selects Sixes\n");
		return total2+0.2;
	}
	else if(total3>total1 && total3>total2 && total3>total4 && total3>total5 && total3>total6)
	{
		printf("Computer selects Three of a kind\n");
		return total3+0.3;
	}
	else if(total4>total1 && total4>total2 && total4>total3 && total4>total5 && total4>total6)
	{
		printf("Computer selects Large Straight\n");
		return total4+0.4;
	}
	else if(total5>total1 && total5>total2 && total5>total3 && total5>total4 && total5>total6)
	{
		printf("Computer selects Yahtzee\n");
		return total5+0.5;
	}
	else if(total6>total1 && total6>total2 && total6>total3 && total6>total4 && total6>total5)
	{
		printf("Computer selects Chance\n");
		return total6+0.6;
	}
}
float play_pc (int choose01, int choose02,int choose03,int choose04,int choose05,int choose06)
{// roll a dice then calculate every option for computer
	int dice1,dice2,dice3,dice4,dice5,i=1,a,j,same=0;
	float total1=0.0,total2=0.0,total3=0.0,total4=0.0,total5=0.0,total6=0.0,total=0.0;
	dice1=roll_a_dice();
	dice2=roll_a_dice();
	dice3=roll_a_dice();
	dice4=roll_a_dice();
	dice5=roll_a_dice();
	printf("Dice1: %d, Dice2: %d, Dice3: %d, Dice4: %d, Dice5: %d\n",dice1,dice2,dice3,dice4,dice5);
	while(i<=6)
	{
		if(i==1 && choose01==0)
		{// if dices equal to 5 increase the total 5
			if(dice1==5)
			total1+=5;
			if(dice2==5)
			total1+=5;
			if(dice3==5)
			total1+=5;
			if(dice4==5)
			total1+=5;
			if(dice5==5)
			total1+=5;
		}
		else if(i==2 && choose02==0)
		{// if dices equal to 6 increase the total 6
			if(dice1==6)
			total2+=6;
			if(dice2==6)
			total2+=6;
			if(dice3==6)
			total2+=6;
			if(dice4==6)
			total2+=6;
			if(dice5==6)
			total2+=6;
		}
		else if(i==3 && choose03==0)
		{//first equal random letter to dice 1 and check other dices if they are euqal or not if there are more then 3 dice it breaks the loop
			for(a=1;a<=5;a++){
				if(a==1)
					j=dice1;
				else if(a==2)
					j=dice2;
				else if(a==3)
					j=dice3;
				else if(a==4)
					j=dice4;
				else if(a==5)
					j=dice5;
				if(j==dice1)
					same++;
				if(j==dice2)
					same++;
				if(j==dice3)
					same++;
				if(j==dice4)
					same++;
				if(j==dice5)
					same++;
				if(same>=3){
					total3=j*same;
					break;
				}
				else
					same=0;
			}
		}
		else if(i==4 && choose04==0)
		{
			if((dice1!=dice2 && dice1!=dice3 && dice1!=dice4 && dice1!=dice5)&&(dice2!=dice3 && dice2!=dice4 && dice2!=dice5)&&(dice3!=dice4 && dice3!=dice5)&&(dice4!=dice5) && (dice1+dice2+dice3+dice4+dice5==15 || dice1+dice2+dice3+dice4+dice5==20))
				total4=40;
		}
		else if(i==5 && choose05==0)
		{
			if(dice1==dice2 && dice1==dice3 && dice1==dice4 && dice1==dice5)
				total5=50;
		}
		else if(i==6 && choose06==0)
		{
			total6=dice1+dice2+dice3+dice4+dice5;
		}
		i++;
	}
	total=computer_strategy_decider(total1,total2,total3,total4,total5,total6);// decide which strategy will use
	return total;
}
int human_play (int choose1, int choose2,int choose3,int choose4,int choose5,int choose6)
{
	int dice1,dice2,dice3,dice4,dice5,time=1,total=0,choose,use=0,i,j=0,same=0;
	char check,forenter,c;

	while (time<=3)
	{
		dice1=roll_a_dice();
		dice2=roll_a_dice();
		dice3=roll_a_dice();
		dice4=roll_a_dice();
		dice5=roll_a_dice();
		printf("Dice1: %d, Dice2: %d, Dice3: %d, Dice4: %d, Dice5: %d\n",dice1,dice2,dice3,dice4,dice5);
		if(time==3)
		{
			break;
		}
		printf("Do you want to roll or not (Y/N):");
		scanf("%c",&check);
		scanf("%c",&forenter);
		if(check=='N' || check=='n')
		{
			break;
		}
		time++;

	}
	if(choose1==0)
	{
		printf("11.Fives\n");
	}
	if(choose2==0)
	{
		printf("22.Sixes\n");
	}
	if(choose3==0)
	{
		printf("33.Three of a kind\n");
	}
	if(choose4==0)
	{
		printf("44.Large Straight\n");
	}
	if(choose5==0)
	{
		printf("55,Yahtzee\n");
	}
	if(choose6==0)
	{
		printf("66.Chance\n");
	}
	scanf("%c",&c);
	switch(c)
	{
		case'1':{
			if(dice1==5)
			total+=5;
			if(dice2==5)
			total+=5;
			if(dice3==5)
			total+=5;
			if(dice4==5)
			total+=5;
			if(dice5==5)
			total+=5;
			break;
		}
		case '2':{
			if(dice1==6)
			total+=6;
			if(dice2==6)
			total+=6;
			if(dice3==6)
			total+=6;
			if(dice4==6)
			total+=6;
			if(dice5==6)
			total+=6;
			break;
		}
		case '3':{
			for(i=1;i<=5;i++){
				if(i==1)
					j=dice1;
				else if(i==2)
					j=dice2;
				else if(i==3)
					j=dice3;
				else if(i==4)
					j=dice4;
				else if(i==5)
					j=dice5;
				if(j==dice1)
					same++;
				if(j==dice2)
					same++;
				if(j==dice3)
					same++;
				if(j==dice4)
					same++;
				if(j==dice5)
					same++;
				if(same>=3){
					total=j*same;
					break;
				}
				else
					same=0;
			}

			break;
		}
		case '4':{
			if((dice1!=dice2 && dice1!=dice3 && dice1!=dice4 && dice1!=dice5)&&(dice2!=dice3 && dice2!=dice4 && dice2!=dice5)&&(dice3!=dice4 && dice3!=dice5)&&(dice4!=dice5) && (dice1+dice2+dice3+dice4+dice5==15 || dice1+dice2+dice3+dice4+dice5==20))
				total=40;
			break;
		}
		case '5':{
			if(dice1==dice2 && dice1==dice3 && dice1==dice4 && dice1==dice5)
				total=50;
			break;
		}
		case '6':{
			total=dice1+dice2+dice3+dice4+dice5;
			break;
		}

	}
	return total;

}
int roll_a_dice (void)
{
	return rand()%6+1;
}
int main()
 {
 	int com=0,user=0,round1_human,choose1=0,choose2=0,choose3=0,choose4=0,choose5=0,choose6=0,round2_human=0,total_human=0,choose01=0,choose02=0,choose03=0,choose04=0,choose05=0,choose06=0;
 	char forenter,check;
 	int iround1_pc=0,pcheck,round=1,iround2_pc=0,round3_human,iround3_pc=0,iround4_pc=0,iround5_pc=0,iround6_pc=0,round4_human,round5_human,round6_human;
 	float total_pc=0.0,round1_pc=0.0,round2_pc=0.0,round3_pc=0.0,round4_pc=0.0,round5_pc=0.0,round6_pc=0.0;
 	srand(time(0));
	printf("Welcome to the Yhatzee game.\nLet's see who is lucky!\n");
	while(com==user)
	{
		com=roll_a_dice();
		user=roll_a_dice();
	}
	printf("Player: %d - Machine: %d\n",user,com);
	if(com<user)
	{
		printf("Player is the lucky one, lets get started!\n");
	}
	else
	{
		printf("Machine is the lucky one, lets get started!\n");
	}
	printf("Round: 1\n======================================\n");
	if(com<user)
	{
		printf("Rolled the dice for you:\n");
		round1_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round1_human;
		printf("Your score is: %d, and your total is: %d\n",round1_human,total_human);
		printf("Rolled the dice for computer:\n");
		round1_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round1_pc=round1_pc*10;
		iround1_pc=round1_pc;
		pcheck=iround1_pc%10;
		round1_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round1_pc/=10;
		total_pc+=round1_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round1_pc,total_pc);
	}
	else if(com>user)
	{
		printf("Rolled the dice for computer:\n");
		round1_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round1_pc=round1_pc*10;
		iround1_pc=round1_pc;
		pcheck=iround1_pc%10;
		round1_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round1_pc/=10;
		total_pc+=round1_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round1_pc,total_pc);
		printf("Rolled the dice for you:\n");
		round1_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round1_human;
		printf("Your score is: %d, and your total is: %d\n",round1_human,total_human);
	}
	scoresheet(total_human,total_pc,round);
	round++;
	printf("Round: 2\n======================================\n");
	if(com<user)
	{
		printf("Rolled the dice for you:\n");
		round2_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round2_human;
		printf("Your score is: %d, and your total is: %d\n",round2_human,total_human);
		printf("Rolled the dice for computer:\n");
		round2_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round2_pc=round2_pc*10;
		iround2_pc=round2_pc;
		pcheck=iround2_pc%10;
		round2_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round2_pc/=10;
		total_pc+=round2_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round2_pc,total_pc);
	}
	else if(com>user)
	{
		printf("Rolled the dice for computer:\n");
		round2_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round2_pc=round2_pc*10;
		iround2_pc=round2_pc;
		pcheck=iround2_pc%10;
		round2_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round2_pc/=10;
		total_pc+=round2_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round2_pc,total_pc);
		printf("Rolled the dice for you:\n");
		round2_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round2_human;
		printf("Your score is: %d, and your total is: %d\n",round2_human,total_human);
	}
	scoresheet(total_human,total_pc,round);
	round++;
	printf("Round: 3\n======================================\n");
	if(com<user)
	{
		printf("Rolled the dice for you:\n");
		round3_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round3_human;
		printf("Your score is: %d, and your total is: %d\n",round3_human,total_human);
		printf("Rolled the dice for computer:\n");
		round3_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round3_pc=round3_pc*10;
		iround3_pc=round3_pc;
		pcheck=iround3_pc%10;
		round3_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round3_pc/=10;
		total_pc+=round3_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round3_pc,total_pc);
	}
	else if(com>user)
	{
		printf("Rolled the dice for computer:\n");
		round3_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round3_pc=round3_pc*10;
		iround3_pc=round3_pc;
		pcheck=iround3_pc%10;
		round3_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round3_pc/=10;
		total_pc+=round3_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round3_pc,total_pc);
		printf("Rolled the dice for you:\n");
		round3_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round3_human;
		printf("Your score is: %d, and your total is: %d\n",round3_human,total_human);
	}
	scoresheet(total_human,total_pc,round);
	round++;
	printf("Round: 4\n======================================\n");
	if(com<user)
	{
		printf("Rolled the dice for you:\n");
		round4_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round4_human;
		printf("Your score is: %d, and your total is: %d\n",round4_human,total_human);
		printf("Rolled the dice for computer:\n");
		round4_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round4_pc=round4_pc*10;
		iround4_pc=round4_pc;
		pcheck=iround4_pc%10;
		round4_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round4_pc/=10;
		total_pc+=round4_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round4_pc,total_pc);
	}
	else if(com>user)
	{
		printf("Rolled the dice for computer:\n");
		round4_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round4_pc=round4_pc*10;
		iround4_pc=round4_pc;
		pcheck=iround4_pc%10;
		round4_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round4_pc/=10;
		total_pc+=round4_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round4_pc,total_pc);
		printf("Rolled the dice for you:\n");
		round4_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round4_human;
		printf("Your score is: %d, and your total is: %d\n",round4_human,total_human);
	}
	scoresheet(total_human,total_pc,round);
	round++;
	printf("Round: 5\n======================================\n");
	if(com<user)
	{
		printf("Rolled the dice for you:\n");
		round5_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round5_human;
		printf("Your score is: %d, and your total is: %d\n",round5_human,total_human);
		printf("Rolled the dice for computer:\n");
		round5_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round5_pc=round5_pc*10;
		iround5_pc=round5_pc;
		pcheck=iround5_pc%10;
		round5_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round5_pc/=10;
		total_pc+=round5_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round5_pc,total_pc);
	}
	else if(com>user)
	{
		printf("Rolled the dice for computer:\n");
		round5_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round5_pc=round5_pc*10;
		iround5_pc=round5_pc;
		pcheck=iround5_pc%10;
		round5_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round5_pc/=10;
		total_pc+=round5_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round5_pc,total_pc);
		printf("Rolled the dice for you:\n");
		round5_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round5_human;
		printf("Your score is: %d, and your total is: %d\n",round5_human,total_human);
	}
	scoresheet(total_human,total_pc,round);
	round++;
	printf("Round: 6\n======================================\n");
	if(com<user)
	{
		printf("Rolled the dice for you:\n");
		round6_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round6_human;
		printf("Your score is: %d, and your total is: %d\n",round6_human,total_human);
		printf("Rolled the dice for computer:\n");
		round6_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round6_pc=round6_pc*10;
		iround6_pc=round6_pc;
		pcheck=iround6_pc%10;
		round6_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round6_pc/=10;
		total_pc+=round6_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round6_pc,total_pc);
	}
	else if(com>user)
	{
		printf("Rolled the dice for computer:\n");
		round6_pc=play_pc(choose01,choose02,choose03,choose04,choose05,choose06);
		round6_pc=round6_pc*10;
		iround6_pc=round6_pc;
		pcheck=iround6_pc%10;
		round6_pc-=pcheck;
		switch(pcheck){
			case 1:
				choose01=1;break;
			case 2:
				choose02=1;break;
			case 3:
				choose03=1;break;
			case 4:
				choose04=1;break;
			case 5:
				choose05=1;break;
			case 6:
				choose06=1;break;
		}
		round6_pc/=10;
		total_pc+=round6_pc;
		printf("Computer score is: %.0f, and computer total is: %.0f\n",round6_pc,total_pc);
		printf("Rolled the dice for you:\n");
		round6_human=human_play(choose1,choose2,choose3,choose4,choose5,choose6);
		scanf("%c",&check);
		scanf("%c",&forenter);
		switch(check){
			case '1':
				choose1=1;break;
			case '2':
				choose2=1;break;
			case '3':
				choose3=1;break;
			case '4':
				choose4=1;break;
			case '5':
				choose5=1;break;
			case '6':
				choose6=1;break;
		}
		total_human+=round6_human;
		printf("Your score is: %d, and your total is: %d\n",round6_human,total_human);
	}
	scoresheet(total_human,total_pc,round);
	round++;
	printf("Game has finished!\n--------------------------------------\n");
	printf("Computer: %.0f\nPlayer: %d\n",total_pc,total_human);
	if(total_pc<total_human)
		printf("PLAYER WON");
	else if(total_pc>total_human)
		printf("COMPUTER WON");
	else
		printf("DRAW");

	return 0;
}
