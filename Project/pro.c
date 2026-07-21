#include<LPC21XX.H>

#define LCD 0XFF
#define RS 1 << 8
#define E 1 << 9
#define IRS1 10
#define IRS2 11
#define MOTORON 1 << 21


void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
void DELAY_MS(unsigned int);
void DELAY_S(unsigned int);
void LCD_STR(unsigned char* );
void LCD_INT(int);



int main()
{
    short int COUNT = 0;
    short int PRODUCTS_ON_BELT = 0;

    int I = 0, J;

    static int IR1_OLD = 1;
    static int IR2_OLD = 1;

    int IR1, IR2;

    unsigned char MSG[] =
    "SMART CONVEYOR SYSTEM FOR AUTOMATIC PRODUCT DETECTION, COUNTING, AND CONVEYOR CONTROL - MADHANRAJ.B ";

    LCD_INIT();

    while(1)
    {
        LCD_COMMAND(0x80);

        for(J = 0; J < 16; J++)
        {
            if(MSG[I + J] != '\0')
                LCD_DATA(MSG[I + J]);
            else
                LCD_DATA(' ');
        }

        LCD_COMMAND(0xC0);
        LCD_STR("PRODUCTS:");
        LCD_COMMAND(0xCA);
        LCD_INT(COUNT);
        IR1 = (IOPIN0 >> IRS1) & 1;

        if(IR1_OLD == 1 && IR1 == 0)
        {
            PRODUCTS_ON_BELT++;
            IOSET0 = MOTORON;
        }

        IR1_OLD = IR1;
        IR2 = (IOPIN0 >> IRS2) & 1;

        if(IR2_OLD == 1 && IR2 == 0)
        {
            if(PRODUCTS_ON_BELT > 0)
                PRODUCTS_ON_BELT--;

            COUNT++;
        }

        IR2_OLD = IR2;
        if(PRODUCTS_ON_BELT == 0)
        {
            IOCLR0 = MOTORON;
        }
        else
        {
            IOSET0 = MOTORON;
        }
        I++;

        if(MSG[I] == '\0')
            I = 0;

        DELAY_MS(50);
    }
}


void LCD_INIT(void)
{
IODIR0 = LCD| RS | E | MOTORON ;
LCD_COMMAND(0X01);
LCD_COMMAND(0X02);
LCD_COMMAND(0X0C);
LCD_COMMAND(0X38);
}

void LCD_COMMAND(unsigned char CMD)
{
IOCLR0 = LCD;
IOSET0 = CMD;
IOCLR0 = RS;
IOSET0 = E;
DELAY_MS(2);
IOCLR0 = E;
}

void LCD_DATA(unsigned char DAT)
{
IOCLR0 = LCD;
IOSET0 = DAT;
IOSET0 = RS;
IOSET0 = E;
DELAY_MS(2);
IOCLR0 = E;
}

void DELAY_MS(unsigned int MS)
{
T0PR = 15000 - 1;
T0TCR = 0X01;
while(T0TC < MS);
T0TCR = 0X03;
T0TCR = 0X00;
}

void DELAY_S(unsigned int S)
{
T0PR = 15000000 - 1;
T0TCR = 0X01;
while(T0TC < S);
T0TCR = 0X03;
T0TCR = 0X00;
}

void LCD_STR(unsigned char* STR )
{
while(*STR)
{
LCD_DATA(*STR++);
}
}

void LCD_INT(int NUM)
{
short int i = 0;
unsigned char arr[45];
if( NUM == 0)
{
LCD_DATA('0');
}
while( NUM > 0)
{
arr[i++] = NUM % 10;
NUM /= 10;
}
for(--i; i >= 0; i--)
{
LCD_DATA(arr[i] + 48);
}

}


