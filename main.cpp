#include <vector>
#include "framebuffer.h"
#include "input.h"
#include "color32.h"
#include "point2.h"

using namespace std;


int main(){
	Framebuffer framebuffer;

	set_conio_terminal_mode();

	framebuffer.ClearScreen();
	
	vector<Point2> points; 
	//points.push_back(Point2(240.0,300.0));
	points.push_back(Point2(450,400));
	points.push_back(Point2(480,600));
	points.push_back(Point2(560,800));
	points.push_back(Point2(660,600));
	points.push_back(Point2(690,400));

	double t;

	for (double i = 0.0; i < 1.0; i+=0.0005) {
		t = i;
		framebuffer.drawCurve(points, t, WHITE);
	}

	framebuffer.SwapBuffers();

	points.clear();
	points.push_back(Point2(450,400));
	points.push_back(Point2(530,325));
	points.push_back(Point2(610,325));
	points.push_back(Point2(690,400));

	for (double i = 0.0; i < 1.0; i+=0.0005) {
		t = i;
		framebuffer.drawCurve(points, t, WHITE);
	}

	framebuffer.SwapBuffers();

	points.clear();
	points.push_back(Point2(470,450));
	points.push_back(Point2(495,425));
	points.push_back(Point2(520,450));

	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(points, t, WHITE);
	}

	framebuffer.SwapBuffers();

	while (1) {
		char c = getch();
		if(c == 's'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, BLACK);
			}

			framebuffer.SwapBuffers();

			for (int i = 0; i < points.size(); i++) {
				points[i].y += 5;
			}

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, WHITE);
			}

			framebuffer.SwapBuffers();
		} 
		else if(c == 'w'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, BLACK);
			}

			framebuffer.SwapBuffers();

			for (int i = 0; i < points.size(); i++) {
				points[i].y -= 5;
			}

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 'a'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, BLACK);
			}

			framebuffer.SwapBuffers();

			for (int i = 0; i < points.size(); i++) {
				points[i].x -= 5;
			}

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 'd'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, BLACK);
			}

			framebuffer.SwapBuffers();

			for (int i = 0; i < points.size(); i++) {
				points[i].x += 5;
			}

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 'g'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, BLACK);
			}

			framebuffer.SwapBuffers();

			points[1].y += 5;

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 't'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, BLACK);
			}

			framebuffer.SwapBuffers();

			points[1].y -= 5;

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(points, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 'x'){
			break;
		}
	}

	// for (int i = 0; i< points.size()-1; i++) {
	// 	framebuffer.DrawLine(Point2((int)points[i].x, (int)points[i].y), Point2((int)points[i+1].x, (int)points[i+1].y), (Color32){0, 255, 0, 255});
	// 	//framebuffer.SetPixel((int)points[i].x, (int)points[i].y, (Color32){0, 255, 0, 255});
	// 	framebuffer.SwapBuffers();
	// }
	// t = 0.0 / 999.0;

	// drawCurve(framebuffer, points, t);
	// printf("d\n");
	// framebuffer.SwapBuffers();
	// printf("e\n");

	//delete &framebuffer;
	
	return 0;
}
