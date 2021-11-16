#pragma once
void CreateNode(int x, int y, string name, int colortext, int colorbk){
	setcolor(colortext);
	setlinestyle(0, 0, 3);
	settextstyle(10, HORIZ_DIR, 1);
	setbkcolor(colorbk);
	outtextxy(x - textwidth((char*)name.c_str())/2, y - textheight((char*)name.c_str())/2, (char*)name.c_str());
	circle(x, y, 25);
}
void AddNode(Graph &graph, int &x, int &y, string &ten, bool isTopo){
	setlinestyle(0, 0, 2);
   	circle(x, y, 25);
	if(isTopo)
   		ten = AddNameTopo();
	else
		ten = AddNameWeight("ten dinh");
   	CreateNode(x, y, (char*)ten.c_str(), WHITE, DODGERBLUE);
}
void Rename(int x, int y, string &ten){// x, y sau nay se truyen node[i].x, node[i].y
	setfillstyle(1, DODGERBLUE);
	fillellipse(x, y, 25, 25);
	setlinestyle(0, 0, 2);
	circle(x, y, 25);
	CreateNode(x, y, (char*)ten.c_str(), WHITE, DODGERBLUE);
}
string AddNameWeight(string name){
	add:
	setfillstyle(1, DODGERBLUE);
	bar(helpArea.x1 + 1, helpArea.y1 + 1, helpArea.x2 - 1, helpArea.y2 - 1);
	string s = "Nhap vao " + name + " (01 -> 99): ";
	settextstyle(10, HORIZ_DIR, 2); 	
	setbkcolor(DODGERBLUE);
	outtextxy(helpArea.x1 + 5, helpArea.y1 + 5, (char*)s.c_str());
	string ans = "";
	int n = 0;
	while(true){
		if(kbhit() == true){
			char key = getch();
			if(key >= 48 && key <= 57 && n < 2){
				ans += ToString(key - 48);
				n++;
				outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, (char*)ans.c_str());
			}
			if(n > 0){
				if(key == 8){
					ans.resize(ans.length() - 1);
					outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, "   ");
					outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, (char*)ans.c_str());
					n--;
				}
			}
			if(n == 2){
				if(ans == "00") {
					ans = "";
					goto add;
				}
				else{
					if(key == 13){
						return ans;
					} 
				}
			}
		} 
	}
}
string AddNameTopo(){
	setfillstyle(1, DODGERBLUE);
	bar(helpArea.x1 + 1, helpArea.y1 + 1, helpArea.x2 - 1, helpArea.y2 - 1);
   	settextstyle(10, HORIZ_DIR, 2);
	string s = "Nhap vao ten mon: ";
	outtextxy(helpArea.x1 + 5, helpArea.y1 + 5, (char*)s.c_str());
	string ans = "";
	int n = 0;
	while(true){
		if(kbhit() == true){
			char key = getch();
			if((key >= 'A' && key <= 'Z') && n < 4){
				ans += key;
				n++;
				outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, (char*)ans.c_str());
			}
			if(n > 0){
				if(key == 8){
					ans.resize(ans.length() - 1);
					outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, "             ");
					outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, (char*)ans.c_str());
					n--;
				}
				else if(key == 13) return ans;
			}
		}  
	}
}
string AddFileName(){
	setfillstyle(1, DODGERBLUE);
	bar(helpArea.x1 + 1, helpArea.y1 + 1, helpArea.x2 - 1, helpArea.y2 - 1);
	string s = "Nhap vao ten file( < 30 ki tu): ";
	settextstyle(10, HORIZ_DIR, 2);
	outtextxy(helpArea.x1 + 5, helpArea.y1 + 5, (char*)s.c_str());
	string ans = "";
	int n = 0; // kich thuoc cua chuoi
	while(true){
		if(kbhit() == true){
			char key = getch();
			if(((key >= 'A' && key <= 'Z') || (key >= 'a' && key <='z') || (key >= '0' && key <= '9')) && n < 30){
				ans += key;
				n++;
				outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, (char*)ans.c_str());
			}
			if(n>0){
				if(key == 8) {
					ans.resize(ans.length() - 1);
					outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, "                                ");
					outtextxy(helpArea.x1 + 5 + textwidth((char*)s.c_str()), helpArea.y1 + 5, (char*)ans.c_str());
					n--;
				}
				if(key == 13) return ans;
			}
		}
	}
}
void NotificationFull(string Noti){
	setfillstyle(1, DODGERBLUE);
	bar(helpArea.x1 + 1, helpArea.y1 + 1, helpArea.x2 - 1, helpArea.y2 - 1);
	settextstyle(10, HORIZ_DIR, 1);
	setbkcolor(DODGERBLUE);
	setcolor(BLACK);
	outtextxy(helpArea.x1 + 5, helpArea.y1 + 5, (char *)Noti.c_str());
}
void DrawTriangle(int x1, int y1, int x2, int y2, int color) {
	setcolor(color);
	float s60 = sin(60 * M_PI / 180);
	float c60 = cos(60 * M_PI / 180);
	x1 = 2 * x1 - x2;
	y1 = 2 * y1 - y2;
	float x3 = c60 * (x1 - x2) - s60 * (y1 - y2) + x2; 
  	float y3 = s60 * (x1 - x2) + c60 * (y1 - y2) + y2;
  	float x4 = c60 * (x1 - x2) + s60 * (y1 - y2) + x2;
  	float y4 = -s60 * (x1 - x2) + c60 * (y1 - y2) + y2;
  	int polypoints[] = {x2, y2, int(round(x3)), int(round(y3)), int(round(x4)), int(round(y4)), x2, y2};
  	setfillstyle(1, color);
  	fillpoly(4, polypoints);
}
void FlipCurved(Node *node1, Node *node2, char *tt, int color) {
	setcolor(color);
	setbkcolor(DODGERBLUE);
	setlinestyle(0, 0, 2);
	int x1 = node1->x, y1 = node1->y, x2 = node2->x, y2 = node2->y;
  	// quay doan thang mot goc 90 do nguoc chieu kim dong ho
  	float midx = (x1 + x2) * 1.0 / 2, midy = (y1 + y2) * 1.0 / 2;
  	float xO = (y2 - midy) + midx; 
  	float yO = -(x2 - midx) + midy;
  	// tinh toa do cua cac giao diem cua duong tron tam O voi duong tron
  	float r1 = sqrt(pow(xO - x1, 2) + pow(yO - y1, 2));
  	float d = r1;
  	float r2 = 25;
  	float a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
  	float h = sqrt(r1 * r1 - a * a);
  	float tempx1 = xO + a * (x1 - xO) / d;
  	float tempy1 = yO + a * (y1 - yO) / d;
  	float tempx2 = xO + a * (x2 - xO) / d;
  	float tempy2 = yO + a * (y2 - yO) / d;
  	float x3 = tempx1 + h * (y1 - yO) / d;
  	float y3 = tempy1 - h * (x1 - xO) / d;
  	float x4 = tempx2 - h * (y2 - yO) / d;
	float y4 = tempy2 + h * (x2 - xO) / d;
	// tim goc quet
	float angle1 = acos(float(x1 - xO) / r1) * 180.0 / M_PI;
	float angle2 = acos(1 - float(pow(r2, 2)) / (2 * pow(r1, 2))) * 180.0 / M_PI;
	if (y1 >= yO) angle1 = 360 - angle1;
	float startAngle = angle1 + angle2;
	float x5 = float(32 * x4 - 7 * x2) / 25;
	float y5 = float(32 * y4 - 7 * y2) / 25;
	float len45 = sqrt(pow(x5 - x4, 2) + pow(y5 - y4, 2));
	float len35 = sqrt(pow(x3 - x5, 2) + pow(y3 - y5, 2));
	float sweep = acos((2 * pow(r1, 2) - pow(len35, 2)) / (2 * pow(r1, 2))) * 180.0 / M_PI;
	sweep += asin(len45 / (2 * r1));
	float endAngle = startAngle + sweep; 
	DrawTriangle(round(x5), round(y5), round(x4), round(y4), color);
	arc(round(xO), round(yO), round(startAngle), round(endAngle), round(r1));
	float sin45 = sin(45 * M_PI / 180);
	float cos45 = cos(45 * M_PI / 180);
	float xT = sin45 * (x1 - xO) + cos45 * (y1 - yO) + xO;
	float yT = -sin45 * (x1 - xO) + cos45 * (y1 - yO) + yO;
	outtextxy(round(xT) - 12, round(yT) - 12, tt);
}
void CreateCurved(Node *node1, Node *node2, char *tt, int color) {
	setcolor(color);
	setbkcolor(DODGERBLUE);
	setlinestyle(0, 0, 2);
	settextstyle(10, HORIZ_DIR, 1);
	int x1 = node1->x, y1 = node1->y, x2 = node2->x, y2 = node2->y;
  	// quay doan thang mot goc 90 do nguoc chieu kim dong ho
  	float midx = (x1 + x2) * 1.0 / 2, midy = (y1 + y2) * 1.0 / 2;
  	float xO = -(y2 - midy) + midx; 
  	float yO = (x2 - midx) + midy;
  	// tinh toa do cua cac giao diem cua duong tron tam O voi duong tron
  	float r1 = sqrt(pow(xO - x1, 2) + pow(yO - y1, 2));
  	float d = r1;
  	float r2 = 25;
  	float a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
  	float h = sqrt(r1 * r1 - a * a);
  	float tempx1 = xO + a * (x1 - xO) / d;
  	float tempy1 = yO + a * (y1 - yO) / d;
  	float tempx2 = xO + a * (x2 - xO) / d;
  	float tempy2 = yO + a * (y2 - yO) / d;
  	float x3 = tempx1 - h * (y1 - yO) / d;
  	float y3 = tempy1 + h * (x1 - xO) / d;
  	float x4 = tempx2 + h * (y2 - yO) / d;
	float y4 = tempy2 - h * (x2 - xO) / d;
	// tim goc quet
	float angle1 = acos(float(x1 - xO) / r1) * 180.0 / M_PI;
	float angle2 = acos(1 - float(pow(r2, 2)) / (2 * pow(r1, 2))) * 180.0 / M_PI;
	if (y1 >= yO) angle1 = -angle1;
	float startAngle = angle1 - angle2;
	float x5 = float(32 * x4 - 7 * x2) / 25;
	float y5 = float(32 * y4 - 7 * y2) / 25;
	float len45 = sqrt(pow(x5 - x4, 2) + pow(y5 - y4, 2));
	float len35 = sqrt(pow(x3 - x5, 2) + pow(y3 - y5, 2));
	float sweep = acos((2 * pow(r1, 2) - pow(len35, 2)) / (2 * pow(r1, 2))) * 180.0 / M_PI;
	sweep += asin(len45 / (2 * r1));
	float endAngle = startAngle - sweep;
	float temp = startAngle;
	startAngle = endAngle;
	endAngle = temp;
	//swap(startAngle, endAngle); 
	float sin45 = sin(45 * M_PI / 180);
	float cos45 = cos(45 * M_PI / 180);
	float xT = sin45 * (x1 - xO) - cos45 * (y1 - yO) + xO;
	float yT = sin45 * (x1 - xO) + cos45 * (y1 - yO) + yO;
	if (!(xT > 440 && xT < 1150 && yT > 90 && yT < 560)) {
		FlipCurved(node1, node2, tt, color);
		return;
	}
	arc(round(xO), round(yO), round(startAngle), round(endAngle), round(r1));
	outtextxy(round(xT) - 12, round(yT) - 12, tt);
	DrawTriangle(round(x5), round(y5), round(x4), round(y4), color);
}
void CreateLine(Node *node1, Node *node2, char *tt, int color) {
	// tim diem dau tien
	setcolor(color);
	setbkcolor(DODGERBLUE);
	setlinestyle(0, 0, 2);
	settextstyle(10, HORIZ_DIR, 1);
	int x1 = node1->x, y1 = node1->y, x2 = node2->x, y2 = node2->y;
	string name1 = node1->name, name2 = node2->name;
	float xx2 = 0, yy2 = 0, xx1 = x1, yy1 = y1;
	xx1 -= x2, yy1 -= y2;
	float a = yy2 - yy1;
	float b = xx1 - xx2;
	float c = a * xx1 + b * yy1; 
	float x0 = -a * c * 1.0 / (a * a + b * b), y0 = -b * c / (a * a + b * b);
	float d = 25 * 25 - c * c * 1.0 / (a * a + b * b);
	float mult = sqrt(d / (a * a + b * b));
	float ax, ay;
	ax = x0 + b * mult;
	ay = y0 - a * mult;
	ax += x2, ay += y2; // diem cuoi de ve mui ten
	// tim diem thu 2
	float midx = (x1 + x2) / 2;
	float midy = (y1 + y2) / 2;
	float bx = 2 * midx - ax;
	float by = 2 * midy - ay;
	// tim diem de ve mui ten
	float vectorx = x1 - x2, vectory = y1 - y2;
	float factor = 7 / sqrt(pow(vectorx, 2) + pow(vectory, 2));
	vectorx *= factor;
	vectory *= factor;
	float x3 = ax + vectorx, y3 = ay + vectory;
	// tim trung diem
	float xT = (x1 + x2) * 1.0 / 2;
	float yT = (y1 + y2) * 1.0 / 2;
	// ve duong thang
	line(ax, ay, bx, by);	
	outtextxy(xT - 13, yT - 13, tt);
	DrawTriangle(x3, y3, ax, ay, color);
}
void DrawGraph(Graph &graph) {
	setfillstyle(1, DODGERBLUE);
	bar(processingArea.x1 + 1, processingArea.y1 + 1, processingArea.x2 - 1, processingArea.y2 - 1);
	setlinestyle(0, 0, 2);
	for (int i = 0; i < graph.numberNode; ++i) {
		string s = graph.node[i]->name;
		CreateNode(graph.node[i]->x, graph.node[i]->y, (char*)s.c_str(), WHITE, DODGERBLUE);
	}
	for (int i = 0; i < graph.numberNode; ++i) {
		for(int j = 0; j < graph.numberNode; j++){
			if(graph.type[i][j] == 1){
				string value = ToStringLen2(graph.adj[i][j]);
				CreateLine(graph.node[i], graph.node[j], (char*)value.c_str(), WHITE);
			}
			else if(graph.type[i][j] == 2){
				string value = ToStringLen2(graph.adj[i][j]);
				CreateCurved(graph.node[i], graph.node[j], (char*)value.c_str(), WHITE);
			}
		}
	}
	DrawWeightMatrix(graph);
}
void DrawGraphTopo(Graph &graph) {
	setfillstyle(1, DODGERBLUE);
	setbkcolor(DODGERBLUE);
	bar(processingArea.x1 + 1, processingArea.y1 + 1, processingArea.x2 - 1, processingArea.y2 - 1);
	setlinestyle(0, 0, 2);
	for (int i = 0; i < graph.numberNode; ++i) {
		string s = graph.node[i]->name;
		CreateNode(graph.node[i]->x, graph.node[i]->y, (char*)s.c_str(), WHITE, DODGERBLUE);
	}
	string empty = "";
	for (int i = 0; i < graph.numberNode; ++i) {
		for(int j = 0; j < graph.numberNode; j++){
			if(graph.type[i][j] == 1){
				CreateLine(graph.node[i], graph.node[j], (char*)empty.c_str(), WHITE);
			}
			else if(graph.type[i][j] == 2){
				CreateCurved(graph.node[i], graph.node[j], (char*)empty.c_str(), WHITE);
			}
		}
	}
}
void DrawEdge(Graph &graph, int idx1, int idx2, int color){
	if(graph.type[idx1][idx2] == 1){
		string value = ToStringLen2(graph.adj[idx1][idx2]);
		CreateLine(graph.node[idx1], graph.node[idx2], (char*)value.c_str(), color);
	}
	else if(graph.type[idx1][idx2] == 2){
		string value = ToStringLen2(graph.adj[idx1][idx2]);
		CreateCurved(graph.node[idx1], graph.node[idx2], (char*)value.c_str(), color);
	}
}
void DeleteEdge(Graph &graph, int x1, int y1, int x2, int y2, int index1, int index2) {
	if (index1 != index2) {
		if (graph.adj[index1][index2]) {
			string empty = "     ";
			if (graph.type[index1][index2] == 1) 
				CreateLine(graph.node[index1], graph.node[index2], (char*)empty.c_str(), DODGERBLUE);
			else if (graph.type[index1][index2] == 2) 
				CreateCurved(graph.node[index1], graph.node[index2], (char*)empty.c_str(), DODGERBLUE);
			graph.adj[index1][index2] = 0;
			graph.type[index1][index2] = 0;
			// DrawGraph(graph);
		}
	}
}
void DeleteVertex(Graph &graph, int x, int y, int index) {
	string empty = "      ";
	for (int row = 0; row < graph.numberNode; ++row) {
		if (graph.adj[row][index]) {
			if (graph.type[row][index] == 1) {
				CreateLine(graph.node[row], graph.node[index], (char*)empty.c_str(), DODGERBLUE);
			} else if (graph.type[row][index] == 2) {
				CreateCurved(graph.node[row], graph.node[index], (char*)empty.c_str(), DODGERBLUE);
			}
		}
	}
	for (int col = 0; col < graph.numberNode; ++col) {
		if (graph.adj[index][col]) {
			if (graph.type[index][col] == 1) {
				CreateLine(graph.node[index], graph.node[col], (char*)empty.c_str(), DODGERBLUE);
			} else if (graph.type[index][col] == 2) {
				CreateCurved(graph.node[index], graph.node[col], (char*)empty.c_str(), DODGERBLUE);
			}
		}
	}
	CreateNode(x, y, (char*)empty.c_str(), DODGERBLUE, DODGERBLUE);
	// xoa dinh -> xoa node trong mang node
	for (int i = index; i < graph.numberNode - 1; ++i)
		graph.node[i] = graph.node[i + 1];
	graph.node[graph.numberNode - 1] = NULL;
	// xoa cot
	for (int i = index; i < graph.numberNode - 1; ++i) {
		for (int j = 0; j < graph.numberNode; ++j) {
			graph.adj[j][i] = graph.adj[j][i + 1]; 
			graph.type[j][i] = graph.type[j][i + 1];
		}
	} 
	for (int i = 0; i < graph.numberNode; ++i) 
		graph.adj[i][graph.numberNode - 1] = graph.type[i][graph.numberNode - 1] = 0; 
	// xoa hang
	for (int i = index; i < graph.numberNode - 1; ++i) {
		for (int j = 0; j < graph.numberNode - 1; ++j) {
			graph.adj[i][j] = graph.adj[i + 1][j];
			graph.type[i][j] = graph.type[i + 1][j];
		}
	}
	for (int i = 0; i < graph.numberNode - 1; ++i)
		graph.adj[graph.numberNode - 1][i] = graph.type[graph.numberNode - 1][i] = 0;
	graph.numberNode--;
	// DrawGraph(graph);
}
void Move(Graph &graph, int x1, int y1, int x2, int y2, int index) {
	// xoa nut hien tai
	string empty = "      ";
	for (int row = 0; row < graph.numberNode; ++row) {
		if (graph.adj[row][index]) {
			if (graph.type[row][index] == 1) {
				CreateLine(graph.node[row], graph.node[index], (char*)empty.c_str(), DODGERBLUE);
			} else if (graph.type[row][index] == 2) {
				CreateCurved(graph.node[row], graph.node[index], (char*)empty.c_str(), DODGERBLUE);
			}
		}
	}
	for (int col = 0; col < graph.numberNode; ++col) {
		if (graph.adj[index][col]) {
			if (graph.type[index][col] == 1) {
				CreateLine(graph.node[index], graph.node[col], (char*)empty.c_str(), DODGERBLUE);
			} else if (graph.type[index][col] == 2) {
				CreateCurved(graph.node[index], graph.node[col], (char*)empty.c_str(), DODGERBLUE);
			}
		}
	}
	CreateNode(x1, y1, (char*)empty.c_str(), DODGERBLUE, DODGERBLUE);
	graph.node[index]->x = x2, graph.node[index]->y = y2;
	// DrawGraph(graph);
}
void EffectAlgorithm(Button button, int colorbk, int colortext, int colorborder){
	setlinestyle(0, 0, 3);
	setcolor(WHITE);
	rectangle(button.x1, button.y1, button.x2 - 1, button.y2 - 1);
	setlinestyle(0, 0, 2);
	setcolor(colorbk);
	setbkcolor(colorbk);
	setfillstyle(1, colorbk);
	bar(button.x1 + 1, button.y1, button.x2 - 2, button.y2 - 2);
	setcolor(colortext);
	outtextxy(button.x1 + ((button.x2 - button.x1) - textwidth((char*)button.name.c_str()))/2, button.y1 + ((button.y2 - button.y1) - textheight((char*)button.name.c_str()))/2, (char*)button.name.c_str());
}
void EffectToolbar(Button button, int colorbk, int colortext, int colorborder){
	setlinestyle(0, 0, 3);
	setcolor(WHITE);
	rectangle(button.x1, button.y1, button.x2 - 1, button.y2 - 1);
	setlinestyle(0, 0, 2);
	setcolor(colorbk);
	setbkcolor(colorbk);
	setfillstyle(1, colorbk);
	bar(button.x1 + 1, button.y1, button.x2 - 2, button.y2 - 2);
	setcolor(colortext);
	outtextxy(button.x1 + ((button.x2 - button.x1) - textwidth((char*)button.name.c_str()))/2, button.y1 + ((button.y2 - button.y1) - textheight((char*)button.name.c_str()))/2, (char*)button.name.c_str());
}
void DrawButton(bool isRunningTopo = false){
	DrawToolBar();
	DrawMenuTable();
	if(isRunningTopo == true) DrawTopoButton();
}
void DrawTopoButton(){	
	setfillstyle(1, DARKAQUA);
	bar(topoSortButton.x1-1, topoSortButton.y1-1, topoSortButton.x2+1, topoSortButton.y2+1);
	DrawButtonForAlgorithm(wanttolearnButton);
	DrawButtonForAlgorithm(havelearnedButton);
	DrawButtonForAlgorithm(startButton);
	DrawButtonForAlgorithm(endButton);
}
void ShowSelectedList(string havelearned[], string wanttolearn[]){
	Button haveLearned, wantToLearn;
	haveLearned.name = "Have Learned", haveLearned.x1 = 10, haveLearned.y1 = 440, haveLearned.x2 = 206, haveLearned.y2 = maxy - 10;
	wantToLearn.name = "Want To Learn", wantToLearn.x1 = 206, wantToLearn.y1 = 440, wantToLearn.x2 = 402, wantToLearn.y2 = maxy - 10;
	setfillstyle(1, DODGERBLUE);
	bar(matrixArea.x1, matrixArea.y1, matrixArea.x2, matrixArea.y2);
	setlinestyle(0, 0, 3);
	setcolor(DARKAQUA);
	rectangle(haveLearned.x1, haveLearned.y1 - 40, haveLearned.x2, haveLearned.y2);
	rectangle(wantToLearn.x1, wantToLearn.y1, wantToLearn.x2, wantToLearn.y2);
	rectangle(matrixArea.x1, matrixArea.y1, matrixArea.x2, matrixArea.y1 + 40);
	settextstyle(10, HORIZ_DIR, 2);
	setcolor(WHITE);
	setbkcolor(DODGERBLUE);
	outtextxy(endButton.x1 + (126 - textwidth((char*)endButton.name.c_str()))/2, endButton.y1 + (36 - textheight((char*)endButton.name.c_str()))/2, (char*)endButton.name.c_str());
	outtextxy(haveLearned.x1 + (196 - textwidth((char*)haveLearned.name.c_str()))/2, haveLearned.y1 - 40 + (40 - textheight((char*)haveLearned.name.c_str()))/2, (char*)haveLearned.name.c_str());
	outtextxy(wantToLearn.x1 + (196 - textwidth((char*)wantToLearn.name.c_str()))/2, wantToLearn.y1 - 40 + (40 - textheight((char*)wantToLearn.name.c_str()))/2, (char*)wantToLearn.name.c_str());
	for(int i=0; i<MAXN; i++){
		outtextxy(haveLearned.x1 + (196 - textwidth((char*)havelearned[i].c_str()))/2, haveLearned.y1 + 3 + i*(textheight((char*)havelearned[i].c_str())), (char*)havelearned[i].c_str());
		outtextxy(wantToLearn.x1 + (196 - textwidth((char*)wanttolearn[i].c_str()))/2, wantToLearn.y1 + 3 + i*(textheight((char*)wanttolearn[i].c_str())), (char*)wanttolearn[i].c_str());	
	}
}
