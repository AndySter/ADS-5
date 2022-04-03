// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet (char nam) {
    switch (nam) {
    case '(': return 0;
    case ')': return 1; 
    case '+': case '-': return 2; 
    case '*': case '/': return 3;
    default : return -1;
    }
}

std::string infx2pstfx(std::string inf) {
  TStack <char, 128> stack;
    std::string outp;
    for (int i = 0; i < inf.length(); i++) {
        if (prioritet(inf[i]) == -1) {
            outp += inf[i];
            while (prioritet(inf[i+1]) == -1 && i+1 < inf.length()) {
                outp += inf[i+1];
                i++;
            }
            outp += ' ';
        } else {
            if (prioritet(inf[i]) == 0)
              stack.push(inf[i]);
            else if (prioritet(inf[i]) > prioritet(stack.get()))
              stack.push(inf[i]);
            else if (stack.isEmpty())
              stack.push(inf[i]);
            else if (prioritet(inf[i]) == 1) {
              while (prioritet(stack.get()) != 0) {
                outp += stack.get();
                outp += ' ';
                stack.pop();
              }
              stack.pop();
        } else if (prioritet(inf[i]) <= prioritet(stack.get())) {
            while (!stack.isEmpty() && prioritet(stack.get()) > 1) {
                outp += stack.get();
                outp += ' ';
                stack.pop();
            }
            stack.push(inf[i]);
        }
    }    
}
while (!stack.isEmpty()) {
    outp += stack.get();
    outp += ' ';
    stack.pop();
}
outp.pop_back();
return outp;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
}
