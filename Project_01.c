#include<stdio.h>
int main(){
	int i,j=0,p,q,r=400,x, a[4][4]={{5,8,6,9},{14,13,3,1},{2,7,15,4},{12,11,10,0}};
	printf("                                Rule of This game\n");
	printf("1.You can move only 1 step at a time by arrow key\n");
	printf("Move Up : by up arrow key\n");
	printf("Move Down : by down arrow key\n");
	printf("Move Left : by left arrow key");
	printf("Move Right arrow key\n");
	printf("2.You can move number at empty postition only\n\n");
	printf("3.For each valid move : your total number of move will decreased by 1\n");
	printf("4.Wining situation : number in a 4*4 matrix should be in order 1 to 15 \n");
	printf("                         wining situation:\n....................\n");
	for(i=1;i<=15;i++){
		if(j){
			printf("%2d ",i);
			j=1-j;
			if(i%4==0)
			printf("|\n");
		}
		else{
			i--;
			printf("| ");
			j=1-j;
		}

	}
	printf("\n....................");
	printf("\n5.You can exit the game at any time by pressing 'E'or 'e'");
	printf("\nso try to win in minimum no of move/n/n");
	printf("                 Happy gaming,Good Luck\n\n Enter any key to start.....");
	
	while(r){
	printf("Hello Aditya ,Move remaingig : %d\n",r);
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
		if(a[i][j]==0){
			p=i;
			q=j;
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
	          printf("%d ",a[i][j]);
	}
	printf("\nEnter Number you want to move");
	scanf("%d",&x);
	r--;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
		if(a[i][j]==x){
			a[p][q]=x;
			a[i][j]=0;
		}
	}
	if(p==15){
	printf("                           YOU   WIN");
	break;
}
}}}
