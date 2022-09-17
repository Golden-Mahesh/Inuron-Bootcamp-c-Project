#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void game_with_SmartComputer(int help[][3],char Tic[][3]);
int HumanTurn(int help[][3],char Tic[][3]);
int ComputerTurn(int help[][3],char Tic[][3]);
int Drow_game(char [][3]);
int Winner(char [][3]);
int play_game(char[][3]);
int Menu();
void pattern(char [][3]);
void game_with_player(char[][3]);
int  play_with_SmartComputer(int[][3],char[][3]);
void game_with_EvailComputer(int[][3],char[][3]);
int play_game_With_EvailComputer(int help[][3],char Tic[][3]);
int EvailComputerTurn(int help[][3],char Tic[][3]);
int main(){
	int choice;
	char Tic[3][3];
	int help[3][3];
	while(1){
	switch(Menu()){
            case  1: 	game_with_SmartComputer(help,Tic);
                        break;
            case  3:	game_with_player(Tic);
                        break;
            case  2:    game_with_EvailComputer(help,Tic);
                        break;
            case 4 : exit(0);
}
getch();
}
}
void game_with_SmartComputer(int help[][3],char Tic[][3]){
	int i,j;
	char k='1';
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		Tic[i][j]=k;
		k++;
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		help[i][j]=2;
	}
	play_game_With_SmartComputer(help,Tic);

}
int play_game_With_SmartComputer(int help[][3],char Tic[][3]){
	int turn=1,i,j;
	while (1){
	if(turn){
		HumanTurn(help,Tic);
	/*	printf("Array\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++)
			printf("%d ",help[i][j]);
		}
		getch();*/
			if(Winner(Tic)){
				pattern(Tic);
				printf("\n\n Congratulatin YOU WON\n\n");
				printf("####################################################################");
				return(1);
			}
		if(Drow_game(Tic)){
			printf("\n\n Drow Game \n");
		return(1);
		}
		turn=1-turn;
	}
	else{
	        	ComputerTurn(help,Tic);
	       	/*printf("Array\n");
	        			for(i=0;i<3;i++){
			for(j=0;j<3;j++)
			printf("%d ",help[i][j]);
	}
		getch();*/
					if(Winner(Tic)){
				pattern(Tic);
			    printf("\n\n Computer WON\n\n");
				printf("###########################################################################");
				return(0);
			}
	    if(Drow_game(Tic)){
	    	printf("\nDrow Game\n");
		return(1);
		}
		turn=1-turn;
	}
 }
}
int HumanTurn(int help[][3],char Tic[][3]){
	int Marking_place;
	pattern(Tic);
			printf("\n\nPlayer 1 ,Enter Marking Place :");
			scanf("%d",&Marking_place);
						int i ,j,k=1;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(k==Marking_place)
					goto l1;
					k++;
				}
			}
			l1:Tic[i][j]='X';
			help[i][j]=1;
			pattern(Tic);
		return(0);
}
int ComputerTurn(int help[][3],char Tic[][3]){
			int i ,j,place,k,multi_1=1,position=0;
			//printf("\n\n player 2 : Computer Turn   :  ");
			srand(time(NULL));
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(help[i][j]==3)
			goto l1;
		}
	}
	if(i==3){
	l3 : place=rand()%9;
		k=-1;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				k++;
				if(k==place)
				goto l2;
			}
	    }
	    l2:if(help[i][j]==1||help[i][j]==3)
	    goto l3;
	    else{
	    	//printf("                   place= %d ,  i=%d ,j=%d , k= %d : Ist",place,i,j,k);
	    	//getch();
	    	help[i][j]=3;
	    	Tic[i][j]='O';
	    	return(0);
		}
	}

	l1:   for(i=0;i<3;i++){
  	if(help[i][i]!=1&&help[i][i]!=3){
  		help[i][i]=3;
  		multi_1=1;
  		for(k=0;k<3;k++){
  		//help[i][i]=3;
  			multi_1=multi_1*help[k][k];
		  }
		  if(multi_1==27){
		  	Tic[i][i]='O';
		  	return(0);
		  }
		  else if(multi_1==3){
		  	Tic[i][i]='O';
		  	return(0);
		  }
		  else{
		  help[i][i]=2;
		 // printf("  Check first digonal ");
		 // getch();
		  }
	  }
  }
  for(i=0;i<3;i++){
  	if(help[i][2-i]!=1&&help[i][2-i]!=3){
  		help[i][2-i]=3;
  		multi_1=1;
  		for(k=0;k<3;k++){
  			//help[i][2-i]=3;
  			multi_1=multi_1*help[k][2-k];
		  }
		  if(multi_1==27){
		  	Tic[i][2-i]='O';
		  	return(0);
		  }
		  else if(multi_1==3){
		  	Tic[i][2-i]='O';
		  	return(0);
		  }
		  else{
		  help[i][2-i]=2;
		  //printf("  Check sencond digonal  ");
		 // getch();
		  }
	  }
  }
	
	 for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		if(help[i][j]!=1&&help[i][j]!=3){
			multi_1=1;
			help[i][j]=3;
			for(k=0;k<3;k++){
				//help[i][j]=3;
				multi_1=multi_1*help[i][k];
			}
			if(multi_1==27){
				Tic[i][j]='O';
				return(0);
			}
			else if(multi_1==3){
				if(position==0){
				position=multi_1;
				goto check_column;
				}
			final:	Tic[i][j]='O';
				return(0);
			}
			else {
			help[i][j]=2;
		//	printf("         \n  check row \n");
		//	getch();
			}
		}
	}
}  
  check_column:{
   for(i=0;i<3;i++){
  	for(j=0;j<3;j++){
  		if(help[i][j]!=1&&help[i][j]!=3){
  			multi_1=1;
  			help[i][j]=3;
  			for(k=0;k<3;k++){
  				//help[i][j]=3;
  		    multi_1=multi_1*help[k][j];		
			  }
			  if(multi_1==27){
			  	Tic[i][j]='O';
			  	return(0);
			  }
			  else if(multi_1==3){
			  	Tic[i][j]='O';
			  	return(0);
			  }
			  else {
			  help[i][j]=2;
		//	  printf("        Check column");
		//	  getch();
			  }
		  }
	  }
  }
}
  if(position==3){
  	goto final;
  }

	//     by default kisi pr bhi value assign nhi hui then :
		A3:	place=rand()%9;
		k=-1;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				k++;
				if(k==place)
				goto A2;
			}
	    }
	    A2:if(help[i][j]==1||help[i][j]==3)
	    goto A3;
	    else{
	    //	printf("                    %d  k=%d: 2nd ",place,k);
	    //	getch();
	    	help[i][j]=3;
	    	Tic[i][j]='O';
	    	return(0);
		}
	}
