#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tour{

  public:

    string name;
    string place;
    string date;
    string price;

    static void addition(fstream &out, int *count, Tour *data){
      cout << "Введите Название, Место, Дату и Стоимость тура \n" << endl;
      cin >> data[*count].name;
      cin >> data[*count].place;
      cin >> data[*count].date;
      cin >> data[*count].price;
      out.seekg(0, ios::end);
      out << data[*count].name << data[*count].place << data[*count].date << data[*count].price << endl;
      *count = *count + 1;
      cout << "Тур успешно добавлен\n" << endl;
    };

    static void show_all_entries(fstream &out, int count, Tour *data){
      for(int c =0; c<count; c++){
        cout << c+1 << data[c].name << data[c].place << data[c].date << data[c].price << endl;
      }
    }

    static void find_tour_by_name(fstream &out, int count, Tour *data){
      bool label = false;
      string name;
      cout << "Введите название тура \n" << endl;
      cin >> name;
      for(int c =0; c<count; c++){
        if(name == data[c].name){
          cout << data[c].name << data[c].place << data[c].date << data[c].price << endl;
          label = true;
        }
      }
      if(label == false){
        cout << "Не существует тура с заданным именем \n" << endl;
      }
    }

    static void find_tour_by_place(fstream &out, int count, Tour *data){
      bool label = false;
      string place;
      cout << "Введите место тура \n" << endl;
      cin >> place;
      for(int c =0; c<count; c++){
        if(place == data[c].place){
          cout << data[c].name << data[c].place << data[c].date << data[c].price << endl;
          label = true;
        }
      }
      if(label == false){
        cout << "Не существует тура с заданным местом \n" << endl;
      }
    }

    static void find_tour_by_date(fstream &out, int count, Tour *data){
      bool label = false;
      string date;
      cout << "Введите дату тура \n" << endl;
      cin >> date;
      if(date.length() != 7){
        cout << "Неверный формат даты \n" << endl;
      }
      else{
        for(int c =0; c<count; c++){
          if(date == data[c].date){
            cout << data[c].name << data[c].place << data[c].date << data[c].price << endl;
            label = true;
          }
        }
        if(label == false){
          cout << "Не существует тура с заданной датой \n" << endl;
        }
      }
    }

    static void find_tour_by_price(fstream &out, int count, Tour *data){
      bool label = false;
      string price;
      cout << "Введите цену тура \n" << endl;
      cin >> price;
      for(int c =0; c<count; c++){
        if(price == data[c].price){
          cout << data[c].name << data[c].place << data[c].date << data[c].price << endl;
          label = true;
          }
        }
      if(label == false){
          cout << "Не существует тура с заданной ценой \n" << endl;
        }
    }

    static void removal(fstream &out, int *count, Tour *data){
      int num;
      char tmp;
      cout << "Введите номер удаляемого тура \n" << endl;
      cin >> num;
      if(num>0 && num<=*count){
        for(int c=num-1; c<*count; c++){
          data[c] = data[c+1];
          *count= *count-1;
        }
      }
      (out).seekg(0, ios::beg);
      for(int c=0; c<*count; c++){
        out << data[c].name << data[c].place << data[c].date << data[c].price << endl;
      }
    }
};