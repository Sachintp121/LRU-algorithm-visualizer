#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

using namespace std;

class Teacher
{
private:
    float faceVertex[5][2] = {{-0.9, 0.0}, {-0.9, -0.1}, {-0.85, -0.18}, {-0.8, -0.1}, {-0.8, 0}};
    float hairVertex[10][2] = {{-0.9, 0.0}, {-0.9, -0.02}, {-0.92, -0.01}, {-0.92, +0.08}, {-0.9, 0.1}, {-0.8, 0.1}, {-0.78, 0.08}, {-0.78, 0.01}, {-0.8, -0.01}, {-0.8, 0.0}};
    float bodyVertex[4][2] = {{-0.95, -0.17}, {-0.95, -0.5}, {-0.75, -0.5}, {-0.75, -0.19}};

    float tieVertex[4][2] = {{-0.85, -0.18}, {-0.83, -0.4}, {-0.85, -0.47}, {-0.88, -0.4}};

    float lHandVertex[4][2] = {{-0.95, -0.2}, {-0.95, -0.3}, {-0.97, -0.4}, {-1.0, -0.4}};
    float rHandVertex[4][2] = {{-0.75, -0.2}, {-0.75, -0.28}, {-0.74, -0.4}, {-0.71, -0.4}};
    float legVertex[7][2] = {{-0.95, -0.5}, {-0.97, -1.0}, {-0.93, -1.0}, {-0.85, -0.6}, {-0.81, -1.0}, {-0.77, -1.0}, {-0.75, -0.5}};

public:
    void drawFace();
    void drawBody();
    void drwaTie();
    void drawLHand();
    void drawRHand();
    void drawLeg();
};

class Student
{
private:
    float headVertex[5][2] = {{-0.1, -0.6}, {-0.1, -0.7}, {-0.15, -0.78}, {-0.2, -0.7}, {-0.2, -0.6}};
    float hairVertex[10][2] = {{-0.2, -0.6}, {-0.2, -0.62}, {-0.22, -0.61}, {-0.22, -0.52}, {-0.2, -0.5}, {-0.1, -0.5}, {-0.08, -0.52}, {-0.08, -0.59}, {-0.1, -0.61}, {-0.1, -0.6}};
    float bodyVertex[3][2] = {{-0.153, -0.7}, {-0.2, -0.97}, {-0.09, -0.97}};

public:
    void drawHead(float z);
    void drawBody();
};

int ypos = 0, windowId;
float x = 0.0, y = 0.0, X = 1.0;

int frmcontent[3] = {0, 0, 0}, frames[3] = {0, 0, 0}, temp[3], pages[20], curpage = 0, pos[20], pgf = 0, n, i = 0;
float talk[10][2] = {{-0.35, 0.95}, {-0.3, 0.9}, {-0.3, 0.8}, {-0.2, 0.7}, {-0.35, 0.75}, {-0.65, 0.75}, {-0.7, 0.8}, {-0.7, 0.9}, {-0.65, 0.95}};
float stalk[10][2] = {{-0.35, 0.95}, {-0.3, 0.9}, {-0.3, 0.8}, {-0.2, 0.7}, {-0.35, 0.75}, {-0.45, 0.75}, {-0.5, 0.8}, {-0.5, 0.9}, {-0.45, 0.95}};
char status[9];
float diffx = 0.0, diffy = 0.0, xx = 0, yy = 0;

void background();
void drawBoard();
void disp();
void drawText(string s, float x, float y, float z);
void clrsc(float xxx, float yyy);
int lru(int pages[9], int cpg);
void boxpush(int x);
void drawframes();
void drawstatus();

