/* usplash
 *
 * eft-theme.c - definition of eft theme
 *
 * Copyright © 2006 Dennis Kaarsemaker <dennis@kaarsemaker.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include <usplash-theme.h>
/* Needed for the custom drawing functions */
#include <usplash_backend.h>
extern struct usplash_pixmap pixmap_logo_xsmall, pixmap_logo_small,
       pixmap_logo_med, pixmap_logo_large, pixmap_logo_xlarge;
extern struct usplash_pixmap pixmap_throbber_back;
extern struct usplash_pixmap pixmap_throbber_back_16;
extern struct usplash_pixmap pixmap_throbber_back_32;
extern struct usplash_pixmap pixmap_throbber_fore;
extern struct usplash_pixmap pixmap_throbber_fore_16;
extern struct usplash_pixmap pixmap_throbber_fore_32;

void t_init(struct usplash_theme* theme);
void t_clear_progressbar(struct usplash_theme* theme);
void t_clear_progressbar_16(struct usplash_theme* theme);
void t_clear_progressbar_32(struct usplash_theme* theme);
void t_draw_progressbar(struct usplash_theme* theme, int percentage);
void t_draw_progressbar_16(struct usplash_theme* theme, int percentage);
void t_draw_progressbar_32(struct usplash_theme* theme, int percentage);
void t_animate_step(struct usplash_theme* theme, int pulsating);
void t_animate_step_16(struct usplash_theme* theme, int pulsating);
void t_animate_step_32(struct usplash_theme* theme, int pulsating);

struct usplash_theme usplash_theme;
struct usplash_theme usplash_theme_640_480;
struct usplash_theme usplash_theme_800_500;
struct usplash_theme usplash_theme_800_600;
struct usplash_theme usplash_theme_896_672;
struct usplash_theme usplash_theme_1024_576;
struct usplash_theme usplash_theme_1024_600;
struct usplash_theme usplash_theme_1024_640;
struct usplash_theme usplash_theme_1024_768;
struct usplash_theme usplash_theme_1152_720;
struct usplash_theme usplash_theme_1280_800;
struct usplash_theme usplash_theme_1280_1024;
struct usplash_theme usplash_theme_1440_900;
struct usplash_theme usplash_theme_1600_1200;
struct usplash_theme usplash_theme_1920_1200;

/* Theme definition */
struct usplash_theme usplash_theme = {
	.version = THEME_VERSION, /* ALWAYS set this to THEME_VERSION, 
                                 it's a compatibility check */
    .next = &usplash_theme_640_480,
    .ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_logo_xsmall,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 640,
        .theme_height = 400,

        /* position of pixmap */
        .pixmap_x = 292,
        .pixmap_y = 165,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 198,
  	.progressbar_y      = 190,
  	.progressbar_width  = 244,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 96,
  	.text_y      = 246,
  	.text_width  = 360,
  	.text_height = 100,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_16,
    .draw_progressbar = t_draw_progressbar_16,
    .animate_step = t_animate_step_16,
};

struct usplash_theme usplash_theme_640_480 = {
	.version = THEME_VERSION, /* ALWAYS set this to THEME_VERSION, 
                                 it's a compatibility check */
    .next = &usplash_theme_800_500,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_logo_xsmall,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 640,
        .theme_height = 480,

        /* position of pixmap */
        .pixmap_x = 292,
        .pixmap_y = 204,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 198,
  	.progressbar_y      = 233,
  	.progressbar_width  = 244,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 120,
  	.text_y      = 307,
  	.text_width  = 360,
  	.text_height = 100,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_16,
    .draw_progressbar = t_draw_progressbar_16,
    .animate_step = t_animate_step_16,
};

struct usplash_theme usplash_theme_800_500 = {
	.version = THEME_VERSION, /* ALWAYS set this to THEME_VERSION, 
                                 it's a compatibility check */
    .next = &usplash_theme_800_600,
    .ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_logo_xsmall,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 800,
        .theme_height = 500,

