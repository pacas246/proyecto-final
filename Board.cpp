#include "Board.hpp"

Board::Board(){
	
	if(!texture.loadFromFile("resources/board1.png"))	std::cout<<"Error loading Texture\n";

	board.setTexture(texture);
	board.setPosition(0,0);
	
	if(!pTexture.loadFromFile("resources/pieces.png")) std::cout<<"Error loading Texture\n";
	
	desc = {{-1,-2,-3,-4,-5,-3,-2,-1},
     				{-6,-6,-6,-6,-6,-6,-6,-6},
      				{0, 0, 0, 0, 0, 0, 0, 0},
      				{0, 0, 0, 0, 0, 0, 0, 0},
      				{0, 0, 0, 0, 0, 0, 0, 0},
      				{0, 0, 0, 0, 0, 0, 0, 0},
      				{6, 6, 6, 6, 6, 6, 6, 6},
      				{1, 2, 3, 4, 5, 3, 2, 1}};

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(desc[i][j]!=0){
				Piece p(pTexture,56+j*56,56+i*56,desc[i][j]);
				piece.push_back(p);
			}
		}
	}
}

void Board::TakePiece(int x, int y){
	for(int h = 0; h < (int)piece.size(); h++){
		if(piece[h].ContainPosition(x,y)){
			pInd=h;
			break;
		}
	}
	
	if(color && piece[pInd].GetValue()<0) pInd=-1;
	else if(!color && piece[pInd].GetValue()>0) pInd=-1;
		
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			sf::IntRect rect = sf::IntRect(28+3+j*56,28+3+i*56,50,50);
			if(rect.contains(x,y))	pI=i, pJ=j;
		}	
	}
}

void Board::DropPiece(int x, int y){
		bool flag = 1;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				sf::IntRect rect = sf::IntRect(28+j*56+3,28+i*56+3,50,50);
				if(rect.contains(x,y) && ((color && desc[i][j]<=0) || (!color && desc[i][j]>=0)) && CheckMove(i,j)){
					
					piece[pInd].SetPosition(56+j*56,56+i*56);
					desc[i][j]=desc[pI][pJ];
					desc[pI][pJ]=0;
					flag=0;

					for(int h = 0; h < (int)piece.size(); h++){
						int val = piece[h].GetValue();
						if(piece[h].ContainPosition(x,y) && ((color && val<0) || (!color && val>0)))
							piece.erase(piece.begin()+h);
					}	
					
					CheckJaque();		
					
					if(color) color=false;
					else color=true;
				}
			}
		}
		
		if(flag) piece[pInd].SetPosition(56+pJ*56,56+pI*56);		
		pInd=-1;
}



void Board::Update(int x, int y, bool pressed){
	CheckJaque();		
	if(pInd!=-1&&pressed){
		piece[pInd].SetPosition(x,y);
	}else if(pInd!=-1&&!pressed){
		DropPiece(x,y);
	}else if(pInd==-1&&pressed){
		TakePiece(x,y);
	}	
}

bool Board::CheckPeon(int i , int j){
	if(color){
		if(desc[i][j]==0 && pI-i==1 && j==pJ) return true;
		else if(desc[i][j]==0 && pI-i==2 && j==pJ && pI==6 && desc[i+1][j]==0) return true;
		else if(desc[i][j]<0 && pI-i==1 && abs(j-pJ)==1) return true;
	}else{
		if(desc[i][j]==0 && pI-i==-1 && j==pJ) return true;
		else if(desc[i][j]==0 && pI-i==-2 && j==pJ && pI==1 && desc[i-1][j]==0) return true;
		else if(desc[i][j]>0 && pI-i==-1 && abs(j-pJ)==1) return true;
	}
	
	return false;
}

bool Board::CheckRey( int i , int j){
	if(color){
		if(abs(pI-i)<=1 && abs(pJ-j)<=1 && desc[i][j]<=0) return true;
	}else{
		if(abs(pI-i)<=1 && abs(pJ-j)<=1 && desc[i][j]>=0) return true;
	}
	
	return false;
}


