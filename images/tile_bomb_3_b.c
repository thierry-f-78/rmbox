/* GIMP RGBA C-Source image dump (tile_bomb_3_b.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[42 * 42 * 4 + 1];
} gimp_image = {
  42, 42, 4,
  "\341\275\275\377\342\277\277\377\341\275\275\377\341\275\275\377\341\275"
  "\275\377\341\275\275\377\341\275\275\377\341\275\275\377\341\275\275\377"
  "\341\275\275\377\341\275\275\377\341\275\275\377\341\275\275\377\341\275"
  "\275\377\341\275\275\377\341\275\275\377\341\275\275\377\341\275\275\377"
  "\341\275\275\377\341\275\275\377\341\275\275\377\341\275\275\377\341\275"
  "\275\377\341\275\275\377\341\275\275\377\341\275\275\377\341\275\275\377"
  "\341\275\275\377\341\275\275\377\341\275\275\377\341\275\275\377\341\275"
  "\275\377\341\275\275\377\341\275\275\377\341\275\275\377\341\275\275\377"
  "\326\301\301\377\247\224\224\377\316\272\272\377\341\275\275\377\325\245"
  "\245\377\264ff\377\325\245\245\377\327\247\247\377\331\254\254\377\331\254"
  "\254\377\331\254\254\377\331\254\254\377\331\254\254\377\331\254\254\377"
  "\331\254\254\377\331\254\254\377\331\254\254\377\331\254\254\377\331\254"
  "\254\377\331\254\254\377\331\254\254\377\331\254\254\377\331\254\254\377"
  "\331\254\254\377\331\254\254\377\331\254\254\377\331\254\254\377\331\254"
  "\254\377\331\254\254\377\331\254\254\377\331\254\254\377\331\254\254\377"
  "\331\254\254\377\331\254\254\377\331\254\254\377\331\254\254\377\331\254"
  "\254\377\331\254\254\377\331\254\254\377\331\254\254\377\331\254\254\377"
  "\331\254\254\377\317\264\264\377\251\220\220\377\324\272\272\377\317\230"
  "\230\377\265hh\377\216--\377\317\230\230\377\317\230\230\377\321\234\234"
  "\377\321\234\234\377\323\241\241\377\323\241\241\377\323\241\241\377\323"
  "\241\241\377\323\241\241\377\323\241\241\377\323\241\241\377\323\241\241"
  "\377\323\241\241\377\323\241\241\377\323\241\241\377\323\241\241\377\323"
  "\241\241\377\323\241\241\377\323\241\241\377\323\241\241\377\323\241\241"
  "\377\323\241\241\377\323\241\241\377\323\241\241\377\323\241\241\377\323"
  "\241\241\377\323\241\241\377\323\241\241\377\323\241\241\377\323\241\241"
  "\377\323\241\241\377\323\241\241\377\323\241\241\377\323\241\241\377\323"
  "\241\241\377\323\241\241\377\315\257\257\377\245\211\211\377\271\230\230"
  "\377\265hh\377\230::\377\177\32\32\377\317\230\230\377\312\217\217\377\312"
  "\217\217\377\313\221\221\377\315\225\225\377\315\225\225\377\315\225\225"
  "\377\315\225\225\377\315\225\225\377\315\225\225\377\315\225\225\377\315"
  "\225\225\377\315\225\225\377\315\225\225\377\315\225\225\377\315\225\225"
  "\377\315\225\225\377\315\225\225\377\315\225\225\377\315\225\225\377\315"
  "\225\225\377\315\225\225\377\315\225\225\377\315\225\225\377\315\225\225"
  "\377\315\225\225\377\315\225\225\377\315\225\225\377\315\225\225\377\315"
  "\225\225\377\315\225\225\377\315\225\225\377\315\225\225\377\315\225\225"
  "\377\315\225\225\377\315\225\225\377\315\225\225\377\245\202\202\377\234"
  "rr\377\242LL\377\213))\377\177\32\32\377\317\230\230\377\312\217\217\377"
  "\306\206\206\377\306\206\206\377\307\210\210\377\310\212\212\377\312\217"
  "\217\377\312\217\217\377\312\217\217\377\312\217\217\377\312\217\217\377"
  "\312\217\217\377\312\217\217\377\312\217\217\377\312\217\217\377\312\217"
  "\217\377\312\217\217\377\312\217\217\377\312\217\217\377\312\217\217\377"
  "\312\217\217\377\312\217\217\377\312\217\217\377\312\217\217\377\312\217"
  "\217\377\312\217\217\377\312\217\217\377\312\217\217\377\312\217\217\377"
  "\312\217\217\377\312\217\217\377\312\217\217\377\312\217\217\377\312\217"
  "\217\377\312\217\217\377\312\217\217\377\302\200\200\377\272\220\220\377"
  "\202SS\377\234ff\377\213))\377\177\32\32\377\317\230\230\377\312\217\217"
  "\377\306\206\206\377\303\202\202\377\303\202\202\377\303\202\202\377\303"
  "\202\202\377\303\202\202\377\303\202\202\377\303\202\202\377\303\202\202"
  "\377\303\202\202\377\303\202\202\377\303\202\202\377\303\202\202\377\303"
  "\202\202\377\303\202\202\377\303\202\202\377\303\202\202\377\303\202\202"
  "\377\303\202\202\377\303\202\202\377\303\202\202\377\303\202\202\377\303"
  "\202\202\377\303\202\202\377\303\202\202\377\303\202\202\377\303\202\202"
  "\377\303\202\202\377\303\202\202\377\303\202\202\377\303\202\202\377\303"
  "\202\202\377\306\206\206\377\300||\377\265hh\377\277\220\220\377\211ZZ\377"
  "\215[[\377\253oo\377\177\32\32\377\317\230\230\377\312\217\217\377\306\206"
  "\206\377\303\202\202\377\302\200\200\377\300||\377\303\202\202\377\302\200"
  "\200\377\302\200\200\377\302\200\200\377\302\200\200\377\301~~\377\300||"
  "\377\300||\377\277zz\377\277zz\377\277zz\377\275vv\377\275vv\377\272rr\377"
  "\272rr\377\272rr\377\272rr\377\270nn\377\270nn\377\270nn\377\270nn\377\267"
  "ll\377\266jj\377\265hh\377\265hh\377\265hh\377\264ff\377\264ff\377\262cc"
  "\377\262cc\377\247QQ\377\235BB\377\247{{\377qBB\377\246nn\377\177\32\32\377"
  "\317\230\230\377\312\217\217\377\306\206\206\377\303\202\202\377\302\200"
  "\200\377\277zz\377\303\202\202\377\302\200\200\377\302\200\200\377\302\200"
  "\200\377\301~~\377\300||\377\300||\377\277zz\377\277zz\377\277zz\377\275"
  "vv\377\275vv\377\274tt\377\272rr\377\272rr\377\272rr\377\271pp\377\270nn"
  "\377\270nn\377\267ll\377\267ll\377\266jj\377\265hh\377\265hh\377\265hh\377"
  "\305\224\225\377\305\225\225\377\262cc\377\261aa\377\261aa\377\242JJ\377"
  "\235BB\377\261\210\210\377wJJ\377\231cc\377\177\32\32\377\317\230\230\377"
  "\312\217\217\377\306\206\206\377\303\202\202\377\302\200\200\377\277zz\377"
  "\302\200\200\377\302\200\200\377\302\200\200\377\302\200\200\377\300||\377"
  "\300||\377\300||\377\277zz\377\276xx\377\275vv\377\274tt\377\274tt\377\274"
  "tt\377\272rr\377\272rr\377\271pp\377\270nn\377\270nn\377\270nn\377\270nn"
  "\377\267ll\377\265hh\377\265hh\377\265hh\377\264\210\210\377\227nn\377\222"
  "kk\377\234uu\377\275\227\227\377\313\245\245\377\242JJ\377\235BB\377\302"
  "\234\234\377vKK\377\214XX\377\177\32\32\377\317\230\230\377\312\217\217\377"
  "\306\206\206\377\303\202\202\377\302\200\200\377\277zz\377\302\200\200\377"
  "\302\200\200\377\301~~\377\300||\377\300||\377\300||\377\300||\377\277zz"
  "\377\275vv\377\274tt\377\272rr\377\272rr\377\272rr\377\272rr\377\272rr\377"
  "\270nn\377\270nn\377\267ll\377\267ll\377\267ll\377\265hh\377\265hh\377\265"
  "hh\377\263\211\212\377\210bc\377\242}~\377\232vw\377\204ab\377\177]]\377"
  "\225ss\377\304\241\241\377\235BB\377\276\232\232\377xMM\377\216YY\377\177"
  "\32\32\377\317\230\230\377\312\217\217\377\306\206\206\377\303\202\202\377"
  "\302\200\200\377\277zz\377\302\200\200\377\300||\377\300||\377\300||\377"
  "\300||\377\277zz\377\317\253\253\377\315\254\254\377\271\231\231\377\264"
  "\223\224\377\264\224\224\377\272\231\232\377\305\244\244\377\320\250\250"
  "\377\305\215\215\377\270nn\377\270nn\377\270nn\377\267ll\377\265hh\377\265"
  "hh\377\311\240\241\377\255\207\210\377\206cd\377\253\210\211\377\313\251"
  "\251\377\317\254\254\377\312\247\247\377\214ii\377wUU\377vRR\377\213gg\377"
  "\177XX\377l??\377\247oo\377\177\32\32\377\317\230\230\377\312\217\217\377"
  "\306\206\206\377\303\202\202\377\302\200\200\377\277zz\377\302\200\200\377"
  "\300||\377\300||\377\277zz\377\301\237\240\377\263\226\226\377\215tt\377"
  "{dd\377_IJ\377WBB\377YDE\377bLM\377{cd\377\206kl\377\241\204\204\377\274"
  "\233\234\377\314\250\251\377\266jj\377\265hh\377\265hh\377\305\241\242\377"
  "\237\177\200\377wWY\377\207gh\377\277\235\237\377\261aa\377\261aa\377\257"
  "__\377\273zz\377\237xx\377\214bb\377vLL\377|OO\377\242nn\377\252mm\377\177"
  "\32\32\377\317\230\230\377\312\217\217\377\306\206\206\377\303\202\202\377"
  "\302\200\200\377\277zz\377\300||\377\300||\377\323\260\261\377\261\223\224"
  "\377w_`\377S>?\377C24\3778)*\377/!\"\3771$%\377,\37\40\377,\37\40\377*\33"
  "\34\3772\40!\377D00\377W@A\377\222yz\377\270\234\235\377\305\212\213\377"
  "\277\243\244\377\227{}\377fLM\377Q68\377sUV\377\265\222\223\377\261aa\377"
  "\257__\377\257__\377\256]]\377\255[[\377\275\212\212\377\265\201\201\377"
  "\267\200\200\377\260rr\377\213))\377\177\32\32\377\317\230\230\377\312\217"
  "\217\377\306\206\206\377\303\202\202\377\302\200\200\377\277zz\377\300||"
  "\377\321\257\260\377\241\207\207\377VAB\377=,-\3773&(\3770%(\377/&(\377/"
  "'(\3771)*\377&\37\40\377!\27\30\377\40\26\27\377\30\15\15\377\34\20\20\377"
  "#\26\26\377)\30\30\377ZGH\377\201ln\377\205qr\377ZFH\377>)+\3779!\"\377e"
  "GH\377\271\223\224\377\257__\377\257__\377\257__\377\255[[\377\255[[\377"
  "\242JJ\377\235BB\377\232==\377\22444\377\213))\377\177\32\32\377\317\230"
  "\230\377\312\217\217\377\306\206\206\377\303\202\202\377\302\200\200\377"
  "\277zz\377\315\254\254\377\231\177\200\377D01\3771#$\377)\36\40\377-&(\377"
  "0*-\377836\377:68\377<78\377=78\377*$%\377$\35\36\377\31\22\23\377\32\22"
  "\23\377\32\21\21\377\32\15\17\377\"\24\26\3774&'\377@13\377-\35\36\377-\33"
  "\34\377U>?\377\260\220\221\377\312\242\242\377\257__\377\256]]\377\255[["
  "\377\255[[\377\255[[\377\242JJ\377\235BB\377\232==\377\22444\377\213))\377"
  "\177\32\32\377\317\230\230\377\312\217\217\377\306\206\206\377\303\202\202"
  "\377\302\200\200\377\320\255\256\377\234\201\202\377@-.\377,\37\37\377%\34"
  "\36\377*$'\377=8;\377JGI\377PMP\377TQT\377QNO\377LHI\377?;<\3770+,\377\35"
  "\30\31\377\21\14\15\377\32\22\24\377\30\17\21\377\34\22\24\377\23\10\12\377"
  "\34\21\23\377!\24\25\377M==\377\265\235\236\377\322\261\262\377\257__\377"
  "\256]]\377\255[[\377\255[[\377\255[[\377\254YY\377\242JJ\377\235BB\377\232"
  "==\377\22444\377\213))\377\177\32\32\377\317\230\230\377\312\217\217\377"
  "\306\206\206\377\303\202\202\377\302\200\200\377\252\215\216\377UAB\3770"
  "\"#\377!\30\32\377(\"$\377>:=\377SPS\377a_b\377dbf\377gei\377dbe\377ZWY\377"
  "LHJ\3772./\377)%&\377\35\27\31\377!\32\34\377!\32\34\377&\37!\377!\31\33"
  "\377\26\15\16\377&\33\34\377xgh\377\316\265\266\377\257__\377\256]]\377\255"
  "[[\377\255[[\377\255[[\377\254YY\377\254YY\377\242JJ\377\235BB\377\232=="
  "\377\22444\377\213))\377\177\32\32\377\317\230\230\377\312\217\217\377\306"
  "\206\206\377\303\202\202\377\277\240\241\377s]]\377A12\377%\33\35\377$\35"
  "\40\377=8;\377NKN\377_]`\377ljm\377qos\377mkp\377fdi\377^\\a\377UQV\377@"
  ";>\377(\"$\377(\"$\377*$&\377.(*\377.')\3772+-\377,%&\377%\33\34\377YIJ\377"
  "\261\231\231\377\257__\377\255[[\377\255[[\377\255[[\377\254YY\377\253XX"
  "\377\252VV\377\242JJ\377\235BB\377\232==\377\22444\377\213))\377\177\32\32"
  "\377\317\230\230\377\312\217\217\377\306\206\206\377\320\256\256\377\243"
  "\212\212\377aOP\377:.1\377!\32\35\3770+.\377>;>\377RPS\377cad\377mkp\377"
  "nlq\377igl\377a_d\377ZX]\377SQV\377GCG\3775/2\377.(*\3774.0\377JDF\377WR"
  "S\377GBC\377B<=\3772()\3771!\"\377\211qr\377\307\244\245\377\255[[\377\255"
  "[[\377\255[[\377\254YY\377\252VV\377\252VV\377\242JJ\377\235BB\377\232=="
  "\377\22444\377\213))\377\177\32\32\377\317\230\230\377\312\217\217\377\306"
  "\206\206\377\312\254\254\377\201kl\377XJK\377=46\377+&(\377,),\377;8;\377"
  "NLO\377a_d\377gej\377ech\377^\\a\377YW\\\377SQV\377LIO\377B@E\377616\377"
  "3.1\377KEG\377hcd\377|xy\377zuv\377e__\377H@A\3776)*\377WAB\377\270\230\230"
  "\377\255[[\377\255[[\377\254YY\377\252VV\377\252VV\377\252VV\377\242JJ\377"
  "\235BB\377\232==\377\22444\377\213))\377\177\32\32\377\317\230\230\377\312"
  "\217\217\377\306\206\206\377\252\217\217\377m[\\\377OCE\377=58\3771-0\377"
  "+(+\377647\377ECH\377RPU\377\\Z_\377ZX]\377TRW\377NKQ\377HEL\377C@G\3779"
  "7=\3771/4\377959\377VQT\377vrs\377\217\213\214\377\221\214\215\377\204\177"
  "\200\377hab\377@56\377M:;\377\221tt\377\312\240\240\377\252VV\377\253XX\377"
  "\252VV\377\252VV\377\252VV\377\242JJ\377\235BB\377\232==\377\22444\377\213"
  "))\377\177\32\32\377\317\230\230\377\312\217\217\377\317\240\240\377\242"
  "\211\213\377dTV\377MCE\377@:=\377403\377*'*\3770.3\377649\377?=B\377HFK\377"
  "MKP\377GEK\377?<C\377:7>\37775<\377.-3\377,*0\377649\377URU\377wuv\377\223"
  "\217\220\377\224\217\220\377\210\203\204\377jcd\377A78\377@/0\377\203hh\377"
  "\312\242\243\377\252VV\377\252VV\377\252VV\377\251TT\377\250RR\377\242JJ"
  "\377\235BB\377\232==\377\22444\377\213))\377\177\32\32\377\317\230\230\377"
  "\312\217\217\377\316\257\260\377\220z|\377SEG\377F=@\377947\377)&)\377'%"
  ")\377*(-\377+).\377,*/\377427\37786;\37763:\3770-4\377+)/\377+*0\377&%+\377"
  "%$)\377/.2\377GGI\377ifi\377\203\200\202\377\223\217\220\377{xy\377b]^\377"
  "D;<\377+\34\34\377oUV\377\272\225\225\377\252VV\377\252VV\377\251TT\377\250"
  "RR\377\247QQ\377\242JJ\377\235BB\377\232==\377\22444\377\213))\377\177\32"
  "\32\377\317\230\230\377\312\217\217\377\307\250\252\377vac\377J=?\377@8;"
  "\377614\377*',\377#!&\377\"\40%\377\33\31\36\377\34\32\37\377\40\36$\377"
  "\"\37&\377!\36%\377\35\33\"\377\30\27\35\377\32\31\37\377\32\31\36\377\32"
  "\31\36\377%$)\37787<\377ONQ\377ede\377rpq\377spq\377XTU\377;33\377-\36\37"
  "\377T<<\377\256\212\212\377\252VV\377\252VV\377\247QQ\377\250RR\377\247Q"
  "Q\377\242JJ\377\235BB\377\232==\377\22444\377\213))\377\177\32\32\377\317"
  "\230\230\377\312\217\217\377\316\260\261\377\177jl\377NAC\377=58\377=8<\377"
  "/,1\377%#(\377\30\26\33\377\17\15\22\377\17\14\22\377\23\20\27\377\16\13"
  "\22\377\16\14\22\377\13\12\20\377\13\12\20\377\14\13\20\377\15\14\21\377"
  "\20\17\24\377\26\25\32\377#\"'\377326\377BBD\377RQR\377UST\377>::\3773+,"
  "\377*\34\34\377L44\377\257\213\213\377\250RR\377\250RR\377\247QQ\377\247"
  "QQ\377\246OO\377\242JJ\377\235BB\377\232==\377\22444\377\213))\377\177\32"
  "\32\377\317\230\230\377\312\217\217\377\311\253\254\377{eg\377H;=\3778/4"
  "\3773.3\377-*/\377\37\35\"\377\26\24\31\377\12\10\15\377\5\2\11\377\5\3\11"
  "\377\4\2\11\377\2\1\7\377\3\3\10\377\4\3\11\377\4\3\10\377\6\5\12\377\10"
  "\7\14\377\13\12\17\377\16\15\22\377\30\30\32\377%%'\377224\377423\377$\37"
  "\40\377\"\33\34\377$\26\26\377R::\377\256\210\210\377\250RR\377\247QQ\377"
  "\247QQ\377\246OO\377\246OO\377\242JJ\377\235BB\377\232==\377\22444\377\213"
  "))\377\177\32\32\377\317\230\230\377\312\217\217\377\323\263\263\377\217"
  "yy\377E68\3773*.\377,',\377#\40%\377\40\36#\377\31\27\35\377\17\14\23\377"
  "\4\1\10\377\0\0\5\377\0\0\5\377\1\0\6\377\0\0\4\377\1\0\5\377\3\2\7\377\2"
  "\1\6\377\2\1\6\377\3\2\7\377\5\5\10\377\7\7\11\377\20\20\22\377\26\26\30"
  "\377\20\17\21\377\22\16\16\377\36\27\27\377\37\20\20\377`FF\377\270\220\220"
  "\377\247QQ\377\246OO\377\246OO\377\246OO\377\246OO\377\242JJ\377\235BB\377"
  "\232==\377\22444\377\213))\377\177\32\32\377\317\230\230\377\312\217\217"
  "\377\306\206\206\377\230\200\200\377O@@\377:03\377-'+\377&#(\377$\"'\377"
  "\35\32!\377\17\14\23\377\6\4\13\377\0\0\5\377\0\0\5\377\1\0\5\377\2\1\6\377"
  "\0\0\4\377\1\0\5\377\1\0\5\377\0\0\3\377\0\0\2\377\2\2\4\377\3\3\5\377\2"
  "\2\4\377\6\5\7\377\6\4\6\377\17\13\13\377\30\17\17\377+\31\31\377sUU\377"
  "\304\231\231\377\247QQ\377\247QQ\377\246OO\377\246OO\377\245MM\377\242JJ"
  "\377\235BB\377\232==\377\22444\377\213))\377\177\32\32\377\317\230\230\377"
  "\312\217\217\377\306\206\206\377\254\223\223\377UEE\3774),\377+$(\377'\""
  "'\377'#*\377\31\26\35\377\17\14\23\377\12\11\17\377\4\3\11\377\0\0\4\377"
  "\0\0\3\377\1\0\5\377\0\0\4\377\0\0\3\377\0\0\3\377\0\0\2\377\0\0\2\377\0"
  "\0\2\377\0\0\2\377\1\1\3\377\2\2\2\377\10\5\5\377\16\10\10\377\32\16\16\377"
  "6!!\377\231ww\377\247QQ\377\246OO\377\246OO\377\246OO\377\246OO\377\245M"
  "M\377\242JJ\377\235BB\377\232==\377\22444\377\213))\377\177\32\32\377\317"
  "\230\230\377\312\217\217\377\306\206\206\377\301\246\246\377gUU\3778-/\377"
  "(!$\377!\34!\377&\")\377\35\33!\377\26\25\33\377\20\17\25\377\10\7\14\377"
  "\2\2\6\377\0\0\3\377\0\0\3\377\0\0\3\377\0\0\3\377\0\0\2\377\0\0\2\377\0"
  "\0\2\377\0\0\2\377\3\3\5\377\3\3\4\377\4\2\2\377\11\4\4\377\22\11\11\377"
  "\"\21\21\377G,,\377\253\205\205\377\246OO\377\246OO\377\246OO\377\246OO\377"
  "\245MM\377\242JJ\377\242JJ\377\235BB\377\232==\377\22444\377\213))\377\177"
  "\32\32\377\317\230\230\377\312\217\217\377\306\206\206\377\314\255\255\377"
  "\210ss\3779,,\377*\"$\377\"\36!\377#!&\377\36\35#\377\33\32\40\377\25\24"
  "\31\377\15\14\21\377\5\4\11\377\1\1\5\377\0\0\3\377\0\0\3\377\0\0\2\377\0"
  "\0\2\377\2\2\4\377\1\1\3\377\2\2\4\377\4\3\4\377\4\2\2\377\14\10\10\377\21"
  "\11\11\377\33\15\15\3770\32\32\377\206ee\377\303\226\226\377\246OO\377\246"
  "OO\377\245MM\377\245MM\377\242JJ\377\242JJ\377\242JJ\377\235BB\377\232=="
  "\377\22444\377\213))\377\177\32\32\377\317\230\230\377\312\217\217\377\306"
  "\206\206\377\304\205\205\377\242\212\212\377K<<\377,\"\"\377!\34\37\377\37"
  "\34!\377\40\36#\377\35\34\"\377\31\30\35\377\23\22\27\377\14\13\20\377\7"
  "\6\13\377\4\4\10\377\2\2\5\377\1\1\3\377\1\1\3\377\0\0\2\377\2\2\4\377\3"
  "\2\3\377\4\2\2\377\10\4\4\377\22\13\13\377\32\15\15\377(\24\24\377aCC\377"
  "\252\200\200\377\246OO\377\246OO\377\246OO\377\245MM\377\244LL\377\242JJ"
  "\377\242JJ\377\242JJ\377\235BB\377\232==\377\22444\377\213))\377\177\32\32"
  "\377\317\230\230\377\312\217\217\377\306\206\206\377\317\252\252\377\312"
  "\256\256\377zff\377.\37\"\377)\40%\377\37\32\36\377\37\34!\377\40\36#\377"
  "\34\33\40\377\31\30\35\377\25\24\31\377\21\21\25\377\17\17\21\377\13\13\15"
  "\377\11\11\13\377\14\14\16\377\7\6\10\377\7\6\7\377\4\2\2\377\10\4\4\377"
  "\17\7\7\377\31\15\15\377)\25\25\377O33\377\220ii\377\246OO\377\246OO\377"
  "\245MM\377\245MM\377\242JJ\377\242JJ\377\242JJ\377\241HH\377\242JJ\377\235"
  "BB\377\232==\377\22444\377\213))\377\177\32\32\377\317\230\230\377\312\217"
  "\217\377\306\206\206\377\303\202\202\377\303\242\242\377\267\236\237\377"
  "]IM\377!\25\30\377\36\27\32\377\34\30\33\377\37\33\36\377\37\36!\377\37\35"
  "\"\377\35\34!\377\35\35\37\377\34\33\35\377\30\27\31\377\27\26\30\377\22"
  "\20\22\377\14\12\13\377\12\7\7\377\12\5\5\377\22\11\11\377\32\14\14\377("
  "\24\24\377N22\377\206``\377\246OO\377\246OO\377\246OO\377\245MM\377\244L"
  "L\377\242JJ\377\242JJ\377\242JJ\377\241HH\377\242JJ\377\235BB\377\232==\377"
  "\22444\377\213))\377\177\32\32\377\317\230\230\377\312\217\217\377\306\206"
  "\206\377\303\202\202\377\302\200\200\377\256\216\221\377\237\204\207\377"
  "SAC\377\35\21\22\377\27\20\20\377\32\26\27\377\37\34\34\377%#%\377(%(\377"
  "(&(\377*(*\377)&(\377*'(\377*&'\377+%%\377'\40\40\377#\30\30\377%\25\25\377"
  "/\31\31\377^AA\377\216gg\377\246OO\377\246OO\377\245MM\377\244LL\377\242"
  "JJ\377\242JJ\377\242JJ\377\242JJ\377\241HH\377\240GG\377\242JJ\377\235BB"
  "\377\232==\377\22444\377\213))\377\177\32\32\377\317\230\230\377\312\217"
  "\217\377\306\206\206\377\303\202\202\377\302\200\200\377\272rr\377\236z|"
  "\377\224z{\377R@@\377)\35\35\377$\33\32\377%\37\35\377*%%\377/+,\3774.0\377"
  "<68\3775/1\377<56\377E<<\377E::\377C55\377F33\377P88\377}^^\377\240xx\377"
  "\246OO\377\246OO\377\246OO\377\245MM\377\244LL\377\242JJ\377\242JJ\377\242"
  "JJ\377\241HH\377\240GG\377\237EE\377\242JJ\377\235BB\377\232==\377\22444"
  "\377\213))\377\177\32\32\377\317\230\230\377\312\217\217\377\306\206\206"
  "\377\303\202\202\377\274tt\377\255[[\377\241HH\377\216ee\377\217pp\377fO"
  "O\377O>=\377E84\377?41\377D87\377D77\377J=>\377I;<\377H88\377UBB\377`JJ\377"
  "hNN\377\207gg\377\237yy\377\266\210\210\377\235BB\377\235BB\377\235BB\377"
  "\235BB\377\235BB\377\235BB\377\235BB\377\235BB\377\235BB\377\235BB\377\234"
  "@@\377\235BB\377\236CC\377\234@@\377\232==\377\22444\377\213))\377\177\32"
  "\32\377\317\230\230\377\312\217\217\377\306\206\206\377\275vv\377\255[[\377"
  "\235BB\377\22799\377\22799\377\224hh\377\235zy\377\222vr\377\203kg\377q["
  "X\377\204ml\377\213ts\377\200hh\377\202hh\377\204gg\377\220pp\377\233ww\377"
  "\264\213\213\377\271\212\212\377\22799\377\22799\377\22799\377\22799\377"
  "\22799\377\22799\377\22799\377\22799\377\22799\377\22799\377\22799\377\227"
  "99\377\22799\377\22799\377\230::\377\233??\377\232==\377\22444\377\213))"
  "\377\177\32\32\377\317\230\230\377\312\217\217\377\277zz\377\254YY\377\232"
  "==\377\22000\377\22000\377\22000\377\22000\377\246us\377\266\214\211\377"
  "\260\212\207\377\254\207\204\377\263\216\213\377\302\234\233\377\300\231"
  "\230\377\272\221\221\377\267\213\213\377\274\214\214\377\22000\377\22000"
  "\377\22000\377\22000\377\22000\377\22000\377\22000\377\22000\377\22000\377"
  "\22000\377\22000\377\22000\377\22000\377\22000\377\22000\377\22000\377\220"
  "00\377\22000\377\22333\377\22799\377\22444\377\213))\377\177\32\32\377\317"
  "\230\230\377\300||\377\252VV\377\22444\377\211&&\377\211&&\377\211&&\377"
  "\211&&\377\211&&\377\211&&\377\257us\377\233IH\377\247ba\377\211&&\377\211"
  "&&\377\211&&\377\211&&\377\211&&\377\211&&\377\211&&\377\211&&\377\211&&"
  "\377\211&&\377\211&&\377\211&&\377\211&&\377\211&&\377\211&&\377\211&&\377"
  "\211&&\377\211&&\377\211&&\377\211&&\377\211&&\377\211&&\377\211&&\377\211"
  "&&\377\211&&\377\213))\377\22000\377\213))\377\177\32\32\377\302\200\200"
  "\377\247QQ\377\213))\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33"
  "\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33"
  "\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377"
  "\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200"
  "\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33"
  "\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33"
  "\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377\200\33\33\377"
  "\200\33\33\377\204\40\40\377\206\"\"\377\177\32\32\377\241HH\377}\30\30\377"
  "l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14"
  "\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14"
  "\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377"
  "l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14"
  "\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377l\14"
  "\14\377l\14\14\377l\14\14\377l\14\14\377l\14\14\377s\15\15\377x\22\22\377",
};
