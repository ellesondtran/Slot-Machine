//Elleson Tran
//Roberts
//Fruit machine Program
//Slot Machine!
//FINAL

#include <iostream>
#include <vector>
#include<ctime>

using namespace std;

int main() {


    double money = 2.00;

    cout<<"Insert your quarter! (Hit Enter)"<<endl;
    cin.get();

    double sum = 0;
    double win, totalPlays = 0;
    int playAgain = 1;
    
    while (playAgain == 1){
      srand(time(0));
      int num1 = rand()%10;
      int num2 = rand()%10;
      int num3 = rand()%10;
      totalPlays = totalPlays + 1;//counts how many times they played to calculate %of wins in the end
      money = money - 0.25;//subtracts 1 quarter everytime they play again
      cout<<endl<<"****SLOTS****"<<endl;
      cout<<"| "<<num1<<" | "<<num2<<" | "<<num3<<" |"<<endl;
      cout<<"*************"<<endl<<endl;

      if (num1 == num2 && num2 == num3){//three of the same number
        win = win + 1;//if they won, it will count this
        cout<<"MATCH 3!"<<endl;
        if (num1 == 0){//if all the numbers are cherries
          cout<<"BONUS!!!!"<<endl;
          sum = 100;
          money = money + sum;
        }
        if (num1 != 0){//if all the numbers are not cherries
          sum = num1 *3;
          money = money + sum;
        }
      }
      if (num1 == num2 && num1 != num3){//if the first two are matching
        win = win + 1;//if they won, it will count this
        cout<<"MATCH 2!"<<endl;
        sum = num1 *2;
        money = money + sum;
        if (num3 == 0){//if the last slot is a cherry
          cout<<"BONUS!!!!"<<endl;
          money = money + 20;
        }
      }
      if (num1 == num3 && num1 != num2){//if the first and third are matching
        win = win + 1;//if they won, it will count this
        cout<<"MATCH 2!"<<endl;
        sum = num1 *2;
        money = money + sum;
        if (num2 == 0){//if the last slot is a cherry
          cout<<"BONUS!!!!"<<endl;
          money = money + 20;
        }
      }
      if (num3 == num2 && num2 != num1){//if the last two slots are matching
        win = win + 1;//if they won, it will count this
        cout<<"MATCH 2!"<<endl;
        sum = num1 *2;
        money = money + sum;
        if (num1 == 0){//if the last slot is a cherry
          cout<<"BONUS!!!!"<<endl;
          money = money + 20;
        }
      }
      cout<<endl<<"Amount won this round: "<<sum<<endl;
      sum = 0;
      cout<<"You have won "<<(win/totalPlays) * 100<<"% of the time"<<endl;//how many wins there are divided by total plays (times 100) equals the percent of wins
      cout<<"You now have $"<<money<<endl;

      if(money > 0){//if there is enough money to keep playing, it will ask the question
        cout<<endl<<"Play again? 1=yes, 2=no:"<<endl;
        cin>>playAgain;
        if(playAgain == 1){
          cout<<"Insert your quarter! (Hit Enter)"<<endl;
          cin.get();
        }
        if(playAgain == 2){
          cout<<"Thank you for playing!";
        }
      }
      if (0 > money){//doesn't even print the play again if there isn't enough money
        cout<<"Sorry - you are out of money!";
        break;
      }

      }
    }