bool Board::CheckCaballo(int i , int j){
	if(color){
		if( ( (abs(pI-i)==2 && abs(pJ-j)==1) || (abs(pI-i)==1 && abs(pJ-j)==2) ) && desc[i][j]<=0) return true;
	}else{
		if( ( (abs(pI-i)==2 && abs(pJ-j)==1) || (abs(pI-i)==1 && abs(pJ-j)==2) ) && desc[i][j]>=0) return true;
	}
	
	return false;
}

bool Board::CheckTorre(int i , int j){
	if(pJ==j){
		for(int I = std::min(pI,i)+1; I < std::max(pI,i); I++){
			if(desc[I][pJ]!=0) return false;
		}
		
		if(color && desc[i][j] <= 0) return true;
		else if(!color && desc[i][j] >=0) return true;
		
	}else if(pI==i){
		for(int J = std::min(pJ,j)+1; J < std::max(pJ,j); J++){
			if(desc[pI][J]!=0) return false;
		}
		
		if(color && desc[i][j] <= 0) return true;
		else if(!color && desc[i][j] >=0) return true;
		
	}
	
	return false;
}

bool Board::CheckAlfil( int i , int j){
	if(abs(pJ-j)==abs(pI-i)){
		
		int difI = (pI-i<0?1:-1);
		int difJ = (pJ-j<0?1:-1);
		
		int I=pI;
		int J=pJ;
				
		while( I!=i-difI && J!=j-difJ ){
			I+=difI;
			J+=difJ;
			if(desc[I][J]!=0) return false;
		}
		
		if(color && desc[i][j] <= 0) return true;
		else if(!color && desc[i][j] >=0) return true;
	}
	
	return false;
}

bool Board::CheckReina(int i , int j){
	if( CheckTorre(i,j) || CheckAlfil(i,j) ) return true;
	return false;
}

bool Board::CheckMove(int i, int j){
	
	switch( abs(desc[pI][pJ]) ){
		case 6: return CheckPeon(i,j); break;
		case 5: return CheckRey(i,j); break;
		case 2: return CheckCaballo(i,j); break;
		case 1: return CheckTorre(i,j); break;
		case 3: return CheckAlfil(i,j); break;
		case 4: return CheckReina(i,j); break;
	}
	return false;
}

void Board::CheckJaque(){
	int iR = -1,jR = -1;
	for (int i=0; i<8; i++){
		for (int j=0; j<8;j++){    if( (color && desc[i][j]==-5) || (!color && desc[i][j]==5) ){	iR=i; jR=j;}}}
	
	int npI = pI; int npJ = pJ;
	bool jaq=false;
		
		
	for (int i=0; i<8; i++){
		for (int j=0; j<8;j++){
			if((color && desc[i][j]<0) || (!color && desc[i][j]>0)) continue;
			pI=i; pJ=j;
			if(CheckMove(iR,jR)){
				jaq=true;
				if(color){	
					if(jaqB) jaqMB=true;
					jaqB=true;
				}else{
					if(jaqW) jaqMW=true;
					jaqW=true;
				}
			}
		}
	}

	pI=npI; pJ=npJ;
	if(color&&!jaq) jaqW=false;
	else if(!jaq) jaqB=false;
}

void Board::ConsultJaque(bool &jW,bool &jB,bool &jMW,bool &jMB){
 	jW=jaqW;
 	jB=jaqB;
 	jMW=jaqMW;
 	jMB=jaqMB;
}

bool Board::ConsultTurn(){
	return color;
}

void Board::draw(sf::RenderTarget &rt,sf::RenderStates rs) const{
	rt.draw(board,rs);
	for(int i = 0; i < (int)piece.size(); i++){
		if(i!=pInd)	rt.draw(piece[i],rs);
	}
	if(pInd!=-1) rt.draw(piece[pInd],rs);
}
