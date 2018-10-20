#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
#include<process.h>

int threesquare[]={6,7,8,11,12,13,16,17,18};

int fivesquare[]={0, 0,  0,  0,  0,
                  0, 6,  7,  8,  0,
                  0, 11, 12, 13, 0,
                  0, 16, 17, 18, 0,
                  0, 0,  0,  0,  0};

int midcorner[5]={4,0,2,6,8};
int mid=4;
int corner[4]={0,2,6,8};
int side[4]={1,3,5,7};
int cornerside[8]={0,2,6,8,1,3,5,7};

int midpointer=0;

int firstturnpointer=0;

int directionsi[4] = { 1, 4, 5, 6 };// direction for five square board

int turni;//contain integer value of turn
int stop;// count total turn made by both player
int mode=2;// to select single/double player
int player;// to select player x/o
char availturn[9];// to save the available turn for computer
int row,column;
int directions[4]={1,2,3,4};
char xo='0';
char ox='0';
int level=1;


struct board
{
    char board[33][33];

    /*char gameresultw1[44];
    char gameresultl1[44];
    char gameresultw2[44];
    char gameresultl2[44];
    char gameresultw3[44];
    char gameresultl3[44];
    char gameresultw4[44];
    char gameresultl4[44];
    char gameresultw5[44];
    char gameresultl5[44];
    int draw;*/
};
struct result
{
    char gameresultw1[44];
    char gameresultl1[44];
    char gameresultw2[44];
    char gameresultl2[44];
    char gameresultw3[44];
    char gameresultl3[44];
    char gameresultw4[44];
    char gameresultl4[44];
    char gameresultw5[44];
    char gameresultl5[44];
    char result1[44];
    char result2[44];
    char result3[44];
    char result4[44];
    char result5[44];
    char resultd[44];
    char gameresultdw[44];
    char gameresultdl[44];
} rs;


char playernamex[33];
char playernameo[33];



void singleplayer(struct board za);
void doubleplayer(struct board za);

void homepage(struct board za);
void menu1(void);
void menu2(void);
void instruction(void);

void playernamed(void);
void playernames(void);

void levelselect(void);

void gameboard(struct board za);
void resultboard(void);

void saveresult(void);

void playero(struct board za);
void playerx(struct board za);
void playerc(struct board za);
void playerc1(struct board za);
void playerc2(struct board za);
void playerc3(struct board za);
void playerc4(struct board za);


int chartointforc1(char turn);
int turncheck(struct board za);
int result(struct board za);
int availableturn(struct board za);// to check the available turn for computer
void rowcolumnhuman(int turn);
void rowcolumncomputer(char turn);


main()
{
    stop=1;
    //level=1;
    struct board ri;
    char loop;
    int a='1';
    int i,j,p;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            ri.board[i][j]=a++;
        }
    }

    homepage(ri);



    getch();





}

void homepage(struct board za)
{
    //char *confirm,yes[]="y";
    int confirm;
    int option;
    printf("\n\n\n\t\t\t1. double player\n\n\n\t\t\t2. single player\n\n\n\t\t\t3. select level\n\n\n\t\t\t4. result board\n\n\n\t\t\t5. help\n\n\n\t\t\t6. exit");
    printf("\n\n\t\t\tNote : by default level 1 is selected & back to main menu enter 99 as any kind of input\n");
    fflush(stdin);
    scanf("%d",&option);

    system("cls");
    if(option!=1&&option!=2&&option!=3&&option!=4&&option!=5&&option!=6)
    {

        homepage(za);
    }
    if(option==1)
    {
        mode=2;
        system("cls");
        doubleplayer(za);
    }
    if(option==2)
    {
       mode=1;
       system("cls");
       singleplayer(za);
    }

    if(option==3)
    {
        system("cls");
        levelselect();

        homepage(za);
    }
    if(option==4)
    {
        //printf("\n\n\n\t\t\toption 4 is not yet done\n");
        //printf("\n\n\n\n\t\t\tback to main menu press any button \n");
        resultboard();
        printf("\n\n\n\n\t\t\tback to main menu press any button \n");
        getch();
        system("cls");
        homepage(za);
    }
    if(option==5)
    {
        system("cls");
        instruction();
        system("cls");


        homepage(za);
    }
    if(option==6)
    {

        printf("\n\n\n\t\t\t1. double player\n\n\n\t\t\t2. single player\n\n\n\t\t\t3. select level\n\n\n\t\t\t4. result board\n\n\n\t\t\t5. help\n\n\n\t\t\t6. exit");
        printf("\n\n\t\t\tNote : by default level 1 is selected & back to main menu enter 99 as any kind of input\n");
        printf("\n\t\t\tare you sure to exit\n\t\t\t1. yes\n\t\t\t2. no\n");
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm==2)
        {
            system("cls");
            main();
        }
        exit(1);


    }
}

void menu1(void)
{

     printf("\n\t\t\tchose one\n\n\n\t\t\t1. single player\n\n\n\t\t\t2. double player\n");

     scanf("%d",&mode);
     if(mode==99)
    {
        system("cls");
        main();
    }
    fflush(stdin);
     if(mode!=1&&mode!=2)
    {
        system("cls");

        menu1();
    }


    system("cls");


}

