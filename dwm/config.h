
/* |  _ \_   _|  Derek Taylor (DistroTube) */
/* | | | || |  	http://www.youtube.com/c/DistroTube */
/* | |_| || |  	http://www.gitlab.com/dwt1/ */
/* |____/ |_|  	*/ 

/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx = 1;   /* border pixel of windows */
static const unsigned int snap     = 24;  /* snap pixel */
static const unsigned int gappx    = 3;   /* pixel gap between clients */
static const int showbar           = 1;   /* 0 means no bar */
static const int topbar            = 1;   /* 0 means bottom bar */
static const int horizpadbar       = 6;   /* horizontal padding for statusbar */
static const int vertpadbar        = 7;   /* vertical padding for statusbar */
#include <X11/XF86keysym.h>
static const char *fonts[]         = { "Sarasa UI SC:style=bold:size=8:antialias=true:autohint=true",
                                  "JoyPixels:size=10:antialias=true:autohint=true"
						     	};
/* static const char col_gray1[]       = "#282a36"; */
/* static const char col_gray2[]       = "#ffb86c"; */
/* static const char col_gray3[]       = "#ff79c6"; */
/* static const char col_gray4[]       = "#ffb86c"; */
/* static const char col_cyan[]        = "#282a36"; */

static const char col_gray1[]       = "#201c1e";
static const char col_gray2[]       = "#E5E9F0";
static const char col_gray3[]       = "#E5E9F0";
static const char col_gray4[]       = "#E5E9F0";
static const char col_cyan[]        = "#9565f1";
/* bar opacity 
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * 0xdd adds adds a bit more transparency.
 * Play with the value to get desired transparency.
 */
static const unsigned int baralpha    = 0xdd; 
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]        = {
	/*               fg         bg         border   */
/*	[SchemeNorm] = { col_3, col_1, col_2 }, */
/*	[SchemeSel]  = { col_3, col_4, col_4 }, */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
        [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};
static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};   /* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* tagging */
 static const char *tags[] = { "1", "2", "3", "4", "5", "6" }; 
/* static const char *tags[] = { "", "", "", "", "", "", "", "", "" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
#include "tcl.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "HHH",      grid },
    { "|||",      tcl  },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(CHAIN,KEY,TAG) \
	{ MODKEY,                       CHAIN,    KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           CHAIN,    KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             CHAIN,    KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, CHAIN,    KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* dmenu */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* If you are using the standard dmenu program, use the following. */
static const char *dmenucmd[]    = { "dmenu_run", "-p", "Run: ", NULL };
/* If you are using the dmenu-distrotube-git program, use the following for a cooler dmenu! */
 /*static const char *dmenucmd[]    = { "dmenu_run", "-g", "10", "-l", "48", "-p", "Run: ", NULL }; */

/* the st terminal with tabbed */
static const char *termcmd[]     = { "st", NULL };
/* An alternative way to launch st along with the fish shell */
/* static const char *termcmd[]     = { "st", "-e fish", NULL }; */
static const char *tabtermcmd[]  = { "tabbed", "-r", "2", "st", "-w", "''", NULL };
static const char *brupcmd[] = { "xbacklight", "+7", NULL };
static const char *brdowncmd[] = { "xbacklight", "-7", NULL };
static const char *upvol[]   = { "inc_vol.sh", NULL };
static const char *downvol[] = { "dec_vol.sh", NULL};
static const char *mutevol[] = { "mute_vol.sh",  NULL };
static const char *togglepicom[] = { "comp.sh", NULL };
static const char *pulsemixer[] = { "st", "-e", "pulsemixer", NULL };
static const char *flameshot[] = { "flameshot", "gui", NULL };
static const char *screenshot_clipboard[] = { "maim-clipboard", NULL };
static const char *screenshot_full_save[] = { "maim-full-save", NULL };

