#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <random>

#define janelaX 600
#define janelaY 400
#define PI 3.1415926535898


float ox = 100.0f;
float verde = 100.0f;

int resgatados = 0;

float resgatado1X = -350.0f;
float resgatado2X = -350.0f;
float resgatado3X = -350.0f;
float resgatado4X = -350.0f;
float resgatado5X = -350.0f;

static float submarinoX = 0.0f;
static float submarinoY = 120.0f;
int velocidadeSubmarino = 10;
int raioLarguraSubmarino = 40;
int raioAlturaSubmarino = 10;

float posXtorpedo = 0.0f;
float posYtorpedo = 0.0f;
float velocidadeTorpedo = 50.0f;
bool atirou = false;
bool direita = true;

float torpedoVertice01[] = 
{ 
    (submarinoX - 5.0f),
    (submarinoY - 1.0f) 
};
float torpedoVertice02[] = 
{ 
    (submarinoX - 5.0f), 
    (submarinoY + 1.0f) 
};
float torpedoVertice03[] = 
{ 
    (submarinoX + 5.0f), 
    (submarinoY + 1.0f) 
};
float torpedoVertice04[] = 
{ 
    (submarinoX + 5.0f), 
    (submarinoY - 1.0f) 
};


float posXmergulhador01 = (janelaX / 2) + 30;
float posYmergulhador01 = (janelaY / 2) - 210;
int velocidadeMergulhador01 = 10;
bool nadarMergulhador01 = false;

float mergulhador01vertice01[] = { 
    (posXmergulhador01 - 10.0f), 
    (posYmergulhador01 - 5.0f) 
};
float mergulhador01vertice02[] = { 
    (posXmergulhador01 - 10.0f), 
    (posYmergulhador01 + 5.0f) 
};
float mergulhador01vertice03[] = { 
    (posXmergulhador01 + 10.0f), 
    (posYmergulhador01 + 5.0f) 
};
float mergulhador01vertice04[] = { 
    (posXmergulhador01 + 10.0f), 
    (posYmergulhador01 - 5.0f) 
};

float posXmergulhador02 = -(janelaX / 2) - 30;
float posYmergulhador02 = (janelaY / 2) - 105;
float velocidadeMergulhador02 = 10.0f;
bool nadarMergulhador02 = false;

float mergulhador02vertice01[] = { 
    (posXmergulhador02 - 10.0f), 
    (posYmergulhador02 - 5.0f) 
};
float mergulhador02vertice02[] = { 
    (posXmergulhador02 - 10.0f), 
    (posYmergulhador02 + 5.0f) 
};
float mergulhador02vertice03[] = { 
    (posXmergulhador02 + 10.0f), 
    (posYmergulhador02 + 5.0f) 
};
float mergulhador02vertice04[] = { 
    (posXmergulhador02 + 10.0f), 
    (posYmergulhador02 - 5.0f) 
};

float posXmergulhador03 = -(janelaX / 2) - 30;
float posYmergulhador03 = (janelaY / 2) - 160;
float velocidadeMergulhador03 = 10.0f;
bool nadarMergulhador03 = false;

float mergulhador03vertice01[] = { 
    (posXmergulhador03 - 10.0f), 
    (posYmergulhador03 - 5.0f) 
};
float mergulhador03vertice02[] = { 
    (posXmergulhador03 - 10.0f), 
    (posYmergulhador03 + 5.0f) 
};
float mergulhador03vertice03[] = { 
    (posXmergulhador03 + 10.0f), 
    (posYmergulhador03 + 5.0f) 
};
float mergulhador03vertice04[] = { 
    (posXmergulhador03 + 10.0f), 
    (posYmergulhador03 - 5.0f) 
};

float posXmergulhador04 = (janelaX / 2) + 30;
float posYmergulhador04 = (janelaY / 2) - 260;
int velocidadeMergulhador04 = 10;
bool nadarMergulhador04 = false;

float mergulhador04vertice01[] = { 
    (posXmergulhador04 - 10.0f), 
    (posYmergulhador04 - 5.0f) 
};
float mergulhador04vertice02[] = { 
    (posXmergulhador04 - 10.0f), 
    (posYmergulhador04 + 5.0f) 
};
float mergulhador04vertice03[] = { 
    (posXmergulhador04 + 10.0f), 
    (posYmergulhador04 + 5.0f) 
};
float mergulhador04vertice04[] = { 
    (posXmergulhador04 + 10.0f), 
    (posYmergulhador04 - 5.0f) 
};

float posXtubarao01 = -(janelaX / 2) - 10;
float posYtubarao01 = (janelaY / 2) - 105;
int velocidadeTubarao01 = 10;
bool nadarTubarao01 = false;

float tubarao01vertice01[] = { 
    (posXtubarao01 - 10.0f), 
    (posYtubarao01 - 5.0f) };
float tubarao01vertice02[] = { 
    (posXtubarao01 - 10.0f), 
    (posYtubarao01 + 5.0f) };
