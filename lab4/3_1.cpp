// use cin method to get inputs
#include <iostream>
#include <vector>
#include <list>
#include <string>

struct character {
  std::string pinyin;
  std::string is_varient;
  std::string tone;
  std::string strokes;

  character(std::string pinyin, std::string is_varient, std::string tone, std::string strokes) {
    this->pinyin = pinyin;
    this->is_varient = is_varient;
    this->tone = tone == "0" ? std::to_string(5): tone;
    this->strokes = strokes;
  }

  // sort overload compare character object
  bool operator <(const character & characterObj)  const {
    if (pinyin != characterObj.pinyin) return pinyin < characterObj.pinyin;  // sort according to pinyin if not same (1)
    else if (is_varient != characterObj.is_varient) return is_varient < characterObj.is_varient; // sort according to varient forms, varient form after (2)
    else if (tone != characterObj.tone) return tone < characterObj.tone; // sort according to tone if not same (3)
    else if (strokes.length() != characterObj.strokes.length()) return strokes.length() < characterObj.strokes.length(); // sort according to number of strokes (4)
    else return strokes.compare(characterObj.strokes) < 0 ? true : false; // sort according to stroke order
    return false;
  }
  
};

int main() {
  std::string s;  
  std::list<character> characters;

  for (int i = 0; i < 2000; i++) {
    std::cin >> s;
    std::string pinyin, is_varient, tone, strokes;
    if (s == "~") break;
    pinyin = s;
    std::cin >> is_varient >> tone >> strokes;
   
    character new_ch = character(pinyin, is_varient, tone, strokes);
    characters.push_back(new_ch);
  }

  characters.sort();
  std::list<character>::iterator it;
  for (it = characters.begin(); it != characters.end(); it++) {
    std::string temp = it->tone == "5" ? "0" : it->tone;
    std::cout << it->pinyin << " " << it->is_varient << " " << temp << " " << it->strokes << "\n";
  }
  std::cout << "\n";
}