#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Ahmet Turan Bulut 2315174
struct player{
    char name[30];
    int g;
    int a;
    int rc;
    int ps;
    int psr;
};
// I create a temporary array of structure for first read from the file then
// I copy that array to my main statistic_table.
//progress is first i count lines for malloc the temp and i read file then i copy to main array
int Load_statistics_Table(char input_name[81],struct player **statistics_table){
    FILE *input;
    char ch,c,surname[30];
    int lines=1,i,a;
    input=fopen(input_name,"r");
    ch=fgetc(input);
    while(ch!=EOF){
        ch=fgetc(input);
        if(ch=='\n')
            lines++;
    }
    fseek(input,0L,SEEK_SET);
    /*
    statistics_table=(struct player *)malloc(lines*sizeof(struct player));
    for(a=0;a<lines;a++){
        c=fgetc(input);
        i=0;
        while(c!=','){
            statistics_table[a].name[i]=c;
            c=fgetc(input);
            i++;
        }
        while(c!='\n'){
                if(a==lines-1)
                    break;
            c=fgetc(input);
        }
    }
    fseek(input,0L,SEEK_SET);
    for(a=0;a<lines;a++){
        fscanf(input,"%d",&statistics_table[a].g);
        fscanf(input,"%d",&statistics_table[a].a);
        fscanf(input,"%d",&statistics_table[a].rc);
        fscanf(input,"%d",&statistics_table[a].ps);
        printf("%s %d %d %d %d\n",statistics_table[a].name,statistics_table[a].g,statistics_table[a].a,statistics_table[a].rc,statistics_table[a].ps);
    }
    */
    struct player *temp;
    temp = malloc(sizeof(struct player)*lines);
    for(i=0;i<lines;i++)
    {
        fscanf(input,"%s",&temp[i].name);
        strcat(&temp[i].name," ");
        fscanf(input,"%s",surname);
        strcat(&temp[i].name,surname);
        fscanf(input,"%d",&temp[i].g);
        fscanf(input,"%d",&temp[i].a);
        fscanf(input,"%d",&temp[i].rc);
        fscanf(input,"%d",&temp[i].ps);
        temp[i].psr = 100*(temp[i].ps)/20;
    }

	*statistics_table = temp;
	fclose(input);
    return lines;
}
//Displays the table
void Display_Statistics_Table(int lines,struct player *statistics_table){
    printf("%30s %7s %7s %7s %7s %7s\n\n","Name","G","A","RC","PS","PSR");
    int i;
    for(i=0;i<lines;i++)
        printf("%30s %7d %7d %7d %7d %7d\n",statistics_table[i].name,statistics_table[i].g,statistics_table[i].a,statistics_table[i].rc,statistics_table[i].ps,statistics_table[i].psr);

}
//read who didn't take red card
void No_red_card(int lines,struct player *statistics_table){
    int i;
    for(i=0;i<lines;i++)
    {
        if(statistics_table[i].rc == 0)
            printf("%s does not have any Red Cards!\n",statistics_table[i].name);
    }

}
//first i set first player to highest one then i check other after that i print who is the highest scorer
void Player_with_Highest_Goal(int lines,struct player *statistics_table){
    int i,max,line;
    max=statistics_table[0].g;
    line=0;
    for(i=1;i<lines;i++){
        if(statistics_table[i].g>max){
            line=i;
            max=statistics_table[i].g;
        }
    }
    printf("%s is score highest goal in this event!!\n",statistics_table[line].name);

}
//i take here surname with gets because i take choose with scanf in the main after i connect them i look if if that
//scorer is exist in my list or not
void Search(char choose[20],int lines,struct player *statistics_table){
    int i,pos=-1;
    char surname[20];
    gets(surname);
    strcat(choose,surname);
    for(i=0;i<lines;i++){
        if(strcmp(choose,statistics_table[i].name)==0)
            pos=i;
    }
    if(pos>=0)
        printf("%s has %d goal, %d assist, %d red card, %d successful pass.\n",statistics_table[pos].name,statistics_table[pos].g,statistics_table[pos].a,statistics_table[pos].rc,statistics_table[pos].ps);
    else
        printf("Couldn't find a player: %s\n",choose);
}
//i store statistics with external statistics
void Storing_statistics(char output_name[20],int lines,struct player *statistics_table){
    int i;
    FILE *output;
    output=fopen(output_name,"w");
    fprintf(output,"%30s %7s %7s %7s %7s\n\n","Name","G","A","RC","PS");
    for(i=0;i<lines;i++)
        fprintf(output,"%30s %7d %7d %7d %7d\n",statistics_table[i].name,statistics_table[i].g,statistics_table[i].a,statistics_table[i].rc,statistics_table[i].ps);
    fclose(output);

}
//firstly i take input file and check then for the output file and check
//after these progrom shows the table and the menu for user decide what to do
int main(int argc,char *argv[])
{
    int i,check=0,lines;
    char input_name[81],c,output_name[81],choose[21];
    FILE *output;
    struct player *statistics_table;
    printf("Enter name of a file for input of name .txt format\nInput:");
    while(check==0){
        scanf("%s",input_name);
        for(i=0;i<81;i++){
            if(input_name[i]=='.'){
                if(input_name[i+1]=='t'&&input_name[i+2]=='x'&&input_name[i+3]=='t'&&input_name[i+4]=='\0')
                    check=1;
            }
        }
    }
    check=0;
    printf("Enter name of a file output of name .txt format\nOutput:");
    while(check==0){
        scanf("%s",output_name);
        for(i=0;i<81;i++){
            if(output_name[i]=='.'){
                if(output_name[i+1]=='t'&&output_name[i+2]=='x'&&output_name[i+3]=='t'&&output_name[i+4]=='\0')
                    check=1;
            }
        }
        output=fopen(output_name,"w");
        if(output==NULL){
            printf("the file not exist or you enter wrong type try again!\nOutput:");
            check=0;
        }
        else
            printf("file exist\n");

    }
    lines=Load_statistics_Table(input_name,&statistics_table);
    Display_Statistics_Table(lines,statistics_table);
    choose[0]='a';
    fflush(stdin);
    while(choose!='X'|| choose!='x'){
        printf("Enter the name of the player (Exit - X, No Red Card - NR, Player with Highest Goal - G): ");
        scanf("%s",choose);
        if(strcmp("NR",choose)==0||strcmp("Nr",choose)==0||strcmp("nr",choose)==0||strcmp("nR",choose)==0)
            No_red_card(lines,statistics_table);
        else if(strcmp("g",choose)==0||strcmp("G",choose)==0)
            Player_with_Highest_Goal(lines,statistics_table);
        else if(choose!='X'|| choose!='x')
            break;
        else
            Search(choose,lines,statistics_table);
    }
    Storing_statistics(output_name,lines,statistics_table);





    return 0;
}
