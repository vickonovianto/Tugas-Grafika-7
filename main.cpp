#include <vector>
#include <map>
#include <iostream>
#include "framebuffer.h"
#include "input.h"
#include "color32.h"
#include "point2.h"
#include "file.h"
#include <unistd.h>

using namespace std;

Framebuffer framebuffer;

void moveUp(vector<Point2> *points_edit, Point2 *point_idx, int n){
	double t;
	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(*points_edit, t, BLACK);
	}

	framebuffer.SwapBuffers();

	point_idx->y -= n;

	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(*points_edit, t, WHITE);
	}

	framebuffer.SwapBuffers();
}

void moveUp(vector<Point2> *points_edit, Point2 *point_idx){
	moveUp(points_edit, point_idx, 5);
}

void moveDown(vector<Point2> *points_edit, Point2 *point_idx, int n){
	double t;
	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(*points_edit, t, BLACK);
	}

	framebuffer.SwapBuffers();

	point_idx->y += n;

	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(*points_edit, t, WHITE);
	}

	framebuffer.SwapBuffers();
}

void moveDown(vector<Point2> *points_edit, Point2 *point_idx){
	moveDown(points_edit, point_idx, 5);
}

void moveRight(vector<Point2> *points_edit, Point2 *point_idx, int n){
	double t;
	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(*points_edit, t, BLACK);
	}

	framebuffer.SwapBuffers();

	for (int i = 0; i < points_edit->size(); i++) {
		points_edit->at(i).x += n;
	}

	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(*points_edit, t, WHITE);
	}

	framebuffer.SwapBuffers();
}

void moveRight(vector<Point2> *points_edit, Point2 *point_idx){
	moveRight(points_edit, point_idx, 5);
}

void moveLeft(vector<Point2> *points_edit, Point2 *point_idx, int n){
	double t;
	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(*points_edit, t, BLACK);
	}

	framebuffer.SwapBuffers();

	for (int i = 0; i < points_edit->size(); i++) {
		points_edit->at(i).x -= n;
	}

	for (double i = 0.0; i < 1.0; i+=0.01) {
		t = i;
		framebuffer.drawCurve(*points_edit, t, WHITE);
	}

	framebuffer.SwapBuffers();
}

void moveLeft(vector<Point2> *points_edit, Point2 *point_idx){
	moveLeft(points_edit, point_idx, 5);
}

int main(){
	framebuffer.ClearScreen();
	
	vector<string> filenames;
    filenames.push_back("points.txt");
	
	double t;
	
	map<string, vector<Point2> > points = getPointsFromFile(filenames);
	
	for(map<string, vector<Point2>>::iterator it=points.begin(); it!=points.end(); it++){
		//cout<<"it:"<<it->first<<endl;
		for (double i = 0.0; i < 1.0; i+=0.0005) {
			t = i;
			framebuffer.drawCurve(it->second, t, WHITE);
		}
	}

	framebuffer.SwapBuffers();
	set_conio_terminal_mode();
	vector<Point2> *points_edit;

	int n_rightBrow = 0, sign_rightBrow = true;
	int n_rightTears = 0;
	while (1) {
		// Move right brow
		points_edit = &points["rightBrow"];

		if (n_rightBrow > 5){
			sign_rightBrow = !sign_rightBrow;
			n_rightBrow = 0;
		}

		if (sign_rightBrow){
			moveUp(points_edit, &(points_edit->at(1)), 1);
			n_rightBrow++;
		} else {
			moveDown(points_edit, &(points_edit->at(1)), 1);
			n_rightBrow++;
		}

		// Move right tears
		points_edit = &points["rightTears"];

		if (n_rightTears > 35){
			n_rightTears = 0;

			moveUp(points_edit, &(points_edit->at(0)), 35 * 5);
			moveUp(points_edit, &(points_edit->at(1)), 35 * 5);
			moveUp(points_edit, &(points_edit->at(2)), 35 * 5);
		}

		moveDown(points_edit, &(points_edit->at(0)), 5);
		moveDown(points_edit, &(points_edit->at(1)), 5);
		moveDown(points_edit, &(points_edit->at(2)), 5);

		n_rightTears++;

		if(kbhit()){
			char c = getch();

			if (c == 'x'){
				break;
			}
		}

		usleep(20000);
	}

	return 0;
}