float tubarao01vertice03[] = { 
    (posXtubarao01 + 10.0f), 
    (posYtubarao01 + 5.0f) 
};
float tubarao01vertice04[] = { 
    (posXtubarao01 + 10.0f), 
    (posYtubarao01 - 5.0f) 
};

float posXtubarao02 = -(janelaX / 2) - 10;
float posYtubarao02 = (janelaY / 2) - 160;
float velocidadeTubarao02 = 10.0f;
bool nadarTubarao02 = false;

float tubarao02vertice01[] = { 
    (posXtubarao02 - 10.0f), 
    (posYtubarao02 - 5.0f) 
};
float tubarao02vertice02[] = { 
    (posXtubarao02 - 10.0f), 
    (posYtubarao02 + 5.0f) 
};
float tubarao02vertice03[] = { 
    (posXtubarao02 - 30.0f), 
    (posYtubarao02 + 5.0f) 
};
float tubarao02vertice04[] = { 
    (posXtubarao02 - 30.0f), 
    (posYtubarao02 - 5.0f) 
};

float posXtubarao03 = (janelaX / 2) + 30;
float posYtubarao03 = (janelaY / 2) - 210;
int velocidadeTubarao03 = 10;
bool nadarTubarao03 = false;

float tubarao03vertice01[] = { 
    (posXtubarao03 - 10.0f), 
    (posYtubarao03 - 5.0f) 
};
float tubarao03vertice02[] = { 
    (posXtubarao03 - 10.0f), 
    (posYtubarao03 + 5.0f) 
};
float tubarao03vertice03[] = { 
    (posXtubarao03 + 10.0f), 
    (posYtubarao03 + 5.0f) 
};
float tubarao03vertice04[] = { 
    (posXtubarao03 + 10.0f), 
    (posYtubarao03 - 5.0f) 
};


float posXtubarao04 = (janelaX / 2) + 30;
float posYtubarao04 = (janelaY / 2) - 260;
int velocidadeTubarao04 = 10;
bool nadarTubarao04 = false;

float tubarao04vertice01[] = { 
    (posXtubarao04 - 10.0f), 
    (posYtubarao04 - 5.0f) 
};
float tubarao04vertice02[] = { 
    (posXtubarao04 - 10.0f), 
    (posYtubarao04 + 5.0f) 
};
float tubarao04vertice03[] = { 
    (posXtubarao04 + 10.0f), 
    (posYtubarao04 + 5.0f) 
};
float tubarao04vertice04[] = { 
    (posXtubarao04 + 10.0f), 
    (posYtubarao04 - 5.0f) 
};

float posVida01 = -10.0f;
bool temVida01 = true;

float posVida02 = -40.0f;
bool temVida02 = true;

float posVida03 = -70.0f;
bool temVida03 = true;

void display();
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
void ceu();
void barraOxigenio();
void submarino();
void torpedo();
void tubarao01();
void tubarao02();
void tubarao03();
void tubarao04();
void mergulhador01();
void mergulhador02();
void mergulhador03();
void mergulhador04();
void vida01();
void vida02();
void vida03();
void resgate01();
void resgate02();
void resgate03();
void resgate04();
void resgate05();
void randomValorMergulhador01();
void animaMergulhador01(int val);
void randomValorMergulhador02();
void animaMergulhador02(int val);
void randomValorMergulhador03();
void animaMergulhador03(int val);
void randomValorMergulhador04();
void animaMergulhador04(int val);
void mudaOxigenio(int val);
void disparaTorpedo(int valor);
void randomValorTubarao01();
void animaTubarao01(int val);
void randomValorTubarao02();
void animaTubarao02(int val);
void randomValorTubarao03();
void animaTubarao03(int val);
void randomValorTubarao04();
void animaTubarao04(int val);
void mostraResgates();
void perdeVida();

void mergulhador01()
{
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(mergulhador01vertice01[0], mergulhador01vertice01[1]);
    glVertex2f(mergulhador01vertice02[0], mergulhador01vertice02[1]);
    glVertex2f(mergulhador01vertice03[0], mergulhador01vertice03[1]);
    glVertex2f(mergulhador01vertice04[0], mergulhador01vertice04[1]);
    glEnd();
}

void randomValorMergulhador01()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarMergulhador01 = true;
    }
}

