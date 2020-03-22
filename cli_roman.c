#include<stdio.h>
#include<stdlib.h>

void digit_roman(int num);
int print_roman(int num);

int main(int count, char *val[]){
    if(count==1){
        while(1){
            int n;
            printf("Enter the number:\n");
            scanf("%d", &n);
            digit_roman(n);
            printf("\n");
        }
    } 
    for(int x=1; x<count; x++){
        printf("%s : ", val[x]);
        digit_roman(atoi(val[x]));
        printf("\n");
    }
    return 0;
}

void digit_roman(int num){
    if(num<=10){
        print_roman(num);
        return ;
    }
    else if(num%10==0){
        if(num<40)
            for(int i=0; i<num/10; i++)
                print_roman(10);
        else if(num<=50)
            print_roman(num);
        else if(num<90){
            print_roman(50);
            digit_roman(num-50);
        }
        else if(num<=100)
            print_roman(num);
        else if(num<400){
            for(int i=0; i<num/100; i++)
                print_roman(100);
            digit_roman(num%100);
        }
        else if(num<=500){
            print_roman(num-num%100);
            digit_roman(num%100);
        }
        else if(num<900){
            print_roman(500);
            digit_roman(num-500);
        }
		else if(num<=1000){
            print_roman(num-num%100);
            digit_roman(num%100);
        }
		else if(num<5000){
            for(int i=0; i<num/1000; i++)
                print_roman(1000);
            digit_roman(num%1000);
        }
        return ;
    }
    else{
        int inner = num%10, outer = num-inner;
        digit_roman(outer);
        print_roman(inner);
        return ;
    }
}

int print_roman(int num){
    switch(num){
        case 1: printf("I");
                break;
        case 2: printf("II");
                break;
        case 3: printf("III");
                break;
        case 4: printf("IV");
                break;
        case 5: printf("V");
                break;
        case 6: printf("VI");
                break;
        case 7: printf("VII");
                break;
        case 8: printf("VIII");
                break;
        case 9: printf("IX");
                break;
        case 10: printf("X");
                break;  
        case 40: printf("XL"); 
                break; 
        case 50: printf("L"); 
                break;
        case 90: printf("XC"); 
                break;
        case 100: printf("C"); 
                break; 
        case 400: printf("CD"); 
                break; 
        case 500: printf("D"); 
                break;  
        case 900: printf("CM"); 
                break; 
        case 1000: printf("M"); 
                break; 
    }
}