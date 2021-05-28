#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

class Tour{

  public:

    std::string name;
    std::string place;
    std::string date;
    std::string price;

    static void addition(std::fstream &out, int *count, Tour *data);
    static void show_all_entries(std::fstream &out, int count, Tour *data);
    static void find_tour_by_name(std::fstream &out, int count, Tour *data);
    static void find_tour_by_place(std::fstream &out, int count, Tour *data);
    static void find_tour_by_date(std::fstream &out, int count, Tour *data);
    static void find_tour_by_price(std::fstream &out, int count, Tour *data);
    static void removal(std::fstream &out, int *count, Tour *data);
};

#endif