void animaMergulhador01(int val)
{
    if (!nadarMergulhador01)
    {
        randomValorMergulhador01();
    }
    else
    {
        posXmergulhador01 -= velocidadeMergulhador01;

        mergulhador01vertice01[0] -= velocidadeMergulhador01;
        mergulhador01vertice02[0] -= velocidadeMergulhador01;
        mergulhador01vertice03[0] -= velocidadeMergulhador01;
        mergulhador01vertice04[0] -= velocidadeMergulhador01;

        if (
            (posXmergulhador01 >= (submarinoX - raioLarguraSubmarino)) &&
            (posXmergulhador01 <= (submarinoX + raioLarguraSubmarino)) &&
            (posYmergulhador01 >= (submarinoY - raioAlturaSubmarino)) &&
            (posYmergulhador01 <= (submarinoY + raioAlturaSubmarino))
            )
        {
            nadarMergulhador01 = false;
            posXmergulhador01 = (janelaX / 2) + 30;
            mostraResgates();
            mergulhador01vertice01[0] = (posXmergulhador01 - 10.0f);
            mergulhador01vertice02[0] = (posXmergulhador01 - 10.0f);
            mergulhador01vertice03[0] = (posXmergulhador01 + 10.0f);
            mergulhador01vertice04[0] = (posXmergulhador01 + 10.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaMergulhador01, 1);
}

void mergulhador02()
{
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(mergulhador02vertice01[0], mergulhador02vertice01[1]);
    glVertex2f(mergulhador02vertice02[0], mergulhador02vertice02[1]);
    glVertex2f(mergulhador02vertice03[0], mergulhador02vertice03[1]);
    glVertex2f(mergulhador02vertice04[0], mergulhador02vertice04[1]);
    glEnd();
}

void randomValorMergulhador02()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarMergulhador02 = true;
    }
}

void animaMergulhador02(int val)
{
    if (!nadarMergulhador02)
    {
        randomValorMergulhador02();
    }
    else
    {
        posXmergulhador02 += velocidadeMergulhador02;

        mergulhador02vertice01[0] += velocidadeMergulhador02;
        mergulhador02vertice02[0] += velocidadeMergulhador02;
        mergulhador02vertice03[0] += velocidadeMergulhador02;
        mergulhador02vertice04[0] += velocidadeMergulhador02;

        if (
            (posXmergulhador02 >= (submarinoX - raioLarguraSubmarino)) &&
            (posXmergulhador02 <= (submarinoX + raioLarguraSubmarino)) &&
            (posYmergulhador02 >= (submarinoY - raioAlturaSubmarino)) &&
            (posYmergulhador02 <= (submarinoY + raioAlturaSubmarino))
            )
        {
            nadarMergulhador02 = false;
            posXmergulhador02 = -(janelaX / 2) - 30;
            mostraResgates();

            mergulhador02vertice01[0] = (posXmergulhador02 - 10.0f);
            mergulhador02vertice02[0] = (posXmergulhador02 - 10.0f);
            mergulhador02vertice03[0] = (posXmergulhador02 + 10.0f);
            mergulhador02vertice04[0] = (posXmergulhador02 + 10.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaMergulhador02, 1);
}

void mergulhador03()
{
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(mergulhador03vertice01[0], mergulhador03vertice01[1]);
    glVertex2f(mergulhador03vertice02[0], mergulhador03vertice02[1]);
    glVertex2f(mergulhador03vertice03[0], mergulhador03vertice03[1]);
    glVertex2f(mergulhador03vertice04[0], mergulhador03vertice04[1]);
    glEnd();
}

void randomValorMergulhador03()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarMergulhador03 = true;
    }
}

void animaMergulhador03(int val)
{
    if (!nadarMergulhador03)
    {
        randomValorMergulhador03();
    }
    else
    {
        posXmergulhador03 += velocidadeMergulhador03;

        mergulhador03vertice01[0] += velocidadeMergulhador03;
        mergulhador03vertice02[0] += velocidadeMergulhador03;
        mergulhador03vertice03[0] += velocidadeMergulhador03;
        mergulhador03vertice04[0] += velocidadeMergulhador03;

        if (
            (posXmergulhador03 >= (submarinoX - raioLarguraSubmarino)) &&
            (posXmergulhador03 <= (submarinoX + raioLarguraSubmarino)) &&
            (posYmergulhador03 >= (submarinoY - raioAlturaSubmarino)) &&
            (posYmergulhador03 <= (submarinoY + raioAlturaSubmarino))
            )
        {
            nadarMergulhador03 = false;
            posXmergulhador03 = -(janelaX / 2) - 30;
            mostraResgates();

            mergulhador03vertice01[0] = (posXmergulhador03 - 10.0f);
            mergulhador03vertice02[0] = (posXmergulhador03 - 10.0f);
            mergulhador03vertice03[0] = (posXmergulhador03 + 10.0f);
            mergulhador03vertice04[0] = (posXmergulhador03 + 10.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaMergulhador03, 1);
}

void mergulhador04()
{
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(mergulhador04vertice01[0], mergulhador04vertice01[1]);
    glVertex2f(mergulhador04vertice02[0], mergulhador04vertice02[1]);
    glVertex2f(mergulhador04vertice03[0], mergulhador04vertice03[1]);
    glVertex2f(mergulhador04vertice04[0], mergulhador04vertice04[1]);
    glEnd();
}

void randomValorMergulhador04()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarMergulhador04 = true;
    }
}