void Student::drawHead(float z)
{
    int i;
    GLfloat x, y;

    glColor3f(0.4, 0.4, 1.0);
    glBegin(GL_TRIANGLES);
    for (i = 0; i < 3; i++)
    {
        x = bodyVertex[i][0];
        y = bodyVertex[i][1];
        glVertex2f(x + z, y);
    }
    glEnd();

    glColor3f(1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    for (i = 0; i < 5; i++)
    {
        x = headVertex[i][0];
        // cout<<x<<endl;
        // headVertex[i][0]=headVertex[i][0]+0.15;
        y = headVertex[i][1];
        glVertex2f(x + z, y);
    }
    glEnd();

    glLineWidth(2);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (i = 0; i < 10; i++)
    {
        x = hairVertex[i][0];
        // cout<<x<<endl;
        // headVertex[i][0]=headVertex[i][0]+0.15;
        y = hairVertex[i][1];
        glVertex2f(x + z, y);
    }
    glEnd();
}

void Teacher::drawFace()
{
    int i;
    glColor3f(1.0, 0.7, 0.5);
    glBegin(GL_POLYGON);
    for (i = 0; i < 5; i++)
    {
        glVertex2fv(faceVertex[i]);
    }
    glEnd();

    glColor3f(0.4, 0.1, 0.0);
    glBegin(GL_POLYGON);
    for (i = 0; i < 10; i++)
    {
        glVertex2fv(hairVertex[i]);
    }
    glEnd();

    glColor3f(0, 0, 0);
    glPointSize(6);
    glBegin(GL_POINTS);
    glVertex2f(-0.82, -0.06);
    glVertex2f(-0.88, -0.06);
    glEnd();
}

void Teacher::drawBody()
{
    int i;
    glColor3f(0.4, 0.4, 1.0);
    glBegin(GL_POLYGON);
    for (i = 0; i < 4; i++)
    {
        glVertex2fv(bodyVertex[i]);
    }
    glEnd();
}

void Teacher::drwaTie()
{
    int i;
    glColor3f(0.8, 0.3, 0.1);
    glBegin(GL_POLYGON);
    for (i = 0; i < 4; i++)
    {
        glVertex2fv(tieVertex[i]);
    }
    glEnd();
}

void Teacher::drawLHand()
{
    int i;
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (i = 0; i < 4; i++)
    {
        glVertex2fv(lHandVertex[i]);
    }
    glEnd();
}

void Teacher::drawRHand()
{
    int i;
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (i = 0; i < 4; i++)
    {
        glVertex2fv(rHandVertex[i]);
    }
    glEnd();
}

void Teacher::drawLeg()
{
    int i;
    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glLineWidth(1);
    for (i = 0; i < 7; i++)
    {
        glVertex2fv(legVertex[i]);
    }
    glEnd();
}

void background()
{
    glColor3f(0.9, 0.8, 0.6); // top  light back
    glBegin(GL_QUADS);
    glVertex2f(-1, 1);
    glVertex2f(-1, -0.2);
    glVertex2f(-0.8, -0.1);
    glVertex2f(-0.8, 1);
    glEnd();

    glColor3f(0.9, 0.8, 0.7); // top  light back
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 1);
    glVertex2f(-0.8, -0.1);
    glVertex2f(1, -0.1);
    glVertex2f(1, 1);
    glEnd();

    glColor3f(0.7, 0.5, 0.3); // bottom dark back
    glBegin(GL_QUADS);
    glVertex2f(-1, -0.2);
    glVertex2f(-1, -1);
    glVertex2f(-0.8, -0.8);
    glVertex2f(-0.8, -0.1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.1);
    glVertex2f(-0.8, -0.8);
    glVertex2f(1, -0.8);
    glVertex2f(1, -0.1);
    glEnd();

    glColor3f(0.7, 0.7, 0.7); // bottom dark back
    glBegin(GL_QUADS);
    glVertex2f(-1, -1);
    glVertex2f(-0.8, -0.8);
    glVertex2f(1, -0.8);
    glVertex2f(1, -1);
    glEnd();

    glColor3f(0.7, 0.7, 0.0);
    // glBegin(GL_QUADS);
    //     glVertex2f(-0.82,-0.4);
    //     glVertex2f(-0.7,-0.3);
    //     glVertex2f(-0.3,-0.3);
    //     glVertex2f(-0.42,--0.4);
    // glEnd();

    glPointSize(10); // table
    glBegin(GL_QUADS);
    glVertex2f(-0.78, -0.6);
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.4, -0.5);
    glVertex2f(-0.48, -0.6);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(-0.78, -0.6);
    glVertex2f(-0.78, -0.9);

    glVertex2f(-0.705, -0.5);
    glVertex2f(-0.705, -0.8);

    glVertex2f(-0.405, -0.5);
    glVertex2f(-0.405, -0.8);

    glVertex2f(-0.485, -0.6);
    glVertex2f(-0.485, -0.9);

    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS); // books on table
    glVertex2f(-0.6, -0.58);
    glVertex2f(-0.62, -0.55);
    glVertex2f(-0.64, -0.55);
    glVertex2f(-0.64, -0.58);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS); // notice board
    glVertex2f(-0.7, 0.7);
    glVertex2f(-0.5, 0.7);
    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.7, 0.3);
    glEnd();

    glColor3f(0.9, 0.5, 0.2);
    glLineWidth(10);
    glBegin(GL_LINES); // notice board
    glVertex2f(-0.7, 0.7);
    glVertex2f(-0.5, 0.7);
    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.7, 0.3);
    glEnd();
}

