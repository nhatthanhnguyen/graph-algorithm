#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <dirent.h>
#include <winbgim.h>
#include <fstream>
#include <cmath>
#include "Define.h"
#include "Struct.h"
#include "Stack.h"
#include "Queue.h"
#include "WordWrap.h"
#include "Global.h"
#include "ConvertValue.h"
#include "Screen.h"
#include "CheckAlgo.h"
#include "DrawObject.h"
#include "Algorithm.h"
#include "Scrollbar.h"
#include "File.h"
using namespace std;
void Run() {
	// createScreenWelcome();
	CreateScreen();
	CreateButton();
	Graph graph;
	int x, y;
	string nameNode, nameFile;
	label:
	NotificationFull("Hay mo mot do thi co san hoac tao mot do thi moi!");
	while(true){//Kiem tra khi moi vao. Chi duoc chon 1 trong 2 nut: New, Open
		if(kbhit())
			ClearBuffer();
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(x != -1 && y != -1){
			if(CheckClickButton(closeButton, x, y)){// VO TINH NHAN NUT THOAT LUON
				NotificationFull("Ban co muon luu lai khong?");
				DrawButtonForNoti(continueButton);
				DrawButtonForNoti(cancelButton);
				while(true){
					if(kbhit()){}
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if(x != -1 && y != -1){
						if(CheckClickButton(continueButton, x, y)){
							reAddExit:
							nameFile = AddFileName();
							if(!nameFile.empty()){
								nameFile = "saves/" + nameFile;
								nameFile += ".txt";
								ofstream graphFile((char*)nameFile.c_str());
								graphFile.close();
								WriteFile((char*)nameFile.c_str(), graph);
								goto exit;
							}
							else goto reAddExit;
						}
						else if(CheckClickButton(cancelButton, x, y)) goto exit;
					}
				}
				exit:
				closegraph();
				return;
			}
			else{
				bool flag = true;
				if(x > newButton.x1 && x < newButton.x2 && y > newButton.y1 && y < newButton.y2){//Nhat nut New
					NotificationFull("Chon chuc nang");
					string fileName = "";
					flag = false;
					if(RunningToolbar(graph, fileName, x, y, flag) == false) return;
				}
				else if(CheckClickButton(openButton, x, y)){//Nhan nut Open  
					string nameFile = OpenScreen();
					if(nameFile.size() > 0){
						nameFile = "saves/" + nameFile;
						ReadFile((char*)nameFile.c_str(), graph);
						DrawGraph(graph);
						DrawWeightMatrix(graph);
						NotificationFull("Hay chon chuc nang!");
						flag = true;
						if(RunningToolbar(graph, nameFile, x, y, flag) == false) return;
					}
					else{
						setfillstyle(1, DODGERBLUE);
						bar(processingArea.x1 + 1, processingArea.y1 + 1, processingArea.x2 - 1, processingArea.y2 - 1);
						goto label;
					} 
				}
			}
		}
	}
	return;
}
