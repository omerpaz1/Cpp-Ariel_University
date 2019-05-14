#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector> 
#include <bits/stdc++.h> 




 namespace bullpgia {
    
class SmartGuesser: public bullpgia::Guesser{
    private:
      string str;
      int myplace;
      int value[10] = {0};
      bool pre;
      vector<string> ans;
      string combi;
      string reply;
      int count;
public:
          SmartGuesser();
          string guess() override;
          void startNewGame(uint length) override;
          void helping();
          string Getstrlength(string s, int legnth);
          void learn(string results) override;
          void permute(string s1, string s2);
          vector<string> getpremu(string s);
};
}