void drawBoard()
{
    glColor3f(0.5, 0.6, 0);
    glLineWidth(10);
    glBegin(GL_QUADS);
    glVertex2f(0.99, 0.99);
    glVertex2f(0.99, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.3, 0.99);
    glEnd();

    glColor3f(1.0, 0.9, 0.3);
    glLineWidth(10);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.99, 0.99);
    glVertex2f(0.99, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.3, 0.99);
    glEnd();
}

Teacher t;
Student s;

// int pages[9],n,pos[10];

void drawText(string s, float x, float y, float z)
{
    int c;
    glRasterPos3f(x, y, z);
    glColor3f(1, 0, 1);
    for (c = 0; s[c] != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[c]);
    }
}

void clrsc(float xxx, float yyy)
{
    glPushMatrix();
    glTranslatef(xxx, yyy, 0);
    // glColor3f(0.1, 0.6, 0);
    glColor3f(0.5, 0.6, 0);
    glLineWidth(10);
    glBegin(GL_QUADS); // background hide
    glVertex2f(0.8, 1.3);
    glVertex2f(0.8, 0.4);
    glVertex2f(0.15, 0.4);
    glVertex2f(0.15, 1.3);
    glEnd();

    glLineWidth(1);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 9; i++)
        glVertex2f(stalk[i][0] + 0.6, stalk[i][1] - 0.5);
    glEnd();

    char smsg[] = "YES SIR!!";
    glRasterPos2f(0.15, 0.34);
    for (i = 0; i < strlen(smsg); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, smsg[i]);

    if (strcmp(status, "HIT") == 0)
    {
        glColor3f(0.99, 0.94, 0.6);
        drawText("LEAST RECENTLY USED ALGORITHM!!", -500, 800, 0);
        glColor3f(1, 1, 1);
        drawText("THE RESULTS ARE...", 0.2, 1.1, 0);
        glColor3f(1, 1, 1);
        drawText("PAGE FAULTS:", 0.25, 0.9, 0);
        glColor3f(1, 1, 1);
        glRasterPos2f(0.5, 0.9);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pgf + '0');
        glColor3f(1, 1, 1);
        drawText("PAGE HITS:", 0.25, 0.7, 0);
        glColor3f(1, 1, 1);
        glRasterPos2f(0.5, 0.7);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (n - pgf) + '0');
        glFlush();
    }
    else
    {
        glColor3f(0.99, 0.94, 0.6);
        drawText("LEAST RECENTLY USED ALGORITHM!!", 70, 1150, 0);
        glColor3f(1, 1, 1);
        drawText("THE RESULTS ARE...", 0.2, 1.1, 0);
        glColor3f(1, 1, 1);
        drawText("PAGE FAULTS:", 0.25, 0.9, 0);
        glColor3f(1, 1, 1);
        glRasterPos2f(0.5, 0.9);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pgf + '0');
        glColor3f(1, 1, 1);
        drawText("PAGE HITS:", 0.25, 0.7, 0);
        glColor3f(1, 1, 1);
        glRasterPos2f(0.5, 0.7);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (n - pgf) + '0');
        glFlush();
    }
    glPopMatrix();
}

int lru(int pages[9], int cpg) // returns position to fill page in
{
    int m, n, position, k, l;
    int a = 0, b = 0;
    for (m = 0; m < 3; m++)
        if (frames[m] == pages[cpg]) // page hit
        {
            a = 1;
            b = 1;
            return -1;
        }
    if (a == 0) // frame empty insert
    {
        for (m = 0; m < 3; m++)
            if (frames[m] == 0)
            {
                frames[m] = pages[cpg];
                b = 1;
                pgf++;
                return m;
            }
    }
    if (b == 0) // page fault
    {
        for (m = 0; m < 3; m++)
            temp[m] = 0;
        for (k = cpg - 1, l = 1; l <= 2; l++, k--)
        {
            for (m = 0; m < 3; m++)
                if (frames[m] == pages[k])
                    temp[m] = 1;
        }
        for (m = 0; m < 3; m++)
            if (temp[m] == 0)
            {
                position = m;
                break;
            }
        frames[position] = pages[cpg];
        pgf++;
        return position;
    }
    return -1;
}

