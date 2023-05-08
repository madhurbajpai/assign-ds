//Name- Madhur Bajpai
//registeration number - 2022CA047
//objective -- solving thee josephus problem
//date- 07/02/2023

#include<stdio.h>
int josephus(int n,int k ){
	if(n==0) return 1;
 	return (josephus(n-1,k)+k)%n;
}
void main(){
	printf("%d",josephus(9,3));

}



/*
		0      1     
	8			2X
				
	7			3
		6	5






*/