void menu2(void)
{

    printf("\n\t\t\tchose player\n\n\n\t\t\t1. player x\n\n\n\t\t\t2. player o\n");
    fflush(stdin);
    scanf("%d",&player);
    if(player==99)
    {
        system("cls");
        main();
    }
    system("cls");
    if(player!=1&&player!=2)
    {
        fflush(stdin);

        menu2();
    }

    if(mode==2)playernamed();
    if(mode==1)playernames();



}

void instruction(void)
{
    printf("\n\n\n\t\t\t1.to play with computer select: level select  >  single player > player o/x \n\n\n\t\t\t2.to play with your friend select:  double player > player x/o\n\n\n\t\t\t3.result of the game will be saved by the name of the player which is taken before the game start\n\n\n\t\t\t4.result board show the result of last 10 game played in each level and in double player\n\n\n\t\t\t5.from level 1-5 the game became harder\n");
    printf("\n\n\n\n\t\t\tback to main menu press any button \n");

    getch();
}

void playernamed(void)
{
    char xox[]={'X','O'};
    if(player==1)
    {
        printf("\n\t\t\tenter player %c name\n",xox[0]);
        fflush(stdin);
        scanf("%s",playernamex);
        if(strcmp(playernamex,"99")==0)
        {
            system("cls");
            main();
        }
        printf("\n\t\t\tenter player %c name\n",xox[1]);
        fflush(stdin);
        scanf("%s",playernameo);
        if(strcmp(playernameo,"99")==0)
        {
            system("cls");
            main();
        }
    }
    if(player==2)
    {
        printf("\n\t\t\tenter player %c name\n",xox[1]);
        fflush(stdin);
        scanf("%s",playernameo);
        if(strcmp(playernameo,"99")==0)
        {
            system("cls");
            main();
        }
        printf("\n\t\t\tenter player %c name\n",xox[0]);
        fflush(stdin);
       scanf("%s",playernamex);
       if(strcmp(playernamex,"99")==0)
        {
            system("cls");
            main();
        }
    }



    system("cls");

}

void playernames(void)
{
    char xox[]={'X','O'};
    if(player==1)
    {
        printf("\n\t\t\tenter player %c name\n",xox[0]);
        fflush(stdin);
        scanf("%s",playernamex);
        if(strcmp(playernamex,"99")==0)
        {
            system("cls");
            main();
        }
        strcpy(playernameo,"computer");
    }
    if(player==2)
    {
        printf("\n\t\t\tenter player %c name\n",xox[1]);
        fflush(stdin);
        scanf("%s",playernameo);
        if(strcmp(playernameo,"99")==0)
        {
            system("cls");
            main();
        }
        strcpy(playernamex,"computer");
    }
    system("cls");

}

void levelselect(void)
{
    int check;
    printf("\n\t\t\tcurrent level=%d\n",level);
    printf("\n\t\t\tselect level 1-5\n");
    fflush(stdin);
    scanf("%d",&check);
    if(check==99)
    {
        system("cls");
        main();
    }

    if(check!=1&&check!=2&&check!=3&&check!=4&&check!=5)
    {
        system("cls");
        levelselect();
    }
    level=check;
    printf("\n\n\n\n\t\t\tback to main menu press any button \n");
    getch();
    system("cls");

}

void singleplayer(struct board za)
{

        int random;
        srand(time(NULL));
        random=(rand()%2)+1;
        menu2();
        gameboard(za);
        if(random==1)
        {
            if(level==1)playerc(za);
            if(level==2)playerc1(za);
            if(level==3)playerc2(za);
            if(level==4)playerc3(za);
            if(level==5)playerc4(za);


        }
        if(random==2)
        {
            if(player==1)
            {
                playerx(za);
            }
            if(player==2)
            {
                playero(za);
            }
        }
}

void doubleplayer(struct board za)
{
    menu2();
        gameboard(za);
        if(player==1)
            {
                playerx(za);
            }
        if(player==2)
            {
                playero(za);
            }
}