        /* position of pixmap */
        .pixmap_x = 372,
        .pixmap_y = 213,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 278,
  	.progressbar_y      = 242,
  	.progressbar_width  = 244,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 220,
  	.text_y      = 360,
  	.text_width  = 360,
  	.text_height = 120,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_16,
    .draw_progressbar = t_draw_progressbar_16,
    .animate_step = t_animate_step_16,
};

struct usplash_theme usplash_theme_800_600 = {
	.version = THEME_VERSION, /* ALWAYS set this to THEME_VERSION, 
                                 it's a compatibility check */
    .next = &usplash_theme_896_672,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_logo_xsmall,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 800,
        .theme_height = 600,

        /* position of pixmap */
        .pixmap_x = 372,
        .pixmap_y = 261,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 278,
  	.progressbar_y      = 292,
  	.progressbar_width  = 244,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 220,
  	.text_y      = 410,
  	.text_width  = 360,
  	.text_height = 150,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_16,
    .draw_progressbar = t_draw_progressbar_16,
    .animate_step = t_animate_step_16,
};

struct usplash_theme usplash_theme_896_672 = {
	.version = THEME_VERSION, /* ALWAYS set this to THEME_VERSION, 
                                 it's a compatibility check */
    .next = &usplash_theme_1024_600,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_logo_xsmall,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 896,
        .theme_height = 672,

        /* position of pixmap */
        .pixmap_x = 420,
        .pixmap_y = 296,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 326,
  	.progressbar_y      = 328,
  	.progressbar_width  = 244,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 268,
  	.text_y      = 410,
  	.text_width  = 360,
  	.text_height = 150,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_16,
    .draw_progressbar = t_draw_progressbar_16,
    .animate_step = t_animate_step_16,
};

struct usplash_theme usplash_theme_1024_576 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1024_600,
    .ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_logo_small,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1024,
        .theme_height = 576,

        /* position of pixmap */
        .pixmap_x = 467,
        .pixmap_y = 215,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 358,
  	.progressbar_y      = 309,
  	.progressbar_width  = 308,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 322,
  	.text_y      = 390,
  	.text_width  = 380,
  	.text_height = 160,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar,
    .draw_progressbar = t_draw_progressbar,
    .animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1024_600 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1024_640,
    .ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_logo_small,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1024,
        .theme_height = 600,

        /* position of pixmap */
        .pixmap_x = 467,
        .pixmap_y = 220,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 358,
  	.progressbar_y      = 309,
  	.progressbar_width  = 308,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 322,
  	.text_y      = 400,
  	.text_width  = 380,
  	.text_height = 180,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar,
    .draw_progressbar = t_draw_progressbar,
    .animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1024_640 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1024_768,
    .ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_logo_small,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1024,
        .theme_height = 640,

        /* position of pixmap */
        .pixmap_x = 467,
        .pixmap_y = 290,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 358,
  	.progressbar_y      = 309,
  	.progressbar_width  = 308,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 322,
  	.text_y      = 400,
  	.text_width  = 380,
  	.text_height = 200,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar,
    .draw_progressbar = t_draw_progressbar,
    .animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1024_768 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1152_720,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_logo_small,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1024,
        .theme_height = 768,

        /* position of pixmap */
        .pixmap_x = 467,
        .pixmap_y = 325,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 358,
  	.progressbar_y      = 373,
  	.progressbar_width  = 308,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 322,
  	.text_y      = 475,
  	.text_width  = 380,
  	.text_height = 200,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar,
    .draw_progressbar = t_draw_progressbar,
    .animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1152_720 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1280_1024,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_logo_small,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1152,
        .theme_height = 720,

        /* position of pixmap */
        .pixmap_x = 531,
        .pixmap_y = 302,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 422,
  	.progressbar_y      = 349,
  	.progressbar_width  = 308,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 386,
  	.text_y      = 465,
  	.text_width  = 380,
  	.text_height = 200,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar,
    .draw_progressbar = t_draw_progressbar,
    .animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1280_800 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1280_1024,
    .ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_logo_med,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1280,
        .theme_height = 800,

        /* position of pixmap */
        .pixmap_x = 584,
        .pixmap_y = 330,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 486,
  	.progressbar_y      = 389,
  	.progressbar_width  = 308,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 450,
  	.text_y      = 600,
  	.text_width  = 380,
  	.text_height = 180,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar,
    .draw_progressbar = t_draw_progressbar,
    .animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1280_1024 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1440_900,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_logo_med,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1280,
        .theme_height = 1024,

        /* position of pixmap */
        .pixmap_x = 584,
        .pixmap_y = 437,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 486,
  	.progressbar_y      = 501,
  	.progressbar_width  = 308,
  	.progressbar_height = 3,

	/* Text box position and size in pixels */
  	.text_x      = 450,
  	.text_y      = 600,
  	.text_width  = 380,
  	.text_height = 200,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar,
    .draw_progressbar = t_draw_progressbar,
    .animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1440_900 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1600_1200,
    .ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_logo_med,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1440,
        .theme_height = 900,

        /* position of pixmap */
        .pixmap_x = 664,
        .pixmap_y = 350,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 500,
  	.progressbar_y      = 437,
  	.progressbar_width  = 420,
  	.progressbar_height = 4,

	/* Text box position and size in pixels */
  	.text_x      = 530,
  	.text_y      = 500,
  	.text_width  = 380,
  	.text_height = 200,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_32,
    .draw_progressbar = t_draw_progressbar_32,
    .animate_step = t_animate_step_32,
};

