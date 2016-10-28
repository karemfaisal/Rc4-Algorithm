#include<stdio.h> /* To Let Standard Functions Work */
#include<stdlib.h> /* To Let System Function Work */
#include<string.h> /* To Let Strlen Function Works */
#include<math.h> /* To let Log2 Function Works */

/* Rc4 Algoritm Coded by Karem Ali */
/* _____________________________________ */

/* Function to Convert Ascii To Binary and Store every Digit in a Var Then Xor The Inputs  */
/* Coded by Karem Ali */

int AsciiToBinary (char A , char B)
{
    int binary[8]; /* Save every Digit in Var */
    int binary_B[8]; /* Save every Digit in Var */
    int x ,i , l;
    /* For Char A */
    x=A;
    for(i=7;i>=0;i--)
    {
   l=log2(x);
if (i==l){   /* Calculate 1s & 0s */
    binary[i]=1;
 x-=pow(2,i);
}
    else
        binary[i]=0;
    }
    /* For Char B */
     x=B;
    for(i=7;i>=0;i--)
    {
   l=log2(x);
if (i==l){   /* Calculate 1s & 0s */
    binary[i]=1;
 x-=pow(2,i);
}
    else
        binary_B[i]=0;
    }

   for(i=7;i>=0;i--)
   {
    x = binary[i] + binary_B[i] ;
    x = x % 2 ;
 printf("%d",x);
 if(i==4)
    printf(" ");
   }
   printf(" ");
}

 main()
{
    int s[256]; /* The S Array * The Main Part of KSA in Rc4 */
    int i , j , key_length , input_Length ,t , c ,s_j , s_i;   /* Variables Helping in The Algorithm */
    char key[96];  /* The Secret Key */
    char input[10000]; /* The Plain-Text in Enc. & and The Cipher-Text in Dec.*/
    char key_stream[10000]; /* The Key generated form Rc4 */
    printf("\t\t Rc4 Algorithm");

    printf("Insert The Text \n");
    gets(input);
    rewind(stdin); /* to Cancle buffering Not in Rc4 but it is related to how C programming Works */

    printf("insert Key * Less That 12 Character\n");
    gets(key);
    rewind(stdin);

    key_length = strlen(key);    /* Measure The Length of The Secret Key */
    input_Length = strlen(input); /* Measure The Length of The Input-Text */

    if(key_length > 12){      /* The Key Length is 12 Character as Maximum */
        printf("Key Have to be Less Than 12\n");
        printf("Insert Key\n");
        gets(key);
    }
        /* KSA Key Scheduling Algorithm */
        for(i=0;i<256;i++)
        {
            s[i]=i;
        }
        j=0;
        for(i=0;i<256;i++)
        {
            j=(j+s[i]+key[i % key_length] ) % 256 ;
            s[j] = s[i];

        }
        /* PRNG Psuedo-Random Number generation */
        i=0;
        j=0;
        t=input_Length;  /* The Key Stream Length */  /* Don't Eliminate The First 256 Byte of The PRNG */

        for(c=0;c<t;c++) /* Don't Eliminate The First 256 Byte of The PRNG */
        {
            i=(i+1) % 256; /* remainder will work fine here because we are dealing with Positive Numbers */
            j=(j+s[i]) % 256;
            s_j=s[j];
            s_i=s[i];
            s[j]=s_i;
            s[i]=s_j;
            key_stream[c]= (s[(s[i]+s[j])] )%256;
        }
        printf("Cipher-Text is : \n");
        /* Printing The Output-Text */
 for(c=0;c<t;c++)
        {
            AsciiToBinary(input[c], key_stream[c]);
        }
return 0 ;
}