void gameboard(struct board za)
{
    int i,j=0;
    //printf("#--------------------------------------------#\n");
    printf("\t\t###############################################\n");
    //printf("|+------------------------------------------+|\n");
    for(i=0;i<3;i++)
    {
        printf("\t\t##             ##             ##             ##\n");
        printf("\t\t##             ##             ##             ##\n");
        printf("\t\t##      %c      ##      %c      ##      %c      ##\n",za.board[i][j],za.board[i][j+1],za.board[i][j+2]);
        printf("\t\t##             ##             ##             ##\n");
        printf("\t\t##             ##             ##             ##\n");
        if(i<2)
        {
            //printf("||-------------++-------------++------------||\n");
            //printf("||-------------++-------------++------------||\n");
             //printf("||#############++#############++############||\n");
              //printf("###############################################\n");
              printf("\t\t###############################################\n");


        }

    }
    //printf("|+------------------------------------------+|\n");
    printf("\t\t###############################################\n");
}
void playero(struct board za)
{
    xo='X';
    ox='O';

    int turn,c,r;
    r=result(za);
    if(r==0&&stop<10)
    {
    printf("\n\t\t%s's turn : O\n",playernameo);
    fflush(stdin);;
    scanf("%d",&turn);
    if(turn==99)
    {
        system("cls");
        main();
    }
    rowcolumnhuman(turn);
    c=turncheck(za);

       if(turn!=99)
        {
            if(c==1&&turn<10&&turn>0)
            {
                za.board[row][column]='O';
                system("cls");
                gameboard(za);

                if(stop<10)
                {
                    stop++;
                    if(mode==1)
                    {
                        if(level==1)playerc(za);
                        if(level==2)playerc1(za);
                        if(level==3)playerc2(za);
                        if(level==4)playerc3(za);
                        if(level==5)playerc4(za);

                     }
                    if(mode==2)
                    {
                        playerx(za);
                    }
                }

            }
            else
            {
                system("cls");
                gameboard(za);
                playero(za);
            }
        }

    }
    if(r==1)
    {
        int confirm;
        printf("\n\t\t\tdo you want to continue or exit\n\t\t\t1. continue\n\t\t\t2. exit\n");
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm==1)
        {
            system("cls");
            main();
        }
        exit(1);

    }


}
void playerx(struct board za)
{
    xo='O';
    ox='X';

    int turn,c,r;
    r=result(za);
    if(r==0&&stop<10)
    {
        printf("\n\t\t%s's turn : X\n",playernamex);
        fflush(stdin);
        scanf("%d",&turn);
        if(turn==99)
        {
            system("cls");
            main();
        }
        rowcolumnhuman(turn);
        c=turncheck(za);

         if(turn!=99)
            {
                if(c==1&&turn<10&&turn>0)
                {
                    za.board[row][column]='X';
                    system("cls");
                    gameboard(za);

                    if(stop<10)
                    {
                        stop++;
                        if(mode==1)
                        {
                            if(level==1)playerc(za);
                            if(level==2)playerc1(za);
                            if(level==3)playerc2(za);
                            if(level==4)playerc3(za);
                            if(level==5)playerc4(za);

                        }
                        if(mode==2)
                        {
                            playero(za);
                        }
                    }

                }
                else
                {
                    system("cls");
                    gameboard(za);
                    playerx(za);
                }
            }

    }
    if(r==1)
    {

        int confirm;
        printf("\n\t\t\tdo you want to continue or exit\n\t\t\t1. continue\n\t\t\t2. exit\n");
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm==1)
        {
            system("cls");
            main();
        }
        exit(1);
    }


}

void playerc(struct board za)
{
    char turn;
    int r,length,p;  /* r=check the result afte
    the turn of previous player , length = the size of avail turn*/
    r=result(za);
    if(r==0&&stop<10)
    {

        length=availableturn(za);
        srand(time(NULL));
        turn=availturn[(rand()%length)];/* take the turn from availableturn()*/
        rowcolumncomputer(turn);
        if(player==2)
        {
            za.board[row][column]='X';
            system("cls");
            gameboard(za);

        }
        if(player==1)
        {

            za.board[row][column]='O';
            system("cls");
            gameboard(za);
        }

        stop++;

        if(player==2)
        {
            playero(za);
        }

        if(player==1)
        {
            playerx(za);
        }

    }
    if(r==1)
    {

        int confirm;
        printf("\n\t\t\tdo you want to continue or exit\n\t\t\t1. continue\n\t\t\t2. exit\n");
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm==1)
        {
            system("cls");
            main();
        }
        exit(1);
    }
}

void playerc1(struct board za)
{

    char turn,winturn;
    int i,r,value,d,index,length,got=0,pot;  /* r=check the result afte
    the turn of previous player , length = the size of avail turn,
     pot= to keep the index value of five square board*/
    r=result(za);
    if(r==0&&stop<10)
    {


        length=availableturn(za);
        for(i=0;i<length;i++)
        {


            winturn=availturn[i];
            turn=availturn[i];
            chartointforc1(turn);
            for(index=0;index<4;index++)
            {
                value=directions[index];

                got=0;


                for(d=1;d<3;d++)
                {

                    if(d==1)
                        {
                            turn=availturn[i]+value;
                            pot=threesquare[turni]+directionsi[index];

                        }
                    if(d==2)
                        {
                            turn=availturn[i]-value;
                            pot=threesquare[turni]-directionsi[index];

                        }

                    while(fivesquare[pot]!=0)
                    {

                       rowcolumncomputer(turn);

                       if(za.board[row][column]!=xo)
                       {

                           break;
                       }
                       if(d==1)
                       {
                            turn=turn+value;
                            pot=pot+directionsi[index];
                       }
                       if(d==2)
                        {
                            turn=turn-value;
                            pot=pot-directionsi[index];

                        }

                       got++;


                    }
                    if(got==2)break;


                }

                if(got==2)break;



            }
                if(got==2)break;

        }
        turn=winturn;
        if(got!=2)
        {

            srand(time(NULL));
            turn=availturn[(rand()%length)];
        }

        rowcolumncomputer(turn);


        if(player==2)
        {
            za.board[row][column]='X';
            system("cls");
            gameboard(za);

        }
        if(player==1)
        {

            za.board[row][column]='O';
            system("cls");
            gameboard(za);
        }

        stop++;

        if(player==2)
        {
            playero(za);
        }

        if(player==1)
        {
            playerx(za);
        }

    }
    if(r==1)
    {

        int confirm;
        printf("\n\t\t\tdo you want to continue or exit\n\t\t\t1. continue\n\t\t\t2. exit\n");
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm==1)
        {
            system("cls");
            main();
        }
        exit(1);
    }
}

