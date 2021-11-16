#pragma once
bool CheckNode(int x, int y, int mx, int my){
	return ((mx - x)*(mx - x) + (my - y)*(my - y) <= 25*25);
}
bool CheckClickButton(Button button, int x, int y){	
	return (x > button.x1 && x < button.x2 && y > button.y1 && y < button.y2);
}
bool CheckReClickNode(Graph graph, int mx, int my){
	for(int i = 0; i < graph.numberNode; i++){
		if(CheckNode(graph.node[i]->x, graph.node[i]->y, mx, my)){
			return true;
		}
	}
	return false;
}
bool CheckName(Graph &graph, string nameNode){
	if(graph.numberNode == 0) return true;
	else{
		for(int i = 0; i < graph.numberNode; i++){
			if(graph.node[i]->name == nameNode){
				return false;
			}
		}
		return true;
	}
}
bool CheckPos(Graph &graph, int mx, int my){
	if(graph.numberNode == 0){
		if(mx > realProcessingArea.x1 && mx < realProcessingArea.x2 && my > realProcessingArea.y1 && my < realProcessingArea.y2) return true;
		else return false;
	}
	else {
		if(mx > realProcessingArea.x1 && mx < realProcessingArea.x2 && my > realProcessingArea.y1 && my < realProcessingArea.y2){ //return true;
			for (int i = 0; i < graph.numberNode; ++i){
				if((mx - graph.node[i]->x)*(mx - graph.node[i]->x) + (my - graph.node[i]->y)*(my - graph.node[i]->y) <  100 * 100){
					return false;
				}
			}
			return true;
		} 
		else return false;
	}		
}