struct usplash_theme usplash_theme_1600_1200 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1920_1200,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_logo_large,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1600,
        .theme_height = 1200,

        /* position of pixmap */
        .pixmap_x = 730,
        .pixmap_y = 509,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 590,
  	.progressbar_y      = 584,
  	.progressbar_width  = 420,
  	.progressbar_height = 4,

	/* Text box position and size in pixels */
  	.text_x      = 550,
  	.text_y      = 680,
  	.text_width  = 500,
  	.text_height = 400,

	/* Text details */
  	.line_height  = 18,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_32,
    .draw_progressbar = t_draw_progressbar_32,
    .animate_step = t_animate_step_32,
};

struct usplash_theme usplash_theme_1920_1200 = {
	.version = THEME_VERSION,
    .next = NULL,
    .ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_logo_large,

        /* theme resolution; if 0, use width/height of pixmap */
        .theme_width = 1920,
        .theme_height = 1200,

        /* position of pixmap */
        .pixmap_x = 890,
        .pixmap_y = 509,

	/* Palette indexes */
	.background             = 0,
  	.progressbar_background = 73,
  	.progressbar_foreground = 168,
	.text_background        = 0,
	.text_foreground        = 168,
	.text_success           = 128,
	.text_failure           = 227,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 750,
  	.progressbar_y      = 584,
  	.progressbar_width  = 420,
  	.progressbar_height = 4,

	/* Text box position and size in pixels */
  	.text_x      = 710,
  	.text_y      = 680,
  	.text_width  = 500,
  	.text_height = 400,

	/* Text details */
  	.line_height  = 18,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_32,
    .draw_progressbar = t_draw_progressbar_32,
    .animate_step = t_animate_step_32,
};

void t_init(struct usplash_theme *theme) {
    int x, y;
    usplash_getdimensions(&x, &y);
    theme->progressbar_x = (x - usplash_theme_width(theme))/2 + theme->progressbar_x;
    theme->progressbar_y = (y - usplash_theme_height(theme))/2 + theme->progressbar_y;
}

#if 0 
/* disable progress bar in Ubuntu 9.10 due to faster boot */

void t_clear_progressbar(struct usplash_theme *theme) {
    usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back);
}

void t_clear_progressbar_16(struct usplash_theme *theme) {
    usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_16);
}

void t_clear_progressbar_32(struct usplash_theme *theme) {
    usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_32);
}

