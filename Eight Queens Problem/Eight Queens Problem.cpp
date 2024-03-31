 #include <iostream>
 #include <array>
 #include <iomanip>
 #include <random>
 
const size_t arraySize = 8; 

void forbiddenMove(std::array<std::array<int, arraySize>, arraySize> &chess, int row, int col, int queens);
void displayMap(std::array<std::array<int, arraySize>, arraySize> &chess, const size_t arraySize);
int eigthQueensProblem(std::array<std::array<int, arraySize>, arraySize> &chess, int queens, int row);
void backtracking(std::array<std::array<int, arraySize>, arraySize> &chess, int row, int queens);


 int main(void){
	 
	std::default_random_engine engine(static_cast<unsigned int>(time(NULL)));
	std::uniform_int_distribution<unsigned int> randomInt(0, 7);
	
	//random satır ve sutun seçiyoruz!
	int row = randomInt(engine); 
	int col =  randomInt(engine);
	int queens = 1;
	
	std::array<std::array<int, arraySize>, arraySize> chess = {};
	chess[row][col] = queens; //ilk vezirimizi yerleştiriyoruz.

        forbiddenMove(chess, row, col, queens);
	eigthQueensProblem(chess, queens, row + 1);
	displayMap(chess, arraySize);
	
    return 0;
 }
int eigthQueensProblem(std::array<std::array<int, arraySize>, arraySize> &chess, int queens, int row){
	
	if(queens == 8)
		return 1;

	for(unsigned int i = 0; i < arraySize; ++i){

            if(chess[row][i] == 0){
			
		chess[row][i] = ++queens;
		forbiddenMove(chess, row, i, queens);
			
		if(eigthQueensProblem(chess, queens, row + 1))
			return 1;
			
		chess[row][i] = 0;
		backtracking(chess, row, queens);	
		--queens;
		}
	}
	

	return 0;
	
}
void forbiddenMove(std::array<std::array<int, arraySize>, arraySize> &chess, int row, int col, int queens){
	
	
	for(int i = 0; i < 7; ++i){
	     //aşağı yukarı sağ-sol satir -1 ile geçersiz kıl
		
		if(col - 1 - i >= 0 && chess[row][col - 1 - i] == 0)
		    chess[row][col - 1 - i] = - queens;
		
		if(col + 1 + i < 8 && chess[row][col + 1 + i] == 0)
		    chess[row][col + 1 + i] = - queens;
		
		if(row + 1 + i < 8 && chess[row + 1 + i][col] == 0)
		    chess[row + 1 + i][col] = - queens;
		
		if(row - 1 - i >= 0 && chess[row - 1 - i][col] == 0)
                    chess[row - 1 - i][col] = - queens;
		
		//çarpraz -1 ile doldur
                if(row - 1 - i >= 0 && col - 1 - i >= 0 && chess[row - 1 - i][col - 1 - i] == 0)
                   chess[row - 1 - i][col - 1 - i] = - queens;
        
	       if(row + 1 + i < 8 && col + 1 + i < 8 && chess[row + 1 + i][col + 1 + i] == 0)
                  chess[row + 1 + i][col + 1 + i] = - queens;
		
               if(row + 1 + i < 8 && col - 1 - i >= 0 && chess[row + 1 + i][col - 1 - i] == 0)
	          chess[row + 1 + i][col - 1 - i] = - queens;
		
	       if(row - 1 - i >= 0 && col + 1 + i < 8 && chess[row - 1 - i][col + 1 + i] == 0)
                  chess[row - 1 - i][col + 1 + i] = - queens;
	}	
}
void displayMap(std::array<std::array<int, arraySize>, arraySize> &chess, const size_t arraySize){
	
	for(unsigned int i = 0; i < arraySize; ++i){
		for(unsigned int j = 0; j < arraySize; ++j){
		    if(chess[i][j] < 0)
			chess[i][j] = 0;
			
			std::cout<<std::right<<std::setw(6)<<chess[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}


void backtracking(std::array<std::array<int, arraySize>, arraySize> &chess, int row, int queens){
	
	for( unsigned int rows = row; rows < chess.size(); ++rows){
		for(unsigned int col = 0; col < chess.size(); ++col){
			if(chess[rows][col] == - queens)
				chess[rows][col] = 0;
		}
	} 
}
