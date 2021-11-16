#pragma once
#include "Define.h"
#include "Struct.h"
#include <iostream>
#include <string>
#include <winbgim.h>
using namespace std;
struct WordWrap {
	string result[maxLine];
	int size;
	int linePerPage;
	int toRight;
	int start;
	WordWrap(int toRight);
	void StoreString(string res, Button helpArea);
	void PrintPage(bool down, Button helpArea, int color);
	int GetIndex(int x, int y, Button helpArea);
};
WordWrap::WordWrap(int toRight) {
	this->toRight = toRight;
	this->size = 0;
}
void WordWrap::StoreString(string res, Button helpArea) {
	settextstyle(10, HORIZ_DIR, 1);
	int len = res.length();
	int x1 = helpArea.x1, x2 = helpArea.x2;
	int y2 = helpArea.y2, y1 = helpArea.y1;
	int fontHeight = textheight((char*)res.c_str());
	string temp = "";
	int j, tj;
	char *msg;
	int low = 0;
	for (int i = 0; i <= len; ++i) {	
		if (i < len) {
			temp += res[i];
			msg = (char*)temp.c_str();
			if (x1 + margin + textwidth(msg) > x2 - margin - toRight) {
				j = i;
				tj = i;	
				if (res[i] != ' ') { 
					while(res[i] != ' ' && i >= low) 
						i--;
					i++;
					if (i == low) {
						while(x1 + margin + textwidth(msg) > x2 - margin - toRight) {
							temp.resize(temp.length() - 1);
							msg = (char*)temp.c_str();	
							j--;
						}
						i = j;
						low = j + 1;
					} else {
						while(res[j] != ' ' && j < len) 
							j++;
						while(tj > i - 1) {
							temp.resize(temp.length() - 1);
							tj--;
						}
						low = i;
						i--;
					}
				} else {
					while(res[i] == ' ' && i >= low) {
						temp.resize(temp.length() - 1);
						i--;
					}
					msg = (char*)temp.c_str();
					while(res[j] == ' ' && j < len) {
						j++;
					}
					if (x1 + margin + textwidth(msg) > x2 - margin - toRight) {
						while(x1 + margin + textwidth(msg) > x2 - margin - toRight) {
							temp.resize(temp.length() - 1);
							msg = (char*)temp.c_str();
							i--;
						}
						low = i + 1;
					} else {
						low = j;
						i = j - 1;
					}
				}
				result[size] = temp;
				temp = "";
				size++;
			}
		} 
		if (i == len) {
			msg = (char*)temp.c_str();
			if (x1 + margin + textwidth(msg) > x2 - margin - toRight) {
				int lenTemp = temp.length();
				string tt = "";
				for (int i = 0; i <= lenTemp; ++i) {
					if (i < lenTemp) {
						tt += temp[i];
						msg = (char*)tt.c_str();
						if (x1 + margin + textwidth(msg) > x2 - margin - toRight) {
							if (x1 + margin + textwidth(msg) > x2 - margin - toRight) {
								tt.resize(tt.length() - 1);
								msg = (char*)tt.c_str();
								i--;
							}
							result[size] = temp;
							tt = "";
							size++;
						}
					} else {
						result[size] = temp;
						tt = "";
						size++;
					}
				}
			} else {
				result[size] = temp;
				temp = "";
				size++;
			}	
		}
	}
	start = -1;	
	linePerPage = (y2 - margin - (y1 + margin)) / (fontHeight + marginLine);
}
void WordWrap::PrintPage(bool down, Button helpArea, int color) {
	bool isLessThan = true;
	if (size >= linePerPage) {
		if (down) {
			if (start + linePerPage > size - 1) {
				return;
			} else {
				start++;
			}
		} else {
			if (start - 1 < 0) {
				return;
			} else {
				start--;
			}
		}
		isLessThan = false;
	}
	if (isLessThan) start++;
	setcolor(BLACK);
	settextstyle(10, HORIZ_DIR, 1);
	int x1 = helpArea.x1, y1 = helpArea.y1, x2 = helpArea.x2, y2 = helpArea.y2;
	int fontHeight = textheight((char*)result[0].c_str());
	setfillstyle(1, color);
	bar(x1, y1 + 1, x2 - toRight, y2);
	int xTxtTop, yTxtTop;
	for (int i = start; i < min(start + linePerPage, start + size); ++i) {
		xTxtTop = x1 + margin;
		yTxtTop = y1 + margin + (fontHeight + marginLine) * (i - start);
		setbkcolor(color);
		outtextxy(xTxtTop, yTxtTop, (char*)result[i].c_str());
	}
}
int WordWrap::GetIndex(int x, int y, Button helpArea) {
	int x1 = helpArea.x1, y1 = helpArea.y1, x2 = helpArea.x2;	
	int fontHeight = textheight((char*)result[0].c_str());	
	int xTxtTop, yTxtTop, xTxtBot, yTxtBot;	
	for (int i = start; i < min(start + linePerPage, start + size); ++i) {
		xTxtTop = x1;
		yTxtTop = y1 + margin + (fontHeight + marginLine) * (i - start);
		xTxtBot = x2 - toRight;
		yTxtBot = yTxtTop + fontHeight;
		if (x > xTxtTop && x < xTxtBot && y > yTxtTop && y < yTxtBot)
			return i;
	}
	return -1;
}