void t_draw_progressbar(struct usplash_theme *theme, int percentage) {
    int w = (pixmap_throbber_back.width * percentage / 100);
    if(percentage == 0)
        usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back);
    if(percentage < 0){/* Unloading */
        w *= -1;
        /* Draw background to left of foreground */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back.height, 
                         &pixmap_throbber_back, 0, 0);
        /* Draw foreground to right of background */
        usplash_put_part(theme->progressbar_x + w, theme->progressbar_y, pixmap_throbber_back.width - w,
                         pixmap_throbber_back.height, &pixmap_throbber_fore, w, 0);
    }
    else{/* Loading */
        /* Draw foreground to left of background */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back.height, 
                         &pixmap_throbber_fore, 0, 0);
        /* Draw background ot right of foreground */
        usplash_put_part(theme->progressbar_x + w, theme->progressbar_y, pixmap_throbber_back.width - w, pixmap_throbber_back.height, 
                         &pixmap_throbber_back, w, 0);
    }
}

void t_draw_progressbar_16(struct usplash_theme *theme, int percentage) {
    int w = (pixmap_throbber_back_16.width * percentage / 100);
    if (percentage == 0)
        usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_16);
    if (percentage < 0){ /* Unloading */
        w *= -1;
        /* Draw background to left of foreground */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_16.height, 
                         &pixmap_throbber_back_16, 0, 0);
        /* Draw foreground to right of background */
        usplash_put_part(theme->progressbar_x + w, theme->progressbar_y, pixmap_throbber_back_16.width - w,
                         pixmap_throbber_back_16.height, &pixmap_throbber_fore_16, w, 0);
    }
    else{/* Loading */
        /* Draw foreground to left of background */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_16.height, 
                         &pixmap_throbber_fore_16, 0, 0);
        /* Draw background to right of foreground */
        usplash_put_part(theme->progressbar_x + w, theme->progressbar_y, pixmap_throbber_back_16.width - w, pixmap_throbber_back_16.height, 
                         &pixmap_throbber_back_16, w, 0);
    }
}

void t_draw_progressbar_32(struct usplash_theme *theme, int percentage) {
    int w = (pixmap_throbber_back_32.width * percentage / 100);
    if (percentage == 0)
        usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_32);
    if (percentage < 0){ /* Unloading */
        w *= -1;
        /* Draw background to left of foreground */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_32.height, 
                         &pixmap_throbber_back_32, 0, 0);
        /* Draw foreground to right of background */
        usplash_put_part(theme->progressbar_x + w, theme->progressbar_y, pixmap_throbber_back_32.width - w,
                         pixmap_throbber_back_32.height, &pixmap_throbber_fore_32, w, 0);
    }
    else{/* Loading */
        /* Draw foreground to left of background */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_32.height, 
                         &pixmap_throbber_fore_32, 0, 0);
        /* Draw background to right of foreground */
        usplash_put_part(theme->progressbar_x + w, theme->progressbar_y, pixmap_throbber_back_32.width - w, pixmap_throbber_back_32.height, 
                         &pixmap_throbber_back_32, w, 0);
    }
}


void t_animate_step(struct usplash_theme* theme, int pulsating) {

    static int pulsate_step = 0;
    static int pulse_width = 16;
    static int step_width = 2;
    static int num_steps = 0;
    int x1;
    int x2;
    num_steps = (pixmap_throbber_fore.width - pulse_width)/2;

    if (pulsating) {
        if(pulsate_step < num_steps/2+1){
	        x1 = 2 * step_width * pulsate_step;
        }
        else{
	        x1 = pixmap_throbber_fore.width - pulse_width - 2 * step_width * (pulsate_step - num_steps/2+1);
        }
        x2 = x1 + pulse_width;

        /* Draw progress bar background on left side of foreground 'pulse' */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, x1,
                         pixmap_throbber_back.height, &pixmap_throbber_back, 0, 0);
        /* Draw progress bar foreground 'pulse' */
        usplash_put_part(theme->progressbar_x + x1, theme->progressbar_y, pulse_width,
                         pixmap_throbber_back.height, &pixmap_throbber_fore, x1, 0);
        /* Draw progress bar background on right side of foreground 'pulse' */
        usplash_put_part(theme->progressbar_x + x2, theme->progressbar_y, pixmap_throbber_back.width - x2,
                         pixmap_throbber_back.height, &pixmap_throbber_back, x2, 0);

        pulsate_step = (pulsate_step + 1) % num_steps;
    }
}