void game_with_player(char Tic[][3]){
	pattern(Tic);
		if(play_game(Tic)){
		pattern(Tic);
		printf("\nGame Drow");
	}
}
void pattern(char Tic[][3]){
	int i,j;
	system("cls");
	printf("\n\n");
	printf("############################### Tic Tac Toe ###################################\n\n");
	printf("1st Player X\n2nd Player O\n\n");
	for(i=0;i<3;i++){
		printf("\t|\t |\n");
		for(j=0;j<3;j++){
				printf("   %c    |",Tic[i][j]);
		}
		printf("\n");
			printf("________|________|________\n");
	}
			printf("\n\n");
	printf("################################################################################");
}
int Menu(){
	int choice;
	system("cls");
	printf("\n1.WANT TO PLAY WITH SMART COMPUTER\n");
	printf("2.WANT TO PLAY WITH EVAIL COMPUTER\n");
	printf("3.WANT TO PLAY WITH PLAYER\n");
	printf("4.EXIT \n\n");
	printf("ENTER YOUR CHOICE");
	scanf("%d",&choice);
	return(choice);
}
int play_game(char Tic[][3]){
		int flag=1,Marking_place;
	int i,j;
	char k='1';
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		Tic[i][j]=k;
		k++;
		}
	}
	while(1){
		if(flag==1){
			printf("\n\nPlayer 1 - Enter Marking Place :");
			scanf("%d",&Marking_place);
			int i ,j,k=1;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(k==Marking_place)
					goto l1;
					k++;
				}
			}
			l1:Tic[i][j]='X';
			pattern(Tic);
			if(Winner(Tic)){
				pattern(Tic);
				printf("\n\nPlayer 1 WON\n\n");
				printf("##################################################################");
				return(0);
			}
			flag=1-flag;
		}
		else{
			printf("\n\nPlayer  2 - Enter Marking Place : ");
			scanf("%d",&Marking_place);
				int i ,j,k=1;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(k==Marking_place)
					goto l2;
					k++;
				}
			}
				l2:Tic[i][j]='O';
			pattern(Tic);
			if(Winner(Tic)){
				pattern(Tic);
				printf("\n\nPlayer 2 Won \n\n");
				printf("########################################################################");
				return(0);
				
			}
			flag=1-flag;
		}
		if(Drow_game(Tic))
		return(1);
	}
}
int Winner(char Tic[][3]){
	int i ,j;
	for(i=0;i<3;i++){
		if(Tic[i][0]==Tic[i][1]&&Tic[i][1]==Tic[i][2])
		return(1);
	}
	for(i=0;i<3;i++){
		if(Tic[0][i]==Tic[1][i]&&Tic[1][i]==Tic[2][i])
		return(1);
	}
	if(Tic[0][0]==Tic[1][1]&&Tic[1][1]==Tic[2][2]||Tic[0][2]==Tic[1][1]&&Tic[1][1]==Tic[2][0])
	return(1);
	return(0);
}
int Drow_game(char Tic[][3]){
		int count_1=0,count_2=0,i,j;
       for(i=0;i<3;i++){
       	for(j=0;j<3;j++){
       		if(Tic[i][j]=='X')
       		count_1++;
       		if(Tic[i][j]=='O')
		   count_2++;
		   }
	   }
	if(count_1==5||count_2==5)
	return(1);
	else
	return(0);
}
    //               Game   with    Evail     Computer                   //
    void game_with_EvailComputer(int help[][3],char Tic[][3]){
	int i,j;
	char k='1';
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		Tic[i][j]=k;
		k++;
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		help[i][j]=2;
	}
	play_game_With_EvailComputer(help,Tic);

}
int play_game_With_EvailComputer(int help[][3],char Tic[][3]){
	int turn=1,i,j;
	while (1){
	if(turn){
		HumanTurn(help,Tic);
		/*printf("Array\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++)
			printf("%d ",help[i][j]);
		}
		getch();*/
			if(Winner(Tic)){
				pattern(Tic);
				printf("\n\n Congratulatin YOU WON\n\n");
				printf("####################################################################");
				return(1);
			}
		if(Drow_game(Tic)){
			printf("\n\n Drow Game \n");
		return(1);
		}
		turn=1-turn;
	}
	else{
	        	EvailComputerTurn(help,Tic);
	      /* 	printf("Array\n");
	        			for(i=0;i<3;i++){
			for(j=0;j<3;j++)
			printf("%d ",help[i][j]);
	}
		getch();*/
					if(Winner(Tic)){
				pattern(Tic);
			    printf("\n\n Computer WON\n\n");
				printf("##############################################################################");
				return(0);
			}
	    if(Drow_game(Tic)){
	    	printf("\nDrow Game\n");
		return(1);
		}
		turn=1-turn;
	}
 }
}
int EvailComputerTurn(int help[][3],char Tic[][3]){
			int i ,j,place,k,multi_1=1,position=0;
		//	printf("\n\n player 2 : Computer Turn   :  ");
			srand(time(NULL));
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(help[i][j]==3)
			goto l1;
		}
	}
	if(i==3){
	l3 : place=rand()%9;
		k=-1;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				k++;
				if(k==place)
				goto l2;
			}
	    }
	    l2:if(help[i][j]==1||help[i][j]==3)
	    goto l3;
	    else{
	    //	printf("                   place= %d ,  i=%d ,j=%d , k= %d : Ist",place,i,j,k);
	    //	getch();
	    	help[i][j]=3;
	    	Tic[i][j]='O';
	    	return(0);
		}
	}

	l1:   position=0;   
         	for(i=0;i<3;i++){
  	       if(help[i][i]!=1&&help[i][i]!=3){
  		   help[i][i]=3;
  		    multi_1=1;
  		       for(k=0;k<3;k++){
  		//help[i][i]=3;
  			multi_1=multi_1*help[k][k];
		  }
		  if(multi_1==27&&position==0){
		  	Tic[i][i]='O';
		  	return(0);
		  }
		  else if(multi_1==3){
		  	Tic[i][i]='O';
		  	position++;
		  }
		  else{
		  help[i][i]=2;
		//  printf("  Check first digonal ");
		//  getch();
		  }
	  }
  }
  for(i=0;i<3;i++){
  	if(help[i][2-i]!=1&&help[i][2-i]!=3){
  		help[i][2-i]=3;
  		multi_1=1;
  		for(k=0;k<3;k++){
  			//help[i][2-i]=3;
  			multi_1=multi_1*help[k][2-k];
		  }
		  if(multi_1==27&&position==0){
		  	Tic[i][2-i]='O';
		  	return(0);
		  }
		  else if(multi_1==3){
		  	Tic[i][2-i]='O';
		  	position++;
		  }
		  else{
		  help[i][2-i]=2;
		//  printf("  Check sencond digonal  ");
		//  getch();
		  }
	  }
  }
	
	 for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		if(help[i][j]!=1&&help[i][j]!=3){
			multi_1=1;
			help[i][j]=3;
			for(k=0;k<3;k++){
				//help[i][j]=3;
				multi_1=multi_1*help[i][k];
			}
			if(multi_1==27&&position==0){
				Tic[i][j]='O';
				return(0);
			}
			else if(multi_1==3){
				Tic[i][j]='O';
				position++;
			}
			else {
			help[i][j]=2;
		//	printf("         \n  check row \n");
		//	getch();
			}
		}
	}
}  
  
  for(i=0;i<3;i++){
  	for(j=0;j<3;j++){
  		if(help[i][j]!=1&&help[i][j]!=3){
  			multi_1=1;
  			help[i][j]=3;
  			for(k=0;k<3;k++){
  				//help[i][j]=3;
  		    multi_1=multi_1*help[k][j];		
			  }
			  if(multi_1==27&&position==0){
			  	Tic[i][j]='O';
			  	return(0);
			  }
			  else if(multi_1==3){
			  	Tic[i][j]='O';
			  	position++;
			  }
			  else {
			  help[i][j]=2;
		//	  printf("        Check column");
		//	  getch();
			  }
		  }
	  }
  }

	//     by default kisi pr bhi value assign nhi hui then :
	if(position==0){
		A3:	place=rand()%9;
		k=-1;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				k++;
				if(k==place)
				goto A2;
			}
	    }
	    A2:if(help[i][j]==1||help[i][j]==3)
	    goto A3;
	    else{
	    //	printf("                    %d  k=%d: 2nd ",place,k);
	    //	getch();
	    	help[i][j]=3;
	    	Tic[i][j]='O';
	    	return(0);
		}
	}
}
