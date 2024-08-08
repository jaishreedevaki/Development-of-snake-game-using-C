#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define multiplier 1103515245
#define increment 12345
#define modulo (1U << 31)
unsigned int seed;
int food_x;
int food_y;
int key;
int score=0;
int gameover;
int snake_length=1;
int ind;
typedef struct
{
	int x;
	int y;
}Positions;
Positions snake[10000];
unsigned int random_generator(int max_limit)
{
	unsigned int dum;
	dum=(multiplier*seed+increment)%modulo;
	if(dum==0)
	{
		dum=modulo;
	}
	seed=dum;
        if(dum%max_limit==0||dum%max_limit==1)
        {
    	   return 2;
	}
	else
	{
	   return dum%max_limit;	
	}
	
}
void initial_setup()
{
	food_x=random_generator(30);
	food_y=random_generator(60);
	snake[0].x=30/2;
	snake[0].y=60/2;
}
void draw_boundary()
{
	int height=30;
	int width=60;
	int height_index;
	int width_index;
	int is_snake;
	for(width_index=1;width_index<=30;width_index++)
	{
	   for(height_index=1;height_index<=60;height_index++)
	   {
	    
		   if(width_index==1)
	           {
	         	printf("_");
		   }
		   else if(width_index==30)
		   {
		   	printf("-");
		   }
		   else if(height_index==1||height_index==60)
	           {
	        	printf("|");
		   }
		   else if(width_index==food_x&&height_index==food_y)
		   {
		   	printf("*");
		   }
		   else if(snake[0].x==width_index&&snake[0].y==height_index)
		   {
		   	printf("#");
		   }
                   else 
                   {
           	        is_snake=0;
           	        for(ind=1;ind<snake_length;ind++)
           	        {
                            if(snake[ind].x==width_index&&snake[ind].y==height_index)
			     {
			    	printf("0");
			    	is_snake=1;
			    	break;
			     }	
			}
			if(!is_snake)
		    	    {
				  printf(" ");
			    }
		   }
	   }
	   printf("\n");	
	}
	printf("SCORE: %d",score);
}
void get_key()
{  
	  switch(getch())
	  {
	  	case '8':
	  		key=8;
	  		break;
	  	case '2':
	  		key=2;
	  		break;
	  	case '4':
	  		key=4;
	  		break;
	  	case '6':
	  		key=6;
	  		break;
	  	case '5':
	  		gameover=1;
	  		break;
	  }
}
void snake_movement()
{   
        Positions temp; 
	Positions prev=snake[0]; 
        for(ind=1;ind<snake_length;ind++)
        {
           temp=snake[ind];
           snake[ind]=prev;;
           prev=temp;
	}
	if(key==8)
	{
	   snake[0].x--;
	}
	else if(key==2)
	{
	   snake[0].x++;
	}
	else if(key==4)
	{
	   snake[0].y--;
	}
	else if (key==6)
	{
	   snake[0].y++;
	}
	
	if(snake[0].x<=1||snake[0].x>=30||snake[0].y<=1||snake[0].y>=60)
	{
	   gameover=1;
	}
	for(ind=1;ind<snake_length;ind++)
       	{
            if(snake[ind].x==snake[0].x&&snake[ind].y==snake[0].y)
           	     {
           	   	    gameover=1;
           	   	    break;
		     }  
        }
	if(snake[0].x==food_x&&snake[0].y==food_y)
	{
		score+=10;
		snake_length++;
		food_x=random_generator(30);
		food_y=random_generator(60);
	}

}
int main()
{    
        seed=(unsigned int)time(NULL);
        gameover=0;
	initial_setup();
	printf("WELCOME!!\n\nINSTRUCTIONS:\n\nPress 8 to move the snake up.\n\nPress 2 to move the snake down.\n\nPress 6 to move the snake right.\n\nPress 4 to move the snake left.\n\nPress 5 to exit the game.\n\n");
	printf("PRESS ENTER KEY TO CONTINUE\n");
	if((int)getch()==13)
	{
	  system("cls");
          while(!gameover)
    	  {
            draw_boundary();
            get_key();
            snake_movement();
            system("cls");
	  }
	}
	printf("GAME OVER!!!\nTOTAL SCORE:%d",score);
}