void playerc2(struct board za)
{

    char turn,winturn;
    int i,r,value,d,index,length,got=0,pot;  /* r=check the result afte
    the turn of previous player , length = the size of avail turn,
     pot= to keep the index value of five square board*/
    r=result(za);
    if(r==0&&stop<10)
    {


        length=availableturn(za);
        for(i=0;i<length;i++)
        {


            winturn=availturn[i];
            turn=availturn[i];
            chartointforc1(turn);
            for(index=0;index<4;index++)
            {
                value=directions[index];

                got=0;


                for(d=1;d<3;d++)
                {

                    if(d==1)
                        {
                            turn=availturn[i]+value;
                            pot=threesquare[turni]+directionsi[index];

                        }
                    if(d==2)
                        {
                            turn=availturn[i]-value;
                            pot=threesquare[turni]-directionsi[index];

                        }

                    while(fivesquare[pot]!=0)
                    {

                       rowcolumncomputer(turn);

                       if(za.board[row][column]!=xo)
                       {

                           break;
                       }
                       if(d==1)
                       {
                            turn=turn+value;
                            pot=pot+directionsi[index];
                       }
                       if(d==2)
                        {
                            turn=turn-value;
                            pot=pot-directionsi[index];

                        }

                       got++;


                    }
                    if(got==2)break;


                }

                if(got==2)break;



            }
                if(got==2)break;

        }
        turn=winturn;

        if(got!=2)
        {
            for(i=0;i<length;i++)
        {


            winturn=availturn[i];
            turn=availturn[i];
            chartointforc1(turn);
            for(index=0;index<4;index++)
            {
                value=directions[index];

                got=0;


                for(d=1;d<3;d++)
                {

                    if(d==1)
                        {
                            turn=availturn[i]+value;
                            pot=threesquare[turni]+directionsi[index];

                        }
                    if(d==2)
                        {
                            turn=availturn[i]-value;
                            pot=threesquare[turni]-directionsi[index];

                        }

                    while(fivesquare[pot]!=0)
                    {

                       rowcolumncomputer(turn);

                       if(za.board[row][column]!=ox)
                       {

                           break;
                       }
                       if(d==1)
                       {
                            turn=turn+value;
                            pot=pot+directionsi[index];
                       }
                       if(d==2)
                        {
                            turn=turn-value;
                            pot=pot-directionsi[index];

                        }

                       got++;


                    }
                    if(got==2)break;


                }

                if(got==2)break;



            }
                if(got==2)break;

        }
        turn=winturn;
        }
        if(got!=2)
        {

            srand(time(NULL));
            turn=availturn[(rand()%length)];
        }

        rowcolumncomputer(turn);


        if(player==2)
        {
            za.board[row][column]='X';
            system("cls");
            gameboard(za);

        }
        if(player==1)
        {

            za.board[row][column]='O';
            system("cls");
            gameboard(za);
        }

        stop++;

        if(player==2)
        {
            playero(za);
        }

        if(player==1)
        {
            playerx(za);
        }

    }
    if(r==1)
    {

        int confirm;
        printf("\n\t\t\tdo you want to continue or exit\n\t\t\t1. continue\n\t\t\t2. exit\n");
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm==1)
        {
            system("cls");
            main();
        }
        exit(1);
    }
}

void playerc3(struct board za)
{

    char turn,winturn;
    int i,r,value,d,index,length,got=0,pot;  /* r=check the result afte
    the turn of previous player , length = the size of avail turn,
     pot= to keep the index value of five square board*/
    r=result(za);
    if(r==0&&stop<10)
    {


        length=availableturn(za);
        for(i=0;i<length;i++)
        {


            winturn=availturn[i];
            turn=availturn[i];
            chartointforc1(turn);
            for(index=0;index<4;index++)
            {
                value=directions[index];

                got=0;


                for(d=1;d<3;d++)
                {

                    if(d==1)
                        {
                            turn=availturn[i]+value;
                            pot=threesquare[turni]+directionsi[index];

                        }
                    if(d==2)
                        {
                            turn=availturn[i]-value;
                            pot=threesquare[turni]-directionsi[index];

                        }

                    while(fivesquare[pot]!=0)
                    {

                       rowcolumncomputer(turn);

                       if(za.board[row][column]!=xo)
                       {

                           break;
                       }
                       if(d==1)
                       {
                            turn=turn+value;
                            pot=pot+directionsi[index];
                       }
                       if(d==2)
                        {
                            turn=turn-value;
                            pot=pot-directionsi[index];

                        }

                       got++;


                    }
                    if(got==2)break;


                }

                if(got==2)break;



            }
                if(got==2)break;

        }
        turn=winturn;

        if(got!=2)
        {
            for(i=0;i<length;i++)
        {


            winturn=availturn[i];
            turn=availturn[i];
            chartointforc1(turn);
            for(index=0;index<4;index++)
            {
                value=directions[index];

                got=0;


                for(d=1;d<3;d++)
                {

                    if(d==1)
                        {
                            turn=availturn[i]+value;
                            pot=threesquare[turni]+directionsi[index];

                        }
                    if(d==2)
                        {
                            turn=availturn[i]-value;
                            pot=threesquare[turni]-directionsi[index];

                        }

                    while(fivesquare[pot]!=0)
                    {

                       rowcolumncomputer(turn);

                       if(za.board[row][column]!=ox)
                       {

                           break;
                       }
                       if(d==1)
                       {
                            turn=turn+value;
                            pot=pot+directionsi[index];
                       }
                       if(d==2)
                        {
                            turn=turn-value;
                            pot=pot-directionsi[index];

                        }

                       got++;


                    }
                    if(got==2)break;


                }

                if(got==2)break;



            }
                if(got==2)break;

        }
        turn=winturn;
        }

        if(got!=2)
        {
            int midcornerkeeper[6];
            int j=0;
            for(i=0;i<6;i++)
            {
                rowcolumnhuman(midcorner[i]+1);
                if(turncheck(za)==1)
                {
                    midcornerkeeper[j++]=midcorner[i];
                }

            }
            rowcolumnhuman(midcornerkeeper[rand()%j]+1);
            turn=za.board[row][column];
            got=2;
        }
        if(got!=2)
        {
            length=availableturn(za);

            srand(time(NULL));
            turn=availturn[(rand()%length)];
        }

        rowcolumncomputer(turn);


        if(player==2)
        {
            za.board[row][column]='X';
            system("cls");
            gameboard(za);

        }
        if(player==1)
        {

            za.board[row][column]='O';
            system("cls");
            gameboard(za);
        }

        stop++;

        if(player==2)
        {
            playero(za);
        }

        if(player==1)
        {
            playerx(za);
        }

    }
    if(r==1)
    {

        int confirm;
        printf("\n\t\t\tdo you want to continue or exit\n\t\t\t1. continue\n\t\t\t2. exit\n");
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm==1)
        {
            system("cls");
            main();
        }
        exit(1);
    }
}


