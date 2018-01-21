#include <iostream>
#include <fstream>      // ifstream

// Line-based parsing, using string streams:
#include <sstream>
#include <string>
#include <map>
#include <regex>

#include "IniParser.h"

using namespace std;

int main() {
  string fnames[] = {
      "../input_files/lab01_input_correct_01.ini",
      "../input_files/lab01_input_correct_02.ini",
      "../input_files/lab01_input_correct_03.ini",
      "../input_files/lab01_input_correct_04.ini",
      "../input_files/lab01_input_correct_05.ini",
      "../input_files/lab01_input_correct_06.ini",
      "../input_files/lab01_input_correct_07.ini",
      "../input_files/lab01_input_correct_08.ini",
      "../input_files/lab01_input_correct_09.ini",
  };

  string fname = fnames[6];

  ifstream input_file(fname, ios::in);

  if (!input_file.is_open()) {
    cerr << "Failed to open " + fname + "!\n";

    return -1;
  }

  IniParser config(input_file);

  cout << "Is have section \"DEMODS\": " << config.isHaveSection("DEMODS") << endl;
  cout << "Is have section \"MY_DEMODS\": " << config.isHaveSection("MY_DEMODS") << endl;
  cout << "Is have param \"DEMODS\" \"BufferLenSeconds\": " << config.isHaveParam("DEMODS", "BufferLenSeconds") << endl;
  cout << "Is have param \"MY_DEMODS\" \"BufferLenSeconds\": " << config.isHaveParam("MY_DEMODS", "BufferLenSeconds") << endl;
  cout << "Is have param \"DEMODS\" \"MyBufferLenSeconds\": " << config.isHaveParam("DEMODS", "MyBufferLenSeconds") << endl;
  cout << "Get value \"DEMODS\" \"BufferLenSeconds\": " << config.getValue("DEMODS", "BufferLenSeconds") << endl;
  cout << "Get value \"DEMODS\" \"BufferLenSeconds\": " << config.getValueInt("DEMODS", "BufferLenSeconds") << endl;
  cout << "Get value \"DEMODS\" \"BufferLenSeconds\": " << config.getValueDouble("DEMODS", "BufferLenSeconds") << endl;

  return 0;
}

