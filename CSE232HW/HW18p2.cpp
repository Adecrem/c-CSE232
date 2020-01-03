#include <iostream>
#include <string>
#include "secret.h"
using std::string;

string SecretKeeper::get_secret(string user){
  if (user == password){
    return secret;
  }else{
    return "";
  }
}
