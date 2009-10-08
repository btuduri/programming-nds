#include "FLib/FLib.h"
#include "background.h"
#include "man.h"

/*float squareRot = 0;
float triangRot = 0;

void DrawGLScene()
{
	// Desenhando triângulo
	glLoadIdentity();
	glTranslatef(-1.5f, 0.0f, -6.0f);
	glRotatef(triangRot, 0, 1, 0);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f);						// Red
		glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of Triangle (Front)
		glColor3f(0.0f,1.0f,0.0f);						// Green
		glVertex3f(-1.0f,-1.0f, 1.0f);					// Left Of Triangle (Front)
		glColor3f(0.0f,0.0f,1.0f);						// Blue
		glVertex3f( 1.0f,-1.0f, 1.0f);					// Right Of Triangle (Front)
		glColor3f(1.0f,0.0f,0.0f);						// Red
		glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of Triangle (Right)
		glColor3f(0.0f,0.0f,1.0f);						// Blue
		glVertex3f( 1.0f,-1.0f, 1.0f);					// Left Of Triangle (Right)
		glColor3f(0.0f,1.0f,0.0f);						// Green
		glVertex3f( 1.0f,-1.0f, -1.0f);					// Right Of Triangle (Right)
		glColor3f(1.0f,0.0f,0.0f);						// Red
		glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of Triangle (Back)
		glColor3f(0.0f,1.0f,0.0f);						// Green
		glVertex3f( 1.0f,-1.0f, -1.0f);					// Left Of Triangle (Back)
		glColor3f(0.0f,0.0f,1.0f);						// Blue
		glVertex3f(-1.0f,-1.0f, -1.0f);					// Right Of Triangle (Back)
		glColor3f(1.0f,0.0f,0.0f);						// Red
		glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of Triangle (Left)
		glColor3f(0.0f,0.0f,1.0f);						// Blue
		glVertex3f(-1.0f,-1.0f,-1.0f);					// Left Of Triangle (Left)
		glColor3f(0.0f,1.0f,0.0f);						// Green
		glVertex3f(-1.0f,-1.0f, 1.0f);					// Right Of Triangle (Left)
	glEnd();

	// Desenhando quadrado
	glLoadIdentity();
	glColor(RGB15(31, 31, 31));
	glTranslatef(1.5f, 0.0f, -6.0f);
	glRotatef(squareRot, 1, 1, 1);
	glBegin(GL_QUADS);
		glColor3f(0.0f,1.0f,0.0f);						// Set The Color To Green
		glVertex3f( 1.0f, 1.0f,-1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f,-1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f, 1.0f);					// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f, 1.0f, 1.0f);					// Bottom Right Of The Quad (Top)
		glColor3f(1.0f,0.5f,0.0f);						// Set The Color To Orange
		glVertex3f( 1.0f,-1.0f, 1.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f, 1.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f( 1.0f,-1.0f,-1.0f);					// Bottom Right Of The Quad (Bottom)
		glColor3f(1.0f,0.0f,0.0f);						// Set The Color To Red
		glVertex3f( 1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Front)
		glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,-1.0f, 1.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom Right Of The Quad (Front)
		glColor3f(1.0f,1.0f,0.0f);						// Set The Color To Yellow
		glVertex3f( 1.0f,-1.0f,-1.0f);					// Top Right Of The Quad (Back)
		glVertex3f(-1.0f,-1.0f,-1.0f);					// Top Left Of The Quad (Back)
		glVertex3f(-1.0f, 1.0f,-1.0f);					// Bottom Left Of The Quad (Back)
		glVertex3f( 1.0f, 1.0f,-1.0f);					// Bottom Right Of The Quad (Back)
		glColor3f(0.0f,0.0f,1.0f);						// Set The Color To Blue
		glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Left)
		glVertex3f(-1.0f, 1.0f,-1.0f);					// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f, 1.0f);					// Bottom Right Of The Quad (Left)
		glColor3f(1.0f,0.0f,1.0f);						// Set The Color To Violet
		glVertex3f( 1.0f, 1.0f,-1.0f);					// Top Right Of The Quad (Right)
		glVertex3f( 1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f,-1.0f);					// Bottom Right Of The Quad (Right)
	glEnd();
}*/

int main(void)
{
	/*F_Init3D();
	//
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);

	consoleDemoInit();

	F_Screen *screen = new F_Screen((u8*)backgroundTiles, backgroundTilesLen, (u16*)backgroundPal, (u16*)manPal);
	F_Background *bg = new F_Background((u16*)backgroundMap, 4, 4);
	F_Sprite *sprite = new F_Sprite((u8*)manTiles, 12);
		
	//F_Music *m = new F_Music(MOD_MUSIC);	
	//s->SetMusic(m);
	
	screen->AddBackground(2, bg, 0, 0);
	screen->AddSprite(sprite);

	sprite->Center();
	
	while(true)
	{
		if (im.Pad.Right.Held)
		{
			bg->Scroll(4, 0);
		}
		else if (im.Pad.Left.Held)
		{
			bg->Scroll(-4, 0);
		}

		if (im.Pad.Up.Held)
		{
			bg->Scroll(0, -4);
		}
		else if (im.Pad.Down.Held)
		{
			bg->Scroll(0, 4);
		}

		if (im.Pad.A.Pressed)
		{
			sprite->AddFrame();
		}

		DrawGLScene();

		squareRot += 0.75f;
		triangRot += 0.9f;
		
		F_Update();
	}*/

	F_Init2D();

	mainBgPal->Load(backgroundPal);
	mainSpPal->Load(manPal);
	subBgPal->Load(backgroundPal);
	subSpPal->Load(manPal);
	
	F_Background *bg = new F_Background(backgroundMap, 4, 4);
	mainScreen->AddBackground(0, bg, 0, 0);
	mainScreen->AddBackground(1, bg, 0, 0);
	mainScreen->AddBackground(2, bg, 0, 0);
	mainScreen->AddBackground(3, bg, 0, 0);
	mainScreen->AddTileset(backgroundTiles, backgroundTilesLen);
	subScreen->AddBackground(0, bg, 0, 0);
	subScreen->AddBackground(1, bg, 0, 0);
	subScreen->AddBackground(2, bg, 0, 0);
	subScreen->AddBackground(3, bg, 0, 0);
	subScreen->AddTileset(backgroundTiles, backgroundTilesLen);

	F_Sprite *sprite = new F_Sprite((u8*)manTiles, 32, 32, 12);
	mainScreen->AddSprite(sprite);
	subScreen->AddSprite(sprite);

	while(true)
		F_Update();
}