void boxpush(int x)
{
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.84, 1); // initialize box with current page
    glVertex2f(0.3, 0.6);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.4, 0.5);
    glVertex2f(0.3, 0.5);
    glEnd();
    glColor3f(0, 0, 0);
    glRasterPos2f(0.345, 0.53);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, x + '0');
    usleep(50000);
    diffy -= 0.01;
    if (pos[curpage] == 0 && diffy > -0.7) // if curpage is inserted to frame 1
    {
        strcpy(status, "FAULT");
        glutPostRedisplay(); // redisplay after each change in position
    }
    else if (pos[curpage] == 1 && diffy > -0.5) // if curpage is inserted to frame 2
    {
        strcpy(status, "FAULT");
        glutPostRedisplay();
    }
    else if (pos[curpage] == 2 && diffy > -0.3) // if curpage is inserted to frame 3
    {
        strcpy(status, "FAULT");
        glutPostRedisplay();
    }
    else if (pos[curpage] == -1 && diffx < 0.8) // if curpage is hit
    {
        usleep(50000);
        diffy = 0;
        diffx += 0.01;
        strcpy(status, "HIT");
        glutPostRedisplay();
    }
    else // move to next page
    {
        if (curpage < n - 1) // if 8th page increment and display one final time
        {
            frmcontent[pos[curpage]] = pages[curpage]; // assign curpage value to chosen frame
            curpage++;
            diffy = 0;
            diffx = 0; // reset positions
            glutPostRedisplay();
        }

        else
        {
            // clrsc();
            char msg[] = "UNDERSTOOD!!";
            int k;
            if (diffx >= 0.8)
            {
                clrsc(-0.83, -0.7);
                glColor3f(0, 0, 0);
                glRasterPos2f(-1.475, 0.13);
                for (k = 0; k < strlen(msg); k++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[k]);
                glLineWidth(1);
                glColor3f(0, 0, 0);
                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < 9; i++)
                {
                    glVertex2f(talk[i][0] - 0.85, talk[i][1] - 0.7);
                }
                glEnd();
            }

            else if (diffy >= -0.31 && diffy < -0.0)
            {
                clrsc(0, -0.43);
                // drawText("UNDERSTOOD!!", -0.6, 0.5, 0);

                glColor3f(0, 0, 0);
                glRasterPos2f(-0.6, 0.45);
                for (k = 0; k < strlen(msg); k++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[k]);

                glLineWidth(1);
                glColor3f(0, 0, 0);
                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < 9; i++)
                {
                    glVertex2f(talk[i][0], talk[i][1] - 0.4);
                }
                glEnd();
            }

            else if (diffy >= -0.52 && diffy < -0.31)
            {
                clrsc(0, -0.2);
                // drawText("UNDERSTOOD!!", -0.6, 0.6, 0);
                glColor3f(0, 0, 0);
                glRasterPos2f(-0.6, 0.63);
                for (k = 0; k < strlen(msg); k++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[k]);
                glLineWidth(1);
                glColor3f(0, 0, 0);
                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < 9; i++)
                {
                    glVertex2f(talk[i][0], talk[i][1] - 0.2);
                }
                glEnd();
            }

            else
            {
                clrsc(0, 0);
                // drawText("UNDERSTOOD!!", -0.6, 0.8, 0);
                glColor3f(0, 0, 0);
                glRasterPos2f(-0.6, 0.83);
                for (k = 0; k < strlen(msg); k++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[k]);
                glLineWidth(1);
                glColor3f(0, 0, 0);
                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < 9; i++)
                {
                    glVertex2fv(talk[i]);
                }
                glEnd();
            }
            // display result
        }
    }
}

void drawframes() // draws frames with current content
{
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.9, 0.56);
    glVertex2f(0.3, -0.1);
    glVertex2f(0.4, -0.1);
    glVertex2f(0.4, -0.2);
    glVertex2f(0.3, -0.2);
    glEnd();
    glColor3f(0, 0, 0);
    glRasterPos2f(0.34, -0.16);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, frmcontent[0] + '0');
    glColor3f(0.5, 0.9, 0.56);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.4, 0.1);
    glVertex2f(0.3, 0.1);
    glEnd();
    glColor3f(0, 0, 0);
    glRasterPos2f(0.34, 0.04);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, frmcontent[1] + '0');
    glColor3f(0.5, 0.9, 0.56);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.3, 0.3);
    glEnd();
    glColor3f(0, 0, 0);
    glRasterPos2f(0.34, 0.235);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, frmcontent[2] + '0');
}

void drawstatus() // draws status of each page
{
    glColor3f(0.99, 0.94, 0.6);
    drawText("LEAST RECENTLY USED ALGORITHM!!", 0.1, 0.7, 0);
    glColor3f(1, 1, 1);
    drawText("INPUT", 0.15, 0.5, 0);
    glColor3f(1, 1, 1);
    glRasterPos2f(380, 780);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, curpage + 1 + '0');
    drawText("FRAME 1", 0.15, 0.25, 0);
    glColor3f(1, 1, 1);
    drawText("FRAME 2", 0.15, 0.04, 0);
    glColor3f(1, 1, 1);
    drawText("FRAME 3", 0.15, -0.165, 0);
    glColor3f(1, 1, 1);
    drawText("STATUS:", 0.15, -0.3, 0);
    glColor3f(1, 1, 1);
    drawText(status, 0.3, -0.3, 0);
}

