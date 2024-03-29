#include <windows.h>              // musi by�, nie mo�na u�y� <stdio.h> zamiast tego
#define GLUT_DISABLE_ATEXIT_HACK  // musi by� u�yte przed includowaniem "glut.h"
#include "zmienne.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
using namespace std;

void Reshape(int w, int h)
     {
     if(h==0)
    	 h=1;

     ratio=1.0f *w/h;

     glViewport(0,0,w,h);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45,ratio,0.01,1000); //HA HA HA :F 1->0.01
     glMatrixMode(GL_MODELVIEW);

     glLoadIdentity();

     gluLookAt(x,y,z,
     x+lx, y+ly, z+lz,
     0.0f, 1.0f, 0.0f);

     }

void pressKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT:
		deltaKat = -0.005f;
		break;
	case GLUT_KEY_RIGHT:
		deltaKat = 0.005f;
		break;
	case GLUT_KEY_UP:
		deltaRuch = 1;
		break;
	case GLUT_KEY_DOWN:
		deltaRuch = -1;
		break;
	}
	glutPostRedisplay();

}

void releaseKey(int key, int x, int y) { //jak to wydosta� z tego pliku?

	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		deltaKat = 0.0;
		break;
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN:
		deltaRuch = 0;
		break;
	}
	glutPostRedisplay();

}

void processNormalKeys(unsigned char key, int x, int y) {

	switch (key) {  //tu jest co� skopane
	case 'a':
		deltaKat=-0.002;
		//deltaKatpion=0;
		break;
	case 'd':
		deltaKat=0.002;
		//deltaKatpion=0;
		break;
	case 'w':
		deltaRuch = 1;
		break;
	case 's':
		deltaRuch = -1;
		break;
	case 27:
	case 'q':case'Q':
		exit(0);
	}

}

void upNormalKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
	case 'd':
		deltaKat = 0.0;
		break;
	case 's':
	case 'w':
		deltaRuch = 0.0;
		break;
	case 27:
	case 'q':
		exit(0);
		break;
	}
	glutPostRedisplay();

}

void mouse(int a, int b) {
	if(a>1000)
		glutWarpPointer(a-900,b);
	if(a<24)
		glutWarpPointer(a+900,b);

	kat2 = -0.007*(512-a);
	//kat=ang;
	lx = -sin(kat+kat2);
	lz = cos(kat+kat2);

	katpion=0.005*(b-384); //added

	ly = -sin(katpion); //added, doda�em 45 �eby na starcie kamera patrzy�a w p�aszczy�nie poziomiej

	glLoadIdentity();

	gluLookAt(	x, y, z,
				x + lx, y + ly,
				z + lz, 0.0f, 1.0, 0.0f);

}
