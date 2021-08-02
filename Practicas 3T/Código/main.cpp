#include <iostream>
#include "User.h"
#include "CristoFinity.h"
#include "Comment.h"
#include "Element.h"
#include "UserNormal.h"
#include "Film.h"
#include "Series.h"
#include <stdlib.h>
#include "Administrator.h"

using namespace std;

#define RESTORE   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define DEBUG   "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define USER  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"  


int main(){

	CristoFinity c2;

	c2.menuLogin();

}