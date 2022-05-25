// gcc -Wall scope.c -o scope && ./scope

#include <stdio.h>

int xx = 100;
int yy = 200;
int zz = 300;

static void one(int zz) {
  xx += 5;
  yy += 5;
  zz += 5;
  printf("one: xx=%d yy=%d zz=%d xx+yy+zz=%d\n", xx, yy, zz, xx+yy+zz);
}

static void two(void) {
  int zz = 40;
  yy += 5;
  zz += 5;
  one(20);
  printf("two: xx=%d yy=%d zz=%d xx+yy+zz=%d\n", xx, yy, zz, xx+yy+zz);
}

static void three(int xx) {
  xx += 5;
  two();
  printf("three: xx=%d yy=%d zz=%d xx+yy+zz=%d\n", xx, yy, zz, xx+yy+zz);
}

static int four() {
  int yy = 2;
  three(10);
  printf("four: xx=%d yy=%d zz=%d xx+yy+zz=%d\n", xx, yy, zz, xx+yy+zz);
  return 4;
}

int main(int arc, char *argv[]) {
  int yy = four();
  zz += 1;
  printf("main: xx=%d yy=%d zz=%d xx+yy+zz=%d\n", xx, yy, zz, xx+yy+zz);
}