void t_animate_step_16(struct usplash_theme* theme, int pulsating) {

    static int pulsate_step = 0;
    static int pulse_width = 8;
    static int step_width = 2;
    static int num_steps = 0;
    int x1;
    int x2;
    num_steps = (pixmap_throbber_fore_16.width - pulse_width)/2;

    if (pulsating) {
        if(pulsate_step < num_steps/2+1){
	        x1 = 2 * step_width * pulsate_step;
        }
        else{
            x1 = pixmap_throbber_fore_16.width - pulse_width - 2 * step_width * (pulsate_step - num_steps/2+1);
        }
        x2 = x1 + pulse_width;

        /* Draw progress bar background on left side of foreground 'pulse' */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, x1,
                         pixmap_throbber_back_16.height, &pixmap_throbber_back_16, 0, 0);
        /* Draw progress bar foreground 'pulse' */
        usplash_put_part(theme->progressbar_x + x1, theme->progressbar_y, pulse_width,
                         pixmap_throbber_back_16.height, &pixmap_throbber_fore_16, x1, 0);
        /* Draw progress bar background on right side of foreground 'pulse' */
        usplash_put_part(theme->progressbar_x + x2, theme->progressbar_y, pixmap_throbber_back_16.width - x2,
                         pixmap_throbber_back_16.height, &pixmap_throbber_back_16, x2, 0);

        pulsate_step = (pulsate_step + 1) % num_steps;
    }
}

void t_animate_step_32(struct usplash_theme* theme, int pulsating) {

    static int pulsate_step = 0;
    static int pulse_width = 32;
    static int step_width = 2;
    static int num_steps = 0;
    int x1;
    int x2;
    num_steps = (pixmap_throbber_fore_32.width - pulse_width)/2;

    if (pulsating) {
        if(pulsate_step < num_steps/2+1){
	        x1 = 2 * step_width * pulsate_step;
        }
        else{
            x1 = pixmap_throbber_fore_32.width - pulse_width - 2 * step_width * (pulsate_step - num_steps/2+1);
        }
        x2 = x1 + pulse_width;

        /* Draw progress bar background on left side of foreground 'pulse' */
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, x1,
                         pixmap_throbber_back_32.height, &pixmap_throbber_back_32, 0, 0);
        /* Draw progress bar foreground 'pulse' */
        usplash_put_part(theme->progressbar_x + x1, theme->progressbar_y, pulse_width,
                         pixmap_throbber_back_32.height, &pixmap_throbber_fore_32, x1, 0);
        /* Draw progress bar background on right side of foreground 'pulse' */
        usplash_put_part(theme->progressbar_x + x2, theme->progressbar_y, pixmap_throbber_back_32.width - x2,
                         pixmap_throbber_back_32.height, &pixmap_throbber_back_32, x2, 0);

        pulsate_step = (pulsate_step + 1) % num_steps;
    }
}

#endif

void t_clear_progressbar(struct usplash_theme *theme) {}
void t_clear_progressbar_16(struct usplash_theme *theme) {}
void t_clear_progressbar_32(struct usplash_theme *theme) {}
void t_draw_progressbar(struct usplash_theme *theme, int percentage) {}
void t_draw_progressbar_16(struct usplash_theme *theme, int percentage) {}
void t_draw_progressbar_32(struct usplash_theme *theme, int percentage) {}
void t_animate_step(struct usplash_theme* theme, int pulsating) {}
void t_animate_step_16(struct usplash_theme* theme, int pulsating) {}
void t_animate_step_32(struct usplash_theme* theme, int pulsating) {}
