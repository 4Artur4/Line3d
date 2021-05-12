

#include "glut/glut.h"
#include "./SDL2-2.0.14/include/SDL.h"
#include "Render.h"
#include "InitMono.h"
#include <iostream>

#pragma comment (lib, "SDL2.lib")
#pragma comment (lib, "SDL2main.lib")
#pragma comment (lib, "glut32.lib")


using namespace std;

SDL_Window* window; // задаем окно для SDL
Render* render;
InitMono* initMono;

const int width = 640; // ширина окна
const int height = 480; // высота окна


void init() {

	// Инициализация SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "Unable to init SDL, error: " << SDL_GetError() << endl;
		exit(1);
	}

	// Включаем двойной буфер, настраиваем цвета

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

	// Создаем окно с заголовком "Cube", размером 640х480 и расположенным по центру экрана.

	window = SDL_CreateWindow("Practika", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	SDL_GLContext glcontext = SDL_GL_CreateContext(window); // создаем контекст OpenGL

	if (window == NULL) {	// если не получилось создать окно, то выходим
		exit(1);
	}

	// Инициализация OpenGL


	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // устанавливаем фоновый цвет на черный
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST); // включаем тест глубины
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f); // настраиваем трехмерную перспективу
	glMatrixMode(GL_MODELVIEW); // переходим в трехмерный режим

	//Создаем Render
	render = new Render();
	initMono = new InitMono(render);
	initMono->Update();
}

int main(int argc, char* argv[]) {

	init(); // инициализация

	bool running = true;

	float xrf = 0; // угол поворота
	double x = 0, lastX = 0;
	bool isDrag = false;
	while (running) {

		SDL_Event event; // события SDL
		
		

		while (SDL_PollEvent(&event)) { // начинаем обработку событий
			
			switch (event.type) { // смотрим:
			case SDL_QUIT: // если произошло событие закрытия окна, то завершаем работу программы
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				lastX = event.motion.x;
				isDrag = true;
				break;
			case SDL_MOUSEBUTTONUP:
				isDrag = false;
				break;
			case SDL_KEYDOWN: // если нажата клавиша
				switch (event.key.keysym.sym) { // смотрим какая
				case SDLK_ESCAPE: // клавиша ESC
					running = false; // завершаем работу программы
					break;
				}
				break;
			}
		}
		if (isDrag) {
			x = event.motion.x;
		}

		// пока программа запущена изменяем угол поворота, тем самым вращая отображение

		xrf -= (lastX - x);

		lastX = x;

		initMono->Update();

		render->Update(0,xrf,0); //Обновляем кадр с повротом по оси у


		// обновляем экран

		glFlush();
		SDL_GL_SwapWindow(window);
	}

	SDL_Quit(); // завершаем работу SDL и выходим
	return 0;
}