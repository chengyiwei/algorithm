#include <stdio.h>

#include <string.h>

struct S

{

char name[10];
    
};

main()

{
struct S s1, s2;

strcpy(s1.name, "12345");
    
strcpy(s2.name, "ABC");
    
s1 = s2;
    
printf("%s\n", s1.name);
    
}