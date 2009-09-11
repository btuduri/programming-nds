#include "Flib/FLib.h"
#include <stdio.h>

void DrawScene();
float angle = 0;

int main(void)
{
	F_Init3D();
	consoleDemoInit();

	lcdSwap();

	// Perspective: Ajusta projeção 3D para a tela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 256.0 / 192.0, 0.1, 100);

	// Model: Desenho do modelo 3D
	glMatrixMode(GL_MODELVIEW);

	while(true)
	{
		if (F_Touch.Held)
			angle = F_GetAngle(128, 96, F_Touch.X, F_Touch.Y) * 360 / 512;

		DrawScene();

		consoleClear();
		printf("Angulo: %f", angle);

		F_WaitVblank();
	}
}

void DrawScene()
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f,1.0f,0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
		glColor3f(0.0f,0.0f,1.0f); glVertex3f( 0.0f, 0.0f, 0.0f);
		glColor3f(1.0f,0.0f,0.0f); glVertex3f( 3.0f, 0.0f, 0.0f);
		glColor3f(0.0f,1.0f,0.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
		glColor3f(0.0f,0.0f,1.0f); glVertex3f( 0.0f, 0.0f, 0.0f);
		glColor3f(1.0f,0.0f,0.0f); glVertex3f( 3.0f, 0.0f, 0.0f);
	glEnd();
}
