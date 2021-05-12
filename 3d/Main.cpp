

#include "glut/glut.h"
#include "./SDL2-2.0.14/include/SDL.h"
#include "Render.h"
#include "InitMono.h"
#include <iostream>

#pragma comment (lib, "SDL2.lib")
#pragma comment (lib, "SDL2main.lib")
#pragma comment (lib, "glut32.lib")


using namespace std;

SDL_Window* window; // ������ ���� ��� SDL
Render* render;
InitMono* initMono;

const int width = 640; // ������ ����
const int height = 480; // ������ ����


void init() {

	// ������������� SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "Unable to init SDL, error: " << SDL_GetError() << endl;
		exit(1);
	}

	// �������� ������� �����, ����������� �����

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

	// ������� ���� � ���������� "Cube", �������� 640�480 � ������������� �� ������ ������.

	window = SDL_CreateWindow("Practika", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	SDL_GLContext glcontext = SDL_GL_CreateContext(window); // ������� �������� OpenGL

	if (window == NULL) {	// ���� �� ���������� ������� ����, �� �������
		exit(1);
	}

	// ������������� OpenGL


	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // ������������� ������� ���� �� ������
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST); // �������� ���� �������
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f); // ����������� ���������� �����������
	glMatrixMode(GL_MODELVIEW); // ��������� � ���������� �����

	//������� Render
	render = new Render();
	initMono = new InitMono(render);
	initMono->Update();
}

int main(int argc, char* argv[]) {

	init(); // �������������

	bool running = true;

	float xrf = 0; // ���� ��������
	double x = 0, lastX = 0;
	bool isDrag = false;
	while (running) {

		SDL_Event event; // ������� SDL
		
		

		while (SDL_PollEvent(&event)) { // �������� ��������� �������
			
			switch (event.type) { // �������:
			case SDL_QUIT: // ���� ��������� ������� �������� ����, �� ��������� ������ ���������
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				lastX = event.motion.x;
				isDrag = true;
				break;
			case SDL_MOUSEBUTTONUP:
				isDrag = false;
				break;
			case SDL_KEYDOWN: // ���� ������ �������
				switch (event.key.keysym.sym) { // ������� �����
				case SDLK_ESCAPE: // ������� ESC
					running = false; // ��������� ������ ���������
					break;
				}
				break;
			}
		}
		if (isDrag) {
			x = event.motion.x;
		}

		// ���� ��������� �������� �������� ���� ��������, ��� ����� ������ �����������

		xrf -= (lastX - x);

		lastX = x;

		initMono->Update();

		render->Update(0,xrf,0); //��������� ���� � �������� �� ��� �


		// ��������� �����

		glFlush();
		SDL_GL_SwapWindow(window);
	}

	SDL_Quit(); // ��������� ������ SDL � �������
	return 0;
}