void playerc4(struct board za)
{

    char turn,winturn;
    int i,r,value,d,index,length,got=0,pot;  /* r=check the result afte
    the turn of previous player , length = the size of avail turn,
     pot= to keep the index value of five square board*/
    r=result(za);
    if(r==0&&stop<10)
    {


        length=availableturn(za);
        for(i=0;i<length;i++)
        {


            winturn=availturn[i];
            turn=availturn[i];
            chartointforc1(turn);
            for(index=0;index<4;index++)
            {
                value=directions[index];

                got=0;


                for(d=1;d<3;d++)
                {

                    if(d==1)
                        {
                            turn=availturn[i]+value;
                            pot=threesquare[turni]+directionsi[index];

                        }
                    if(d==2)
                        {
                            turn=availturn[i]-value;
                            pot=threesquare[turni]-directionsi[index];

                        }

                    while(fivesquare[pot]!=0)
                    {

                       rowcolumncomputer(turn);

                       if(za.board[row][column]!=xo)
                       {

                           break;
                       }
                       if(d==1)
                       {
                            turn=turn+value;
                            pot=pot+directionsi[index];
                       }
                       if(d==2)
                        {
                            turn=turn-value;
                            pot=pot-directionsi[index];

                        }

                       got++;


                    }
                    if(got==2)break;


                }

                if(got==2)break;



            }
                if(got==2)break;

        }
        turn=winturn;

        if(got!=2)
        {
            for(i=0;i<length;i++)
        {


            winturn=availturn[i];
            turn=availturn[i];
            chartointforc1(turn);
            for(index=0;index<4;index++)
            {
                value=directions[index];

                got=0;


                for(d=1;d<3;d++)
                {

                    if(d==1)
                        {
                            turn=availturn[i]+value;
                            pot=threesquare[turni]+directionsi[index];

                        }
                    if(d==2)
                        {
                            turn=availturn[i]-value;
                            pot=threesquare[turni]-directionsi[index];

                        }

                    while(fivesquare[pot]!=0)
                    {

                       rowcolumncomputer(turn);

                       if(za.board[row][column]!=ox)
                       {

                           break;
                       }
                       if(d==1)
                       {
                            turn=turn+value;
                            pot=pot+directionsi[index];
                       }
                       if(d==2)
                        {
                            turn=turn-value;
                            pot=pot-directionsi[index];

                        }

                       got++;


                    }
                    if(got==2)break;


                }

                if(got==2)break;



            }
                if(got==2)break;

        }
        turn=winturn;
        }
        int j=0;
        int cornerkeeper[4];


        if(got!=2&&stop==2)
        {
            int right;
            rowcolumnhuman(mid+1);
            if(turncheck(za)==1)
            {
                turn=za.board[row][column];
                got=2;
                midpointer=1;
            }
            else
            {

                for(i=0;i<5;i++)
                {
                    rowcolumnhuman(corner[i]+1);
                    if(turncheck(za)==1)
                    {
                        cornerkeeper[j++]=corner[i];
                    }

                }
                rowcolumnhuman(cornerkeeper[rand()%j]+1);
                turn=za.board[row][column];
                got=2;
                midpointer=2;
            }
            if(got!=2)
            {
                for(i=0;i<5;i++)
                {
                    rowcolumnhuman(corner[i]+1);
                    turn=za.board[row][column];
                    if(turncheck(za)==1)
                    {
                        got=2;
                        break;
                    }
                }
            }



        }

        int sidekeeper[4];

        if(got!=2&&midpointer==1&&stop==4)
        {
            for(i=0;i<5;i++)
            {
                rowcolumnhuman(side[i]+1);
                if(turncheck(za)==1)
                {
                    sidekeeper[j++]=side[i];
                }

            }
            rowcolumnhuman(sidekeeper[rand()%j]+1);
            turn=za.board[row][column];
            got=2;
            midpointer=0;
        }

        if(got!=2&&midpointer==2&&stop==4)
        {
            j=0;
            for(i=0;i<5;i++)
            {
                rowcolumnhuman(corner[i]+1);
                if(turncheck(za)==1)
                {
                    cornerkeeper[j++]=corner[i];
                }

            }
            rowcolumnhuman(cornerkeeper[rand()%j]+1);
            turn=za.board[row][column];
            got=2;
            midpointer=0;
        }

        if(got!=2&&stop==3)
        {
            if(firstturnpointer==1)
            {
                rowcolumnhuman(9);
                if(turncheck(za)==1)
                {
                    turn=za.board[row][column];
                    got=2;
                }
            }
            if(firstturnpointer==2)
            {
                rowcolumnhuman(7);
                if(turncheck(za)==1)
                {
                    turn=za.board[row][column];
                    got=2;
                }
            }
            if(firstturnpointer==3)
            {
                rowcolumnhuman(3);
                if(turncheck(za)==1)
                {
                    turn=za.board[row][column];
                    got=2;
                }
            }
            if(firstturnpointer==4)
            {
                rowcolumnhuman(1);
                if(turncheck(za)==1)
                {
                    turn=za.board[row][column];
                    got=2;
                }
            }
        }

        if(got!=2)
        {
            int midcornerkeeper[6];
            int j=0;
            for(i=0;i<6;i++)
            {
                rowcolumnhuman(midcorner[i]+1);
                if(turncheck(za)==1)
                {
                    midcornerkeeper[j++]=midcorner[i];
                }

            }
            rowcolumnhuman(midcornerkeeper[rand()%j]+1);
            turn=za.board[row][column];
            if(stop==1)
            {
                if(turn=='1')firstturnpointer=1;
                if(turn=='3')firstturnpointer=2;
                if(turn=='7')firstturnpointer=3;
                if(turn=='9')firstturnpointer=4;
            }

            got=2;
        }

        if(got!=2)
        {

            srand(time(NULL));
            turn=availturn[(rand()%length)];
        }

        rowcolumncomputer(turn);


        if(player==2)
        {
            za.board[row][column]='X';
            system("cls");
            gameboard(za);

        }
        if(player==1)
        {

            za.board[row][column]='O';
            system("cls");
            gameboard(za);
        }

        stop++;

        if(player==2)
        {
            playero(za);
        }

        if(player==1)
        {
            playerx(za);
        }

    }
    if(r==1)
    {


        int confirm;
        printf("\n\t\t\tdo you want to continue or exit\n\t\t\t1. continue\n\t\t\t2. exit\n");
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm==1)
        {
            system("cls");
            main();
        }

        exit(1);
    }
}


