#include <nds.h>

#include "logo.h"

void InitGL();
void LoadGLTextures();
void DrawGLScene();

float xrot;
float yrot;
float xspeed;
float yspeed;

int texture;

int main()
{
	// Inicializações
	videoSetMode(MODE_0_3D);
	vramSetBankA(VRAM_A_TEXTURE);
	
	InitGL();
	LoadGLTextures();

	glLight(0, RGB15(31, 31, 31), 0, floattov10(-1.0), 0);

	// Viewport: Área da tela que será utilizada pelo OpenGL
	glViewport(0, 0, 255, 191);
	
	// Propriedades do material deve ser ajustado
	// DS não possui valores padrão
	glMaterialf(GL_AMBIENT, RGB15(16, 16, 16));
	glMaterialf(GL_DIFFUSE, RGB15(16, 16, 16));
	glMaterialf(GL_SPECULAR, BIT(15) | RGB15(8, 8, 8));
	glMaterialf(GL_EMISSION, RGB15(16, 16, 16));
	glMaterialShinyness();

	// Perspective: Ajusta projeção 3D para a tela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 256.0 / 192.0, 0.1, 100);

	// Model: Desenho do modelo 3D
	glMatrixMode(GL_MODELVIEW);

	while (true)
	{
		scanKeys();
		if (keysHeld() & KEY_LEFT)  xspeed -= 0.2;
		if (keysHeld() & KEY_RIGHT) xspeed += 0.2;
		if (keysHeld() & KEY_UP)    yspeed += 0.2;
		if (keysHeld() & KEY_DOWN)  yspeed -= 0.2;

		DrawGLScene();
		glFlush(0);
		
		swiWaitForVBlank();

		xrot += xspeed;
		yrot += yspeed;
	}
	
	return 0;
}

void InitGL()
{
	glInit();

	glEnable(GL_ANTIALIAS);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);

	glClearColor(0, 0, 8, 31);
	glClearPolyID(63);
	glClearDepth(0x7FFF);
}

void LoadGLTextures()
{
	glGenTextures(1, &texture);
	glBindTexture(0, texture);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_128, TEXTURE_SIZE_128, 0, TEXGEN_TEXCOORD, (uint8 *)logoBitmap);
}

void DrawGLScene()
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, texture);
	glPolyFmt(POLY_ALPHA(15) | POLY_CULL_NONE  | POLY_FORMAT_LIGHT0);
	glBegin(GL_QUADS);
		// Front Face
		glNormal3f( 0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
		glNormal3f( 0.0f, 0.0f,-1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
		glNormal3f( 0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
		glNormal3f( 0.0f,-1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		// Right face
		glNormal3f( 1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();
}
