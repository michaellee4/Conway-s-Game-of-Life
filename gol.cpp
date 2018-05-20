/** 
Name: <your name>
Eid: <your id>

Q1: Why are the arrays passed to both print life functions const? <your answer>
Q2: Why are the arrays passed to both play life functions not const? <your answer>
Q3: If we did change the arrays passed to play life functions to make them const, 
    what else would have to happen to make play life work? <your answer>
*/

#include <iostream>

using namespace std;

/// global constant for fixed 2nd dimension of 2D array
const int NUM_COLS = 5;

/** function declarations
    you will need to write the definitions of these functions below.
    DO NOT MODIFY the declarations.
    You may create your own functions, but you must use these.
*/

/** 2d array functions, notice that for 2d arrays the second size 
    needs to be fixed, or more precisely it needs to be a const.
    if you typed a literal, like 5, it would be a literal constant,
    which also works.
*/
void printLife2DArray(const bool[][NUM_COLS], const int nRows);

int check2dCell(int r, int c, int nRows, const bool game[][NUM_COLS]){
    int numAliveNeighbors = 0;
    for(int i = r-1;i<=r+1 ;i++){
        if(i>=0 && i<nRows){
            for(int j = c-1; j<=c+1;j++){
                if(j>=0&&j<NUM_COLS){
                    if(!(i==r &&j==c) && game[i][j]){
                        numAliveNeighbors++;
                        
                        // cout<<i<<" "<<j<<" "<<numAliveNeighbors<<endl;
                    }
                }
            }
        }
    }

    return numAliveNeighbors;
}

void printLife2DArray(const bool game[][NUM_COLS], const int nRows){
    for(unsigned int i =0 ; i<nRows;i++){
        for (unsigned int j =0; j<NUM_COLS;j++){
            // int numAliveNeighbors = check2dCell(i,j,nRows,game);
            // cout<<numAliveNeighbors;
            cout<<game[i][j];
        }
        cout<<endl;
    }
}

void playLife2DArray(bool[][NUM_COLS], const int nRows, int iterations);
void playLife2DArray(bool game[][NUM_COLS], const int nRows, int iterations){
    bool gen[nRows][NUM_COLS];
    if(iterations>0){
        for (int i =0; i<nRows;i++){
            for (int j=0; j<NUM_COLS;j++){
                int numAliveNeighbors = check2dCell(i,j,nRows,game);
                bool isAlive = game[i][j];
                if(isAlive && !(numAliveNeighbors==2||numAliveNeighbors==3))
                    gen[i][j] = false;
                else if(!isAlive&&numAliveNeighbors==3)
                    gen[i][j]= true;
                else gen[i][j] = game[i][j];
                }
            }
        printLife2DArray(game, nRows);
        cout<<endl;
        playLife2DArray(gen,nRows,iterations-1);
    }
}



/** 1d array functions
*/
int check1dCell(int r, int c, int nCol, int nRows, const bool game[]);

int check1dCell(int r, int c, int nRows,int nCols, const bool game[]){
    int numAliveNeighbors = 0;
    for(int i = r-1;i<=r+1 ;i++){
        if(i>=0 && i<nRows){
            for(int j = c-1; j<=c+1;j++){
                if(j>=0&&j<nCols){
                    if(!(i==r &&j==c) && game[i*nCols+j]){
                        numAliveNeighbors++;
                        // cout<<i<<" "<<j<<" "<<numAliveNeighbors<<endl;
                    }
                }
            }
        }
    }

    return numAliveNeighbors;
}

void printLife1DArray(const bool[], const int nRows, const int nCols);

void printLife1DArray(const bool game[], const int nRows, const int nCols){\
    for(unsigned int i =0 ; i<nRows;i++){
        for (unsigned int j =0; j<nCols;j++){
            cout<<game[i*nCols+j];
        }
        cout<<endl;
    }
}
void playLife1DArray(bool[], const int nRows, const int nCols, int iterations);
void playLife1DArray(bool game[], const int nRows, const int nCols, int iterations){
    bool gen[nRows*nCols];
    if(iterations>0){
        for (int i =0; i<nRows;i++){
            for (int j=0; j<nCols;j++){
                int numAliveNeighbors = check1dCell(i,j,nRows,nCols,game);
                bool isAlive = game[i*nCols+j];
                if(isAlive && !(numAliveNeighbors==2||numAliveNeighbors==3))
                    gen[i*nCols+j] = false;
                else if(!isAlive&&numAliveNeighbors==3)
                    gen[i*nCols+j]= true;
                else gen[i*nCols+j] = game[i*nCols+j];
                }
            }
        printLife1DArray(game, nRows,nCols);
        cout<<endl;
        playLife1DArray(gen,nRows,nCols,iterations-1);
    }
}

int main() {
    /// read in row and col dimensions from standard input
    int rows, cols;
    cin>>rows>>cols;
    /// read in the number of iterations to run
    int iterations;
    cin>>iterations;
    /// read in whether this is a 2d array version(2),or 1d array (1)
    int dim;
    cin>>dim;

    //clear the end of line buffer for the line containing the dimension
    string trash;
    getline(cin,trash);

    string s;
    int r = 0;

    /** create an if statement to determint whether we are playing a 1d or 2d
     array. 
    2D: make a 2d bool array with the number of rows from
        standard input and the second value NUM_COLS
    1D: make a 1d array of the correct size from the rows and cols from
        standard input

    Some input examples and explanation of game of life
    Look at http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#Examples_of_patterns
    */
    //1d array
    if (dim ==1){
        bool game[rows*cols];
        while (getline(cin, s)){
            for(unsigned int i = 0;i<s.length();i++ ){
                if (s[i]=='*'){
                    game[r*cols+i] = true;
                }
                else{
                    game[r*cols+i] = false;
                }
            }
            r++;
        }
        playLife1DArray(game, rows,cols,iterations);
        printLife1DArray(game, rows,cols);

    }
    //2d array
    else{
        bool game[rows][NUM_COLS];
        while (getline(cin, s)){
            for(unsigned int i = 0;i<s.length();i++ ){
                if (s[i]=='*'){
                    game[r][i] = true;
                }
                else{
                    game[r][i] = false;
                }
            }
            r++;
        }
            // int numAliveNeighbors = check2dCell(4,1,rows,game);
            // cout<<numAliveNeighbors<<endl;
        // printLife2DArray(game, rows);
        // cout<<endl;
        playLife2DArray(game,rows, iterations);
        // cout<<endl;
    }

    /** print out what game we are playing */
    cout << "Game Of Life rows= " << rows << " cols= " << cols << 
          " iterations= " << iterations << " dimensions= " << 
          dim << endl;


    /** start your code
    */
    return 0; /// return a ok
}