int turncheck(struct board za)
{
    if((za.board[row][column]=='O'||za.board[row][column]=='X'))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int result(struct board za)
{
    char draw[44]="draw";

    if((za.board[0][0]=='O'&&za.board[0][1]=='O'&&za.board[0][2]=='O')||(za.board[1][0]=='O'&&za.board[1][1]=='O'&&za.board[1][2]=='O')||(za.board[2][0]=='O'&&za.board[2][1]=='O'&&za.board[2][2]=='O')||(za.board[0][0]=='O'&&za.board[1][0]=='O'&&za.board[2][0]=='O')||(za.board[0][1]=='O'&&za.board[1][1]=='O'&&za.board[2][1]=='O')||(za.board[0][2]=='O'&&za.board[1][2]=='O'&&za.board[2][2]=='O')||(za.board[0][0]=='O'&&za.board[1][1]=='O'&&za.board[2][2]=='O')||(za.board[0][2]=='O'&&za.board[1][1]=='O'&&za.board[2][0]=='O'))
    {
        printf("\n\t\t\t $$$$$=%s:O win=$$$$$\n\n",playernameo);

        if(level==1&&mode==1)
        {
            strcpy(rs.gameresultw1,playernameo);
            strcpy(rs.gameresultl1,playernamex);
            strcpy(rs.result1,playernameo);
        }
        if(level==2&&mode==1)
        {
            strcpy(rs.gameresultw2,playernameo);
            strcpy(rs.gameresultl2,playernamex);
            strcpy(rs.result2,playernameo);
        }
        if(level==3&&mode==1)
        {
            strcpy(rs.gameresultw3,playernameo);
            strcpy(rs.gameresultl3,playernamex);
            strcpy(rs.result3,playernameo);
        }if(level==4&&mode==1)
        {
            strcpy(rs.gameresultw4,playernameo);
            strcpy(rs.gameresultl4,playernamex);
            strcpy(rs.result4,playernameo);
        }
        if(level==5&&mode==1)
        {
            strcpy(rs.gameresultw5,playernameo);
            strcpy(rs.gameresultl5,playernamex);
            strcpy(rs.result5,playernameo);
        }
        if(mode==2)
        {
            strcpy(rs.gameresultdw,playernameo);
            strcpy(rs.gameresultdl,playernamex);
            strcpy(rs.resultd,playernameo);
        }
        saveresult();

        return 1;
    }
    else if((za.board[0][0]=='X'&&za.board[0][1]=='X'&&za.board[0][2]=='X')||(za.board[1][0]=='X'&&za.board[1][1]=='X'&&za.board[1][2]=='X')||(za.board[2][0]=='X'&&za.board[2][1]=='X'&&za.board[2][2]=='X')||(za.board[0][0]=='X'&&za.board[1][0]=='X'&&za.board[2][0]=='X')||(za.board[0][1]=='X'&&za.board[1][1]=='X'&&za.board[2][1]=='X')||(za.board[0][2]=='X'&&za.board[1][2]=='X'&&za.board[2][2]=='X')||(za.board[0][0]=='X'&&za.board[1][1]=='X'&&za.board[2][2]=='X')||(za.board[0][2]=='X'&&za.board[1][1]=='X'&&za.board[2][0]=='X'))
    {
        printf("\n\t\t\t $$$$$=%s:X win=$$$$$\n\n",playernamex);

        if(level==1&&mode==1)
        {
            strcpy(rs.gameresultw1,playernamex);
            strcpy(rs.gameresultl1,playernameo);
            strcpy(rs.result1,playernamex);
        }
        if(level==2&&mode==1)
        {
            strcpy(rs.gameresultw2,playernamex);
            strcpy(rs.gameresultl2,playernameo);
            strcpy(rs.result2,playernamex);
        }
        if(level==3&&mode==1)
        {
            strcpy(rs.gameresultw3,playernamex);
            strcpy(rs.gameresultl3,playernameo);
            strcpy(rs.result3,playernamex);
        }if(level==4&&mode==1)
        {
            strcpy(rs.gameresultw4,playernamex);
            strcpy(rs.gameresultl4,playernameo);
            strcpy(rs.result4,playernamex);
        }
        if(level==5&&mode==1)
        {
            strcpy(rs.gameresultw5,playernamex);
            strcpy(rs.gameresultl5,playernameo);
            strcpy(rs.result5,playernamex);
        }
        if(mode==2)
        {
            strcpy(rs.gameresultdw,playernamex);
            strcpy(rs.gameresultdl,playernameo);
            strcpy(rs.resultd,playernamex);
        }
        saveresult();

        return 1;
    }
    else if(stop>9)
    {
        printf("\n\t\t\t $$$$$=match draw=$$$$$\n\n");
        if(level==1&&mode==1)
        {
            strcpy(rs.gameresultw1,playernamex);
            strcpy(rs.gameresultl1,playernameo);
            strcpy(rs.result1,draw);
        }
        if(level==2&&mode==1)
        {
            strcpy(rs.gameresultw2,playernamex);
            strcpy(rs.gameresultl2,playernameo);
            strcpy(rs.result2,draw);
        }
        if(level==3&&mode==1)
        {
            strcpy(rs.gameresultw3,playernamex);
            strcpy(rs.gameresultl3,playernameo);
            strcpy(rs.result3,draw);
        }if(level==4&&mode==1)
        {
            strcpy(rs.gameresultw4,playernamex);
            strcpy(rs.gameresultl4,playernameo);
            strcpy(rs.result4,draw);
        }
        if(level==5&&mode==1)
        {
            strcpy(rs.gameresultw5,playernamex);
            strcpy(rs.gameresultl5,playernameo);
            strcpy(rs.result5,draw);
        }
        if(mode==2)
        {
            strcpy(rs.gameresultdw,playernamex);
            strcpy(rs.gameresultdl,playernameo);
            strcpy(rs.resultd,draw);
        }


        saveresult();

        return 1;


    }
    else
    {
        return 0;
    }
}

int availableturn(struct board za)
{
    int index=0,j,i=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            {
                if((za.board[i][j]!= 'X') && (za.board[i][j]!= 'O'))
                {
                    availturn[index]=za.board[i][j];

                    index++;

                }
            }


    }
    return index;
}