void animaMergulhador04(int val)
{
    if (!nadarMergulhador04)
    {
        randomValorMergulhador04();
    }
    else
    {
        posXmergulhador04 -= velocidadeMergulhador04;

        mergulhador04vertice01[0] -= velocidadeMergulhador04;
        mergulhador04vertice02[0] -= velocidadeMergulhador04;
        mergulhador04vertice03[0] -= velocidadeMergulhador04;
        mergulhador04vertice04[0] -= velocidadeMergulhador04;

        if (
            (posXmergulhador04 >= (submarinoX - raioLarguraSubmarino)) &&
            (posXmergulhador04 <= (submarinoX + raioLarguraSubmarino)) &&
            (posYmergulhador04 >= (submarinoY - raioAlturaSubmarino)) &&
            (posYmergulhador04 <= (submarinoY + raioAlturaSubmarino))
            )
        {
            nadarMergulhador04 = false;
            posXmergulhador04 = (janelaX / 2) + 30;
            mostraResgates();

            mergulhador04vertice01[0] = (posXmergulhador04 - 10.0f);
            mergulhador04vertice02[0] = (posXmergulhador04 - 10.0f);
            mergulhador04vertice03[0] = (posXmergulhador04 + 10.0f);
            mergulhador04vertice04[0] = (posXmergulhador04 + 10.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaMergulhador04, 1);
}

void barraOxigenio()
{

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-100.0f, -150.0f);
    glVertex2f(-100.0f, -140.0f);
    glVertex2f(ox, -140.0f);
    glVertex2f(ox, -150.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(verde, -150.0f);
    glVertex2f(verde, -140.0f);
    glVertex2f(100.0f, -140.0f);
    glVertex2f(100.0f, -150.0f);
    glEnd();
}

void mudaOxigenio(int val)
{
    if (ox > -100.0f && submarinoY < 120.0f)
    {
        ox -= 1.0f;
        verde -= 1.0f;
    }
    else
    {
        if (ox < 100.0f && submarinoY >= 120.0f)
        {
            ox += 2.0f;
            verde += 2.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, mudaOxigenio, 1);
}

void resgate01()
{
    glTranslatef(resgatado1X, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void resgate02()
{
    glTranslatef(resgatado2X, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void resgate03()
{
    glTranslatef(resgatado3X, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void resgate04()
{
    glTranslatef(resgatado4X, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void resgate05()
{
    glTranslatef(resgatado5X, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void mostraResgates()
{
    resgatados++;

    switch (resgatados)
    {
    case 1:
        resgatado1X = 60.0f;
        break;

    case 2:
        resgatado2X = 30.0f;
        break;

    case 3:
        resgatado3X = 0.0f;
        break;

    case 4:
        resgatado4X = -30.0f;
        break;

    case 5:
        resgatado5X = -60.0f;
        break;

    default:
        break;
    }
}

void submarino()
{
    GLfloat circ_pnt = 100;
    GLfloat ang;

    glTranslatef(submarinoX, submarinoY, 0);

    circ_pnt = 100;

    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++)
    {
        glColor3f(0.0, 1.0, 0.0);
        ang = (2 * PI * i) / circ_pnt;
        glVertex2f(cos(ang) * raioLarguraSubmarino, sin(ang) * raioAlturaSubmarino);
    }
    glEnd();
}

void torpedo()
{
    glTranslatef(posXtorpedo, posYtorpedo, 0);

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(torpedoVertice01[0], torpedoVertice01[1]);
    glVertex2f(torpedoVertice02[0], torpedoVertice02[1]);
    glVertex2f(torpedoVertice03[0], torpedoVertice03[1]);
    glVertex2f(torpedoVertice04[0], torpedoVertice04[1]);
    glEnd();
}

void disparaTorpedo(int valor)
{
    if (atirou)
    {
        if (direita)
        {
            posXtorpedo += velocidadeTorpedo;

            torpedoVertice01[0] += velocidadeTorpedo;
            torpedoVertice02[0] += velocidadeTorpedo;
            torpedoVertice03[0] += velocidadeTorpedo;
            torpedoVertice04[0] += velocidadeTorpedo;

            if (posXtorpedo > janelaX / 2)
            {
                atirou = false;
                posXtorpedo = 0.0f;

                torpedoVertice01[0] = (submarinoX - 5.0f);
                torpedoVertice02[0] = (submarinoX - 5.0f);
                torpedoVertice03[0] = (submarinoX + 5.0f);
                torpedoVertice04[0] = (submarinoX + 5.0f);
            }
        }
        else
        {
            posXtorpedo -= velocidadeTorpedo;

            torpedoVertice01[0] -= velocidadeTorpedo;
            torpedoVertice02[0] -= velocidadeTorpedo;
            torpedoVertice03[0] -= velocidadeTorpedo;
            torpedoVertice04[0] -= velocidadeTorpedo;

            if (posXtorpedo < -(janelaX) / 2)
            {
                atirou = false;
                posXtorpedo = 0.0f;

                torpedoVertice01[0] = (submarinoX - 5.0f);
                torpedoVertice02[0] = (submarinoX - 5.0f);
                torpedoVertice03[0] = (submarinoX + 5.0f);
                torpedoVertice04[0] = (submarinoX + 5.0f);
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, disparaTorpedo, 0);
}

void tubarao01()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(tubarao01vertice01[0], tubarao01vertice01[1]);
    glVertex2f(tubarao01vertice02[0], tubarao01vertice02[1]);
    glVertex2f(tubarao01vertice03[0], tubarao01vertice03[1]);
    glVertex2f(tubarao01vertice04[0], tubarao01vertice04[1]);
    glEnd();
}

void randomValorTubarao01()
{
    int valor = rand() % 11;

    if (valor == 1)
    {
        nadarTubarao01 = true;
    }
}

void animaTubarao01(int val)
{
    if (!nadarTubarao01)
    {
        randomValorTubarao01();
    }
    else
    {
        posXtubarao01 += velocidadeTubarao01;

        tubarao01vertice01[0] += velocidadeTubarao01;
        tubarao01vertice02[0] += velocidadeTubarao01;
        tubarao01vertice03[0] += velocidadeTubarao01;
        tubarao01vertice04[0] += velocidadeTubarao01;

        if (posXtubarao01 > ((janelaX / 2) + 10) ||
            (
                (
                    (
                        torpedoVertice01[0] <= tubarao01vertice03[0] &&
                        torpedoVertice01[0] >= tubarao01vertice02[0] &&
                        torpedoVertice01[1] <= tubarao01vertice03[1] &&
                        torpedoVertice01[1] >= tubarao01vertice04[1]
                        ) ||
                    (
                        torpedoVertice02[0] <= tubarao01vertice04[0] &&
                        torpedoVertice02[0] >= tubarao01vertice01[0] &&
                        torpedoVertice02[1] >= tubarao01vertice04[1] &&
                        torpedoVertice02[1] <= tubarao01vertice03[1]
                        ) ||
                    (
                        torpedoVertice03[0] >= tubarao01vertice01[0] &&
                        torpedoVertice03[0] <= tubarao01vertice04[0] &&
                        torpedoVertice03[1] >= tubarao01vertice01[1] &&
                        torpedoVertice03[1] <= tubarao01vertice02[1]
                        ) ||
                    (
                        torpedoVertice04[0] >= tubarao01vertice02[0] &&
                        torpedoVertice04[0] <= tubarao01vertice03[0] &&
                        torpedoVertice04[1] <= tubarao01vertice02[1] &&
                        torpedoVertice04[1] >= tubarao01vertice01[1]
                        )
                    )
                )
            )
        {
            nadarTubarao01 = false;
            posXtubarao01 = -(janelaX / 2) - 10;

            tubarao01vertice01[0] = (posXtubarao01 - 10.0f);
            tubarao01vertice02[0] = (posXtubarao01 - 10.0f);
            tubarao01vertice03[0] = (posXtubarao01 + 10.0f);
            tubarao01vertice04[0] = (posXtubarao01 + 10.0f);
        }

        if (
            (posXtubarao01 >= (submarinoX - raioLarguraSubmarino)) &&
            (posXtubarao01 <= (submarinoX + raioLarguraSubmarino)) &&
            (posYtubarao01 >= (submarinoY - raioAlturaSubmarino)) &&
            (posYtubarao01 <= (submarinoY + raioAlturaSubmarino))
            )
        {
            submarinoX = 0.0f;
            submarinoY = 120.0f;
            ox = 100.0f;
            verde = 100.0f;
            perdeVida();

            torpedoVertice01[0] = (submarinoX - 5.0f);
            torpedoVertice01[1] = (submarinoY - 1.0f);
            torpedoVertice02[0] = (submarinoX - 5.0f);
            torpedoVertice02[1] = (submarinoY + 1.0f);
            torpedoVertice03[0] = (submarinoX + 5.0f);
            torpedoVertice03[1] = (submarinoY + 1.0f);
            torpedoVertice04[0] = (submarinoX + 5.0f);
            torpedoVertice04[1] = (submarinoY - 1.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaTubarao01, 0);
}

void tubarao02()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(tubarao02vertice01[0], tubarao02vertice01[1]);
    glVertex2f(tubarao02vertice02[0], tubarao02vertice02[1]);
    glVertex2f(tubarao02vertice03[0], tubarao02vertice03[1]);
    glVertex2f(tubarao02vertice04[0], tubarao02vertice04[1]);
    glEnd();
}

void randomValorTubarao02()
{
    int valor = rand() % 11;

    if (valor == 2)
    {
        nadarTubarao02 = true;
    }
}

void animaTubarao02(int val)
{
    if (!nadarTubarao02)
    {
        randomValorTubarao02();
    }
    else
    {
        posXtubarao02 += velocidadeTubarao02;

        tubarao02vertice01[0] += velocidadeTubarao02;
        tubarao02vertice02[0] += velocidadeTubarao02;
        tubarao02vertice03[0] += velocidadeTubarao02;
        tubarao02vertice04[0] += velocidadeTubarao02;

        if (posXtubarao02 > ((janelaX / 2) + 10) ||
            (
                (
                    (
                        torpedoVertice01[0] <= tubarao02vertice03[0] &&
                        torpedoVertice01[0] >= tubarao02vertice02[0] &&
                        torpedoVertice01[1] <= tubarao02vertice03[1] &&
                        torpedoVertice01[1] >= tubarao02vertice04[1]
                        ) ||
                    (
                        torpedoVertice02[0] <= tubarao02vertice04[0] &&
                        torpedoVertice02[0] >= tubarao02vertice01[0] &&
                        torpedoVertice02[1] >= tubarao02vertice04[1] &&
                        torpedoVertice02[1] <= tubarao02vertice03[1]
                        ) ||
                    (
                        torpedoVertice03[0] >= tubarao02vertice01[0] &&
                        torpedoVertice03[0] <= tubarao02vertice04[0] &&
                        torpedoVertice03[1] >= tubarao02vertice01[1] &&
                        torpedoVertice03[1] <= tubarao02vertice02[1]
                        ) ||
                    (
                        torpedoVertice04[0] >= tubarao02vertice02[0] &&
                        torpedoVertice04[0] <= tubarao02vertice03[0] &&
                        torpedoVertice04[1] <= tubarao02vertice02[1] &&
                        torpedoVertice04[1] >= tubarao02vertice01[1]
                        )
                    )
                )
            )
        {
            nadarTubarao01 = false;
            posXtubarao02 = -(janelaX / 2) - 10;

            tubarao02vertice01[0] = (posXtubarao02 - 10.0f);
            tubarao02vertice02[0] = (posXtubarao02 - 10.0f);
            tubarao02vertice03[0] = (posXtubarao02 + 10.0f);
            tubarao02vertice04[0] = (posXtubarao02 + 10.0f);
        }

        if (
            (posXtubarao02 >= (submarinoX - raioLarguraSubmarino)) &&
            (posXtubarao02 <= (submarinoX + raioLarguraSubmarino)) &&
            (posYtubarao02 >= (submarinoY - raioAlturaSubmarino)) &&
            (posYtubarao02 <= (submarinoY + raioAlturaSubmarino))
            )
        {
            submarinoX = 0.0f;
            submarinoY = 120.0f;
            ox = 100.0f;
            verde = 100.0;
            perdeVida();

            torpedoVertice01[0] = (submarinoX - 5.0f);
            torpedoVertice01[1] = (submarinoY - 1.0f);
            torpedoVertice02[0] = (submarinoX - 5.0f);
            torpedoVertice02[1] = (submarinoY + 1.0f);
            torpedoVertice03[0] = (submarinoX + 5.0f);
            torpedoVertice03[1] = (submarinoY + 1.0f);
            torpedoVertice04[0] = (submarinoX + 5.0f);
            torpedoVertice04[1] = (submarinoY - 1.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaTubarao02, 1);
}

void tubarao03()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(tubarao03vertice01[0], tubarao03vertice01[1]);
    glVertex2f(tubarao03vertice02[0], tubarao03vertice02[1]);
    glVertex2f(tubarao03vertice03[0], tubarao03vertice03[1]);
    glVertex2f(tubarao03vertice04[0], tubarao03vertice04[1]);
    glEnd();
}

void randomValorTubarao03()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarTubarao03 = true;
    }
}

void animaTubarao03(int val)
{
    if (!nadarTubarao03)
    {
        randomValorTubarao03();
    }
    else
    {
        posXtubarao03 -= velocidadeTubarao03;

        tubarao03vertice01[0] -= velocidadeTubarao03;
        tubarao03vertice02[0] -= velocidadeTubarao03;
        tubarao03vertice03[0] -= velocidadeTubarao03;
        tubarao03vertice04[0] -= velocidadeTubarao03;

        if (posXtubarao03 < (-(janelaX / 2) - 10) ||
            (
                (
                    (
                        torpedoVertice01[0] <= tubarao03vertice03[0] &&
                        torpedoVertice01[0] >= tubarao03vertice02[0] &&
                        torpedoVertice01[1] <= tubarao03vertice03[1] &&
                        torpedoVertice01[1] >= tubarao03vertice04[1]
                        ) ||
                    (
                        torpedoVertice02[0] <= tubarao03vertice04[0] &&
                        torpedoVertice02[0] >= tubarao03vertice01[0] &&
                        torpedoVertice02[1] >= tubarao03vertice04[1] &&
                        torpedoVertice02[1] <= tubarao03vertice03[1]
                        ) ||
                    (
                        torpedoVertice03[0] >= tubarao03vertice01[0] &&
                        torpedoVertice03[0] <= tubarao03vertice04[0] &&
                        torpedoVertice03[1] >= tubarao03vertice01[1] &&
                        torpedoVertice03[1] <= tubarao03vertice02[1]
                        ) ||
                    (
                        torpedoVertice04[0] >= tubarao03vertice02[0] &&
                        torpedoVertice04[0] <= tubarao03vertice03[0] &&
                        torpedoVertice04[1] <= tubarao03vertice02[1] &&
                        torpedoVertice04[1] >= tubarao03vertice01[1]
                        )
                    )
                )
            )
        {
            nadarTubarao01 = false;
            posXtubarao03 = (janelaX / 2) + 30;

            tubarao03vertice01[0] = (posXtubarao03 - 10.0f);
            tubarao03vertice02[0] = (posXtubarao03 - 10.0f);
            tubarao03vertice03[0] = (posXtubarao03 + 10.0f);
            tubarao03vertice04[0] = (posXtubarao03 + 10.0f);
        }

        if (
            (posXtubarao03 >= (submarinoX - raioLarguraSubmarino)) &&
            (posXtubarao03 <= (submarinoX + raioLarguraSubmarino)) &&
            (posYtubarao03 >= (submarinoY - raioAlturaSubmarino)) &&
            (posYtubarao03 <= (submarinoY + raioAlturaSubmarino))
            )
        {
            submarinoX = 0.0f;
            submarinoY = 120.0f;
            ox = 100.0f;
            verde = 100.0;
            perdeVida();

            torpedoVertice01[0] = (submarinoX - 5.0f);
            torpedoVertice01[1] = (submarinoY - 1.0f);
            torpedoVertice02[0] = (submarinoX - 5.0f);
            torpedoVertice02[1] = (submarinoY + 1.0f);
            torpedoVertice03[0] = (submarinoX + 5.0f);
            torpedoVertice03[1] = (submarinoY + 1.0f);
            torpedoVertice04[0] = (submarinoX + 5.0f);
            torpedoVertice04[1] = (submarinoY - 1.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaTubarao03, 1);
}

void tubarao04()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(tubarao04vertice01[0], tubarao04vertice01[1]);
    glVertex2f(tubarao04vertice02[0], tubarao04vertice02[1]);
    glVertex2f(tubarao04vertice03[0], tubarao04vertice03[1]);
    glVertex2f(tubarao04vertice04[0], tubarao04vertice04[1]);
    glEnd();
}

void randomValorTubarao04()
{
    int valor = rand() % 11;

    if (valor == 4)
    {
        nadarTubarao04 = true;
    }
}

void animaTubarao04(int val)
{
    if (!nadarTubarao04)
    {
        randomValorTubarao04();
    }
    else
    {
        posXtubarao04 -= velocidadeTubarao04;

        tubarao04vertice01[0] -= velocidadeTubarao04;
        tubarao04vertice02[0] -= velocidadeTubarao04;
        tubarao04vertice03[0] -= velocidadeTubarao04;
        tubarao04vertice04[0] -= velocidadeTubarao04;

        if (posXtubarao04 < (-(janelaX / 2) - 10) ||
            (
                (
                    (
                        torpedoVertice01[0] <= tubarao04vertice03[0] &&
                        torpedoVertice01[0] >= tubarao04vertice02[0] &&
                        torpedoVertice01[1] <= tubarao04vertice03[1] &&
                        torpedoVertice01[1] >= tubarao04vertice04[1]
                        ) ||
                    (
                        torpedoVertice02[0] <= tubarao04vertice04[0] &&
                        torpedoVertice02[0] >= tubarao04vertice01[0] &&
                        torpedoVertice02[1] >= tubarao04vertice04[1] &&
                        torpedoVertice02[1] <= tubarao04vertice03[1]
                        ) ||
                    (
                        torpedoVertice03[0] >= tubarao04vertice01[0] &&
                        torpedoVertice03[0] <= tubarao04vertice04[0] &&
                        torpedoVertice03[1] >= tubarao04vertice01[1] &&
                        torpedoVertice03[1] <= tubarao04vertice02[1]
                        ) ||
                    (
                        torpedoVertice04[0] >= tubarao04vertice02[0] &&
                        torpedoVertice04[0] <= tubarao04vertice03[0] &&
                        torpedoVertice04[1] <= tubarao04vertice02[1] &&
                        torpedoVertice04[1] >= tubarao04vertice01[1]
                        )
                    )
                )
            )
        {
            nadarTubarao01 = false;
            posXtubarao04 = (janelaX / 2) + 30;

            tubarao04vertice01[0] = (posXtubarao04 - 10.0f);
            tubarao04vertice02[0] = (posXtubarao04 - 10.0f);
            tubarao04vertice03[0] = (posXtubarao04 + 10.0f);
            tubarao04vertice04[0] = (posXtubarao04 + 10.0f);
        }

        if (
            (posXtubarao04 >= (submarinoX - raioLarguraSubmarino)) &&
            (posXtubarao04 <= (submarinoX + raioLarguraSubmarino)) &&
            (posYtubarao04 >= (submarinoY - raioAlturaSubmarino)) &&
            (posYtubarao04 <= (submarinoY + raioAlturaSubmarino))
            )
        {
            submarinoX = 0.0f;
            submarinoY = 120.0f;
            ox = 100.0f;
            verde = 100.0;
            perdeVida();

            torpedoVertice01[0] = (submarinoX - 5.0f);
            torpedoVertice01[1] = (submarinoY - 1.0f);
            torpedoVertice02[0] = (submarinoX - 5.0f);
            torpedoVertice02[1] = (submarinoY + 1.0f);
            torpedoVertice03[0] = (submarinoX + 5.0f);
            torpedoVertice03[1] = (submarinoY + 1.0f);
            torpedoVertice04[0] = (submarinoX + 5.0f);
            torpedoVertice04[1] = (submarinoY - 1.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaTubarao04, 1);
}

void vida01()
{
    glTranslatef(posVida01, 170.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void vida02()
{
    glTranslatef(posVida02, 170.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void vida03()
{
    glTranslatef(posVida03, 170.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void perdeVida()
{
    if (temVida01)
    {
        posVida01 = 350.0f;
        temVida01 = false;
    }
    else if (temVida02)
    {
        posVida02 = 350;
        temVida02 = false;
    }
    else
    {
        posVida03 = 350;
        temVida03 = false;
    }
}


void ceu()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-300.0f, 200.0f);
    glVertex2f(300.0f, 200.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(300.0f, 120.0f);
    glVertex2f(-300.0f, 120.0f);
    glEnd();
}

void desenhar()
{
    glPushMatrix();

    ceu();
    barraOxigenio();

    glPopMatrix();
    glPushMatrix();

    submarino();

    glPopMatrix();
    glPushMatrix();

    torpedo();

    glPopMatrix();
    glPushMatrix();

    tubarao01();
    tubarao02();
    tubarao03();
    tubarao04();

    mergulhador01();
    mergulhador02();
    mergulhador03();
    mergulhador04();

    vida01();

    glPopMatrix();
    glPushMatrix();

    vida02();

    glPopMatrix();
    glPushMatrix();

    vida03();

    glPopMatrix();
    glPushMatrix();

    resgate01();

    glPopMatrix();
    glPushMatrix();

    resgate02();

    glPopMatrix();
    glPushMatrix();

    resgate03();

    glPopMatrix();
    glPushMatrix();

    resgate04();

    glPopMatrix();
    glPushMatrix();

    resgate05();

    if (!temVida03 || ox <= -100.0f)
    {
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    if (resgatados == 5)
    {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0, 0.0, 1.0, 1.0);

    glClear(GL_COLOR_BUFFER_BIT);

    glTranslatef(janelaX / 2, janelaY / 2, 0.0f);

    glViewport(0, 0, janelaX, janelaY);

    desenhar();

    glFlush();
}

void tela(GLsizei w, GLsizei h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, janelaX, 0, janelaY);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case '1':

        direita = true;

        if (submarinoX < ((janelaX / 2) - raioLarguraSubmarino))
        {
            submarinoX += velocidadeSubmarino;

            torpedoVertice01[0] += velocidadeSubmarino;
            torpedoVertice02[0] += velocidadeSubmarino;
            torpedoVertice03[0] += velocidadeSubmarino;
            torpedoVertice04[0] += velocidadeSubmarino;
        }
        else
        {
            submarinoX += 0;
        }
        break;

    case '2':

        direita = false;

        if (submarinoX > (-(janelaX / 2) + raioLarguraSubmarino))
        {
            submarinoX -= velocidadeSubmarino;

            torpedoVertice01[0] -= velocidadeSubmarino;
            torpedoVertice02[0] -= velocidadeSubmarino;
            torpedoVertice03[0] -= velocidadeSubmarino;
            torpedoVertice04[0] -= velocidadeSubmarino;
        }
        else
        {
            submarinoX -= 0;
        }
        break;

    case '3':
        if (submarinoY < 120)
        {
            submarinoY += velocidadeSubmarino;

            torpedoVertice01[1] += velocidadeSubmarino;
            torpedoVertice02[1] += velocidadeSubmarino;
            torpedoVertice03[1] += velocidadeSubmarino;
            torpedoVertice04[1] += velocidadeSubmarino;
        }
        else
        {
            submarinoY += 0;
        }
        break;

    case '4':
        if (submarinoY > (-120 + raioAlturaSubmarino))
        {
            submarinoY -= velocidadeSubmarino;

            torpedoVertice01[1] -= velocidadeSubmarino;
            torpedoVertice02[1] -= velocidadeSubmarino;
            torpedoVertice03[1] -= velocidadeSubmarino;
            torpedoVertice04[1] -= velocidadeSubmarino;
        }
        else
        {
            submarinoY -= 0;
        }
        break;

    case '5':
        if (!atirou)
        {
            atirou = true;
        }
        break;

    default:
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(janelaX, janelaY);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Seaquest");

    glutKeyboardFunc(&keyboard);
    glutReshapeFunc(tela);
    glutDisplayFunc(display);
    glutTimerFunc(150, mudaOxigenio, 1);
    glutTimerFunc(30, disparaTorpedo, 0);
    glutTimerFunc(150, animaTubarao01, 0);
    glutTimerFunc(150, animaTubarao02, 1);
    glutTimerFunc(150, animaTubarao03, 1);
    glutTimerFunc(150, animaTubarao04, 1);
    glutTimerFunc(150, animaMergulhador01, 1);
    glutTimerFunc(150, animaMergulhador02, 1);
    glutTimerFunc(150, animaMergulhador03, 1);
    glutTimerFunc(150, animaMergulhador04, 1);
    glutMainLoop();

    return 0;
}