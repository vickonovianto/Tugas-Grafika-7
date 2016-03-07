#include <vector>
#include <map>
#include <iostream>
#include "framebuffer.h"
#include "input.h"
#include "color32.h"
#include "point2.h"
#include "file.h"

using namespace std;


int main(){
	Framebuffer framebuffer;

	

	framebuffer.ClearScreen();
	
	vector<string> filenames;
    filenames.push_back("points.txt");
	
	
	double t;
	
	map<string, vector<Point2> > points = getPointsFromFile(filenames);
	//printf("points size: %d\n",points.size());
	/*for(int i=0; i<points["head_up"].size(); i++)
		cout<<points["head_up"][i].x<<" "<<points["head_up"][i].y<<endl;*/
	
	for(map<string, vector<Point2>>::iterator it=points.begin(); it!=points.end(); it++){
		//cout<<"it:"<<it->first<<endl;
		for (double i = 0.0; i < 1.0; i+=0.0005) {
			t = i;
			framebuffer.drawCurve(it->second, t, WHITE);
		}
	}

	//printf("a\n");
	vector<Point2> *points_edit;
	points_edit = &points["hat"];
	//printf("b\n");
	Point2 *point_idx;
	//printf("c\n");
	framebuffer.SwapBuffers();
	set_conio_terminal_mode();
	while (1) {
		char c = getch();
		//printf("c:  %c",c);
		if(c == '0')
			point_idx = &(points_edit->at(0));
		else if(c == '1')
			point_idx = &(points_edit->at(1));
		else if(c == '2')
			point_idx = &(points_edit->at(2));
		else if(c == 's'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, BLACK);
			}

			framebuffer.SwapBuffers();

			for (int i = 0; i < points_edit->size(); i++) {
				points_edit->at(i).y += 5;
			}

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, WHITE);
			}

			framebuffer.SwapBuffers();
		} 
		else if(c == 'w'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, BLACK);
			}

			framebuffer.SwapBuffers();

			for (int i = 0; i < points_edit->size(); i++) {
				points_edit->at(i).y -= 5;
			}

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 'a'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, BLACK);
			}

			framebuffer.SwapBuffers();

			for (int i = 0; i < points_edit->size(); i++) {
				points_edit->at(i).x -= 5;
			}

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 'd'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, BLACK);
			}

			framebuffer.SwapBuffers();

			for (int i = 0; i < points_edit->size(); i++) {
				points_edit->at(i).x += 5;
			}

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 'g'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, BLACK);
			}

			framebuffer.SwapBuffers();

			point_idx->y += 5;

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 't'){ 
			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, BLACK);
			}

			framebuffer.SwapBuffers();

			point_idx->y -= 5;

			for (double i = 0.0; i < 1.0; i+=0.01) {
				t = i;
				framebuffer.drawCurve(*points_edit, t, WHITE);
			}

			framebuffer.SwapBuffers();
		}
		else if(c == 'x'){
			break;
		}
		else{
			int idx = int(c);
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
