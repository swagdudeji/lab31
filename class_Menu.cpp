#include "class_Menu.h"

std::ostream& operator<< (std::ostream &out, const Tour tour){
  cout << tour.name << tour.place << tour.date << tour.price << endl;
  return out;
};

std::istream& operator>> (std::istream &in, Tour tour){
  in >> tour.name;
  in >> tour.place;
  in >> tour.date;
  in >> tour.price;
  return in;
}

void Menu::addition(fstream &out, Tour *data, int *arr_size){
      Tour *tmpData = new Tour[*arr_size+1];
      for(int i=0; i<*arr_size; i++){
        tmpData[i] = data[i];
        }
      delete[] data;
      cout << "Введите Название, Место, Дату и Стоимость тура \n" << endl;
      cin >> tmpData[count];
      data = tmpData;
      tmpData = nullptr;
      out.seekg(0, ios::end);
      out << data[count];
      count = count + 1;
      cout << "Тур успешно добавлен\n" << endl;
    };

    void Menu::show_all_entries(fstream &out, Tour *data){
      for(int c =0; c<count; c++){
        cout << data[c];
      }
    }

    void Menu::find_tour_by_name(fstream &out, Tour *data){
      bool label = false;
      string name;
      cout << "Введите название тура \n" << endl;
      cin >> name;
      for(int c =0; c<count; c++){
        if(name == data[c].name){
          cout << data[c];
        }
      }
      if(label == false){
        cout << "Не существует тура с заданным именем \n" << endl;
      }
    }

    void Menu::find_tour_by_place(fstream &out, Tour *data){
      bool label = false;
      string place;
      cout << "Введите место тура \n" << endl;
      cin >> place;
      for(int c =0; c<count; c++){
        if(place == data[c].place){
          cout << data[c];
          label = true;
        }
      }
      if(label == false){
        cout << "Не существует тура с заданным местом \n" << endl;
      }
    }

    void Menu::find_tour_by_date(fstream &out, Tour *data){
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
            cout << data[c];
            label = true;
          }
        }
        if(label == false){
          cout << "Не существует тура с заданной датой \n" << endl;
        }
      }
    }

    void Menu::find_tour_by_price(fstream &out, Tour *data){
      bool label = false;
      string price;
      cout << "Введите цену тура \n" << endl;
      cin >> price;
      for(int c =0; c<count; c++){
        if(price == data[c].price){
          cout << data[c];
          label = true;
          }
        }
      if(label == false){
          cout << "Не существует тура с заданной ценой \n" << endl;
        }
    }

    void Menu::removal(fstream &out, Tour *data, int *arr_size){
      int num;
      char tmp;
      cout << "Введите номер удаляемого тура \n" << endl;
      cin >> num;
      count--;
      Tour *tmpData = new Tour[*arr_size-1];
        for(int i=0; i<*arr_size-1; i++){
          if(num != i){
            tmpData[i] = data[i];
            }
          else{
            continue;
            }
        }
      delete[] data;
      data = tmpData;
      tmpData = nullptr;
      arr_size--;
      (out).seekg(0, ios::beg);
      for(int c=0; c<count; c++){
        out << data[c];
      }
    }

    Tour Menu::getFile(fstream &f, Tour *data, int *arr_size){
      string tmp1;
      while (!f.eof()) {
        getline(f, tmp1);
        count++;
        }
      count = count-1;
      f.seekg(0, ios::beg);
      int t = 0;
      while(!f.eof() && t<=count){
        Tour *tmpData = new Tour[*arr_size+1];
        for(int i=0; i<*arr_size; i++){
          tmpData[i] = data[i];
          }
        delete[] data;
        getline(f, tmpData[*arr_size-1].name, ' ');
        getline(f, tmpData[*arr_size-1].place, ' ');
        getline(f, tmpData[*arr_size-1].date, ' ');
        getline(f, tmpData[*arr_size-1].price, ' ');
        data = tmpData;
        tmpData = nullptr;
        arr_size++;      
        }
      return *data;
    }