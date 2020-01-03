#ifndef SECRET_H
#define SECRET_H
#include <string>
using std::string;

struct SecretKeeper{
  string password;
  string secret;
  string get_secret(string);
};

//string get_secret(string);

#endif
