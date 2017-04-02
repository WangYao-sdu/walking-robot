#include<windows.h>  
#include<gl/glut.h>  
#pragma comment(lib, "glut32.lib")  
#include <iostream>  
using namespace std;

GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat no_shininess[] = { 0.5 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

static float yy = 0.0;
static int angle = 0, lshoulder = 0, lelbow = 0, rshoulder = 0, relbow = 0,
lhips = 0, rhips = 0, lfoot = 0, rfoot = 0, flagneck = 0, flaglshoulder = 0,
flaglelbow = 0, flagrshoulder = 0, flagrelbow = 0, flaglhips = 0,
flagrhips = 0, flaglfoot = 0, flagrfoot = 0;

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void draw_head(void)
{
	glPushMatrix();
	glTranslatef(0, 3.5, yy);
	glTranslatef(0, 1, 0);
	glutSolidCube(2);
	glPopMatrix();
}

void draw_body(void)
{
	glPushMatrix();
	glTranslatef(0, 1.5, yy);
	glScalef(0.5, 1, 0.4);
	glutSolidCube(4);

	glPopMatrix();
}

void draw_leftshoulder(void)
{
	glPushMatrix();
	glTranslatef(1.5, 3, yy);
	glRotatef(lshoulder, 1, 0, 0);
	//glPopMatrix();
	glTranslatef(0, -0.5, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);
	//glPushMatrix();
	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lelbow, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_rightshoulder(void)
{
	glPushMatrix();
	glTranslatef(-1.5, 3, yy);
	glRotatef(rshoulder, 1, 0, 0);

	glTranslatef(0, -0.5, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(relbow, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_leftfoot(void)
{
	glPushMatrix();
	glTranslatef(-0.6, -0.6, yy);
	glRotatef(lfoot, 1, 0, 0);
	glTranslatef(0, -1, 0);
	//缩放
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);
	
	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lhips, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);
	
	glScalef(0.4, 1, 0.5);
	
	glScalef(1, 1, 1);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_rightfoot(void)
{
	glPushMatrix();
	glTranslatef(0.6, -0.6, yy);
	glRotatef(rfoot, 1, 0, 0);
	glTranslatef(0, -1, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);
	
	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(rhips, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);
	
	glScalef(0.4, 1, 0.5);
	
	glScalef(1, 1, 1);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glRotatef(angle, 0, 1, 0);

	glTranslatef(0, 4, 0);
	draw_body();

	draw_head();

	draw_leftshoulder();
	draw_rightshoulder();

	draw_leftfoot();
	draw_rightfoot();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-8, 8, -8, 8, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 4.0, 5, 0.0, 4, 0.0, 0.0, 1.0, 0.0);

}
/*
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '0':
		angle = (angle + 5) % 360;
		glutPostRedisplay();
		break;
	case '1':
		angle = (angle - 5) % 360;
		glutPostRedisplay();
		break;
	case '2':
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -180)flaglshoulder = 1;
		}
		glutPostRedisplay(); 
		break;
	case '3':
		if (flagrshoulder)
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 0;
		}
		else
		{
			rshoulder -= 5;
			if (rshoulder <= -180)flagrshoulder = 1;
		}
		glutPostRedisplay();
		break;
	case '4':
		if (flaglelbow)
		{
			lelbow += 5;
			if (lelbow >= 0)flaglelbow = 0;
		}
		else
		{
			lelbow -= 5;
			if (lelbow <= -120)flaglelbow = 1;
		}
		glutPostRedisplay();
		break;
	case '5':
		if (flagrelbow)
		{
			relbow += 5;
			if (relbow >= 0)flagrelbow = 0;
		}
		else
		{
			relbow -= 5;
			if (relbow <= -120)flagrelbow = 1;
		}
		glutPostRedisplay();
		break;
	case '6':
		if (flaglhips)
		{
			lhips += 5;
			if (lhips >= 120)flaglhips = 0;
		}
		else
		{
			lhips -= 5;
			if (lhips <= 0)flaglhips = 1;
		}
		glutPostRedisplay();
		break;
	case '7':
		if (flagrhips)
		{
			rhips += 5;
			if (rhips >= 120)flagrhips = 0;
		}
		else
		{
			rhips -= 5;
			if (rhips <= 0)flagrhips = 1;
		}
		glutPostRedisplay();
		break;
	case '8':
		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		glutPostRedisplay();
		break;
	case '9':
		if (flagrfoot)
		{
			rfoot += 5;
			if (rfoot >= 60)flagrfoot = 0;
		}
		else
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 1;
		}
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
*/

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '0':
		angle = (angle + 5) % 360;
		glutPostRedisplay();
		break;
	case '1':
		angle = (angle - 5) % 360;
		glutPostRedisplay();
		break;
	case '2':
		if (yy < 8.0) {
			yy += 0.05;
		}
		else {
			yy = -8.0;
		}
			
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -60)flaglshoulder = 1;
		}
		glutPostRedisplay();
		//3
		if (flagrshoulder)
		{
			rshoulder -= 5;
			if (rshoulder <= -60)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 1;
		}
		glutPostRedisplay();
		//4
		if (flaglelbow)
		{
			lelbow += 2.5;
			if (lelbow >= 0)flaglelbow = 0;
		}
		else
		{
			lelbow -= 2.5;
			if (lelbow <= -30)flaglelbow = 1;
		}
		glutPostRedisplay();
		//5
		if (flagrelbow)
		{
			relbow += 2.5;
			if (relbow >= 0)flagrelbow = 0;
		}
		else
		{
			relbow -= 2.5;
			if (relbow <= -30)flagrelbow = 1;
		}
		glutPostRedisplay();
		//6
		if (flaglhips)
		{
			lhips += 2.5;
			if (lhips >= 30)flaglhips = 0;
		}
		else
		{
			lhips -= 2.5;
			if (lhips <= 0)flaglhips = 1;
		}
		glutPostRedisplay();
		//7
		if (flagrhips)
		{
			rhips += 2.5;
			if (rhips >= 30)flagrhips = 0;
		}
		else
		{
			rhips -= 2.5;
			if (rhips <= 0)flagrhips = 1;
		}
		glutPostRedisplay();
		//8
		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		glutPostRedisplay();
		//9
		if (flagrfoot)
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 0;
		}
		else
		{
			rfoot += 5;
			if (rfoot >= +60)flagrfoot = 1;
		}
		glutPostRedisplay();
		break;	
	
	
	default:
		break;
	}
}
int main(int argc, char** argv)
{
	printf("按键‘0’,‘1’为整体旋转\n");
	printf("按键‘2’使机器人行走\n");
	//printf("按键‘2’,‘3’,‘4’,‘5’为手臂旋转\n");
	//printf("按键‘6’,‘7’,‘8’,‘9’为腿部旋转\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RED);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 10);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutKeyboardFunc(keyboard);
	
	glutMainLoop();
	return 0;
}