void disp()
{
    // glClearColor(0,0,0,0);
    // glClear(GL_COLOR_BUFFER_BIT);
    drawframes();
    drawstatus();
    glPushMatrix();
    glTranslatef(diffx, diffy, 0); // push box down/left
    boxpush(pages[curpage]);       // keep pushing till reach end
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1000, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFlush();
}

void Pos()
{

    if (x <= 1)
    {
        x += 0.0001;
        if (x <= 0.65)
        {
            if (ypos == 0)
            {
                y += 0.05;
                ypos = 1;
            }
            else
            {
                y -= 0.05;
                ypos = 0;
            }
            glutPostRedisplay();
        }
    }
}

void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(10);

    background();
    drawBoard();

    glPushMatrix();
    glTranslatef(x, y, 0);
    t.drawFace();
    t.drawBody();
    t.drwaTie();
    t.drawLHand();
    t.drawRHand();
    t.drawLeg();
    Pos();
    glPopMatrix();
    float c = 0;
    for (int i = 0; i < 6; i++)
    {
        s.drawHead(c);
        c = c + 0.2;
    }
    if (x > 0.65)
        disp();
    glutSwapBuffers();
    glFlush();
}

void coverDisplay()
{
    glClearColor(1, 0.8, 0.6, 0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    // setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0., 0., 1);
    drawText("SAHYADRI COLLAGE OF ENGINEERING AND MANAGEMENT", -0.48f, 0.8f, 0.0f);
    glColor3f(0.7, 0., 1.);
    drawText("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING", -0.48f, 0.6f, 0.0f);
    glColor3f(1., 0.5, 0.);
    drawText("A MINI PROJECT ON", -0.15f, 0.4f, 0.0f);
    glColor3f(1, 0, 0);
    drawText("  LRU VISUALIZER  ", -0.14f, 0.2f, 0.0f);
    glColor3f(1., 0.5, 0);
    drawText("BY:", -0.02f, 0.0f, 0.0f);
    glColor3f(0.3, 0, 0.6);
    drawText("DEEKSHITH D SHETTY                         4SF19CS054", -0.4f, -0.2f, 0.0f);
    glColor3f(0.3, 0, 0.6);
    drawText("BHAVISH A                                               4SF19CS042", -0.4f, -0.4f, 0.0f);
    glColor3f(1., 0.5, 0);
    drawText("UNDER THE GUIDANCE OF:", -0.2f, -0.6f, 0.0f);
    glColor3f(0.6, 0.2, 0.7);
    drawText("Ms.SHIJI ABRAHAM", -0.15f, -0.8f, 0.0f);
    glColor3f(0.5, 0.2, 0.2);
    glColor3f(0.2, 0.6, 0);
    drawText("PRESS ENTER TO START!!", -0.2f, -0.95, 0.0f);
    glColor3f(1., 0.5, 0);
    glFlush();
    glutSwapBuffers();
}

void key(unsigned char k, int x, int y)
{
    if (k == 'q' || k == 'Q')
        exit(0);
}

void nxtKey(unsigned char k, int x, int y)
{
    if (k == 13)
    {
        glutDestroyWindow(windowId);
        glutInitWindowPosition(10, 10);
        glutInitWindowSize(1320, 690);
        glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
        init();
        glutCreateWindow("COMPUTER GRAPHICS");
        glutDisplayFunc(display);
        glutKeyboardFunc(key);
        glutMainLoop();
    }
}

int main(int argc, char *argv[])
{
    int i;
    printf("Enter the number of pages (maximum 9):\n");
    scanf("%d", &n);
    printf("Enter the sequence of pages:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    glutInit(&argc, argv);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(1320, 690);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    init();
    glutCreateWindow("COMPUTER GRAPHICS");
    // glutFullScreen();
    glutDisplayFunc(coverDisplay);
    printf("\nPAGE NO.\tINSERTED INTO FRAME NO.\t\tFRAME STATE\n");
    for (i = 0; i < n; i++)
    {
        pos[i] = lru(pages, i);
        printf("   %d\t\t\t %d\t\t\t   %d %d %d\n", pages[i], pos[i] + 1, frames[0], frames[1], frames[2]);
    }
    glutKeyboardFunc(nxtKey);
    glutMainLoop();
}