void rowcolumnhuman(int turn)
{
    if(turn==1||turn==3||turn==2)
        {
            row=0;
        }
        if(turn==4||turn==5||turn==6)
        {
            row=1;
        }
        if(turn==7||turn==8||turn==9)
        {
            row=2;
        }
    if(turn==1||turn==4||turn==7)
    {
        column=0;
    }
    if(turn==2||turn==5||turn==8)
    {
        column=1;
    }
    if(turn==3||turn==6||turn==9)
    {
        column=2;
    }
}

void rowcolumncomputer(char turn)
{
    if(turn=='1'||turn=='3'||turn=='2')
    {
        row=0;
    }
    if(turn=='4'||turn=='5'||turn=='6')
    {
        row=1;
    }
    if(turn=='7'||turn=='8'||turn=='9')
    {
        row=2;
    }
    if(turn=='1'||turn=='4'||turn=='7')
    {
        column=0;
    }
    if(turn=='2'||turn=='5'||turn=='8')
    {
        column=1;
    }
    if(turn=='3'||turn=='6'||turn=='9')
    {
        column=2;
    }
}

int chartointforc1(char turn)
{
    int value,i;
    char j='1';
    for(i=0;turn!=j++;i++);
    turni=i;



}

void saveresult()
{

    FILE *ptr1,*ptr2,*ptr3,*ptr4,*ptr5,*ptrd;
    if(level==1&&mode==1)
    {
        ptr1=fopen("level1.txt","a");
        fwrite(&rs,sizeof(rs),1,ptr1);
        fclose(ptr1);
    }
    if(level==2&&mode==1)
    {
        ptr2=fopen("level2.txt","a");
        fwrite(&rs,sizeof(rs),1,ptr2);
        fclose(ptr2);
    }
    if(level==3&&mode==1)
    {
        ptr3=fopen("level3.txt","a");
        fwrite(&rs,sizeof(rs),1,ptr3);
        fclose(ptr3);
    }
    if(level==4&&mode==1)
    {
        ptr4=fopen("level4.txt","a");
        fwrite(&rs,sizeof(rs),1,ptr4);
        fclose(ptr4);
    }
    if(level==5&&mode==1)
    {
        ptr5=fopen("level5.txt","a");
        fwrite(&rs,sizeof(rs),1,ptr5);
        fclose(ptr5);
    }
    if(mode==2)
    {
        ptrd=fopen("leveld.txt","a");
        fwrite(&rs,sizeof(rs),1,ptrd);
        fclose(ptrd);
    }
}

