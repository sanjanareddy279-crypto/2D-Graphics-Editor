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
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int x,int y,int width,int height)
{
    for(int j=x;j<x+width;j++)
    {
        canvas[y][j]='*';
        canvas[y+height-1][j]='*';
    }

    for(int i=y;i<y+height;i++)
    {
        canvas[i][x]='*';
        canvas[i][x+width-1]='*';
    }
}
void drawLine(int x1,int y1,int x2,int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int steps = (dx > dy) ? dx : dy;

    float xInc = (float)(x2 - x1) / steps;
    float yInc = (float)(y2 - y1) / steps;

    float x = x1;
    float y = y1;

    for(int i=0;i<=steps;i++)
    {
        if((int)x >= 0 && (int)x < COLS &&
           (int)y >= 0 && (int)y < ROWS)
        {
            canvas[(int)y][(int)x] = '*';
        }

        x += xInc;
        y += yInc;
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
    for(int angle=0; angle<360; angle++)
    {
        double rad = angle * 3.14159 / 180.0;

        int x = cx + radius * cos(rad);
        int y = cy + radius * sin(rad);

        if(x >= 0 && x < COLS &&
           y >= 0 && y < ROWS)
        {
            canvas[y][x] = '*';
        }
    }
}

int main()
{
    initializeCanvas();
    drawCircle(20,10,5);
    displayCanvas();

    return 0;
}