#include <iostream>
#include <fstream>
#include <string>
#include "class_Tour.h"

class Menu{
  public:

    std::string menu = "Туры для альпинистов \n \
    1 - добавить тур \n \
    2 - посмотреть все туры \n \
    3 - найти тур по названию \n \
    4 - найти тур по месту \n \
    5 - найти тур по дате \n \
    6 - найти тур по цене \n \
    7 - удалить тур \n \
    8 - выход \n \
    9 - повторный вызов меню \n";
    std::string div ="========================";

    static int count;

    friend std::ostream& operator<< (std::ostream &out, const Tour tour);
    friend std::istream& operator>> (std::istream &in, Tour tour);

    void addition(std::fstream &out, Tour *data, int *arr_size);
    void show_all_entries(std::fstream &out, Tour *data);
    void find_tour_by_name(std::fstream &out, Tour *data);
    void find_tour_by_place(std::fstream &out, Tour *data);
    void find_tour_by_date(std::fstream &out, Tour *data);
    void find_tour_by_price(std::fstream &out, Tour *data);
    void removal(std::fstream &out, Tour *data, int *arr_size);
    Tour getFile(fstream& f, Tour* data, int *arr_size);
};