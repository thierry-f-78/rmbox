/* GIMP RGBA C-Source image dump (tile_delete_13-15.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[42 * 42 * 4 + 1];
} gimp_image = {
  42, 42, 4,
  "\347\347\347\377\351\351\351\377\347\347\347\377\347\347\347\377\347\347"
  "\347\377\347\347\347\377\347\347\347\377\347\347\347\377\347\347\347\377"
  "\347\347\347\377\347\347\347\377\347\347\347\377\347\347\347\377\347\347"
  "\347\377\347\347\347\377\347\347\347\377\347\347\347\377\347\347\347\377"
  "\347\347\347\377\347\347\347\377\347\347\347\377\347\347\347\377\347\347"
  "\347\377\347\347\347\377\347\347\347\377\347\347\347\377\347\347\347\377"
  "\347\347\347\377\347\347\347\377\347\347\347\377\347\347\347\377\347\347"
  "\347\377\347\347\347\377\347\347\347\377\347\347\347\377\347\347\347\377"
  "\347\347\347\377\347\347\347\377\347\347\347\377\347\347\347\377\336\336"
  "\336\377\277\277\277\377\335\335\335\377\337\337\337\377\340\340\340\377"
  "\340\340\340\377\340\340\340\377\340\340\340\377\340\340\340\377\340\340"
  "\340\377\340\340\340\377\340\340\340\377\340\340\340\377\340\340\340\377"
  "\340\340\340\377\340\340\340\377\340\340\340\377\340\340\340\377\340\340"
  "\340\377\340\340\340\377\340\340\340\377\340\340\340\377\340\340\340\377"
  "\340\340\340\377\340\340\340\377\340\340\340\377\340\340\340\377\340\340"
  "\340\377\340\340\340\377\340\340\340\377\340\340\340\377\340\340\340\377"
  "\340\340\340\377\340\340\340\377\340\340\340\377\340\340\340\377\340\340"
  "\340\377\340\340\340\377\340\340\340\377\340\340\340\377\340\340\340\377"
  "\330\330\330\377\300\300\300\377\234\234\234\377\330\330\330\377\330\330"
  "\330\377\331\331\331\377\332\332\332\377\333\333\333\377\333\333\333\377"
  "\333\333\333\377\333\333\333\377\333\333\333\377\333\333\333\377\333\333"
  "\333\377\333\333\333\377\333\333\333\377\333\333\333\377\333\333\333\377"
  "\333\333\333\377\333\333\333\377\333\333\333\377\333\333\333\377\333\333"
  "\333\377\333\333\333\377\333\333\333\377\333\333\333\377\333\333\333\377"
  "\333\333\333\377\333\333\333\377\333\333\333\377\333\333\333\377\333\333"
  "\333\377\333\333\333\377\333\333\333\377\333\333\333\377\333\333\333\377"
  "\333\333\333\377\333\333\333\377\333\333\333\377\333\333\333\377\333\333"
  "\333\377\323\323\323\377\300\300\300\377\246\246\246\377\215\215\215\377"
  "\330\330\330\377\323\323\323\377\323\323\323\377\324\324\324\377\327\327"
  "\327\377\327\327\327\377\327\327\327\377\327\327\327\377\327\327\327\377"
  "\327\327\327\377\327\327\327\377\327\327\327\377\327\327\327\377\327\327"
  "\327\377\327\327\327\377\327\327\327\377\327\327\327\377\326\326\326\377"
  "\326\326\326\377\326\326\326\377\326\326\326\377\326\326\326\377\326\326"
  "\326\377\326\326\326\377\327\327\327\377\327\327\327\377\327\327\327\377"
  "\327\327\327\377\327\327\327\377\327\327\327\377\327\327\327\377\327\327"
  "\327\377\327\327\327\377\327\327\327\377\327\327\327\377\327\327\327\377"
  "\327\327\327\377\320\320\320\377\300\300\300\377\254\254\254\377\232\232"
  "\232\377\215\215\215\377\330\330\330\377\323\323\323\377\320\320\320\377"
  "\320\320\320\377\321\321\321\377\322\322\322\377\323\323\323\377\323\323"
  "\323\377\323\323\323\377\322\322\322\377\322\322\322\377\322\322\322\377"
  "\321\321\321\377\321\321\321\377\321\321\321\377\321\321\321\377\321\321"
  "\321\377\321\321\321\377\321\321\321\377\320\320\320\377\320\320\320\377"
  "\320\320\320\377\320\320\320\377\321\321\321\377\321\321\321\377\321\321"
  "\321\377\321\321\321\377\321\321\321\377\321\321\321\377\321\321\321\377"
  "\322\322\322\377\322\322\322\377\322\322\322\377\323\323\323\377\323\323"
  "\323\377\323\323\323\377\315\315\315\377\300\300\300\377\257\257\257\377"
  "\242\242\242\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323"
  "\323\377\320\320\320\377\316\316\316\377\316\316\316\377\316\316\316\377"
  "\316\316\316\377\316\316\316\377\315\315\315\377\314\314\314\377\313\313"
  "\313\377\312\312\312\377\311\311\311\377\311\311\311\377\311\311\311\377"
  "\311\311\311\377\311\311\311\377\311\311\311\377\310\310\310\377\310\310"
  "\310\377\310\310\310\377\310\310\310\377\310\310\310\377\310\310\310\377"
  "\311\311\311\377\311\311\311\377\311\311\311\377\311\311\311\377\311\311"
  "\311\377\311\311\311\377\311\311\311\377\313\313\313\377\313\313\313\377"
  "\315\315\315\377\316\316\316\377\313\313\313\377\300\300\300\377\261\261"
  "\261\377\247\247\247\377\242\242\242\377\232\232\232\377\215\215\215\377"
  "\330\330\330\377\323\323\323\377\320\320\320\377\316\316\316\377\314\314"
  "\314\377\312\312\312\377\315\315\315\377\314\314\315\377\313\313\313\377"
  "\310\311\311\377\307\307\307\377\304\305\305\377\303\303\303\377\300\300"
  "\301\377\300\277\300\377\277\277\277\377\277\277\277\377\276\276\276\377"
  "\275\275\275\377\274\273\274\377\273\273\273\377\273\272\273\377\272\272"
  "\272\377\272\272\272\377\272\272\272\377\271\272\271\377\271\271\271\377"
  "\270\270\270\377\270\271\271\377\271\271\271\377\272\271\272\377\272\272"
  "\272\377\274\273\273\377\274\274\274\377\274\274\274\377\274\275\275\377"
  "\263\263\263\377\253\253\253\377\247\247\247\377\242\242\242\377\232\232"
  "\232\377\215\215\215\377\330\330\330\377\323\323\323\377\320\320\320\377"
  "\316\316\316\377\314\314\314\377\311\311\311\377\315\315\315\377\314\313"
  "\313\377\312\311\312\377\310\310\310\377\305\304\305\377\300\300\301\377"
  "\276\276\277\377\274\273\274\377\272\272\272\377\271\271\270\377\267\267"
  "\267\377\267\266\267\377\266\266\266\377\266\265\265\377\265\265\264\377"
  "\264\264\264\377\264\263\263\377\262\263\263\377\262\262\262\377\262\262"
  "\262\377\262\262\262\377\262\263\263\377\264\264\264\377\265\265\265\377"
  "\266\266\266\377\270\267\267\377\270\271\271\377\270\270\270\377\272\271"
  "\272\377\272\272\272\377\256\256\256\377\252\252\252\377\247\247\247\377"
  "\242\242\242\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323"
  "\323\377\320\320\320\377\316\316\316\377\314\314\314\377\310\310\310\377"
  "\314\313\314\377\312\311\311\377\310\310\310\377\306\306\306\377\303\302"
  "\303\377\300\277\277\377\274\275\275\377\271\270\270\377\266\265\266\377"
  "\264\264\264\377\262\263\262\377\261\261\261\377\261\261\261\377\261\260"
  "\261\377\260\260\260\377\257\260\257\377\257\257\257\377\256\257\256\377"
  "\256\256\255\377\256\256\255\377\256\256\256\377\256\256\256\377\261\261"
  "\261\377\263\263\262\377\264\265\264\377\265\266\266\377\265\265\266\377"
  "\265\265\265\377\265\265\265\377\266\267\266\377\254\254\254\377\252\252"
  "\252\377\247\247\247\377\242\242\242\377\232\232\232\377\215\215\215\377"
  "\330\330\330\377\323\323\323\377\320\320\320\377\316\316\316\377\313\313"
  "\313\377\307\307\307\377\311\310\310\377\310\310\310\377\306\305\305\377"
  "\304\304\304\377\302\302\303\377\300\300\277\377\275\275\274\377\271\271"
  "\271\377\265\265\265\377\262\261\261\377\257\256\256\377\256\255\256\377"
  "\255\255\255\377\254\254\254\377\254\254\253\377\253\252\253\377\252\252"
  "\252\377\252\252\253\377\253\252\252\377\253\253\252\377\253\253\253\377"
  "\255\256\255\377\260\260\260\377\262\262\262\377\263\263\263\377\262\262"
  "\262\377\256\256\257\377\255\255\255\377\256\255\256\377\261\261\260\377"
  "\252\252\252\377\250\250\250\377\246\246\246\377\242\242\242\377\232\232"
  "\232\377\215\215\215\377\330\330\330\377\323\323\323\377\320\320\320\377"
  "\316\316\316\377\313\313\313\377\306\306\306\377\310\307\307\377\303\303"
  "\303\377\303\303\303\377\302\302\302\377\302\302\302\377\301\301\302\377"
  "\275\276\275\377\272\272\272\377\265\265\265\377\262\262\262\377\256\256"
  "\256\377\254\254\255\377\253\253\253\377\252\252\253\377\252\252\252\377"
  "\251\251\251\377\251\251\251\377\250\251\251\377\251\251\250\377\251\251"
  "\251\377\253\252\252\377\255\255\254\377\260\260\260\377\262\262\262\377"
  "\261\261\261\377\255\255\255\377\250\250\250\377\244\245\244\377\245\245"
  "\245\377\253\253\253\377\247\247\247\377\247\247\247\377\246\246\246\377"
  "\242\242\242\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323"
  "\323\377\320\320\320\377\316\316\316\377\313\313\313\377\305\305\305\377"
  "\304\304\303\377\301\301\301\377\276\277\276\377\275\275\276\377\277\277"
  "\277\377\300\301\301\377\277\277\277\377\275\275\275\377\270\270\270\377"
  "\264\264\264\377\257\257\260\377\255\255\255\377\252\253\252\377\251\251"
  "\251\377\251\251\251\377\251\250\251\377\250\250\250\377\247\250\247\377"
  "\250\250\250\377\252\251\252\377\254\253\254\377\256\256\256\377\260\261"
  "\260\377\260\260\260\377\255\254\254\377\246\246\246\377\235\236\236\377"
  "\232\232\232\377\236\235\235\377\246\246\245\377\245\245\245\377\246\246"
  "\246\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215\215\377"
  "\330\330\330\377\323\323\323\377\320\320\320\377\315\315\315\377\312\312"
  "\312\377\305\305\305\377\302\302\301\377\275\275\276\377\272\272\272\377"
  "\272\272\272\377\275\275\275\377\276\276\276\377\300\277\277\377\276\276"
  "\275\377\274\273\274\377\267\267\267\377\261\261\261\377\256\255\256\377"
  "\253\253\253\377\252\251\251\377\251\251\250\377\250\250\250\377\250\250"
  "\250\377\250\250\250\377\251\250\251\377\253\253\253\377\255\255\256\377"
  "\257\260\260\377\261\261\261\377\256\255\256\377\246\246\246\377\234\235"
  "\234\377\224\224\224\377\221\221\221\377\227\226\227\377\241\241\241\377"
  "\243\243\243\377\246\246\246\377\245\245\245\377\242\242\242\377\232\232"
  "\232\377\215\215\215\377\330\330\330\377\323\323\323\377\320\320\320\377"
  "\315\315\315\377\312\312\312\377\304\304\304\377\300\300\301\377\272\272"
  "\272\377\267\267\267\377\266\266\265\377\270\270\270\377\273\272\273\377"
  "\275\275\275\377\277\276\276\377\274\273\273\377\271\270\270\377\264\264"
  "\263\377\260\260\260\377\254\254\254\377\251\252\252\377\250\250\250\377"
  "\250\250\247\377\250\250\250\377\250\247\247\377\252\252\252\377\254\254"
  "\254\377\257\257\257\377\260\260\260\377\256\256\257\377\250\250\250\377"
  "\235\235\235\377\222\222\222\377\211\211\211\377\211\211\211\377\221\221"
  "\221\377\236\236\236\377\242\242\242\377\245\245\245\377\245\245\245\377"
  "\242\242\242\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323"
  "\323\377\320\320\320\377\315\315\315\377\312\312\312\377\304\304\304\377"
  "\300\300\300\377\272\272\272\377\265\265\265\377\263\263\264\377\265\264"
  "\264\377\267\267\267\377\272\272\273\377\274\274\274\377\275\275\276\377"
  "\272\272\272\377\266\266\266\377\261\261\261\377\256\256\256\377\253\253"
  "\253\377\251\251\251\377\250\250\250\377\247\250\250\377\251\251\251\377"
  "\253\253\253\377\257\257\257\377\260\260\261\377\257\257\257\377\252\252"
  "\252\377\240\240\241\377\224\224\223\377\210\210\211\377\202\201\201\377"
  "\204\204\204\377\216\216\216\377\234\234\234\377\242\242\242\377\245\245"
  "\245\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215\215\377"
  "\330\330\330\377\323\323\323\377\320\320\320\377\315\315\315\377\312\312"
  "\312\377\304\304\304\377\276\276\276\377\271\271\270\377\263\263\263\377"
  "\260\261\261\377\261\261\261\377\264\263\263\377\267\267\267\377\272\272"
  "\272\377\274\274\273\377\273\272\273\377\271\270\270\377\264\264\263\377"
  "\260\261\260\377\255\255\255\377\252\252\252\377\251\251\252\377\252\252"
  "\252\377\253\254\254\377\256\255\256\377\257\257\257\377\260\260\260\377"
  "\254\254\254\377\244\244\245\377\230\230\227\377\212\213\212\377\200\177"
  "\177\377|||\377\200\200\200\377\214\214\214\377\233\233\233\377\241\241\241"
  "\377\245\245\245\377\245\245\245\377\242\242\242\377\232\232\232\377\215"
  "\215\215\377\330\330\330\377\323\323\323\377\320\320\320\377\315\315\315"
  "\377\312\312\312\377\304\304\304\377\275\276\276\377\267\267\267\377\261"
  "\262\262\377\257\257\257\377\257\256\256\377\260\261\261\377\263\263\263"
  "\377\266\267\267\377\272\272\272\377\273\272\273\377\271\271\270\377\267"
  "\267\270\377\263\262\263\377\257\257\257\377\255\255\256\377\254\254\254"
  "\377\255\255\255\377\257\256\256\377\257\257\257\377\260\260\260\377\255"
  "\255\255\377\245\246\245\377\233\234\234\377\217\217\217\377\202\201\202"
  "\377yyy\377xww\377}~~\377\213\212\212\377\233\233\233\377\241\241\241\377"
  "\245\245\245\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215"
  "\215\377\330\330\330\377\323\323\323\377\320\320\320\377\315\315\315\377"
  "\311\311\311\377\303\303\303\377\276\275\275\377\267\266\266\377\261\261"
  "\261\377\255\255\256\377\254\255\255\377\255\255\255\377\257\257\260\377"
  "\263\263\263\377\266\267\267\377\271\271\271\377\271\271\271\377\271\271"
  "\271\377\266\266\266\377\263\264\263\377\260\260\260\377\260\260\260\377"
  "\260\260\257\377\260\261\260\377\260\261\261\377\255\255\255\377\247\247"
  "\247\377\236\235\236\377\222\221\221\377\205\205\204\377{{{\377vvv\377uu"
  "u\377}||\377\212\211\212\377\232\232\232\377\241\241\241\377\245\245\245"
  "\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215\215\377\330"
  "\330\330\377\323\323\323\377\320\320\320\377\315\315\315\377\311\311\311"
  "\377\303\303\303\377\274\274\275\377\266\266\266\377\261\261\261\377\255"
  "\255\255\377\254\254\254\377\254\253\253\377\254\254\254\377\260\257\257"
  "\377\262\262\262\377\265\265\265\377\267\267\267\377\271\271\271\377\270"
  "\271\271\377\266\266\266\377\264\264\265\377\263\263\263\377\262\262\262"
  "\377\262\261\262\377\256\256\256\377\250\250\250\377\236\236\235\377\222"
  "\222\222\377\206\206\206\377|||\377vvu\377rrr\377sts\377|||\377\211\211\211"
  "\377\232\232\231\377\241\241\241\377\245\245\245\377\245\245\245\377\242"
  "\242\242\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323\323"
  "\377\320\320\320\377\315\315\315\377\311\311\311\377\303\303\303\377\274"
  "\274\274\377\265\265\266\377\261\261\261\377\254\254\254\377\252\253\253"
  "\377\252\252\252\377\253\252\252\377\254\254\254\377\256\256\256\377\262"
  "\262\261\377\265\265\265\377\267\267\267\377\271\271\271\377\271\271\271"
  "\377\270\270\270\377\266\265\265\377\263\263\262\377\256\256\256\377\250"
  "\250\250\377\237\237\237\377\223\224\223\377\210\210\210\377}}}\377uuu\377"
  "qqq\377opp\377sss\377zz{\377\211\210\211\377\231\231\231\377\241\241\241"
  "\377\245\245\245\377\245\245\245\377\242\242\242\377\232\232\232\377\215"
  "\215\215\377\330\330\330\377\323\323\323\377\320\320\320\377\315\315\315"
  "\377\311\311\311\377\303\303\303\377\274\273\274\377\265\264\265\377\260"
  "\260\260\377\253\254\253\377\251\251\251\377\251\251\251\377\251\251\251"
  "\377\252\252\251\377\253\253\253\377\256\256\256\377\262\262\262\377\266"
  "\265\266\377\270\270\270\377\271\271\271\377\271\271\271\377\270\267\270"
  "\377\262\263\262\377\253\253\253\377\241\241\241\377\226\226\225\377\211"
  "\211\211\377~~~\377vvv\377qqq\377ono\377nno\377rrr\377zzz\377\210\210\210"
  "\377\231\231\231\377\241\241\241\377\245\245\245\377\245\245\245\377\242"
  "\242\242\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323\323"
  "\377\320\320\320\377\315\315\315\377\311\311\311\377\303\303\303\377\272"
  "\273\273\377\264\264\264\377\257\260\260\377\253\253\253\377\251\251\251"
  "\377\251\251\251\377\251\250\250\377\250\250\250\377\252\252\252\377\254"
  "\253\254\377\260\260\260\377\263\263\263\377\267\267\267\377\270\270\270"
  "\377\271\271\271\377\267\267\267\377\262\261\262\377\250\250\250\377\235"
  "\234\235\377\217\217\217\377\202\202\202\377yxy\377rrr\377ooo\377mmm\377"
  "mmm\377qrr\377zzz\377\210\207\210\377\230\230\230\377\241\241\241\377\245"
  "\245\245\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215\215"
  "\377\330\330\330\377\323\323\323\377\320\320\320\377\315\315\315\377\311"
  "\311\311\377\303\303\303\377\272\273\273\377\264\263\264\377\257\257\257"
  "\377\253\252\253\377\251\251\251\377\250\251\250\377\250\250\250\377\250"
  "\251\250\377\251\252\251\377\253\253\253\377\255\256\255\377\262\262\262"
  "\377\265\265\266\377\266\267\266\377\270\267\267\377\265\264\265\377\260"
  "\260\260\377\247\247\250\377\232\233\233\377\216\217\216\377\200\201\201"
  "\377www\377rrr\377nmm\377mmm\377mmm\377qqq\377yzy\377\207\207\207\377\227"
  "\227\230\377\241\241\241\377\245\245\245\377\245\245\245\377\242\242\242"
  "\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323\323\377\320"
  "\320\320\377\315\315\315\377\311\311\311\377\303\303\303\377\272\272\272"
  "\377\263\263\263\377\256\256\257\377\252\252\252\377\251\250\251\377\250"
  "\247\250\377\250\250\250\377\251\251\251\377\252\252\252\377\254\254\254"
  "\377\256\257\257\377\260\260\260\377\261\261\261\377\261\261\261\377\261"
  "\261\261\377\260\260\260\377\255\255\255\377\247\247\247\377\236\236\236"
  "\377\222\221\222\377\205\205\205\377zz{\377srs\377ooo\377mmm\377mmm\377r"
  "rr\377xyy\377\207\207\206\377\227\227\227\377\241\241\241\377\245\245\245"
  "\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215\215\377\330"
  "\330\330\377\323\323\323\377\320\320\320\377\315\315\315\377\311\311\311"
  "\377\303\303\303\377\272\272\272\377\262\263\262\377\256\256\256\377\252"
  "\252\251\377\250\250\250\377\250\250\250\377\251\251\251\377\252\252\252"
  "\377\254\254\255\377\256\256\255\377\257\257\257\377\256\257\256\377\254"
  "\254\254\377\252\251\252\377\246\246\247\377\247\246\246\377\247\246\247"
  "\377\245\245\245\377\240\241\240\377\227\227\226\377\214\213\214\377\201"
  "\201\201\377xxx\377rrr\377nnn\377nnn\377qqq\377yyy\377\206\206\206\377\226"
  "\226\226\377\241\241\241\377\245\245\245\377\245\245\245\377\242\242\242"
  "\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323\323\377\320"
  "\320\320\377\315\315\315\377\312\312\312\377\304\304\304\377\272\272\271"
  "\377\262\262\262\377\256\256\255\377\252\252\252\377\250\250\250\377\251"
  "\251\251\377\252\252\252\377\254\254\254\377\257\257\256\377\257\260\260"
  "\377\256\257\257\377\254\253\253\377\244\244\244\377\236\235\236\377\232"
  "\232\232\377\231\232\232\377\234\234\234\377\237\237\236\377\240\240\240"
  "\377\233\233\233\377\223\223\223\377\212\212\211\377\200\200\200\377xxx\377"
  "rrs\377ppp\377rrr\377zzz\377\206\206\206\377\226\226\226\377\241\241\241"
  "\377\245\245\245\377\245\245\245\377\242\242\242\377\232\232\232\377\215"
  "\215\215\377\330\330\330\377\323\323\323\377\320\320\320\377\315\315\315"
  "\377\312\312\312\377\304\304\304\377\271\271\271\377\262\262\262\377\255"
  "\255\255\377\253\252\253\377\252\251\252\377\253\253\253\377\255\255\255"
  "\377\257\260\260\377\261\260\260\377\256\256\257\377\253\253\253\377\242"
  "\242\242\377\231\232\232\377\221\221\221\377\214\214\214\377\214\213\213"
  "\377\216\216\217\377\225\225\225\377\232\232\232\377\234\234\234\377\231"
  "\230\230\377\222\223\223\377\211\211\211\377\201\201\201\377yyy\377ttt\377"
  "utu\377zzz\377\207\207\206\377\226\226\226\377\241\241\241\377\245\245\245"
  "\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215\215\377\330"
  "\330\330\377\323\323\323\377\320\320\320\377\315\315\315\377\312\312\312"
  "\377\304\304\304\377\271\270\270\377\262\262\262\377\256\256\256\377\254"
  "\254\254\377\254\254\254\377\256\256\255\377\260\260\257\377\262\261\261"
  "\377\257\257\260\377\253\253\253\377\244\245\244\377\232\232\232\377\216"
  "\216\217\377\205\205\205\377\177\200\177\377\177~\177\377\202\202\202\377"
  "\211\211\211\377\221\221\221\377\227\230\227\377\233\233\233\377\231\231"
  "\231\377\223\224\223\377\213\213\213\377\204\204\203\377||{\377yzy\377}}"
  "|\377\207\210\210\377\226\225\226\377\242\242\242\377\245\245\245\377\245"
  "\245\245\377\242\242\242\377\232\232\232\377\215\215\215\377\330\330\330"
  "\377\323\323\323\377\320\320\320\377\315\315\315\377\312\312\312\377\304"
  "\304\304\377\270\270\270\377\262\262\262\377\257\257\257\377\255\255\255"
  "\377\255\256\255\377\260\260\260\377\260\260\260\377\256\257\256\377\253"
  "\253\253\377\244\245\245\377\232\232\232\377\217\217\216\377\203\203\203"
  "\377{{{\377vvv\377vvv\377yyy\377~~~\377\206\206\206\377\220\220\217\377\227"
  "\227\227\377\234\234\234\377\231\231\232\377\226\225\225\377\215\215\215"
  "\377\206\205\205\377\200\201\201\377\201\201\201\377\212\212\212\377\227"
  "\227\226\377\242\242\242\377\245\245\245\377\245\245\245\377\242\242\242"
  "\377\232\232\232\377\215\215\215\377\330\330\330\377\323\323\323\377\320"
  "\320\320\377\315\315\315\377\312\312\312\377\305\305\305\377\270\270\270"
  "\377\264\264\264\377\260\260\260\377\260\260\260\377\257\260\260\377\257"
  "\257\260\377\256\256\256\377\252\252\252\377\243\242\243\377\231\231\231"
  "\377\217\216\217\377\203\203\204\377z{z\377ttt\377qqq\377poo\377rrq\377w"
  "vv\377}|}\377\206\206\206\377\220\220\220\377\227\230\230\377\234\234\234"
  "\377\233\234\234\377\226\226\227\377\220\217\220\377\212\212\212\377\211"
  "\211\210\377\216\216\216\377\230\230\230\377\243\243\243\377\245\245\245"
  "\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215\215\377\330"
  "\330\330\377\323\323\323\377\320\320\320\377\316\316\316\377\312\312\312"
  "\377\305\305\305\377\271\272\271\377\265\265\265\377\263\263\263\377\260"
  "\260\260\377\257\257\257\377\254\254\254\377\247\247\247\377\237\237\237"
  "\377\227\227\227\377\216\215\215\377\204\204\204\377{{{\377ttt\377ppp\377"
  "onn\377nnn\377ooo\377rrr\377vvv\377}~~\377\206\206\206\377\220\220\220\377"
  "\230\230\230\377\234\234\234\377\233\233\234\377\230\230\230\377\223\223"
  "\223\377\221\221\221\377\223\223\223\377\233\233\233\377\244\244\244\377"
  "\246\246\246\377\245\245\245\377\242\242\242\377\232\232\232\377\215\215"
  "\215\377\330\330\330\377\323\323\323\377\320\320\320\377\316\316\316\377"
  "\313\313\313\377\306\306\306\377\272\272\272\377\270\267\267\377\264\264"
  "\264\377\260\260\260\377\253\254\254\377\245\246\245\377\235\236\236\377"
  "\224\224\224\377\214\214\214\377\202\202\202\377{{{\377uuv\377rrr\377oop"
  "\377ooo\377nnn\377ooo\377ppp\377rrr\377www\377\177~\177\377\207\206\207\377"
  "\221\220\220\377\230\227\227\377\235\235\235\377\235\235\235\377\232\232"
  "\231\377\231\230\230\377\232\231\231\377\237\237\237\377\247\247\247\377"
  "\247\247\247\377\246\246\246\377\242\242\242\377\232\232\232\377\215\215"
  "\215\377\330\330\330\377\323\323\323\377\320\320\320\377\316\316\316\377"
  "\313\313\313\377\307\307\307\377\273\274\274\377\271\271\271\377\264\264"
  "\264\377\257\257\257\377\246\246\246\377\235\235\236\377\224\224\224\377"
  "\213\214\213\377\203\203\204\377~~~\377xyy\377vvv\377ttt\377sss\377rrr\377"
  "rrr\377rrr\377rrq\377sss\377uvu\377zzz\377\201\201\201\377\212\211\212\377"
  "\222\222\222\377\232\232\232\377\237\237\237\377\240\240\240\377\240\240"
  "\237\377\241\241\241\377\245\244\245\377\252\252\252\377\250\250\250\377"
  "\246\246\246\377\242\242\242\377\232\232\232\377\215\215\215\377\330\330"
  "\330\377\323\323\323\377\320\320\320\377\316\316\316\377\314\314\314\377"
  "\310\310\310\377\273\274\274\377\272\272\271\377\264\264\264\377\256\255"
  "\255\377\245\244\244\377\232\232\232\377\221\221\221\377\211\211\212\377"
  "\205\204\204\377\200\201\200\377~~~\377}||\377|{|\377{|{\377{{{\377zzz\377"
  "zzz\377zzz\377zzz\377{{{\377}}~\377\201\201\201\377\210\210\210\377\221\221"
  "\221\377\231\231\230\377\241\240\240\377\244\244\243\377\245\245\245\377"
  "\246\246\245\377\250\247\250\377\255\255\255\377\251\251\251\377\247\247"
  "\247\377\242\242\242\377\232\232\232\377\215\215\215\377\330\330\330\377"
  "\323\323\323\377\320\320\320\377\316\316\316\377\314\314\314\377\311\311"
  "\311\377\275\275\274\377\272\271\271\377\265\265\265\377\256\256\256\377"
  "\245\245\245\377\235\235\235\377\227\227\227\377\221\221\221\377\216\216"
  "\216\377\214\214\214\377\214\213\214\377\212\212\212\377\212\211\211\377"
  "\211\211\211\377\210\210\210\377\210\210\207\377\210\210\210\377\207\207"
  "\210\377\207\207\207\377\207\207\210\377\210\210\210\377\212\212\212\377"
  "\215\215\216\377\223\224\224\377\233\233\233\377\242\242\242\377\246\246"
  "\246\377\251\251\250\377\252\252\252\377\252\253\252\377\256\256\256\377"
  "\252\252\252\377\247\247\247\377\242\242\242\377\232\232\232\377\215\215"
  "\215\377\330\330\330\377\323\323\323\377\320\320\320\377\316\316\316\377"
  "\314\314\314\377\306\306\306\377\275\275\274\377\272\272\272\377\267\267"
  "\266\377\261\261\260\377\254\253\254\377\246\246\245\377\241\241\241\377"
  "\237\237\236\377\235\235\235\377\233\233\233\377\233\233\233\377\232\232"
  "\233\377\232\232\231\377\231\231\231\377\230\230\231\377\230\230\230\377"
  "\230\227\230\377\227\227\227\377\226\226\226\377\226\226\226\377\226\226"
  "\226\377\230\230\230\377\231\231\231\377\234\233\233\377\241\241\241\377"
  "\246\245\245\377\251\251\250\377\253\253\253\377\253\253\254\377\253\253"
  "\254\377\256\256\256\377\253\253\253\377\247\247\247\377\242\242\242\377"
  "\232\232\232\377\215\215\215\377\330\330\330\377\323\323\323\377\320\320"
  "\320\377\316\316\316\377\307\307\307\377\272\272\272\377\256\256\256\377"
  "\251\251\251\377\250\250\250\377\245\245\245\377\242\242\242\377\240\240"
  "\240\377\236\236\236\377\236\236\236\377\235\235\235\377\235\235\235\377"
  "\235\235\235\377\235\235\235\377\234\234\234\377\234\234\234\377\234\234"
  "\234\377\234\234\234\377\234\234\234\377\234\234\234\377\235\235\235\377"
  "\235\235\235\377\235\235\235\377\236\236\236\377\236\236\236\377\240\240"
  "\240\377\242\242\242\377\245\245\245\377\250\250\250\377\252\252\252\377"
  "\251\251\251\377\253\253\253\377\254\254\254\377\252\252\252\377\247\247"
  "\247\377\242\242\242\377\232\232\232\377\215\215\215\377\330\330\330\377"
  "\323\323\323\377\320\320\320\377\310\310\310\377\271\271\271\377\253\253"
  "\253\377\244\244\244\377\243\243\243\377\243\243\243\377\242\242\242\377"
  "\240\240\240\377\240\240\240\377\237\237\237\377\236\236\236\377\236\236"
  "\236\377\236\236\236\377\236\236\236\377\236\236\236\377\236\236\236\377"
  "\236\236\236\377\236\236\236\377\236\236\236\377\236\236\236\377\236\236"
  "\236\377\236\236\236\377\236\236\236\377\236\236\236\377\236\236\236\377"
  "\237\237\237\377\240\240\240\377\240\240\240\377\242\242\242\377\243\243"
  "\243\377\243\243\243\377\244\244\244\377\244\244\244\377\246\246\246\377"
  "\250\250\250\377\247\247\247\377\242\242\242\377\232\232\232\377\215\215"
  "\215\377\330\330\330\377\323\323\323\377\311\311\311\377\270\270\270\377"
  "\247\247\247\377\236\236\236\377\236\236\236\377\236\236\236\377\236\236"
  "\236\377\235\235\235\377\235\235\235\377\235\235\235\377\235\235\235\377"
  "\235\235\235\377\235\235\235\377\235\235\235\377\234\234\234\377\234\234"
  "\234\377\234\234\234\377\234\234\234\377\234\234\234\377\234\234\234\377"
  "\234\234\234\377\234\234\234\377\234\234\234\377\235\235\235\377\235\235"
  "\235\377\235\235\235\377\235\235\235\377\235\235\235\377\235\235\235\377"
  "\235\235\235\377\236\236\236\377\236\236\236\377\236\236\236\377\236\236"
  "\236\377\236\236\236\377\241\241\241\377\244\244\244\377\242\242\242\377"
  "\232\232\232\377\215\215\215\377\330\330\330\377\313\313\313\377\266\266"
  "\266\377\242\242\242\377\230\230\230\377\230\230\230\377\230\230\230\377"
  "\230\230\230\377\230\230\230\377\230\230\230\377\230\230\230\377\230\230"
  "\230\377\230\230\230\377\230\230\230\377\230\230\230\377\230\230\230\377"
  "\230\230\230\377\230\230\230\377\230\230\230\377\230\230\230\377\230\230"
  "\230\377\230\230\230\377\230\230\230\377\230\230\230\377\230\230\230\377"
  "\230\230\230\377\230\230\230\377\230\230\230\377\230\230\230\377\230\230"
  "\230\377\230\230\230\377\230\230\230\377\230\230\230\377\230\230\230\377"
  "\230\230\230\377\230\230\230\377\230\230\230\377\230\230\230\377\232\232"
  "\232\377\236\236\236\377\232\232\232\377\215\215\215\377\315\315\315\377"
  "\264\264\264\377\232\232\232\377\217\217\217\377\217\217\217\377\217\217"
  "\217\377\217\217\217\377\217\217\217\377\217\217\217\377\217\217\217\377"
  "\217\217\217\377\217\217\217\377\217\217\217\377\217\217\217\377\217\217"
  "\217\377\217\217\217\377\217\217\217\377\217\217\217\377\217\217\217\377"
  "\217\217\217\377\217\217\217\377\217\217\217\377\217\217\217\377\217\217"
  "\217\377\217\217\217\377\217\217\217\377\217\217\217\377\217\217\217\377"
  "\217\217\217\377\217\217\217\377\217\217\217\377\217\217\217\377\217\217"
  "\217\377\217\217\217\377\217\217\217\377\217\217\217\377\217\217\217\377"
  "\217\217\217\377\217\217\217\377\222\222\222\377\225\225\225\377\215\215"
  "\215\377\256\256\256\377\214\214\214\377~~~\377~~~\377~~~\377~~~\377~~~\377"
  "~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~"
  "~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377"
  "~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~~\377~~"
  "~\377~~~\377\202\202\202\377\207\207\207\377",
};
