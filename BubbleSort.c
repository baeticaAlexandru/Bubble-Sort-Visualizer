#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1400
#define HEIGHT 1000
#define OFFSET 395 // (DIST * (nr dreptunghiuri - 1) + WRECTANGLE) / 2
                  // Cei 10 pixeli aflati in dreapta ultimului dreptunghi nu se iau in calcul
#define DIST 40  // WRECTANGLE + 10 (distanta dintre 2 dreptunghiuri)
#define WRECTANGLE 30

int main() {
	int v[20], i;
	for (i = 0; i < 20; i++) {
		v[i] = GetRandomValue(1, 100);
	}
	InitWindow(WIDTH, HEIGHT, "BubbleSort");
	ClearBackground(BLACK);
	int posX = WIDTH / 2 - OFFSET, s = 0, avg = 0, j = 0, k = 1, aux;
	for (i = 0; i < 20; i++) 
		s = s + v[i];
	avg = s / 20;  // variabila folosita strict pentru centrarea dreptunghiurilor in fereastra
	while (!WindowShouldClose()) {
		SetTargetFPS(20);
		BeginDrawing();
		ClearBackground(BLACK);

		posX = WIDTH / 2 - OFFSET;
			for (i = 0; i < 20; i++) {
				DrawRectangle(posX, HEIGHT / 2 + avg - 2 * v[i], WRECTANGLE, 2 * v[i], RED);
				posX = posX + DIST;
				if (i == 19) {
					posX = WIDTH / 2 - OFFSET;
				}
			}
			if (j < 19) {
				if (v[j] > v[k]) {
					aux = v[j];
					v[j] = v[k];
					v[k] = aux;
					DrawRectangle(WIDTH / 2 - OFFSET + DIST * k, HEIGHT / 2 + avg - 2 * v[j], WRECTANGLE, 2 * v[j], YELLOW);
					DrawRectangle(WIDTH / 2 - OFFSET + DIST * j, HEIGHT / 2 + avg - 2 * v[k], WRECTANGLE, 2 * v[k], YELLOW);
				}
				k++;
				if (k == 20) {
					j++;
					k = j + 1;
				}
			}

			if (j == 19) {
				for (i = 0; i < 20; i++)
					DrawRectangle(WIDTH / 2 - OFFSET + DIST * i, HEIGHT / 2 + avg - 2 * v[i], WRECTANGLE, 2 * v[i], GREEN);
			}

		EndDrawing();
	}
	CloseWindow();
	return 0;
}