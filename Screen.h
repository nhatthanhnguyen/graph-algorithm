void DisableMinimizeButton (HWND hwnd){
 	SetWindowLong (hwnd, GWL_STYLE,
               GetWindowLong (hwnd, GWL_STYLE) & ~ WS_MINIMIZEBOX);
}
void DisableMaximizeButton (HWND hwnd){
 	SetWindowLong (hwnd, GWL_STYLE,
               GetWindowLong (hwnd, GWL_STYLE) & ~ WS_MAXIMIZEBOX);
}
void DisableCloseButton (HWND hwnd){
 	EnableMenuItem (GetSystemMenu (hwnd, FALSE), SC_CLOSE,
                MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
}
void CreateScreen(){
	initwindow(1209, 813);
	HWND hwnd = GetActiveWindow();
	if(hwnd) SetWindowText(hwnd, "Graph");
	DisableMaximizeButton(hwnd);
	DisableMinimizeButton(hwnd);
	// DisableCloseButton(hwnd);
	setbkcolor(AQUA);
	setlinestyle(0, 0, 10);
	cleardevice();
	CreateButton();
	//ve khung man hinh
	setcolor(COLOR(0,76,153));
	rectangle(0, 0, maxx, maxy);
	setlinestyle(0, 0, 2);
	setfillstyle(1, DARKAQUA);
	bar(processingArea.x1 - 7, processingArea.y1 - 7, processingArea.x2 - 7, processingArea.y2 - 7);
	setfillstyle(1, DODGERBLUE);
	bar(processingArea.x1, processingArea.y1, processingArea.x2, processingArea.y2);	
	DrawToolBar();
	DrawMenuTable();
	DrawMatrix();
}
void CreateButton (){
	matrixArea.name = "", matrixArea.x1 = 11, matrixArea.y1 = 400, matrixArea.x2 = 402, matrixArea.y2 = maxy - 10;
	toolbarArea.name = "", toolbarArea.x1 = 10, toolbarArea.y1 = 10, toolbarArea.x2 = 1190, toolbarArea.y2 = 52;
	newButton.name = "New", newButton.x1 = 10, newButton.y1 = 10, newButton.x2 = 155, newButton.y2 = 52;
	openButton.name = "Open", openButton.x1 = 155, openButton.y1 = 10, openButton.x2 = 300, openButton.y2 = 52;
	saveButton.name = "Save", saveButton.x1 = 300, saveButton.y1 = 10, saveButton.x2 = 445, saveButton.y2 = 52;
	addVertexButton.name = "AddVertex", addVertexButton.x1 = 445, addVertexButton.y1 = 10, addVertexButton.x2 = 590, addVertexButton.y2 = 52;
	addEdgeButton.name = "AddEdge", addEdgeButton.x1 = 590, addEdgeButton.y1 = 10, addEdgeButton.x2 = 735, addEdgeButton.y2 = 52;
	moveButton.name = "Move", moveButton.x1 = 735, moveButton.y1 = 10, moveButton.x2 = 880, moveButton.y2 = 52;
	deleteVertexButton.name = "DelVertex", deleteVertexButton.x1 = 880, deleteVertexButton.y1 = 10, deleteVertexButton.x2 = 1025, deleteVertexButton.y2 = 52;
	deleteEdgeButton.name = "DelEdge", deleteEdgeButton.x1 = 1025, deleteEdgeButton.y1 = 10, deleteEdgeButton.x2 = 1140, deleteEdgeButton.y2 = 52;
	algorithmArea.name = "", algorithmArea.x1 = 10, algorithmArea.y1 = 58, algorithmArea.x2 = 402, algorithmArea.y2 = 314;                 
	dfsButton.name = "DFS", dfsButton.x1 = 16, dfsButton.y1 = 99, dfsButton.x2 = 139, dfsButton.y2 = 168;
	bfsButton.name = "BFS", bfsButton.x1 = 143, bfsButton.y1 = 99, bfsButton.x2 = 268, bfsButton.y2 = 168;
	shortestPathButton.name = "X=>Y", shortestPathButton.x1 = 272, shortestPathButton.y1 = 99, shortestPathButton.x2 = 397, shortestPathButton.y2 = 168;
	ComponentButton.name = "TPLT", ComponentButton.x1 = 16, ComponentButton.y1 = 172, ComponentButton.x2 = 139, ComponentButton.y2 =241;
	hamiltonButton.name = "Hamilton", hamiltonButton.x1 = 143, hamiltonButton.y1 = 172, hamiltonButton.x2 = 268, hamiltonButton.y2 = 241;
	eulerButton.name = "Euler", eulerButton.x1 = 272, eulerButton.y1 = 172, eulerButton.x2 = 397, eulerButton.y2 = 241;
	dinhTruButton.name = "Dinh tru", dinhTruButton.x1 = 16, dinhTruButton.y1 = 245, dinhTruButton.x2 = 139, dinhTruButton.y2 = 314;
	dinhThatButton.name = "Dinh that", dinhThatButton.x1 = 143, dinhThatButton.y1 = 245, dinhThatButton.x2 = 268, dinhThatButton.y2 = 314;
	bridgeEdgeButton.name = "Canh cau", bridgeEdgeButton.x1 = 272, bridgeEdgeButton.y1 = 245, bridgeEdgeButton.x2 = 397, bridgeEdgeButton.y2 = 314;
	topoSortButton.name = "Topo Sort", topoSortButton.x1 = 16, topoSortButton.y1 = 318, topoSortButton.x2 = 397, topoSortButton.y2 = 391;
	helpArea.name = "", helpArea.x1 = 409, helpArea.y1 = 601, helpArea.x2 = 1190, helpArea.y2 = 790;
	processingArea.name = "", processingArea.x1 = 416, processingArea.y1 = 65, processingArea.x2 = 1190, processingArea.y2 = 595; 
	realProcessingArea.name = "", realProcessingArea.x1 = 446, realProcessingArea.y1 = 95, realProcessingArea.x2 = 1160, realProcessingArea.y2 = 565;
	closeButton.name = "X", closeButton.x1 = 1140, closeButton.y1 = 10, closeButton.x2 = 1190, closeButton.y2 = 52;
	continueButton.name = "Tiep tuc", continueButton.x1 = 411, continueButton.y1 = 696, continueButton.x2 = 800, continueButton.y2 = 788;
	cancelButton.name = "Huy", cancelButton.x1 = 800, cancelButton.y1 = 696, cancelButton.x2 = maxx-10 - 2, cancelButton.y2 = 788 	;
	havelearnedButton.name = "Learned", havelearnedButton.x1 = 14, havelearnedButton.y1 = 318, havelearnedButton.x2 = 139, havelearnedButton.y2 = 391;
	wanttolearnButton.name = "Want learn", wanttolearnButton.x1 = 143, wanttolearnButton.y1 = 318, wanttolearnButton.x2 = 268, wanttolearnButton.y2 = 391;
	startButton.name = "Start", startButton.x1 = 272, startButton.y1 = 318, startButton.x2 = 397, startButton.y2 = 353;
	endButton.name = "End", endButton.x1 = 272, endButton.y1 = 355, endButton.x2 = 397, endButton.y2 = 391;	
}
void DrawButtonForAlgorithm(Button button){
	setlinestyle(0, 0, 2);
	settextstyle(10, HORIZ_DIR, 2);
	setbkcolor(DODGERBLUE);
	setfillstyle(1, DODGERBLUE);
	bar(button.x1, button.y1, button.x2, button.y2);
	setcolor(WHITE);
	outtextxy(button.x1 + ((button.x2 - button.x1) - textwidth((char*)button.name.c_str()))/2, button.y1 + ((button.y2 - button.y1) - textheight((char*)button.name.c_str()))/2, (char*)button.name.c_str());
}
void DrawButtonForToolBar(Button button){
	setlinestyle(0, 0, 3);
	settextstyle(10, HORIZ_DIR, 2);//(font, ngang doc, do dam)
	setcolor(WHITE);
	setbkcolor(DARKAQUA);
	setfillstyle(1, DODGERBLUE);
	setbkcolor(DODGERBLUE);
	bar(button.x1, button.y1, button.x2, button.y2);
	outtextxy(button.x1 + ((button.x2 - button.x1) - textwidth((char*)button.name.c_str()))/2, button.y1 + ((button.y2 - button.y1) - textheight((char*)button.name.c_str()))/2, (char*)button.name.c_str());
	setcolor(DARKAQUA);
	rectangle(button.x1, button.y1, button.x2, button.y2);
	
}
void DrawButtonForNoti(Button button){
	setbkcolor(DODGERBLUE);
	setcolor(DARKAQUA);
	setlinestyle(0, 0, 2);
	settextstyle(10, HORIZ_DIR, 3);//(font, ngang doc, do dam)
	rectangle(button.x1, button.y1, button.x2, button.y2);
	setcolor(BLACK);
	outtextxy(button.x1 + ((button.x2 - button.x1) - textwidth((char*)button.name.c_str()))/2, button.y1 + ((button.y2 - button.y1) - textheight((char*)button.name.c_str()))/2, (char*)button.name.c_str());
}
void DrawToolBar(){
	DrawButtonForToolBar(newButton);
	DrawButtonForToolBar(openButton);
	DrawButtonForToolBar(saveButton);
	DrawButtonForToolBar(addVertexButton);
	DrawButtonForToolBar(addEdgeButton);
	DrawButtonForToolBar(moveButton);
	DrawButtonForToolBar(deleteVertexButton);
	DrawButtonForToolBar(deleteEdgeButton);
	DrawButtonForToolBar(closeButton);
}
void DrawMenuTable(){
	setfillstyle(1, DARKAQUA);
	bar(algorithmArea.x1 + 1, algorithmArea.y1 + 1, algorithmArea.x2, algorithmArea.y2 + 81);
	settextstyle(10, HORIZ_DIR, 3);
	setfillstyle(1, DODGERBLUE);
	bar(algorithmArea.x1, algorithmArea.y1, algorithmArea.x2, algorithmArea.y1 + 37);
	setbkcolor(DODGERBLUE);
	setcolor(BLACK);
	outtextxy(algorithmArea.x1 + ((algorithmArea.x2 - algorithmArea.x1) - textwidth("ALGORITHM"))/2, algorithmArea.y1 + (37 - textheight("ALGORITHM"))/2, "ALGORITHM");
	DrawButtonForAlgorithm(dfsButton);
	DrawButtonForAlgorithm(bfsButton);
	DrawButtonForAlgorithm(shortestPathButton);
	DrawButtonForAlgorithm(ComponentButton);
	DrawButtonForAlgorithm(hamiltonButton);
	DrawButtonForAlgorithm(eulerButton);
	DrawButtonForAlgorithm(dinhTruButton);
	DrawButtonForAlgorithm(dinhThatButton);
	DrawButtonForAlgorithm(bridgeEdgeButton);
	DrawButtonForAlgorithm(topoSortButton);
}
void DrawMatrix(){
	setfillstyle(1, DODGERBLUE);
	bar(matrixArea.x1, matrixArea.y1, matrixArea.x2, matrixArea.y2);
	settextstyle(10, HORIZ_DIR, 3);
	setcolor(BLACK);
	setbkcolor(DODGERBLUE);
	outtextxy(matrixArea.x1 + ((matrixArea.x2 - matrixArea.x1) - textwidth("WEIGHT MATRIX"))/2, matrixArea.y1 + (40 - textheight("WEIGHT MATRIX"))/2, "WEIGHT MATRIX");
	setcolor(DARKAQUA);
	setlinestyle(0, 0, 1);
	for(int j = 0; j < 14; j++){
		for(int i = 0; i < 14; i++){
			rectangle(10 + i * 28, 440 + j * 25, 38 + i * 28, 465 + j * 25);
		}
	}
	setlinestyle(0, 0, 2);
	rectangle(matrixArea.x1 + 1, matrixArea.y1 + 40, matrixArea.x2, matrixArea.y2);
}
void DrawWeightMatrix(Graph &graph){
	DrawMatrix();
	settextstyle(10, HORIZ_DIR, 1);
	setbkcolor(DODGERBLUE);
	for(int i = 0; i < graph.numberNode; i++){ 
		if(graph.numberNode > i){
			setcolor(BLACK);
			outtextxy(14, 441 + (i+1)*25, (char*)graph.node[i]->name.c_str());
			outtextxy(13 + (i+1)*28, 441, (char*)graph.node[i]->name.c_str());
		}
		for(int j = 0; j < graph.numberNode; j++){
			setcolor(WHITE);
			if(graph.adj[i][j] != 0) outtextxy(15 + (j+1)*28, 441 + (i+1)*25, (char*)ToStringLen2(graph.adj[i][j]).c_str());
			else outtextxy(14 + (j+1)*28, 441 + (i+1)*25, "  ");
		}
	}
}
string OpenScreen(){
	Button fileNameButton, propertyButton, exitButton, OpenButton, showFileNameArea, upButton, downButton;
	showFileNameArea.name = "", showFileNameArea.x1 = 510, showFileNameArea.y1 = 148, showFileNameArea.x2 = 1090, showFileNameArea.y2 = 445;
	fileNameButton.name = "", fileNameButton.x1 = 516, fileNameButton.y1 = 499, fileNameButton.x2 = 883, fileNameButton.y2 = 537;
	propertyButton. name = "File text(.txt)", propertyButton.x1 = 890, propertyButton.y1 = 452, propertyButton.x2 = 1083, propertyButton.y2 = 490;
	exitButton.name = "Cancel", exitButton.x1 = 995, exitButton.y1 = 499, exitButton.x2 = 1083, exitButton.y2 = 537;
	OpenButton.name = "Open", OpenButton.x1 = 890, OpenButton.y1 = 499, OpenButton.x2 = 988, OpenButton.y2 = 537;
	// setcolor(BLACK);
	// setlinestyle(0, 0, 1);
	// rectangle(509, 108, 1090, 545);
	setfillstyle(1, COLOR(211,211,211));// mau xam
	bar(510, 109, 1090, 149);//khung cua chu OPEN
	setbkcolor(COLOR(211,211,211));
	setcolor(BLACK);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(519, 108 + (40 - textheight("OPEN"))/2, "OPEN");
	bar(510, 446, 1090, 545);
	//xoa phan help
	setfillstyle(1, DODGERBLUE);
	bar(helpArea.x1 + 1, helpArea.y1 + 1, helpArea.x2 - 1, helpArea.y2 - 1);
	setfillstyle(1, WHITE);
	bar(propertyButton.x1 + 1, propertyButton.y1 + 1, propertyButton.x2, propertyButton.y2);
	bar(OpenButton.x1 + 1, OpenButton.y1 + 1, OpenButton.x2, OpenButton.y2);
	bar(exitButton.x1 + 1, exitButton.y1 + 1, exitButton.x2, exitButton.y2);
	bar(fileNameButton.x1 + 1, fileNameButton.y1 + 1, fileNameButton.x2, fileNameButton.y2);
	settextstyle(10, HORIZ_DIR, 1);
	outtextxy(515, 450, "File name:");
	setbkcolor(WHITE);
	outtextxy(propertyButton.x1 + ((propertyButton.x2 - propertyButton.x1) - textwidth((char*)propertyButton.name.c_str()))/2, propertyButton.y1 + ((propertyButton.y2 - propertyButton.y1) - textheight((char*)propertyButton.name.c_str()))/2, (char*)propertyButton.name.c_str());
	outtextxy(OpenButton.x1 + ((OpenButton.x2 - OpenButton.x1) - textwidth((char*)OpenButton.name.c_str()))/2, OpenButton.y1 + ((OpenButton.y2 - OpenButton.y1) - textheight((char*)OpenButton.name.c_str()))/2, (char*)OpenButton.name.c_str());
	outtextxy(exitButton.x1 + ((exitButton.x2 - exitButton.x1) - textwidth((char*)exitButton.name.c_str()))/2, exitButton.y1 + ((exitButton.y2 - exitButton.y1) - textheight((char*)exitButton.name.c_str()))/2, (char*)exitButton.name.c_str());
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	dirent *entry;
	WordWrap word1(22);
	char path[] = "saves";
	DIR *dir = opendir(path);
	if(dir == NULL) return "";
	else{
		while((entry = readdir(dir)) != NULL){
			string temp(entry->d_name);
			if(temp == "." || temp =="..") continue;
			else{
				word1.StoreString(temp, showFileNameArea);
			}
		}
		closedir(dir);
	}
	bool isOpened = false;
	string ans = "";
	char key;
	WordWrap word(22);
	word = word1;//word 1 luu danh sach tep tin trong thu muc
	label:
	string s = ShowFileName(word, key, ans, showFileNameArea, fileNameButton, OpenButton, exitButton, isOpened);
	if(s == "false") {
		if((key >= 'A' && key <= 'Z') || (key >= 'a' && key <='z') || (key >= '0' && key <= '9') ){
			if(ans.size() < 30)
				ans += key;
		}
		else if(key == 8 && ans.size() > 0){
			ans.resize(ans.length() - 1);//= pop_back()
		}
		outtextxy(fileNameButton.x1 + 5, fileNameButton.y1 + 5, "                                ");
		outtextxy(fileNameButton.x1 + 5, fileNameButton.y1 + 5, (char*)ans.c_str());
		WordWrap wordTemp(22);
		for(int i = 0; i < word1.size; i++){
			if(word1.result[i].substr(0, ans.size()) == ans) {
				wordTemp.StoreString(word1.result[i], showFileNameArea);
			}
		}
		if(wordTemp.size > 0) word = wordTemp;
		else word = word1;
		goto label;
	} 
	else{
		return s;
	}
}
string ShowFileName(WordWrap word, char &key, string ans, Button showFileNameArea, Button fileNameButton, Button OpenButton, Button exitButton, bool &isOpened){
	setfillstyle(1, WHITE);
    bar(showFileNameArea.x1 + 1, showFileNameArea.y1 + 1, showFileNameArea.x2, showFileNameArea.y2 + 1);
	Button upButton;
	upButton.x1 = showFileNameArea.x2 - 20;
	upButton.y1 = showFileNameArea.y1 + 1;
	upButton.x2 = showFileNameArea.x2;
	upButton.y2 = showFileNameArea.y1 + 21;
	Button downButton;
	downButton.x1 = showFileNameArea.x2 - 20;
	downButton.y1 = showFileNameArea.y2 - 20;
	downButton.x2 = showFileNameArea.x2;
	downButton.y2 = showFileNameArea.y2;
	word.PrintPage(true, showFileNameArea, WHITE);
	Button scrollbar;
	scrollbar.x1 = upButton.x1;
	scrollbar.y1 = upButton.y2;
	scrollbar.x2 = upButton.x2;
	int x = -1, y = -1;
	int tempIndex = -1;
	int index = -1;
	int nextx = -1, nexty = -1, dist = 0, range = 0;
	int scrollbarArea = downButton.y1 - upButton.y2;
	int thumbHeight = round(word.linePerPage * scrollbarArea * 1.0 / word.size);
	int jump = round((scrollbarArea - thumbHeight) * 1.0 / (word.size - word.linePerPage)); // buoc nhay cho moi lan bam nut (pixel)
	scrollbar.y2 = scrollbar.y1 + thumbHeight;
	bool isHover = false;
	bool draw = true;
	int firstPosition = scrollbar.y2;
	bool isChoose = false;
	string res = "";
	int chooseIndex = -1;
	if (word.size > word.linePerPage) // neu kich thuoc word > kich thuoc hien thi thi se co thanh cuon
		DrawResult(upButton, downButton, scrollbar);
	else 
		draw = false;
	while(true) {
		if (kbhit()) {
			key = getch();
			if(key && key != 224){
				if((key >= 'A' && key <= 'Z') || (key >= 'a' && key <='z') || (key >= '0' && key <= '9') || key == 8){
					return "false";
				}
			}
			else{
				char ex = getch();
				if (draw) {
					if(ex == KEY_UP){
						goto upbutton;
					}
					if(ex == KEY_DOWN){
						goto downbutton;
					}
				}
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (CheckClickButton(scrollbar, x, y) && draw) {
				isHover = true;
				dist = y - scrollbar.y1;
			}
			if (word.GetIndex(x, y, showFileNameArea) != -1) {
				index = word.GetIndex(x, y, showFileNameArea);
				int x1 = showFileNameArea.x1, y1 = showFileNameArea.y1, x2 = showFileNameArea.x2;	
				int height = textheight((char*)word.result[0].c_str());
				if (tempIndex != -1) {
					if (tempIndex - word.start >= 0 && tempIndex - word.start < word.linePerPage) {
						setfillstyle(1, WHITE);
						int xBoxTop = x1;
						int yBoxTop = y1 + margin + (height + marginLine) * (tempIndex - word.start);
						int xBoxBot = x2 - word.toRight;
						if (!draw)
							xBoxBot = x2 - 1;
						int yBoxBot = yBoxTop + height;
						bar(xBoxTop, yBoxTop, xBoxBot, yBoxBot);
						setbkcolor(WHITE);
						setcolor(BLACK);
						outtextxy(x1 + margin, yBoxTop, (char*)word.result[tempIndex].c_str());
						setbkcolor(WHITE);
					}	
				}	
				setfillstyle(1, GREEN);
				int xBoxTop = x1;
				int yBoxTop = y1 + margin + (height + marginLine) * (index - word.start);
				int xBoxBot = x2 - word.toRight;
				if (!draw) 
					xBoxBot = x2 - 1;
				int yBoxBot = yBoxTop + height;
				bar(xBoxTop, yBoxTop, xBoxBot, yBoxBot);
				setbkcolor(GREEN);
				setcolor(BLACK);
				outtextxy(x1 + margin, yBoxTop, (char*)word.result[index].c_str());
				setbkcolor(WHITE);
				isChoose = true;
				chooseIndex = index;
				tempIndex = index;
			}
			if (CheckClickButton(upButton, x, y) && draw) {
				upbutton:
				DeleteScrollbar(scrollbar);
				if (range == 0) {
					scrollbar.y2 = firstPosition;
				} else {
					range--;
					if (range == 0)
						scrollbar.y2 = firstPosition;
					else 
						scrollbar.y2 = firstPosition + range * jump;
				}
				scrollbar.y1 = scrollbar.y2 - thumbHeight;
				DrawScrollbar(scrollbar, LIGHTGRAY);
				word.PrintPage(false, showFileNameArea, WHITE);
			}
			if (CheckClickButton(downButton, x, y) && draw) {
				downbutton:
				DeleteScrollbar(scrollbar);
				if (range == word.size - word.linePerPage) {
					scrollbar.y2 = downButton.y1;
				} else if (range < word.size - word.linePerPage) {
					range++;
					if (range == word.size - word.linePerPage) 
						scrollbar.y2 = downButton.y1;
					else
						scrollbar.y2 = firstPosition + range * jump;
				}
				scrollbar.y1 = scrollbar.y2 - thumbHeight;
				DrawScrollbar(scrollbar, LIGHTGRAY);
				word.PrintPage(true, showFileNameArea, WHITE);
			}
			if(CheckClickButton(OpenButton, x, y)){
				if(isChoose == true){
					res = word.result[chooseIndex];
					return res;
				}
				else{
					for(int i=0; i<word.size; i++){
						if(word.result[i] == ans + ".txt"){
							res = word.result[i];
							return res;
						} 
					}
				}
			}
			if(CheckClickButton(exitButton, x, y)){
				return "";
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (ismouseclick(WM_LBUTTONUP)) {
			if (isHover == true && draw) {
				isHover = false;
			}
			clearmouseclick(WM_LBUTTONUP);
		}
		if (ismouseclick(WM_MOUSEMOVE)) {
			if (isHover == true && draw) {
				getmouseclick(WM_MOUSEMOVE, nextx, nexty);
				DeleteScrollbar(scrollbar);
				bool changed = false;
                int currRange = range;
                scrollbar.y1 = nexty - dist;
                scrollbar.y2 = scrollbar.y1 + thumbHeight;
                if (scrollbar.y2 > downButton.y1) {
                    scrollbar.y2 = downButton.y1;
                    scrollbar.y1 = scrollbar.y2 - thumbHeight;
                    range = word.size - word.linePerPage;
                    changed = true;
                } else if (scrollbar.y1 < upButton.y2) {
                    scrollbar.y1 = upButton.y2;
                    scrollbar.y2 = scrollbar.y1 + thumbHeight;
                    range = 0;
                    changed = true;
                }
                int after = scrollbar.y2;
                int rangeAfter = round((after - firstPosition) * 1.0 / jump);
                if (rangeAfter > word.size - word.linePerPage) {
                    rangeAfter = word.size - word.linePerPage;
                }
                DrawScrollbar(scrollbar, LIGHTGRAY);
                if (!changed) {
                    if (rangeAfter > range) range++;
                    else if (rangeAfter < range) range--;
                }
                if (rangeAfter > currRange) {
                    word.PrintPage(true, showFileNameArea, WHITE);
                } else if (rangeAfter < currRange) {
                    word.PrintPage(false, showFileNameArea, WHITE);
                }
			}
			clearmouseclick(WM_MOUSEMOVE);
		}	
	}
	return res;
}
void ClearBuffer() {
	while(kbhit()) {
		getch();
	}
}