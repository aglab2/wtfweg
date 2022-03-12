#ifndef io_h_
#define io_h_

#include <libretro.h>
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <filesystem>
#include "clibretro.h"

void audio_mix(const int16_t* samples, size_t size);
bool audio_init(double refreshra, float input_srate, float fps);
void audio_destroy();
void video_test(SDL_Window *window);
void video_test2();
bool video_init(const struct retro_game_geometry* geom,float & refreshrate, SDL_Window *window);
void video_refresh(const void* data, unsigned width, unsigned height, unsigned pitch);
bool video_sethw(struct retro_hw_render_callback *hw);
void video_deinit();
void video_buf_clear();
uintptr_t video_get_fb();
bool video_set_pixelformat(retro_pixel_format fmt);

void init_inp();
void close_inp();
void poll_inp(SDL_Event * event,int selected_inp,bool *isselected_inp);
int getbind(unsigned port, unsigned device, unsigned index,
                                unsigned id);

int16_t axismaskval(bool * pressed,bool * rightstick, bool analog, std::string * name, int *axisval,int axistocheck);
int hatmaskval(std::string * name);

bool load_inpcfg();
bool save_inpcfg();



#endif