void resultboard()
{
    int j=1;
    menu1();
    int i=1,lenth=0;
    char name1[444][44],name2[444][44],resultk[444][44];

    FILE *ptr11,*ptr21,*ptr31,*ptr41,*ptr51,*ptrd1;
    if(mode==1)
    {
        printf("\t\t\t..................level-1.................\n");
        printf("\t\t\tmatch\t\t\t\twiner/draw\n\n");
        ptr11=fopen("level1.txt","r");
        while((fread(&rs,sizeof(rs),1,ptr11)))
        {
            strcpy(name1[lenth],rs.gameresultw1);
            strcpy(name2[lenth],rs.gameresultl1);
            strcpy(resultk[lenth++],rs.result1);

        }
        fclose(ptr11);
        for(i=lenth-1;i>lenth-11&&i>-1;i--)
        {
            printf("\t\t\t%d.%s vs %-8s\t\t%s\n",j++,name1[i],name2[i],resultk[i]);
        }
        j=1;
        lenth=0;




        printf("\n\n\n\t\t\t..................level-2.................\n");
        printf("\t\t\tmatch\t\t\t\twiner/draw\n\n");

        ptr21=fopen("level2.txt","r");
        while((fread(&rs,sizeof(rs),1,ptr21)))
        {
            strcpy(name1[lenth],rs.gameresultw2);
            strcpy(name2[lenth],rs.gameresultl2);
            strcpy(resultk[lenth++],rs.result2);
        }
        fclose(ptr21);
        for(i=lenth-1;i>lenth-11&&i>-1;i--)
        {
            printf("\t\t\t%d.%s vs %-8s\t\t%s\n",j++,name1[i],name2[i],resultk[i]);
        }
        j=1;
        lenth=0;



        printf("\n\n\n\t\t\t..................level-3.................\n");
        printf("\t\t\tmatch\t\t\t\twiner/draw\n\n");
        ptr31=fopen("level3.txt","r");
        while((fread(&rs,sizeof(rs),1,ptr31)))
        {
            strcpy(name1[lenth],rs.gameresultw3);
            strcpy(name2[lenth],rs.gameresultl3);
            strcpy(resultk[lenth++],rs.result3);
        }
        fclose(ptr31);
        for(i=lenth-1;i>lenth-11&&i>-1;i--)
        {
            printf("\t\t\t%d.%s vs %-8s\t\t%s\n",j++,name1[i],name2[i],resultk[i]);
        }
        j=1;
        lenth=0;


        printf("\n\n\n\t\t\t..................level-4.................\n");
        printf("\t\t\tmatch\t\t\t\twiner/draw\n\n");
        ptr41=fopen("level4.txt","r");
        while((fread(&rs,sizeof(rs),1,ptr41)))
        {
            strcpy(name1[lenth],rs.gameresultw4);
            strcpy(name2[lenth],rs.gameresultl4);
            strcpy(resultk[lenth++],rs.result4);

        }
        fclose(ptr41);
        for(i=lenth-1;i>lenth-11&&i>-1;i--)
        {
            printf("\t\t\t%d.%s vs %-8s\t\t%s\n",j++,name1[i],name2[i],resultk[i]);
        }
        j=1;
        lenth=0;


        printf("\n\n\n\t\t\t..................level-5.................\n");
        printf("\t\t\tmatch\t\t\t\twiner/draw\n\n");
        ptr51=fopen("level5.txt","r");
        while((fread(&rs,sizeof(rs),1,ptr51)))
        {
            strcpy(name1[lenth],rs.gameresultw5);
            strcpy(name2[lenth],rs.gameresultl5);
            strcpy(resultk[lenth++],rs.result5);

        }
        fclose(ptr51);
        for(i=lenth-1;i>lenth-11&&i>-1;i--)
        {
            printf("\t\t\t%d.%s vs %-8s\t\t%s\n",j++,name1[i],name2[i],resultk[i]);
        }
        j=1;
        lenth=0;

    }
    if(mode==2)
    {
        printf("\t\t\t...............double player...............\n");
        printf("\t\t\tmatch\t\t\t\twiner/draw\n\n");
        ptrd1=fopen("leveld.txt","r");
        while((fread(&rs,sizeof(rs),1,ptrd1)))
        {
            strcpy(name1[lenth],rs.gameresultdw);
            strcpy(name2[lenth],rs.gameresultdl);
            strcpy(resultk[lenth++],rs.resultd);

        }
        fclose(ptrd1);
        for(i=lenth-1;i>lenth-11&&i>-1;i--)
        {
            printf("\t\t\t%d.%s vs %-9s\t\t%s\n",j++,name1[i],name2[i],resultk[i]);
        }
        j=1;
        lenth=0;
    }

}





