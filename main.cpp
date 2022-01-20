#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <vlc/vlc.h>

#include <iostream>

static void *lock(void *opaque, void **planes) {
  printf("lock");
  return nullptr;
}

// 获取 argb 图片并保存到文件中
static void unlock(void *opaque, void *picture, void *const *planes) {
  printf("unlock");
}

static void display(void *opaque, void *picture) { printf("display"); }

int main(int argc, char **argv) {
  libvlc_instance_t *inst;
  libvlc_media_player_t *meida_player;
  libvlc_media_t *media;

  // load the vlc engine
  inst = libvlc_new(0, NULL);

  // create a new item
  media = libvlc_media_new_path(
      inst, "/home/guangoon/FLUTTER/vlc_sample/Butterfly-209.mp4");

  // create a media play playing environment
  meida_player = libvlc_media_player_new_from_media(media);
  libvlc_video_set_callbacks(meida_player, lock, unlock, display, nullptr);
  libvlc_video_set_format(meida_player, "RGBA", 1920, 1080, 1920 * 4);

  // no need to keep the media now
  libvlc_media_release(media);

  libvlc_media_player_play(meida_player);

  usleep(10000000);  // play the audio 100s

  // stop playing
  libvlc_media_player_stop(meida_player);

  // free the media_player
  libvlc_media_player_release(meida_player);

  libvlc_release(inst);

  return 0;
}