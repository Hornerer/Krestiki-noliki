
#include <iostream>
#include <string>


using namespace std;

class Krestiki_noliki
{

   private:
   char board[3][3];

   public:
   Krestiki_noliki() {}

   void SetBoard()
   {
      int n = 1;
      int i = 0;
      int j = 0;

      for ( i = 0; i < 3; i++ ){
         for ( j = 0; j < 3; j++ ){
            board[i][j] = '0' + n;
            n++;
         }
      }
   }
   void PrintBoard()
   {
      int i = 0;
      int j = 0;

      for ( i = 0; i < 3; i++ ){
         for ( j = 0; j < 3; j++ ){
            if ( j < 2 ){
               cout <<"|"<<"-"<< board[i][j]<<"-";
            }
               else{
                  cout <<"|"<<"-"<< board[i][j] <<"-"<<"|"<< endl;
               }
         }
      }
   }
   void Turn(char num, char Player){
      int i = 0;
      int j = 0;

      bool Wrong = true;
      for( i = 0; i < 3; i++ ){
         for( j = 0; j < 3; j++ )
         {
            if(board[i][j] == num){
               board[i][j] = Player;
               Wrong = false;
            }
         }
      }
      if(Wrong == true) {
            cout << "ERROR\n";
      }
   }
   bool Result(char Player, bool GameOver){
      for(int i = 0; i < 3; i++){
         if(board[i][0] == board[i][1] && board[i][1] ==
         board[i][2]) GameOver = true;
      }
      for(int i = 0; i < 3; i++){
         if(board[0][i] == board[1][i] && board[1][i] ==
         board[2][i]) GameOver = true;
      }

      if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
         GameOver = true;
      }
      if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
         GameOver = true;
      }
      if(GameOver == true){
         cout << "Player " << Player << " WINS\n\n";
      }
         return GameOver;
   }
   bool Draw(bool GameOver){
      int n = 1;
      int i = 0;
      int j = 0;
      int counter = 0;

      for( i = 0; i < 3; i++ ){
         for( j = 0; j < 3; j++ ){
            if(board[i][j] == '0' + n){
               counter++;
            }
            n++;
         }
      }
      if( counter < 1 ){
         cout << "Nichia\n\n";
         GameOver = true;
      }
      return GameOver;
   }
};

int main()
{
    bool done = false, GameOver = false;
    char Player = 'O', num;
    cout << "Krestiki noliki\n";
    Krestiki_noliki g;
    g.SetBoard();
    do
    {
        if( Player == 'X' ){
           Player = 'O';
        }
           else{
              Player = 'X';
           }
        g.PrintBoard();
        cout << "\nPlayer \"" << Player << "\", Vash_hod: ";
        cin >> num;
        cout << "\n";
        g.Turn(num, Player);
        GameOver = g.Result(Player, GameOver);
        GameOver = g.Draw(GameOver);
        if(GameOver == true){
            g.SetBoard();
            GameOver = false;
        }
    } while(!done);
    return 0;
}

