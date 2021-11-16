#pragma once
bool RunningToolbar(Graph &graph, string fileName, int &x, int &y, bool isOpenSave){
	string nameNode;
	bool isFirstSave = true, isRunningTopo = false;
	Button upButton;
	upButton.x1 = helpArea.x2 - 22, upButton.y1 = helpArea.y1 + 1, upButton.x2 = helpArea.x2 - 2, upButton.y2 = helpArea.y1 + 20;
	Button downButton;
	downButton.x1 = helpArea.x2 - 22, downButton.y1 = helpArea.y2 - 22, downButton.x2 = helpArea.x2 - 2, downButton.y2 = helpArea.y2 - 2;
	Button scrollbar;
	int nextx, nexty, dist = 0, range = 0;
	int scrollbarArea = downButton.y1 - upButton.y2;
	int thumbHeight, jump, firstPosition;
	bool isHover = false, showResult = false, showScrollbar = false;
	WordWrap word(22);
	gtnew:	
	DrawButton();
	int numberHavelearned=0, numberWanttolearn=0;
	string havelearned[MAXN], wanttolearn[MAXN];
	bool isChoose[MAXN], isHaveLearned[MAXN], isWantToLearn[MAXN];
	for(int i=0; i<MAXN; i++){
		havelearned[i] = wanttolearn[i] = "";
		isChoose[i] = isHaveLearned[i] = isWantToLearn[i] = false;
	}
	NotificationFull("Chon chuc nang");
	while(true){
		if(kbhit()){
			char key = getch();
			if (!(key && key != 224) && showScrollbar) {
				char ex = getch();
				if (ex == KEY_UP) 
					goto upbutton;
				if (ex == KEY_DOWN)
					goto downbutton;
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			action:
			if(CheckClickButton(closeButton, x, y)){
				exit:
				DrawButton(isRunningTopo);
				EffectToolbar(closeButton, BLACK, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				if(isOpenSave == true){
					OpenSave(graph, fileName);
					return false;
				}
				else{
					NewSave(graph, fileName, isFirstSave);
					return false;
				}
			}
			else if(CheckClickButton(saveButton, x, y)){
				DrawButton(isRunningTopo);
				EffectToolbar(saveButton, GREEN, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				if(isOpenSave == true){
					OpenSave(graph, fileName);
					goto gtnew;
				}
				else{
					NewSave(graph, fileName, isFirstSave);
					goto gtnew;
				}
			}
			else if(CheckClickButton(topoSortButton, x, y)){
				if(isRunningTopo){
					reChoose:
					if(CheckClickButton(havelearnedButton, x, y)){
						DrawButton(true);
						EffectAlgorithm(havelearnedButton, GREEN, WHITE, BLACK);
						reC1:
						clearmouseclick(WM_LBUTTONDOWN);
						ShowSelectedList(havelearned, wanttolearn);
						while(true){
							if(kbhit())
								ClearBuffer();
							if(ismouseclick(WM_LBUTTONDOWN)){
								getmouseclick(WM_LBUTTONDOWN, x, y);
								if(CheckClickButton(processingArea, x, y)){
									for(int i=0; i<graph.numberNode; i++){
										if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y)){
											if(isChoose[i] == false){
												EffectVertex(graph, i, LIGHTWHITE, WHITE, false);
												havelearned[numberHavelearned] = graph.node[i]->name;
												isChoose[i] = true;
												isHaveLearned[i] = true;
												numberHavelearned++;
												goto reC1;
											}
											else{
												if(isHaveLearned[i] == true){
													isHaveLearned[i] = false;
													isChoose[i] = false;
													for(int j=0; j<numberHavelearned; j++){
														if(havelearned[j] == graph.node[i]->name){
															setfillstyle(1, DODGERBLUE);
															fillellipse(graph.node[i]->x, graph.node[i]->y, 25, 25);
															CreateNode(graph.node[i]->x, graph.node[i]->y, graph.node[i]->name, WHITE, DODGERBLUE);
															for(int k = j; k < numberHavelearned - 1; k++){
																havelearned[k] = havelearned[k+1];
															}
															havelearned[numberHavelearned - 1] = "";
															numberHavelearned--;
															goto reC1;
														}
													}
												}
											}
										}
									}
									goto reC1;
								}
								else if(CheckClickButton(topoSortButton, x, y)) goto reChoose;
								else if(CheckClickButton(closeButton, x, y)) goto exit;
							}
						}
					}
					else if(CheckClickButton(wanttolearnButton, x, y)){
						DrawButton(true);
						EffectAlgorithm(wanttolearnButton, GREEN, WHITE, BLACK);
						reC2:
						clearmouseclick(WM_LBUTTONDOWN);
						ShowSelectedList(havelearned, wanttolearn);
						while(true){
							if(kbhit())
								ClearBuffer();
							if(ismouseclick(WM_LBUTTONDOWN)){
								getmouseclick(WM_LBUTTONDOWN, x, y);
								if(CheckClickButton(processingArea, x, y)){
									for(int i=0; i<graph.numberNode; i++){
										if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y)){
											if(isChoose[i] == false){
												EffectVertex(graph, i, COLOR(184,134,11), WHITE, false);
												wanttolearn[numberWanttolearn] = graph.node[i]->name;
												isChoose[i] = true;
												isWantToLearn[i] = true;
												numberWanttolearn++;
												goto reC2;
											}
											else{
												if(isWantToLearn[i] == true){
													isWantToLearn[i] = false;
													isChoose[i] = false;
													for(int j=0; j<numberWanttolearn; j++){
														if(wanttolearn[j] == graph.node[i]->name){
															setfillstyle(1, DODGERBLUE);
															fillellipse(graph.node[i]->x, graph.node[i]->y, 25, 25);
															CreateNode(graph.node[i]->x, graph.node[i]->y, graph.node[i]->name, WHITE, DODGERBLUE);
															for(int k = j; k < numberWanttolearn - 1; k++){
																wanttolearn[k] = wanttolearn[k+1];
															}
															wanttolearn[numberWanttolearn - 1] = "";
															numberWanttolearn--;
															goto reC2;
														}
													}
												}
											}
										}
									}
									goto reC2;
								}
								else if(CheckClickButton(topoSortButton, x, y)) goto reChoose;
								else if(CheckClickButton(closeButton, x, y)) goto exit;
							}
						}
					}
					else if(CheckClickButton(startButton, x, y)){
						if(numberHavelearned == 0 && numberWanttolearn == 0) goto reChoose;
						else{
							DrawButton(true);
							EffectAlgorithm(startButton, GREEN, WHITE, BLACK);
							if (showResult) {
								setfillstyle(1, DODGERBLUE);
								bar(helpArea.x1 + 1, helpArea.y1 + 1, helpArea.x2 - 1, helpArea.y2 - 1);
							}
							TopoSort(graph, havelearned, numberHavelearned, wanttolearn, numberWanttolearn, word, helpArea);
							showResult = true;
							if (showResult) {
								scrollbar.x1 = upButton.x1, scrollbar.y1 = upButton.y2, scrollbar.x2 = upButton.x2;
								UpdateValue(word, scrollbarArea, scrollbar, thumbHeight, jump, firstPosition);
								if (word.size > word.linePerPage) {
									showScrollbar = true;
									range = 0;
									DrawResult(upButton, downButton, scrollbar);
								} else {
									showScrollbar = false;
								}
								word.PrintPage(true, helpArea, DODGERBLUE);
							}
						}
					}
					else if(CheckClickButton(endButton, x, y)){
						DrawButton(true);
						EffectAlgorithm(endButton, GREEN, WHITE, BLACK);
						isRunningTopo = false;
						setfillstyle(1, DODGERBLUE);
						OpenSaveTopo(graph, "topo/testtopo.txt");
						bar(processingArea.x1 + 1, processingArea.y1 + 1, processingArea.x2 - 1, processingArea.y2 - 1);
						Graph g;
						graph = g;
						DrawButton();
						DrawMatrix();
						goto gtnew;
					}
				}
				else{
					topo:
					DrawButton(isRunningTopo);
					EffectAlgorithm(topoSortButton, GREEN, WHITE, BLACK);
					if(isRunningTopo) DrawGraphTopo(graph);
					else DrawGraph(graph);
					if(isOpenSave == true){
						OpenSave(graph, fileName);
					}
					else{
						NewSave(graph, fileName, isFirstSave);
					}
					isRunningTopo = true;
					Graph g;
					graph = g;
					setfillstyle(1, DODGERBLUE);
					bar(processingArea.x1 + 1, processingArea.y1 + 1, processingArea.x2 - 1, processingArea.y2 - 1);
					char path[] = "topo/testtopo.txt";
					ReadGraphTopo(path, graph);
					DrawGraphTopo(graph);
					DrawTopoButton();
					ShowSelectedList(havelearned, wanttolearn);
				}
			}
			else if(CheckClickButton(algorithmArea, x, y) && isRunningTopo == false){
				if(graph.numberNode == 0){
					NotificationFull("Do thi rong!");
				}
				else{
					RunningAlgorithm(graph, x, y, word, helpArea, upButton, downButton, scrollbar, showResult);
					if (showResult) {
						scrollbar.x1 = upButton.x1, scrollbar.y1 = upButton.y2, scrollbar.x2 = upButton.x2;
						UpdateValue(word, scrollbarArea, scrollbar, thumbHeight, jump, firstPosition);
						if (word.size > word.linePerPage) {
							showScrollbar = true;
							range = 0;
							DrawResult(upButton, downButton, scrollbar);
						} else {
							showScrollbar = false;
						}
						word.PrintPage(true, helpArea, DODGERBLUE);
					}
				}
			} 
			else if (CheckClickButton(scrollbar, x, y) && showResult && showScrollbar) {
				isHover = true;
                dist = y - scrollbar.y1;
			} 
			else if (CheckClickButton(upButton, x, y) && showResult && showScrollbar) {
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
				DrawScrollbar(scrollbar, COLOR(192, 192, 192));
				word.PrintPage(false, helpArea, DODGERBLUE);
			}
			else if (CheckClickButton(downButton, x, y) && showResult && showScrollbar) {
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
				DrawScrollbar(scrollbar, COLOR(192, 192, 192));
				word.PrintPage(true, helpArea, DODGERBLUE);
			} 
			else if(CheckClickButton(newButton, x, y) && isRunningTopo == false){
				DrawButton(isRunningTopo);
				EffectToolbar(newButton, GREEN, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				if(isOpenSave == true){
					OpenSave(graph, fileName);
				} 
				else{
					NewSave(graph, fileName, isFirstSave);
				}
				isOpenSave = false;	
				isFirstSave = true;			
				Graph g;
				graph = g;
				setfillstyle(1, DODGERBLUE);
				bar(processingArea.x1 + 1, processingArea.y1 + 1, processingArea.x2 - 1, processingArea.y2 - 1);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				goto gtnew;
			}
			else if(CheckClickButton(openButton, x, y) && isRunningTopo == false){
				DrawButton(isRunningTopo);
				EffectToolbar(openButton, GREEN, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				if(isOpenSave == true){
					OpenSave(graph, fileName);
				}
				else{
					NewSave(graph, fileName, isFirstSave);
				}

				Graph g;
				graph = g;
				setfillstyle(1, DODGERBLUE);
				bar(processingArea.x1 + 1, processingArea.y1 + 1, processingArea.x2 - 1, processingArea.y2 - 1);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				string nameFile = OpenScreen();
				nameFile = "saves/" + nameFile;
				ReadFile((char*)nameFile.c_str(), graph);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				isOpenSave = true;
				isFirstSave = false;
				goto gtnew;
			}
			else if(CheckClickButton(addVertexButton, x, y)){//Nhan nut AddVerTex
				DrawButton(isRunningTopo);
				EffectToolbar(addVertexButton, GREEN, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				addV:
				clearmouseclick(WM_LBUTTONDOWN);
				if(graph.numberNode < 14){
					NotificationFull("Click vao vung trong de them dinh hoac doi ten!");
					while(true){
						if(kbhit())
							ClearBuffer();
						if(ismouseclick(WM_LBUTTONDOWN)){
							getmouseclick(WM_LBUTTONDOWN, x, y);
							if(CheckClickButton(realProcessingArea, x, y)){
								if(CheckReClickNode(graph, x, y)){//rename
									string nameNode = "";
									for(int i=0; i < graph.numberNode; i++){
										if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y)){
											setcolor(BLACK);
											setlinestyle(0, 0, 3);
											circle(graph.node[i]->x, graph.node[i]->y, 25);
											setcolor(WHITE);
											setlinestyle(0, 0, 2);
											if(isRunningTopo == false){
												nameNode = AddNameWeight("ten dinh");
												Rename(graph.node[i]->x, graph.node[i]->y, nameNode);
												while(CheckName(graph, nameNode) == false){
													nameNode = AddNameWeight("ten dinh");
												}
											}
											else {
												nameNode = AddNameTopo();
												Rename(graph.node[i]->x, graph.node[i]->y, nameNode);
												while(CheckName(graph, nameNode) == false){
													nameNode = AddNameTopo();
												}
											}
											Rename(graph.node[i]->x, graph.node[i]->y, nameNode);
											graph.node[i]->name = nameNode;
											goto addV;
										}
									}
								}
								else if(CheckPos(graph, x, y)){//them moi
									AddNode(graph, x, y, nameNode, isRunningTopo);
									if(isRunningTopo){
										while(CheckName(graph, nameNode) == false){
											nameNode = AddNameTopo();
											Rename(x, y, nameNode);
										}
									}
									else{
										while(CheckName(graph, nameNode) == false){
											nameNode = AddNameWeight("ten dinh");
											Rename(x, y, nameNode);
										}
									}
									Node *n = new Node(nameNode, x, y);
									graph.node[graph.numberNode] = n;
									graph.numberNode++;
									if(isRunningTopo) DrawGraphTopo(graph);
									else DrawGraph(graph);
									goto addV;
								}
								else goto addV;
							}
							else if(CheckClickButton(closeButton, x, y)) goto exit;
							else if(CheckClickButton(toolbarArea, x, y) || CheckClickButton(algorithmArea, x, y)) goto action;
							else if(CheckClickButton(topoSortButton, x, y)){
								if(isRunningTopo) goto reChoose;
								else goto topo;
							}
							else goto addV;
						}
					}	
				}
				else{
					NotificationFull("Do thi da day!");
					goto gtnew;
				}
			}

			else if(CheckClickButton(addEdgeButton, x, y)){//Nhan nut AddEdge
				DrawButton(isRunningTopo);
				EffectToolbar(addEdgeButton, GREEN, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				if(graph.numberNode < 2){
					NotificationFull("So luong dinh khong du. Moi them dinh!");
				}
				else{
					reClick:
					int start = 0;
					bool flag = true;
					NotificationFull("Click vao hai dinh de them cung hoac thay doi trong so cua cung!");
					while(true){
						if(kbhit())
							ClearBuffer();
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if(x != -1 && y != -1){
							if(CheckClickButton(processingArea, x, y)){
								for(int i=0; i<graph.numberNode; i++){
									if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y)){
										setcolor(BLACK);
										setlinestyle(0, 0 , 3);
										circle(graph.node[i]->x, graph.node[i]->y, 25);
										setcolor(WHITE);
										setlinestyle(0, 0, 2);
										start = i;
										flag = false;
										break;
									}
								}
								if(flag == true) goto reClick;
								else{
									int idx1 = start;
									NotificationFull("Click vao dinh cuoi!");
									int idx2 = ChooseVertex(graph, x, y);
									string value;
									if(isRunningTopo) value = "";
									else
										value = AddNameWeight("trong so");
									if(graph.adj[idx1][idx2] == 0 && graph.adj[idx2][idx1] != 0) {
										CreateCurved(graph.node[idx1], graph.node[idx2], (char*)value.c_str(), WHITE);
										graph.type[idx1][idx2] = 2;
									}
									else if(graph.adj[idx1][idx2] == 0 && graph.adj[idx2][idx1] == 0){
										CreateLine(graph.node[idx1], graph.node[idx2], (char*)value.c_str(), WHITE);
										graph.type[idx1][idx2] = 1;
									}
									else if(graph.adj[idx1][idx2] != 0){
										DrawEdge(graph, idx1, idx2, WHITE);
									}													
									graph.adj[idx1][idx2] = (value[0]-'0')*10+(value[1]-'0');
									if(isRunningTopo) DrawGraphTopo(graph);
									else DrawGraph(graph);
									goto reClick;
								}
							}
							else{
								if(CheckClickButton(closeButton, x, y)) goto exit;
								else if(CheckClickButton(toolbarArea, x, y) || CheckClickButton(algorithmArea, x, y)) goto action;
								else if(CheckClickButton(topoSortButton, x, y)){
									if(isRunningTopo) goto reChoose;
									else goto topo;
								}
								else goto gtnew;
							} 	
						}
					}
				}																			
			}
			else if(CheckClickButton(moveButton, x, y)){//Nhan nut Move
				DrawButton(isRunningTopo);
				EffectToolbar(moveButton, GREEN, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				if(graph.numberNode < 1){
					NotificationFull("Do thi rong. Hay them dinh!");
				}
				else{
					move:
					NotificationFull("Click vao dinh can di chuyen!");
					int x1 = 0, y1 = 0, x2 = 0, y2 = 0, idx = -1;
					while(true){//Bat phim dau
						if(kbhit()) 
							ClearBuffer();
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if(x != -1 && y != -1){
							if(CheckClickButton(processingArea, x, y)){
								string nameNode="";
								bool isOpenSave = true;
								for(int i=0; i<graph.numberNode; i++){
									if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y)){
										x1 = graph.node[i]->x;
										y1 = graph.node[i]->y;
										idx = i;
										nameNode = graph.node[i]->name;
										setcolor(BLACK);
										setlinestyle(0, 0, 3);
										circle(graph.node[i]->x, graph.node[i]->y, 25);
										isOpenSave = false;
										break;
									}
								}
								if(isOpenSave == true) goto move;
								else{
									movee:
									NotificationFull("HAY CLICK VAO VI TRI CAN DI CHUYEN TOI!");
									while(1){
										if (kbhit()) {}
										getmouseclick(WM_LBUTTONDOWN, x, y);
										if(x != -1 && y != -1){
											if((graph.node[idx]->x - x)*(graph.node[idx]->x - x) + (graph.node[idx]->y - y)*(graph.node[idx]->y - y) <= 100*100){
												x2 = x;
												y2 = y;
												break;
											}
											else{
												if(CheckPos(graph, x, y)){
													x2 = x;
													y2 = y;
													break;
												}
												else{
													goto movee;//nhap lai noi can den 
												}	
											}
										}	
									}
									Move(graph, x1, y1, x2, y2, idx);
									if(isRunningTopo) DrawGraphTopo(graph);
									else DrawGraph(graph);
									goto move;
								}
							}
							else{
								if(CheckClickButton(closeButton, x, y)) goto exit;
								if(CheckClickButton(toolbarArea, x, y) || CheckClickButton(algorithmArea, x, y)) goto action;
								else if(CheckClickButton(topoSortButton, x, y)){
									if(isRunningTopo) goto reChoose;
									else goto topo;
								}
								else goto gtnew;
							}
						}
					}
				}
			}
			else if(CheckClickButton(deleteVertexButton, x, y)){// xoa dinh
				DrawButton(isRunningTopo);
				EffectToolbar(deleteVertexButton, GREEN, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				delV:
				NotificationFull("HAY CLICK VAO DINH CAN XOA!");
				int idx;
				bool flag = true;
				while(true){//Bat phim dau
					if(kbhit())
						ClearBuffer();
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if(x != -1 && y != -1){
						if(CheckClickButton(processingArea, x, y)){
							for(int i=0; i<graph.numberNode; i++){
								if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y)){
									setcolor(BLACK);
									setlinestyle(0, 0, 3);
									circle(graph.node[i]->x, graph.node[i]->y, 25);
									x = graph.node[i]->x;
									y = graph.node[i]->y;
									idx = i;
									flag = false;
									break;
								}
							}
							if(flag == true){
								goto delV;
							}
							else{
								int idx1 = x, idx2 = y;
								delay(1000);
								DeleteVertex(graph, idx1, idx2, idx);
								if(isRunningTopo) DrawGraphTopo(graph);
									else DrawGraph(graph);
								goto delV;
							}
						}
						else{
							if(CheckClickButton(closeButton, x, y)) goto exit;
							else if(CheckClickButton(toolbarArea, x, y) || CheckClickButton(algorithmArea, x, y)) goto action;
							else if(CheckClickButton(topoSortButton, x, y)){
								if(isRunningTopo) goto reChoose;
								else goto topo;
							}
							else goto gtnew;
						}
					}
				}
			}
			else if(CheckClickButton(deleteEdgeButton, x, y)){//xoa canh
				DrawButton(isRunningTopo);
				EffectToolbar(deleteEdgeButton, GREEN, WHITE, BLACK);
				if(isRunningTopo) DrawGraphTopo(graph);
				else DrawGraph(graph);
				if(graph.numberNode < 2){
					NotificationFull("Do thi khong co canh de xoa!");
				}
				else{
					delS:
					NotificationFull("Hay click vao dinh bat dau!");
					int x1, y1, x2, y2, idx1, idx2;
					while(true){//Bat phim dau
						if(kbhit())
							ClearBuffer();
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if(x != -1 && y != -1){
							if(CheckClickButton(processingArea, x, y)){
								bool flag = true;
								for(int i=0; i < graph.numberNode; i++){
									if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y)){
										x1 = graph.node[i]->x;
										y1 = graph.node[i]->y;
										idx1 = i;
										setcolor(BLACK);
										setlinestyle(0, 0, 3);
										circle(graph.node[i]->x, graph.node[i]->y, 25);
										flag = false;
										break;
									}
								}
								if(flag == true) goto delS;
								else{
									delE:
									NotificationFull("Hay click vao dinh cuoi!");
									while(!kbhit()){
										getmouseclick(WM_LBUTTONDOWN, x, y);
										if(x != -1 && y != -1){
											bool flag = true;
											for(int i=0; i < graph.numberNode; i++){
												if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y) && graph.node[i]->x != x1 && graph.node[i]->y != y1){
													x2 = graph.node[i]->x;
													y2 = graph.node[i]->y;
													idx2 = i;
													setcolor(BLACK);
													setlinestyle(0, 0, 3);
													circle(graph.node[i]->x, graph.node[i]->y, 25);
													flag = false;
													break;
												}
											}	
											if(flag == true){
												goto delE;
											}
											else{
												DeleteEdge(graph, x1, y1, x2, y2, idx1, idx2);
												if(isRunningTopo) DrawGraphTopo(graph);
												else DrawGraph(graph);
												goto delS;
											}
										}	
									}
								}
							}
							else{
								if(CheckClickButton(closeButton, x, y)) goto exit;
								else if(CheckClickButton(toolbarArea, x, y) || CheckClickButton(algorithmArea, x, y)) goto action;
								else if(CheckClickButton(topoSortButton, x, y)){
									if(isRunningTopo) goto reChoose;
									else goto topo;
								}
								else goto gtnew;
							}
						}
					}
				}
			}
		} 
		if (ismouseclick(WM_LBUTTONUP)) {
			if (isHover == true && showResult && showScrollbar) {
				isHover = false;
			}
			clearmouseclick(WM_LBUTTONUP);
		}
		if (ismouseclick(WM_MOUSEMOVE)) {
			if (isHover == true && showResult) {
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
                DrawScrollbar(scrollbar, COLOR(192, 192, 192));
                if (!changed) {
                    if (rangeAfter > range) range++;
                    else if (rangeAfter < range) range--;
                }
                if (rangeAfter > currRange) {
                    word.PrintPage(true, helpArea, DODGERBLUE);
                } else if (rangeAfter < currRange) {
                    word.PrintPage(false, helpArea, DODGERBLUE);
                }
			}
			clearmouseclick(WM_MOUSEMOVE);
		}
	}
}
void RunningAlgorithm(Graph graph, int x, int y, WordWrap &word, Button helpArea, Button upButton, Button downButton, Button scrollbar, bool &showResult){
	setfillstyle(1, DODGERBLUE);
	bar(helpArea.x1 + 1, helpArea.y1 + 1, helpArea.x2 - 1, helpArea.y2);
	if(CheckClickButton(dfsButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(dfsButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		showResult = true;
		NotificationFull("Hay click vao dinh bat dau!");
		int start = ChooseVertex(graph, x, y);
		NotificationFull("Bat dau thuat toan!");
		DFS(graph, start, word, helpArea);
	}
	else if(CheckClickButton(bfsButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(bfsButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		showResult = true;
		NotificationFull("Hay click vao dinh bat dau!");
		int start = ChooseVertex(graph, x, y);
		NotificationFull("Bat dau thuat toan!");
		BFS(graph, start, word, helpArea);
	}
	else if(CheckClickButton(shortestPathButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(shortestPathButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		if(graph.numberNode < 2) {
			NotificationFull("Do thi chua du dinh de thuc hien thuat toan!");
		}
		else{
			showResult = true;
			NotificationFull("Hay click vao dinh bat dau!");
			int start = ChooseVertex(graph, x, y);
			NotificationFull("Hay click vao dinh ket thuc!");
			int end = ChooseVertex(graph, x, y);
			while(end == start){
				end = ChooseVertex(graph, x, y);
			}
			NotificationFull("Bat dau thuat toan!");
			Dijkstra(graph, start, end, word, helpArea);
		}
	}
	else if(CheckClickButton(ComponentButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(ComponentButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		showResult = true;
		SCC(graph, word, helpArea);
	}
	else if(CheckClickButton(hamiltonButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(hamiltonButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		showResult = true;
		NotificationFull("Hay click vao dinh bat dau!");
		int start = ChooseVertex(graph, x, y);
		HamCycle(graph, word, helpArea, start);
	}
	else if(CheckClickButton(eulerButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(eulerButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		showResult = true;
		NotificationFull("Hay click vao dinh bat dau!");
		int start = ChooseVertex(graph, x, y);
		EulerCycle(graph, word, helpArea, start);
	}
	else if(CheckClickButton(dinhTruButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(dinhTruButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		showResult = true;
		ArticulationPoint(graph, word, helpArea);	
	}
	else if(CheckClickButton(dinhThatButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(dinhThatButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		if (graph.numberNode < 2) {
			NotificationFull("Do thi chua du dinh de thuc hien thuat toan!");	
		} else {
			showResult = true;
			NotificationFull("Hay click vao dinh bat dau!");
			int start = ChooseVertex(graph, x, y);
			NotificationFull("Hay click vao dinh ket thuc!");
			int end = ChooseVertex(graph, x, y);
			while(end == start){
				end = ChooseVertex(graph, x, y);
			}
			KnotPoint(graph, start, end, word, helpArea); 
		}	
	}
	else if(CheckClickButton(bridgeEdgeButton, x, y)){
		DrawButton(false);
		EffectAlgorithm(bridgeEdgeButton, GREEN, WHITE, BLACK);
		DrawGraph(graph);
		showResult = true;
		BridgeEdge(graph, word, helpArea);	
	}
}
int ChooseVertex(Graph graph, int &x, int &y){
	int start = 0;
	bool flag = true;
	reClick:
	while(true){
		if(kbhit())
			ClearBuffer();
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(x != -1 && y != -1){
			if(CheckClickButton(processingArea, x, y)){
				for(int i=0; i<graph.numberNode; i++){
					if(CheckNode(graph.node[i]->x, graph.node[i]->y, x, y)){
						setcolor(BLACK);
						setlinestyle(0, 0 , 3);
						circle(graph.node[i]->x, graph.node[i]->y, 25);
						setcolor(WHITE);
						setlinestyle(0, 0, 2);
						start = i;
						flag = false;
						break;
					}
				}
				if(flag == true) goto reClick;
				else break;
			}
			else goto reClick;
		}
	}
	return start;
}
void OpenSave(Graph &graph, string nameFile){
	int x = -1, y = -1;
	NotificationFull("Ban co muon luu lai khong?");
	DrawButtonForNoti(continueButton);
	DrawButtonForNoti(cancelButton);
	while(true){
		if(kbhit())
			ClearBuffer();
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(x != -1 && y != -1){
			if(CheckClickButton(continueButton, x, y)){
				WriteFile((char*)nameFile.c_str(), graph);
				setfillstyle(1, DODGERBLUE);
				bar(helpArea.x1, helpArea.y1, helpArea.x2, helpArea.y2);
				return;
			}
			else if(CheckClickButton(cancelButton, x, y)){
				setfillstyle(1, DODGERBLUE);
				bar(helpArea.x1, helpArea.y1, helpArea.x2, helpArea.y2);
				return;
			} 
		}
	}
}
void OpenSaveTopo(Graph &graph, string nameFile){
	int x = -1, y = -1;
	NotificationFull("Ban co muon luu lai khong?");
	DrawButtonForNoti(continueButton);
	DrawButtonForNoti(cancelButton);
	while(true){
		if(kbhit())
			ClearBuffer();
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(x != -1 && y != -1){
			if(CheckClickButton(continueButton, x, y)){
				WriteGraphTopo((char*)nameFile.c_str(), graph);
				setfillstyle(1, DODGERBLUE);
				bar(helpArea.x1, helpArea.y1, helpArea.x2, helpArea.y2);
				return;
			}
			else if(CheckClickButton(cancelButton, x, y)){
				setfillstyle(1, DODGERBLUE);
				bar(helpArea.x1, helpArea.y1, helpArea.x2, helpArea.y2);
				return;
			} 
		}
	}
}
void NewSave(Graph &graph, string &nameFile, bool &isFirstSave){
	int x = -1, y = -1;
	NotificationFull("Ban co muon luu lai khong?");
	DrawButtonForNoti(continueButton);
	DrawButtonForNoti(cancelButton);
	while(true){
		if(kbhit())
			ClearBuffer();
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(x != -1 && y != -1){
			if(CheckClickButton(continueButton, x, y)){
				if(isFirstSave == true){
					reAddName:
					nameFile = AddFileName();
					if(!nameFile.empty()){
						nameFile = "saves/" + nameFile;
						nameFile += ".txt";
						ofstream graphFile((char*)nameFile.c_str());
						graphFile.close();
						WriteFile((char*)nameFile.c_str(), graph);
						isFirstSave = false;
						return;
					}
					else goto reAddName;
				}
				else {
					WriteFile((char*)nameFile.c_str(), graph);
					setfillstyle(1, DODGERBLUE);
					bar(helpArea.x1, helpArea.y1, helpArea.x2, helpArea.y2);
					return;
				}
			}
			else if(CheckClickButton(cancelButton, x, y)){
				setfillstyle(1, DODGERBLUE);
				bar(helpArea.x1, helpArea.y1, helpArea.x2, helpArea.y2);
				return;
			} 
		}
	}
}
void EffectVertex(Graph graph, int u, int colorbk, int colortext, bool isDelay=true){
	if(isDelay) delay(500);
	setcolor(colorbk);
	setbkcolor(colorbk);
	setfillstyle(1, colorbk);
	fillellipse(graph.node[u]->x, graph.node[u]->y, 25, 25);
	CreateNode(graph.node[u]->x, graph.node[u]->y, (char*)graph.node[u]->name.c_str(), colortext, colorbk);
	setcolor(colorbk);
	circle(graph.node[u]->x, graph.node[u]->y, 25);
}
void EffectEdge(Graph graph, int u, int v, int color, bool isDelay = true){
	if(isDelay) delay(500);
	string value = ToStringLen2(graph.adj[u][v]);
	if (graph.type[u][v] == 1) {
		CreateLine(graph.node[u], graph.node[v], (char*)value.c_str(), color);
	}				
	else if (graph.type[u][v] == 2) {
		CreateCurved(graph.node[u], graph.node[v], (char*)value.c_str(), color);
	}
}
void DFS(Graph graph, int start, WordWrap &word, Button helpArea){
	WordWrap wordTemp(22);
	word = wordTemp;
	string noti = "Thu tu duyet: ";
	word.StoreString(noti, helpArea);
	bool isVisited[MAXN];
	int tick[MAXN][MAXN];
	for(int i=0; i<graph.numberNode; i++){
		isVisited[i] = false;
		for(int j = 0; j<graph.numberNode; j++){
			tick[i][j] = 0;
		}
	}
	Stack st;
	st.push(start);
	noti = "";
	noti += graph.node[start]->name + ", ";
	EffectVertex(graph, start, COLOR(220,20,60), WHITE);				
	isVisited[start] = true;
	while(!st.empty()){
		int u;
		st.pop(u);
		for(int v = 0; v < graph.numberNode; v++){
			if(graph.adj[u][v] != 0 && isVisited[v] == false) {
				noti += graph.node[v]->name + ", ";
				st.push(u);
				st.push(v);
				tick[u][v] = 1;
				isVisited[v] = true;
				EffectVertex(graph, u, COLOR(210,105,30), WHITE);
				EffectVertex(graph, u, COLOR(220,20,60), WHITE);				
				EffectEdge(graph, u, v, COLOR(220,20,60));
				EffectVertex(graph, v, COLOR(220,20,60), WHITE);
				break;
			}
			else if(graph.adj[u][v] != 0 && isVisited[v] == true && tick[u][v] == 0){
				tick[u][v] = 1;
				EffectVertex(graph, u, COLOR(210,105,30), WHITE);
				EffectVertex(graph, u, COLOR(220,20,60), WHITE);				
				EffectEdge(graph, u, v, BLACK);
			}
		}
	}
	noti.erase(noti.end()-2, noti.end());
	word.StoreString(noti, helpArea);
	NotificationFull(noti);
}
void BFS (Graph graph, int start, WordWrap &word, Button helpArea){
	bool isVisited[MAXN];
	int tick[MAXN][MAXN];
	WordWrap wordTemp(22);
	word = wordTemp;
	string noti = "Thu tu duyet: "; 
	word.StoreString(noti, helpArea);
	for(int i=0; i<graph.numberNode; i++){
		isVisited[i] = false;
		for(int j = 0; j<graph.numberNode; j++){
			tick[i][j] = 0;
		}
	}
	Queue q;
	q.push(start);
	isVisited[start] = true;
	EffectVertex(graph, start, COLOR(220,20,60), WHITE);				
	noti = "";
	while(!q.empty()) {
		int u;
		q.pop(u);	
		noti += graph.node[u]->name + ", ";
		for (int v = 0; v < graph.numberNode; v++) {
			if (graph.adj[u][v] != 0 && isVisited[v] == false) {
				q.push(v);
				isVisited[v] = true;
				tick[u][v] = 1;
				EffectVertex(graph, u, COLOR(210,105,30), WHITE);
				EffectVertex(graph, u, COLOR(220,20,60), WHITE);				
				EffectEdge(graph, u, v, COLOR(220,20,60));
				EffectVertex(graph, v, COLOR(220,20,60), WHITE);
			}
			else if(graph.adj[u][v] != 0 && isVisited[v] == true && tick[u][v] == 0){
				tick[u][v] = 1;
				EffectVertex(graph, u, COLOR(210,105,30), WHITE);
				EffectVertex(graph, u, COLOR(220,20,60), WHITE);				
				EffectEdge(graph, u, v, BLACK);
			}
		}
	}
	noti.erase(noti.end() - 2, noti.end());
	word.StoreString(noti, helpArea);
	NotificationFull(noti);
}
//////////////////////////////////////_Thanh phan lien thong manh_ ///////////////////////////////////////
void SCCHelp(int u, int &time, int &count, int disc[], int low[], bool stackMember[], Stack &stack, Stack ans[], Graph graph) {
	disc[u] = low[u] = ++time;
	stack.push(u);
	stackMember[u] = true;
	int v;
	for (v = 0; v < graph.numberNode; ++v) {
		if (graph.adj[u][v]) {
			if (disc[v] == -1) {
				SCCHelp(v, time, count, disc, low, stackMember, stack, ans, graph);
				low[u] = min(low[u], low[v]);
			} else if (stackMember[v]) {
				low[u] = min(low[u], disc[v]);
			}
		}
	}
	if (low[u] == disc[u]) {
		int w;
		do {
			stack.pop(w);
			ans[count].push(w);
			stackMember[w] = false;
		} while(w != u);
		count++;
	}
}
void SCC(Graph graph, WordWrap &word, Button helpArea){
	int disc[MAXN];
	int low[MAXN];
	bool stackMember[MAXN];
	Stack stack;
	int count = 0, time = 0;
	WordWrap wordTemp(22);
	word = wordTemp;
	for (int i = 0; i < graph.numberNode; ++i) {
		disc[i] = -1;
		low[i] = -1;
		stackMember[i] = false;
	}
	Stack ans[MAXN];
	for (int i = 0; i < graph.numberNode; ++i) 
		if (disc[i] == -1)
			SCCHelp(i, time, count, disc, low, stackMember, stack, ans, graph);
	int v, currColor = 2;
	string res = "Co " + ToString(count) + " thanh phan lien thong manh:";
	word.StoreString(res, helpArea);
	for (int i = 0; i < count; ++i) {
		res = "";
		if (currColor == WHITE) currColor++;
		setfillstyle(1, currColor);
		while(!ans[i].empty()) {
			ans[i].pop(v);
			EffectVertex(graph, v, currColor, WHITE, false);
			res += graph.node[v]->name + ", ";
			setbkcolor(DODGERBLUE);
		}
		res.resize(res.length() - 2);
		word.StoreString(res, helpArea);
		currColor++;
	}
}	
/////////////////////////////////////////////////////////////////Dijkstra/////////////////////////////////////////////////////////////////////////////////
int minDistance(int distance[], bool tick[], int V){
	int min = INT_MAX, minIndex = -1;
	for(int i=0; i<V; i++) {
		if(min >= distance[i] && tick[i] == false){
			min = distance[i];
			minIndex = i;
		}
	}
	return minIndex;
}	
void Dijkstra(Graph graph, int start, int end, WordWrap &word, Button helpArea){
	WordWrap wordTemp(22);
	word = wordTemp;
	bool tick[graph.numberNode];
	int distance[graph.numberNode];
	int parent[graph.numberNode];
	for(int i=0; i<graph.numberNode; i++){
		tick[i] = false;
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
	distance[start] = 0;
	parent[start] = start;
	for(int count = 0; count < graph.numberNode - 1; count++){
		int u = minDistance(distance, tick, graph.numberNode);
		tick[u] = true;
		for(int v = 0; v < graph.numberNode; v++){
			if(tick[v] == false && graph.adj[u][v] && distance[u] != INT_MAX && distance[u] + graph.adj[u][v] < distance[v]){
				distance[v] = distance[u] + graph.adj[u][v];
				parent[v] = u;
			}
		}
	}
	if(distance[end] == INT_MAX){
		string noti = "Khong ton tai duong di tu dinh " + graph.node[start]->name + " den dinh " + graph.node[end]->name + "!";
		word.StoreString(noti, helpArea);
	}
	else{
		string noti = "Duong di ngan nhat tu " + graph.node[start]->name + " den " + graph.node[end]->name + " la: ";
		word.StoreString(noti, helpArea);
		if(parent[end] != -1 && distance[end] != INT_MAX){
			int answer = distance[end];
			int listAns[graph.numberNode];
			int sizeListAns=0;
			Stack ans;
			ans.push(end);

			while(end != start){
				ans.push(parent[end]);
				end = parent[end];
			}
			while(ans.empty() == false){
				int t = -1;
				ans.pop(t);
				listAns[sizeListAns] = t;
				sizeListAns++;
			}
			noti = "";
			for(int i=0; i<sizeListAns; i++){
				noti += graph.node[listAns[i]]->name + " -> "; 
			} 
			noti.erase(noti.end() - 4, noti.end());
			word.StoreString(noti, helpArea);
			noti = "Tong trong so nho nhat: " + ToString(answer);
			word.StoreString(noti, helpArea);
			if(sizeListAns > 0){
				for(int i=0; i<sizeListAns; i++){
					if(i>0){	
						EffectEdge(graph, listAns[i-1], listAns[i], BLACK);
					}
					EffectVertex(graph, listAns[i], GREEN, WHITE);
				}
			}
		}
	}
}

/////////////////////// Dinh that ////////////////////////////
bool dfsCheck(Graph g, int u, int v) {
    bool vis[MAXN];
    for (int i = 0; i < g.numberNode; ++i) vis[i] = false;
    Stack stack;
    stack.push(u);
    vis[u] = true;
    int numCheckedVertex = 0;
    while(!stack.empty()) {
        int start;
        stack.pop(start);
        if (start == v) return 1;
        ++numCheckedVertex;
        for (int i = 0; i < g.numberNode; ++i) 
            if (!vis[i] && g.adj[start][i]) {
                vis[i] = true;
                stack.push(i);
            }
    }
    return (numCheckedVertex == g.numberNode);
}
bool IsConnected(Graph g, int u, int v) {
    bool vis[MAXN];
    for (int i = 0; i < g.numberNode; ++i) vis[i] = false;
    Queue q;
    q.push(u);
    vis[u] = true;
    while(!q.empty()) {
        int t;
        q.pop(t);
        for (int i = 0; i < g.numberNode; ++i) {
            if (g.adj[t][i] && !vis[i]) {
                q.push(i);
                vis[i] = true;
                /// neu nut i = v thi co lien thong //////////
                if (i == v)
                    return true;
            }
        }
    }
    return false;
}
void KnotPoint(Graph graph, int u, int v, WordWrap &word, Button helpArea) {
	WordWrap wordTemp(22);
	word = wordTemp;
	string ans = "";
	if (graph.adj[u][v] || !dfsCheck(graph, u, v)) {
		ans = "Khong co dinh that (Ton tai duong di truc tiep / Khong co duong di)!";
		word.StoreString(ans, helpArea);
		return;
	}
    int temp[MAXN][MAXN];
    int res[MAXN];
    int index = 0;
    for (int i = 0; i < graph.numberNode; ++i) 
        for (int j = 0; j < graph.numberNode; ++j)
            temp[i][j] = graph.adj[i][j];
    for (int i = 0; i < graph.numberNode; ++i) {
        ///////////////////// loai bo dinh /////////////////////
        for (int j = 0; j < graph.numberNode; ++j) 
            graph.adj[j][i] = graph.adj[i][j] = 0;
        // kiem tra co duong di tu u den v hay ko//////////////
        if (!IsConnected(graph, u, v)) 
            if (i != u && i != v) 
                res[index++] = i;
        // khoi phuc lai trang thai truoc do///////////////////
        for (int j = 0; j < graph.numberNode; ++j) 
            graph.adj[j][i] = temp[j][i], graph.adj[i][j] = temp[i][j];
    }
    if (index == 0) {
		ans = "Khong co dinh that giua " + ToString(u) + " va " + ToString(v) + "!";
		word.StoreString(ans, helpArea);
	} else {
		ans = "Co " + ToString(index) + " dinh that giua " + ToString(u) + " va " + ToString(v) + ": ";
		word.StoreString(ans, helpArea);
		ans = "";
		for (int i = 0; i < index; ++i){
			ans += graph.node[res[i]]->name + ", ";
			EffectVertex(graph, res[i], GREEN, WHITE, false);
			setbkcolor(DODGERBLUE);
		}
		ans.erase(ans.end() - 2, ans.end());
		word.StoreString(ans, helpArea);
	}
}
///////////////////////////////////////////////////////////////

// /////////////////////Chu trinh Euler///////////////////////////
bool IsEulerCircuit(Graph g) {
    if(CountSCCs(g, 0) > 1) return false; 
    int inWards[MAXN], outWards[MAXN];
    for (int i = 0; i < MAXN; ++i)
        inWards[i] = outWards[i] = 0;
    int sum = 0;
    for (int u = 0; u < g.numberNode; ++u) {
        sum = 0;
        for (int v = 0; v < g.numberNode; ++v) {
            if (g.adj[u][v]) {
                inWards[v]++;
                sum++;
            }
        }
        outWards[u] = sum;
    }
    for (int i = 0; i < g.numberNode; ++i)
        if (inWards[i] != outWards[i])
            return false;
    return true;
}
void EulerCycle(Graph graph, WordWrap &word, Button helpArea, int start) {
    string ans;
	WordWrap wordTemp(22);
	word = wordTemp;
    if (!IsEulerCircuit(graph)) {
		ans = "Khong ton tai chu trinh Euler";
		word.StoreString(ans, helpArea);
        return;
    }
    Stack stack;
    int countEdge = 0;
    for (int u = 0; u < graph.numberNode; ++u) 
        for (int v = 0; v < graph.numberNode; ++v) 
            if (graph.adj[u][v])
                countEdge++;
    int temp[MAXN][MAXN];
    for (int u = 0; u < graph.numberNode; ++u) 
        for (int v = 0; v < graph.numberNode; ++v)
            temp[u][v] = graph.adj[u][v];
    int path[MAXN + 1];
    stack.push(start);
    int index = 0;
    while(!stack.empty()) {
        int s;
        stack.pop(s);
        stack.push(s);
        bool isEmpty = true;
        int t;
        for (t = 0; t < graph.numberNode; ++t) {
            if (temp[s][t]) {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty == false) {
            stack.push(t);
            temp[s][t] = 0;
        } else {
            stack.pop(s);
            path[index++] = s;
        }
    }
	ans = "Ton tai chu trinh Euler: ";
	word.StoreString(ans, helpArea);
	ans = "";
    for (int i = index - 1; i >= 0; --i){
		if(i < index - 1){	
			delay(500);
			string value = ToStringLen2(graph.adj[path[i+1]][path[i]]);
			if (graph.type[path[i+1]][path[i]] == 1) {
				CreateLine(graph.node[path[i+1]], graph.node[path[i]], (char*)value.c_str(), BLACK);
			}				
			else if (graph.type[path[i+1]][path[i]] == 2) {
				CreateCurved(graph.node[path[i+1]], graph.node[path[i]], (char*)value.c_str(), BLACK);
			}
		}
		EffectVertex(graph, path[i], GREEN, WHITE);
		ans += graph.node[path[i]]->name + " -> ";
	}
	ans.erase(ans.end() - 4, ans.end());
	word.StoreString(ans, helpArea);
}
// ///////////////////////////////////////////////////////////////

// /////////////////// Chu trinh Hamilton /////////////////////////////////
/* Ham kiem tra xem dinh 'v' co the them vao vi tri 'pos' 
trong chu trinh hamilton duoc hay khong */
bool IsSafe(int v, Graph g, int path[], int count[], int pos) {
	// path luu danh sach dinh the hien chu trinh hamilton
    /* Kiem tra dinh hien tai co phai la dinh lien ke 
        cua dinh truoc do hay khong */ 
    if (!g.adj[path[pos - 1]][v]) return false;
    /* Kiem tra dinh da co truoc do hay chua*/
    if (count[v] > 1) return false;
    return true;
}
bool RecursiveHam(Graph g, int path[], int count[], int pos) {
    /* Kiem tra neu toan bo cac dinh da duoc tham*/
    if (pos == g.numberNode) {
        /* Va kiem tra xem co canh noi tu dinh cuoi den
            dinh dau trong 'path' hay khong*/
        if (g.adj[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }
    for (int v = 0; v < g.numberNode; ++v) {
        if (IsSafe(v, g, path, count, pos)) {
            path[pos] = v;
			count[v]++;
            if (RecursiveHam(g, path, count, pos + 1))
                return true;
            path[pos] = -1;
			count[v]--;
        }
    }
    return false;
}
void HamCycle(Graph graph, WordWrap &word, Button helpArea, int start) { 
    int path[MAXN];
    int count[MAXN];
    for (int i = 0; i < graph.numberNode; ++i) {
        path[i] = -1;
        count[i] = 0;
    }
    path[0] = start;
    count[start] = 1;
	WordWrap wordTemp(22);
	word = wordTemp;
	string ans;
    if (RecursiveHam(graph, path, count, 1) == false) {
		ans = "Khong ton tai chu trinh Hamilton";
		word.StoreString(ans, helpArea);
        return;
    } 
	ans = "Ton tai chu trinh Hamilton: ";
	word.StoreString(ans, helpArea);
	path[graph.numberNode] = start;
	ans = "";
    for (int i = 0; i <= graph.numberNode; ++i){
		if(i > 0){	
			delay(500);	
			string value = ToStringLen2(graph.adj[path[i-1]][path[i]]);
			if (graph.type[path[i-1]][path[i]] == 1) {
				CreateLine(graph.node[path[i-1]], graph.node[path[i]], (char*)value.c_str(), BLACK);
			}				
			else if (graph.type[path[i-1]][path[i]] == 2) {
				CreateCurved(graph.node[path[i-1]], graph.node[path[i]], (char*)value.c_str(), BLACK);
			}
		}
		EffectVertex(graph, path[i], GREEN, WHITE);
		ans += graph.node[path[i]]->name + " -> ";
	}
	ans.erase(ans.end() - 4, ans.end());
	word.StoreString(ans, helpArea);
}
// ////////////////////////////////////////////////////////////////////////

/////////////////////_Cac ham ho tro cho canh cau va dinh that_//////////////////////////////////////////////////////////////////////////			
void SCCTravel(int u, int &time, int &count, int disc[], int low[], bool stackMember[], Stack &stack, Graph graph) {
	disc[u] = low[u] = ++time;
	stack.push(u);
	stackMember[u] = true;
	int v;
	for (v = 0; v < graph.numberNode; ++v) {
		if (graph.adj[u][v]) {
			if (disc[v] == -1) {
				SCCTravel(v, time, count, disc, low, stackMember, stack, graph);
				low[u] = min(low[u], low[v]);
			} else if (stackMember[v]) {
				low[u] = min(low[u], disc[v]);
			}
		}
	}
	if (low[u] == disc[u]) {
		int w;
		do {
			stack.pop(w);
			stackMember[w] = false;
		} while(w != u);
		count++;
	}
}
int CountSCCs(Graph graph, int start) {
	int disc[MAXN];
	int low[MAXN];
	bool stackMember[MAXN];
	Stack stack;
	for (int i = 0; i < graph.numberNode; ++i)
		low[i] = disc[i] = -1, stackMember[i] = false;
	if (start != -1) {
		disc[start] = 0;
		stackMember[start] = true;
	}
	int count = 0, time = 0;  
	for (int i = 0; i < graph.numberNode; ++i) 
		if (disc[i] == -1) 
			SCCTravel(i, time, count, disc, low, stackMember, stack, graph);
	return count;
}
////////////////////////////////////////////////////////////////////////////

///////////////////////////////Canh cau/////////////////////////////////
void BridgeEdge(Graph graph, WordWrap &word, Button helpArea) {
    int numComponents = CountSCCs(graph, -1);
    int count = 0, edges = 0;
    for (int i = 0; i < graph.numberNode; ++i) 
        for (int j = 0; j < graph.numberNode; ++j)
            if (graph.adj[i][j])
                edges++;
    int bridgeEdges[MAXN * MAXN][2];
    for (int i = 0; i < graph.numberNode; ++i) {
        for (int j = 0; j < graph.numberNode; ++j) {
            if (graph.adj[i][j]) {
                int value = graph.adj[i][j];
                // Loai bo canh
                graph.adj[i][j] = 0;
                // Dem so thanh phan lien thong sau khi da cat canh
                int numComAfterRemove = CountSCCs(graph, -1);
                // Khoi phuc lai ban dau
                graph.adj[i][j] = value;
                if (numComAfterRemove > numComponents) {
                    bridgeEdges[count][0] = i;
                    bridgeEdges[count][1] = j;
                    count++;
                }
            }
        }
    }
	WordWrap wordTemp(22);
	word = wordTemp;
	string ans = "";
    if (count == 0) {
		ans = "Khong ton tai canh cau manh!";
		word.StoreString(ans, helpArea);
    } else {
		ans = "Co " + ToString(count) + " canh cau manh:";
		word.StoreString(ans, helpArea);
		ans = "";
        for (int i = 0; i < count; ++i) {
        	ans += "(" + graph.node[bridgeEdges[i][0]]->name + ", " + graph.node[bridgeEdges[i][1]]->name + ") ";
			string value = ToStringLen2(graph.adj[bridgeEdges[i][0]][bridgeEdges[i][1]]);
			if (graph.type[bridgeEdges[i][0]][bridgeEdges[i][1]] == 1) {
				CreateLine(graph.node[bridgeEdges[i][0]], graph.node[bridgeEdges[i][1]], (char*)value.c_str(), BLACK);
			}				
			else if (graph.type[bridgeEdges[i][0]][bridgeEdges[i][1]] == 2) {
				CreateCurved(graph.node[bridgeEdges[i][0]], graph.node[bridgeEdges[i][1]], (char*)value.c_str(), BLACK);
			}
		}
		word.StoreString(ans, helpArea);
    }
}
////////////////////////////////////////////////////////////////////////

///////////////////////////////Dinh Tru/////////////////////////////////
void ArticulationPoint(Graph graph, WordWrap &word, Button helpArea) {
    int numberComponents = CountSCCs(graph, -1);
    int count = 0;
    int vertex[MAXN];
    int temp[MAXN][MAXN];
    for (int i = 0; i < graph.numberNode; ++i) 
        for (int j = 0; j < graph.numberNode; ++j)
            temp[i][j] = graph.adj[i][j];
    for (int i = 0; i < graph.numberNode; ++i) {
        // Xoa dinh
        for (int j = 0; j < graph.numberNode; ++j)
            graph.adj[i][j] = graph.adj[j][i] = 0;
        int numComAfterRemove = CountSCCs(graph, i);
        // Khoi phuc
        for (int j = 0; j < graph.numberNode; ++j)
            graph.adj[i][j] = temp[i][j],graph.adj[j][i] = temp[j][i];
        if (numComAfterRemove > numberComponents)
            vertex[count++] = i;
    }
	WordWrap wordTemp(22);
	word = wordTemp;
	string ans;
    if (count == 0) {
		ans = "Do thi khong co dinh tru manh!";
		word.StoreString(ans, helpArea);
    } else {
		ans = "Do thi co " + ToString(count) + " dinh tru manh:";
		word.StoreString(ans, helpArea);
		ans = "";
        for (int i = 0; i < count; ++i){
			EffectVertex(graph, vertex[i], GREEN, WHITE, false);
			ans += graph.node[vertex[i]]->name + ", ";
		}
		ans.erase(ans.end() - 2, ans.end());
		word.StoreString(ans, helpArea);
    }
}
////////////////////////////////////////////////////////////////////////

//////////////////////////////Topo Sort///////////////////////////////////
bool CheckDAG(Graph graph, int topoOrder[], bool degZero[]) {
	int inDegree[MAXN];
	for (int i = 0; i < MAXN; ++i)
		inDegree[i] = 0;
	for (int i = 0; i < graph.numberNode; ++i)
		for (int j = 0; j < graph.numberNode; ++j)
			if (graph.adj[i][j]) 
				inDegree[j]++;
	Queue queue;
	for (int i = 0; i < graph.numberNode; ++i)
		if (inDegree[i] == 0) {
			queue.push(i);
			degZero[i] = true;
		}
	int cnt = 0, u, v;
	while(!queue.empty()) {
		queue.pop(u);
		topoOrder[cnt++] = u;
		for (v = 0; v < graph.numberNode; ++v) {
			if (graph.adj[u][v]) {
				if (--inDegree[v] == 0)
					queue.push(v);
			}
		} 
	}
	if (cnt != graph.numberNode)
		return false;
	else 
		return true;
}
void TopoSort(Graph graph, string haveLearned[], int numHaveLearned, string wantToLearn[], int numWantToLearn, WordWrap &word, Button helpArea) {
	int topoOrder[MAXN];
	bool degZero[MAXN];
	for (int i = 0; i < MAXN; ++i)	
		topoOrder[i] = -1, degZero[i] = false;
	string ans = "";
	WordWrap wordTemp(22);
	word = wordTemp;
	if (!CheckDAG(graph, topoOrder, degZero)) {
		ans = "Do thi ton tai chu trinh!";
		word.StoreString(ans, helpArea);
		return;
	}
	bool checked[MAXN];
	int IDHaveLearned[MAXN], IDWantToLearn[MAXN];
	for (int i = 0; i < MAXN; ++i) 
		checked[i] = false, IDHaveLearned[i] = IDWantToLearn[i] = -1;
	for (int i = 0; i < numHaveLearned; ++i) {
		int j;
		for (j = 0; j < graph.numberNode; ++j)
			if (graph.node[j]->name == haveLearned[i])
				break;
		IDHaveLearned[i] = j;
		checked[j] = true;
	}
	for (int i = 0; i < numWantToLearn; ++i) {
		int j;
		for (j = 0; j < graph.numberNode; ++j) 
			if (graph.node[j]->name == wantToLearn[i])
				break;
		IDWantToLearn[i] = j;
	}
	int cnt = 0, index1, index2, u, v;
	for (int i = 0; i < numWantToLearn; ++i) {
		if (degZero[IDWantToLearn[i]]) {
			EffectVertex(graph, IDWantToLearn[i], GREEN, WHITE, false);
			cnt++;
			continue;
		}
		for (index1 = 0; index1 < graph.numberNode; ++index1)
			if (topoOrder[index1] == IDWantToLearn[i])
				break;
		v = topoOrder[index1];
		for (index2 = 0; index2 < index1; ++index2) {
			u = topoOrder[index2];
			if (graph.adj[u][v] && checked[u]) {
				cnt++;
				EffectVertex(graph, v, GREEN, WHITE, false);
				break;
			}
		}
		if (index2 == index1) {
			EffectVertex(graph, v, BLACK, WHITE, false);
			ans = "Mon " + wantToLearn[i] + " khong dang ky duoc vi mon ";
			for (int u = 0; u < graph.numberNode; ++u) {
				if (graph.adj[u][v] && !checked[u]) {
					ans += graph.node[u]->name + " hoac ";
				}
			}
			ans.erase(ans.end() - 5, ans.end());
			ans += "chua duoc hoc!";
			word.StoreString(ans, helpArea);
		}
	}
	if (cnt == numWantToLearn) {
		ans = "Da dang ky xong!";
		word.StoreString(ans, helpArea);
	}
}
