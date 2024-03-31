
#ifndef SINGLE_RESPONSIBILITY_PRICIPLE_H
#define SINGLE_RESPONSIBILITY_PRICIPLE_H
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Journal {
  string title;
  vector<string> entries;

  explicit Journal(const string &title) : title{title} {}

  void add(const string &entry);

  // persistence is a separate concern
  void save(const string &filename);
};

struct PersistenceManager {
  static void save(const Journal &j, const string &filename) {
    ofstream ofs(filename);
    for (auto &s : j.entries)
      ofs << s << endl;
  }
};
#endif