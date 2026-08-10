#include <stdio.h>
#include <time.h>

#include "log.h"
#include "raylib.h"

void print_start_time() {
  time_t current = time(NULL);

  char buf[256];
  snprintf(buf, 256, "Time is: %lld", (long long)current);

  log_debug(buf);
}

void run_game_loop() {
  const int w = 640;
  const int h = 480;

  InitWindow(w, h, "Objects Game");
  SetTargetFPS(60);

  Color c;
  c.a = 255;
  c.r = 100;
  c.g = 149;
  c.b = 237;

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(c);

    DrawText("Hello !", 10, 10, 20, RED);

    EndDrawing();
  }

  CloseWindow();
}

int main() {
#if DEBUG
  print_start_time();
#endif

  log_info("Starting.");

  run_game_loop();

  return 0;
}
