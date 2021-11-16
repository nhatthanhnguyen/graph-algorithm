#pragma once
Button newButton, openButton, saveButton, addVertexButton, addEdgeButton, moveButton, deleteVertexButton, deleteEdgeButton; 
Button startButton, endButton, havelearnedButton, wanttolearnButton, dfsButton, bfsButton, shortestPathButton, ComponentButton, hamiltonButton, eulerButton, dinhTruButton, dinhThatButton, bridgeEdgeButton, topoSortButton;
Button helpArea, matrixArea, processingArea, realProcessingArea, closeButton, continueButton, cancelButton, toolbarArea, algorithmArea;

/////////////////////////////////////////////////////////////////////_ConvertValue.h_/////////////////////////////////////////////////////////////////////
string ToStringLen2(int n);
string ToString(int n);
int ToInt(string s);

/////////////////////////////////////////////////////////////////////_Screen.h_/////////////////////////////////////////////////////////////////////
void DisableMinimizeButton (HWND hwnd);
void DisableMaximizeButton (HWND hwnd);
void DisableCloseButton (HWND hwnd);
void CreateScreen();
void CreateButton();
void DrawMenuTable();
void DrawButtonForAlgorithm(Button button);
void DrawButtonForToolBar(Button button);
void DrawButtonForNoti(Button button);
void DrawToolBar();
void DrawMatrix();
void DrawWeightMatrix(Graph &graph);
void DrawSubDel();
string OpenScreen();
string ShowFileName(WordWrap word, char &key, string ans, Button showFileNameArea, Button fileNameButton, Button OpenButton, Button exitButton, bool &isOpened);
void ClearBuffer();
/////////////////////////////////////////////////////////////////////_CheckAlgo.h_/////////////////////////////////////////////////////////////////////
bool CheckNode(int x, int y, int mx, int my);
bool CheckClickButton(Button button, int x, int y);
bool CheckReClickNode(Graph graph, int mx, int my);
bool CheckName(Graph &graph, string name);
bool CheckPos(Graph &graph, int mx, int my);

/////////////////////////////////////////////////////////////////////_DrawObject.h_/////////////////////////////////////////////////////////////////////
void CreateNode(int x, int y, string name, int colortext, int colorbk);
void AddNode(Graph &graph, int &x, int &y, string &ten, bool isTopo);
void Rename(int x, int y, string &ten);
string AddNameWeight(string name);
string AddNameTopo();
string AddFileName();
void NotificationFull(string Noti);
void DrawTriangle(int x1, int y1, int x2, int y2, int color);
void FlipCurved(Node *node1, Node *node2, char *tt, int color);
void CreateCurved(Node *node1, Node *node2, char *tt, int color);
void CreateLine(Node *node1, Node *node2, char *tt, int color);
void DrawGraph(Graph &graph);
void DrawGraphTopo(Graph &graph);
void DrawEdge(Graph &graph, int idx1, int color);
void DeleteEdge(Graph &graph, int x1, int y1, int x2, int y2, int index1, int index2);
void DeleteVertex(Graph &graph, int x, int y, int index);
void Move(Graph &graph, int x1, int y1, int x2, int y2, int index);

/////////////////////////////////////////////////////////////////////_Algorithm.h_/////////////////////////////////////////////////////////////////////
void EffectToolbar(Button button, int colorbk, int colortext, int colorborder);
bool CheckInButton(Button button);
void EffectFile();
void EffectToolbar();
void DrawTopoButton();
void EffectTopo(Graph graph);
void ShowSelectedList(string havelearned[], string wanttolearn[]);
bool RunningToolbar(Graph &graph, string fileName, int &x, int &y, bool flag);
void RunningAlgorithm(Graph graph, int x, int y, WordWrap &word, Button helpArea, Button upButton, Button downButton, Button scrollbar, bool &showResult);
int ChooseVertex(Graph graph, int &x, int &y);
void OpenSaveTopo(Graph &graph, string nameFile);
void OpenSave(Graph &graph, string nameFile);
void NewSave(Graph &graph, string &nameFile, bool &isFirstSave);
void EffectVertex(Graph graph, int u, int colorbk, int colortext, bool isDelay);
void EffectEdge(Graph graph, int u, int v, int color, bool isDelay);
void DFS(Graph graph, int start, WordWrap &word, Button helpArea);
void BFS(Graph graph, int start, WordWrap &word, Button helpArea);
void SCCHelp(int u, int &time, int &count, int disc[], int low[], bool stackMember[], Stack &stack, Stack ans[], Graph graph);
void SCC(Graph graph, WordWrap &word, Button helpArea);
int minDistance(int distance[], bool tick[], int V);
void Dijkstra(Graph graph, int start, int end, WordWrap &word, Button helpArea);
bool dfsCheck(Graph graph, int u, int v);
bool IsConnected(Graph graph, int u, int v);
void KnotPoint(Graph graph, int u, int v, WordWrap &word, Button helpArea);
void SCCTravel(int u, int &time, int &count, int disc[], int low[], bool stackMember[], Stack &stack, Graph graph);
int CountSCCs(Graph graph, int start);
void BridgeEdge(Graph graph, WordWrap &word, Button helpArea);
void ArticulationPoint(Graph graph, WordWrap &word, Button helpArea);
int CountWCC(Graph g, int start);
bool IsEulerCircuit(Graph graph);
void EulerCycle(Graph graph, WordWrap &word, Button helpArea, int start);
bool IsSafe(int v, Graph graph, int path[], int count[], int pos);
void HamCycle(Graph graph, WordWrap &word, Button helpArea, int start);
bool RecursiveHam(Graph graph, int path[], int count[], int pos);
bool CheckDAG(Graph graph, int topoOrder[], bool degZero[]);
void TopoSort(Graph graph, string haveLearned[], int numHaveLearned, string wantToLearn[], int numWantToLearn, WordWrap &word, Button helpArea);

/////////////////////////////////////////////////////////////////////_Scrollbar.h_/////////////////////////////////////////////////////////////////////
void DrawScrollbar(Button btn, int color);
void DrawUpDownButton(Button btn, int color);
void DeleteScrollbar(Button btn);
void UpdateValue(WordWrap &word, int scrollbarArea, Button &scrollbar, int &thumbHeight, int &jump, int &u0);
void DrawResult(Button upButton, Button downButton, Button scrollbar);

/////////////////////////////////////////////////////////////////////_File.h_/////////////////////////////////////////////////////////////////////
void WriteFile(char *path, Graph &graph);
void ReadFile(char *path, Graph &graph);
void WriteGraphTopo(char *path, Graph &graph);
void ReadGraphTopo(char *path, Graph &graph);