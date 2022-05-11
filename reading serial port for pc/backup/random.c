#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	srand(time(NULL));   
	int i = 0;
	int j,a;
	int aaa[40];
	
	for(; i < 40 ; ++i){
		int r = rand() % 2;      
		printf("%d %d\n" , i * 200 , r % 2);
	}
	
	return 0;
	
	for(; i < 40 ; ++i){
		int r = rand() % 20000;      
		aaa[i] = r;
		//printf("%d %d\n" , r , r % 2);
	}
	
	        for (i = 0; i < 40; ++i) 
        {

 

            for (j = i + 1; j < 40; ++j)

            {

 

                if (aaa[i] > aaa[j]) 

                {

 

                    a =  aaa[i];

                    aaa[i] = aaa[j];

                    aaa[j] = a;

 

                }

 

            }


        }
	
	for(i = 0; i < 40 ; ++i){
		printf("%d %d\n" , aaa[i] , aaa[i] % 2);
	}
	
}
