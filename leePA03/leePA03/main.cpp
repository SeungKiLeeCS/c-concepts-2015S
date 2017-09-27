#include<iostream>
using namespace std;

const int ROW = 9;
const int COL = 7;
char board[ROW][COL];//available for whole program

void welcome();
void display();
void catchNonNum();
int endGame(int totalToken, char player);
bool check(int a, int b);
int drop(int b, char player);

int main()
{
    for(int a =0;a <= ROW; a++)
    {       //fill board with whitespace
        for(int b = 0; b<= COL; b++)
            board[a][b] = ' ';
    }
    welcome();//Display Welcome message
    display();//Displays for first time so players can see the board

    int rowChoice, dropVal = 0;//rowChoice will hold user row choice, dropVal wil hold values for dropping tokens
    int totalToken = 0;//Number of peices dropped so can end game if a draw
    bool gameWon = false;//Will be changed to true when game is won and will exit while loop
    char player = 'X';//start as player 2 will change back 2 player 1

    while(!gameWon)//will stop when game is won, ! means NOT makes the oppisite be checked
    {
        if(dropVal != -1)//check if there was a error in the last drop
        {
            if(player == 'X') //if player 2 lasted dropped a piece so its player 1s turn
            {
                cout<<"player 1 drop where?";
                player = 'O';//char of players piece
            }
            else
            {
                cout<<"player 2 drop where?";
                player = 'X';//char of player piece
            }
        }

        while(true) //will run untill 'break;'
        {
            if(totalToken == ROW*COL)
            {
                break;//if draw
            }
            cin>>rowChoice;//get user input
            rowChoice--;//take off 1 to account for arrays starting at 0 not 1

            if(rowChoice <COL && rowChoice>= 0)
            {
                break;//if within valid range stop loop
            }
            else
            {
                cout<<endl;
                cout<<"please enter a value between 1 and 7 :";//ask for input and loop again
            }

            catchNonNum();
        }

        if(totalToken == ROW*COL)
        {
            break;//if draw
        }

        dropVal = drop(rowChoice,player);//drop the player store the row in dropVal

        if(dropVal == -1)
        {
            cout<<"Column is full"<<endl;
            cout<<"Please enter anothor number between 1 and 7:";//if error -1 row is full
        }
        else
        {
            gameWon = check(dropVal,rowChoice);//check if game is run
            totalToken ++;//another character has been succesfully placed
            display();//displayed updated board
        }
    }
    endGame(totalToken, player);
    return 0;//Exit application
}

void welcome()
{
    cout<<"Thank you for choosing Lee's Connect4."<<endl;
    cout<<"Token 'O' is for player 1, and Token 'X' is for player2"<<endl;
    cout<<"Player 1 will start."<<endl;
    cout<<endl;
}

int endGame(int totalToken, char player)
{
    if(totalToken == ROW*COL) //if draw
    {
        cout<<"No winner, Game ends in draw."<<endl;
        cout<<"You are not prepared."<<endl;
        cout<<endl;
        return 0;
    }
    if(player == 'X')//if won by player 2
    {
        cout<<"The Loser is: Player1"<<endl;
        cout<<"Grab a napking Hommie, you just got served."<<endl;
        cout<<"PS: All Human, Can Feel... You Know the Rest."<<endl;
        cout<<endl;
    }
    else
    {
        cout<<"The Loser is : Player2"<<endl;//Else won by player 1
        cout<<"Is today Valentine? Cuz you just got screwed."<<endl;
        cout<<endl;
    }
}

void catchNonNum()
{
    if (cin.fail()) //If nonNum is caught,
    {
        cin.clear();        //Stops cin trying to put its value in to rowChoice
        char c;
        cin>>c;
    }
}

void display()
{
    int a, b;
    cout<<" "<<"Lee's Connect4"<<endl;
    cout<<endl;
    for(a = 0; a < COL; a++)
    {
        cout<<" "<<a+1; // have the Row number printed for user interface
    }
    cout<<endl;

        for(b = 0; b < ROW; b++) // printing out the board with empty space.
        {
            for(a = 0; a < COL; a++)
            {
                cout<<"|"<<board[b][a];
            }
            cout<<"|";
            cout<<endl;
        }

        cout<<" ";
        for(a = 0; a <= (2*COL); a++) // printing the lower bound for user interface.
        {
            cout<<"=";
        }
        cout<<endl;
}

bool check(int a, int b){
    int vertical = 1, horizontal = 1, diagonalL = 1, diagonalR = 1;// used for
    int v, h;//used for vertical and horizontal place checks
    char player = board[a][b];

    //check for vertical(|)
    for(v = a +1;board[v][b] == player && v < ROW;v++,vertical++);//Check down
    for(v = a -1;board[v][b] == player && v >= 0;v--,vertical++);//Check up
    if(vertical >= 4)
        return true;

    //check for horizontal(-)
    for(h = b -1;board[a][h] == player && h >= 0;h--,horizontal++);//Check left
    for(h = b +1;board[a][h] == player && h < COL;h++,horizontal++);//Check right
    if(horizontal >= 4)
        return true;

    //check for diagonalL (\)
    for(v = a -1, h = b-1;board[v][h] == player && v>=0 && h >=0; diagonalL ++, v --, h --);//up and left
    for(v = a +1, h = b+1;board[v][h] == player && v<ROW && h <COL;diagonalL ++, v ++, h ++);//down and right
    if(diagonalL >= 4)
        return true;

    //check for diagonalR(/)
    for(v = a -1, h= b +1;board[v][h] == player && v>=0 && h < COL; diagonalR ++, v --, h ++);//up and right
    for(v = a +1, h= b -1;board[v][h] == player && v< ROW && h >=0; diagonalR ++, v ++, h --);//up and left
    if(diagonalR >= 4)
        return true;

    return false; // return false if all tests fail. Continue game.
}
int drop(int b, char player) //function to place the token into empty space
{
    if(b >=0 && b< ROW)
    {
        if(board[0][b] == ' ')
        {
            int i;
            for(i = 0;board[i][b] == ' ';i++) // if ' 'is checked, move down if clear
                //check column for empty space and where to stock
                if(i == COL-1) // check to see whether it reaches bottom
                {
                    board[i][b] = player;//set the empty space to player
                    return i; // return the value of place
                }
            i--; // counter the forloop check
            board[i][b] =player;
            return i; // return the row

        }
        else
        {
            return -1; // return -1 for dropVal
        }
    }
    else
    {
        return -1; // return -1 for dropVal
    }
}
