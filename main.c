#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j]='_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x,int y,int width,int height)
{
    for(int j=x;j<x+width;j++)
    {
        if(j<COLS)
        {
            canvas[y][j]='*';
            canvas[y+height-1][j]='*';
        }
    }

    for(int i=y;i<y+height;i++)
    {
        if(i<ROWS)
        {
            canvas[i][x]='*';
            canvas[i][x+width-1]='*';
        }
    }
}

void drawLine(int x1,int y1,int x2,int y2)
{
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);

    int steps=(dx>dy)?dx:dy;

    float xInc=(float)(x2-x1)/steps;
    float yInc=(float)(y2-y1)/steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++)
    {
        if((int)x>=0 && (int)x<COLS &&
           (int)y>=0 && (int)y<ROWS)
        {
            canvas[(int)y][(int)x]='*';
        }

        x+=xInc;
        y+=yInc;
    }
}

void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x1,y1);
}

void drawCircle(int cx,int cy,int radius)
{
    for(int angle=0;angle<360;angle++)
    {
        double rad=angle*3.14159/180.0;

        int x=cx+radius*cos(rad);
        int y=cy+radius*sin(rad);

        if(x>=0 && x<COLS &&
           y>=0 && y<ROWS)
        {
            canvas[y][x]='*';
        }
    }
}

int main()
{
    int choice;

    while(1)
    {
        initializeCanvas();

        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Circle\n");
        printf("3. Draw Line\n");
        printf("4. Draw Triangle\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x,y,width,height;

                printf("Enter x: ");
                scanf("%d",&x);

                printf("Enter y: ");
                scanf("%d",&y);

                printf("Enter width: ");
                scanf("%d",&width);

                printf("Enter height: ");
                scanf("%d",&height);

                drawRectangle(x,y,width,height);
                displayCanvas();
                break;
            }

            case 2:
            {
                int cx,cy,r;

                printf("Enter center x: ");
                scanf("%d",&cx);

                printf("Enter center y: ");
                scanf("%d",&cy);

                printf("Enter radius: ");
                scanf("%d",&r);

                drawCircle(cx,cy,r);
                displayCanvas();
                break;
            }

            case 3:
            {
                int x1,y1,x2,y2;

                printf("Enter x1: ");
                scanf("%d",&x1);

                printf("Enter y1: ");
                scanf("%d",&y1);

                printf("Enter x2: ");
                scanf("%d",&x2);

                printf("Enter y2: ");
                scanf("%d",&y2);

                drawLine(x1,y1,x2,y2);
                displayCanvas();
                break;
            }

            case 4:
            {
                int x1,y1,x2,y2,x3,y3;

                printf("Enter x1 y1: ");
                scanf("%d%d",&x1,&y1);

                printf("Enter x2 y2: ");
                scanf("%d%d",&x2,&y2);

                printf("Enter x3 y3: ");
                scanf("%d%d",&x3,&y3);

                drawTriangle(x1,y1,x2,y2,x3,y3);
                displayCanvas();
                break;
            }

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}