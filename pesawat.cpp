#include <graphics.h>
#include <conio.h>
#include <windows.h>

void Bingkai() {
    setcolor(WHITE);
rectangle(10, 10, 625, 465);
}

void drawPlaneW(int x, int y) {
   setcolor(WHITE);
    // Body of the plane
    line(x - 4, y - 20, x, y - 30);
    line(x, y - 30, x + 4, y - 20);
    rectangle(x - 4, y + 20, x + 4, y - 20);
    // Wings
    line(x - 4, y - 20, x - 25, y + 20);
    line(x - 25, y + 20, x - 4, y + 17);
    
    line(x + 4, y - 20, x + 25, y + 20);
    line(x + 25, y + 20, x + 4, y + 17);
}

void FireW(int x, int y) {
    setcolor(RED);
    line(x - 4, y + 20.5, x, y + 40);
    line(x, y + 40, x + 4, y + 20.5);
}    

void drawPlaneA(int x, int y) {
    setcolor(WHITE);
    // Body of the plane
    line(x - 20, y - 4, x - 30, y);
    line(x - 30, y, x - 20, y + 4);
    rectangle(x + 20, y - 4, x- 20, y + 4);
    // Wings
    line(x - 20, y - 4, x + 20, y - 25);
    line(x + 20, y - 25, x + 17, y - 4);
    
    line(x - 20, y + 4, x + 20, y + 25);
    line(x + 20, y + 25, x + 17, y + 4);    
}

void FireA(int x, int y) {
    setcolor(RED);
    line(x + 20.5, y - 4, x + 40, y);
    line(x + 40, y, x + 20.5, y + 4);
}    

void drawPlaneD(int x, int y) {
    setcolor(WHITE);
    // Body of the plane
    line(x + 20, y - 4, x + 30, y);
    line(x + 30, y, x + 20, y + 4);
    rectangle(x - 20, y - 4, x + 20, y + 4);
    // Wings
    line(x + 20, y - 4, x - 20, y - 25);
    line(x - 20, y - 25, x - 17, y - 4);
    
    line(x + 20, y + 4, x - 20, y + 25);
    line(x - 20, y + 25, x - 17, y + 4);    
}

void FireD(int x, int y) {
    setcolor(RED);
    line(x - 20.5, y - 4, x - 40, y);
    line(x - 40, y, x - 20.5, y + 4);
}    

void drawPlaneS(int x, int y) {
    setcolor(WHITE);
    // Body of the plane
    line(x - 4, y + 20, x, y + 30);
    line(x, y + 30, x + 4, y + 20);
    rectangle(x - 4, y - 20, x + 4, y + 20);
    // Wings
    line(x - 4, y + 20, x - 25, y - 20);
    line(x - 25, y - 20, x - 4, y - 17);
    
    line(x + 4, y + 20, x + 25, y - 20);
    line(x + 25, y - 20, x + 4, y - 17);
}

void FireS(int x, int y) {
    setcolor(RED);
    line(x - 4, y - 20.5, x, y - 40);
    line(x, y - 40, x + 4, y - 20.5);
}    

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); 

    int x = 400, y = 200;
    drawPlaneW(x, y);
    Bingkai();
    bool KeyPressedW = true;
    bool KeyPressedA = true;
    bool KeyPressedD = true;
    bool KeyPressedS = true;

    while (KeyPressedA == true || KeyPressedD == true || KeyPressedS == true || KeyPressedW == true) {
        Bingkai();
        if (GetAsyncKeyState('W') & 0x8000) {
        cleardevice();
        Bingkai();
        drawPlaneW(x, y);
        delay(5);        
        FireW(x, y);
        y -= 3;
        KeyPressedW = false;
        delay(15);
        }

        else if (GetAsyncKeyState('A') & 0x8000) {
        cleardevice();
        Bingkai();
        drawPlaneA(x, y);
        delay(5);
        FireA(x, y);
        x -= 3;
        KeyPressedA = false;
        delay(15);
        }

        else if (GetAsyncKeyState('D') & 0x8000) {
        cleardevice();
        Bingkai();
        drawPlaneD(x, y);
        delay(5);
        FireD(x, y);
        x += 3;
        KeyPressedD = false;
        delay(15);
        }

        else if (GetAsyncKeyState('S') & 0x8000) {
        cleardevice();
        Bingkai();
        drawPlaneS(x, y);
        delay(5);
        FireS(x, y);
        y += 3;
        KeyPressedS = false;
        delay(15);
        }

        else if (KeyPressedW == false) {
        cleardevice();
        Bingkai();
        drawPlaneW(x, y);
        KeyPressedW = true;
        delay(100);
        }

        else if (KeyPressedA == false) {
        cleardevice();
        Bingkai();
        drawPlaneA(x, y);
        KeyPressedA = true;
        delay(100);
        }
        else if (KeyPressedD == false) {
        cleardevice();
        Bingkai();
        drawPlaneD(x, y);
        KeyPressedD = true;
        delay(100);
        }
        else if (KeyPressedS == false) {
        cleardevice();
        Bingkai();
        drawPlaneS(x, y);
        KeyPressedS = true;
        delay(100);
        }

    if (x > 590)
    {x = 590;}
    else if (x < 40)
    {x = 40;}
    if (y > 430)
    {y = 430;}
    else if (y < 40)
    {y = 40;}
    }

    getch();
    closegraph();
    return 0;
}
