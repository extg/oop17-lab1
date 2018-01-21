#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

class IniParser {
private:
  static std::regex RE_SECTION;
  static std::regex RE_KEY_VALUE;

  std::map<std::string, std::map<std::string, std::string>> sections;
public:
  IniParser(std::ifstream &file);

  bool isHaveSection(std::string section_name);

  bool isHaveParam(std::string section_name, std::string param_name);

  int getValueInt(std::string section_name, std::string param_name);

  double getValueDouble(std::string section_name, std::string param_name);

  std::string getValue(std::string section_name, std::string param_name);

//  template <typename T>
//  T getValueT(std::string section_name, std::string param_name);
};
