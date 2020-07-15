#include <iostream>
extern struct Definition;
extern struct Class;
bool isIF(Definition *mas, int i);
bool isFUNC(Definition *mas, int i);
bool isTHEN(Definition *mas, int i);
bool findIndex(Definition *mas, Class *arr, int size, int i, char *buf);
bool isDIV(Definition *mas, int i);
bool isMOD(Definition *mas, int i);
bool isPROC(Definition *mas, int i);
bool isID(Definition *mas, int i);
bool isELSE(Definition *mas, int i);
bool lexicalModule(Definition *mas, Class *arr, int size, int i, int k);
