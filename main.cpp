#include <iostream>
#include <fstream>
#include <string>
#include "class.h"
#define DIV cout << div << endl;

using namespace std;

int main(/*int argc, char* argv[]*/){

  #if 0
  if(argc<2){return 1;}
  #endif

  fstream out(/*argv[1]*/"outputFile.txt", ios::in | ios::out);
    if(!out) {
        cout << "Файл не октрылся";
        return 0;}

  char menu[] = "Туры для альпинистов \n \
    1 - добавить тур \n \
    2 - посмотреть все туры \n \
    3 - найти тур по названию \n \
    4 - найти тур по месту \n \
    5 - найти тур по дате \n \
    6 - найти тур по цене \n \
    7 - удалить тур \n \
    8 - выход \n \
    9 - повторный вызов меню \n";
  char div[] ="========================";

  cout << menu << endl;
  cout << div <<endl;

  int count =0;
  int t =0;
  int i = 1;
  int id;
  string tmp1;

  while (!out.eof()) {
    getline(out, tmp1);
    count++;
  }
  count = count-1;
  out.seekg(0, ios::beg);

  Tour *data = new Tour;

  while(!out.eof() && t<=count){
    getline(out, data[t].name, ' ');
    getline(out, data[t].place, ' ');
    getline(out, data[t].date, ' ');
    getline(out, data[t].price, ' ');
    t++;
  }

  while(i == 1){
    scanf("%d", &id);
    if(id == 1){
      Tour::addition(out, &count, data);
      DIV
    }
    else if(id == 2){
      Tour::show_all_entries(out, count, data);
      DIV
    }
    else if(id == 3){
      Tour::find_tour_by_name(out, count, data);
      DIV
    }
    else if(id == 4){
      Tour::find_tour_by_place(out, count, data);
      DIV
    }
    else if(id == 5){
      Tour::find_tour_by_date(out, count, data);
      DIV
    }
    else if(id == 6){
      Tour::find_tour_by_price(out, count, data);
      DIV
    }
    else if(id == 7){
      Tour::removal(out, &count, data);
    }
    else if(id == 8){
      break;
    }
    else if(id == 9){
      cout << menu << endl;
      DIV
    }
    else{
      cout << "Неверный id команды\n" << endl;
      DIV
    }
  }
  out.close();
}