static Key keys[] = {
	/* modifier             chain key  key        function        argument */
	{ MODKEY,               -1,        XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,               -1,        XK_Return, spawn,          {.v = termcmd } },
	{ Mod1Mask,             -1,        XK_Return, spawn,          {.v = tabtermcmd } },
    
    /* CUSTOM KEYBINDS */

	{ 0,                    -1,        XF86XK_MonBrightnessUp,    spawn,  {.v = brupcmd } },
	{ 0,                    -1,        XF86XK_MonBrightnessDown,  spawn,  {.v = brdowncmd } },
    { 0,                    -1,        XF86XK_AudioLowerVolume,   spawn,  {.v = downvol } },
	{ 0,                    -1,        XF86XK_AudioMute,          spawn,  {.v = mutevol } },
    { MODKEY,               -1,        XK_bracketleft,            spawn,  {.v = downvol } },
    { MODKEY,               -1,        XK_backslash,              spawn,  {.v = mutevol } },
    { MODKEY,               -1,        XK_bracketright,           spawn,  {.v = upvol   } },
	{ 0,                    -1,        XF86XK_AudioRaiseVolume,   spawn,  {.v = upvol   } },
	{ Mod1Mask|ControlMask, -1,        XK_equal,                  spawn,  {.v = togglepicom} },
    { Mod1Mask|ControlMask, -1,        XK_minus,                  spawn,  {.v = pulsemixer} },
    { MODKEY,               -1,        XK_Print,                  spawn,  {.v = flameshot}  },
    { 0,                    -1,        XK_Print,                         spawn,  {.v = screenshot_clipboard} },
    { Mod1Mask,             -1,        XK_Print,                  spawn,  {.v = screenshot_full_save} },

    { MODKEY,               -1,        XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,     -1,        XK_i,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,     -1,        XK_o,      rotatestack,    {.i = -1 } },
	{ MODKEY,               -1,        XK_j,      focusstack,     {.i = +1 } },
    { Mod1Mask,             -1,        XK_Tab,    focusstack,     {.i = +1 } },
	{ Mod1Mask,             -1,        -1,        focusstack,     {.i = +1 } },
	{ MODKEY,               -1,        XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,               -1,        XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,               -1,        XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,               -1,        XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,               -1,        XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask,   -1,        XK_Return, zoom,           {0} },
	{ MODKEY,               -1,        XK_Tab,    view,           {0} },
	{ MODKEY,               -1,        XK_q,      killclient,     {0} },

    /* Layout manipulation */
	{ MODKEY,               -1,        XK_period, cyclelayout,    {.i = -1 } },
	{ MODKEY|ShiftMask,     -1,        XK_Tab,    cyclelayout,    {.i = +1 } },
	{ MODKEY,               -1,        XK_comma,  setlayout,      {0} },
	{ MODKEY|ShiftMask,     -1,        XK_space,  togglefloating, {0} },
    { MODKEY,               -1,        XK_s,      togglesticky,   {0} },
    { MODKEY,               -1,        XK_f,      togglefullscr,  {0} },

    /* Switch to specific layouts */
	{ MODKEY,               -1,        XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,               -1,        XK_u,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,               -1,        XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,               -1,        XK_g,      setlayout,      {.v = &layouts[3]} },
    { MODKEY,               -1,        XK_y,      setlayout,      {.v = &layouts[4]} },

	{ MODKEY,               -1,        XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,     -1,        XK_0,      tag,            {.ui = ~0 } },

    /* Switching between monitors */
	{ MODKEY,               -1,        XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,               -1,        XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,     -1,        XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,     -1,        XK_period, tagmon,         {.i = +1 } },
	
    /* Keybindings for programs using the format SUPER + ALT + "key" */
	{ MODKEY|Mod1Mask,      -1,        XK_s,      spawn,          CMD("tabbed -r 2 surf -pe x '.surf/html/homepage.html'") },
	{ MODKEY|Mod1Mask,      -1,        XK_c,      spawn,          CMD("chromium") },
	{ MODKEY|Mod1Mask,      -1,        XK_m,      spawn,          CMD("mailspring") },
	{ MODKEY|Mod1Mask,      -1,        XK_f,      spawn,          CMD("thunar") },
    
    /* Doom emacs keybindings use the keychord CTRL + e followed by "key" */
	{ ControlMask,          XK_e,      XK_e,      spawn,          CMD("emacsclient -c -a 'emacs'") },
	{ ControlMask,          XK_e,      XK_b,      spawn,          CMD("emacsclient -c -a 'emacs' --eval '(ibuffer)'") },
	{ ControlMask,          XK_e,      XK_d,      spawn,          CMD("emacsclient -c -a 'emacs' --eval '(dired nil)'") },
	{ ControlMask,          XK_e,      XK_m,      spawn,          CMD("emacsclient -c -a 'emacs' --eval '(mu4e)'") },
	{ ControlMask,          XK_e,      XK_n,      spawn,          CMD("emacsclient -c -a 'emacs' --eval '(elfeed)'") },
	{ ControlMask,          XK_e,      XK_s,      spawn,          CMD("emacsclient -c -a 'emacs' --eval '(eshell)'") },
	{ ControlMask,          XK_e,      XK_v,      spawn,          CMD("emacsclient -c -a 'emacs' --eval '(+vterm/here nil)'") },

	TAGKEYS(                -1,        XK_1,                      0)
	TAGKEYS(                -1,        XK_2,                      1)
	TAGKEYS(                -1,        XK_3,                      2)
	TAGKEYS(                -1,        XK_4,                      3)
	TAGKEYS(                -1,        XK_5,                      4)
	TAGKEYS(                -1,        XK_6,                      5)
	TAGKEYS(                -1,        XK_7,                      6)
	TAGKEYS(                -1,        XK_8,                      7)
	TAGKEYS(                -1,        XK_9,                      8)
	{ MODKEY|ShiftMask,     -1,        XK_q,	  quit,		      {0} },
    { MODKEY|ShiftMask,     -1,        XK_r,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click           event mask   button          function        argument */
	{ ClkLtSymbol,     0,           Button1,        setlayout,      {0} },
	{ ClkLtSymbol,     0,           Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,     0,           Button2,        zoom,           {0} },
	{ ClkStatusText,   0,           Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,    MODKEY,      Button1,        movemouse,      {0} },
	{ ClkClientWin,    MODKEY,      Button2,        togglefloating, {0} },
	{ ClkClientWin,    MODKEY,      Button3,        resizemouse,    {0} },
	{ ClkTagBar,       0,           Button1,        view,           {0} },
	{ ClkTagBar,       0,           Button3,        toggleview,     {0} },
	{ ClkTagBar,       MODKEY,      Button1,        tag,            {0} },
	{ ClkTagBar,       MODKEY,      Button3,        toggletag,      {0} },
};


