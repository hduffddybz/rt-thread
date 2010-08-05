#ifndef __RTGUI_SCROLLBAR_H__
#define __RTGUI_SCROLLBAR_H__

#include <rtgui/rtgui.h>
#include <rtgui/widgets/widget.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Gets the type of a scrollbar */
#define RTGUI_SCROLLBAR_TYPE       (rtgui_scrollbar_type_get())
/** Casts the object to an rtgui_scrollbar */
#define RTGUI_SCROLLBAR(obj)       (RTGUI_OBJECT_CAST((obj), RTGUI_SCROLLBAR_TYPE, rtgui_scrollbar_t))
/** Checks if the object is an rtgui_scrollbar */
#define RTGUI_IS_SCROLLBAR(obj)    (RTGUI_OBJECT_CHECK_TYPE((obj), RTGUI_SCROLLBAR_TYPE))

#define RTGUI_DEFAULT_SB_WIDTH				100
#define RTGUI_DEFAULT_SB_HEIGHT				16

/* scrollbar status/positions*/
#define SBS_UNKNOWN         0x0000
#define SBS_LEFTARROW       0x0001
#define SBS_RIGHTARROW      0x0002
#define SBS_LEFTSPACE       0x0004
#define SBS_RIGHTSPACE      0x0008
#define SBS_HORZTHUMB       0x0010
#define SBS_UPARROW         0x0020
#define SBS_DOWNARROW       0x0040
#define SBS_UPSPACE         0x0080
#define SBS_DOWNSPACE       0x0100
#define SBS_VERTTHUMB       0x0200

struct rtgui_scrollbar
{
	/* inherit from widget */
	struct rtgui_widget parent;

	rt_uint8_t orient;
	rt_uint8_t status;

	/* page_step = width of scrollbar */
	/* thumb size = line_step * page_step / (page_step - (button width * 2)) */
	rt_int16_t line_step, page_step;

	rt_int16_t thumb_position, thumb_size;

	/* position 1:1 width of scrollbar */
	rt_int16_t min_position, max_position;

	rt_int16_t bar_width;

	rt_bool_t (*on_scroll) (struct rtgui_widget* widget, struct rtgui_event* event);
};
typedef struct rtgui_scrollbar rtgui_scrollbar_t;

rtgui_type_t *rtgui_scrollbar_type_get(void);

struct rtgui_scrollbar* rtgui_scrollbar_create(int orient, rtgui_rect_t* r);
void rtgui_scrollbar_destroy(struct rtgui_scrollbar* bar);

void rtgui_scrollbar_set_range(struct rtgui_scrollbar* bar, int min, int max);
rt_int16_t rtgui_scrollbar_get_value(struct rtgui_scrollbar* bar);
void rtgui_scrollbar_set_value(struct rtgui_scrollbar* bar, rt_int16_t position);

void rtgui_scrollbar_set_onscroll(struct rtgui_scrollbar* bar, rtgui_event_handler_ptr handler);
void rtgui_scrollbar_set_orientation(struct rtgui_scrollbar* bar, int orientation);
void rtgui_scrollbar_set_page_step(struct rtgui_scrollbar* bar, int step);
void rtgui_scrollbar_set_line_step(struct rtgui_scrollbar* bar, int step);

rt_bool_t rtgui_scrollbar_event_handler(struct rtgui_widget* widget, struct rtgui_event* event);

#ifdef __cplusplus
}
#endif

#endif