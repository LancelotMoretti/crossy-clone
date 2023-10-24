#include <windows.h>
#include <iostream>
#include <chrono>
#include <utility>

#include "game.hpp"
#include "scene.hpp"
#include "player.hpp"

const int w = 1920, h = 1080;

void test() {
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console); // get device context

	SetConsoleTitle("Crossy Clone"); // Set title
	ShowWindow(console, SW_MAXIMIZE); // Maximize window

	DWORD style = GetWindowLong(console, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(console, GWL_STYLE, style);

	BITMAPINFO toiquagae;
	ZeroMemory(&toiquagae, sizeof(BITMAPINFO));
	toiquagae.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	toiquagae.bmiHeader.biWidth = w;
	toiquagae.bmiHeader.biHeight = -h;
	toiquagae.bmiHeader.biPlanes = 1;
	toiquagae.bmiHeader.biBitCount = 32;
	
	int frame = 0, time = 0;

	int cur = 0, numcur = 1;
	byte count[3] = { 1, 1, 1 }, num[3] = { 1, 1, 1 };

	byte* bits;
	HBITMAP bitmap = CreateDIBSection(hdc, &toiquagae, DIB_RGB_COLORS, (void**)&bits, nullptr, 0);

	auto start = std::chrono::high_resolution_clock::now();

	while (true) {
		for (int x = 0; x < w; x++) {
			for (int y = 0; y < h; y++) {
				byte* pixels = bits + (x + y * w) * 4;

				pixels[0] = count[0]; // B
				pixels[1] = count[1]; // G
				pixels[2] = count[2]; // R
				pixels[3] = 0;
			}
		}

		++frame;
	
		auto now = std::chrono::high_resolution_clock::now();
		uintmax_t micro = std::chrono::duration_cast<std::chrono::microseconds>(now - start).count();

		if (micro >= (uintmax_t)time * 1000000 / 85) {
			HDC memDC = CreateCompatibleDC(hdc);
			HBITMAP oldBit = (HBITMAP)SelectObject(memDC, bitmap);
			BitBlt(hdc, 0, 0, w, h, memDC, 0, 0, SRCCOPY);

			SelectObject(memDC, oldBit);
			DeleteDC(memDC);

			++time;
		}

		if (count[cur] == 0 || count[cur] == 255) {
			cur += numcur;
			if (cur == 0 || cur == 2) numcur = -numcur;
		}

		if (count[cur] == 0 || count[cur] == 255) num[cur] = -num[cur];
		count[cur] += num[cur];
	}

	DeleteObject(bitmap);

	ReleaseDC(console, hdc); // release device context
	DeleteDC(hdc);
}

int main() {
	Game game;
}